/* nec2dxs.f -- translated by f2c (version 20090411).
   You must link the resulting object file with libf2c:
	on Microsoft Windows system, link with libf2c.lib;
	on Linux or Unix systems, link with .../path/to/libf2c.a -lm
	or, if you install libf2c.a in a standard place, with -lf2c -lm
	-- in that order, at the end of the command line, as in
		cc *.o -lf2c -lm
	Source for libf2c is in /netlib/f2c/libf2c.zip, e.g.,

		http://www.netlib.org/f2c/libf2c.zip
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal x[1500], y[1500], z__[1500], si[1500], bi[1500], alp[1500], 
	    bet[1500], wlam;
    integer icon1[3000], icon2[3000], itag[3000], iconx[1500], ld, n1, n2, n, 
	    np, m1, m2, m, mp, ipsym;
} data_;

#define data_1 data_

struct {
    doublecomplex cm[2250000];
} cmb_;

#define cmb_1 cmb_

struct {
    integer icase, nbloks, npblk, nlast, nblsym, npsym, nlsym, imat, icasx, 
	    nbbx, npbx, nlbx, nbbl, npbl, nlbl;
} matpar_;

#define matpar_1 matpar_

struct {
    doublereal epsr, sig, scrwlt, scrwrt, fmhz;
    integer ip[3000], kcom;
} save_;

#define save_1 save_

struct {
    doublereal com[95]	/* was [19][5] */;
} csave_;

#define csave_1 csave_

struct {
    doublereal air[1500], aii[1500], bir[1500], bii[1500], cir[1500], cii[
	    1500];
    doublecomplex cur[4500];
} crnt_;

#define crnt_1 crnt_

struct {
    doublecomplex zrati, zrati2, frati, t1;
    doublereal t2, cl, ch, scrwl, scrwr;
    integer nradl, ksymp, ifar, iperf;
} gnd_;

#define gnd_1 gnd_

struct {
    doublecomplex zarray[1500];
    integer nload, nlodf;
} zload_;

#define zload_1 zload_

struct {
    doublecomplex y11a[5], y12a[20];
    integer ncoup, icoup, nctag[5], ncseg[5];
} yparm_;

#define yparm_1 yparm_

struct {
    doublereal ax[30], bx[30], cx[30];
    integer jco[30], jsno, iscon[50], nscon, ipcon[10], npcon;
} segj_;

#define segj_1 segj_

union {
    struct {
	doublecomplex vqd[64], vsant[64], vqds[64];
	integer ivqd[64], isant[64], iqds[64], nvqd, nsant, nqds;
    } _1;
    struct {
	doublecomplex vqd[30], vsant[30], vqds[30];
	integer ivqd[30], isant[30], iqds[30], nvqd, nsant, nqds;
    } _2;
} vsorc_;

#define vsorc_1 (vsorc_._1)
#define vsorc_2 (vsorc_._2)

union {
    struct {
	doublecomplex zped;
	doublereal pin, pnls, x11r[128], x11i[128], x12r[128], x12i[128], 
		x22r[128], x22i[128];
	integer ntyp[128], iseg1[128], iseg2[128], neq, npeq, neq2, nonet, 
		ntsol, nprint, masym;
    } _1;
    struct {
	doublecomplex zped;
	doublereal pin, pnls, x11r[30], x11i[30], x12r[30], x12i[30], x22r[30]
		, x22i[30];
	integer ntyp[30], iseg1[30], iseg2[30], neq, npeq, neq2, nonet, ntsol,
		 nprint, masym;
    } _2;
} netcx_;

#define netcx_1 (netcx_._1)
#define netcx_2 (netcx_._2)

struct {
    doublereal thets, phis, dth, dph, rfld, gnor, clt, cht, epsr2, sig2, xpr6,
	     pinr, pnlr, ploss, xnr, ynr, znr, dxnr, dynr, dznr;
    integer nth, nph, ipd, iavp, inor, iax, ixtyp, near__, nfeh, nrx, nry, 
	    nrz;
} fpat_;

#define fpat_1 fpat_

struct ggrid_1_ {
    doublecomplex ar1[440]	/* was [11][10][4] */, ar2[340]	/* was [17][5]
	    [4] */, ar3[288]	/* was [9][8][4] */, epscf;
    doublereal dxa[3], dya[3], xsa[3], ysa[3];
    integer nxa[3], nya[3];
};

#define ggrid_1 (*(struct ggrid_1_ *) &ggrid_)

struct {
    doublecomplex u, u2, xx1, xx2;
    doublereal r1, r2, zmh, zph;
} gwav_;

#define gwav_1 gwav_

struct {
    integer iplp1, iplp2, iplp3, iplp4;
} plot_;

#define plot_1 plot_

struct {
    doublecomplex cksm, ct1, ct2, ct3, ck1, ck1sq;
    doublereal ck2, ck2sq, tkmag, tsmag, ck1r, zph, rho;
    integer jh;
} evlcom_;

#define evlcom_1 evlcom_

struct {
    doublecomplex a, b;
} cntour_;

#define cntour_1 cntour_

struct {
    doublereal salp[1500];
} angl_;

#define angl_1 angl_

struct {
    doublereal s, b, xj, yj, zj, cabj, sabj, salpj;
    doublecomplex exk, eyk, ezk, exs, eys, ezs, exc, eyc, ezc;
    doublereal rkh;
    integer ind1, indd1, ind2, indd2, iexk, ipgnd;
} dataj_;

#define dataj_1 dataj_

struct {
    doublecomplex ssx[256]	/* was [16][16] */;
} smat_;

#define smat_1 smat_

union {
    struct {
	doublecomplex d__[3000];
    } _1;
    struct {
	doublecomplex y[3000];
    } _2;
    struct {
	doublereal gain[6000];
    } _3;
} scratm_;

#define scratm_1 (scratm_._1)
#define scratm_2 (scratm_._2)
#define scratm_3 (scratm_._3)

struct {
    doublereal xo, yo, zo, sn, xsn, ysn;
    integer isnor;
} incom_;

#define incom_1 incom_

union {
    struct {
	doublereal zpk, rkb2;
	integer ijx;
    } _1;
    struct {
	doublereal zpk, rkb2;
	integer ij;
    } _2;
} tmi_;

#define tmi_1 (tmi_._1)
#define tmi_2 (tmi_._2)

struct {
    doublereal zpk, rhks;
} tmh_;

#define tmh_1 tmh_

/* Initialized data */

struct {
    doublereal fill_1[2138];
    doublereal e_2[12];
    integer e_3[6];
    } ggrid_ = { {0}, .02, .05, .1, .1745329252, .0872664626, .1745329252, 0.,
	     .2, .2, 0., 0., .3490658504, 11, 17, 9, 10, 5, 8 };


/* Table of constant values */

static integer c__9 = 9;
static integer c__1 = 1;
static integer c__1500 = 1500;
static integer c__3 = 3;
static integer c_b101 = 2250000;
static integer c__2 = 2;
static doublecomplex c_b245 = {1.,0.};
static integer c__11 = 11;
static integer c__12 = 12;
static integer c__13 = 13;
static integer c__14 = 14;
static integer c__7 = 7;
static integer c__5 = 5;
static integer c__6 = 6;
static integer c__0 = 0;
static doublecomplex c_b622 = {2.,0.};
static doublereal c_b636 = 0.;
static integer c_n1 = -1;
static integer c__31 = 31;
static integer c__64 = 64;
static integer c__16 = 16;
static integer c__17 = 17;
static integer c__18 = 18;
static integer c__19 = 19;
static integer c__20 = 20;
static integer c__602 = 602;
static integer c__193 = 193;
static doublecomplex c_b1440 = {.5,0.};
static integer c__880 = 880;
static integer c__680 = 680;
static integer c__576 = 576;
static integer c__95 = 95;
static integer c__206 = 206;
static integer c__205 = 205;
static integer c__201 = 201;
static integer c__202 = 202;
static integer c__203 = 203;
static integer c__204 = 204;
static integer c__207 = 207;
static integer c__208 = 208;
static integer c__121 = 121;
static integer c__122 = 122;
static integer c__123 = 123;
static integer c__124 = 124;
static integer c__125 = 125;
static integer c__4 = 4;

/* 	av00	01-mar-02	First compile with Gnu77 compiler for windows */
/* 				(Thanks to Raymond Anderson for letting me know */
/* 				about this compiler and doing initial compilations) */
/* 	av01	14-mar-02	Var PI not used in routine GWAVE */
/* 	av02	14-mar-02	Sub SECOND already intrinsic function */
/* 	av03	15-mar-02	Multiple changes to include SOMNEC routines in nec2d.exe */
/* 	av04	16-mar-02	Status='NEW', seems not to replace existing file. */
/* 	av05	21-okt-02	Max number of loads (LOADMX) made equal to max-nr of segments. */
/* 	av06	21-okt-02	Max number of NT cards (NETMX) increased form 30 to 99 */
/* 	av07	21-okt-02	Max number of EX cards (NSMAX) increased form 30 to 99 */
/* 	av08  22-oct-02	Use of VSRC is uncertain, in some sources equal 10 and some */
/* 				equal 30 (=nr EX?). What should be new value ??? */
/* 	av09	??		?? */
/* 	av10	30-jan-03	Used DGJJ port of G77 compiler which delivers speed increase */
/* 				from 30 to 60% */
/*     History: */
/*        Date      Change */
/*      -------     ---------------------------------------------- */
/*      5/04/95     Matrix re-transposed in subroutine FACTR. */
/*                  FACTR and SOLVE changed for non-transposed matrix. */

/*     PROGRAM NEC(INPUT,TAPE5=INPUT,OUTPUT,TAPE11,TAPE12,TAPE13,TAPE14, */
/*    1TAPE15,TAPE16,TAPE20,TAPE21) */

/*     NUMERICAL ELECTROMAGNETICS CODE (NEC2)  DEVELOPED AT LAWRENCE */
/*     LIVERMORE LAB., LIVERMORE, CA.  (CONTACT G. BURKE AT 510-422-8414 */
/*     FOR PROBLEMS WITH THE NEC CODE.) */
/*     FILE CREATED 4/11/80. */

/*                ***********NOTICE********** */
/*     THIS COMPUTER CODE MATERIAL WAS PREPARED AS AN ACCOUNT OF WORK */
/*     SPONSORED BY THE UNITED STATES GOVERNMENT.  NEITHER THE UNITED */
/*     STATES NOR THE UNITED STATES DEPARTMENT OF ENERGY, NOR ANY OF */
/*     THEIR EMPLOYEES, NOR ANY OF THEIR CONTRACTORS, SUBCONTRACTORS, OR */
/*     THEIR EMPLOYEES, MAKES ANY WARRANTY, EXPRESS OR IMPLIED, OR */
/*     ASSUMES ANY LEGAL LIABILITY OR RESPONSIBILITY FOR THE ACCURACY, */
/*     COMPLETENESS OR USEFULNESS OF ANY INFORMATION, APPARATUS, PRODUCT */
/*     OR PROCESS DISCLOSED, OR REPRESENTS THAT ITS USE WOULD NOT */
/*     INFRINGE PRIVATELY-OWNED RIGHTS. */

/*     DOUBLE PRECISION 6/4/85 */

/* AV05,AV06,AV07 */
/* Declares MAXSEG,MAXMAT,LOADMX,NETMX and N */
/* Main program */ int MAIN__(void)
{
    /* Initialized data */

    static char atst[2*22] = "CE" "FR" "LD" "GN" "EX" "NT" "XQ" "NE" "GD" 
	    "RP" "CM" "NX" "EN" "TL" "PT" "KH" "NH" "PQ" "EK" "WG" "CP" "PL";
    static struct {
	char e_1[24];
	doublereal e_2;
	} equiv_199 = { "LINEAR  RIGHT   LEFT    ", 0. };

#define hpol ((doublereal *)&equiv_199)

    static struct {
	char e_1[48];
	doublereal e_2;
	} equiv_200 = { "                STRAIG  HT      CROSSE  D       ", 
		0. };

#define pnet ((doublereal *)&equiv_200)

    static doublereal ta = .01745329252;
    static doublereal cvel = 299.8;
    static integer normf = 200;

    /* Format strings */
    static char fmt_700[] = "(\002 ENTER NAME OF INPUT FILE >\002,$)";
    static char fmt_701[] = "(a)";
    static char fmt_703[] = "(\002 ENTER NAME OF OUTPUT FILE >\002,$)";
    static char fmt_125[] = "(a2,19a4)";
    static char fmt_126[] = "(\0021\002)";
    static char fmt_127[] = "(///,33x,\002**********************************"
	    "***********\002,//,36x,\002NUMERICAL ELECTROMAGNETICS CODE (NEC-"
	    "2D)\002,//,33x,\002********************************************"
	    "*\002)";
    static char fmt_128[] = "(////,37x,\002- - - - COMMENTS - - - -\002,//)";
    static char fmt_129[] = "(25x,20a4)";
    static char fmt_130[] = "(///,10x,\002INCORRECT LABEL FOR A COMMENT CAR"
	    "D\002)";
    static char fmt_135[] = "(/////)";
    static char fmt_137[] = "(1x,\002***** DATA CARD NO.\002,i3,3x,a2,1x,i3,"
	    "3(1x,i5),6(1x,1p,e12.5))";
    static char fmt_201[] = "(/,\002 RUN TIME =\002,f10.3)";
    static char fmt_138[] = "(///,10x,\002FAULTY DATA CARD LABEL AFTER GEOME"
	    "TRY SECTION\002)";
    static char fmt_303[] = "(/,\002 ERROR - \002,a2,\002 CARD IS NOT ALLOWE"
	    "D WITH N.G.F.\002)";
    static char fmt_313[] = "(/,\002 NUMBER OF SEGMENTS IN COUPLING CALCULAT"
	    "ION (CP) EXCEEDS LIMIT\002)";
    static char fmt_139[] = "(///,10x,\002NUMBER OF LOADING CARDS EXCEEDS ST"
	    "ORAGE ALLOTTED\002)";
    static char fmt_140[] = "(///,10x,\002DATA FAULT ON LOADING CARD NO.="
	    "\002,i5,5x,\002ITAG STEP1=\002,i5,\002  IS GREATER THAN ITAG STE"
	    "P2=\002,i5)";
    static char fmt_390[] = "(\002 RADIAL WIRE G. S. APPROXIMATION MAY NOT B"
	    "E USED WITH SOMMERFELD GROUND OPTION\002)";
    static char fmt_141[] = "(///,10x,\002NUMBER OF EXCITATION CARDS EXCEEDS"
	    " STORAGE ALLO\002,\002TTED\002)";
    static char fmt_142[] = "(///,10x,\002NUMBER OF NETWORK CARDS EXCEEDS ST"
	    "ORAGE ALLOTTE\002,\002D\002)";
    static char fmt_143[] = "(///,10x,\002WHEN MULTIPLE FREQUENCIES ARE REQU"
	    "ESTED, ONLY ON\002,\002E NEAR FIELD CARD CAN BE USED -\002,/,10x,"
	    "\002LAST CARD READ IS USED\002)";
    static char fmt_302[] = "(\002 ERROR - N.G.F. IN USE.  CANNOT WRITE NEW "
	    "N.G.F.\002)";
    static char fmt_145[] = "(////,33x,\002- - - - - - FREQUENCY - - - - - "
	    "-\002,//,36x,\002FREQUENCY=\002,1p,e11.4,\002 MHZ\002,/,36x,\002"
	    "WAVELENGTH=\002,e11.4,\002 METERS\002)";
    static char fmt_196[] = "(////,20x,\002APPROXIMATE INTEGRATION EMPLOYED "
	    "FOR SEGMENTS MORE THAN\002,f8.3,\002 WAVELENGTHS APART\002)";
    static char fmt_321[] = "(/,20x,\002THE EXTENDED THIN WIRE KERNEL WILL B"
	    "E USED\002)";
    static char fmt_146[] = "(///,30x,\002 - - - STRUCTURE IMPEDANCE LOADING"
	    " - - -\002)";
    static char fmt_147[] = "(/,35x,\002THIS STRUCTURE IS NOT LOADED\002)";
    static char fmt_327[] = "(/,35x,\002 LOADING ONLY IN N.G.F. SECTION\002)";
    static char fmt_148[] = "(///,34x,\002- - - ANTENNA ENVIRONMENT - - -"
	    "\002,/)";
    static char fmt_170[] = "(40x,\002RADIAL WIRE GROUND SCREEN\002,/,40x,"
	    "i5,\002 WIRES\002,/,40x,\002WIRE LENGTH=\002,f8.2,\002 METERS"
	    "\002,/,40x,\002WIRE RADIUS=\002,1p,e10.3,\002 METERS\002)";
    static char fmt_149[] = "(40x,\002MEDIUM UNDER SCREEN -\002)";
    static char fmt_391[] = "(40x,\002FINITE GROUND.  REFLECTION COEFFICIENT"
	    " APPROXIMATION\002)";
    static char fmt_393[] = "(/,\002 ERROR IN GROUND PARAMETERS -\002,/,\002"
	    " COMPLEX DIELECTRIC CONSTANT FROM FILE IS\002,1p,2e12.5,/,32x"
	    ",\002REQUESTED\002,2e12.5)";
    static char fmt_392[] = "(40x,\002FINITE GROUND.  SOMMERFELD SOLUTION"
	    "\002)";
    static char fmt_150[] = "(40x,\002RELATIVE DIELECTRIC CONST.=\002,f7.3,/"
	    ",40x,\002CONDUCTIV\002,\002ITY=\002,1p,e10.3,\002 MHOS/METER\002"
	    ",/,40x,\002COMPLEX DIELECTRIC CONSTANT=\002,2e12.5)";
    static char fmt_151[] = "(42x,\002PERFECT GROUND\002)";
    static char fmt_152[] = "(44x,\002FREE SPACE\002)";
    static char fmt_153[] = "(///,32x,\002- - - MATRIX TIMING - - -\002,//,2"
	    "4x,\002FILL=\002,f9.3,\002 SEC.,  FACTOR=\002,f9.3,\002 SEC.\002)"
	    ;
    static char fmt_154[] = "(///,40x,\002- - - EXCITATION - - -\002)";
    static char fmt_156[] = "(/,31x,\002POSITION (METERS)\002,14x,\002ORIENT"
	    "ATION (DEG)=\002,/,28x,\002X\002,12x,\002Y\002,12x,\002Z\002,10x,"
	    "\002ALPHA\002,5x,\002BETA\002,4x,\002DIPOLE MOMENT\002,//,4x,"
	    "\002CURRENT SOURCE\002,1x,3(3x,f10.5),1x,2(3x,f7.2),4x,f8.3)";
    static char fmt_155[] = "(/,4x,\002PLANE WAVE\002,4x,\002THETA=\002,f7"
	    ".2,\002 DEG,  PHI=\002,f7.2,\002 DEG,  ETA=\002,f7.2,\002 DEG,  "
	    "TYPE -\002,a6,\002=  AXIAL RATIO=\002,f6.3)";
    static char fmt_158[] = "(///,44x,\002- - - NETWORK DATA - - -\002)";
    static char fmt_159[] = "(/,6x,\002- FROM -    - TO -\002,11x,\002TRANSM"
	    "ISSION LINE\002,15x,\002-  -  SHUNT ADMITTANCES (MHOS)  -  -\002"
	    ",14x,\002LINE\002,/,6x,\002TAG  SEG.\002,\002   TAG  SEG.\002,6x,"
	    "\002IMPEDANCE\002,6x,\002LENGTH\002,12x,\002- END ONE -\002,17x"
	    ",\002- END TWO -\002,12x,\002TYPE\002,/,6x,\002NO.   NO.   NO.  "
	    " NO.\002,9x,\002OHMS\002,8x,\002METERS\002,9x,\002REAL\002,10x"
	    ",\002IMAG.\002,9x,\002REAL\002,10x,\002IMAG.\002)";
    static char fmt_160[] = "(/,6x,\002- FROM -\002,4x,\002- TO -\002,26x"
	    ",\002-  -  ADMITTANCE MATRIX\002,\002 ELEMENTS (MHOS)  -  -\002,"
	    "/,6x,\002TAG  SEG.   TAG  SEG.\002,13x,\002(ON\002,\002E,ONE)"
	    "\002,19x,\002(ONE,TWO)\002,19x,\002(TWO,TWO)\002,/,6x,\002NO.   "
	    "NO.   NO\002,\002.   NO.\002,8x,\002REAL\002,10x,\002IMAG.\002,9"
	    "x,\002REAL\002,10x,\002IMAG.\002,9x,\002REAL\002,10x,\002IMAG"
	    ".\002)";
    static char fmt_157[] = "(4x,4(i5,1x),1p,6(3x,e11.4),3x,a6,a2)";
    static char fmt_161[] = "(///,29x,\002- - - CURRENTS AND LOCATION - - "
	    "-\002,//,33x,\002DISTANCES IN WAVELENGTHS\002)";
    static char fmt_162[] = "(//,2x,\002SEG.\002,2x,\002TAG\002,4x,\002COORD"
	    ". OF SEG. CENTER\002,5x,\002SEG.\002,12x,\002- - - CURRENT (AMPS"
	    ") - - -\002,/,2x,\002NO.\002,3x,\002NO.\002,5x,\002X\002,8x,\002Y"
	    "\002,8x,\002Z\002,6x,\002LENGTH\002,5x,\002REAL\002,8x,\002IMAG"
	    ".\002,7x,\002MAG.\002,8x,\002PHASE\002)";
    static char fmt_163[] = "(///,33x,\002- - - RECEIVING PATTERN PARAMETERS"
	    " - - -\002,/,43x,\002ETA=\002,f7.2,\002 DEGREES\002,/,43x,\002TY"
	    "PE -\002,a6,/,43x,\002AXIAL RATIO=\002,f6.3,//,11x,\002THETA\002"
	    ",6x,\002PHI\002,10x,\002-  CURRENT  -\002,9x,\002SEG\002,/,11x"
	    ",\002(DEG)\002,5x,\002(DEG)\002,7x,\002MAGNITUDE\002,4x,\002PHASE"
	    "\002,6x,\002NO.\002,/)";
    static char fmt_164[] = "(10x,2(f7.2,3x),1x,1p,e11.4,3x,0p,f7.2,4x,i5)";
    static char fmt_165[] = "(1x,2i5,3f9.4,f9.5,1x,1p,3e12.4,0p,f9.3)";
    static char fmt_315[] = "(///,34x,\002- - - CHARGE DENSITIES - - -\002,/"
	    "/,36x,\002DISTANCES IN WAVELENGTHS\002,///,2x,\002SEG.\002,2x"
	    ",\002TAG\002,4x,\002COORD. OF SEG. CENTER\002,5x,\002SEG.\002,10"
	    "x,\002CHARGE DENSITY (COULOMBS/METER)\002,/,2x,\002NO.\002,3x"
	    ",\002NO.\002,5x,\002X\002,8x,\002Y\002,8x,\002Z\002,6x,\002LENGTH"
	    "\002,5x,\002REAL\002,8x,\002IMAG.\002,7x,\002MAG.\002,8x,\002PHA"
	    "SE\002)";
    static char fmt_197[] = "(////,41x,\002- - - - SURFACE PATCH CURRENTS - "
	    "- - -\002,//,50x,\002DISTANCE IN WAVELENGTHS\002,/,50x,\002CURRE"
	    "NT IN AMPS/METER\002,//,28x,\002- - SURFACE COMPONENTS - -\002,1"
	    "9x,\002- - - RECTANGULAR COMPONENTS - - -\002,/,6x,\002PATCH CEN"
	    "TER\002,6x,\002TANGENT VECTOR 1\002,3x,\002TANGENT VECTOR 2\002,"
	    "11x,\002X\002,19x,\002Y\002,19x,\002Z\002,/,5x,\002X\002,6x,\002Y"
	    "\002,6x,\002Z\002,5x,\002MAG.\002,7x,\002PHASE\002,3x,\002MAG"
	    ".\002,7x,\002PHASE\002,3(4x,\002REAL\002,6x,\002IMAG. \002))";
    static char fmt_198[] = "(1x,i4,/,1x,3f7.3,2(1p,e11.4,0p,f8.2),1p,6e10.2)"
	    ;
    static char fmt_166[] = "(///,40x,\002- - - POWER BUDGET - - -\002,//,43"
	    "x,\002INPUT POWER   =\002,1p,e11.4,\002 WATTS\002,/,43x,\002RADI"
	    "ATED POWER=\002,e11.4,\002 WATTS\002,/,43x,\002STRUCTURE LOSS"
	    "=\002,e11.4,\002 WATTS\002,/,43x,\002NETWORK LOSS  =\002,e11.4"
	    ",\002 WATTS\002,/,43x,\002EFFICIENCY    =\002,0p,f7.2,\002 PERCE"
	    "NT\002)";
    static char fmt_181[] = "(///,4x,\002RECEIVING PATTERN STORAGE TOO SMALL"
	    ",ARRAY TRUNCA\002,\002TED\002)";
    static char fmt_182[] = "(///,32x,\002- - - NORMALIZED RECEIVING PATTERN"
	    " - - -\002,/,41x,\002NORMALIZATION FACTOR=\002,1p,e11.4,/,41x"
	    ",\002ETA=\002,0p,f7.2,\002 DEGREES\002,/,41x,\002TYPE -\002,a6,/"
	    ",41x,\002AXIAL RATIO=\002,f6.3,/,41x,\002SEGMENT NO.=\002,i5,//,"
	    "21x,\002THETA\002,6x,\002PHI\002,9x,\002-  PATTERN  -\002,/,21x"
	    ",\002(DEG)\002,5x,\002(DEG)\002,8x,\002DB\002,8x,\002MAGNITUD"
	    "E\002,/)";
    static char fmt_183[] = "(20x,2(f7.2,3x),1x,f7.2,4x,1p,e11.4)";
    static char fmt_184[] = "(///,36x,\002- - - INPUT IMPEDANCE DATA - - "
	    "-\002,/,45x,\002SOURCE SEGMENT NO.\002,i4,/,45x,\002NORMALIZATIO"
	    "N FACTOR=\002,1p,e12.5,//,7x,\002FREQ.\002,13x,\002-  -  UNNORMA"
	    "LIZED IMPEDANCE  -  -\002,21x,\002-\r -  NORMALIZED IMPEDANCE  -"
	    "  -\002,/,19x,\002RESISTANCE\002,4x,\002REACTANCE\002,6x,\002MAG"
	    "NITUDE\002,4x,\002PHASE\002,7x,\002RESISTANCE\002,4x,\002REACTAN"
	    "CE\002,6x,\002MAGNITUDE\002,4x,\002PHASE\002,/,8x,\002MHZ\002,11"
	    "x,\002OHMS\002,10x,\002OHMS\002,11x,\002OHMS\002,5x,\002DEGREE"
	    "S\002,47x,\002DEGREES\002,/)";
    static char fmt_185[] = "(///,4x,\002STORAGE FOR IMPEDANCE NORMALIZATION"
	    " TOO SMALL, ARRAY TRUNCATED\002)";
    static char fmt_186[] = "(3x,f9.3,2x,1p,2(2x,e12.5),3x,e12.5,2x,0p,f7.2,"
	    "2x,1p,2(2x,e12.5),3x,e12.5,2x,0p,f7.2)";

    /* System generated locals */
    integer i__1, i__2, i__3, i__4;
    doublereal d__1, d__2, d__3;
    doublecomplex z__1, z__2, z__3, z__4, z__5;
    olist o__1;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void), s_wsfe(cilist *), e_wsfe(void), s_rsfe(cilist *), 
	    do_fio(integer *, char *, ftnlen), e_rsfe(void), f_open(olist *);
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    double z_abs(doublecomplex *);
    void z_sqrt(doublecomplex *, doublecomplex *), z_div(doublecomplex *, 
	    doublecomplex *, doublecomplex *);
    double sqrt(doublereal), d_imag(doublecomplex *), pow_di(doublereal *, 
	    integer *);

    /* Local variables */
    integer i__, j;
#define x2 ((doublereal *)&data_1 + 4500)
#define y2 ((doublereal *)&data_1 + 7500)
#define z2 ((doublereal *)&data_1 + 9000)
    doublecomplex fj;
    doublereal fr;
    doublecomplex ex, ey, ez;
    integer ix[3000];
    doublereal ph, fr2;
#define t1x ((doublereal *)&data_1 + 4500)
#define t1y ((doublereal *)&data_1 + 7500)
#define t1z ((doublereal *)&data_1 + 9000)
#define t2x ((doublereal *)&data_1 + 10501)
#define t2y ((doublereal *)&data_1 + 12001)
#define t2z ((doublereal *)&data_1 + 13501)
#define cab ((doublereal *)&data_1 + 7500)
    extern doublereal db20_(doublereal *);
    integer ib11, ic11, id11;
#define sab ((doublereal *)&data_1 + 9000)
    char ain[2];
    integer inc;
    doublecomplex eph, eth;
    doublereal zlr[1500], zli[1500], zlc[1500];
    integer ix11, igo;
    doublereal rkh;
    integer mhz;
    doublereal tim, tim1, tim2, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, xpr1, 
	    xpr2, xpr3, xpr4, xpr5, cmag;
    extern doublereal cang_(doublecomplex *);
    doublereal epha;
    extern /* Subroutine */ int load_(integer *, integer *, integer *, 
	    integer *, doublereal *, doublereal *, doublereal *);
    integer iped, lain;
    doublereal etha;
    doublecomplex epsc, curi;
    integer nfrq, iexk, ifrq, nthi, nphi, jump;
    doublereal ethm, ephm;
    extern /* Subroutine */ int som2d_(doublereal *, doublereal *, doublereal 
	    *);
    doublereal fmhz1;
    integer itmp1, itmp2, itmp3, itmp4, itmp5;
    extern /* Subroutine */ int facgf_(doublecomplex *, doublecomplex *, 
	    doublecomplex *, doublecomplex *, doublecomplex *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *), fbngf_(integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *), cmngf_(doublecomplex *, 
	    doublecomplex *, doublecomplex *, integer *, integer *, integer *,
	     doublereal *, integer *);
    integer ldtag[1500];
    shortint llneg;
    integer iptag, irngf;
    extern /* Subroutine */ int cmset_(integer *, doublecomplex *, doublereal 
	    *, integer *);
    integer ldtyp[1500];
    doublereal fnorm[200], xtemp[1500], ytemp[1500], ztemp[1500], extim;
    integer mpcnt, iflow;
    doublereal fmhzs, phiss;
    integer iptaq;
    extern /* Subroutine */ int gfout_(void);
    integer nthic, nphic;
    extern /* Subroutine */ int etmns_(doublereal *, doublereal *, doublereal 
	    *, doublereal *, doublereal *, doublereal *, integer *, 
	    doublecomplex *), netwk_(doublecomplex *, doublecomplex *, 
	    doublecomplex *, doublecomplex *, integer *, doublecomplex *);
    integer isave;
    extern /* Subroutine */ int nfpat_(void), rdpat_(void), datagn_(void), 
	    fblock_(integer *, integer *, integer *, integer *, integer *);
    integer ldtagf[1500];
    char infile__[80];
    extern /* Subroutine */ int readmn_(integer *, char *, integer *, integer 
	    *, integer *, integer *, doublereal *, doublereal *, doublereal *,
	     doublereal *, doublereal *, doublereal *, ftnlen);
    integer iptagf;
    extern /* Subroutine */ int second_(doublereal *);
    doublereal delfrq;
    integer ldtagt[1500];
    doublereal bitemp[1500];
    extern /* Subroutine */ int upcase_(char *, char *, integer *, ftnlen, 
	    ftnlen), factrs_(integer *, integer *, doublecomplex *, integer *,
	     integer *, integer *, integer *, integer *, integer *);
    integer iptflg;
    extern integer isegno_(integer *, integer *);
    integer iptagt, iptaqf;
    extern /* Subroutine */ int couple_(doublecomplex *, doublereal *);
    integer iptflq;
    doublereal thetis, sitemp[1500];
    integer iptaqt;
    doublereal zpnorm;
    char outfile[80];
    integer ifrtimp, ifrtimw;

    /* Fortran I/O blocks */
    static cilist io___18 = { 0, 6, 0, 0, 0 };
    static cilist io___19 = { 0, 6, 0, 0, 0 };
    static cilist io___20 = { 0, 6, 0, 0, 0 };
    static cilist io___21 = { 0, 6, 0, 0, 0 };
    static cilist io___22 = { 0, 6, 0, 0, 0 };
    static cilist io___23 = { 0, 6, 0, 0, 0 };
    static cilist io___24 = { 0, 6, 0, 0, 0 };
    static cilist io___25 = { 0, 6, 0, 0, 0 };
    static cilist io___26 = { 0, 6, 0, 0, 0 };
    static cilist io___27 = { 0, 6, 0, 0, 0 };
    static cilist io___28 = { 0, 6, 0, fmt_700, 0 };
    static cilist io___29 = { 1, 5, 1, fmt_701, 0 };
    static cilist io___31 = { 0, 6, 0, fmt_703, 0 };
    static cilist io___32 = { 1, 5, 1, fmt_701, 0 };
    static cilist io___34 = { 0, 6, 0, 0, 0 };
    static cilist io___35 = { 0, 6, 0, 0, 0 };
    static cilist io___36 = { 0, 6, 0, 0, 0 };
    static cilist io___41 = { 0, 2, 0, fmt_125, 0 };
    static cilist io___45 = { 0, 3, 0, fmt_126, 0 };
    static cilist io___46 = { 0, 3, 0, fmt_127, 0 };
    static cilist io___47 = { 0, 3, 0, fmt_128, 0 };
    static cilist io___48 = { 0, 3, 0, fmt_129, 0 };
    static cilist io___49 = { 0, 3, 0, fmt_130, 0 };
    static cilist io___56 = { 0, 3, 0, fmt_135, 0 };
    static cilist io___77 = { 0, 3, 0, fmt_137, 0 };
    static cilist io___78 = { 0, 3, 0, fmt_201, 0 };
    static cilist io___79 = { 0, 3, 0, fmt_138, 0 };
    static cilist io___81 = { 0, 3, 0, fmt_303, 0 };
    static cilist io___84 = { 0, 3, 0, fmt_313, 0 };
    static cilist io___85 = { 0, 3, 0, fmt_139, 0 };
    static cilist io___90 = { 0, 3, 0, fmt_140, 0 };
    static cilist io___94 = { 0, 3, 0, fmt_303, 0 };
    static cilist io___95 = { 0, 3, 0, fmt_390, 0 };
    static cilist io___96 = { 0, 3, 0, fmt_141, 0 };
    static cilist io___106 = { 0, 3, 0, fmt_142, 0 };
    static cilist io___113 = { 0, 3, 0, fmt_143, 0 };
    static cilist io___114 = { 0, 3, 0, fmt_302, 0 };
    static cilist io___124 = { 0, 3, 0, fmt_145, 0 };
    static cilist io___125 = { 0, 3, 0, fmt_196, 0 };
    static cilist io___126 = { 0, 3, 0, fmt_321, 0 };
    static cilist io___128 = { 0, 3, 0, fmt_146, 0 };
    static cilist io___129 = { 0, 3, 0, fmt_147, 0 };
    static cilist io___130 = { 0, 3, 0, fmt_327, 0 };
    static cilist io___131 = { 0, 3, 0, fmt_148, 0 };
    static cilist io___133 = { 0, 3, 0, fmt_170, 0 };
    static cilist io___134 = { 0, 3, 0, fmt_149, 0 };
    static cilist io___135 = { 0, 3, 0, fmt_391, 0 };
    static cilist io___136 = { 0, 3, 0, fmt_393, 0 };
    static cilist io___137 = { 0, 3, 0, fmt_392, 0 };
    static cilist io___138 = { 0, 3, 0, fmt_150, 0 };
    static cilist io___139 = { 0, 3, 0, fmt_151, 0 };
    static cilist io___140 = { 0, 3, 0, fmt_152, 0 };
    static cilist io___145 = { 0, 3, 0, fmt_153, 0 };
    static cilist io___149 = { 0, 3, 0, fmt_154, 0 };
    static cilist io___150 = { 0, 3, 0, fmt_156, 0 };
    static cilist io___151 = { 0, 3, 0, fmt_155, 0 };
    static cilist io___152 = { 0, 3, 0, fmt_158, 0 };
    static cilist io___153 = { 0, 3, 0, fmt_159, 0 };
    static cilist io___154 = { 0, 3, 0, fmt_160, 0 };
    static cilist io___156 = { 0, 3, 0, fmt_157, 0 };
    static cilist io___158 = { 0, 3, 0, fmt_161, 0 };
    static cilist io___159 = { 0, 3, 0, fmt_162, 0 };
    static cilist io___160 = { 0, 3, 0, fmt_163, 0 };
    static cilist io___166 = { 0, 3, 0, fmt_164, 0 };
    static cilist io___167 = { 0, 3, 0, fmt_165, 0 };
    static cilist io___168 = { 0, 8, 0, 0, 0 };
    static cilist io___169 = { 0, 8, 0, 0, 0 };
    static cilist io___170 = { 0, 3, 0, fmt_315, 0 };
    static cilist io___171 = { 0, 3, 0, fmt_165, 0 };
    static cilist io___172 = { 0, 3, 0, fmt_197, 0 };
    static cilist io___182 = { 0, 3, 0, fmt_198, 0 };
    static cilist io___183 = { 0, 8, 0, 0, 0 };
    static cilist io___184 = { 0, 8, 0, 0, 0 };
    static cilist io___185 = { 0, 8, 0, 0, 0 };
    static cilist io___186 = { 0, 8, 0, 0, 0 };
    static cilist io___187 = { 0, 3, 0, fmt_166, 0 };
    static cilist io___188 = { 0, 3, 0, fmt_135, 0 };
    static cilist io___189 = { 0, 3, 0, fmt_135, 0 };
    static cilist io___190 = { 0, 3, 0, fmt_181, 0 };
    static cilist io___191 = { 0, 3, 0, fmt_182, 0 };
    static cilist io___192 = { 0, 3, 0, fmt_183, 0 };
    static cilist io___193 = { 0, 3, 0, fmt_135, 0 };
    static cilist io___194 = { 0, 3, 0, fmt_184, 0 };
    static cilist io___195 = { 0, 3, 0, fmt_184, 0 };
    static cilist io___196 = { 0, 3, 0, fmt_185, 0 };
    static cilist io___197 = { 0, 3, 0, fmt_186, 0 };
    static cilist io___198 = { 0, 3, 0, fmt_135, 0 };


/* Max number of segments 	(Windows-95 <= 4 */
/* max nr of 'in-core' alloc.	(MAXMAT <= MA */
/* Max number of LD cards */
/* Max number of EX cards */
/* Max number of segs connected to NT/TL */
/* *** */
/*      CHARACTER INMSG*48,OUTMSG*40 */
/*      INTEGER*2 GPWNXY(2) */
/*      LOGICAL*4 GetPut,LGTPT */
/* av07 COMMON/VSORC/VQD(30),VSANT(30),VQDS(30),IVQD(30),ISANT(30), */
/* av07 -IQDS(30),NVQD,NSANT,NQDS */
/* av06 COMMON/NETCX/ZPED,PIN,PNLS,X11R(30),X11I(30),X12R(30),X12I(30), */
/*     -X22R(30),X22I(30),NTYP(30),ISEG1(30),ISEG2(30),NEQ,NPEQ,NEQ2, */
/* av06 -NONET,NTSOL,NPRINT,MASYM */
/* av07 */
/* av06 */
/* *** */
/* *** */
/* av05 DIMENSION LDTYP(30),LDTAG(30),LDTAGF(30),LDTAGT(30),ZLR(30), */
/* av05 -ZLI(30),ZLC(30) */
/* av05 */
/* *** */
/* av05-7 DATA LOADMX,NSMAX,NETMX/30,30,30/,NORMF/200/ */
    s_wsle(&io___18);
    do_lio(&c__9, &c__1, "", (ftnlen)0);
    e_wsle();
    s_wsle(&io___19);
    do_lio(&c__9, &c__1, "Numerical Electromagnetics Code, ", (ftnlen)33);
    do_lio(&c__9, &c__1, "double precision version (nec2d)", (ftnlen)32);
    e_wsle();
    s_wsle(&io___20);
    do_lio(&c__9, &c__1, "developed at Lawrence Livermore Lab., ", (ftnlen)38)
	    ;
    do_lio(&c__9, &c__1, "Livermore, CA., by G. Burke", (ftnlen)27);
    e_wsle();
    s_wsle(&io___21);
    do_lio(&c__9, &c__1, "(burke@icdc.llnl.gov) and A. Poggio.", (ftnlen)36);
    e_wsle();
/* av03      Write(*,*) */
/* av03      & 'Fortran file was created 4/11/80, last changed: Jan 15, 96, by' */
/* av03      Write(*,*) */
/* av03     & 'J. Bergervoet (bergervo@prl.philips.nl)' */
    s_wsle(&io___22);
    do_lio(&c__9, &c__1, "Maximum number of segments in core : MAXMAT=", (
	    ftnlen)44);
    do_lio(&c__3, &c__1, (char *)&c__1500, (ftnlen)sizeof(integer));
    e_wsle();
    if (FALSE_) {
	s_wsle(&io___23);
	do_lio(&c__9, &c__1, "Maximum when using swap files      : MAXSEG=", (
		ftnlen)44);
	do_lio(&c__3, &c__1, (char *)&c__1500, (ftnlen)sizeof(integer));
	e_wsle();
    }
    s_wsle(&io___24);
    do_lio(&c__9, &c__1, "", (ftnlen)0);
    e_wsle();
    s_wsle(&io___25);
    do_lio(&c__9, &c__1, "Merged nec2d/som2d file created by Arie. (4nec2@gm"
	    "x.net)", (ftnlen)56);
    e_wsle();
    s_wsle(&io___26);
    do_lio(&c__9, &c__1, "V2.2  31-jan-2003   (maxLD=MaxSeg, MaxEX=99, MaxTL"
	    "=64)", (ftnlen)54);
    e_wsle();
    s_wsle(&io___27);
    do_lio(&c__9, &c__1, "", (ftnlen)0);
    e_wsle();
/* ***VAX */
L706:
    s_wsfe(&io___28);
    e_wsfe();
/* av03 READ(*,701,ERR=702) INFILE */
    i__1 = s_rsfe(&io___29);
    if (i__1 != 0) {
	goto L100001;
    }
    i__1 = do_fio(&c__1, infile__, (ftnlen)80);
    if (i__1 != 0) {
	goto L100001;
    }
    i__1 = e_rsfe();
L100001:
    if (i__1 < 0) {
	goto L708;
    }
    if (i__1 > 0) {
	goto L706;
    }
/* av03 */
/*     IF(INFILE.EQ.' ')INFILE='SYS$INPUT' */
    o__1.oerr = 1;
    o__1.ounit = 2;
    o__1.ofnmlen = 80;
    o__1.ofnm = infile__;
    o__1.orl = 0;
    o__1.osta = "OLD";
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    i__1 = f_open(&o__1);
    if (i__1 != 0) {
	goto L702;
    }
/*     OPEN (UNIT=2,FILE=INFILE,STATUS='OLD',ACTION='READ',ERR=702) */
/*     OPEN (UNIT=2,FILE=INFILE,STATUS='OLD',READONLY,ERR=702) */
L707:
    s_wsfe(&io___31);
    e_wsfe();
/* av03 READ(*,701,ERR=704) OUTFILE */
    i__1 = s_rsfe(&io___32);
    if (i__1 != 0) {
	goto L100002;
    }
    i__1 = do_fio(&c__1, outfile, (ftnlen)80);
    if (i__1 != 0) {
	goto L100002;
    }
    i__1 = e_rsfe();
L100002:
    if (i__1 < 0) {
	goto L706;
    }
    if (i__1 > 0) {
	goto L707;
    }
/*     IF(OUTFILE.EQ.' ')OUTFILE='SYS$OUTPUT' */
/*     OPEN (UNIT=3,FILE=OUTFILE,STATUS='NEW',ERR=704) */
/* av03 */
    o__1.oerr = 1;
    o__1.ounit = 3;
    o__1.ofnmlen = 80;
    o__1.ofnm = outfile;
    o__1.orl = 0;
    o__1.osta = "UNKNOWN";
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    i__1 = f_open(&o__1);
    if (i__1 != 0) {
	goto L704;
    }
    goto L705;
/* av03 702   CALL ERROR */
L702:
    s_wsle(&io___34);
    do_lio(&c__9, &c__1, "Error opening input-file:", (ftnlen)25);
    do_lio(&c__9, &c__1, infile__, (ftnlen)80);
    e_wsle();
/* av03 */
    goto L706;
/* av03 704   CALL ERROR */
L704:
    s_wsle(&io___35);
    do_lio(&c__9, &c__1, "Error opening output-file:", (ftnlen)26);
    do_lio(&c__9, &c__1, outfile, (ftnlen)80);
    e_wsle();
/* av03 */
    goto L707;
L708:
    s_stop("", (ftnlen)0);
L705:
    s_wsle(&io___36);
    do_lio(&c__9, &c__1, "", (ftnlen)0);
    e_wsle();
    second_(&extim);
    fj.r = 0.f, fj.i = 1.f;
    data_1.ld = 1500;
/* av03 NXA(1)=0		! NXA is now init by block-data SOMSET */
L1:
    save_1.kcom = 0;
/* *** */
    ifrtimw = 0;
    ifrtimp = 0;
/* *** */
L2:
    ++save_1.kcom;
    if (save_1.kcom > 5) {
	save_1.kcom = 5;
    }
    s_rsfe(&io___41);
    do_fio(&c__1, ain, (ftnlen)2);
    for (i__ = 1; i__ <= 19; ++i__) {
	do_fio(&c__1, (char *)&csave_1.com[i__ + save_1.kcom * 19 - 20], (
		ftnlen)sizeof(doublereal));
    }
    e_rsfe();
    upcase_(ain, ain, &lain, (ftnlen)2, (ftnlen)2);
    if (save_1.kcom > 1) {
	goto L3;
    }
    s_wsfe(&io___45);
    e_wsfe();
    s_wsfe(&io___46);
    e_wsfe();
    s_wsfe(&io___47);
    e_wsfe();
L3:
    s_wsfe(&io___48);
    for (i__ = 1; i__ <= 19; ++i__) {
	do_fio(&c__1, (char *)&csave_1.com[i__ + save_1.kcom * 19 - 20], (
		ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    if (s_cmp(ain, atst + 20, (ftnlen)2, (ftnlen)2) == 0) {
	goto L2;
    }
    if (s_cmp(ain, atst, (ftnlen)2, (ftnlen)2) == 0) {
	goto L4;
    }
    s_wsfe(&io___49);
    e_wsfe();
    s_stop("", (ftnlen)0);
L4:
    i__1 = data_1.ld;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L5: */
	i__2 = i__ - 1;
	zload_1.zarray[i__2].r = 0.f, zload_1.zarray[i__2].i = 0.f;
    }
    mpcnt = 0;
    matpar_1.imat = 0;

/*     SET UP GEOMETRY DATA IN SUBROUTINE DATAGN */

    datagn_();
    iflow = 1;
    if (matpar_1.imat == 0) {
	goto L326;
    }

/*     CORE ALLOCATION FOR ARRAYS B, C, AND D FOR N.G.F. SOLUTION */

    netcx_1.neq = data_1.n1 + (data_1.m1 << 1);
    netcx_1.neq2 = data_1.n - data_1.n1 + (data_1.m - data_1.m1 << 1) + 
	    segj_1.nscon + (segj_1.npcon << 1);
    fbngf_(&netcx_1.neq, &netcx_1.neq2, &c_b101, &ib11, &ic11, &id11, &ix11);
    goto L6;
L326:
    netcx_1.neq = data_1.n + (data_1.m << 1);
    netcx_1.neq2 = 0;
    ib11 = 1;
    ic11 = 1;
    id11 = 1;
    ix11 = 1;
    matpar_1.icasx = 0;
L6:
    netcx_1.npeq = data_1.np + (data_1.mp << 1);
    s_wsfe(&io___56);
    e_wsfe();

/*     DEFAULT VALUES FOR INPUT PARAMETERS AND FLAGS */

/* *** */
    plot_1.iplp1 = 0;
    plot_1.iplp2 = 0;
    plot_1.iplp3 = 0;
    plot_1.iplp4 = 0;
/* *** */
    igo = 1;
    fmhzs = cvel;
    nfrq = 1;
    rkh = 1.f;
    iexk = 0;
    fpat_1.ixtyp = 0;
    zload_1.nload = 0;
    netcx_1.nonet = 0;
    fpat_1.near__ = -1;
    iptflg = -2;
    iptflq = -1;
    gnd_1.ifar = -1;
    gnd_1.zrati.r = 1.f, gnd_1.zrati.i = 0.f;
    iped = 0;
    irngf = 0;
    yparm_1.ncoup = 0;
    yparm_1.icoup = 0;
    llneg = 0;
/* av03, Default = No freq-loop/Neg-sigma */
    if (matpar_1.icasx > 0) {
	goto L14;
    }
    save_1.fmhz = cvel;
    zload_1.nlodf = 0;
    gnd_1.ksymp = 1;
    gnd_1.nradl = 0;
    gnd_1.iperf = 0;

/*     MAIN INPUT SECTION - STANDARD READ STATEMENT - JUMPS TO APPRO- */
/*     PRIATE SECTION FOR SPECIFIC PARAMETER SET UP */

L14:
    readmn_(&c__2, ain, &itmp1, &itmp2, &itmp3, &itmp4, &tmp1, &tmp2, &tmp3, &
	    tmp4, &tmp5, &tmp6, (ftnlen)2);
    ++mpcnt;
    s_wsfe(&io___77);
    do_fio(&c__1, (char *)&mpcnt, (ftnlen)sizeof(integer));
    do_fio(&c__1, ain, (ftnlen)2);
    do_fio(&c__1, (char *)&itmp1, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&itmp2, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&itmp3, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&itmp4, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&tmp1, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&tmp2, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&tmp3, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&tmp4, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&tmp5, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&tmp6, (ftnlen)sizeof(doublereal));
    e_wsfe();
    if (s_cmp(ain, atst + 2, (ftnlen)2, (ftnlen)2) == 0) {
	goto L16;
    }
/* FR */
    if (s_cmp(ain, atst + 4, (ftnlen)2, (ftnlen)2) == 0) {
	goto L17;
    }
/* LD */
    if (s_cmp(ain, atst + 6, (ftnlen)2, (ftnlen)2) == 0) {
	goto L21;
    }
/* GN */
    if (s_cmp(ain, atst + 8, (ftnlen)2, (ftnlen)2) == 0) {
	goto L24;
    }
/* EX */
    if (s_cmp(ain, atst + 10, (ftnlen)2, (ftnlen)2) == 0) {
	goto L28;
    }
/* NT */
    if (s_cmp(ain, atst + 26, (ftnlen)2, (ftnlen)2) == 0) {
	goto L28;
    }
/* TL */
    if (s_cmp(ain, atst + 28, (ftnlen)2, (ftnlen)2) == 0) {
	goto L31;
    }
/* PT */
    if (s_cmp(ain, atst + 34, (ftnlen)2, (ftnlen)2) == 0) {
	goto L319;
    }
/* PQ */
    if (s_cmp(ain, atst + 12, (ftnlen)2, (ftnlen)2) == 0) {
	goto L37;
    }
/* XQ */
    if (s_cmp(ain, atst + 14, (ftnlen)2, (ftnlen)2) == 0) {
	goto L32;
    }
/* NE */
    if (s_cmp(ain, atst + 32, (ftnlen)2, (ftnlen)2) == 0) {
	goto L208;
    }
/* NH */
    if (s_cmp(ain, atst + 16, (ftnlen)2, (ftnlen)2) == 0) {
	goto L34;
    }
/* GD */
    if (s_cmp(ain, atst + 18, (ftnlen)2, (ftnlen)2) == 0) {
	goto L36;
    }
/* RP */
    if (s_cmp(ain, atst + 30, (ftnlen)2, (ftnlen)2) == 0) {
	goto L305;
    }
/* KH */
    if (s_cmp(ain, atst + 36, (ftnlen)2, (ftnlen)2) == 0) {
	goto L320;
    }
/* EK */
    if (s_cmp(ain, atst + 22, (ftnlen)2, (ftnlen)2) == 0) {
	goto L1;
    }
/* NX */
    if (s_cmp(ain, atst + 38, (ftnlen)2, (ftnlen)2) == 0) {
	goto L322;
    }
/* WG */
    if (s_cmp(ain, atst + 40, (ftnlen)2, (ftnlen)2) == 0) {
	goto L304;
    }
/* *** */
/* CP */
    if (s_cmp(ain, atst + 42, (ftnlen)2, (ftnlen)2) == 0) {
	goto L330;
    }
/* *** */
/* PL ??? */
    if (s_cmp(ain, atst + 24, (ftnlen)2, (ftnlen)2) != 0) {
	goto L15;
    }
/* EN */
    second_(&tmp1);
    tmp1 -= extim;
    s_wsfe(&io___78);
    do_fio(&c__1, (char *)&tmp1, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_stop("", (ftnlen)0);
L15:
    s_wsfe(&io___79);
    e_wsfe();
    s_stop("", (ftnlen)0);

/*     FREQUENCY PARAMETERS */

L16:
    ifrq = itmp1;
    if (matpar_1.icasx == 0) {
	goto L8;
    }
    s_wsfe(&io___81);
    do_fio(&c__1, ain, (ftnlen)2);
    e_wsfe();
    s_stop("", (ftnlen)0);
L8:
    nfrq = itmp2;
    if (nfrq == 0) {
	nfrq = 1;
    }
    save_1.fmhz = tmp1;
    delfrq = tmp2;
    if (iped == 1) {
	zpnorm = 0.f;
    }
    igo = 1;
    iflow = 1;
    goto L14;

/*     MATRIX INTEGRATION LIMIT */

L305:
    rkh = tmp1;
    if (igo > 2) {
	igo = 2;
    }
    iflow = 1;
    goto L14;

/*     EXTENDED THIN WIRE KERNEL OPTION */

L320:
    iexk = 1;
    if (itmp1 == -1) {
	iexk = 0;
    }
    if (igo > 2) {
	igo = 2;
    }
    iflow = 1;
    goto L14;

/*     MAXIMUM COUPLING BETWEEN ANTENNAS */

L304:
    if (iflow != 2) {
	yparm_1.ncoup = 0;
    }
    yparm_1.icoup = 0;
    iflow = 2;
    if (itmp2 == 0) {
	goto L14;
    }
    ++yparm_1.ncoup;
    if (yparm_1.ncoup > 5) {
	goto L312;
    }
    yparm_1.nctag[yparm_1.ncoup - 1] = itmp1;
    yparm_1.ncseg[yparm_1.ncoup - 1] = itmp2;
    if (itmp4 == 0) {
	goto L14;
    }
    ++yparm_1.ncoup;
    if (yparm_1.ncoup > 5) {
	goto L312;
    }
    yparm_1.nctag[yparm_1.ncoup - 1] = itmp3;
    yparm_1.ncseg[yparm_1.ncoup - 1] = itmp4;
    goto L14;
L312:
    s_wsfe(&io___84);
    e_wsfe();
    s_stop("", (ftnlen)0);

/*     LOADING PARAMETERS */

L17:
    if (iflow == 3) {
	goto L18;
    }
    zload_1.nload = 0;
    iflow = 3;
    if (igo > 2) {
	igo = 2;
    }
    if (itmp1 == -1) {
	goto L14;
    }
L18:
    ++zload_1.nload;
    if (zload_1.nload <= 1500) {
	goto L19;
    }
    s_wsfe(&io___85);
    e_wsfe();
    s_stop("", (ftnlen)0);
L19:
    ldtyp[zload_1.nload - 1] = itmp1;
    ldtag[zload_1.nload - 1] = itmp2;
    if (itmp4 == 0) {
	itmp4 = itmp3;
    }
    ldtagf[zload_1.nload - 1] = itmp3;
    ldtagt[zload_1.nload - 1] = itmp4;
    if (itmp4 >= itmp3) {
	goto L20;
    }
    s_wsfe(&io___90);
    do_fio(&c__1, (char *)&zload_1.nload, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&itmp3, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&itmp4, (ftnlen)sizeof(integer));
    e_wsfe();
    s_stop("", (ftnlen)0);
L20:
    zlr[zload_1.nload - 1] = tmp1;
    zli[zload_1.nload - 1] = tmp2;
    zlc[zload_1.nload - 1] = tmp3;
    goto L14;

/*     GROUND PARAMETERS UNDER THE ANTENNA */

L21:
    iflow = 4;
    if (matpar_1.icasx == 0) {
	goto L10;
    }
    s_wsfe(&io___94);
    do_fio(&c__1, ain, (ftnlen)2);
    e_wsfe();
    s_stop("", (ftnlen)0);
L10:
    if (igo > 2) {
	igo = 2;
    }
    if (itmp1 != -1) {
	goto L22;
    }
    gnd_1.ksymp = 1;
    gnd_1.nradl = 0;
    gnd_1.iperf = 0;
    goto L14;
L22:
    gnd_1.iperf = itmp1;
    gnd_1.nradl = itmp2;
    gnd_1.ksymp = 2;
    save_1.epsr = tmp1;
    save_1.sig = tmp2;
    if (gnd_1.nradl == 0) {
	goto L23;
    }
    if (gnd_1.iperf != 2) {
	goto L314;
    }
    s_wsfe(&io___95);
    e_wsfe();
    s_stop("", (ftnlen)0);
L314:
    save_1.scrwlt = tmp3;
    save_1.scrwrt = tmp4;
    goto L14;
L23:
    fpat_1.epsr2 = tmp3;
    fpat_1.sig2 = tmp4;
    fpat_1.clt = tmp5;
    fpat_1.cht = tmp6;
    goto L14;

/*     EXCITATION PARAMETERS */

L24:
    if (iflow == 5) {
	goto L25;
    }
    vsorc_1.nsant = 0;
    vsorc_1.nvqd = 0;
    iped = 0;
    iflow = 5;
    if (igo > 3) {
	igo = 3;
    }
L25:
    netcx_1.masym = itmp4 / 10;
    if (itmp1 > 0 && itmp1 != 5) {
	goto L27;
    }
    fpat_1.ixtyp = itmp1;
    netcx_1.ntsol = 0;
    if (fpat_1.ixtyp == 0) {
	goto L205;
    }
    ++vsorc_1.nvqd;
    if (vsorc_1.nvqd > 64) {
	goto L206;
    }
    vsorc_1.ivqd[vsorc_1.nvqd - 1] = isegno_(&itmp2, &itmp3);
    i__2 = vsorc_1.nvqd - 1;
    z__1.r = tmp1, z__1.i = tmp2;
    vsorc_1.vqd[i__2].r = z__1.r, vsorc_1.vqd[i__2].i = z__1.i;
    if (z_abs(&vsorc_1.vqd[vsorc_1.nvqd - 1]) < 1e-20) {
	i__2 = vsorc_1.nvqd - 1;
	vsorc_1.vqd[i__2].r = 1.f, vsorc_1.vqd[i__2].i = 0.f;
    }
    goto L207;
L205:
    ++vsorc_1.nsant;
    if (vsorc_1.nsant <= 64) {
	goto L26;
    }
L206:
    s_wsfe(&io___96);
    e_wsfe();
    s_stop("", (ftnlen)0);
L26:
    vsorc_1.isant[vsorc_1.nsant - 1] = isegno_(&itmp2, &itmp3);
    i__2 = vsorc_1.nsant - 1;
    z__1.r = tmp1, z__1.i = tmp2;
    vsorc_1.vsant[i__2].r = z__1.r, vsorc_1.vsant[i__2].i = z__1.i;
    if (z_abs(&vsorc_1.vsant[vsorc_1.nsant - 1]) < 1e-20) {
	i__2 = vsorc_1.nsant - 1;
	vsorc_1.vsant[i__2].r = 1.f, vsorc_1.vsant[i__2].i = 0.f;
    }
L207:
    iped = itmp4 - netcx_1.masym * 10;
    zpnorm = tmp3;
    if (iped == 1 && zpnorm > 0.) {
	iped = 2;
    }
    goto L14;
L27:
    if (fpat_1.ixtyp == 0 || fpat_1.ixtyp == 5) {
	netcx_1.ntsol = 0;
    }
    fpat_1.ixtyp = itmp1;
    nthi = itmp2;
    nphi = itmp3;
    xpr1 = tmp1;
    xpr2 = tmp2;
    xpr3 = tmp3;
    xpr4 = tmp4;
    xpr5 = tmp5;
    fpat_1.xpr6 = tmp6;
    vsorc_1.nsant = 0;
    vsorc_1.nvqd = 0;
    thetis = xpr1;
    phiss = xpr2;
    goto L14;

/*     NETWORK PARAMETERS */

L28:
    if (iflow == 6) {
	goto L29;
    }
    netcx_1.nonet = 0;
    netcx_1.ntsol = 0;
    iflow = 6;
    if (igo > 3) {
	igo = 3;
    }
    if (itmp2 == -1) {
	goto L14;
    }
L29:
    ++netcx_1.nonet;
    if (netcx_1.nonet <= 128) {
	goto L30;
    }
    s_wsfe(&io___106);
    e_wsfe();
    s_stop("", (ftnlen)0);
L30:
    netcx_1.ntyp[netcx_1.nonet - 1] = 2;
    if (s_cmp(ain, atst + 10, (ftnlen)2, (ftnlen)2) == 0) {
	netcx_1.ntyp[netcx_1.nonet - 1] = 1;
    }
    netcx_1.iseg1[netcx_1.nonet - 1] = isegno_(&itmp1, &itmp2);
    netcx_1.iseg2[netcx_1.nonet - 1] = isegno_(&itmp3, &itmp4);
    netcx_1.x11r[netcx_1.nonet - 1] = tmp1;
    netcx_1.x11i[netcx_1.nonet - 1] = tmp2;
    netcx_1.x12r[netcx_1.nonet - 1] = tmp3;
    netcx_1.x12i[netcx_1.nonet - 1] = tmp4;
    netcx_1.x22r[netcx_1.nonet - 1] = tmp5;
    netcx_1.x22i[netcx_1.nonet - 1] = tmp6;
    if (netcx_1.ntyp[netcx_1.nonet - 1] == 1 || tmp1 > 0.f) {
	goto L14;
    }
    netcx_1.ntyp[netcx_1.nonet - 1] = 3;
    netcx_1.x11r[netcx_1.nonet - 1] = -tmp1;
    goto L14;
/* *** */

/*     PLOT FLAGS */

L330:
    plot_1.iplp1 = itmp1;
    plot_1.iplp2 = itmp2;
    plot_1.iplp3 = itmp3;
    plot_1.iplp4 = itmp4;
/* av04 OPEN (UNIT=8,FILE='PLTDAT.NEC',STATUS='NEW',ERR=14) */
    o__1.oerr = 1;
    o__1.ounit = 8;
    o__1.ofnmlen = 10;
    o__1.ofnm = "PLTDAT.NEC";
    o__1.orl = 0;
    o__1.osta = "UNKNOWN";
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    i__2 = f_open(&o__1);
    if (i__2 != 0) {
	goto L14;
    }
/* *** */
/* av04 */
    goto L14;

/*     PRINT CONTROL FOR CURRENT */

L31:
    iptflg = itmp1;
    iptag = itmp2;
    iptagf = itmp3;
    iptagt = itmp4;
    if (itmp3 == 0 && iptflg != -1) {
	iptflg = -2;
    }
    if (itmp4 == 0) {
	iptagt = iptagf;
    }
    goto L14;

/*     WRITE CONTROL FOR CHARGE */

L319:
    iptflq = itmp1;
    iptaq = itmp2;
    iptaqf = itmp3;
    iptaqt = itmp4;
    if (itmp3 == 0 && iptflq != -1) {
	iptflq = -2;
    }
    if (itmp4 == 0) {
	iptaqt = iptaqf;
    }
    goto L14;

/*     NEAR FIELD CALCULATION PARAMETERS */

L208:
    fpat_1.nfeh = 1;
    goto L209;
L32:
    fpat_1.nfeh = 0;
L209:
    if (! (iflow == 8 && nfrq != 1)) {
	goto L33;
    }
    s_wsfe(&io___113);
    e_wsfe();
L33:
    fpat_1.near__ = itmp1;
    fpat_1.nrx = itmp2;
    fpat_1.nry = itmp3;
    fpat_1.nrz = itmp4;
    fpat_1.xnr = tmp1;
    fpat_1.ynr = tmp2;
    fpat_1.znr = tmp3;
    fpat_1.dxnr = tmp4;
    fpat_1.dynr = tmp5;
    fpat_1.dznr = tmp6;
    iflow = 8;
    if (nfrq != 1) {
	goto L14;
    }
    switch (igo) {
	case 1:  goto L41;
	case 2:  goto L46;
	case 3:  goto L53;
	case 4:  goto L71;
	case 5:  goto L72;
    }

/*     GROUND REPRESENTATION */

L34:
    fpat_1.epsr2 = tmp1;
    fpat_1.sig2 = tmp2;
    fpat_1.clt = tmp3;
    fpat_1.cht = tmp4;
    iflow = 9;
    goto L14;

/*     STANDARD OBSERVATION ANGLE PARAMETERS */

L36:
    gnd_1.ifar = itmp1;
    fpat_1.nth = itmp2;
    fpat_1.nph = itmp3;
    if (fpat_1.nth == 0) {
	fpat_1.nth = 1;
    }
    if (fpat_1.nph == 0) {
	fpat_1.nph = 1;
    }
    fpat_1.ipd = itmp4 / 10;
    fpat_1.iavp = itmp4 - fpat_1.ipd * 10;
    fpat_1.inor = fpat_1.ipd / 10;
    fpat_1.ipd -= fpat_1.inor * 10;
    fpat_1.iax = fpat_1.inor / 10;
    fpat_1.inor -= fpat_1.iax * 10;
    if (fpat_1.iax != 0) {
	fpat_1.iax = 1;
    }
    if (fpat_1.ipd != 0) {
	fpat_1.ipd = 1;
    }
    if (fpat_1.nth < 2 || fpat_1.nph < 2) {
	fpat_1.iavp = 0;
    }
    if (gnd_1.ifar == 1) {
	fpat_1.iavp = 0;
    }
    fpat_1.thets = tmp1;
    fpat_1.phis = tmp2;
    fpat_1.dth = tmp3;
    fpat_1.dph = tmp4;
    fpat_1.rfld = tmp5;
    fpat_1.gnor = tmp6;
    iflow = 10;
    switch (igo) {
	case 1:  goto L41;
	case 2:  goto L46;
	case 3:  goto L53;
	case 4:  goto L71;
	case 5:  goto L78;
    }

/*     WRITE NUMERICAL GREEN'S FUNCTION TAPE */

L322:
    iflow = 12;
    if (matpar_1.icasx == 0) {
	goto L301;
    }
    s_wsfe(&io___114);
    e_wsfe();
    s_stop("", (ftnlen)0);
L301:
    irngf = 1125000;
    switch (igo) {
	case 1:  goto L41;
	case 2:  goto L46;
	case 3:  goto L52;
	case 4:  goto L52;
	case 5:  goto L52;
    }

/*     EXECUTE CARD  -  CALC. INCLUDING RADIATED FIELDS */

L37:
    if (iflow == 10 && itmp1 == 0) {
	goto L14;
    }
    if (nfrq == 1 && itmp1 == 0 && iflow > 7) {
	goto L14;
    }
    if (itmp1 != 0) {
	goto L39;
    }
    if (iflow > 7) {
	goto L38;
    }
    iflow = 7;
    goto L40;
L38:
    iflow = 11;
    goto L40;
L39:
    gnd_1.ifar = 0;
    fpat_1.rfld = 0.f;
    fpat_1.ipd = 0;
    fpat_1.iavp = 0;
    fpat_1.inor = 0;
    fpat_1.iax = 0;
    fpat_1.nth = 91;
    fpat_1.nph = 1;
    fpat_1.thets = 0.f;
    fpat_1.phis = 0.f;
    fpat_1.dth = 1.f;
    fpat_1.dph = 0.f;
    if (itmp1 == 2) {
	fpat_1.phis = 90.f;
    }
    if (itmp1 != 3) {
	goto L40;
    }
    fpat_1.nph = 2;
    fpat_1.dph = 90.f;
L40:
    switch (igo) {
	case 1:  goto L41;
	case 2:  goto L46;
	case 3:  goto L53;
	case 4:  goto L71;
	case 5:  goto L78;
    }

/*     END OF THE MAIN INPUT SECTION */

/*     BEGINNING OF THE FREQUENCY DO LOOP */

L41:
    mhz = 1;
/* *** */
    if (data_1.n == 0 || ifrtimw == 1) {
	goto L406;
    }
    ifrtimw = 1;
    i__2 = data_1.n;
    for (i__ = 1; i__ <= i__2; ++i__) {
	xtemp[i__ - 1] = data_1.x[i__ - 1];
	ytemp[i__ - 1] = data_1.y[i__ - 1];
	ztemp[i__ - 1] = data_1.z__[i__ - 1];
	sitemp[i__ - 1] = data_1.si[i__ - 1];
	bitemp[i__ - 1] = data_1.bi[i__ - 1];
/* L445: */
    }
L406:
    if (data_1.m == 0 || ifrtimp == 1) {
	goto L407;
    }
    ifrtimp = 1;
    j = data_1.ld + 1;
    i__2 = data_1.m;
    for (i__ = 1; i__ <= i__2; ++i__) {
	--j;
	xtemp[j - 1] = data_1.x[j - 1];
	ytemp[j - 1] = data_1.y[j - 1];
	ztemp[j - 1] = data_1.z__[j - 1];
	bitemp[j - 1] = data_1.bi[j - 1];
/* L545: */
    }
L407:
    fmhz1 = save_1.fmhz;
/* *** */
/*     CORE ALLOCATION FOR PRIMARY INTERACTON MATRIX.  (A) */
    if (matpar_1.imat == 0) {
	fblock_(&netcx_1.npeq, &netcx_1.neq, &c_b101, &irngf, &data_1.ipsym);
    }
L42:
    if (mhz == 1) {
	goto L44;
    }
    if (ifrq == 1) {
	goto L43;
    }
/*      FMHZ=FMHZ+DELFRQ */
/* *** */
    save_1.fmhz = fmhz1 + (mhz - 1) * delfrq;
    goto L44;
L43:
    save_1.fmhz *= delfrq;
L44:
    fr = save_1.fmhz / cvel;
/* *** */
    data_1.wlam = cvel / save_1.fmhz;
/* wavl=299.8/freq */
    s_wsfe(&io___124);
    do_fio(&c__1, (char *)&save_1.fmhz, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&data_1.wlam, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___125);
    do_fio(&c__1, (char *)&rkh, (ftnlen)sizeof(doublereal));
    e_wsfe();
    if (iexk == 1) {
	s_wsfe(&io___126);
	e_wsfe();
    }
/*     FREQUENCY SCALING OF GEOMETRIC PARAMETERS */
/* ***      FMHZS=FMHZ */
    if (data_1.n == 0) {
	goto L306;
    }
    i__2 = data_1.n;
    for (i__ = 1; i__ <= i__2; ++i__) {
/* *** */
	data_1.x[i__ - 1] = xtemp[i__ - 1] * fr;
	data_1.y[i__ - 1] = ytemp[i__ - 1] * fr;
	data_1.z__[i__ - 1] = ztemp[i__ - 1] * fr;
	data_1.si[i__ - 1] = sitemp[i__ - 1] * fr;
/* L45: */
	data_1.bi[i__ - 1] = bitemp[i__ - 1] * fr;
    }
/* *** */
L306:
    if (data_1.m == 0) {
	goto L307;
    }
    fr2 = fr * fr;
    j = data_1.ld + 1;
    i__2 = data_1.m;
    for (i__ = 1; i__ <= i__2; ++i__) {
	--j;
/* *** */
	data_1.x[j - 1] = xtemp[j - 1] * fr;
	data_1.y[j - 1] = ytemp[j - 1] * fr;
	data_1.z__[j - 1] = ztemp[j - 1] * fr;
/* L245: */
	data_1.bi[j - 1] = bitemp[j - 1] * fr2;
    }
/* *** */
L307:
    igo = 2;
/*     STRUCTURE SEGMENT LOADING */
L46:
    s_wsfe(&io___128);
    e_wsfe();
    if (zload_1.nload != 0) {
	load_(ldtyp, ldtag, ldtagf, ldtagt, zlr, zli, zlc);
    }
    if (zload_1.nload == 0 && zload_1.nlodf == 0) {
	s_wsfe(&io___129);
	e_wsfe();
    }
    if (zload_1.nload == 0 && zload_1.nlodf != 0) {
	s_wsfe(&io___130);
	e_wsfe();
    }
/*     GROUND PARAMETER */
    s_wsfe(&io___131);
    e_wsfe();
/* Antenna environment */
    if (gnd_1.ksymp == 1) {
	goto L49;
    }
    gnd_1.frati.r = 1.f, gnd_1.frati.i = 0.f;
    if (gnd_1.iperf == 1) {
	goto L48;
    }
/* av03 IF(SIG.LT.0.) SIG=-SIG/(59.96*WLAM) */
    if (save_1.sig < 0.f) {
/* av03, Negative sigma ? */
	llneg = 1;
/* Set flag */
	save_1.sig = -save_1.sig / (data_1.wlam * 59.96f);
/* Make positive */
    }
    d__1 = -save_1.sig * data_1.wlam * 59.96f;
    z__1.r = save_1.epsr, z__1.i = d__1;
    epsc.r = z__1.r, epsc.i = z__1.i;
    z_sqrt(&z__2, &epsc);
    z_div(&z__1, &c_b245, &z__2);
    gnd_1.zrati.r = z__1.r, gnd_1.zrati.i = z__1.i;
    gwav_1.u.r = gnd_1.zrati.r, gwav_1.u.i = gnd_1.zrati.i;
    z__1.r = gwav_1.u.r * gwav_1.u.r - gwav_1.u.i * gwav_1.u.i, z__1.i = 
	    gwav_1.u.r * gwav_1.u.i + gwav_1.u.i * gwav_1.u.r;
    gwav_1.u2.r = z__1.r, gwav_1.u2.i = z__1.i;
    if (gnd_1.nradl == 0) {
	goto L47;
    }
    gnd_1.scrwl = save_1.scrwlt / data_1.wlam;
    gnd_1.scrwr = save_1.scrwrt / data_1.wlam;
    z__2.r = fj.r * 2367.067, z__2.i = fj.i * 2367.067;
    d__1 = (doublereal) gnd_1.nradl;
    z__1.r = z__2.r / d__1, z__1.i = z__2.i / d__1;
    gnd_1.t1.r = z__1.r, gnd_1.t1.i = z__1.i;
    gnd_1.t2 = gnd_1.scrwr * (doublereal) gnd_1.nradl;
    s_wsfe(&io___133);
    do_fio(&c__1, (char *)&gnd_1.nradl, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&save_1.scrwlt, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&save_1.scrwrt, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___134);
    e_wsfe();
L47:
    if (gnd_1.iperf == 2) {
	goto L328;
    }
/* Somnec ground ? */
    s_wsfe(&io___135);
    e_wsfe();
/* Finite ground */
    goto L329;
/* ****************************************************************************** */
/* 	Include SomNec calculations */
/* ****************************************************************************** */
L328:
    if (llneg <= 1) {
/* Single or first step ? */
	if (llneg == 1) {
	    llneg = 2;
	}
/* If negative, only once */
	som2d_(&save_1.fmhz, &save_1.epsr, &save_1.sig);
/* Get SomNec data, av03 */
    }
/* av03 328   IF(NXA(1).EQ.0)THEN */
/*         OPEN(UNIT=21,FILE='SOM2D.NEC',STATUS='OLD',FORM='UNFORMATTED', */
/*     &   ERR=800) */
/*         GO TO 801 */
/* 800      WRITE(3,900) */
/*         STOP */
/* 801      READ(21)AR1,AR2,AR3,EPSCF,DXA,DYA,XSA,YSA,NXA,NYA */
/* av03      END IF */
    z__2.r = epsc.r - 1.f, z__2.i = epsc.i;
    z__3.r = epsc.r + 1.f, z__3.i = epsc.i;
    z_div(&z__1, &z__2, &z__3);
    gnd_1.frati.r = z__1.r, gnd_1.frati.i = z__1.i;
    z__2.r = ggrid_1.epscf.r - epsc.r, z__2.i = ggrid_1.epscf.i - epsc.i;
    z_div(&z__1, &z__2, &epsc);
    if (z_abs(&z__1) < .001) {
	goto L400;
    }
    s_wsfe(&io___136);
    do_fio(&c__2, (char *)&ggrid_1.epscf, (ftnlen)sizeof(doublereal));
    do_fio(&c__2, (char *)&epsc, (ftnlen)sizeof(doublereal));
    e_wsfe();
/* Error in ground param's */
    s_stop("", (ftnlen)0);
L400:
    s_wsfe(&io___137);
    e_wsfe();
/* Sommerfeld ground */
L329:
    s_wsfe(&io___138);
    do_fio(&c__1, (char *)&save_1.epsr, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&save_1.sig, (ftnlen)sizeof(doublereal));
    do_fio(&c__2, (char *)&epsc, (ftnlen)sizeof(doublereal));
    e_wsfe();
/* Rel-diel-C, conduct, compl-diel-C */
    goto L50;
L48:
    s_wsfe(&io___139);
    e_wsfe();
/* Perfect ground */
    goto L50;
L49:
    s_wsfe(&io___140);
    e_wsfe();
/* Free space */
L50:
/* * * * */
/*     FILL AND FACTOR PRIMARY INTERACTION MATRIX */

    second_(&tim1);
    if (matpar_1.icasx != 0) {
	goto L324;
    }
    cmset_(&netcx_1.neq, cmb_1.cm, &rkh, &iexk);
    second_(&tim2);
    tim = tim2 - tim1;
    factrs_(&netcx_1.npeq, &netcx_1.neq, cmb_1.cm, save_1.ip, ix, &c__11, &
	    c__12, &c__13, &c__14);
    goto L323;

/*     N.G.F. - FILL B, C, AND D AND FACTOR D-C(INV(A)B) */

/* **** */
L324:
    if (netcx_1.neq2 == 0) {
	goto L333;
    }
/* **** */
    cmngf_(&cmb_1.cm[ib11 - 1], &cmb_1.cm[ic11 - 1], &cmb_1.cm[id11 - 1], &
	    matpar_1.npbx, &netcx_1.neq, &netcx_1.neq2, &rkh, &iexk);
    second_(&tim2);
    tim = tim2 - tim1;
    facgf_(cmb_1.cm, &cmb_1.cm[ib11 - 1], &cmb_1.cm[ic11 - 1], &cmb_1.cm[id11 
	    - 1], &cmb_1.cm[ix11 - 1], save_1.ip, ix, &data_1.np, &data_1.n1, 
	    &data_1.mp, &data_1.m1, &netcx_1.neq, &netcx_1.neq2);
L323:
    second_(&tim1);
    tim2 = tim1 - tim2;
    s_wsfe(&io___145);
    do_fio(&c__1, (char *)&tim, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&tim2, (ftnlen)sizeof(doublereal));
    e_wsfe();
L333:
    igo = 3;
    netcx_1.ntsol = 0;
    if (iflow != 12) {
	goto L53;
    }
/*     WRITE N.G.F. FILE */
L52:
    gfout_();
    goto L14;

/*     EXCITATION SET UP (RIGHT HAND SIDE, -E INC.) */

L53:
    nthic = 1;
    nphic = 1;
    inc = 1;
    netcx_1.nprint = 0;
L54:
    if (fpat_1.ixtyp == 0 || fpat_1.ixtyp == 5) {
	goto L56;
    }
    if (iptflg <= 0 || fpat_1.ixtyp == 4) {
	s_wsfe(&io___149);
	e_wsfe();
    }
    tmp5 = ta * xpr5;
    tmp4 = ta * xpr4;
    if (fpat_1.ixtyp != 4) {
	goto L55;
    }
    tmp1 = xpr1 / data_1.wlam;
    tmp2 = xpr2 / data_1.wlam;
    tmp3 = xpr3 / data_1.wlam;
    tmp6 = fpat_1.xpr6 / (data_1.wlam * data_1.wlam);
    s_wsfe(&io___150);
    do_fio(&c__1, (char *)&xpr1, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&xpr2, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&xpr3, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&xpr4, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&xpr5, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&fpat_1.xpr6, (ftnlen)sizeof(doublereal));
    e_wsfe();
    goto L56;
L55:
    tmp1 = ta * xpr1;
    tmp2 = ta * xpr2;
    tmp3 = ta * xpr3;
    tmp6 = fpat_1.xpr6;
    if (iptflg <= 0) {
	s_wsfe(&io___151);
	do_fio(&c__1, (char *)&xpr1, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&xpr2, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&xpr3, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&hpol[fpat_1.ixtyp - 1], (ftnlen)sizeof(
		doublereal));
	do_fio(&c__1, (char *)&fpat_1.xpr6, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
L56:
    etmns_(&tmp1, &tmp2, &tmp3, &tmp4, &tmp5, &tmp6, &fpat_1.ixtyp, 
	    crnt_1.cur);

/*     MATRIX SOLVING  (NETWK CALLS SOLVES) */

    if (netcx_1.nonet == 0 || inc > 1) {
	goto L60;
    }
    s_wsfe(&io___152);
    e_wsfe();
    itmp3 = 0;
    itmp1 = netcx_1.ntyp[0];
    for (i__ = 1; i__ <= 2; ++i__) {
	if (itmp1 == 3) {
	    itmp1 = 2;
	}
	if (itmp1 == 2) {
	    s_wsfe(&io___153);
	    e_wsfe();
	}
	if (itmp1 == 1) {
	    s_wsfe(&io___154);
	    e_wsfe();
	}
	i__2 = netcx_1.nonet;
	for (j = 1; j <= i__2; ++j) {
	    itmp2 = netcx_1.ntyp[j - 1];
	    if (itmp2 / itmp1 == 1) {
		goto L57;
	    }
	    itmp3 = itmp2;
	    goto L58;
L57:
	    itmp4 = netcx_1.iseg1[j - 1];
	    itmp5 = netcx_1.iseg2[j - 1];
	    if (itmp2 >= 2 && netcx_1.x11i[j - 1] <= 0.f) {
/* Computing 2nd power */
		d__1 = data_1.x[itmp5 - 1] - data_1.x[itmp4 - 1];
/* Computing 2nd power */
		d__2 = data_1.y[itmp5 - 1] - data_1.y[itmp4 - 1];
/* Computing 2nd power */
		d__3 = data_1.z__[itmp5 - 1] - data_1.z__[itmp4 - 1];
		netcx_1.x11i[j - 1] = data_1.wlam * sqrt(d__1 * d__1 + d__2 * 
			d__2 + d__3 * d__3);
	    }
	    s_wsfe(&io___156);
	    do_fio(&c__1, (char *)&data_1.itag[itmp4 - 1], (ftnlen)sizeof(
		    integer));
	    do_fio(&c__1, (char *)&itmp4, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&data_1.itag[itmp5 - 1], (ftnlen)sizeof(
		    integer));
	    do_fio(&c__1, (char *)&itmp5, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&netcx_1.x11r[j - 1], (ftnlen)sizeof(
		    doublereal));
	    do_fio(&c__1, (char *)&netcx_1.x11i[j - 1], (ftnlen)sizeof(
		    doublereal));
	    do_fio(&c__1, (char *)&netcx_1.x12r[j - 1], (ftnlen)sizeof(
		    doublereal));
	    do_fio(&c__1, (char *)&netcx_1.x12i[j - 1], (ftnlen)sizeof(
		    doublereal));
	    do_fio(&c__1, (char *)&netcx_1.x22r[j - 1], (ftnlen)sizeof(
		    doublereal));
	    do_fio(&c__1, (char *)&netcx_1.x22i[j - 1], (ftnlen)sizeof(
		    doublereal));
	    do_fio(&c__1, (char *)&pnet[(itmp2 << 1) - 2], (ftnlen)sizeof(
		    doublereal));
	    do_fio(&c__1, (char *)&pnet[(itmp2 << 1) - 1], (ftnlen)sizeof(
		    doublereal));
	    e_wsfe();
L58:
	    ;
	}
	if (itmp3 == 0) {
	    goto L60;
	}
	itmp1 = itmp3;
/* L59: */
    }
L60:
    if (inc > 1 && iptflg > 0) {
	netcx_1.nprint = 1;
    }
    netwk_(cmb_1.cm, &cmb_1.cm[ib11 - 1], &cmb_1.cm[ic11 - 1], &cmb_1.cm[id11 
	    - 1], save_1.ip, crnt_1.cur);
    netcx_1.ntsol = 1;
    if (iped == 0) {
	goto L61;
    }
    itmp1 = mhz + (mhz - 1 << 2);
    if (itmp1 > normf - 3) {
	goto L61;
    }
    fnorm[itmp1 - 1] = netcx_1.zped.r;
    fnorm[itmp1] = d_imag(&netcx_1.zped);
    fnorm[itmp1 + 1] = z_abs(&netcx_1.zped);
    fnorm[itmp1 + 2] = cang_(&netcx_1.zped);
    if (iped == 2) {
	goto L61;
    }
    if (fnorm[itmp1 + 1] > zpnorm) {
	zpnorm = fnorm[itmp1 + 1];
    }
L61:

/*     PRINTING STRUCTURE CURRENTS */

    if (data_1.n == 0) {
	goto L308;
    }
    if (iptflg == -1) {
	goto L63;
    }
    if (iptflg > 0) {
	goto L62;
    }
    s_wsfe(&io___158);
    e_wsfe();
    s_wsfe(&io___159);
    e_wsfe();
    goto L63;
L62:
    if (iptflg == 3 || inc > 1) {
	goto L63;
    }
    s_wsfe(&io___160);
    do_fio(&c__1, (char *)&xpr3, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&hpol[fpat_1.ixtyp - 1], (ftnlen)sizeof(doublereal))
	    ;
    do_fio(&c__1, (char *)&fpat_1.xpr6, (ftnlen)sizeof(doublereal));
    e_wsfe();
L63:
    fpat_1.ploss = 0.f;
    itmp1 = 0;
    jump = iptflg + 1;
    i__2 = data_1.n;
    for (i__ = 1; i__ <= i__2; ++i__) {
	i__1 = i__ - 1;
	z__1.r = data_1.wlam * crnt_1.cur[i__1].r, z__1.i = data_1.wlam * 
		crnt_1.cur[i__1].i;
	curi.r = z__1.r, curi.i = z__1.i;
	cmag = z_abs(&curi);
	ph = cang_(&curi);
	if (zload_1.nload == 0 && zload_1.nlodf == 0) {
	    goto L64;
	}
	i__1 = i__ - 1;
	if ((d__1 = zload_1.zarray[i__1].r, abs(d__1)) < 1e-20) {
	    goto L64;
	}
	i__1 = i__ - 1;
	fpat_1.ploss += cmag * .5f * cmag * zload_1.zarray[i__1].r * 
		data_1.si[i__ - 1];
L64:
	if (jump < 0) {
	    goto L68;
	} else if (jump == 0) {
	    goto L69;
	} else {
	    goto L65;
	}
L65:
	if (iptag == 0) {
	    goto L66;
	}
	if (data_1.itag[i__ - 1] != iptag) {
	    goto L69;
	}
L66:
	++itmp1;
	if (itmp1 < iptagf || itmp1 > iptagt) {
	    goto L69;
	}
	if (iptflg == 0) {
	    goto L68;
	}
	if (iptflg < 2 || inc > normf) {
	    goto L67;
	}
	fnorm[inc - 1] = cmag;
	isave = i__;
L67:
	if (iptflg != 3) {
	    s_wsfe(&io___166);
	    do_fio(&c__1, (char *)&xpr1, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&xpr2, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&cmag, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&ph, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
	goto L69;
L68:
	s_wsfe(&io___167);
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&data_1.itag[i__ - 1], (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&data_1.x[i__ - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&data_1.y[i__ - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&data_1.z__[i__ - 1], (ftnlen)sizeof(doublereal)
		);
	do_fio(&c__1, (char *)&data_1.si[i__ - 1], (ftnlen)sizeof(doublereal))
		;
	do_fio(&c__2, (char *)&curi, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&cmag, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ph, (ftnlen)sizeof(doublereal));
	e_wsfe();
/* *** */
	if (plot_1.iplp1 != 1) {
	    goto L69;
	}
	if (plot_1.iplp2 == 1) {
	    s_wsle(&io___168);
	    do_lio(&c__7, &c__1, (char *)&curi, (ftnlen)sizeof(doublecomplex))
		    ;
	    e_wsle();
	}
	if (plot_1.iplp2 == 2) {
	    s_wsle(&io___169);
	    do_lio(&c__5, &c__1, (char *)&cmag, (ftnlen)sizeof(doublereal));
	    do_lio(&c__5, &c__1, (char *)&ph, (ftnlen)sizeof(doublereal));
	    e_wsle();
	}
/* *** */
L69:
	;
    }
    if (iptflq == -1) {
	goto L308;
    }
    s_wsfe(&io___170);
    e_wsfe();
    itmp1 = 0;
    fr = 1e-6 / save_1.fmhz;
    i__2 = data_1.n;
    for (i__ = 1; i__ <= i__2; ++i__) {
	if (iptflq == -2) {
	    goto L318;
	}
	if (iptaq == 0) {
	    goto L317;
	}
	if (data_1.itag[i__ - 1] != iptaq) {
	    goto L316;
	}
L317:
	++itmp1;
	if (itmp1 < iptaqf || itmp1 > iptaqt) {
	    goto L316;
	}
L318:
	d__1 = -crnt_1.bii[i__ - 1];
	i__1 = i__ - 1;
	z__2.r = d__1, z__2.i = crnt_1.bir[i__1];
	z__1.r = fr * z__2.r, z__1.i = fr * z__2.i;
	curi.r = z__1.r, curi.i = z__1.i;
	cmag = z_abs(&curi);
	ph = cang_(&curi);
	s_wsfe(&io___171);
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&data_1.itag[i__ - 1], (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&data_1.x[i__ - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&data_1.y[i__ - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&data_1.z__[i__ - 1], (ftnlen)sizeof(doublereal)
		);
	do_fio(&c__1, (char *)&data_1.si[i__ - 1], (ftnlen)sizeof(doublereal))
		;
	do_fio(&c__2, (char *)&curi, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&cmag, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ph, (ftnlen)sizeof(doublereal));
	e_wsfe();
L316:
	;
    }
L308:
    if (data_1.m == 0) {
	goto L310;
    }
    s_wsfe(&io___172);
    e_wsfe();
    j = data_1.n - 2;
    itmp1 = data_1.ld + 1;
    i__2 = data_1.m;
    for (i__ = 1; i__ <= i__2; ++i__) {
	j += 3;
	--itmp1;
	i__1 = j - 1;
	ex.r = crnt_1.cur[i__1].r, ex.i = crnt_1.cur[i__1].i;
	i__1 = j;
	ey.r = crnt_1.cur[i__1].r, ey.i = crnt_1.cur[i__1].i;
	i__1 = j + 1;
	ez.r = crnt_1.cur[i__1].r, ez.i = crnt_1.cur[i__1].i;
	i__1 = itmp1 - 1;
	z__3.r = t1x[i__1] * ex.r, z__3.i = t1x[i__1] * ex.i;
	i__3 = itmp1 - 1;
	z__4.r = t1y[i__3] * ey.r, z__4.i = t1y[i__3] * ey.i;
	z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
	i__4 = itmp1 - 1;
	z__5.r = t1z[i__4] * ez.r, z__5.i = t1z[i__4] * ez.i;
	z__1.r = z__2.r + z__5.r, z__1.i = z__2.i + z__5.i;
	eth.r = z__1.r, eth.i = z__1.i;
	i__1 = itmp1 - 1;
	z__3.r = t2x[i__1] * ex.r, z__3.i = t2x[i__1] * ex.i;
	i__3 = itmp1 - 1;
	z__4.r = t2y[i__3] * ey.r, z__4.i = t2y[i__3] * ey.i;
	z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
	i__4 = itmp1 - 1;
	z__5.r = t2z[i__4] * ez.r, z__5.i = t2z[i__4] * ez.i;
	z__1.r = z__2.r + z__5.r, z__1.i = z__2.i + z__5.i;
	eph.r = z__1.r, eph.i = z__1.i;
	ethm = z_abs(&eth);
	etha = cang_(&eth);
	ephm = z_abs(&eph);
	epha = cang_(&eph);
/* 309   WRITE(3,198) I,X(ITMP1),Y(ITMP1),Z(ITMP1),ETHM,ETHA,EPHM,EPHA,E */
/*     1X,EY, EZ */
/* *** */
	s_wsfe(&io___182);
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&data_1.x[itmp1 - 1], (ftnlen)sizeof(doublereal)
		);
	do_fio(&c__1, (char *)&data_1.y[itmp1 - 1], (ftnlen)sizeof(doublereal)
		);
	do_fio(&c__1, (char *)&data_1.z__[itmp1 - 1], (ftnlen)sizeof(
		doublereal));
	do_fio(&c__1, (char *)&ethm, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&etha, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ephm, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&epha, (ftnlen)sizeof(doublereal));
	do_fio(&c__2, (char *)&ex, (ftnlen)sizeof(doublereal));
	do_fio(&c__2, (char *)&ey, (ftnlen)sizeof(doublereal));
	do_fio(&c__2, (char *)&ez, (ftnlen)sizeof(doublereal));
	e_wsfe();
	if (plot_1.iplp1 != 1) {
	    goto L309;
	}
	if (plot_1.iplp3 == 1) {
	    s_wsle(&io___183);
	    do_lio(&c__7, &c__1, (char *)&ex, (ftnlen)sizeof(doublecomplex));
	    e_wsle();
	}
	if (plot_1.iplp3 == 2) {
	    s_wsle(&io___184);
	    do_lio(&c__7, &c__1, (char *)&ey, (ftnlen)sizeof(doublecomplex));
	    e_wsle();
	}
	if (plot_1.iplp3 == 3) {
	    s_wsle(&io___185);
	    do_lio(&c__7, &c__1, (char *)&ez, (ftnlen)sizeof(doublecomplex));
	    e_wsle();
	}
	if (plot_1.iplp3 == 4) {
	    s_wsle(&io___186);
	    do_lio(&c__7, &c__1, (char *)&ex, (ftnlen)sizeof(doublecomplex));
	    do_lio(&c__7, &c__1, (char *)&ey, (ftnlen)sizeof(doublecomplex));
	    do_lio(&c__7, &c__1, (char *)&ez, (ftnlen)sizeof(doublecomplex));
	    e_wsle();
	}
L309:
	;
    }
/* *** */
L310:
    if (fpat_1.ixtyp != 0 && fpat_1.ixtyp != 5) {
	goto L70;
    }
    tmp1 = netcx_1.pin - netcx_1.pnls - fpat_1.ploss;
    tmp2 = tmp1 * 100.f / netcx_1.pin;
    s_wsfe(&io___187);
    do_fio(&c__1, (char *)&netcx_1.pin, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&tmp1, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&fpat_1.ploss, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&netcx_1.pnls, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&tmp2, (ftnlen)sizeof(doublereal));
    e_wsfe();
L70:
    igo = 4;
    if (yparm_1.ncoup > 0) {
	couple_(crnt_1.cur, &data_1.wlam);
    }
    if (iflow != 7) {
	goto L71;
    }
    if (fpat_1.ixtyp > 0 && fpat_1.ixtyp < 4) {
	goto L113;
    }
    if (nfrq != 1) {
	goto L120;
    }
    s_wsfe(&io___188);
    e_wsfe();
    goto L14;
L71:
    igo = 5;

/*     NEAR FIELD CALCULATION */

L72:
    if (fpat_1.near__ == -1) {
	goto L78;
    }
    nfpat_();
    if (mhz == nfrq) {
	fpat_1.near__ = -1;
    }
    if (nfrq != 1) {
	goto L78;
    }
    s_wsfe(&io___189);
    e_wsfe();
    goto L14;

/*     STANDARD FAR FIELD CALCULATION */

L78:
    if (gnd_1.ifar == -1) {
	goto L113;
    }
    fpat_1.pinr = netcx_1.pin;
    fpat_1.pnlr = netcx_1.pnls;
    rdpat_();
L113:
    if (fpat_1.ixtyp == 0 || fpat_1.ixtyp >= 4) {
	goto L119;
    }
    ++nthic;
    ++inc;
    xpr1 += xpr4;
    if (nthic <= nthi) {
	goto L54;
    }
    nthic = 1;
    xpr1 = thetis;
    xpr2 += xpr5;
    ++nphic;
    if (nphic <= nphi) {
	goto L54;
    }
    nphic = 1;
    xpr2 = phiss;
    if (iptflg < 2) {
	goto L119;
    }
/*     NORMALIZED RECEIVING PATTERN PRINTED */
    itmp1 = nthi * nphi;
    if (itmp1 <= normf) {
	goto L114;
    }
    itmp1 = normf;
    s_wsfe(&io___190);
    e_wsfe();
L114:
    tmp1 = fnorm[0];
    i__2 = itmp1;
    for (j = 2; j <= i__2; ++j) {
	if (fnorm[j - 1] > tmp1) {
	    tmp1 = fnorm[j - 1];
	}
/* L115: */
    }
    s_wsfe(&io___191);
    do_fio(&c__1, (char *)&tmp1, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&xpr3, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&hpol[fpat_1.ixtyp - 1], (ftnlen)sizeof(doublereal))
	    ;
    do_fio(&c__1, (char *)&fpat_1.xpr6, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&isave, (ftnlen)sizeof(integer));
    e_wsfe();
    i__2 = nphi;
    for (j = 1; j <= i__2; ++j) {
	itmp2 = nthi * (j - 1);
	i__1 = nthi;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    itmp3 = i__ + itmp2;
	    if (itmp3 > itmp1) {
		goto L117;
	    }
	    tmp2 = fnorm[itmp3 - 1] / tmp1;
	    tmp3 = db20_(&tmp2);
	    s_wsfe(&io___192);
	    do_fio(&c__1, (char *)&xpr1, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&xpr2, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&tmp3, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&tmp2, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	    xpr1 += xpr4;
/* L116: */
	}
L117:
	xpr1 = thetis;
	xpr2 += xpr5;
/* L118: */
    }
    xpr2 = phiss;
L119:
    if (mhz == nfrq) {
	gnd_1.ifar = -1;
    }
    if (nfrq != 1) {
	goto L120;
    }
    s_wsfe(&io___193);
    e_wsfe();
    goto L14;
L120:
    ++mhz;
    if (mhz <= nfrq) {
	goto L42;
    }
    if (iped == 0) {
	goto L123;
    }
    if (vsorc_1.nvqd < 1) {
	goto L199;
    }
    s_wsfe(&io___194);
    do_fio(&c__1, (char *)&vsorc_1.ivqd[vsorc_1.nvqd - 1], (ftnlen)sizeof(
	    integer));
    do_fio(&c__1, (char *)&zpnorm, (ftnlen)sizeof(doublereal));
    e_wsfe();
    goto L204;
L199:
    s_wsfe(&io___195);
    do_fio(&c__1, (char *)&vsorc_1.isant[vsorc_1.nsant - 1], (ftnlen)sizeof(
	    integer));
    do_fio(&c__1, (char *)&zpnorm, (ftnlen)sizeof(doublereal));
    e_wsfe();
L204:
    itmp1 = nfrq;
    if (itmp1 <= normf / 4) {
	goto L121;
    }
    itmp1 = normf / 4;
    s_wsfe(&io___196);
    e_wsfe();
L121:
    if (ifrq == 0) {
	tmp1 = save_1.fmhz - (nfrq - 1) * delfrq;
    }
    if (ifrq == 1) {
	i__2 = nfrq - 1;
	tmp1 = save_1.fmhz / pow_di(&delfrq, &i__2);
    }
    i__2 = itmp1;
    for (i__ = 1; i__ <= i__2; ++i__) {
	itmp2 = i__ + (i__ - 1 << 2);
	tmp2 = fnorm[itmp2 - 1] / zpnorm;
	tmp3 = fnorm[itmp2] / zpnorm;
	tmp4 = fnorm[itmp2 + 1] / zpnorm;
	tmp5 = fnorm[itmp2 + 2];
	s_wsfe(&io___197);
	do_fio(&c__1, (char *)&tmp1, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&fnorm[itmp2 - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&fnorm[itmp2], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&fnorm[itmp2 + 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&fnorm[itmp2 + 2], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&tmp2, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&tmp3, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&tmp4, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&tmp5, (ftnlen)sizeof(doublereal));
	e_wsfe();
	if (ifrq == 0) {
	    tmp1 += delfrq;
	}
	if (ifrq == 1) {
	    tmp1 *= delfrq;
	}
/* L122: */
    }
    s_wsfe(&io___198);
    e_wsfe();
L123:
    nfrq = 1;
    mhz = 1;
    goto L14;
/* L136: */
/* L900: */
} /* MAIN__ */

#undef sab
#undef cab
#undef t2z
#undef t2y
#undef t2x
#undef t1z
#undef t1y
#undef t1x
#undef z2
#undef y2
#undef x2
#undef pnet
#undef hpol


/* av03 ################## START OF SOM2D INCLUDE ######################## */
/* *********************************************************************** */
/* Subroutine */ int som2d_(doublereal *rmhz, doublereal *repr, doublereal *
	rsig)
{
    /* Initialized data */

    static char lcomp[3*4] = "ERV" "EZV" "ERH" "EPH";

    /* Format strings */
    static char fmt_17[] = "(\0021NEC GROUND INTERPOLATION GRID\002,/,\002 D"
	    "IELECTRIC CONSTANT=\002,1p2e12.5)";
    static char fmt_18[] = "(///,\002 GRID\002,i2,/,4x,\002R(1)=\002,f7.4,"
	    "4x,\002DR=\002,f7.4,4x,\002NR=\002,i3,/,\002 THET(1)=\002,f7.4,3"
	    "x,\002DTH=\002,f7.4,3x,\002NTH=\002,i3,//)";
    static char fmt_19[] = "(///,1x,a3)";
    static char fmt_20[] = "(\002 IR=\002,i3,/,1x,(1p10e12.5))";

    /* System generated locals */
    integer i__1, i__2, i__3;
    doublereal d__1, d__2;
    doublecomplex z__1, z__2, z__3, z__4;
    olist o__1;

    /* Builtin functions */
    void d_cnjg(doublecomplex *, doublecomplex *), z_sqrt(doublecomplex *, 
	    doublecomplex *);
    double z_abs(doublecomplex *);
    void z_div(doublecomplex *, doublecomplex *, doublecomplex *);
    double cos(doublereal), sin(doublereal);
    integer f_open(olist *), s_wsfe(cilist *), do_fio(integer *, char *, 
	    ftnlen), e_wsfe(void);

    /* Local variables */
    integer k, l;
    doublereal r__, dr;
    integer ir;
    doublereal rk;
    integer nr;
    doublecomplex cl1, cl2, eph, erh, con;
    doublereal dth, sig;
    integer ith;
    doublereal epr;
    integer nth;
    doublecomplex erv;
    integer ipt, irs;
    doublecomplex ezv;
    doublereal wlam, fmhz, thet, tfac1, tfac2;
    extern /* Subroutine */ int evlua_(doublecomplex *, doublecomplex *, 
	    doublecomplex *, doublecomplex *);

    /* Fortran I/O blocks */
    static cilist io___227 = { 0, 3, 0, fmt_17, 0 };
    static cilist io___228 = { 0, 9, 0, fmt_18, 0 };
    static cilist io___230 = { 0, 9, 0, fmt_19, 0 };
    static cilist io___231 = { 0, 9, 0, fmt_20, 0 };
    static cilist io___232 = { 0, 9, 0, fmt_20, 0 };
    static cilist io___233 = { 0, 9, 0, fmt_20, 0 };


/* *********************************************************************** */
/* *** */

/* av03 999   WRITE(*,21) */
/* av03 READ(*,*,ERR=999) EPR,SIG,FMHZ,IPT */
    epr = *repr;
/* av03 */
    sig = *rsig;
/* av03 */
    fmhz = *rmhz;
/* av03 */
    ipt = 0;
/* deb	write (*,100) fmhz,epr,sig */
/* deb  100 format (' Som2d: Freq=',d10.5,' Diel=',d10.5,' Cond=',d10.5) */
/* av03      WRITE(*,100) EPR */
/* av03100   FORMAT("  RELATIVE DIELECTRIC CONSTANT (EPR)  = ", D20.5) */
/* av03      WRITE(*,101) SIG */
/* av03101   FORMAT("  SIGMA [CONDUCTIVITY IN MHOS/METER]  = ", D20.5) */
/* av03      WRITE(*,102) FMHZ */
/* av03102   FORMAT("                     FREQUENCY IN MHZ = ", D20.5) */
/* av03      IF(IPT == 1) WRITE(*,*) "   GRID FILE [SOM2D.OUT] WILL BE CREATED" */
/* av03      IF(IPT == 0) WRITE(*,*) "   NO GRID FILE WILL BE CREATED" */
/* av03      WRITE(*,*) */
/* *** */
/* No printing, av03 */
    if (sig < 0.f) {
	goto L1;
    }
    wlam = 299.8f / fmhz;
    d__1 = -sig * wlam * 59.96f;
    z__1.r = epr, z__1.i = d__1;
    ggrid_1.epscf.r = z__1.r, ggrid_1.epscf.i = z__1.i;
    goto L2;
L1:
    z__1.r = epr, z__1.i = sig;
    ggrid_1.epscf.r = z__1.r, ggrid_1.epscf.i = z__1.i;
L2:
/* av03 2     CALL SECOND (TST) */
    evlcom_1.ck2 = 6.283185308f;
    evlcom_1.ck2sq = evlcom_1.ck2 * evlcom_1.ck2;

/*     SOMMERFELD INTEGRAL EVALUATION USES EXP(-JWT), NEC USES EXP(+JWT), */
/*     HENCE NEED CONJG(EPSCF).  CONJUGATE OF FIELDS OCCURS IN SUBROUTINE */
/*     EVLUA. */

    d_cnjg(&z__2, &ggrid_1.epscf);
    z__1.r = evlcom_1.ck2sq * z__2.r, z__1.i = evlcom_1.ck2sq * z__2.i;
    evlcom_1.ck1sq.r = z__1.r, evlcom_1.ck1sq.i = z__1.i;
    z_sqrt(&z__1, &evlcom_1.ck1sq);
    evlcom_1.ck1.r = z__1.r, evlcom_1.ck1.i = z__1.i;
    evlcom_1.ck1r = evlcom_1.ck1.r;
    evlcom_1.tkmag = z_abs(&evlcom_1.ck1) * 100.f;
    z__2.r = evlcom_1.ck1.r * 100.f, z__2.i = evlcom_1.ck1.i * 100.f;
    d_cnjg(&z__3, &evlcom_1.ck1);
    z__1.r = z__2.r * z__3.r - z__2.i * z__3.i, z__1.i = z__2.r * z__3.i + 
	    z__2.i * z__3.r;
    evlcom_1.tsmag = z__1.r;
    z__2.r = evlcom_1.ck2sq, z__2.i = 0.;
    z__3.r = evlcom_1.ck1sq.r + evlcom_1.ck2sq, z__3.i = evlcom_1.ck1sq.i;
    z_div(&z__1, &z__2, &z__3);
    evlcom_1.cksm.r = z__1.r, evlcom_1.cksm.i = z__1.i;
    z__2.r = evlcom_1.ck1sq.r - evlcom_1.ck2sq, z__2.i = evlcom_1.ck1sq.i;
    z__1.r = z__2.r * .5f, z__1.i = z__2.i * .5f;
    evlcom_1.ct1.r = z__1.r, evlcom_1.ct1.i = z__1.i;
    z__1.r = evlcom_1.ck1sq.r * evlcom_1.ck1sq.r - evlcom_1.ck1sq.i * 
	    evlcom_1.ck1sq.i, z__1.i = evlcom_1.ck1sq.r * evlcom_1.ck1sq.i + 
	    evlcom_1.ck1sq.i * evlcom_1.ck1sq.r;
    erv.r = z__1.r, erv.i = z__1.i;
    d__1 = evlcom_1.ck2sq * evlcom_1.ck2sq;
    ezv.r = d__1, ezv.i = 0.;
    z__2.r = erv.r - ezv.r, z__2.i = erv.i - ezv.i;
    z__1.r = z__2.r * .125f, z__1.i = z__2.i * .125f;
    evlcom_1.ct2.r = z__1.r, evlcom_1.ct2.i = z__1.i;
    z__1.r = erv.r * evlcom_1.ck1sq.r - erv.i * evlcom_1.ck1sq.i, z__1.i = 
	    erv.r * evlcom_1.ck1sq.i + erv.i * evlcom_1.ck1sq.r;
    erv.r = z__1.r, erv.i = z__1.i;
    z__1.r = evlcom_1.ck2sq * ezv.r, z__1.i = evlcom_1.ck2sq * ezv.i;
    ezv.r = z__1.r, ezv.i = z__1.i;
    z__2.r = erv.r - ezv.r, z__2.i = erv.i - ezv.i;
    z__1.r = z__2.r * .0625f, z__1.i = z__2.i * .0625f;
    evlcom_1.ct3.r = z__1.r, evlcom_1.ct3.i = z__1.i;

/*     LOOP OVER 3 GRID REGIONS */

    for (k = 1; k <= 3; ++k) {
	nr = ggrid_1.nxa[k - 1];
	nth = ggrid_1.nya[k - 1];
	dr = ggrid_1.dxa[k - 1];
	dth = ggrid_1.dya[k - 1];
	r__ = ggrid_1.xsa[k - 1] - dr;
	irs = 1;
	if (k == 1) {
	    r__ = ggrid_1.xsa[k - 1];
	}
	if (k == 1) {
	    irs = 2;
	}

/*     LOOP OVER R.  (R=SQRT(RHO**2 + (Z+H)**2)) */

	i__1 = nr;
	for (ir = irs; ir <= i__1; ++ir) {
	    r__ += dr;
	    thet = ggrid_1.ysa[k - 1] - dth;

/*     LOOP OVER THETA.  (THETA=ATAN((Z+H)/RHO)) */

	    i__2 = nth;
	    for (ith = 1; ith <= i__2; ++ith) {
		thet += dth;
		evlcom_1.rho = r__ * cos(thet);
		evlcom_1.zph = r__ * sin(thet);
		if (evlcom_1.rho < 1e-7f) {
		    evlcom_1.rho = 1e-8f;
		}
		if (evlcom_1.zph < 1e-7f) {
		    evlcom_1.zph = 0.f;
		}
		evlua_(&erv, &ezv, &erh, &eph);
		rk = evlcom_1.ck2 * r__;
		z__2.r = r__ * -0.f, z__2.i = r__ * -4.77147f;
		d__1 = cos(rk);
		d__2 = -sin(rk);
		z__3.r = d__1, z__3.i = d__2;
		z_div(&z__1, &z__2, &z__3);
		con.r = z__1.r, con.i = z__1.i;
		switch (k) {
		    case 1:  goto L3;
		    case 2:  goto L4;
		    case 3:  goto L5;
		}
L3:
		i__3 = ir + (ith + 10) * 11 - 122;
		z__1.r = erv.r * con.r - erv.i * con.i, z__1.i = erv.r * 
			con.i + erv.i * con.r;
		ggrid_1.ar1[i__3].r = z__1.r, ggrid_1.ar1[i__3].i = z__1.i;
		i__3 = ir + (ith + 20) * 11 - 122;
		z__1.r = ezv.r * con.r - ezv.i * con.i, z__1.i = ezv.r * 
			con.i + ezv.i * con.r;
		ggrid_1.ar1[i__3].r = z__1.r, ggrid_1.ar1[i__3].i = z__1.i;
		i__3 = ir + (ith + 30) * 11 - 122;
		z__1.r = erh.r * con.r - erh.i * con.i, z__1.i = erh.r * 
			con.i + erh.i * con.r;
		ggrid_1.ar1[i__3].r = z__1.r, ggrid_1.ar1[i__3].i = z__1.i;
		i__3 = ir + (ith + 40) * 11 - 122;
		z__1.r = eph.r * con.r - eph.i * con.i, z__1.i = eph.r * 
			con.i + eph.i * con.r;
		ggrid_1.ar1[i__3].r = z__1.r, ggrid_1.ar1[i__3].i = z__1.i;
		goto L6;
L4:
		i__3 = ir + (ith + 5) * 17 - 103;
		z__1.r = erv.r * con.r - erv.i * con.i, z__1.i = erv.r * 
			con.i + erv.i * con.r;
		ggrid_1.ar2[i__3].r = z__1.r, ggrid_1.ar2[i__3].i = z__1.i;
		i__3 = ir + (ith + 10) * 17 - 103;
		z__1.r = ezv.r * con.r - ezv.i * con.i, z__1.i = ezv.r * 
			con.i + ezv.i * con.r;
		ggrid_1.ar2[i__3].r = z__1.r, ggrid_1.ar2[i__3].i = z__1.i;
		i__3 = ir + (ith + 15) * 17 - 103;
		z__1.r = erh.r * con.r - erh.i * con.i, z__1.i = erh.r * 
			con.i + erh.i * con.r;
		ggrid_1.ar2[i__3].r = z__1.r, ggrid_1.ar2[i__3].i = z__1.i;
		i__3 = ir + (ith + 20) * 17 - 103;
		z__1.r = eph.r * con.r - eph.i * con.i, z__1.i = eph.r * 
			con.i + eph.i * con.r;
		ggrid_1.ar2[i__3].r = z__1.r, ggrid_1.ar2[i__3].i = z__1.i;
		goto L6;
L5:
		i__3 = ir + (ith + 8) * 9 - 82;
		z__1.r = erv.r * con.r - erv.i * con.i, z__1.i = erv.r * 
			con.i + erv.i * con.r;
		ggrid_1.ar3[i__3].r = z__1.r, ggrid_1.ar3[i__3].i = z__1.i;
		i__3 = ir + (ith + 16) * 9 - 82;
		z__1.r = ezv.r * con.r - ezv.i * con.i, z__1.i = ezv.r * 
			con.i + ezv.i * con.r;
		ggrid_1.ar3[i__3].r = z__1.r, ggrid_1.ar3[i__3].i = z__1.i;
		i__3 = ir + (ith + 24) * 9 - 82;
		z__1.r = erh.r * con.r - erh.i * con.i, z__1.i = erh.r * 
			con.i + erh.i * con.r;
		ggrid_1.ar3[i__3].r = z__1.r, ggrid_1.ar3[i__3].i = z__1.i;
		i__3 = ir + (ith + 32) * 9 - 82;
		z__1.r = eph.r * con.r - eph.i * con.i, z__1.i = eph.r * 
			con.i + eph.i * con.r;
		ggrid_1.ar3[i__3].r = z__1.r, ggrid_1.ar3[i__3].i = z__1.i;
L6:
		;
	    }
	}
    }

/*     FILL GRID 1 FOR R EQUAL TO ZERO. */

    z__3.r = ggrid_1.epscf.r - 1.f, z__3.i = ggrid_1.epscf.i;
    z__2.r = z__3.r * -0.f - z__3.i * -188.37f, z__2.i = z__3.r * -188.37f + 
	    z__3.i * -0.f;
    z__4.r = ggrid_1.epscf.r + 1.f, z__4.i = ggrid_1.epscf.i;
    z_div(&z__1, &z__2, &z__4);
    cl2.r = z__1.r, cl2.i = z__1.i;
    z__2.r = ggrid_1.epscf.r + 1.f, z__2.i = ggrid_1.epscf.i;
    z_div(&z__1, &cl2, &z__2);
    cl1.r = z__1.r, cl1.i = z__1.i;
    z__1.r = ggrid_1.epscf.r * cl1.r - ggrid_1.epscf.i * cl1.i, z__1.i = 
	    ggrid_1.epscf.r * cl1.i + ggrid_1.epscf.i * cl1.r;
    ezv.r = z__1.r, ezv.i = z__1.i;
    thet = -dth;
    nth = ggrid_1.nya[0];
    i__2 = nth;
    for (ith = 1; ith <= i__2; ++ith) {
	thet += dth;
	if (ith == nth) {
	    goto L7;
	}
	tfac2 = cos(thet);
	tfac1 = (1.f - sin(thet)) / tfac2;
	tfac2 = tfac1 / tfac2;
	z__2.r = ggrid_1.epscf.r * cl1.r - ggrid_1.epscf.i * cl1.i, z__2.i = 
		ggrid_1.epscf.r * cl1.i + ggrid_1.epscf.i * cl1.r;
	z__1.r = tfac1 * z__2.r, z__1.i = tfac1 * z__2.i;
	erv.r = z__1.r, erv.i = z__1.i;
	d__1 = tfac2 - 1.f;
	z__2.r = d__1 * cl1.r, z__2.i = d__1 * cl1.i;
	z__1.r = z__2.r + cl2.r, z__1.i = z__2.i + cl2.i;
	erh.r = z__1.r, erh.i = z__1.i;
	z__2.r = tfac2 * cl1.r, z__2.i = tfac2 * cl1.i;
	z__1.r = z__2.r - cl2.r, z__1.i = z__2.i - cl2.i;
	eph.r = z__1.r, eph.i = z__1.i;
	goto L8;
L7:
	erv.r = 0.f, erv.i = 0.f;
	z__2.r = cl1.r * .5f, z__2.i = cl1.i * .5f;
	z__1.r = cl2.r - z__2.r, z__1.i = cl2.i - z__2.i;
	erh.r = z__1.r, erh.i = z__1.i;
	z__1.r = -erh.r, z__1.i = -erh.i;
	eph.r = z__1.r, eph.i = z__1.i;
L8:
	i__1 = (ith + 10) * 11 - 121;
	ggrid_1.ar1[i__1].r = erv.r, ggrid_1.ar1[i__1].i = erv.i;
	i__1 = (ith + 20) * 11 - 121;
	ggrid_1.ar1[i__1].r = ezv.r, ggrid_1.ar1[i__1].i = ezv.i;
	i__1 = (ith + 30) * 11 - 121;
	ggrid_1.ar1[i__1].r = erh.r, ggrid_1.ar1[i__1].i = erh.i;
/* L9: */
	i__1 = (ith + 40) * 11 - 121;
	ggrid_1.ar1[i__1].r = eph.r, ggrid_1.ar1[i__1].i = eph.i;
    }
/* av03 CALL SECOND (TIM) */

/*     WRITE GRID ON TAPE21 */

/* av03      OPEN(UNIT=21,FILE='SOM2D.NEC',STATUS='UNKNOWN',FORM='UNFORMATTED') */
/* av03      WRITE (21) AR1,AR2,AR3,EPSCF,DXA,DYA,XSA,YSA,NXA,NYA */
/* av03      REWIND 21 */
/* av03      IF (IPT.EQ.0) GO TO 14 */
    if (ipt == 0) {
	return 0;
    }

/*     PRINT GRID */

/* av03 OPEN (UNIT=3,FILE='SOM2D.OUT',STATUS='NEW',ERR=14) */
/* AV04 OPEN (UNIT=9,FILE='SOM2D.OUT',STATUS='NEW',ERR=14)	! av03 */
/* av03 */
    o__1.oerr = 1;
    o__1.ounit = 9;
    o__1.ofnmlen = 9;
    o__1.ofnm = "SOM2D.OUT";
    o__1.orl = 0;
    o__1.osta = "UNKNOWN";
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    i__1 = f_open(&o__1);
    if (i__1 != 0) {
	goto L14;
    }
/* av04 */
    s_wsfe(&io___227);
    do_fio(&c__2, (char *)&ggrid_1.epscf, (ftnlen)sizeof(doublereal));
    e_wsfe();
    for (k = 1; k <= 3; ++k) {
	nr = ggrid_1.nxa[k - 1];
	nth = ggrid_1.nya[k - 1];
	s_wsfe(&io___228);
	do_fio(&c__1, (char *)&k, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&ggrid_1.xsa[k - 1], (ftnlen)sizeof(doublereal))
		;
	do_fio(&c__1, (char *)&ggrid_1.dxa[k - 1], (ftnlen)sizeof(doublereal))
		;
	do_fio(&c__1, (char *)&nr, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&ggrid_1.ysa[k - 1], (ftnlen)sizeof(doublereal))
		;
	do_fio(&c__1, (char *)&ggrid_1.dya[k - 1], (ftnlen)sizeof(doublereal))
		;
	do_fio(&c__1, (char *)&nth, (ftnlen)sizeof(integer));
	e_wsfe();
	for (l = 1; l <= 4; ++l) {
	    s_wsfe(&io___230);
	    do_fio(&c__1, lcomp + (l - 1) * 3, (ftnlen)3);
	    e_wsfe();
	    i__1 = nr;
	    for (ir = 1; ir <= i__1; ++ir) {
		switch (k) {
		    case 1:  goto L10;
		    case 2:  goto L11;
		    case 3:  goto L12;
		}
L10:
		s_wsfe(&io___231);
		do_fio(&c__1, (char *)&ir, (ftnlen)sizeof(integer));
		i__2 = nth;
		for (ith = 1; ith <= i__2; ++ith) {
		    do_fio(&c__2, (char *)&ggrid_1.ar1[ir + (ith + l * 10) * 
			    11 - 122], (ftnlen)sizeof(doublereal));
		}
		e_wsfe();
		goto L13;
L11:
		s_wsfe(&io___232);
		do_fio(&c__1, (char *)&ir, (ftnlen)sizeof(integer));
		i__2 = nth;
		for (ith = 1; ith <= i__2; ++ith) {
		    do_fio(&c__2, (char *)&ggrid_1.ar2[ir + (ith + l * 5) * 
			    17 - 103], (ftnlen)sizeof(doublereal));
		}
		e_wsfe();
		goto L13;
L12:
		s_wsfe(&io___233);
		do_fio(&c__1, (char *)&ir, (ftnlen)sizeof(integer));
		i__2 = nth;
		for (ith = 1; ith <= i__2; ++ith) {
		    do_fio(&c__2, (char *)&ggrid_1.ar3[ir + (ith + (l << 3)) *
			     9 - 82], (ftnlen)sizeof(doublereal));
		}
		e_wsfe();
L13:
		;
	    }
	}
    }
/* av03 14    TIM=TIM-TST */
/* av03 WRITE(*,16) TIM */
/* av03	STOP */
L14:
    return 0;

/* av03 */
/* L16: */
/* L21: */
/* L22: */
} /* som2d_ */

/* *********************************************************************** */
/* Subroutine */ int somset_(void)
{
    return 0;
} /* somset_ */

/* *********************************************************************** */

/* *********************************************************************** */
/* Subroutine */ int bessel_(doublecomplex *z__, doublecomplex *j0, 
	doublecomplex *j0p)
{
    /* Initialized data */

    static doublereal c3 = .7978845608;
    static doublereal p10 = .0703125;
    static doublereal p20 = .1121520996;
    static doublereal q10 = .125;
    static doublereal q20 = .0732421875;
    static doublereal p11 = .1171875;
    static doublereal p21 = .1441955566;
    static doublereal q11 = .375;
    static doublereal q21 = .1025390625;
    static doublereal pof = .7853981635;
    static integer init = 0;
    static struct {
	doublereal e_1[2];
	} equiv_0 = { 0., 1. };


    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2;
    doublecomplex z__1, z__2, z__3, z__4, z__5;

    /* Builtin functions */
    void d_cnjg(doublecomplex *, doublecomplex *), z_div(doublecomplex *, 
	    doublecomplex *, doublecomplex *), z_exp(doublecomplex *, 
	    doublecomplex *), z_sqrt(doublecomplex *, doublecomplex *);
    double sqrt(doublereal), cos(doublereal);

    /* Local variables */
    static integer i__, k, m[101];
    static doublereal a1[25], a2[25];
    static integer ib;
#define fj ((doublecomplex *)&equiv_0)
    static doublecomplex cz, zi;
    static integer iz;
    static doublecomplex zk, sz, j0x, zi2, p0z, p1z, q0z, q1z;
#define fjx ((doublereal *)&equiv_0)
    static integer miz;
    static doublereal zms;
    static doublecomplex j0px;
    static doublereal test;

/* *********************************************************************** */

/*     BESSEL EVALUATES THE ZERO-ORDER BESSEL FUNCTION AND ITS DERIVATIVE */
/*     FOR COMPLEX ARGUMENT Z. */

/* av03      DATA PI,C3,P10,P20,Q10,Q20/3.141592654,.7978845608,.0703125,.11215 */
/* av03     120996,.125,.0732421875/ */
    if (init == 0) {
	goto L5;
    }
L1:
    d_cnjg(&z__2, z__);
    z__1.r = z__->r * z__2.r - z__->i * z__2.i, z__1.i = z__->r * z__2.i + 
	    z__->i * z__2.r;
    zms = z__1.r;
    if (zms > 1e-12f) {
	goto L2;
    }
    j0->r = 1.f, j0->i = 0.f;
    z__1.r = z__->r * -.5f, z__1.i = z__->i * -.5f;
    j0p->r = z__1.r, j0p->i = z__1.i;
    return 0;
L2:
    ib = 0;
    if (zms > 37.21f) {
	goto L4;
    }
    if (zms > 36.f) {
	ib = 1;
    }
/*     SERIES EXPANSION */
    iz = (integer) (zms + 1.f);
    miz = m[iz - 1];
    j0->r = 1.f, j0->i = 0.f;
    j0p->r = j0->r, j0p->i = j0->i;
    zk.r = j0->r, zk.i = j0->i;
    z__1.r = z__->r * z__->r - z__->i * z__->i, z__1.i = z__->r * z__->i + 
	    z__->i * z__->r;
    zi.r = z__1.r, zi.i = z__1.i;
    i__1 = miz;
    for (k = 1; k <= i__1; ++k) {
	i__2 = k - 1;
	z__2.r = a1[i__2] * zk.r, z__2.i = a1[i__2] * zk.i;
	z__1.r = z__2.r * zi.r - z__2.i * zi.i, z__1.i = z__2.r * zi.i + 
		z__2.i * zi.r;
	zk.r = z__1.r, zk.i = z__1.i;
	z__1.r = j0->r + zk.r, z__1.i = j0->i + zk.i;
	j0->r = z__1.r, j0->i = z__1.i;
/* L3: */
	i__2 = k - 1;
	z__2.r = a2[i__2] * zk.r, z__2.i = a2[i__2] * zk.i;
	z__1.r = j0p->r + z__2.r, z__1.i = j0p->i + z__2.i;
	j0p->r = z__1.r, j0p->i = z__1.i;
    }
    z__2.r = z__->r * -.5f, z__2.i = z__->i * -.5f;
    z__1.r = z__2.r * j0p->r - z__2.i * j0p->i, z__1.i = z__2.r * j0p->i + 
	    z__2.i * j0p->r;
    j0p->r = z__1.r, j0p->i = z__1.i;
    if (ib == 0) {
	return 0;
    }
    j0x.r = j0->r, j0x.i = j0->i;
    j0px.r = j0p->r, j0px.i = j0p->i;
/*     ASYMPTOTIC EXPANSION */
L4:
    z_div(&z__1, &c_b245, z__);
    zi.r = z__1.r, zi.i = z__1.i;
    z__1.r = zi.r * zi.r - zi.i * zi.i, z__1.i = zi.r * zi.i + zi.i * zi.r;
    zi2.r = z__1.r, zi2.i = z__1.i;
    z__4.r = p20 * zi2.r, z__4.i = p20 * zi2.i;
    z__3.r = z__4.r - p10, z__3.i = z__4.i;
    z__2.r = z__3.r * zi2.r - z__3.i * zi2.i, z__2.i = z__3.r * zi2.i + 
	    z__3.i * zi2.r;
    z__1.r = z__2.r + 1.f, z__1.i = z__2.i;
    p0z.r = z__1.r, p0z.i = z__1.i;
    z__4.r = p21 * zi2.r, z__4.i = p21 * zi2.i;
    z__3.r = p11 - z__4.r, z__3.i = -z__4.i;
    z__2.r = z__3.r * zi2.r - z__3.i * zi2.i, z__2.i = z__3.r * zi2.i + 
	    z__3.i * zi2.r;
    z__1.r = z__2.r + 1.f, z__1.i = z__2.i;
    p1z.r = z__1.r, p1z.i = z__1.i;
    z__3.r = q20 * zi2.r, z__3.i = q20 * zi2.i;
    z__2.r = z__3.r - q10, z__2.i = z__3.i;
    z__1.r = z__2.r * zi.r - z__2.i * zi.i, z__1.i = z__2.r * zi.i + z__2.i * 
	    zi.r;
    q0z.r = z__1.r, q0z.i = z__1.i;
    z__3.r = q21 * zi2.r, z__3.i = q21 * zi2.i;
    z__2.r = q11 - z__3.r, z__2.i = -z__3.i;
    z__1.r = z__2.r * zi.r - z__2.i * zi.i, z__1.i = z__2.r * zi.i + z__2.i * 
	    zi.r;
    q1z.r = z__1.r, q1z.i = z__1.i;
    z__3.r = z__->r - pof, z__3.i = z__->i;
    z__2.r = fj->r * z__3.r - fj->i * z__3.i, z__2.i = fj->r * z__3.i + fj->i 
	    * z__3.r;
    z_exp(&z__1, &z__2);
    zk.r = z__1.r, zk.i = z__1.i;
    z_div(&z__1, &c_b245, &zk);
    zi2.r = z__1.r, zi2.i = z__1.i;
    z__2.r = zk.r + zi2.r, z__2.i = zk.i + zi2.i;
    z__1.r = z__2.r * .5f, z__1.i = z__2.i * .5f;
    cz.r = z__1.r, cz.i = z__1.i;
    z__2.r = fj->r * .5f, z__2.i = fj->i * .5f;
    z__3.r = zi2.r - zk.r, z__3.i = zi2.i - zk.i;
    z__1.r = z__2.r * z__3.r - z__2.i * z__3.i, z__1.i = z__2.r * z__3.i + 
	    z__2.i * z__3.r;
    sz.r = z__1.r, sz.i = z__1.i;
    z_sqrt(&z__2, &zi);
    z__1.r = c3 * z__2.r, z__1.i = c3 * z__2.i;
    zk.r = z__1.r, zk.i = z__1.i;
    z__3.r = p0z.r * cz.r - p0z.i * cz.i, z__3.i = p0z.r * cz.i + p0z.i * 
	    cz.r;
    z__4.r = q0z.r * sz.r - q0z.i * sz.i, z__4.i = q0z.r * sz.i + q0z.i * 
	    sz.r;
    z__2.r = z__3.r - z__4.r, z__2.i = z__3.i - z__4.i;
    z__1.r = zk.r * z__2.r - zk.i * z__2.i, z__1.i = zk.r * z__2.i + zk.i * 
	    z__2.r;
    j0->r = z__1.r, j0->i = z__1.i;
    z__2.r = -zk.r, z__2.i = -zk.i;
    z__4.r = p1z.r * sz.r - p1z.i * sz.i, z__4.i = p1z.r * sz.i + p1z.i * 
	    sz.r;
    z__5.r = q1z.r * cz.r - q1z.i * cz.i, z__5.i = q1z.r * cz.i + q1z.i * 
	    cz.r;
    z__3.r = z__4.r + z__5.r, z__3.i = z__4.i + z__5.i;
    z__1.r = z__2.r * z__3.r - z__2.i * z__3.i, z__1.i = z__2.r * z__3.i + 
	    z__2.i * z__3.r;
    j0p->r = z__1.r, j0p->i = z__1.i;
    if (ib == 0) {
	return 0;
    }
    zms = cos((sqrt(zms) - 6.f) * 31.41592654f);
    d__1 = zms + 1.f;
    z__3.r = d__1 * j0x.r, z__3.i = d__1 * j0x.i;
    d__2 = 1.f - zms;
    z__4.r = d__2 * j0->r, z__4.i = d__2 * j0->i;
    z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
    z__1.r = z__2.r * .5f, z__1.i = z__2.i * .5f;
    j0->r = z__1.r, j0->i = z__1.i;
    d__1 = zms + 1.f;
    z__3.r = d__1 * j0px.r, z__3.i = d__1 * j0px.i;
    d__2 = 1.f - zms;
    z__4.r = d__2 * j0p->r, z__4.i = d__2 * j0p->i;
    z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
    z__1.r = z__2.r * .5f, z__1.i = z__2.i * .5f;
    j0p->r = z__1.r, j0p->i = z__1.i;
    return 0;
/*     INITIALIZATION OF CONSTANTS */
L5:
    for (k = 1; k <= 25; ++k) {
	a1[k - 1] = -.25 / (k * k);
/* L6: */
	a2[k - 1] = 1. / (k + 1.);
    }
    for (i__ = 1; i__ <= 101; ++i__) {
	test = 1.;
	for (k = 1; k <= 24; ++k) {
	    init = k;
	    test = -test * i__ * a1[k - 1];
	    if (test < 1e-6) {
		goto L8;
	    }
/* L7: */
	}
L8:
	m[i__ - 1] = init;
    }
    goto L1;
} /* bessel_ */

#undef fjx
#undef fj


/* *********************************************************************** */
/* Subroutine */ int evlua_(doublecomplex *erv, doublecomplex *ezv, 
	doublecomplex *erh, doublecomplex *eph)
{
    /* Initialized data */

    static doublereal ptp = .6283185308;

    /* System generated locals */
    integer i__1, i__2, i__3;
    doublereal d__1, d__2;
    doublecomplex z__1, z__2, z__3, z__4;

    /* Builtin functions */
    double sqrt(doublereal);
    void d_cnjg(doublecomplex *, doublecomplex *);
    double d_imag(doublecomplex *), z_abs(doublecomplex *);

    /* Local variables */
    static integer i__;
    static doublecomplex bk, cp1, cp2, cp3;
    static doublereal del;
    static doublecomplex ans[6], sum[6];
    extern /* Subroutine */ int rom1_(integer *, doublecomplex *, integer *);
    static doublereal rmis;
    static doublecomplex delta;
    static doublereal slope;
    static doublecomplex delta2;
    extern /* Subroutine */ int gshank_(doublecomplex *, doublecomplex *, 
	    doublecomplex *, integer *, doublecomplex *, integer *, 
	    doublecomplex *, doublecomplex *);

/* *********************************************************************** */

/*     EVALUA CONTROLS THE INTEGRATION CONTOUR IN THE COMPLEX LAMBDA */
/*     PLANE FOR EVALUATION OF THE SOMMERFELD INTEGRALS. */

    del = evlcom_1.zph;
    if (evlcom_1.rho > del) {
	del = evlcom_1.rho;
    }
    if (evlcom_1.zph < evlcom_1.rho * 2.f) {
	goto L4;
    }

/*     BESSEL FUNCTION FORM OF SOMMERFELD INTEGRALS */

    evlcom_1.jh = 0;
    cntour_1.a.r = 0.f, cntour_1.a.i = 0.f;
    del = 1.f / del;
    if (del <= evlcom_1.tkmag) {
	goto L2;
    }
    d__1 = evlcom_1.tkmag * .1f;
    d__2 = evlcom_1.tkmag * -.1f;
    z__1.r = d__1, z__1.i = d__2;
    cntour_1.b.r = z__1.r, cntour_1.b.i = z__1.i;
    rom1_(&c__6, sum, &c__2);
    cntour_1.a.r = cntour_1.b.r, cntour_1.a.i = cntour_1.b.i;
    d__1 = -del;
    z__1.r = del, z__1.i = d__1;
    cntour_1.b.r = z__1.r, cntour_1.b.i = z__1.i;
    rom1_(&c__6, ans, &c__2);
    for (i__ = 1; i__ <= 6; ++i__) {
/* L1: */
	i__1 = i__ - 1;
	i__2 = i__ - 1;
	i__3 = i__ - 1;
	z__1.r = sum[i__2].r + ans[i__3].r, z__1.i = sum[i__2].i + ans[i__3]
		.i;
	sum[i__1].r = z__1.r, sum[i__1].i = z__1.i;
    }
    goto L3;
L2:
    d__1 = -del;
    z__1.r = del, z__1.i = d__1;
    cntour_1.b.r = z__1.r, cntour_1.b.i = z__1.i;
    rom1_(&c__6, sum, &c__2);
L3:
    d__1 = ptp * del;
    delta.r = d__1, delta.i = 0.;
    gshank_(&cntour_1.b, &delta, ans, &c__6, sum, &c__0, &cntour_1.b, &
	    cntour_1.b);
    goto L10;

/*     HANKEL FUNCTION FORM OF SOMMERFELD INTEGRALS */

L4:
    evlcom_1.jh = 1;
    d__1 = evlcom_1.ck2 * .4f;
    z__1.r = 0., z__1.i = d__1;
    cp1.r = z__1.r, cp1.i = z__1.i;
    d__1 = evlcom_1.ck2 * .6f;
    d__2 = evlcom_1.ck2 * -.2f;
    z__1.r = d__1, z__1.i = d__2;
    cp2.r = z__1.r, cp2.i = z__1.i;
    d__1 = evlcom_1.ck2 * 1.02f;
    d__2 = evlcom_1.ck2 * -.2f;
    z__1.r = d__1, z__1.i = d__2;
    cp3.r = z__1.r, cp3.i = z__1.i;
    cntour_1.a.r = cp1.r, cntour_1.a.i = cp1.i;
    cntour_1.b.r = cp2.r, cntour_1.b.i = cp2.i;
    rom1_(&c__6, sum, &c__2);
    cntour_1.a.r = cp2.r, cntour_1.a.i = cp2.i;
    cntour_1.b.r = cp3.r, cntour_1.b.i = cp3.i;
    rom1_(&c__6, ans, &c__2);
    for (i__ = 1; i__ <= 6; ++i__) {
/* L5: */
	i__1 = i__ - 1;
	i__2 = i__ - 1;
	i__3 = i__ - 1;
	z__2.r = sum[i__2].r + ans[i__3].r, z__2.i = sum[i__2].i + ans[i__3]
		.i;
	z__1.r = -z__2.r, z__1.i = -z__2.i;
	sum[i__1].r = z__1.r, sum[i__1].i = z__1.i;
    }
/*     PATH FROM IMAGINARY AXIS TO -INFINITY */
    slope = 1e3f;
    if (evlcom_1.zph > evlcom_1.rho * .001f) {
	slope = evlcom_1.rho / evlcom_1.zph;
    }
    del = ptp / del;
    z__3.r = -1., z__3.i = slope;
    z__2.r = del * z__3.r, z__2.i = del * z__3.i;
    d__1 = sqrt(slope * slope + 1.f);
    z__1.r = z__2.r / d__1, z__1.i = z__2.i / d__1;
    delta.r = z__1.r, delta.i = z__1.i;
    d_cnjg(&z__2, &delta);
    z__1.r = -z__2.r, z__1.i = -z__2.i;
    delta2.r = z__1.r, delta2.i = z__1.i;
    gshank_(&cp1, &delta, ans, &c__6, sum, &c__0, &bk, &bk);
    rmis = evlcom_1.rho * (evlcom_1.ck1.r - evlcom_1.ck2);
    if (rmis < evlcom_1.ck2 * 2.f) {
	goto L8;
    }
    if (evlcom_1.rho < 1e-10f) {
	goto L8;
    }
    if (evlcom_1.zph < 1e-10f) {
	goto L6;
    }
    d__1 = -evlcom_1.zph;
    z__2.r = d__1, z__2.i = evlcom_1.rho;
    z__3.r = evlcom_1.ck1.r - cp3.r, z__3.i = evlcom_1.ck1.i - cp3.i;
    z__1.r = z__2.r * z__3.r - z__2.i * z__3.i, z__1.i = z__2.r * z__3.i + 
	    z__2.i * z__3.r;
    bk.r = z__1.r, bk.i = z__1.i;
    rmis = -bk.r / (d__1 = d_imag(&bk), abs(d__1));
    if (rmis > evlcom_1.rho * 4.f / evlcom_1.zph) {
	goto L8;
    }
/*     INTEGRATE UP BETWEEN BRANCH CUTS, THEN TO + INFINITY */
L6:
    z__1.r = evlcom_1.ck1.r - .1f, z__1.i = evlcom_1.ck1.i - .2f;
    cp1.r = z__1.r, cp1.i = z__1.i;
    z__1.r = cp1.r + .2f, z__1.i = cp1.i;
    cp2.r = z__1.r, cp2.i = z__1.i;
    z__1.r = 0., z__1.i = del;
    bk.r = z__1.r, bk.i = z__1.i;
    gshank_(&cp1, &bk, sum, &c__6, ans, &c__0, &bk, &bk);
    cntour_1.a.r = cp1.r, cntour_1.a.i = cp1.i;
    cntour_1.b.r = cp2.r, cntour_1.b.i = cp2.i;
    rom1_(&c__6, ans, &c__1);
    for (i__ = 1; i__ <= 6; ++i__) {
/* L7: */
	i__1 = i__ - 1;
	i__2 = i__ - 1;
	i__3 = i__ - 1;
	z__1.r = ans[i__2].r - sum[i__3].r, z__1.i = ans[i__2].i - sum[i__3]
		.i;
	ans[i__1].r = z__1.r, ans[i__1].i = z__1.i;
    }
    gshank_(&cp3, &bk, sum, &c__6, ans, &c__0, &bk, &bk);
    gshank_(&cp2, &delta2, ans, &c__6, sum, &c__0, &bk, &bk);
    goto L10;
/*     INTEGRATE BELOW BRANCH POINTS, THEN TO + INFINITY */
L8:
    for (i__ = 1; i__ <= 6; ++i__) {
/* L9: */
	i__1 = i__ - 1;
	i__2 = i__ - 1;
	z__1.r = -ans[i__2].r, z__1.i = -ans[i__2].i;
	sum[i__1].r = z__1.r, sum[i__1].i = z__1.i;
    }
    rmis = evlcom_1.ck1.r * 1.01f;
    if (evlcom_1.ck2 + 1.f > rmis) {
	rmis = evlcom_1.ck2 + 1.f;
    }
    d__1 = d_imag(&evlcom_1.ck1) * .99f;
    z__1.r = rmis, z__1.i = d__1;
    bk.r = z__1.r, bk.i = z__1.i;
    z__1.r = bk.r - cp3.r, z__1.i = bk.i - cp3.i;
    delta.r = z__1.r, delta.i = z__1.i;
    z__2.r = del * delta.r, z__2.i = del * delta.i;
    d__1 = z_abs(&delta);
    z__1.r = z__2.r / d__1, z__1.i = z__2.i / d__1;
    delta.r = z__1.r, delta.i = z__1.i;
    gshank_(&cp3, &delta, ans, &c__6, sum, &c__1, &bk, &delta2);
L10:
    z__1.r = ans[5].r * evlcom_1.ck1.r - ans[5].i * evlcom_1.ck1.i, z__1.i = 
	    ans[5].r * evlcom_1.ck1.i + ans[5].i * evlcom_1.ck1.r;
    ans[5].r = z__1.r, ans[5].i = z__1.i;
/*     CONJUGATE SINCE NEC USES EXP(+JWT) */
    z__2.r = evlcom_1.ck1sq.r * ans[2].r - evlcom_1.ck1sq.i * ans[2].i, 
	    z__2.i = evlcom_1.ck1sq.r * ans[2].i + evlcom_1.ck1sq.i * ans[2]
	    .r;
    d_cnjg(&z__1, &z__2);
    erv->r = z__1.r, erv->i = z__1.i;
    z__4.r = evlcom_1.ck2sq * ans[4].r, z__4.i = evlcom_1.ck2sq * ans[4].i;
    z__3.r = ans[1].r + z__4.r, z__3.i = ans[1].i + z__4.i;
    z__2.r = evlcom_1.ck1sq.r * z__3.r - evlcom_1.ck1sq.i * z__3.i, z__2.i = 
	    evlcom_1.ck1sq.r * z__3.i + evlcom_1.ck1sq.i * z__3.r;
    d_cnjg(&z__1, &z__2);
    ezv->r = z__1.r, ezv->i = z__1.i;
    z__3.r = ans[0].r + ans[5].r, z__3.i = ans[0].i + ans[5].i;
    z__2.r = evlcom_1.ck2sq * z__3.r, z__2.i = evlcom_1.ck2sq * z__3.i;
    d_cnjg(&z__1, &z__2);
    erh->r = z__1.r, erh->i = z__1.i;
    z__4.r = ans[3].r + ans[5].r, z__4.i = ans[3].i + ans[5].i;
    z__3.r = evlcom_1.ck2sq * z__4.r, z__3.i = evlcom_1.ck2sq * z__4.i;
    d_cnjg(&z__2, &z__3);
    z__1.r = -z__2.r, z__1.i = -z__2.i;
    eph->r = z__1.r, eph->i = z__1.i;
    return 0;
} /* evlua_ */

/* *********************************************************************** */
/* Subroutine */ int gshank_(doublecomplex *start, doublecomplex *dela, 
	doublecomplex *sum, integer *nans, doublecomplex *seed, integer *ibk, 
	doublecomplex *bk, doublecomplex *delb)
{
    /* Initialized data */

    static doublereal crit = 1e-4;
    static integer maxh = 20;

    /* Format strings */
    static char fmt_24[] = "(\002 **** NO CONVERGENCE IN SUBROUTINE GSHANK *"
	    "***\002)";
    static char fmt_25[] = "(1x,1p10e12.5)";

    /* System generated locals */
    integer i__1, i__2, i__3, i__4, i__5;
    doublereal d__1, d__2;
    doublecomplex z__1, z__2, z__3, z__4, z__5;

    /* Builtin functions */
    double d_imag(doublecomplex *);
    void z_div(doublecomplex *, doublecomplex *, doublecomplex *);
    integer s_wsfe(cilist *), e_wsfe(void), do_fio(integer *, char *, ftnlen);

    /* Local variables */
    static integer i__, j;
    static doublecomplex a1, a2, q1[120]	/* was [6][20] */, q2[120]	
	    /* was [6][20] */, aa;
    static integer jm;
    static doublecomplex as1, as2, del;
    static doublereal den, amg, rbk;
    static integer ibx, int__, inx;
    static doublecomplex ans1[6], ans2[6];
    extern /* Subroutine */ int rom1_(integer *, doublecomplex *, integer *);
    static doublereal denm;

    /* Fortran I/O blocks */
    static cilist io___303 = { 0, 6, 0, fmt_24, 0 };
    static cilist io___304 = { 0, 6, 0, fmt_25, 0 };


/* *********************************************************************** */

/*     GSHANK INTEGRATES THE 6 SOMMERFELD INTEGRALS FROM START TO */
/*     INFINITY (UNTIL CONVERGENCE) IN LAMBDA.  AT THE BREAK POINT, BK, */
/*     THE STEP INCREMENT MAY BE CHANGED FROM DELA TO DELB.  SHANK S */
/*     ALGORITHM TO ACCELERATE CONVERGENCE OF A SLOWLY CONVERGING SERIES */
/*     IS USED */

    /* Parameter adjustments */
    --seed;
    --sum;

    /* Function Body */
    rbk = bk->r;
    del.r = dela->r, del.i = dela->i;
    ibx = 0;
    if (*ibk == 0) {
	ibx = 1;
    }
    i__1 = *nans;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L1: */
	i__2 = i__ - 1;
	i__3 = i__;
	ans2[i__2].r = seed[i__3].r, ans2[i__2].i = seed[i__3].i;
    }
    cntour_1.b.r = start->r, cntour_1.b.i = start->i;
L2:
    i__2 = maxh;
    for (int__ = 1; int__ <= i__2; ++int__) {
	inx = int__;
	cntour_1.a.r = cntour_1.b.r, cntour_1.a.i = cntour_1.b.i;
	z__1.r = cntour_1.b.r + del.r, z__1.i = cntour_1.b.i + del.i;
	cntour_1.b.r = z__1.r, cntour_1.b.i = z__1.i;
	if (ibx == 0 && cntour_1.b.r >= rbk) {
	    goto L5;
	}
	rom1_(nans, &sum[1], &c__2);
	i__3 = *nans;
	for (i__ = 1; i__ <= i__3; ++i__) {
/* L3: */
	    i__1 = i__ - 1;
	    i__4 = i__ - 1;
	    i__5 = i__;
	    z__1.r = ans2[i__4].r + sum[i__5].r, z__1.i = ans2[i__4].i + sum[
		    i__5].i;
	    ans1[i__1].r = z__1.r, ans1[i__1].i = z__1.i;
	}
	cntour_1.a.r = cntour_1.b.r, cntour_1.a.i = cntour_1.b.i;
	z__1.r = cntour_1.b.r + del.r, z__1.i = cntour_1.b.i + del.i;
	cntour_1.b.r = z__1.r, cntour_1.b.i = z__1.i;
	if (ibx == 0 && cntour_1.b.r >= rbk) {
	    goto L6;
	}
	rom1_(nans, &sum[1], &c__2);
	i__1 = *nans;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L4: */
	    i__4 = i__ - 1;
	    i__5 = i__ - 1;
	    i__3 = i__;
	    z__1.r = ans1[i__5].r + sum[i__3].r, z__1.i = ans1[i__5].i + sum[
		    i__3].i;
	    ans2[i__4].r = z__1.r, ans2[i__4].i = z__1.i;
	}
	goto L11;
/*     HIT BREAK POINT.  RESET SEED AND START OVER. */
L5:
	ibx = 1;
	goto L7;
L6:
	ibx = 2;
L7:
	cntour_1.b.r = bk->r, cntour_1.b.i = bk->i;
	del.r = delb->r, del.i = delb->i;
	rom1_(nans, &sum[1], &c__2);
	if (ibx == 2) {
	    goto L9;
	}
	i__4 = *nans;
	for (i__ = 1; i__ <= i__4; ++i__) {
/* L8: */
	    i__5 = i__ - 1;
	    i__3 = i__ - 1;
	    i__1 = i__;
	    z__1.r = ans2[i__3].r + sum[i__1].r, z__1.i = ans2[i__3].i + sum[
		    i__1].i;
	    ans2[i__5].r = z__1.r, ans2[i__5].i = z__1.i;
	}
	goto L2;
L9:
	i__5 = *nans;
	for (i__ = 1; i__ <= i__5; ++i__) {
/* L10: */
	    i__3 = i__ - 1;
	    i__1 = i__ - 1;
	    i__4 = i__;
	    z__1.r = ans1[i__1].r + sum[i__4].r, z__1.i = ans1[i__1].i + sum[
		    i__4].i;
	    ans2[i__3].r = z__1.r, ans2[i__3].i = z__1.i;
	}
	goto L2;
L11:
	den = 0.f;
	i__3 = *nans;
	for (i__ = 1; i__ <= i__3; ++i__) {
	    i__1 = i__ - 1;
	    as1.r = ans1[i__1].r, as1.i = ans1[i__1].i;
	    i__1 = i__ - 1;
	    as2.r = ans2[i__1].r, as2.i = ans2[i__1].i;
	    if (int__ < 2) {
		goto L17;
	    }
	    i__1 = int__;
	    for (j = 2; j <= i__1; ++j) {
		jm = j - 1;
		i__4 = i__ + jm * 6 - 7;
		aa.r = q2[i__4].r, aa.i = q2[i__4].i;
		i__4 = i__ + jm * 6 - 7;
		z__2.r = q1[i__4].r + as1.r, z__2.i = q1[i__4].i + as1.i;
		z__3.r = aa.r * 2.f, z__3.i = aa.i * 2.f;
		z__1.r = z__2.r - z__3.r, z__1.i = z__2.i - z__3.i;
		a1.r = z__1.r, a1.i = z__1.i;
		if (a1.r == 0.f && d_imag(&a1) == 0.f) {
		    goto L12;
		}
		i__4 = i__ + jm * 6 - 7;
		z__1.r = aa.r - q1[i__4].r, z__1.i = aa.i - q1[i__4].i;
		a2.r = z__1.r, a2.i = z__1.i;
		i__4 = i__ + jm * 6 - 7;
		z__3.r = a2.r * a2.r - a2.i * a2.i, z__3.i = a2.r * a2.i + 
			a2.i * a2.r;
		z_div(&z__2, &z__3, &a1);
		z__1.r = q1[i__4].r - z__2.r, z__1.i = q1[i__4].i - z__2.i;
		a1.r = z__1.r, a1.i = z__1.i;
		goto L13;
L12:
		i__4 = i__ + jm * 6 - 7;
		a1.r = q1[i__4].r, a1.i = q1[i__4].i;
L13:
		z__2.r = aa.r + as2.r, z__2.i = aa.i + as2.i;
		z__3.r = as1.r * 2.f, z__3.i = as1.i * 2.f;
		z__1.r = z__2.r - z__3.r, z__1.i = z__2.i - z__3.i;
		a2.r = z__1.r, a2.i = z__1.i;
		if (a2.r == 0.f && d_imag(&a2) == 0.f) {
		    goto L14;
		}
		z__4.r = as1.r - aa.r, z__4.i = as1.i - aa.i;
		z__5.r = as1.r - aa.r, z__5.i = as1.i - aa.i;
		z__3.r = z__4.r * z__5.r - z__4.i * z__5.i, z__3.i = z__4.r * 
			z__5.i + z__4.i * z__5.r;
		z_div(&z__2, &z__3, &a2);
		z__1.r = aa.r - z__2.r, z__1.i = aa.i - z__2.i;
		a2.r = z__1.r, a2.i = z__1.i;
		goto L15;
L14:
		a2.r = aa.r, a2.i = aa.i;
L15:
		i__4 = i__ + jm * 6 - 7;
		q1[i__4].r = as1.r, q1[i__4].i = as1.i;
		i__4 = i__ + jm * 6 - 7;
		q2[i__4].r = as2.r, q2[i__4].i = as2.i;
		as1.r = a1.r, as1.i = a1.i;
/* L16: */
		as2.r = a2.r, as2.i = a2.i;
	    }
L17:
	    i__1 = i__ + int__ * 6 - 7;
	    q1[i__1].r = as1.r, q1[i__1].i = as1.i;
	    i__1 = i__ + int__ * 6 - 7;
	    q2[i__1].r = as2.r, q2[i__1].i = as2.i;
	    amg = (d__1 = as2.r, abs(d__1)) + (d__2 = d_imag(&as2), abs(d__2))
		    ;
	    if (amg > den) {
		den = amg;
	    }
/* L18: */
	}
	denm = den * .001f * crit;
	jm = int__ - 3;
	if (jm < 1) {
	    jm = 1;
	}
	i__3 = int__;
	for (j = jm; j <= i__3; ++j) {
	    i__1 = *nans;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		i__4 = i__ + j * 6 - 7;
		a1.r = q2[i__4].r, a1.i = q2[i__4].i;
		den = ((d__1 = a1.r, abs(d__1)) + (d__2 = d_imag(&a1), abs(
			d__2))) * crit;
		if (den < denm) {
		    den = denm;
		}
		i__4 = i__ + j * 6 - 7;
		z__1.r = q1[i__4].r - a1.r, z__1.i = q1[i__4].i - a1.i;
		a1.r = z__1.r, a1.i = z__1.i;
		amg = (d__1 = a1.r, abs(d__1)) + (d__2 = d_imag(&a1), abs(
			d__2));
		if (amg > den) {
		    goto L20;
		}
/* L19: */
	    }
	}
	goto L22;
L20:
	;
    }
    s_wsfe(&io___303);
    e_wsfe();
    i__2 = *nans;
    for (i__ = 1; i__ <= i__2; ++i__) {
/* L21: */
	s_wsfe(&io___304);
	do_fio(&c__2, (char *)&q1[i__ + inx * 6 - 7], (ftnlen)sizeof(
		doublereal));
	do_fio(&c__2, (char *)&q2[i__ + inx * 6 - 7], (ftnlen)sizeof(
		doublereal));
	e_wsfe();
    }
L22:
    i__2 = *nans;
    for (i__ = 1; i__ <= i__2; ++i__) {
/* L23: */
	i__1 = i__;
	i__3 = i__ + inx * 6 - 7;
	i__4 = i__ + inx * 6 - 7;
	z__2.r = q1[i__3].r + q2[i__4].r, z__2.i = q1[i__3].i + q2[i__4].i;
	z__1.r = z__2.r * .5f, z__1.i = z__2.i * .5f;
	sum[i__1].r = z__1.r, sum[i__1].i = z__1.i;
    }
    return 0;

} /* gshank_ */

/* *********************************************************************** */
/* Subroutine */ int hankel_(doublecomplex *z__, doublecomplex *h0, 
	doublecomplex *h0p)
{
    /* Initialized data */

    static doublereal pi = 3.141592654;
    static doublereal gamma = .5772156649;
    static doublereal c1 = -.0245785095;
    static doublereal c2 = .3674669052;
    static doublereal c3 = .7978845608;
    static doublereal p10 = .0703125;
    static doublereal p20 = .1121520996;
    static doublereal q10 = .125;
    static doublereal q20 = .0732421875;
    static doublereal p11 = .1171875;
    static doublereal p21 = .1441955566;
    static doublereal q11 = .375;
    static doublereal q21 = .1025390625;
    static doublereal pof = .7853981635;
    static integer init = 0;
    static struct {
	doublereal e_1[2];
	} equiv_0 = { 0., 1. };


    /* Format strings */
    static char fmt_9[] = "(\002 ERROR - HANKEL NOT VALID FOR Z=0.\002)";

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2;
    doublecomplex z__1, z__2, z__3, z__4, z__5, z__6, z__7, z__8, z__9, z__10;

    /* Builtin functions */
    void d_cnjg(doublecomplex *, doublecomplex *);
    integer s_wsfe(cilist *), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);
    void z_log(doublecomplex *, doublecomplex *), z_div(doublecomplex *, 
	    doublecomplex *, doublecomplex *), z_exp(doublecomplex *, 
	    doublecomplex *), z_sqrt(doublecomplex *, doublecomplex *);
    double sqrt(doublereal), cos(doublereal);

    /* Local variables */
    static integer i__, k, m[101];
    static doublereal a1[25], a2[25], a3[25], a4[25];
    static doublecomplex j0, y0;
    static integer ib;
#define fj ((doublecomplex *)&equiv_0)
    static doublecomplex zi;
    static integer iz;
    static doublecomplex zk, j0p, zi2, y0p, p0z, p1z, q0z, q1z;
#define fjx ((doublereal *)&equiv_0)
    static doublereal psi;
    static integer miz;
    static doublereal zms, test;
    static doublecomplex clogz;

    /* Fortran I/O blocks */
    static cilist io___323 = { 0, 6, 0, fmt_9, 0 };


/* *********************************************************************** */

/*     HANKEL EVALUATES HANKEL FUNCTION OF THE FIRST KIND, ORDER ZERO, */
/*     AND ITS DERIVATIVE FOR COMPLEX ARGUMENT Z. */

    if (init == 0) {
	goto L5;
    }
L1:
    d_cnjg(&z__2, z__);
    z__1.r = z__->r * z__2.r - z__->i * z__2.i, z__1.i = z__->r * z__2.i + 
	    z__->i * z__2.r;
    zms = z__1.r;
    if (zms != 0.f) {
	goto L2;
    }
    s_wsfe(&io___323);
    e_wsfe();
    s_stop("", (ftnlen)0);
L2:
    ib = 0;
    if (zms > 16.81f) {
	goto L4;
    }
    if (zms > 16.f) {
	ib = 1;
    }
/*     SERIES EXPANSION */
    iz = (integer) (zms + 1.f);
    miz = m[iz - 1];
    j0.r = 1.f, j0.i = 0.f;
    j0p.r = j0.r, j0p.i = j0.i;
    y0.r = 0.f, y0.i = 0.f;
    y0p.r = y0.r, y0p.i = y0.i;
    zk.r = j0.r, zk.i = j0.i;
    z__1.r = z__->r * z__->r - z__->i * z__->i, z__1.i = z__->r * z__->i + 
	    z__->i * z__->r;
    zi.r = z__1.r, zi.i = z__1.i;
    i__1 = miz;
    for (k = 1; k <= i__1; ++k) {
	i__2 = k - 1;
	z__2.r = a1[i__2] * zk.r, z__2.i = a1[i__2] * zk.i;
	z__1.r = z__2.r * zi.r - z__2.i * zi.i, z__1.i = z__2.r * zi.i + 
		z__2.i * zi.r;
	zk.r = z__1.r, zk.i = z__1.i;
	z__1.r = j0.r + zk.r, z__1.i = j0.i + zk.i;
	j0.r = z__1.r, j0.i = z__1.i;
	i__2 = k - 1;
	z__2.r = a2[i__2] * zk.r, z__2.i = a2[i__2] * zk.i;
	z__1.r = j0p.r + z__2.r, z__1.i = j0p.i + z__2.i;
	j0p.r = z__1.r, j0p.i = z__1.i;
	i__2 = k - 1;
	z__2.r = a3[i__2] * zk.r, z__2.i = a3[i__2] * zk.i;
	z__1.r = y0.r + z__2.r, z__1.i = y0.i + z__2.i;
	y0.r = z__1.r, y0.i = z__1.i;
/* L3: */
	i__2 = k - 1;
	z__2.r = a4[i__2] * zk.r, z__2.i = a4[i__2] * zk.i;
	z__1.r = y0p.r + z__2.r, z__1.i = y0p.i + z__2.i;
	y0p.r = z__1.r, y0p.i = z__1.i;
    }
    z__2.r = z__->r * -.5f, z__2.i = z__->i * -.5f;
    z__1.r = z__2.r * j0p.r - z__2.i * j0p.i, z__1.i = z__2.r * j0p.i + 
	    z__2.i * j0p.r;
    j0p.r = z__1.r, j0p.i = z__1.i;
    z__2.r = z__->r * .5f, z__2.i = z__->i * .5f;
    z_log(&z__1, &z__2);
    clogz.r = z__1.r, clogz.i = z__1.i;
    z__5.r = j0.r * 2.f, z__5.i = j0.i * 2.f;
    z__4.r = z__5.r * clogz.r - z__5.i * clogz.i, z__4.i = z__5.r * clogz.i + 
	    z__5.i * clogz.r;
    z__3.r = z__4.r - y0.r, z__3.i = z__4.i - y0.i;
    z__2.r = z__3.r / pi, z__2.i = z__3.i / pi;
    z__1.r = z__2.r + c2, z__1.i = z__2.i;
    y0.r = z__1.r, y0.i = z__1.i;
    z_div(&z__5, &c_b622, z__);
    z__7.r = j0p.r * 2.f, z__7.i = j0p.i * 2.f;
    z__6.r = z__7.r * clogz.r - z__7.i * clogz.i, z__6.i = z__7.r * clogz.i + 
	    z__7.i * clogz.r;
    z__4.r = z__5.r + z__6.r, z__4.i = z__5.i + z__6.i;
    z__9.r = y0p.r * .5f, z__9.i = y0p.i * .5f;
    z__8.r = z__9.r * z__->r - z__9.i * z__->i, z__8.i = z__9.r * z__->i + 
	    z__9.i * z__->r;
    z__3.r = z__4.r + z__8.r, z__3.i = z__4.i + z__8.i;
    z__2.r = z__3.r / pi, z__2.i = z__3.i / pi;
    z__10.r = c1 * z__->r, z__10.i = c1 * z__->i;
    z__1.r = z__2.r + z__10.r, z__1.i = z__2.i + z__10.i;
    y0p.r = z__1.r, y0p.i = z__1.i;
    z__2.r = fj->r * y0.r - fj->i * y0.i, z__2.i = fj->r * y0.i + fj->i * 
	    y0.r;
    z__1.r = j0.r + z__2.r, z__1.i = j0.i + z__2.i;
    h0->r = z__1.r, h0->i = z__1.i;
    z__2.r = fj->r * y0p.r - fj->i * y0p.i, z__2.i = fj->r * y0p.i + fj->i * 
	    y0p.r;
    z__1.r = j0p.r + z__2.r, z__1.i = j0p.i + z__2.i;
    h0p->r = z__1.r, h0p->i = z__1.i;
    if (ib == 0) {
	return 0;
    }
    y0.r = h0->r, y0.i = h0->i;
    y0p.r = h0p->r, y0p.i = h0p->i;
/*     ASYMPTOTIC EXPANSION */
L4:
    z_div(&z__1, &c_b245, z__);
    zi.r = z__1.r, zi.i = z__1.i;
    z__1.r = zi.r * zi.r - zi.i * zi.i, z__1.i = zi.r * zi.i + zi.i * zi.r;
    zi2.r = z__1.r, zi2.i = z__1.i;
    z__4.r = p20 * zi2.r, z__4.i = p20 * zi2.i;
    z__3.r = z__4.r - p10, z__3.i = z__4.i;
    z__2.r = z__3.r * zi2.r - z__3.i * zi2.i, z__2.i = z__3.r * zi2.i + 
	    z__3.i * zi2.r;
    z__1.r = z__2.r + 1.f, z__1.i = z__2.i;
    p0z.r = z__1.r, p0z.i = z__1.i;
    z__4.r = p21 * zi2.r, z__4.i = p21 * zi2.i;
    z__3.r = p11 - z__4.r, z__3.i = -z__4.i;
    z__2.r = z__3.r * zi2.r - z__3.i * zi2.i, z__2.i = z__3.r * zi2.i + 
	    z__3.i * zi2.r;
    z__1.r = z__2.r + 1.f, z__1.i = z__2.i;
    p1z.r = z__1.r, p1z.i = z__1.i;
    z__3.r = q20 * zi2.r, z__3.i = q20 * zi2.i;
    z__2.r = z__3.r - q10, z__2.i = z__3.i;
    z__1.r = z__2.r * zi.r - z__2.i * zi.i, z__1.i = z__2.r * zi.i + z__2.i * 
	    zi.r;
    q0z.r = z__1.r, q0z.i = z__1.i;
    z__3.r = q21 * zi2.r, z__3.i = q21 * zi2.i;
    z__2.r = q11 - z__3.r, z__2.i = -z__3.i;
    z__1.r = z__2.r * zi.r - z__2.i * zi.i, z__1.i = z__2.r * zi.i + z__2.i * 
	    zi.r;
    q1z.r = z__1.r, q1z.i = z__1.i;
    z__5.r = z__->r - pof, z__5.i = z__->i;
    z__4.r = fj->r * z__5.r - fj->i * z__5.i, z__4.i = fj->r * z__5.i + fj->i 
	    * z__5.r;
    z_exp(&z__3, &z__4);
    z_sqrt(&z__6, &zi);
    z__2.r = z__3.r * z__6.r - z__3.i * z__6.i, z__2.i = z__3.r * z__6.i + 
	    z__3.i * z__6.r;
    z__1.r = c3 * z__2.r, z__1.i = c3 * z__2.i;
    zk.r = z__1.r, zk.i = z__1.i;
    z__3.r = fj->r * q0z.r - fj->i * q0z.i, z__3.i = fj->r * q0z.i + fj->i * 
	    q0z.r;
    z__2.r = p0z.r + z__3.r, z__2.i = p0z.i + z__3.i;
    z__1.r = zk.r * z__2.r - zk.i * z__2.i, z__1.i = zk.r * z__2.i + zk.i * 
	    z__2.r;
    h0->r = z__1.r, h0->i = z__1.i;
    z__2.r = fj->r * zk.r - fj->i * zk.i, z__2.i = fj->r * zk.i + fj->i * 
	    zk.r;
    z__4.r = fj->r * q1z.r - fj->i * q1z.i, z__4.i = fj->r * q1z.i + fj->i * 
	    q1z.r;
    z__3.r = p1z.r + z__4.r, z__3.i = p1z.i + z__4.i;
    z__1.r = z__2.r * z__3.r - z__2.i * z__3.i, z__1.i = z__2.r * z__3.i + 
	    z__2.i * z__3.r;
    h0p->r = z__1.r, h0p->i = z__1.i;
    if (ib == 0) {
	return 0;
    }
    zms = cos((sqrt(zms) - 4.f) * 31.41592654f);
    d__1 = zms + 1.f;
    z__3.r = d__1 * y0.r, z__3.i = d__1 * y0.i;
    d__2 = 1.f - zms;
    z__4.r = d__2 * h0->r, z__4.i = d__2 * h0->i;
    z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
    z__1.r = z__2.r * .5f, z__1.i = z__2.i * .5f;
    h0->r = z__1.r, h0->i = z__1.i;
    d__1 = zms + 1.f;
    z__3.r = d__1 * y0p.r, z__3.i = d__1 * y0p.i;
    d__2 = 1.f - zms;
    z__4.r = d__2 * h0p->r, z__4.i = d__2 * h0p->i;
    z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
    z__1.r = z__2.r * .5f, z__1.i = z__2.i * .5f;
    h0p->r = z__1.r, h0p->i = z__1.i;
    return 0;
/*     INITIALIZATION OF CONSTANTS */
L5:
    psi = -gamma;
    for (k = 1; k <= 25; ++k) {
	a1[k - 1] = -.25 / (k * k);
	a2[k - 1] = 1. / (k + 1.);
	psi += 1. / k;
	a3[k - 1] = psi + psi;
/* L6: */
	a4[k - 1] = (psi + psi + 1. / (k + 1.)) / (k + 1.);
    }
    for (i__ = 1; i__ <= 101; ++i__) {
	test = 1.;
	for (k = 1; k <= 24; ++k) {
	    init = k;
	    test = -test * i__ * a1[k - 1];
	    if (test * a3[k - 1] < 1e-6) {
		goto L8;
	    }
/* L7: */
	}
L8:
	m[i__ - 1] = init;
    }
    goto L1;

} /* hankel_ */

#undef fjx
#undef fj


/* *********************************************************************** */
/* Subroutine */ int lambda_(doublereal *t, doublecomplex *xlam, 
	doublecomplex *dxlam)
{
    /* System generated locals */
    doublecomplex z__1, z__2;

/* *********************************************************************** */

/*     COMPUTE INTEGRATION PARAMETER XLAM=LAMBDA FROM PARAMETER T. */

    z__1.r = cntour_1.b.r - cntour_1.a.r, z__1.i = cntour_1.b.i - 
	    cntour_1.a.i;
    dxlam->r = z__1.r, dxlam->i = z__1.i;
    z__2.r = *t * dxlam->r, z__2.i = *t * dxlam->i;
    z__1.r = cntour_1.a.r + z__2.r, z__1.i = cntour_1.a.i + z__2.i;
    xlam->r = z__1.r, xlam->i = z__1.i;
    return 0;
} /* lambda_ */

/* *********************************************************************** */
/* Subroutine */ int rom1_(integer *n, doublecomplex *sum, integer *nx)
{
    /* Initialized data */

    static integer nm = 131072;
    static integer nts = 4;
    static doublereal rx = 1e-4;

    /* Format strings */
    static char fmt_18[] = "(\002 ROM1 -- STEP SIZE LIMITED AT LAMBDA =\002,"
	    "1p2e12.5)";
    static char fmt_19[] = "(1x,1p10e12.5)";

    /* System generated locals */
    integer i__1, i__2, i__3, i__4;
    doublereal d__1, d__2, d__3, d__4;
    doublecomplex z__1, z__2, z__3, z__4;

    /* Builtin functions */
    double d_imag(doublecomplex *);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer i__;
    static doublereal s, z__;
    static doublecomplex g1[6], g2[6], g3[6], g4[6], g5[6], t00, t01[6], t10[
	    6], t02, t11, t20[6];
    static doublereal ep, ti, dz, ze;
    static integer ns, nt;
    static doublereal tr;
    extern /* Subroutine */ int saoa_(doublereal *, doublecomplex *);
    static doublereal zend;
    static integer nogo;
    extern /* Subroutine */ int test_(doublereal *, doublereal *, doublereal *
	    , doublereal *, doublereal *, doublereal *, doublereal *);
    static doublereal dzot;
    static integer lstep;
    extern /* Subroutine */ int lambda_(doublereal *, doublecomplex *, 
	    doublecomplex *);

    /* Fortran I/O blocks */
    static cilist io___376 = { 0, 6, 0, fmt_18, 0 };
    static cilist io___377 = { 0, 6, 0, fmt_19, 0 };
    static cilist io___378 = { 0, 6, 0, fmt_19, 0 };


/* *********************************************************************** */

/*     ROM1 INTEGRATES THE 6 SOMMERFELD INTEGRALS FROM A TO B IN LAMBDA. */
/*     THE METHOD OF VARIABLE INTERVAL WIDTH ROMBERG INTEGRATION IS USED. */

    /* Parameter adjustments */
    --sum;

    /* Function Body */
    lstep = 0;
    z__ = 0.f;
    ze = 1.f;
    s = 1.f;
    ep = s / (nm * 1e4f);
    zend = ze - ep;
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L1: */
	i__2 = i__;
	sum[i__2].r = 0.f, sum[i__2].i = 0.f;
    }
    ns = *nx;
    nt = 0;
    saoa_(&z__, g1);
L2:
    dz = s / ns;
    if (z__ + dz <= ze) {
	goto L3;
    }
    dz = ze - z__;
    if (dz <= ep) {
	goto L17;
    }
L3:
    dzot = dz * .5f;
    d__1 = z__ + dzot;
    saoa_(&d__1, g3);
    d__1 = z__ + dz;
    saoa_(&d__1, g5);
L4:
    nogo = 0;
    i__2 = *n;
    for (i__ = 1; i__ <= i__2; ++i__) {
	i__1 = i__ - 1;
	i__3 = i__ - 1;
	z__2.r = g1[i__1].r + g5[i__3].r, z__2.i = g1[i__1].i + g5[i__3].i;
	z__1.r = dzot * z__2.r, z__1.i = dzot * z__2.i;
	t00.r = z__1.r, t00.i = z__1.i;
	i__1 = i__ - 1;
	i__3 = i__ - 1;
	z__3.r = dz * g3[i__3].r, z__3.i = dz * g3[i__3].i;
	z__2.r = t00.r + z__3.r, z__2.i = t00.i + z__3.i;
	z__1.r = z__2.r * .5f, z__1.i = z__2.i * .5f;
	t01[i__1].r = z__1.r, t01[i__1].i = z__1.i;
	i__1 = i__ - 1;
	i__3 = i__ - 1;
	z__3.r = t01[i__3].r * 4.f, z__3.i = t01[i__3].i * 4.f;
	z__2.r = z__3.r - t00.r, z__2.i = z__3.i - t00.i;
	z__1.r = z__2.r / 3.f, z__1.i = z__2.i / 3.f;
	t10[i__1].r = z__1.r, t10[i__1].i = z__1.i;
/*     TEST CONVERGENCE OF 3 POINT ROMBERG RESULT */
	i__1 = i__ - 1;
	d__1 = t01[i__1].r;
	i__3 = i__ - 1;
	d__2 = t10[i__3].r;
	d__3 = d_imag(&t01[i__ - 1]);
	d__4 = d_imag(&t10[i__ - 1]);
	test_(&d__1, &d__2, &tr, &d__3, &d__4, &ti, &c_b636);
	if (tr > rx || ti > rx) {
	    nogo = 1;
	}
/* L5: */
    }
    if (nogo != 0) {
	goto L7;
    }
    i__2 = *n;
    for (i__ = 1; i__ <= i__2; ++i__) {
/* L6: */
	i__1 = i__;
	i__3 = i__;
	i__4 = i__ - 1;
	z__1.r = sum[i__3].r + t10[i__4].r, z__1.i = sum[i__3].i + t10[i__4]
		.i;
	sum[i__1].r = z__1.r, sum[i__1].i = z__1.i;
    }
    nt += 2;
    goto L11;
L7:
    d__1 = z__ + dz * .25f;
    saoa_(&d__1, g2);
    d__1 = z__ + dz * .75f;
    saoa_(&d__1, g4);
    nogo = 0;
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__3 = i__ - 1;
	i__4 = i__ - 1;
	i__2 = i__ - 1;
	z__4.r = g2[i__4].r + g4[i__2].r, z__4.i = g2[i__4].i + g4[i__2].i;
	z__3.r = dzot * z__4.r, z__3.i = dzot * z__4.i;
	z__2.r = t01[i__3].r + z__3.r, z__2.i = t01[i__3].i + z__3.i;
	z__1.r = z__2.r * .5f, z__1.i = z__2.i * .5f;
	t02.r = z__1.r, t02.i = z__1.i;
	z__3.r = t02.r * 4.f, z__3.i = t02.i * 4.f;
	i__3 = i__ - 1;
	z__2.r = z__3.r - t01[i__3].r, z__2.i = z__3.i - t01[i__3].i;
	z__1.r = z__2.r / 3.f, z__1.i = z__2.i / 3.f;
	t11.r = z__1.r, t11.i = z__1.i;
	i__3 = i__ - 1;
	z__3.r = t11.r * 16.f, z__3.i = t11.i * 16.f;
	i__4 = i__ - 1;
	z__2.r = z__3.r - t10[i__4].r, z__2.i = z__3.i - t10[i__4].i;
	z__1.r = z__2.r / 15.f, z__1.i = z__2.i / 15.f;
	t20[i__3].r = z__1.r, t20[i__3].i = z__1.i;
/*     TEST CONVERGENCE OF 5 POINT ROMBERG RESULT */
	d__1 = t11.r;
	i__3 = i__ - 1;
	d__2 = t20[i__3].r;
	d__3 = d_imag(&t11);
	d__4 = d_imag(&t20[i__ - 1]);
	test_(&d__1, &d__2, &tr, &d__3, &d__4, &ti, &c_b636);
	if (tr > rx || ti > rx) {
	    nogo = 1;
	}
/* L8: */
    }
    if (nogo != 0) {
	goto L13;
    }
L9:
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L10: */
	i__3 = i__;
	i__4 = i__;
	i__2 = i__ - 1;
	z__1.r = sum[i__4].r + t20[i__2].r, z__1.i = sum[i__4].i + t20[i__2]
		.i;
	sum[i__3].r = z__1.r, sum[i__3].i = z__1.i;
    }
    ++nt;
L11:
    z__ += dz;
    if (z__ > zend) {
	goto L17;
    }
    i__3 = *n;
    for (i__ = 1; i__ <= i__3; ++i__) {
/* L12: */
	i__4 = i__ - 1;
	i__2 = i__ - 1;
	g1[i__4].r = g5[i__2].r, g1[i__4].i = g5[i__2].i;
    }
    if (nt < nts || ns <= *nx) {
	goto L2;
    }
    ns /= 2;
    nt = 1;
    goto L2;
L13:
    nt = 0;
    if (ns < nm) {
	goto L15;
    }
    if (lstep == 1) {
	goto L9;
    }
    lstep = 1;
    lambda_(&z__, &t00, &t11);
    s_wsfe(&io___376);
    do_fio(&c__2, (char *)&t00, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___377);
    do_fio(&c__1, (char *)&z__, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&dz, (ftnlen)sizeof(doublereal));
    do_fio(&c__2, (char *)&cntour_1.a, (ftnlen)sizeof(doublereal));
    do_fio(&c__2, (char *)&cntour_1.b, (ftnlen)sizeof(doublereal));
    e_wsfe();
    i__4 = *n;
    for (i__ = 1; i__ <= i__4; ++i__) {
/* L14: */
	s_wsfe(&io___378);
	do_fio(&c__2, (char *)&g1[i__ - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__2, (char *)&g2[i__ - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__2, (char *)&g3[i__ - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__2, (char *)&g4[i__ - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__2, (char *)&g5[i__ - 1], (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    goto L9;
L15:
    ns <<= 1;
    dz = s / ns;
    dzot = dz * .5f;
    i__4 = *n;
    for (i__ = 1; i__ <= i__4; ++i__) {
	i__2 = i__ - 1;
	i__3 = i__ - 1;
	g5[i__2].r = g3[i__3].r, g5[i__2].i = g3[i__3].i;
/* L16: */
	i__2 = i__ - 1;
	i__3 = i__ - 1;
	g3[i__2].r = g2[i__3].r, g3[i__2].i = g2[i__3].i;
    }
    goto L4;
L17:
    return 0;

} /* rom1_ */

/* *********************************************************************** */
/* Subroutine */ int saoa_(doublereal *t, doublecomplex *ans)
{
    /* System generated locals */
    doublereal d__1, d__2;
    doublecomplex z__1, z__2, z__3, z__4, z__5, z__6;

    /* Builtin functions */
    void z_sqrt(doublecomplex *, doublecomplex *);
    double d_imag(doublecomplex *);
    void d_cnjg(doublecomplex *, doublecomplex *), z_div(doublecomplex *, 
	    doublecomplex *, doublecomplex *), z_exp(doublecomplex *, 
	    doublecomplex *);

    /* Local variables */
    static doublecomplex b0, xl, b0p, com, dxl;
    static doublereal xlr;
    static doublecomplex den1, den2, dgam;
    static doublereal sign;
    static doublecomplex cgam1, cgam2;
    extern /* Subroutine */ int lambda_(doublereal *, doublecomplex *, 
	    doublecomplex *), hankel_(doublecomplex *, doublecomplex *, 
	    doublecomplex *), bessel_(doublecomplex *, doublecomplex *, 
	    doublecomplex *);

/* *********************************************************************** */

/*     SAOA COMPUTES THE INTEGRAND FOR EACH OF THE 6 */
/*     SOMMERFELD INTEGRALS FOR SOURCE AND OBSERVER ABOVE GROUND */

    /* Parameter adjustments */
    --ans;

    /* Function Body */
    lambda_(t, &xl, &dxl);
    if (evlcom_1.jh > 0) {
	goto L1;
    }
/*     BESSEL FUNCTION FORM */
    z__1.r = evlcom_1.rho * xl.r, z__1.i = evlcom_1.rho * xl.i;
    bessel_(&z__1, &b0, &b0p);
    z__1.r = b0.r * 2.f, z__1.i = b0.i * 2.f;
    b0.r = z__1.r, b0.i = z__1.i;
    z__1.r = b0p.r * 2.f, z__1.i = b0p.i * 2.f;
    b0p.r = z__1.r, b0p.i = z__1.i;
    z__3.r = xl.r * xl.r - xl.i * xl.i, z__3.i = xl.r * xl.i + xl.i * xl.r;
    z__2.r = z__3.r - evlcom_1.ck1sq.r, z__2.i = z__3.i - evlcom_1.ck1sq.i;
    z_sqrt(&z__1, &z__2);
    cgam1.r = z__1.r, cgam1.i = z__1.i;
    z__3.r = xl.r * xl.r - xl.i * xl.i, z__3.i = xl.r * xl.i + xl.i * xl.r;
    z__2.r = z__3.r - evlcom_1.ck2sq, z__2.i = z__3.i;
    z_sqrt(&z__1, &z__2);
    cgam2.r = z__1.r, cgam2.i = z__1.i;
    if (cgam1.r == 0.f) {
	d__2 = -(d__1 = d_imag(&cgam1), abs(d__1));
	z__1.r = 0., z__1.i = d__2;
	cgam1.r = z__1.r, cgam1.i = z__1.i;
    }
    if (cgam2.r == 0.f) {
	d__2 = -(d__1 = d_imag(&cgam2), abs(d__1));
	z__1.r = 0., z__1.i = d__2;
	cgam2.r = z__1.r, cgam2.i = z__1.i;
    }
    goto L2;
/*     HANKEL FUNCTION FORM */
L1:
    z__1.r = evlcom_1.rho * xl.r, z__1.i = evlcom_1.rho * xl.i;
    hankel_(&z__1, &b0, &b0p);
    z__1.r = xl.r - evlcom_1.ck1.r, z__1.i = xl.i - evlcom_1.ck1.i;
    com.r = z__1.r, com.i = z__1.i;
    z__3.r = xl.r + evlcom_1.ck1.r, z__3.i = xl.i + evlcom_1.ck1.i;
    z_sqrt(&z__2, &z__3);
    z_sqrt(&z__4, &com);
    z__1.r = z__2.r * z__4.r - z__2.i * z__4.i, z__1.i = z__2.r * z__4.i + 
	    z__2.i * z__4.r;
    cgam1.r = z__1.r, cgam1.i = z__1.i;
    if (com.r < 0.f && d_imag(&com) >= 0.f) {
	z__1.r = -cgam1.r, z__1.i = -cgam1.i;
	cgam1.r = z__1.r, cgam1.i = z__1.i;
    }
    z__1.r = xl.r - evlcom_1.ck2, z__1.i = xl.i;
    com.r = z__1.r, com.i = z__1.i;
    z__3.r = xl.r + evlcom_1.ck2, z__3.i = xl.i;
    z_sqrt(&z__2, &z__3);
    z_sqrt(&z__4, &com);
    z__1.r = z__2.r * z__4.r - z__2.i * z__4.i, z__1.i = z__2.r * z__4.i + 
	    z__2.i * z__4.r;
    cgam2.r = z__1.r, cgam2.i = z__1.i;
    if (com.r < 0.f && d_imag(&com) >= 0.f) {
	z__1.r = -cgam2.r, z__1.i = -cgam2.i;
	cgam2.r = z__1.r, cgam2.i = z__1.i;
    }
L2:
    d_cnjg(&z__2, &xl);
    z__1.r = xl.r * z__2.r - xl.i * z__2.i, z__1.i = xl.r * z__2.i + xl.i * 
	    z__2.r;
    xlr = z__1.r;
    if (xlr < evlcom_1.tsmag) {
	goto L3;
    }
    if (d_imag(&xl) < 0.f) {
	goto L4;
    }
    xlr = xl.r;
    if (xlr < evlcom_1.ck2) {
	goto L5;
    }
    if (xlr > evlcom_1.ck1r) {
	goto L4;
    }
L3:
    z__1.r = cgam2.r - cgam1.r, z__1.i = cgam2.i - cgam1.i;
    dgam.r = z__1.r, dgam.i = z__1.i;
    goto L7;
L4:
    sign = 1.f;
    goto L6;
L5:
    sign = -1.f;
L6:
    z__2.r = xl.r * xl.r - xl.i * xl.i, z__2.i = xl.r * xl.i + xl.i * xl.r;
    z_div(&z__1, &c_b245, &z__2);
    dgam.r = z__1.r, dgam.i = z__1.i;
    z__6.r = evlcom_1.ct3.r * dgam.r - evlcom_1.ct3.i * dgam.i, z__6.i = 
	    evlcom_1.ct3.r * dgam.i + evlcom_1.ct3.i * dgam.r;
    z__5.r = z__6.r + evlcom_1.ct2.r, z__5.i = z__6.i + evlcom_1.ct2.i;
    z__4.r = z__5.r * dgam.r - z__5.i * dgam.i, z__4.i = z__5.r * dgam.i + 
	    z__5.i * dgam.r;
    z__3.r = z__4.r + evlcom_1.ct1.r, z__3.i = z__4.i + evlcom_1.ct1.i;
    z__2.r = sign * z__3.r, z__2.i = sign * z__3.i;
    z_div(&z__1, &z__2, &xl);
    dgam.r = z__1.r, dgam.i = z__1.i;
L7:
    z__2.r = evlcom_1.cksm.r * dgam.r - evlcom_1.cksm.i * dgam.i, z__2.i = 
	    evlcom_1.cksm.r * dgam.i + evlcom_1.cksm.i * dgam.r;
    z__5.r = evlcom_1.ck1sq.r * cgam2.r - evlcom_1.ck1sq.i * cgam2.i, z__5.i =
	     evlcom_1.ck1sq.r * cgam2.i + evlcom_1.ck1sq.i * cgam2.r;
    z__6.r = evlcom_1.ck2sq * cgam1.r, z__6.i = evlcom_1.ck2sq * cgam1.i;
    z__4.r = z__5.r + z__6.r, z__4.i = z__5.i + z__6.i;
    z__3.r = cgam2.r * z__4.r - cgam2.i * z__4.i, z__3.i = cgam2.r * z__4.i + 
	    cgam2.i * z__4.r;
    z_div(&z__1, &z__2, &z__3);
    den2.r = z__1.r, den2.i = z__1.i;
    z__3.r = cgam1.r + cgam2.r, z__3.i = cgam1.i + cgam2.i;
    z_div(&z__2, &c_b245, &z__3);
    z_div(&z__4, &evlcom_1.cksm, &cgam2);
    z__1.r = z__2.r - z__4.r, z__1.i = z__2.i - z__4.i;
    den1.r = z__1.r, den1.i = z__1.i;
    z__2.r = dxl.r * xl.r - dxl.i * xl.i, z__2.i = dxl.r * xl.i + dxl.i * 
	    xl.r;
    z__5.r = -cgam2.r, z__5.i = -cgam2.i;
    z__4.r = evlcom_1.zph * z__5.r, z__4.i = evlcom_1.zph * z__5.i;
    z_exp(&z__3, &z__4);
    z__1.r = z__2.r * z__3.r - z__2.i * z__3.i, z__1.i = z__2.r * z__3.i + 
	    z__2.i * z__3.r;
    com.r = z__1.r, com.i = z__1.i;
    z__3.r = com.r * b0.r - com.i * b0.i, z__3.i = com.r * b0.i + com.i * 
	    b0.r;
    z__2.r = z__3.r * den1.r - z__3.i * den1.i, z__2.i = z__3.r * den1.i + 
	    z__3.i * den1.r;
    z_div(&z__1, &z__2, &evlcom_1.ck1);
    ans[6].r = z__1.r, ans[6].i = z__1.i;
    z__1.r = com.r * den2.r - com.i * den2.i, z__1.i = com.r * den2.i + com.i 
	    * den2.r;
    com.r = z__1.r, com.i = z__1.i;
    if (evlcom_1.rho == 0.f) {
	goto L8;
    }
    z__1.r = b0p.r / evlcom_1.rho, z__1.i = b0p.i / evlcom_1.rho;
    b0p.r = z__1.r, b0p.i = z__1.i;
    z__3.r = -com.r, z__3.i = -com.i;
    z__2.r = z__3.r * xl.r - z__3.i * xl.i, z__2.i = z__3.r * xl.i + z__3.i * 
	    xl.r;
    z__5.r = b0.r * xl.r - b0.i * xl.i, z__5.i = b0.r * xl.i + b0.i * xl.r;
    z__4.r = b0p.r + z__5.r, z__4.i = b0p.i + z__5.i;
    z__1.r = z__2.r * z__4.r - z__2.i * z__4.i, z__1.i = z__2.r * z__4.i + 
	    z__2.i * z__4.r;
    ans[1].r = z__1.r, ans[1].i = z__1.i;
    z__2.r = com.r * xl.r - com.i * xl.i, z__2.i = com.r * xl.i + com.i * 
	    xl.r;
    z__1.r = z__2.r * b0p.r - z__2.i * b0p.i, z__1.i = z__2.r * b0p.i + 
	    z__2.i * b0p.r;
    ans[4].r = z__1.r, ans[4].i = z__1.i;
    goto L9;
L8:
    z__4.r = -com.r, z__4.i = -com.i;
    z__3.r = z__4.r * xl.r - z__4.i * xl.i, z__3.i = z__4.r * xl.i + z__4.i * 
	    xl.r;
    z__2.r = z__3.r * xl.r - z__3.i * xl.i, z__2.i = z__3.r * xl.i + z__3.i * 
	    xl.r;
    z__1.r = z__2.r * .5f, z__1.i = z__2.i * .5f;
    ans[1].r = z__1.r, ans[1].i = z__1.i;
    ans[4].r = ans[1].r, ans[4].i = ans[1].i;
L9:
    z__3.r = com.r * cgam2.r - com.i * cgam2.i, z__3.i = com.r * cgam2.i + 
	    com.i * cgam2.r;
    z__2.r = z__3.r * cgam2.r - z__3.i * cgam2.i, z__2.i = z__3.r * cgam2.i + 
	    z__3.i * cgam2.r;
    z__1.r = z__2.r * b0.r - z__2.i * b0.i, z__1.i = z__2.r * b0.i + z__2.i * 
	    b0.r;
    ans[2].r = z__1.r, ans[2].i = z__1.i;
    z__3.r = -ans[4].r, z__3.i = -ans[4].i;
    z__2.r = z__3.r * cgam2.r - z__3.i * cgam2.i, z__2.i = z__3.r * cgam2.i + 
	    z__3.i * cgam2.r;
    z__1.r = evlcom_1.rho * z__2.r, z__1.i = evlcom_1.rho * z__2.i;
    ans[3].r = z__1.r, ans[3].i = z__1.i;
    z__1.r = com.r * b0.r - com.i * b0.i, z__1.i = com.r * b0.i + com.i * 
	    b0.r;
    ans[5].r = z__1.r, ans[5].i = z__1.i;
    return 0;
} /* saoa_ */

/* *********************************************************************** */
/* av03 SUBROUTINE TEST (F1R,F2R,TR,F1I,F2I,TI,DMIN) */

/* av03	Routine already available, note however the SAVE statement. */

/* *********************************************************************** */

/*     TEST FOR CONVERGENCE IN NUMERICAL INTEGRATION */

/* av03      IMPLICIT REAL*8(A-H,O-Z) */
/* av03      SAVE */
/* av03      DEN=ABS(F2R) */
/* av03      TR=ABS(F2I) */
/* av03      IF (DEN.LT.TR) DEN=TR */
/* av03      IF (DEN.LT.DMIN) DEN=DMIN */
/* av03      IF (DEN.LT.1.E-37) GO TO 1 */
/* av03      TR=ABS((F1R-F2R)/DEN) */
/* av03      TI=ABS((F1I-F2I)/DEN) */
/* av03      RETURN */
/* av03 */
/* av031     TR=0. */
/* av03      TI=0. */
/* av03      RETURN */
/* av03      END */
/* av03      SUBROUTINE SECOND (CPUSECD) */
/*     Purpose: */
/*     SECOND returns cpu time in seconds.  Must be customized!!! */
/* av03      REAL*8 CPUSECD */
/* av03      integer Iticks */
/* av03 */
/* --   Not customized: */
/*       Cpusecd = 0.0            ! if we have no clock routine */
/* --   MACINTOSH: */
/*       CPUSECD= LONG(362)/60.0 */
/* --   Lahey fortran */
/*        Call Timer(Iticks) */
/* av03        cpusecd = Iticks/100.d0 */
/* av03      END */
/* av03 ################## END OF SOM2D INCLUDE ########################## */
/* *********************************************************************** */
/* Subroutine */ int arc_(integer *itg, integer *ns, doublereal *rada, 
	doublereal *ang1, doublereal *ang2, doublereal *rad)
{
    /* Initialized data */

    static doublereal ta = .01745329252;

    /* Format strings */
    static char fmt_3[] = "(\002 ERROR -- ARC ANGLE EXCEEDS 360. DEGREES\002)"
	    ;

    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);
    double cos(doublereal), sin(doublereal);

    /* Local variables */
    integer i__;
#define x2 ((doublereal *)&data_1 + 4500)
#define y2 ((doublereal *)&data_1 + 7500)
#define z2 ((doublereal *)&data_1 + 9000)
    doublereal xs1, xs2, zs1, zs2, ang;
    integer ist;
    doublereal dang;

    /* Fortran I/O blocks */
    static cilist io___396 = { 0, 3, 0, fmt_3, 0 };


/* *********************************************************************** */
/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* Max number of segments 	(Windows-95 <= 4 */
/* max nr of 'in-core' alloc.	(MAXMAT <= MA */
/* Max number of LD cards */
/* Max number of EX cards */
/* Max number of segs connected to NT/TL */
/* *** */

/*     ARC GENERATES SEGMENT GEOMETRY DATA FOR AN ARC OF NS SEGMENTS */

    ist = data_1.n + 1;
    data_1.n += *ns;
    data_1.np = data_1.n;
    data_1.mp = data_1.m;
    data_1.ipsym = 0;
    if (*ns < 1) {
	return 0;
    }
    if ((d__1 = *ang2 - *ang1, abs(d__1)) < 360.00001) {
	goto L1;
    }
    s_wsfe(&io___396);
    e_wsfe();
    s_stop("", (ftnlen)0);
L1:
    ang = *ang1 * ta;
    dang = (*ang2 - *ang1) * ta / *ns;
    xs1 = *rada * cos(ang);
    zs1 = *rada * sin(ang);
    i__1 = data_1.n;
    for (i__ = ist; i__ <= i__1; ++i__) {
	ang += dang;
	xs2 = *rada * cos(ang);
	zs2 = *rada * sin(ang);
	data_1.x[i__ - 1] = xs1;
	data_1.y[i__ - 1] = 0.f;
	data_1.z__[i__ - 1] = zs1;
	x2[i__ - 1] = xs2;
	y2[i__ - 1] = 0.f;
	z2[i__ - 1] = zs2;
	xs1 = xs2;
	zs1 = zs2;
	data_1.bi[i__ - 1] = *rad;
/* L2: */
	data_1.itag[i__ - 1] = *itg;
    }
    return 0;

} /* arc_ */

#undef z2
#undef y2
#undef x2


doublereal atgn2_(doublereal *x, doublereal *y)
{
    /* System generated locals */
    doublereal ret_val;

    /* Builtin functions */
    double atan2(doublereal, doublereal);

/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* *** */

/*     ATGN2 IS ARCTANGENT FUNCTION MODIFIED TO RETURN 0. WHEN X=Y=0. */

    if (*x != 0.) {
	goto L3;
    } else {
	goto L1;
    }
L1:
    if (*y != 0.) {
	goto L3;
    } else {
	goto L2;
    }
L2:
    ret_val = 0.f;
    return ret_val;
L3:
    ret_val = atan2(*x, *y);
    return ret_val;
} /* atgn2_ */

/* Subroutine */ int blckot_0_(int n__, doublecomplex *ar, integer *nunit, 
	integer *ix1, integer *ix2, integer *nblks, integer *neof)
{
    /* Format strings */
    static char fmt_4[] = "(\002  EOF ON UNIT\002,i3,\002  NBLKS= \002,i3"
	    ",\002  NEOF= \002,i5)";

    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Builtin functions */
    integer s_wsue(cilist *), do_uio(integer *, char *, ftnlen), e_wsue(void),
	     s_rsue(cilist *), e_rsue(void), s_wsfe(cilist *), do_fio(integer 
	    *, char *, ftnlen), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer i__, j, i1, i2;

    /* Fortran I/O blocks */
    static cilist io___406 = { 0, 0, 0, 0, 0 };
    static cilist io___409 = { 0, 0, 1, 0, 0 };
    static cilist io___410 = { 0, 3, 0, fmt_4, 0 };


/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* *** */

/*     BLCKOT CONTROLS THE READING AND WRITING OF MATRIX BLOCKS ON FILES */
/*     FOR THE OUT-OF-CORE MATRIX SOLUTION. */

    /* Parameter adjustments */
    --ar;

    /* Function Body */
    switch(n__) {
	case 1: goto L_blckin;
	}

    i1 = (*ix1 + 1) / 2;
    i2 = (*ix2 + 1) / 2;
/* L1: */
    io___406.ciunit = *nunit;
    s_wsue(&io___406);
    i__1 = i2;
    for (j = i1; j <= i__1; ++j) {
	do_uio(&c__2, (char *)&ar[j], (ftnlen)sizeof(doublereal));
    }
    e_wsue();
    return 0;

L_blckin:
    i1 = (*ix1 + 1) / 2;
    i2 = (*ix2 + 1) / 2;
    i__1 = *nblks;
    for (i__ = 1; i__ <= i__1; ++i__) {
	io___409.ciunit = *nunit;
	i__2 = s_rsue(&io___409);
	if (i__2 != 0) {
	    goto L3;
	}
	i__3 = i2;
	for (j = i1; j <= i__3; ++j) {
	    i__2 = do_uio(&c__2, (char *)&ar[j], (ftnlen)sizeof(doublereal));
	    if (i__2 != 0) {
		goto L3;
	    }
	}
	i__2 = e_rsue();
	if (i__2 != 0) {
	    goto L3;
	}
/* L2: */
    }
    return 0;
L3:
    s_wsfe(&io___410);
    do_fio(&c__1, (char *)&(*nunit), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*nblks), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*neof), (ftnlen)sizeof(integer));
    e_wsfe();
    if (*neof != 777) {
	s_stop("", (ftnlen)0);
    }
    *neof = 0;
    return 0;

} /* blckot_ */

/* Subroutine */ int blckot_(doublecomplex *ar, integer *nunit, integer *ix1, 
	integer *ix2, integer *nblks, integer *neof)
{
    return blckot_0_(0, ar, nunit, ix1, ix2, nblks, neof);
    }

/* Subroutine */ int blckin_(doublecomplex *ar, integer *nunit, integer *ix1, 
	integer *ix2, integer *nblks, integer *neof)
{
    return blckot_0_(1, ar, nunit, ix1, ix2, nblks, neof);
    }

/* Subroutine */ int cabc_(doublecomplex *curx)
{
    /* Initialized data */

    static doublereal tp = 6.283185308;
    static struct {
	doublereal e_1[2];
	} equiv_6 = { 0., -.01666666667 };


    /* System generated locals */
    integer i__1, i__2, i__3, i__4;
    doublereal d__1, d__2;
    doublecomplex z__1, z__2, z__3;

    /* Builtin functions */
    double d_imag(doublecomplex *), log(doublereal), cos(doublereal), sin(
	    doublereal);

    /* Local variables */
    integer i__, j, k;
    doublereal ai, ar;
    integer is;
    doublereal sh;
    integer jx;
    doublecomplex cs1, cs2;
#define t1x ((doublereal *)&data_1 + 4500)
#define t1y ((doublereal *)&data_1 + 7500)
#define t1z ((doublereal *)&data_1 + 9000)
#define t2x ((doublereal *)&data_1 + 10501)
#define t2y ((doublereal *)&data_1 + 12001)
#define t2z ((doublereal *)&data_1 + 13501)
#define ccj ((doublecomplex *)&equiv_6)
    extern /* Subroutine */ int tbf_(integer *, integer *);
    integer jco1, jco2;
#define ccjx ((doublereal *)&equiv_6)
    doublecomplex curd;

/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* Max number of segments 	(Windows-95 <= 4 */
/* max nr of 'in-core' alloc.	(MAXMAT <= MA */
/* Max number of LD cards */
/* Max number of EX cards */
/* Max number of segs connected to NT/TL */
/* *** */

/*     CABC COMPUTES COEFFICIENTS OF THE CONSTANT (A), SINE (B), AND */
/*     COSINE (C) TERMS IN THE CURRENT INTERPOLATION FUNCTIONS FOR THE */
/*     CURRENT VECTOR CUR. */

/* av07 COMMON /VSORC/ VQD(30),VSANT(30),VQDS(30),IVQD(30),ISANT(30),IQDS( */
/* av07 130),NVQD,NSANT,NQDS */
/* av07 */
    /* Parameter adjustments */
    --curx;

    /* Function Body */
    if (data_1.n == 0) {
	goto L6;
    }
    i__1 = data_1.n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	crnt_1.air[i__ - 1] = 0.f;
	crnt_1.aii[i__ - 1] = 0.f;
	crnt_1.bir[i__ - 1] = 0.f;
	crnt_1.bii[i__ - 1] = 0.f;
	crnt_1.cir[i__ - 1] = 0.f;
/* L1: */
	crnt_1.cii[i__ - 1] = 0.f;
    }
    i__1 = data_1.n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = i__;
	ar = curx[i__2].r;
	ai = d_imag(&curx[i__]);
	tbf_(&i__, &c__1);
	i__2 = segj_1.jsno;
	for (jx = 1; jx <= i__2; ++jx) {
	    j = segj_1.jco[jx - 1];
	    crnt_1.air[j - 1] += segj_1.ax[jx - 1] * ar;
	    crnt_1.aii[j - 1] += segj_1.ax[jx - 1] * ai;
	    crnt_1.bir[j - 1] += segj_1.bx[jx - 1] * ar;
	    crnt_1.bii[j - 1] += segj_1.bx[jx - 1] * ai;
	    crnt_1.cir[j - 1] += segj_1.cx[jx - 1] * ar;
/* L2: */
	    crnt_1.cii[j - 1] += segj_1.cx[jx - 1] * ai;
	}
    }
    if (vsorc_1.nqds == 0) {
	goto L4;
    }
    i__2 = vsorc_1.nqds;
    for (is = 1; is <= i__2; ++is) {
	i__ = vsorc_1.iqds[is - 1];
	jx = data_1.icon1[i__ - 1];
	data_1.icon1[i__ - 1] = 0;
	tbf_(&i__, &c__0);
	data_1.icon1[i__ - 1] = jx;
	sh = data_1.si[i__ - 1] * .5f;
	i__1 = is - 1;
	z__2.r = ccj->r * vsorc_1.vqds[i__1].r - ccj->i * vsorc_1.vqds[i__1]
		.i, z__2.i = ccj->r * vsorc_1.vqds[i__1].i + ccj->i * 
		vsorc_1.vqds[i__1].r;
	d__1 = (log(sh * 2.f / data_1.bi[i__ - 1]) - 1.f) * (segj_1.bx[
		segj_1.jsno - 1] * cos(tp * sh) + segj_1.cx[segj_1.jsno - 1] *
		 sin(tp * sh)) * data_1.wlam;
	z__1.r = z__2.r / d__1, z__1.i = z__2.i / d__1;
	curd.r = z__1.r, curd.i = z__1.i;
	ar = curd.r;
	ai = d_imag(&curd);
	i__1 = segj_1.jsno;
	for (jx = 1; jx <= i__1; ++jx) {
	    j = segj_1.jco[jx - 1];
	    crnt_1.air[j - 1] += segj_1.ax[jx - 1] * ar;
	    crnt_1.aii[j - 1] += segj_1.ax[jx - 1] * ai;
	    crnt_1.bir[j - 1] += segj_1.bx[jx - 1] * ar;
	    crnt_1.bii[j - 1] += segj_1.bx[jx - 1] * ai;
	    crnt_1.cir[j - 1] += segj_1.cx[jx - 1] * ar;
/* L3: */
	    crnt_1.cii[j - 1] += segj_1.cx[jx - 1] * ai;
	}
    }
L4:
    i__1 = data_1.n;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L5: */
	i__2 = i__;
	d__1 = crnt_1.air[i__ - 1] + crnt_1.cir[i__ - 1];
	d__2 = crnt_1.aii[i__ - 1] + crnt_1.cii[i__ - 1];
	z__1.r = d__1, z__1.i = d__2;
	curx[i__2].r = z__1.r, curx[i__2].i = z__1.i;
    }
L6:
    if (data_1.m == 0) {
	return 0;
    }
/*     CONVERT SURFACE CURRENTS FROM T1,T2 COMPONENTS TO X,Y,Z COMPONENTS */
    k = data_1.ld - data_1.m;
    jco1 = data_1.n + (data_1.m << 1) + 1;
    jco2 = jco1 + data_1.m;
    i__2 = data_1.m;
    for (i__ = 1; i__ <= i__2; ++i__) {
	++k;
	jco1 += -2;
	jco2 += -3;
	i__1 = jco1;
	cs1.r = curx[i__1].r, cs1.i = curx[i__1].i;
	i__1 = jco1 + 1;
	cs2.r = curx[i__1].r, cs2.i = curx[i__1].i;
	i__1 = jco2;
	i__3 = k - 1;
	z__2.r = t1x[i__3] * cs1.r, z__2.i = t1x[i__3] * cs1.i;
	i__4 = k - 1;
	z__3.r = t2x[i__4] * cs2.r, z__3.i = t2x[i__4] * cs2.i;
	z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
	curx[i__1].r = z__1.r, curx[i__1].i = z__1.i;
	i__1 = jco2 + 1;
	i__3 = k - 1;
	z__2.r = t1y[i__3] * cs1.r, z__2.i = t1y[i__3] * cs1.i;
	i__4 = k - 1;
	z__3.r = t2y[i__4] * cs2.r, z__3.i = t2y[i__4] * cs2.i;
	z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
	curx[i__1].r = z__1.r, curx[i__1].i = z__1.i;
/* L7: */
	i__1 = jco2 + 2;
	i__3 = k - 1;
	z__2.r = t1z[i__3] * cs1.r, z__2.i = t1z[i__3] * cs1.i;
	i__4 = k - 1;
	z__3.r = t2z[i__4] * cs2.r, z__3.i = t2z[i__4] * cs2.i;
	z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
	curx[i__1].r = z__1.r, curx[i__1].i = z__1.i;
    }
    return 0;
} /* cabc_ */

#undef ccjx
#undef ccj
#undef t2z
#undef t2y
#undef t2x
#undef t1z
#undef t1y
#undef t1x


doublereal cang_(doublecomplex *z__)
{
    /* System generated locals */
    doublereal ret_val, d__1, d__2;

    /* Builtin functions */
    double d_imag(doublecomplex *);

    /* Local variables */
    extern doublereal atgn2_(doublereal *, doublereal *);

/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* *** */

/*     CANG RETURNS THE PHASE ANGLE OF A COMPLEX NUMBER IN DEGREES. */

    d__1 = d_imag(z__);
    d__2 = z__->r;
    ret_val = atgn2_(&d__1, &d__2) * 57.29577951;
    return ret_val;
} /* cang_ */

/* Subroutine */ int cmngf_(doublecomplex *cb, doublecomplex *cc, 
	doublecomplex *cd, integer *nb, integer *nc, integer *nd, doublereal *
	rkhx, integer *iexkx)
{
    /* System generated locals */
    integer cb_dim1, cb_offset, cc_dim1, cc_offset, cd_dim1, cd_offset, i__1, 
	    i__2, i__3, i__4, i__5;
    doublereal d__1;
    doublecomplex z__1, z__2;
    alist al__1;

    /* Builtin functions */
    integer f_rew(alist *), s_wsue(cilist *), do_uio(integer *, char *, 
	    ftnlen), e_wsue(void);

    /* Local variables */
    integer i__, j, i1, i2, it, ir, ix, jx, im1, im2, in2, in1;
    extern /* Subroutine */ int tbf_(integer *, integer *);
    integer meq, imx, ist, isv, itx, jss, jsx, m1eq, m2eq, iblk, neqn, neqp;
    extern /* Subroutine */ int cmss_(integer *, integer *, integer *, 
	    integer *, doublecomplex *, integer *, integer *);
    integer neqs;
    extern /* Subroutine */ int cmws_(integer *, integer *, integer *, 
	    doublecomplex *, integer *, doublecomplex *, integer *, integer *)
	    , cmsw_(integer *, integer *, integer *, integer *, doublecomplex 
	    *, doublecomplex *, integer *, integer *, integer *), trio_(
	    integer *), cmww_(integer *, integer *, integer *, doublecomplex *
	    , integer *, doublecomplex *, integer *, integer *);
    integer isvv, neqsp;

    /* Fortran I/O blocks */
    static cilist io___458 = { 0, 14, 0, 0, 0 };
    static cilist io___461 = { 0, 12, 0, 0, 0 };
    static cilist io___462 = { 0, 15, 0, 0, 0 };


/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* Max number of segments 	(Windows-95 <= 4 */
/* max nr of 'in-core' alloc.	(MAXMAT <= MA */
/* Max number of LD cards */
/* Max number of EX cards */
/* Max number of segs connected to NT/TL */
/* *** */
/*     CMNGF FILLS INTERACTION MATRICIES B, C, AND D FOR N.G.F. SOLUTION */
    /* Parameter adjustments */
    cb_dim1 = *nb;
    cb_offset = 1 + cb_dim1;
    cb -= cb_offset;
    cc_dim1 = *nc;
    cc_offset = 1 + cc_dim1;
    cc -= cc_offset;
    cd_dim1 = *nd;
    cd_offset = 1 + cd_dim1;
    cd -= cd_offset;

    /* Function Body */
    dataj_1.rkh = *rkhx;
    dataj_1.iexk = *iexkx;
    m1eq = data_1.m1 << 1;
    m2eq = m1eq + 1;
    meq = data_1.m << 1;
    neqp = *nd - (segj_1.npcon << 1);
    neqs = neqp - segj_1.nscon;
    neqsp = neqs + *nc;
    neqn = *nc + data_1.n - data_1.n1;
    itx = 1;
    if (segj_1.nscon > 0) {
	itx = 2;
    }
    if (matpar_1.icasx == 1) {
	goto L1;
    }
    al__1.aerr = 0;
    al__1.aunit = 12;
    f_rew(&al__1);
    al__1.aerr = 0;
    al__1.aunit = 14;
    f_rew(&al__1);
    al__1.aerr = 0;
    al__1.aunit = 15;
    f_rew(&al__1);
    if (matpar_1.icasx > 2) {
	goto L5;
    }
L1:
    i__1 = *nd;
    for (j = 1; j <= i__1; ++j) {
	i__2 = *nd;
	for (i__ = 1; i__ <= i__2; ++i__) {
/* L2: */
	    i__3 = i__ + j * cd_dim1;
	    cd[i__3].r = 0.f, cd[i__3].i = 0.f;
	}
	i__3 = *nb;
	for (i__ = 1; i__ <= i__3; ++i__) {
	    i__2 = i__ + j * cb_dim1;
	    cb[i__2].r = 0.f, cb[i__2].i = 0.f;
/* L3: */
	    i__2 = i__ + j * cc_dim1;
	    cc[i__2].r = 0.f, cc[i__2].i = 0.f;
	}
/* L4: */
    }
L5:
    ist = data_1.n - data_1.n1 + 1;
    it = matpar_1.npbx;
    isv = -matpar_1.npbx;
/*     LOOP THRU 24 FILLS B.  FOR ICASX=1 OR 2 ALSO FILLS D(WW), D(WS) */
    i__1 = matpar_1.nbbx;
    for (iblk = 1; iblk <= i__1; ++iblk) {
	isv += matpar_1.npbx;
	if (iblk == matpar_1.nbbx) {
	    it = matpar_1.nlbx;
	}
	if (matpar_1.icasx < 3) {
	    goto L7;
	}
	i__2 = *nd;
	for (j = 1; j <= i__2; ++j) {
	    i__3 = it;
	    for (i__ = 1; i__ <= i__3; ++i__) {
/* L6: */
		i__4 = i__ + j * cb_dim1;
		cb[i__4].r = 0.f, cb[i__4].i = 0.f;
	    }
	}
L7:
	i1 = isv + 1;
	i2 = isv + it;
	in2 = i2;
	if (in2 > data_1.n1) {
	    in2 = data_1.n1;
	}
	im1 = i1 - data_1.n1;
	im2 = i2 - data_1.n1;
	if (im1 < 1) {
	    im1 = 1;
	}
	imx = 1;
	if (i1 <= data_1.n1) {
	    imx = data_1.n1 - i1 + 2;
	}
	if (data_1.n2 > data_1.n) {
	    goto L12;
	}
/*     FILL B(WW),B(WS).  FOR ICASX=1,2 FILL D(WW),D(WS) */
	i__4 = data_1.n;
	for (j = data_1.n2; j <= i__4; ++j) {
	    trio_(&j);
	    i__3 = segj_1.jsno;
	    for (i__ = 1; i__ <= i__3; ++i__) {
		jss = segj_1.jco[i__ - 1];
		if (jss < data_1.n2) {
		    goto L8;
		}
/*     SET JCO WHEN SOURCE IS NEW BASIS FUNCTION ON NEW SEGMENT */
		segj_1.jco[i__ - 1] = jss - data_1.n1;
		goto L9;
/*     SOURCE IS PORTION OF MODIFIED BASIS FUNCTION ON NEW SEGMENT */
L8:
		segj_1.jco[i__ - 1] = neqs + data_1.iconx[jss - 1];
L9:
		;
	    }
	    if (i1 <= in2) {
		cmww_(&j, &i1, &in2, &cb[cb_offset], nb, &cb[cb_offset], nb, &
			c__0);
	    }
	    if (im1 <= im2) {
		cmws_(&j, &im1, &im2, &cb[imx + cb_dim1], nb, &cb[cb_offset], 
			nb, &c__0);
	    }
	    if (matpar_1.icasx > 2) {
		goto L11;
	    }
	    cmww_(&j, &data_1.n2, &data_1.n, &cd[cd_offset], nd, &cd[
		    cd_offset], nd, &c__1);
	    if (data_1.m2 <= data_1.m) {
		cmws_(&j, &m2eq, &meq, &cd[ist * cd_dim1 + 1], nd, &cd[
			cd_offset], nd, &c__1);
	    }
/*     LOADING IN D(WW) */
	    if (zload_1.nload == 0) {
		goto L11;
	    }
	    ir = j - data_1.n1;
	    i__3 = j - 1;
	    dataj_1.exk.r = zload_1.zarray[i__3].r, dataj_1.exk.i = 
		    zload_1.zarray[i__3].i;
	    i__3 = segj_1.jsno;
	    for (i__ = 1; i__ <= i__3; ++i__) {
		jss = segj_1.jco[i__ - 1];
/* L10: */
		i__2 = jss + ir * cd_dim1;
		i__5 = jss + ir * cd_dim1;
		d__1 = segj_1.ax[i__ - 1] + segj_1.cx[i__ - 1];
		z__2.r = d__1 * dataj_1.exk.r, z__2.i = d__1 * dataj_1.exk.i;
		z__1.r = cd[i__5].r - z__2.r, z__1.i = cd[i__5].i - z__2.i;
		cd[i__2].r = z__1.r, cd[i__2].i = z__1.i;
	    }
L11:
	    ;
	}
L12:
	if (segj_1.nscon == 0) {
	    goto L20;
	}
/*     FILL B(WW)PRIME */
	i__4 = segj_1.nscon;
	for (i__ = 1; i__ <= i__4; ++i__) {
	    j = segj_1.iscon[i__ - 1];
/*     SOURCES ARE NEW OR MODIFIED BASIS FUNCTIONS ON OLD SEGMENTS WHICH */
/*     CONNECT TO NEW SEGMENTS */
	    trio_(&j);
	    jss = 0;
	    i__2 = segj_1.jsno;
	    for (ix = 1; ix <= i__2; ++ix) {
		ir = segj_1.jco[ix - 1];
		if (ir < data_1.n2) {
		    goto L13;
		}
		ir -= data_1.n1;
		goto L14;
L13:
		ir = data_1.iconx[ir - 1];
		if (ir == 0) {
		    goto L15;
		}
		ir = neqs + ir;
L14:
		++jss;
		segj_1.jco[jss - 1] = ir;
		segj_1.ax[jss - 1] = segj_1.ax[ix - 1];
		segj_1.bx[jss - 1] = segj_1.bx[ix - 1];
		segj_1.cx[jss - 1] = segj_1.cx[ix - 1];
L15:
		;
	    }
	    segj_1.jsno = jss;
	    if (i1 <= in2) {
		cmww_(&j, &i1, &in2, &cb[cb_offset], nb, &cb[cb_offset], nb, &
			c__0);
	    }
	    if (im1 <= im2) {
		cmws_(&j, &im1, &im2, &cb[imx + cb_dim1], nb, &cb[cb_offset], 
			nb, &c__0);
	    }
/*     SOURCE IS SINGULAR COMPONENT OF PATCH CURRENT THAT IS PART OF */
/*     MODIFIED BASIS FUNCTION FOR OLD SEGMENT THAT CONNECTS TO A NEW */
/*     SEGMENT ON END OPPOSITE PATCH. */
	    if (i1 <= in2) {
		cmsw_(&j, &i__, &i1, &in2, &cb[cb_offset], &cb[cb_offset], &
			c__0, nb, &c_n1);
	    }
	    if (zload_1.nlodf == 0) {
		goto L17;
	    }
	    jx = j - isv;
	    if (jx < 1 || jx > it) {
		goto L17;
	    }
	    i__2 = j - 1;
	    dataj_1.exk.r = zload_1.zarray[i__2].r, dataj_1.exk.i = 
		    zload_1.zarray[i__2].i;
	    i__2 = segj_1.jsno;
	    for (ix = 1; ix <= i__2; ++ix) {
		jss = segj_1.jco[ix - 1];
/* L16: */
		i__5 = jx + jss * cb_dim1;
		i__3 = jx + jss * cb_dim1;
		d__1 = segj_1.ax[ix - 1] + segj_1.cx[ix - 1];
		z__2.r = d__1 * dataj_1.exk.r, z__2.i = d__1 * dataj_1.exk.i;
		z__1.r = cb[i__3].r - z__2.r, z__1.i = cb[i__3].i - z__2.i;
		cb[i__5].r = z__1.r, cb[i__5].i = z__1.i;
	    }
/*     SOURCES ARE PORTIONS OF MODIFIED BASIS FUNCTION J ON OLD SEGMENTS */
/*     EXCLUDING OLD SEGMENTS THAT DIRECTLY CONNECT TO NEW SEGMENTS. */
L17:
	    tbf_(&j, &c__1);
	    jsx = segj_1.jsno;
	    segj_1.jsno = 1;
	    ir = segj_1.jco[0];
	    segj_1.jco[0] = neqs + i__;
	    i__5 = jsx;
	    for (ix = 1; ix <= i__5; ++ix) {
		if (ix == 1) {
		    goto L18;
		}
		ir = segj_1.jco[ix - 1];
		segj_1.ax[0] = segj_1.ax[ix - 1];
		segj_1.bx[0] = segj_1.bx[ix - 1];
		segj_1.cx[0] = segj_1.cx[ix - 1];
L18:
		if (ir > data_1.n1) {
		    goto L19;
		}
		if (data_1.iconx[ir - 1] != 0) {
		    goto L19;
		}
		if (i1 <= in2) {
		    cmww_(&ir, &i1, &in2, &cb[cb_offset], nb, &cb[cb_offset], 
			    nb, &c__0);
		}
		if (im1 <= im2) {
		    cmws_(&ir, &im1, &im2, &cb[imx + cb_dim1], nb, &cb[
			    cb_offset], nb, &c__0);
		}
/*     LOADING FOR B(WW)PRIME */
		if (zload_1.nlodf == 0) {
		    goto L19;
		}
		jx = ir - isv;
		if (jx < 1 || jx > it) {
		    goto L19;
		}
		i__3 = ir - 1;
		dataj_1.exk.r = zload_1.zarray[i__3].r, dataj_1.exk.i = 
			zload_1.zarray[i__3].i;
		jss = segj_1.jco[0];
		i__3 = jx + jss * cb_dim1;
		i__2 = jx + jss * cb_dim1;
		d__1 = segj_1.ax[0] + segj_1.cx[0];
		z__2.r = d__1 * dataj_1.exk.r, z__2.i = d__1 * dataj_1.exk.i;
		z__1.r = cb[i__2].r - z__2.r, z__1.i = cb[i__2].i - z__2.i;
		cb[i__3].r = z__1.r, cb[i__3].i = z__1.i;
L19:
		;
	    }
	}
L20:
	if (segj_1.npcon == 0) {
	    goto L22;
	}
	jss = neqp;
/*     FILL B(SS)PRIME TO SET OLD PATCH BASIS FUNCTIONS TO ZERO FOR */
/*     PATCHES THAT CONNECT TO NEW SEGMENTS */
	i__5 = segj_1.npcon;
	for (i__ = 1; i__ <= i__5; ++i__) {
	    ix = (segj_1.ipcon[i__ - 1] << 1) + data_1.n1 - isv;
	    ir = ix - 1;
	    ++jss;
	    if (ir > 0 && ir <= it) {
		i__4 = ir + jss * cb_dim1;
		cb[i__4].r = 1.f, cb[i__4].i = 0.f;
	    }
	    ++jss;
	    if (ix > 0 && ix <= it) {
		i__4 = ix + jss * cb_dim1;
		cb[i__4].r = 1.f, cb[i__4].i = 0.f;
	    }
/* L21: */
	}
L22:
	if (data_1.m2 > data_1.m) {
	    goto L23;
	}
/*     FILL B(SW) AND B(SS) */
	if (i1 <= in2) {
	    cmsw_(&data_1.m2, &data_1.m, &i1, &in2, &cb[ist * cb_dim1 + 1], &
		    cb[cb_offset], &data_1.n1, nb, &c__0);
	}
	if (im1 <= im2) {
	    cmss_(&data_1.m2, &data_1.m, &im1, &im2, &cb[imx + ist * cb_dim1],
		     nb, &c__0);
	}
L23:
	if (matpar_1.icasx == 1) {
	    goto L24;
	}
	s_wsue(&io___458);
	i__5 = *nd;
	for (j = 1; j <= i__5; ++j) {
	    i__4 = it;
	    for (i__ = 1; i__ <= i__4; ++i__) {
		do_uio(&c__2, (char *)&cb[i__ + j * cb_dim1], (ftnlen)sizeof(
			doublereal));
	    }
	}
	e_wsue();
L24:
	;
    }
/*     FILLING B COMPLETE.  START ON C AND D */
    it = matpar_1.npbl;
    isv = -matpar_1.npbl;
    i__1 = matpar_1.nbbl;
    for (iblk = 1; iblk <= i__1; ++iblk) {
	isv += matpar_1.npbl;
	isvv = isv + *nc;
	if (iblk == matpar_1.nbbl) {
	    it = matpar_1.nlbl;
	}
	if (matpar_1.icasx < 3) {
	    goto L27;
	}
	i__4 = it;
	for (j = 1; j <= i__4; ++j) {
	    i__5 = *nc;
	    for (i__ = 1; i__ <= i__5; ++i__) {
/* L25: */
		i__3 = i__ + j * cc_dim1;
		cc[i__3].r = 0.f, cc[i__3].i = 0.f;
	    }
	    i__3 = *nd;
	    for (i__ = 1; i__ <= i__3; ++i__) {
/* L26: */
		i__5 = i__ + j * cd_dim1;
		cd[i__5].r = 0.f, cd[i__5].i = 0.f;
	    }
	}
L27:
	i1 = isvv + 1;
	i2 = isvv + it;
	in1 = i1 - m1eq;
	in2 = i2 - m1eq;
	if (in2 > data_1.n) {
	    in2 = data_1.n;
	}
	im1 = i1 - data_1.n;
	im2 = i2 - data_1.n;
	if (im1 < m2eq) {
	    im1 = m2eq;
	}
	if (im2 > meq) {
	    im2 = meq;
	}
	imx = 1;
	if (in1 <= in2) {
	    imx = neqn - i1 + 2;
	}
	if (matpar_1.icasx < 3) {
	    goto L32;
	}
	if (data_1.n2 > data_1.n) {
	    goto L32;
	}
/*     SAME AS DO 24 LOOP TO FILL D(WW) FOR ICASX GREATER THAN 2 */
	i__5 = data_1.n;
	for (j = data_1.n2; j <= i__5; ++j) {
	    trio_(&j);
	    i__3 = segj_1.jsno;
	    for (i__ = 1; i__ <= i__3; ++i__) {
		jss = segj_1.jco[i__ - 1];
		if (jss < data_1.n2) {
		    goto L28;
		}
		segj_1.jco[i__ - 1] = jss - data_1.n1;
		goto L29;
L28:
		segj_1.jco[i__ - 1] = neqs + data_1.iconx[jss - 1];
L29:
		;
	    }
	    if (in1 <= in2) {
		cmww_(&j, &in1, &in2, &cd[cd_offset], nd, &cd[cd_offset], nd, 
			&c__1);
	    }
	    if (im1 <= im2) {
		cmws_(&j, &im1, &im2, &cd[imx * cd_dim1 + 1], nd, &cd[
			cd_offset], nd, &c__1);
	    }
	    if (zload_1.nload == 0) {
		goto L31;
	    }
	    ir = j - data_1.n1 - isv;
	    if (ir < 1 || ir > it) {
		goto L31;
	    }
	    i__3 = j - 1;
	    dataj_1.exk.r = zload_1.zarray[i__3].r, dataj_1.exk.i = 
		    zload_1.zarray[i__3].i;
	    i__3 = segj_1.jsno;
	    for (i__ = 1; i__ <= i__3; ++i__) {
		jss = segj_1.jco[i__ - 1];
/* L30: */
		i__4 = jss + ir * cd_dim1;
		i__2 = jss + ir * cd_dim1;
		d__1 = segj_1.ax[i__ - 1] + segj_1.cx[i__ - 1];
		z__2.r = d__1 * dataj_1.exk.r, z__2.i = d__1 * dataj_1.exk.i;
		z__1.r = cd[i__2].r - z__2.r, z__1.i = cd[i__2].i - z__2.i;
		cd[i__4].r = z__1.r, cd[i__4].i = z__1.i;
	    }
L31:
	    ;
	}
L32:
	if (data_1.m2 > data_1.m) {
	    goto L33;
	}
/*     FILL D(SW) AND D(SS) */
	if (in1 <= in2) {
	    cmsw_(&data_1.m2, &data_1.m, &in1, &in2, &cd[ist + cd_dim1], &cd[
		    cd_offset], &data_1.n1, nd, &c__1);
	}
	if (im1 <= im2) {
	    cmss_(&data_1.m2, &data_1.m, &im1, &im2, &cd[ist + imx * cd_dim1],
		     nd, &c__1);
	}
L33:
	if (data_1.n1 < 1) {
	    goto L39;
	}
/*     FILL C(WW),C(WS), D(WW)PRIME, AND D(WS)PRIME. */
	i__5 = data_1.n1;
	for (j = 1; j <= i__5; ++j) {
	    trio_(&j);
	    if (segj_1.nscon == 0) {
		goto L36;
	    }
	    i__4 = segj_1.jsno;
	    for (ix = 1; ix <= i__4; ++ix) {
		jss = segj_1.jco[ix - 1];
		if (jss < data_1.n2) {
		    goto L34;
		}
		segj_1.jco[ix - 1] = jss + m1eq;
		goto L35;
L34:
		ir = data_1.iconx[jss - 1];
		if (ir != 0) {
		    segj_1.jco[ix - 1] = neqsp + ir;
		}
L35:
		;
	    }
L36:
	    if (in1 <= in2) {
		cmww_(&j, &in1, &in2, &cc[cc_offset], nc, &cd[cd_offset], nd, 
			&itx);
	    }
	    if (im1 <= im2) {
		cmws_(&j, &im1, &im2, &cc[imx * cc_dim1 + 1], nc, &cd[imx * 
			cd_dim1 + 1], nd, &itx);
	    }
/* L37: */
	}
	if (segj_1.nscon == 0) {
	    goto L39;
	}
/*     FILL C(WW)PRIME */
	i__5 = segj_1.nscon;
	for (ix = 1; ix <= i__5; ++ix) {
	    ir = segj_1.iscon[ix - 1];
	    jss = neqs + ix - isv;
	    if (jss > 0 && jss <= it) {
		i__4 = ir + jss * cc_dim1;
		cc[i__4].r = 1.f, cc[i__4].i = 0.f;
	    }
/* L38: */
	}
L39:
	if (segj_1.npcon == 0) {
	    goto L41;
	}
	jss = neqp - isv;
/*     FILL C(SS)PRIME */
	i__5 = segj_1.npcon;
	for (i__ = 1; i__ <= i__5; ++i__) {
	    ix = (segj_1.ipcon[i__ - 1] << 1) + data_1.n1;
	    ir = ix - 1;
	    ++jss;
	    if (jss > 0 && jss <= it) {
		i__4 = ir + jss * cc_dim1;
		cc[i__4].r = 1.f, cc[i__4].i = 0.f;
	    }
	    ++jss;
	    if (jss > 0 && jss <= it) {
		i__4 = ix + jss * cc_dim1;
		cc[i__4].r = 1.f, cc[i__4].i = 0.f;
	    }
/* L40: */
	}
L41:
	if (data_1.m1 < 1) {
	    goto L42;
	}
/*     FILL C(SW) AND C(SS) */
	if (in1 <= in2) {
	    cmsw_(&c__1, &data_1.m1, &in1, &in2, &cc[data_1.n2 + cc_dim1], &
		    cc[cc_offset], &c__0, nc, &c__1);
	}
	if (im1 <= im2) {
	    cmss_(&c__1, &data_1.m1, &im1, &im2, &cc[data_1.n2 + imx * 
		    cc_dim1], nc, &c__1);
	}
L42:
	if (matpar_1.icasx == 1) {
	    goto L43;
	}
	s_wsue(&io___461);
	i__5 = it;
	for (i__ = 1; i__ <= i__5; ++i__) {
	    i__4 = *nd;
	    for (j = 1; j <= i__4; ++j) {
		do_uio(&c__2, (char *)&cd[j + i__ * cd_dim1], (ftnlen)sizeof(
			doublereal));
	    }
	}
	e_wsue();
	s_wsue(&io___462);
	i__4 = it;
	for (i__ = 1; i__ <= i__4; ++i__) {
	    i__5 = *nc;
	    for (j = 1; j <= i__5; ++j) {
		do_uio(&c__2, (char *)&cc[j + i__ * cc_dim1], (ftnlen)sizeof(
			doublereal));
	    }
	}
	e_wsue();
L43:
	;
    }
    if (matpar_1.icasx == 1) {
	return 0;
    }
    al__1.aerr = 0;
    al__1.aunit = 12;
    f_rew(&al__1);
    al__1.aerr = 0;
    al__1.aunit = 14;
    f_rew(&al__1);
    al__1.aerr = 0;
    al__1.aunit = 15;
    f_rew(&al__1);
    return 0;
} /* cmngf_ */

/* Subroutine */ int cmset_(integer *nrow, doublecomplex *cm, doublereal *
	rkhx, integer *iexkx)
{
    /* System generated locals */
    integer cm_dim1, cm_offset, i__1, i__2, i__3, i__4, i__5, i__6, i__7;
    doublereal d__1;
    doublecomplex z__1, z__2;
    alist al__1;

    /* Builtin functions */
    integer f_rew(alist *);

    /* Local variables */
    integer i__, j, k, i1, i2, ka, ij, kk, it, im1, im2, in2, jm1, jm2, mp2, 
	    neq;
    doublecomplex zaj;
    integer ipr, nop, isv, ist, jss, jst, npeq;
    extern /* Subroutine */ int cmss_(integer *, integer *, integer *, 
	    integer *, doublecomplex *, integer *, integer *), cmws_(integer *
	    , integer *, integer *, doublecomplex *, integer *, doublecomplex 
	    *, integer *, integer *), cmsw_(integer *, integer *, integer *, 
	    integer *, doublecomplex *, doublecomplex *, integer *, integer *,
	     integer *), trio_(integer *), cmww_(integer *, integer *, 
	    integer *, doublecomplex *, integer *, doublecomplex *, integer *,
	     integer *);
    integer iout;
    doublecomplex deter;
    integer ixblk1;
    extern /* Subroutine */ int blckot_(doublecomplex *, integer *, integer *,
	     integer *, integer *, integer *);

/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* Max number of segments 	(Windows-95 <= 4 */
/* max nr of 'in-core' alloc.	(MAXMAT <= MA */
/* Max number of LD cards */
/* Max number of EX cards */
/* Max number of segs connected to NT/TL */
/* *** */

/*     CMSET SETS UP THE COMPLEX STRUCTURE MATRIX IN THE ARRAY CM */

    /* Parameter adjustments */
    cm_dim1 = *nrow;
    cm_offset = 1 + cm_dim1;
    cm -= cm_offset;

    /* Function Body */
    mp2 = data_1.mp << 1;
    npeq = data_1.np + mp2;
    neq = data_1.n + (data_1.m << 1);
    nop = neq / npeq;
    if (matpar_1.icase > 2) {
	al__1.aerr = 0;
	al__1.aunit = 11;
	f_rew(&al__1);
    }
    dataj_1.rkh = *rkhx;
    dataj_1.iexk = *iexkx;
    iout = (matpar_1.npblk << 1) * *nrow;
    it = matpar_1.npblk;

/*     CYCLE OVER MATRIX BLOCKS */

    i__1 = matpar_1.nbloks;
    for (ixblk1 = 1; ixblk1 <= i__1; ++ixblk1) {
	isv = (ixblk1 - 1) * matpar_1.npblk;
	if (ixblk1 == matpar_1.nbloks) {
	    it = matpar_1.nlast;
	}
	i__2 = *nrow;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    i__3 = it;
	    for (j = 1; j <= i__3; ++j) {
/* L1: */
		i__4 = i__ + j * cm_dim1;
		cm[i__4].r = 0.f, cm[i__4].i = 0.f;
	    }
	}
	i1 = isv + 1;
	i2 = isv + it;
	in2 = i2;
	if (in2 > data_1.np) {
	    in2 = data_1.np;
	}
	im1 = i1 - data_1.np;
	im2 = i2 - data_1.np;
	if (im1 < 1) {
	    im1 = 1;
	}
	ist = 1;
	if (i1 <= data_1.np) {
	    ist = data_1.np - i1 + 2;
	}
	if (data_1.n == 0) {
	    goto L5;
	}

/*     WIRE SOURCE LOOP */

	i__4 = data_1.n;
	for (j = 1; j <= i__4; ++j) {
	    trio_(&j);
	    i__3 = segj_1.jsno;
	    for (i__ = 1; i__ <= i__3; ++i__) {
		ij = segj_1.jco[i__ - 1];
/* L2: */
		segj_1.jco[i__ - 1] = (ij - 1) / data_1.np * mp2 + ij;
	    }
	    if (i1 <= in2) {
		cmww_(&j, &i1, &in2, &cm[cm_offset], nrow, &cm[cm_offset], 
			nrow, &c__1);
	    }
	    if (im1 <= im2) {
		cmws_(&j, &im1, &im2, &cm[ist * cm_dim1 + 1], nrow, &cm[
			cm_offset], nrow, &c__1);
	    }
	    if (zload_1.nload == 0) {
		goto L4;
	    }

/*     MATRIX ELEMENTS MODIFIED BY LOADING */

	    if (j > data_1.np) {
		goto L4;
	    }
	    ipr = j - isv;
	    if (ipr < 1 || ipr > it) {
		goto L4;
	    }
	    i__3 = j - 1;
	    zaj.r = zload_1.zarray[i__3].r, zaj.i = zload_1.zarray[i__3].i;
	    i__3 = segj_1.jsno;
	    for (i__ = 1; i__ <= i__3; ++i__) {
		jss = segj_1.jco[i__ - 1];
/* L3: */
		i__2 = jss + ipr * cm_dim1;
		i__5 = jss + ipr * cm_dim1;
		d__1 = segj_1.ax[i__ - 1] + segj_1.cx[i__ - 1];
		z__2.r = d__1 * zaj.r, z__2.i = d__1 * zaj.i;
		z__1.r = cm[i__5].r - z__2.r, z__1.i = cm[i__5].i - z__2.i;
		cm[i__2].r = z__1.r, cm[i__2].i = z__1.i;
	    }
L4:
	    ;
	}
L5:
	if (data_1.m == 0) {
	    goto L7;
	}
/*     MATRIX ELEMENTS FOR PATCH CURRENT SOURCES */
	jm1 = 1 - data_1.mp;
	jm2 = 0;
	jst = 1 - mp2;
	i__4 = nop;
	for (i__ = 1; i__ <= i__4; ++i__) {
	    jm1 += data_1.mp;
	    jm2 += data_1.mp;
	    jst += npeq;
	    if (i1 <= in2) {
		cmsw_(&jm1, &jm2, &i1, &in2, &cm[jst + cm_dim1], &cm[
			cm_offset], &c__0, nrow, &c__1);
	    }
	    if (im1 <= im2) {
		cmss_(&jm1, &jm2, &im1, &im2, &cm[jst + ist * cm_dim1], nrow, 
			&c__1);
	    }
/* L6: */
	}
L7:
	if (matpar_1.icase == 1) {
	    goto L13;
	}
	if (matpar_1.icase == 3) {
	    goto L12;
	}
/*     COMBINE ELEMENTS FOR SYMMETRY MODES */
	i__4 = it;
	for (i__ = 1; i__ <= i__4; ++i__) {
	    i__2 = npeq;
	    for (j = 1; j <= i__2; ++j) {
		i__5 = nop;
		for (k = 1; k <= i__5; ++k) {
		    ka = j + (k - 1) * npeq;
/* L8: */
		    i__3 = k - 1;
		    i__6 = ka + i__ * cm_dim1;
		    scratm_1.d__[i__3].r = cm[i__6].r, scratm_1.d__[i__3].i = 
			    cm[i__6].i;
		}
		deter.r = scratm_1.d__[0].r, deter.i = scratm_1.d__[0].i;
		i__3 = nop;
		for (kk = 2; kk <= i__3; ++kk) {
/* L9: */
		    i__6 = kk - 1;
		    z__1.r = deter.r + scratm_1.d__[i__6].r, z__1.i = deter.i 
			    + scratm_1.d__[i__6].i;
		    deter.r = z__1.r, deter.i = z__1.i;
		}
		i__6 = j + i__ * cm_dim1;
		cm[i__6].r = deter.r, cm[i__6].i = deter.i;
		i__6 = nop;
		for (k = 2; k <= i__6; ++k) {
		    ka = j + (k - 1) * npeq;
		    deter.r = scratm_1.d__[0].r, deter.i = scratm_1.d__[0].i;
		    i__3 = nop;
		    for (kk = 2; kk <= i__3; ++kk) {
/* L10: */
			i__5 = kk - 1;
			i__7 = k + (kk << 4) - 17;
			z__2.r = scratm_1.d__[i__5].r * smat_1.ssx[i__7].r - 
				scratm_1.d__[i__5].i * smat_1.ssx[i__7].i, 
				z__2.i = scratm_1.d__[i__5].r * smat_1.ssx[
				i__7].i + scratm_1.d__[i__5].i * smat_1.ssx[
				i__7].r;
			z__1.r = deter.r + z__2.r, z__1.i = deter.i + z__2.i;
			deter.r = z__1.r, deter.i = z__1.i;
		    }
		    i__5 = ka + i__ * cm_dim1;
		    cm[i__5].r = deter.r, cm[i__5].i = deter.i;
/* L11: */
		}
	    }
	}
	if (matpar_1.icase < 3) {
	    goto L13;
	}
/*     WRITE BLOCK FOR OUT-OF-CORE CASES. */
L12:
	blckot_(&cm[cm_offset], &c__11, &c__1, &iout, &c__1, &c__31);
L13:
	;
    }
    if (matpar_1.icase > 2) {
	al__1.aerr = 0;
	al__1.aunit = 11;
	f_rew(&al__1);
    }
    return 0;
} /* cmset_ */

/* Subroutine */ int cmss_(integer *j1, integer *j2, integer *im1, integer *
	im2, doublecomplex *cm, integer *nrow, integer *itrp)
{
    /* System generated locals */
    integer cm_dim1, cm_offset, i__1, i__2, i__3;
    doublecomplex z__1, z__2, z__3, z__4, z__5, z__6;

    /* Local variables */
    integer i__, j, i1, i2;
    doublecomplex g11, g12, g21, g22;
    integer il, jl;
    doublereal xi, yi, zi;
    integer ii1, ii2, jj1, jj2;
#define t1x ((doublereal *)&data_1 + 4500)
#define t1y ((doublereal *)&data_1 + 7500)
#define t1z ((doublereal *)&data_1 + 9000)
#define t2x ((doublereal *)&data_1 + 10501)
#define t2y ((doublereal *)&data_1 + 12001)
#define t2z ((doublereal *)&data_1 + 13501)
    integer ldp;
    doublereal t1xi;
#define t1xj ((doublereal *)&dataj_1 + 5)
#define t1yj ((doublereal *)&dataj_1 + 6)
#define t1zj ((doublereal *)&dataj_1 + 7)
#define t2xj ((doublereal *)&dataj_1 + 1)
#define t2yj ((doublereal *)&dataj_1 + 27)
#define t2zj ((doublereal *)&dataj_1 + 28)
    doublereal t1yi, t1zi, t2xi, t2yi, t2zi;
    integer icomp;
    extern /* Subroutine */ int hintg_(doublereal *, doublereal *, doublereal 
	    *);

/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* Max number of segments 	(Windows-95 <= 4 */
/* max nr of 'in-core' alloc.	(MAXMAT <= MA */
/* Max number of LD cards */
/* Max number of EX cards */
/* Max number of segs connected to NT/TL */
/* *** */
/*     CMSS COMPUTES MATRIX ELEMENTS FOR SURFACE-SURFACE INTERACTIONS. */
    /* Parameter adjustments */
    cm_dim1 = *nrow;
    cm_offset = 1 + cm_dim1;
    cm -= cm_offset;

    /* Function Body */
    ldp = data_1.ld + 1;
    i1 = (*im1 + 1) / 2;
    i2 = (*im2 + 1) / 2;
    icomp = (i1 << 1) - 3;
    ii1 = -1;
    if (icomp + 2 < *im1) {
	ii1 = -2;
    }
/*     LOOP OVER OBSERVATION PATCHES */
    i__1 = i2;
    for (i__ = i1; i__ <= i__1; ++i__) {
	il = ldp - i__;
	icomp += 2;
	ii1 += 2;
	ii2 = ii1 + 1;
	t1xi = t1x[il - 1] * angl_1.salp[il - 1];
	t1yi = t1y[il - 1] * angl_1.salp[il - 1];
	t1zi = t1z[il - 1] * angl_1.salp[il - 1];
	t2xi = t2x[il - 1] * angl_1.salp[il - 1];
	t2yi = t2y[il - 1] * angl_1.salp[il - 1];
	t2zi = t2z[il - 1] * angl_1.salp[il - 1];
	xi = data_1.x[il - 1];
	yi = data_1.y[il - 1];
	zi = data_1.z__[il - 1];
	jj1 = -1;
/*     LOOP OVER SOURCE PATCHES */
	i__2 = *j2;
	for (j = *j1; j <= i__2; ++j) {
	    jl = ldp - j;
	    jj1 += 2;
	    jj2 = jj1 + 1;
	    dataj_1.s = data_1.bi[jl - 1];
	    dataj_1.xj = data_1.x[jl - 1];
	    dataj_1.yj = data_1.y[jl - 1];
	    dataj_1.zj = data_1.z__[jl - 1];
	    *t1xj = t1x[jl - 1];
	    *t1yj = t1y[jl - 1];
	    *t1zj = t1z[jl - 1];
	    *t2xj = t2x[jl - 1];
	    *t2yj = t2y[jl - 1];
	    *t2zj = t2z[jl - 1];
	    hintg_(&xi, &yi, &zi);
	    z__4.r = t2xi * dataj_1.exk.r, z__4.i = t2xi * dataj_1.exk.i;
	    z__5.r = t2yi * dataj_1.eyk.r, z__5.i = t2yi * dataj_1.eyk.i;
	    z__3.r = z__4.r + z__5.r, z__3.i = z__4.i + z__5.i;
	    z__6.r = t2zi * dataj_1.ezk.r, z__6.i = t2zi * dataj_1.ezk.i;
	    z__2.r = z__3.r + z__6.r, z__2.i = z__3.i + z__6.i;
	    z__1.r = -z__2.r, z__1.i = -z__2.i;
	    g11.r = z__1.r, g11.i = z__1.i;
	    z__4.r = t2xi * dataj_1.exs.r, z__4.i = t2xi * dataj_1.exs.i;
	    z__5.r = t2yi * dataj_1.eys.r, z__5.i = t2yi * dataj_1.eys.i;
	    z__3.r = z__4.r + z__5.r, z__3.i = z__4.i + z__5.i;
	    z__6.r = t2zi * dataj_1.ezs.r, z__6.i = t2zi * dataj_1.ezs.i;
	    z__2.r = z__3.r + z__6.r, z__2.i = z__3.i + z__6.i;
	    z__1.r = -z__2.r, z__1.i = -z__2.i;
	    g12.r = z__1.r, g12.i = z__1.i;
	    z__4.r = t1xi * dataj_1.exk.r, z__4.i = t1xi * dataj_1.exk.i;
	    z__5.r = t1yi * dataj_1.eyk.r, z__5.i = t1yi * dataj_1.eyk.i;
	    z__3.r = z__4.r + z__5.r, z__3.i = z__4.i + z__5.i;
	    z__6.r = t1zi * dataj_1.ezk.r, z__6.i = t1zi * dataj_1.ezk.i;
	    z__2.r = z__3.r + z__6.r, z__2.i = z__3.i + z__6.i;
	    z__1.r = -z__2.r, z__1.i = -z__2.i;
	    g21.r = z__1.r, g21.i = z__1.i;
	    z__4.r = t1xi * dataj_1.exs.r, z__4.i = t1xi * dataj_1.exs.i;
	    z__5.r = t1yi * dataj_1.eys.r, z__5.i = t1yi * dataj_1.eys.i;
	    z__3.r = z__4.r + z__5.r, z__3.i = z__4.i + z__5.i;
	    z__6.r = t1zi * dataj_1.ezs.r, z__6.i = t1zi * dataj_1.ezs.i;
	    z__2.r = z__3.r + z__6.r, z__2.i = z__3.i + z__6.i;
	    z__1.r = -z__2.r, z__1.i = -z__2.i;
	    g22.r = z__1.r, g22.i = z__1.i;
	    if (i__ != j) {
		goto L1;
	    }
	    z__1.r = g11.r - .5f, z__1.i = g11.i;
	    g11.r = z__1.r, g11.i = z__1.i;
	    z__1.r = g22.r + .5f, z__1.i = g22.i;
	    g22.r = z__1.r, g22.i = z__1.i;
L1:
	    if (*itrp != 0) {
		goto L3;
	    }
/*     NORMAL FILL */
	    if (icomp < *im1) {
		goto L2;
	    }
	    i__3 = ii1 + jj1 * cm_dim1;
	    cm[i__3].r = g11.r, cm[i__3].i = g11.i;
	    i__3 = ii1 + jj2 * cm_dim1;
	    cm[i__3].r = g12.r, cm[i__3].i = g12.i;
L2:
	    if (icomp >= *im2) {
		goto L5;
	    }
	    i__3 = ii2 + jj1 * cm_dim1;
	    cm[i__3].r = g21.r, cm[i__3].i = g21.i;
	    i__3 = ii2 + jj2 * cm_dim1;
	    cm[i__3].r = g22.r, cm[i__3].i = g22.i;
	    goto L5;
/*     TRANSPOSED FILL */
L3:
	    if (icomp < *im1) {
		goto L4;
	    }
	    i__3 = jj1 + ii1 * cm_dim1;
	    cm[i__3].r = g11.r, cm[i__3].i = g11.i;
	    i__3 = jj2 + ii1 * cm_dim1;
	    cm[i__3].r = g12.r, cm[i__3].i = g12.i;
L4:
	    if (icomp >= *im2) {
		goto L5;
	    }
	    i__3 = jj1 + ii2 * cm_dim1;
	    cm[i__3].r = g21.r, cm[i__3].i = g21.i;
	    i__3 = jj2 + ii2 * cm_dim1;
	    cm[i__3].r = g22.r, cm[i__3].i = g22.i;
L5:
	    ;
	}
    }
    return 0;
} /* cmss_ */

#undef t2zj
#undef t2yj
#undef t2xj
#undef t1zj
#undef t1yj
#undef t1xj
#undef t2z
#undef t2y
#undef t2x
#undef t1z
#undef t1y
#undef t1x


/* Subroutine */ int cmsw_(integer *j1, integer *j2, integer *i1, integer *i2,
	 doublecomplex *cm, doublecomplex *cw, integer *ncw, integer *nrow, 
	integer *itrp)
{
    /* Initialized data */

    static doublereal pi = 3.141592654;

    /* System generated locals */
    integer cm_dim1, cm_offset, cw_dim1, cw_offset, i__1, i__2, i__3, i__4, 
	    i__5;
    doublereal d__1;
    doublecomplex z__1, z__2, z__3, z__4, z__5, z__6;

    /* Builtin functions */
    double sin(doublereal), cos(doublereal);

    /* Local variables */
    integer i__, j, k, il, jl;
    doublereal xi, yi, zi;
    integer js, ip;
    doublereal py, px;
#define t1x ((doublereal *)&data_1 + 4500)
#define t1y ((doublereal *)&data_1 + 7500)
#define t1z ((doublereal *)&data_1 + 9000)
#define t2x ((doublereal *)&data_1 + 10501)
#define t2y ((doublereal *)&data_1 + 12001)
#define t2z ((doublereal *)&data_1 + 13501)
#define cab ((doublereal *)&data_1 + 7500)
#define sab ((doublereal *)&data_1 + 9000)
    integer ldp;
#define t1xj ((doublereal *)&dataj_1 + 5)
#define t1yj ((doublereal *)&dataj_1 + 6)
#define t1zj ((doublereal *)&dataj_1 + 7)
#define t2xj ((doublereal *)&dataj_1 + 1)
#define t2yj ((doublereal *)&dataj_1 + 27)
#define t2zj ((doublereal *)&dataj_1 + 28)
    doublereal cabi, sabi;
    doublecomplex emel[9];
    integer icgo, ipch, neqs;
    extern /* Subroutine */ int trio_(integer *);
    doublereal fsign, salpi;
    extern /* Subroutine */ int pcint_(doublereal *, doublereal *, doublereal 
	    *, doublereal *, doublereal *, doublereal *, doublecomplex *), 
	    unere_(doublereal *, doublereal *, doublereal *);

/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* Max number of segments 	(Windows-95 <= 4 */
/* max nr of 'in-core' alloc.	(MAXMAT <= MA */
/* Max number of LD cards */
/* Max number of EX cards */
/* Max number of segs connected to NT/TL */
/* *** */
/*     COMPUTES MATRIX ELEMENTS FOR E ALONG WIRES DUE TO PATCH CURRENT */
    /* Parameter adjustments */
    cw_dim1 = *nrow;
    cw_offset = 1 + cw_dim1;
    cw -= cw_offset;
    cm_dim1 = *nrow;
    cm_offset = 1 + cm_dim1;
    cm -= cm_offset;

    /* Function Body */
    ldp = data_1.ld + 1;
    neqs = data_1.n - data_1.n1 + (data_1.m - data_1.m1 << 1);
    if (*itrp < 0) {
	goto L13;
    }
    k = 0;
    icgo = 1;
/*     OBSERVATION LOOP */
    i__1 = *i2;
    for (i__ = *i1; i__ <= i__1; ++i__) {
	++k;
	xi = data_1.x[i__ - 1];
	yi = data_1.y[i__ - 1];
	zi = data_1.z__[i__ - 1];
	cabi = cab[i__ - 1];
	sabi = sab[i__ - 1];
	salpi = angl_1.salp[i__ - 1];
	ipch = 0;
	if (data_1.icon1[i__ - 1] < 10000) {
	    goto L1;
	}
	ipch = data_1.icon1[i__ - 1] - 10000;
	fsign = -1.f;
L1:
	if (data_1.icon2[i__ - 1] < 10000) {
	    goto L2;
	}
	ipch = data_1.icon2[i__ - 1] - 10000;
	fsign = 1.f;
L2:
	jl = 0;
/*     SOURCE LOOP */
	i__2 = *j2;
	for (j = *j1; j <= i__2; ++j) {
	    js = ldp - j;
	    jl += 2;
	    *t1xj = t1x[js - 1];
	    *t1yj = t1y[js - 1];
	    *t1zj = t1z[js - 1];
	    *t2xj = t2x[js - 1];
	    *t2yj = t2y[js - 1];
	    *t2zj = t2z[js - 1];
	    dataj_1.xj = data_1.x[js - 1];
	    dataj_1.yj = data_1.y[js - 1];
	    dataj_1.zj = data_1.z__[js - 1];
	    dataj_1.s = data_1.bi[js - 1];
/*     GROUND LOOP */
	    i__3 = gnd_1.ksymp;
	    for (ip = 1; ip <= i__3; ++ip) {
		dataj_1.ipgnd = ip;
		if (ipch != j && icgo == 1) {
		    goto L9;
		}
		if (ip == 2) {
		    goto L9;
		}
		if (icgo > 1) {
		    goto L6;
		}
		pcint_(&xi, &yi, &zi, &cabi, &sabi, &salpi, emel);
		py = pi * data_1.si[i__ - 1] * fsign;
		px = sin(py);
		py = cos(py);
		z__1.r = fsign * emel[8].r, z__1.i = fsign * emel[8].i;
		dataj_1.exc.r = z__1.r, dataj_1.exc.i = z__1.i;
		trio_(&i__);
		if (i__ > data_1.n1) {
		    goto L3;
		}
		il = neqs + data_1.iconx[i__ - 1];
		goto L4;
L3:
		il = i__ - *ncw;
		if (i__ <= data_1.np) {
		    il = ((il - 1) / data_1.np << 1) * data_1.mp + il;
		}
L4:
		if (*itrp != 0) {
		    goto L5;
		}
		i__4 = k + il * cw_dim1;
		i__5 = k + il * cw_dim1;
		d__1 = segj_1.ax[segj_1.jsno - 1] + segj_1.bx[segj_1.jsno - 1]
			 * px + segj_1.cx[segj_1.jsno - 1] * py;
		z__2.r = d__1 * dataj_1.exc.r, z__2.i = d__1 * dataj_1.exc.i;
		z__1.r = cw[i__5].r + z__2.r, z__1.i = cw[i__5].i + z__2.i;
		cw[i__4].r = z__1.r, cw[i__4].i = z__1.i;
		goto L6;
L5:
		i__4 = il + k * cw_dim1;
		i__5 = il + k * cw_dim1;
		d__1 = segj_1.ax[segj_1.jsno - 1] + segj_1.bx[segj_1.jsno - 1]
			 * px + segj_1.cx[segj_1.jsno - 1] * py;
		z__2.r = d__1 * dataj_1.exc.r, z__2.i = d__1 * dataj_1.exc.i;
		z__1.r = cw[i__5].r + z__2.r, z__1.i = cw[i__5].i + z__2.i;
		cw[i__4].r = z__1.r, cw[i__4].i = z__1.i;
L6:
		if (*itrp != 0) {
		    goto L7;
		}
		i__4 = k + (jl - 1) * cm_dim1;
		i__5 = icgo - 1;
		cm[i__4].r = emel[i__5].r, cm[i__4].i = emel[i__5].i;
		i__4 = k + jl * cm_dim1;
		i__5 = icgo + 3;
		cm[i__4].r = emel[i__5].r, cm[i__4].i = emel[i__5].i;
		goto L8;
L7:
		i__4 = jl - 1 + k * cm_dim1;
		i__5 = icgo - 1;
		cm[i__4].r = emel[i__5].r, cm[i__4].i = emel[i__5].i;
		i__4 = jl + k * cm_dim1;
		i__5 = icgo + 3;
		cm[i__4].r = emel[i__5].r, cm[i__4].i = emel[i__5].i;
L8:
		++icgo;
		if (icgo == 5) {
		    icgo = 1;
		}
		goto L11;
L9:
		unere_(&xi, &yi, &zi);
		if (*itrp != 0) {
		    goto L10;
		}
/*     NORMAL FILL */
		i__4 = k + (jl - 1) * cm_dim1;
		i__5 = k + (jl - 1) * cm_dim1;
		z__4.r = cabi * dataj_1.exk.r, z__4.i = cabi * dataj_1.exk.i;
		z__3.r = cm[i__5].r + z__4.r, z__3.i = cm[i__5].i + z__4.i;
		z__5.r = sabi * dataj_1.eyk.r, z__5.i = sabi * dataj_1.eyk.i;
		z__2.r = z__3.r + z__5.r, z__2.i = z__3.i + z__5.i;
		z__6.r = salpi * dataj_1.ezk.r, z__6.i = salpi * 
			dataj_1.ezk.i;
		z__1.r = z__2.r + z__6.r, z__1.i = z__2.i + z__6.i;
		cm[i__4].r = z__1.r, cm[i__4].i = z__1.i;
		i__4 = k + jl * cm_dim1;
		i__5 = k + jl * cm_dim1;
		z__4.r = cabi * dataj_1.exs.r, z__4.i = cabi * dataj_1.exs.i;
		z__3.r = cm[i__5].r + z__4.r, z__3.i = cm[i__5].i + z__4.i;
		z__5.r = sabi * dataj_1.eys.r, z__5.i = sabi * dataj_1.eys.i;
		z__2.r = z__3.r + z__5.r, z__2.i = z__3.i + z__5.i;
		z__6.r = salpi * dataj_1.ezs.r, z__6.i = salpi * 
			dataj_1.ezs.i;
		z__1.r = z__2.r + z__6.r, z__1.i = z__2.i + z__6.i;
		cm[i__4].r = z__1.r, cm[i__4].i = z__1.i;
		goto L11;
/*     TRANSPOSED FILL */
L10:
		i__4 = jl - 1 + k * cm_dim1;
		i__5 = jl - 1 + k * cm_dim1;
		z__4.r = cabi * dataj_1.exk.r, z__4.i = cabi * dataj_1.exk.i;
		z__3.r = cm[i__5].r + z__4.r, z__3.i = cm[i__5].i + z__4.i;
		z__5.r = sabi * dataj_1.eyk.r, z__5.i = sabi * dataj_1.eyk.i;
		z__2.r = z__3.r + z__5.r, z__2.i = z__3.i + z__5.i;
		z__6.r = salpi * dataj_1.ezk.r, z__6.i = salpi * 
			dataj_1.ezk.i;
		z__1.r = z__2.r + z__6.r, z__1.i = z__2.i + z__6.i;
		cm[i__4].r = z__1.r, cm[i__4].i = z__1.i;
		i__4 = jl + k * cm_dim1;
		i__5 = jl + k * cm_dim1;
		z__4.r = cabi * dataj_1.exs.r, z__4.i = cabi * dataj_1.exs.i;
		z__3.r = cm[i__5].r + z__4.r, z__3.i = cm[i__5].i + z__4.i;
		z__5.r = sabi * dataj_1.eys.r, z__5.i = sabi * dataj_1.eys.i;
		z__2.r = z__3.r + z__5.r, z__2.i = z__3.i + z__5.i;
		z__6.r = salpi * dataj_1.ezs.r, z__6.i = salpi * 
			dataj_1.ezs.i;
		z__1.r = z__2.r + z__6.r, z__1.i = z__2.i + z__6.i;
		cm[i__4].r = z__1.r, cm[i__4].i = z__1.i;
L11:
/* L12: */
		;
	    }
	}
    }
    return 0;
/*     FOR OLD SEG. CONNECTING TO OLD PATCH ON ONE END AND NEW SEG. ON */
/*     OTHER END INTEGRATE SINGULAR COMPONENT (9) OF SURFACE CURRENT ONLY */
L13:
    if (*j1 < *i1 || *j1 > *i2) {
	goto L16;
    }
    ipch = data_1.icon1[*j1 - 1];
    if (ipch < 10000) {
	goto L14;
    }
    ipch += -10000;
    fsign = -1.f;
    goto L15;
L14:
    ipch = data_1.icon2[*j1 - 1];
    if (ipch < 10000) {
	goto L16;
    }
    ipch += -10000;
    fsign = 1.f;
L15:
    if (ipch > data_1.m1) {
	goto L16;
    }
    js = ldp - ipch;
    dataj_1.ipgnd = 1;
    *t1xj = t1x[js - 1];
    *t1yj = t1y[js - 1];
    *t1zj = t1z[js - 1];
    *t2xj = t2x[js - 1];
    *t2yj = t2y[js - 1];
    *t2zj = t2z[js - 1];
    dataj_1.xj = data_1.x[js - 1];
    dataj_1.yj = data_1.y[js - 1];
    dataj_1.zj = data_1.z__[js - 1];
    dataj_1.s = data_1.bi[js - 1];
    xi = data_1.x[*j1 - 1];
    yi = data_1.y[*j1 - 1];
    zi = data_1.z__[*j1 - 1];
    cabi = cab[*j1 - 1];
    sabi = sab[*j1 - 1];
    salpi = angl_1.salp[*j1 - 1];
    pcint_(&xi, &yi, &zi, &cabi, &sabi, &salpi, emel);
    py = pi * data_1.si[*j1 - 1] * fsign;
    px = sin(py);
    py = cos(py);
    z__1.r = fsign * emel[8].r, z__1.i = fsign * emel[8].i;
    dataj_1.exc.r = z__1.r, dataj_1.exc.i = z__1.i;
    il = segj_1.jco[segj_1.jsno - 1];
    k = *j1 - *i1 + 1;
    i__3 = k + il * cw_dim1;
    i__2 = k + il * cw_dim1;
    d__1 = segj_1.ax[segj_1.jsno - 1] + segj_1.bx[segj_1.jsno - 1] * px + 
	    segj_1.cx[segj_1.jsno - 1] * py;
    z__2.r = d__1 * dataj_1.exc.r, z__2.i = d__1 * dataj_1.exc.i;
    z__1.r = cw[i__2].r + z__2.r, z__1.i = cw[i__2].i + z__2.i;
    cw[i__3].r = z__1.r, cw[i__3].i = z__1.i;
L16:
    return 0;
} /* cmsw_ */

#undef t2zj
#undef t2yj
#undef t2xj
#undef t1zj
#undef t1yj
#undef t1xj
#undef sab
#undef cab
#undef t2z
#undef t2y
#undef t2x
#undef t1z
#undef t1y
#undef t1x


/* Subroutine */ int cmws_(integer *j, integer *i1, integer *i2, 
	doublecomplex *cm, integer *nr, doublecomplex *cw, integer *nw, 
	integer *itrp)
{
    /* System generated locals */
    integer cm_dim1, cm_offset, cw_dim1, cw_offset, i__1, i__2, i__3, i__4, 
	    i__5, i__6, i__7;
    doublecomplex z__1, z__2, z__3, z__4, z__5, z__6, z__7;

    /* Local variables */
    integer i__, ij, ik, js;
    doublereal xi, yi, zi;
    integer jx;
    doublereal tx, ty, tz;
#define t1x ((doublereal *)&data_1 + 4500)
#define t1y ((doublereal *)&data_1 + 7500)
#define t1z ((doublereal *)&data_1 + 9000)
#define t2x ((doublereal *)&data_1 + 10501)
#define t2y ((doublereal *)&data_1 + 12001)
#define t2z ((doublereal *)&data_1 + 13501)
#define cab ((doublereal *)&data_1 + 7500)
#define sab ((doublereal *)&data_1 + 9000)
    doublecomplex etc;
    integer ldp;
    doublecomplex etk;
    integer ipr;
    doublecomplex ets;
    extern /* Subroutine */ int hsfld_(doublereal *, doublereal *, doublereal 
	    *, doublereal *);
    integer ipatch;

/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* Max number of segments 	(Windows-95 <= 4 */
/* max nr of 'in-core' alloc.	(MAXMAT <= MA */
/* Max number of LD cards */
/* Max number of EX cards */
/* Max number of segs connected to NT/TL */
/* *** */

/*     CMWS COMPUTES MATRIX ELEMENTS FOR WIRE-SURFACE INTERACTIONS */

    /* Parameter adjustments */
    cm_dim1 = *nr;
    cm_offset = 1 + cm_dim1;
    cm -= cm_offset;
    cw_dim1 = *nw;
    cw_offset = 1 + cw_dim1;
    cw -= cw_offset;

    /* Function Body */
    ldp = data_1.ld + 1;
    dataj_1.s = data_1.si[*j - 1];
    dataj_1.b = data_1.bi[*j - 1];
    dataj_1.xj = data_1.x[*j - 1];
    dataj_1.yj = data_1.y[*j - 1];
    dataj_1.zj = data_1.z__[*j - 1];
    dataj_1.cabj = cab[*j - 1];
    dataj_1.sabj = sab[*j - 1];
    dataj_1.salpj = angl_1.salp[*j - 1];

/*     OBSERVATION LOOP */

    ipr = 0;
    i__1 = *i2;
    for (i__ = *i1; i__ <= i__1; ++i__) {
	++ipr;
	ipatch = (i__ + 1) / 2;
	ik = i__ - (i__ / 2 << 1);
	if (ik == 0 && ipr != 1) {
	    goto L1;
	}
	js = ldp - ipatch;
	xi = data_1.x[js - 1];
	yi = data_1.y[js - 1];
	zi = data_1.z__[js - 1];
	hsfld_(&xi, &yi, &zi, &c_b636);
	if (ik == 0) {
	    goto L1;
	}
	tx = t2x[js - 1];
	ty = t2y[js - 1];
	tz = t2z[js - 1];
	goto L2;
L1:
	tx = t1x[js - 1];
	ty = t1y[js - 1];
	tz = t1z[js - 1];
L2:
	z__5.r = tx * dataj_1.exk.r, z__5.i = tx * dataj_1.exk.i;
	z__6.r = ty * dataj_1.eyk.r, z__6.i = ty * dataj_1.eyk.i;
	z__4.r = z__5.r + z__6.r, z__4.i = z__5.i + z__6.i;
	z__7.r = tz * dataj_1.ezk.r, z__7.i = tz * dataj_1.ezk.i;
	z__3.r = z__4.r + z__7.r, z__3.i = z__4.i + z__7.i;
	z__2.r = -z__3.r, z__2.i = -z__3.i;
	i__2 = js - 1;
	z__1.r = angl_1.salp[i__2] * z__2.r, z__1.i = angl_1.salp[i__2] * 
		z__2.i;
	etk.r = z__1.r, etk.i = z__1.i;
	z__5.r = tx * dataj_1.exs.r, z__5.i = tx * dataj_1.exs.i;
	z__6.r = ty * dataj_1.eys.r, z__6.i = ty * dataj_1.eys.i;
	z__4.r = z__5.r + z__6.r, z__4.i = z__5.i + z__6.i;
	z__7.r = tz * dataj_1.ezs.r, z__7.i = tz * dataj_1.ezs.i;
	z__3.r = z__4.r + z__7.r, z__3.i = z__4.i + z__7.i;
	z__2.r = -z__3.r, z__2.i = -z__3.i;
	i__2 = js - 1;
	z__1.r = angl_1.salp[i__2] * z__2.r, z__1.i = angl_1.salp[i__2] * 
		z__2.i;
	ets.r = z__1.r, ets.i = z__1.i;
	z__5.r = tx * dataj_1.exc.r, z__5.i = tx * dataj_1.exc.i;
	z__6.r = ty * dataj_1.eyc.r, z__6.i = ty * dataj_1.eyc.i;
	z__4.r = z__5.r + z__6.r, z__4.i = z__5.i + z__6.i;
	z__7.r = tz * dataj_1.ezc.r, z__7.i = tz * dataj_1.ezc.i;
	z__3.r = z__4.r + z__7.r, z__3.i = z__4.i + z__7.i;
	z__2.r = -z__3.r, z__2.i = -z__3.i;
	i__2 = js - 1;
	z__1.r = angl_1.salp[i__2] * z__2.r, z__1.i = angl_1.salp[i__2] * 
		z__2.i;
	etc.r = z__1.r, etc.i = z__1.i;

/*     FILL MATRIX ELEMENTS.  ELEMENT LOCATIONS DETERMINED BY CONNECTION */
/*     DATA. */

	if (*itrp != 0) {
	    goto L4;
	}
/*     NORMAL FILL */
	i__2 = segj_1.jsno;
	for (ij = 1; ij <= i__2; ++ij) {
	    jx = segj_1.jco[ij - 1];
/* L3: */
	    i__3 = ipr + jx * cm_dim1;
	    i__4 = ipr + jx * cm_dim1;
	    i__5 = ij - 1;
	    z__4.r = segj_1.ax[i__5] * etk.r, z__4.i = segj_1.ax[i__5] * 
		    etk.i;
	    z__3.r = cm[i__4].r + z__4.r, z__3.i = cm[i__4].i + z__4.i;
	    i__6 = ij - 1;
	    z__5.r = segj_1.bx[i__6] * ets.r, z__5.i = segj_1.bx[i__6] * 
		    ets.i;
	    z__2.r = z__3.r + z__5.r, z__2.i = z__3.i + z__5.i;
	    i__7 = ij - 1;
	    z__6.r = segj_1.cx[i__7] * etc.r, z__6.i = segj_1.cx[i__7] * 
		    etc.i;
	    z__1.r = z__2.r + z__6.r, z__1.i = z__2.i + z__6.i;
	    cm[i__3].r = z__1.r, cm[i__3].i = z__1.i;
	}
	goto L9;
L4:
	if (*itrp == 2) {
	    goto L6;
	}
/*     TRANSPOSED FILL */
	i__3 = segj_1.jsno;
	for (ij = 1; ij <= i__3; ++ij) {
	    jx = segj_1.jco[ij - 1];
/* L5: */
	    i__4 = jx + ipr * cm_dim1;
	    i__5 = jx + ipr * cm_dim1;
	    i__6 = ij - 1;
	    z__4.r = segj_1.ax[i__6] * etk.r, z__4.i = segj_1.ax[i__6] * 
		    etk.i;
	    z__3.r = cm[i__5].r + z__4.r, z__3.i = cm[i__5].i + z__4.i;
	    i__7 = ij - 1;
	    z__5.r = segj_1.bx[i__7] * ets.r, z__5.i = segj_1.bx[i__7] * 
		    ets.i;
	    z__2.r = z__3.r + z__5.r, z__2.i = z__3.i + z__5.i;
	    i__2 = ij - 1;
	    z__6.r = segj_1.cx[i__2] * etc.r, z__6.i = segj_1.cx[i__2] * 
		    etc.i;
	    z__1.r = z__2.r + z__6.r, z__1.i = z__2.i + z__6.i;
	    cm[i__4].r = z__1.r, cm[i__4].i = z__1.i;
	}
	goto L9;
/*     TRANSPOSED FILL - C(WS) AND D(WS)PRIME (=CW) */
L6:
	i__4 = segj_1.jsno;
	for (ij = 1; ij <= i__4; ++ij) {
	    jx = segj_1.jco[ij - 1];
	    if (jx > *nr) {
		goto L7;
	    }
	    i__5 = jx + ipr * cm_dim1;
	    i__6 = jx + ipr * cm_dim1;
	    i__7 = ij - 1;
	    z__4.r = segj_1.ax[i__7] * etk.r, z__4.i = segj_1.ax[i__7] * 
		    etk.i;
	    z__3.r = cm[i__6].r + z__4.r, z__3.i = cm[i__6].i + z__4.i;
	    i__2 = ij - 1;
	    z__5.r = segj_1.bx[i__2] * ets.r, z__5.i = segj_1.bx[i__2] * 
		    ets.i;
	    z__2.r = z__3.r + z__5.r, z__2.i = z__3.i + z__5.i;
	    i__3 = ij - 1;
	    z__6.r = segj_1.cx[i__3] * etc.r, z__6.i = segj_1.cx[i__3] * 
		    etc.i;
	    z__1.r = z__2.r + z__6.r, z__1.i = z__2.i + z__6.i;
	    cm[i__5].r = z__1.r, cm[i__5].i = z__1.i;
	    goto L8;
L7:
	    jx -= *nr;
	    i__5 = jx + ipr * cw_dim1;
	    i__6 = jx + ipr * cw_dim1;
	    i__7 = ij - 1;
	    z__4.r = segj_1.ax[i__7] * etk.r, z__4.i = segj_1.ax[i__7] * 
		    etk.i;
	    z__3.r = cw[i__6].r + z__4.r, z__3.i = cw[i__6].i + z__4.i;
	    i__2 = ij - 1;
	    z__5.r = segj_1.bx[i__2] * ets.r, z__5.i = segj_1.bx[i__2] * 
		    ets.i;
	    z__2.r = z__3.r + z__5.r, z__2.i = z__3.i + z__5.i;
	    i__3 = ij - 1;
	    z__6.r = segj_1.cx[i__3] * etc.r, z__6.i = segj_1.cx[i__3] * 
		    etc.i;
	    z__1.r = z__2.r + z__6.r, z__1.i = z__2.i + z__6.i;
	    cw[i__5].r = z__1.r, cw[i__5].i = z__1.i;
L8:
	    ;
	}
L9:
	;
    }
    return 0;
} /* cmws_ */

#undef sab
#undef cab
#undef t2z
#undef t2y
#undef t2x
#undef t1z
#undef t1y
#undef t1x


/* Subroutine */ int cmww_(integer *j, integer *i1, integer *i2, 
	doublecomplex *cm, integer *nr, doublecomplex *cw, integer *nw, 
	integer *itrp)
{
    /* System generated locals */
    integer cm_dim1, cm_offset, cw_dim1, cw_offset, i__1, i__2, i__3, i__4, 
	    i__5, i__6, i__7;
    doublereal d__1;
    doublecomplex z__1, z__2, z__3, z__4, z__5, z__6;

    /* Local variables */
    integer i__;
    doublereal ai;
    integer ij;
    doublereal xi, yi, zi;
    integer jx;
#define cab ((doublereal *)&data_1 + 7500)
#define sab ((doublereal *)&data_1 + 9000)
    doublecomplex etc, etk;
    integer ipr;
    doublecomplex ets;
    doublereal cabi;
    extern /* Subroutine */ int efld_(doublereal *, doublereal *, doublereal *
	    , doublereal *, integer *);
    doublereal sabi, salpi;

/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* Max number of segments 	(Windows-95 <= 4 */
/* max nr of 'in-core' alloc.	(MAXMAT <= MA */
/* Max number of LD cards */
/* Max number of EX cards */
/* Max number of segs connected to NT/TL */
/* *** */

/*     CMWW COMPUTES MATRIX ELEMENTS FOR WIRE-WIRE INTERACTIONS */

/*     SET SOURCE SEGMENT PARAMETERS */
    /* Parameter adjustments */
    cm_dim1 = *nr;
    cm_offset = 1 + cm_dim1;
    cm -= cm_offset;
    cw_dim1 = *nw;
    cw_offset = 1 + cw_dim1;
    cw -= cw_offset;

    /* Function Body */
    dataj_1.s = data_1.si[*j - 1];
    dataj_1.b = data_1.bi[*j - 1];
    dataj_1.xj = data_1.x[*j - 1];
    dataj_1.yj = data_1.y[*j - 1];
    dataj_1.zj = data_1.z__[*j - 1];
    dataj_1.cabj = cab[*j - 1];
    dataj_1.sabj = sab[*j - 1];
    dataj_1.salpj = angl_1.salp[*j - 1];
    if (dataj_1.iexk == 0) {
	goto L16;
    }
/*     DECIDE WETHER EXT. T.W. APPROX. CAN BE USED */
    ipr = data_1.icon1[*j - 1];
    if (ipr < 0) {
	goto L1;
    } else if (ipr == 0) {
	goto L6;
    } else {
	goto L2;
    }
L1:
    ipr = -ipr;
    if (-data_1.icon1[ipr - 1] != *j) {
	goto L7;
    }
    goto L4;
L2:
    if (ipr != *j) {
	goto L3;
    }
    if (dataj_1.cabj * dataj_1.cabj + dataj_1.sabj * dataj_1.sabj > 1e-8) {
	goto L7;
    }
    goto L5;
L3:
    if (data_1.icon2[ipr - 1] != *j) {
	goto L7;
    }
L4:
    xi = (d__1 = dataj_1.cabj * cab[ipr - 1] + dataj_1.sabj * sab[ipr - 1] + 
	    dataj_1.salpj * angl_1.salp[ipr - 1], abs(d__1));
    if (xi < .999999) {
	goto L7;
    }
    if ((d__1 = data_1.bi[ipr - 1] / dataj_1.b - 1.f, abs(d__1)) > 1e-6) {
	goto L7;
    }
L5:
    dataj_1.ind1 = 0;
    goto L8;
L6:
    dataj_1.ind1 = 1;
    goto L8;
L7:
    dataj_1.ind1 = 2;
L8:
    ipr = data_1.icon2[*j - 1];
    if (ipr < 0) {
	goto L9;
    } else if (ipr == 0) {
	goto L14;
    } else {
	goto L10;
    }
L9:
    ipr = -ipr;
    if (-data_1.icon2[ipr - 1] != *j) {
	goto L15;
    }
    goto L12;
L10:
    if (ipr != *j) {
	goto L11;
    }
    if (dataj_1.cabj * dataj_1.cabj + dataj_1.sabj * dataj_1.sabj > 1e-8) {
	goto L15;
    }
    goto L13;
L11:
    if (data_1.icon1[ipr - 1] != *j) {
	goto L15;
    }
L12:
    xi = (d__1 = dataj_1.cabj * cab[ipr - 1] + dataj_1.sabj * sab[ipr - 1] + 
	    dataj_1.salpj * angl_1.salp[ipr - 1], abs(d__1));
    if (xi < .999999) {
	goto L15;
    }
    if ((d__1 = data_1.bi[ipr - 1] / dataj_1.b - 1.f, abs(d__1)) > 1e-6) {
	goto L15;
    }
L13:
    dataj_1.ind2 = 0;
    goto L16;
L14:
    dataj_1.ind2 = 1;
    goto L16;
L15:
    dataj_1.ind2 = 2;
L16:

/*     OBSERVATION LOOP */

    ipr = 0;
    i__1 = *i2;
    for (i__ = *i1; i__ <= i__1; ++i__) {
	++ipr;
	ij = i__ - *j;
	xi = data_1.x[i__ - 1];
	yi = data_1.y[i__ - 1];
	zi = data_1.z__[i__ - 1];
	ai = data_1.bi[i__ - 1];
	cabi = cab[i__ - 1];
	sabi = sab[i__ - 1];
	salpi = angl_1.salp[i__ - 1];
	efld_(&xi, &yi, &zi, &ai, &ij);
	z__3.r = cabi * dataj_1.exk.r, z__3.i = cabi * dataj_1.exk.i;
	z__4.r = sabi * dataj_1.eyk.r, z__4.i = sabi * dataj_1.eyk.i;
	z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
	z__5.r = salpi * dataj_1.ezk.r, z__5.i = salpi * dataj_1.ezk.i;
	z__1.r = z__2.r + z__5.r, z__1.i = z__2.i + z__5.i;
	etk.r = z__1.r, etk.i = z__1.i;
	z__3.r = cabi * dataj_1.exs.r, z__3.i = cabi * dataj_1.exs.i;
	z__4.r = sabi * dataj_1.eys.r, z__4.i = sabi * dataj_1.eys.i;
	z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
	z__5.r = salpi * dataj_1.ezs.r, z__5.i = salpi * dataj_1.ezs.i;
	z__1.r = z__2.r + z__5.r, z__1.i = z__2.i + z__5.i;
	ets.r = z__1.r, ets.i = z__1.i;
	z__3.r = cabi * dataj_1.exc.r, z__3.i = cabi * dataj_1.exc.i;
	z__4.r = sabi * dataj_1.eyc.r, z__4.i = sabi * dataj_1.eyc.i;
	z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
	z__5.r = salpi * dataj_1.ezc.r, z__5.i = salpi * dataj_1.ezc.i;
	z__1.r = z__2.r + z__5.r, z__1.i = z__2.i + z__5.i;
	etc.r = z__1.r, etc.i = z__1.i;

/*     FILL MATRIX ELEMENTS.  ELEMENT LOCATIONS DETERMINED BY CONNECTION */
/*     DATA. */

	if (*itrp != 0) {
	    goto L18;
	}
/*     NORMAL FILL */
	i__2 = segj_1.jsno;
	for (ij = 1; ij <= i__2; ++ij) {
	    jx = segj_1.jco[ij - 1];
/* L17: */
	    i__3 = ipr + jx * cm_dim1;
	    i__4 = ipr + jx * cm_dim1;
	    i__5 = ij - 1;
	    z__4.r = segj_1.ax[i__5] * etk.r, z__4.i = segj_1.ax[i__5] * 
		    etk.i;
	    z__3.r = cm[i__4].r + z__4.r, z__3.i = cm[i__4].i + z__4.i;
	    i__6 = ij - 1;
	    z__5.r = segj_1.bx[i__6] * ets.r, z__5.i = segj_1.bx[i__6] * 
		    ets.i;
	    z__2.r = z__3.r + z__5.r, z__2.i = z__3.i + z__5.i;
	    i__7 = ij - 1;
	    z__6.r = segj_1.cx[i__7] * etc.r, z__6.i = segj_1.cx[i__7] * 
		    etc.i;
	    z__1.r = z__2.r + z__6.r, z__1.i = z__2.i + z__6.i;
	    cm[i__3].r = z__1.r, cm[i__3].i = z__1.i;
	}
	goto L23;
L18:
	if (*itrp == 2) {
	    goto L20;
	}
/*     TRANSPOSED FILL */
	i__3 = segj_1.jsno;
	for (ij = 1; ij <= i__3; ++ij) {
	    jx = segj_1.jco[ij - 1];
/* L19: */
	    i__4 = jx + ipr * cm_dim1;
	    i__5 = jx + ipr * cm_dim1;
	    i__6 = ij - 1;
	    z__4.r = segj_1.ax[i__6] * etk.r, z__4.i = segj_1.ax[i__6] * 
		    etk.i;
	    z__3.r = cm[i__5].r + z__4.r, z__3.i = cm[i__5].i + z__4.i;
	    i__7 = ij - 1;
	    z__5.r = segj_1.bx[i__7] * ets.r, z__5.i = segj_1.bx[i__7] * 
		    ets.i;
	    z__2.r = z__3.r + z__5.r, z__2.i = z__3.i + z__5.i;
	    i__2 = ij - 1;
	    z__6.r = segj_1.cx[i__2] * etc.r, z__6.i = segj_1.cx[i__2] * 
		    etc.i;
	    z__1.r = z__2.r + z__6.r, z__1.i = z__2.i + z__6.i;
	    cm[i__4].r = z__1.r, cm[i__4].i = z__1.i;
	}
	goto L23;
/*     TRANS. FILL FOR C(WW) - TEST FOR ELEMENTS FOR D(WW)PRIME.  (=CW) */
L20:
	i__4 = segj_1.jsno;
	for (ij = 1; ij <= i__4; ++ij) {
	    jx = segj_1.jco[ij - 1];
	    if (jx > *nr) {
		goto L21;
	    }
	    i__5 = jx + ipr * cm_dim1;
	    i__6 = jx + ipr * cm_dim1;
	    i__7 = ij - 1;
	    z__4.r = segj_1.ax[i__7] * etk.r, z__4.i = segj_1.ax[i__7] * 
		    etk.i;
	    z__3.r = cm[i__6].r + z__4.r, z__3.i = cm[i__6].i + z__4.i;
	    i__2 = ij - 1;
	    z__5.r = segj_1.bx[i__2] * ets.r, z__5.i = segj_1.bx[i__2] * 
		    ets.i;
	    z__2.r = z__3.r + z__5.r, z__2.i = z__3.i + z__5.i;
	    i__3 = ij - 1;
	    z__6.r = segj_1.cx[i__3] * etc.r, z__6.i = segj_1.cx[i__3] * 
		    etc.i;
	    z__1.r = z__2.r + z__6.r, z__1.i = z__2.i + z__6.i;
	    cm[i__5].r = z__1.r, cm[i__5].i = z__1.i;
	    goto L22;
L21:
	    jx -= *nr;
	    i__5 = jx + ipr * cw_dim1;
	    i__6 = jx + ipr * cw_dim1;
	    i__7 = ij - 1;
	    z__4.r = segj_1.ax[i__7] * etk.r, z__4.i = segj_1.ax[i__7] * 
		    etk.i;
	    z__3.r = cw[i__6].r + z__4.r, z__3.i = cw[i__6].i + z__4.i;
	    i__2 = ij - 1;
	    z__5.r = segj_1.bx[i__2] * ets.r, z__5.i = segj_1.bx[i__2] * 
		    ets.i;
	    z__2.r = z__3.r + z__5.r, z__2.i = z__3.i + z__5.i;
	    i__3 = ij - 1;
	    z__6.r = segj_1.cx[i__3] * etc.r, z__6.i = segj_1.cx[i__3] * 
		    etc.i;
	    z__1.r = z__2.r + z__6.r, z__1.i = z__2.i + z__6.i;
	    cw[i__5].r = z__1.r, cw[i__5].i = z__1.i;
L22:
	    ;
	}
L23:
	;
    }
    return 0;
} /* cmww_ */

#undef sab
#undef cab


/* Subroutine */ int conect_(integer *ignd)
{
    /* Initialized data */

    static integer jmax = 30;
    static doublereal smin = .001;
    static integer npmax = 10;

    /* Format strings */
    static char fmt_54[] = "(/,3x,\002GROUND PLANE SPECIFIED.\002)";
    static char fmt_55[] = "(/,3x,\002WHERE WIRE ENDS TOUCH GROUND, CURRENT "
	    "WILL BE \002,\002INTERPOLATED TO IMAGE IN GROUND PLANE.\002,/)";
    static char fmt_56[] = "(\002 GEOMETRY DATA ERROR-- SEGMENT\002,i5,\002 "
	    "EXTENDS BELOW GROUND\002)";
    static char fmt_57[] = "(\002 GEOMETRY DATA ERROR--SEGMENT\002,i5,\002 L"
	    "IES IN GROUND \002,\002PLANE.\002)";
    static char fmt_62[] = "(\002 ERROR - NO. NEW SEGMENTS CONNECTED TO N.G."
	    "F. SEGMENTS \002,\002OR PATCHES EXCEEDS LIMIT OF\002,i5)";
    static char fmt_58[] = "(/,3x,\002TOTAL SEGMENTS USED=\002,i5,5x,\002NO."
	    " SEG. IN \002,\002A SYMMETRIC CELL=\002,i5,5x,\002SYMMETRY FLAG"
	    "=\002,i3)";
    static char fmt_61[] = "(3x,\002TOTAL PATCHES USED=\002,i5,6x,\002NO. PA"
	    "TCHES IN A SYMMETRIC CELL=\002,i5)";
    static char fmt_59[] = "(\002 STRUCTURE HAS\002,i4,\002 FOLD ROTATIONAL "
	    "SYMMETRY\002,/)";
    static char fmt_60[] = "(\002 STRUCTURE HAS\002,i2,\002 PLANES OF SYMMET"
	    "RY\002,/)";
    static char fmt_50[] = "(//,9x,\002- MULTIPLE WIRE JUNCTIONS -\002,/,1x"
	    ",\002JUNCTION\002,4x,\002SEGMENTS  (- FOR END 1, + FOR END 2)"
	    "\002)";
    static char fmt_51[] = "(1x,i5,5x,20i5,/,(11x,20i5))";
    static char fmt_52[] = "(2x,\002NONE\002)";
    static char fmt_53[] = "(\002 CONNECT - SEGMENT CONNECTION ERROR FOR SEG"
	    "MENT\002,i5)";

    /* System generated locals */
    integer i__1, i__2, i__3;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);
    double sqrt(doublereal);
    integer do_fio(integer *, char *, ftnlen);

    /* Local variables */
    integer i__, j;
#define x2 ((doublereal *)&data_1 + 4500)
#define y2 ((doublereal *)&data_1 + 7500)
#define z2 ((doublereal *)&data_1 + 9000)
    integer ic;
    doublereal xa, ya;
    integer ix;
    doublereal za, xs, ys, zs, xi1, yi1, zi1, xi2, yi2, zi2, sep;
    integer iend, jend, iseg;
    doublereal slen;
    integer nsflg;
    extern /* Subroutine */ int subph_(integer *, integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *);

    /* Fortran I/O blocks */
    static cilist io___610 = { 0, 3, 0, fmt_54, 0 };
    static cilist io___611 = { 0, 3, 0, fmt_55, 0 };
    static cilist io___620 = { 0, 3, 0, fmt_56, 0 };
    static cilist io___624 = { 0, 3, 0, fmt_56, 0 };
    static cilist io___625 = { 0, 3, 0, fmt_57, 0 };
    static cilist io___634 = { 0, 3, 0, fmt_62, 0 };
    static cilist io___635 = { 0, 3, 0, fmt_58, 0 };
    static cilist io___636 = { 0, 3, 0, fmt_61, 0 };
    static cilist io___637 = { 0, 3, 0, fmt_59, 0 };
    static cilist io___638 = { 0, 3, 0, fmt_60, 0 };
    static cilist io___639 = { 0, 3, 0, fmt_50, 0 };
    static cilist io___643 = { 0, 3, 0, fmt_62, 0 };
    static cilist io___644 = { 0, 3, 0, fmt_51, 0 };
    static cilist io___645 = { 0, 3, 0, fmt_52, 0 };
    static cilist io___646 = { 0, 3, 0, fmt_53, 0 };


/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* Max number of segments 	(Windows-95 <= 4 */
/* max nr of 'in-core' alloc.	(MAXMAT <= MA */
/* Max number of LD cards */
/* Max number of EX cards */
/* Max number of segs connected to NT/TL */
/* *** */

/*     CONNECT SETS UP SEGMENT CONNECTION DATA IN ARRAYS ICON1 AND ICON2 */
/*     BY SEARCHING FOR SEGMENT ENDS THAT ARE IN CONTACT. */

/* av07 DATA JMAX/30/,SMIN/1.D-3/,NSMAX/50/,NPMAX/10/ */
    segj_1.nscon = 0;
    segj_1.npcon = 0;
    if (*ignd == 0) {
	goto L3;
    }
    s_wsfe(&io___610);
    e_wsfe();
    if (*ignd > 0) {
	s_wsfe(&io___611);
	e_wsfe();
    }
    if (data_1.ipsym != 2) {
	goto L1;
    }
    data_1.np <<= 1;
    data_1.mp <<= 1;
L1:
    if (abs(data_1.ipsym) <= 2) {
	goto L2;
    }
    data_1.np = data_1.n;
    data_1.mp = data_1.m;
L2:
    if (data_1.np > data_1.n) {
	s_stop("", (ftnlen)0);
    }
    if (data_1.np == data_1.n && data_1.mp == data_1.m) {
	data_1.ipsym = 0;
    }
L3:
    if (data_1.n == 0) {
	goto L26;
    }
    i__1 = data_1.n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	data_1.iconx[i__ - 1] = 0;
	xi1 = data_1.x[i__ - 1];
	yi1 = data_1.y[i__ - 1];
	zi1 = data_1.z__[i__ - 1];
	xi2 = x2[i__ - 1];
	yi2 = y2[i__ - 1];
	zi2 = z2[i__ - 1];
/* Computing 2nd power */
	d__1 = xi2 - xi1;
/* Computing 2nd power */
	d__2 = yi2 - yi1;
/* Computing 2nd power */
	d__3 = zi2 - zi1;
	slen = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3) * smin;

/*     DETERMINE CONNECTION DATA FOR END 1 OF SEGMENT. */

	if (*ignd < 1) {
	    goto L5;
	}
	if (zi1 > -slen) {
	    goto L4;
	}
	s_wsfe(&io___620);
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	e_wsfe();
	s_stop("", (ftnlen)0);
L4:
	if (zi1 > slen) {
	    goto L5;
	}
	data_1.icon1[i__ - 1] = i__;
	data_1.z__[i__ - 1] = 0.f;
	goto L9;
L5:
	ic = i__;
	i__2 = data_1.n;
	for (j = 2; j <= i__2; ++j) {
	    ++ic;
	    if (ic > data_1.n) {
		ic = 1;
	    }
	    sep = (d__1 = xi1 - data_1.x[ic - 1], abs(d__1)) + (d__2 = yi1 - 
		    data_1.y[ic - 1], abs(d__2)) + (d__3 = zi1 - data_1.z__[
		    ic - 1], abs(d__3));
	    if (sep > slen) {
		goto L6;
	    }
	    data_1.icon1[i__ - 1] = -ic;
	    goto L8;
L6:
	    sep = (d__1 = xi1 - x2[ic - 1], abs(d__1)) + (d__2 = yi1 - y2[ic 
		    - 1], abs(d__2)) + (d__3 = zi1 - z2[ic - 1], abs(d__3));
	    if (sep > slen) {
		goto L7;
	    }
	    data_1.icon1[i__ - 1] = ic;
	    goto L8;
L7:
	    ;
	}
	if (i__ < data_1.n2 && data_1.icon1[i__ - 1] > 10000) {
	    goto L8;
	}
	data_1.icon1[i__ - 1] = 0;

/*     DETERMINE CONNECTION DATA FOR END 2 OF SEGMENT. */

L8:
	if (*ignd < 1) {
	    goto L12;
	}
L9:
	if (zi2 > -slen) {
	    goto L10;
	}
	s_wsfe(&io___624);
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	e_wsfe();
	s_stop("", (ftnlen)0);
L10:
	if (zi2 > slen) {
	    goto L12;
	}
	if (data_1.icon1[i__ - 1] != i__) {
	    goto L11;
	}
	s_wsfe(&io___625);
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	e_wsfe();
	s_stop("", (ftnlen)0);
L11:
	data_1.icon2[i__ - 1] = i__;
	z2[i__ - 1] = 0.f;
	goto L15;
L12:
	ic = i__;
	i__2 = data_1.n;
	for (j = 2; j <= i__2; ++j) {
	    ++ic;
	    if (ic > data_1.n) {
		ic = 1;
	    }
	    sep = (d__1 = xi2 - data_1.x[ic - 1], abs(d__1)) + (d__2 = yi2 - 
		    data_1.y[ic - 1], abs(d__2)) + (d__3 = zi2 - data_1.z__[
		    ic - 1], abs(d__3));
	    if (sep > slen) {
		goto L13;
	    }
	    data_1.icon2[i__ - 1] = ic;
	    goto L15;
L13:
	    sep = (d__1 = xi2 - x2[ic - 1], abs(d__1)) + (d__2 = yi2 - y2[ic 
		    - 1], abs(d__2)) + (d__3 = zi2 - z2[ic - 1], abs(d__3));
	    if (sep > slen) {
		goto L14;
	    }
	    data_1.icon2[i__ - 1] = -ic;
	    goto L15;
L14:
	    ;
	}
	if (i__ < data_1.n2 && data_1.icon2[i__ - 1] > 10000) {
	    goto L15;
	}
	data_1.icon2[i__ - 1] = 0;
L15:
	;
    }
    if (data_1.m == 0) {
	goto L26;
    }
/*     FIND WIRE-SURFACE CONNECTIONS FOR NEW PATCHES */
    ix = data_1.ld + 1 - data_1.m1;
    i__ = data_1.m2;
L16:
    if (i__ > data_1.m) {
	goto L20;
    }
    --ix;
    xs = data_1.x[ix - 1];
    ys = data_1.y[ix - 1];
    zs = data_1.z__[ix - 1];
    i__1 = data_1.n;
    for (iseg = 1; iseg <= i__1; ++iseg) {
	xi1 = data_1.x[iseg - 1];
	yi1 = data_1.y[iseg - 1];
	zi1 = data_1.z__[iseg - 1];
	xi2 = x2[iseg - 1];
	yi2 = y2[iseg - 1];
	zi2 = z2[iseg - 1];
	slen = ((d__1 = xi2 - xi1, abs(d__1)) + (d__2 = yi2 - yi1, abs(d__2)) 
		+ (d__3 = zi2 - zi1, abs(d__3))) * smin;
/*     FOR FIRST END OF SEGMENT */
	sep = (d__1 = xi1 - xs, abs(d__1)) + (d__2 = yi1 - ys, abs(d__2)) + (
		d__3 = zi1 - zs, abs(d__3));
	if (sep > slen) {
	    goto L17;
	}
/*     CONNECTION - DIVIDE PATCH INTO 4 PATCHES AT PRESENT ARRAY LOC. */
	data_1.icon1[iseg - 1] = i__ + 10000;
	ic = 0;
	subph_(&i__, &ic, &xi1, &yi1, &zi1, &xi2, &yi2, &zi2, &xa, &ya, &za, &
		xs, &ys, &zs);
	goto L19;
L17:
	sep = (d__1 = xi2 - xs, abs(d__1)) + (d__2 = yi2 - ys, abs(d__2)) + (
		d__3 = zi2 - zs, abs(d__3));
	if (sep > slen) {
	    goto L18;
	}
	data_1.icon2[iseg - 1] = i__ + 10000;
	ic = 0;
	subph_(&i__, &ic, &xi1, &yi1, &zi1, &xi2, &yi2, &zi2, &xa, &ya, &za, &
		xs, &ys, &zs);
	goto L19;
L18:
	;
    }
L19:
    ++i__;
    goto L16;
/*     REPEAT SEARCH FOR NEW SEGMENTS CONNECTED TO NGF PATCHES. */
L20:
    if (data_1.m1 == 0 || data_1.n2 > data_1.n) {
	goto L26;
    }
    ix = data_1.ld + 1;
    i__ = 1;
L21:
    if (i__ > data_1.m1) {
	goto L25;
    }
    --ix;
    xs = data_1.x[ix - 1];
    ys = data_1.y[ix - 1];
    zs = data_1.z__[ix - 1];
    i__1 = data_1.n;
    for (iseg = data_1.n2; iseg <= i__1; ++iseg) {
	xi1 = data_1.x[iseg - 1];
	yi1 = data_1.y[iseg - 1];
	zi1 = data_1.z__[iseg - 1];
	xi2 = x2[iseg - 1];
	yi2 = y2[iseg - 1];
	zi2 = z2[iseg - 1];
	slen = ((d__1 = xi2 - xi1, abs(d__1)) + (d__2 = yi2 - yi1, abs(d__2)) 
		+ (d__3 = zi2 - zi1, abs(d__3))) * smin;
	sep = (d__1 = xi1 - xs, abs(d__1)) + (d__2 = yi1 - ys, abs(d__2)) + (
		d__3 = zi1 - zs, abs(d__3));
	if (sep > slen) {
	    goto L22;
	}
	data_1.icon1[iseg - 1] = data_1.m + 10001;
	ic = 1;
	++segj_1.npcon;
	segj_1.ipcon[segj_1.npcon - 1] = i__;
	subph_(&i__, &ic, &xi1, &yi1, &zi1, &xi2, &yi2, &zi2, &xa, &ya, &za, &
		xs, &ys, &zs);
	goto L24;
L22:
	sep = (d__1 = xi2 - xs, abs(d__1)) + (d__2 = yi2 - ys, abs(d__2)) + (
		d__3 = zi2 - zs, abs(d__3));
	if (sep > slen) {
	    goto L23;
	}
	data_1.icon2[iseg - 1] = data_1.m + 10001;
	ic = 1;
	++segj_1.npcon;
	segj_1.ipcon[segj_1.npcon - 1] = i__;
	subph_(&i__, &ic, &xi1, &yi1, &zi1, &xi2, &yi2, &zi2, &xa, &ya, &za, &
		xs, &ys, &zs);
	goto L24;
L23:
	;
    }
L24:
    ++i__;
    goto L21;
L25:
    if (segj_1.npcon <= npmax) {
	goto L26;
    }
    s_wsfe(&io___634);
    do_fio(&c__1, (char *)&npmax, (ftnlen)sizeof(integer));
    e_wsfe();
    s_stop("", (ftnlen)0);
L26:
    s_wsfe(&io___635);
    do_fio(&c__1, (char *)&data_1.n, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&data_1.np, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&data_1.ipsym, (ftnlen)sizeof(integer));
    e_wsfe();
    if (data_1.m > 0) {
	s_wsfe(&io___636);
	do_fio(&c__1, (char *)&data_1.m, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&data_1.mp, (ftnlen)sizeof(integer));
	e_wsfe();
    }
    iseg = (data_1.n + data_1.m) / (data_1.np + data_1.mp);
    if (iseg == 1) {
	goto L30;
    }
    if (data_1.ipsym < 0) {
	goto L28;
    } else if (data_1.ipsym == 0) {
	goto L27;
    } else {
	goto L29;
    }
L27:
    s_stop("", (ftnlen)0);
L28:
    s_wsfe(&io___637);
    do_fio(&c__1, (char *)&iseg, (ftnlen)sizeof(integer));
    e_wsfe();
    goto L30;
L29:
    ic = iseg / 2;
    if (iseg == 8) {
	ic = 3;
    }
    s_wsfe(&io___638);
    do_fio(&c__1, (char *)&ic, (ftnlen)sizeof(integer));
    e_wsfe();
L30:
    if (data_1.n == 0) {
	goto L48;
    }
    s_wsfe(&io___639);
    e_wsfe();
    iseg = 0;
/*     ADJUST CONNECTED SEG. ENDS TO EXACTLY COINCIDE.  PRINT JUNCTIONS */
/*     OF 3 OR MORE SEG.  ALSO FIND OLD SEG. CONNECTING TO NEW SEG. */
    i__1 = data_1.n;
    for (j = 1; j <= i__1; ++j) {
	iend = -1;
	jend = -1;
	ix = data_1.icon1[j - 1];
	ic = 1;
	segj_1.jco[0] = -j;
	xa = data_1.x[j - 1];
	ya = data_1.y[j - 1];
	za = data_1.z__[j - 1];
L31:
	if (ix == 0) {
	    goto L43;
	}
	if (ix == j) {
	    goto L43;
	}
	if (ix > 10000) {
	    goto L43;
	}
	nsflg = 0;
L32:
	if (ix < 0) {
	    goto L33;
	} else if (ix == 0) {
	    goto L49;
	} else {
	    goto L34;
	}
L33:
	ix = -ix;
	goto L35;
L34:
	jend = -jend;
L35:
	if (ix == j) {
	    goto L37;
	}
	if (ix < j) {
	    goto L43;
	}
	++ic;
	if (ic > jmax) {
	    goto L49;
	}
	segj_1.jco[ic - 1] = ix * jend;
	if (ix > data_1.n1) {
	    nsflg = 1;
	}
	if (jend == 1) {
	    goto L36;
	}
	xa += data_1.x[ix - 1];
	ya += data_1.y[ix - 1];
	za += data_1.z__[ix - 1];
	ix = data_1.icon1[ix - 1];
	goto L32;
L36:
	xa += x2[ix - 1];
	ya += y2[ix - 1];
	za += z2[ix - 1];
	ix = data_1.icon2[ix - 1];
	goto L32;
L37:
	sep = (doublereal) ic;
	xa /= sep;
	ya /= sep;
	za /= sep;
	i__2 = ic;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    ix = segj_1.jco[i__ - 1];
	    if (ix > 0) {
		goto L38;
	    }
	    ix = -ix;
	    data_1.x[ix - 1] = xa;
	    data_1.y[ix - 1] = ya;
	    data_1.z__[ix - 1] = za;
	    goto L39;
L38:
	    x2[ix - 1] = xa;
	    y2[ix - 1] = ya;
	    z2[ix - 1] = za;
L39:
	    ;
	}
	if (data_1.n1 == 0) {
	    goto L42;
	}
	if (nsflg == 0) {
	    goto L42;
	}
	i__2 = ic;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    ix = (i__3 = segj_1.jco[i__ - 1], abs(i__3));
	    if (ix > data_1.n1) {
		goto L41;
	    }
	    if (data_1.iconx[ix - 1] != 0) {
		goto L41;
	    }
	    ++segj_1.nscon;
	    if (segj_1.nscon <= 64) {
		goto L40;
	    }
	    s_wsfe(&io___643);
	    do_fio(&c__1, (char *)&c__64, (ftnlen)sizeof(integer));
	    e_wsfe();
	    s_stop("", (ftnlen)0);
L40:
	    segj_1.iscon[segj_1.nscon - 1] = ix;
	    data_1.iconx[ix - 1] = segj_1.nscon;
L41:
	    ;
	}
L42:
	if (ic < 3) {
	    goto L43;
	}
	++iseg;
	s_wsfe(&io___644);
	do_fio(&c__1, (char *)&iseg, (ftnlen)sizeof(integer));
	i__2 = ic;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    do_fio(&c__1, (char *)&segj_1.jco[i__ - 1], (ftnlen)sizeof(
		    integer));
	}
	e_wsfe();
L43:
	if (iend == 1) {
	    goto L44;
	}
	iend = 1;
	jend = 1;
	ix = data_1.icon2[j - 1];
	ic = 1;
	segj_1.jco[0] = j;
	xa = x2[j - 1];
	ya = y2[j - 1];
	za = z2[j - 1];
	goto L31;
L44:
	;
    }
    if (iseg == 0) {
	s_wsfe(&io___645);
	e_wsfe();
    }
    if (data_1.n1 == 0 || data_1.m1 == data_1.m) {
	goto L48;
    }
/*     FIND OLD SEGMENTS THAT CONNECT TO NEW PATCHES */
    i__1 = data_1.n1;
    for (j = 1; j <= i__1; ++j) {
	ix = data_1.icon1[j - 1];
	if (ix < 10000) {
	    goto L45;
	}
	ix += -10000;
	if (ix > data_1.m1) {
	    goto L46;
	}
L45:
	ix = data_1.icon2[j - 1];
	if (ix < 10000) {
	    goto L47;
	}
	ix += -10000;
	if (ix < data_1.m2) {
	    goto L47;
	}
L46:
	if (data_1.iconx[j - 1] != 0) {
	    goto L47;
	}
	++segj_1.nscon;
	segj_1.iscon[segj_1.nscon - 1] = j;
	data_1.iconx[j - 1] = segj_1.nscon;
L47:
	;
    }
L48:
    return 0;
L49:
    s_wsfe(&io___646);
    do_fio(&c__1, (char *)&ix, (ftnlen)sizeof(integer));
    e_wsfe();
    s_stop("", (ftnlen)0);

    return 0;
} /* conect_ */

#undef z2
#undef y2
#undef x2


/* Subroutine */ int couple_(doublecomplex *cur, doublereal *wlam)
{
    /* Format strings */
    static char fmt_6[] = "(///,36x,\002- - - ISOLATION DATA - - -\002,//,"
	    "6x,\002- - COUPLING BETWEEN - -\002,8x,\002MAXIMUM\002,15x,\002-"
	    " - - FOR MAXIMUM COUPLING - - -\002,/,12x,\002SEG.\002,14x,\002S"
	    "EG.\002,3x,\002COUPLING\002,4x,\002LOAD IMPEDANCE (2ND SEG.)\002"
	    ",7x,\002INPUT IMPEDANCE\002,/,2x,\002TAG/SEG.\002,3x,\002NO.\002"
	    ",4x,\002TAG/SEG.\002,3x,\002NO.\002,6x,\002(DB)\002,8x,\002REA"
	    "L\002,9x,\002IMAG.\002,9x,\002REAL\002,9x,\002IMAG.\002)";
    static char fmt_7[] = "(2(1x,i4,1x,i4,1x,i5,2x),f9.3,2x,1p,2(2x,e12.5,1x"
	    ",e12.5))";
    static char fmt_8[] = "(2(1x,i4,1x,i4,1x,i5,2x),\002**ERROR** COUPLING I"
	    "S NOT BETWEEN 0 AND 1. (=\002,1p,e12.5,\002)\002)";

    /* System generated locals */
    integer i__1, i__2, i__3, i__4;
    doublereal d__1;
    doublecomplex z__1, z__2, z__3, z__4, z__5, z__6;

    /* Builtin functions */
    void z_div(doublecomplex *, doublecomplex *, doublecomplex *);
    integer s_wsfe(cilist *), e_wsfe(void);
    double z_abs(doublecomplex *), sqrt(doublereal);
    void d_cnjg(doublecomplex *, doublecomplex *);
    integer do_fio(integer *, char *, ftnlen);

    /* Local variables */
    doublereal c__;
    integer i__, j, k, j1, j2, l1;
    doublecomplex y11, y12, y22, yl, zl;
    extern doublereal db10_(doublereal *);
    doublereal dbc;
    doublecomplex rho, yin, zin;
    integer isg1, isg2, npm1, its1, itt1, itt2, its2;
    doublereal gmax;
    extern integer isegno_(integer *, integer *);

    /* Fortran I/O blocks */
    static cilist io___652 = { 0, 3, 0, fmt_6, 0 };
    static cilist io___672 = { 0, 3, 0, fmt_7, 0 };
    static cilist io___673 = { 0, 3, 0, fmt_8, 0 };


/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* av07 */
/* Max number of segments 	(Windows-95 <= 4 */
/* max nr of 'in-core' alloc.	(MAXMAT <= MA */
/* Max number of LD cards */
/* Max number of EX cards */
/* Max number of segs connected to NT/TL */
/* *** */

/*     COUPLE COMPUTES THE MAXIMUM COUPLING BETWEEN PAIRS OF SEGMENTS. */

/* av07 COMMON /VSORC/ VQD(30),VSANT(30),VQDS(30),IVQD(30),ISANT(30),IQDS( */
/* av07 130),NVQD,NSANT,NQDS */
/* av07 */
    /* Parameter adjustments */
    --cur;

    /* Function Body */
    if (vsorc_1.nsant != 1 || vsorc_1.nvqd != 0) {
	return 0;
    }
    j = isegno_(&yparm_1.nctag[yparm_1.icoup], &yparm_1.ncseg[yparm_1.icoup]);
    if (j != vsorc_1.isant[0]) {
	return 0;
    }
    ++yparm_1.icoup;
    zin.r = vsorc_1.vsant[0].r, zin.i = vsorc_1.vsant[0].i;
    i__1 = yparm_1.icoup - 1;
    i__2 = j;
    z__2.r = *wlam * cur[i__2].r, z__2.i = *wlam * cur[i__2].i;
    z_div(&z__1, &z__2, &zin);
    yparm_1.y11a[i__1].r = z__1.r, yparm_1.y11a[i__1].i = z__1.i;
    l1 = (yparm_1.icoup - 1) * (yparm_1.ncoup - 1);
    i__1 = yparm_1.ncoup;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (i__ == yparm_1.icoup) {
	    goto L1;
	}
	k = isegno_(&yparm_1.nctag[i__ - 1], &yparm_1.ncseg[i__ - 1]);
	++l1;
	i__2 = l1 - 1;
	i__3 = k;
	z__2.r = *wlam * cur[i__3].r, z__2.i = *wlam * cur[i__3].i;
	z_div(&z__1, &z__2, &zin);
	yparm_1.y12a[i__2].r = z__1.r, yparm_1.y12a[i__2].i = z__1.i;
L1:
	;
    }
    if (yparm_1.icoup < yparm_1.ncoup) {
	return 0;
    }
    s_wsfe(&io___652);
    e_wsfe();
    npm1 = yparm_1.ncoup - 1;
    i__1 = npm1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	itt1 = yparm_1.nctag[i__ - 1];
	its1 = yparm_1.ncseg[i__ - 1];
	isg1 = isegno_(&itt1, &its1);
	l1 = i__ + 1;
	i__2 = yparm_1.ncoup;
	for (j = l1; j <= i__2; ++j) {
	    itt2 = yparm_1.nctag[j - 1];
	    its2 = yparm_1.ncseg[j - 1];
	    isg2 = isegno_(&itt2, &its2);
	    j1 = j + (i__ - 1) * npm1 - 1;
	    j2 = i__ + (j - 1) * npm1;
	    i__3 = i__ - 1;
	    y11.r = yparm_1.y11a[i__3].r, y11.i = yparm_1.y11a[i__3].i;
	    i__3 = j - 1;
	    y22.r = yparm_1.y11a[i__3].r, y22.i = yparm_1.y11a[i__3].i;
	    i__3 = j1 - 1;
	    i__4 = j2 - 1;
	    z__2.r = yparm_1.y12a[i__3].r + yparm_1.y12a[i__4].r, z__2.i = 
		    yparm_1.y12a[i__3].i + yparm_1.y12a[i__4].i;
	    z__1.r = z__2.r * .5f, z__1.i = z__2.i * .5f;
	    y12.r = z__1.r, y12.i = z__1.i;
	    z__1.r = y12.r * y12.r - y12.i * y12.i, z__1.i = y12.r * y12.i + 
		    y12.i * y12.r;
	    yin.r = z__1.r, yin.i = z__1.i;
	    dbc = z_abs(&yin);
	    c__ = dbc / (y11.r * 2.f * y22.r - yin.r);
	    if (c__ < 0.f || c__ > 1.f) {
		goto L4;
	    }
	    if (c__ < .01f) {
		goto L2;
	    }
	    gmax = (1.f - sqrt(1.f - c__ * c__)) / c__;
	    goto L3;
L2:
	    gmax = (c__ + c__ * .25f * c__ * c__) * .5f;
L3:
	    d_cnjg(&z__3, &yin);
	    z__2.r = gmax * z__3.r, z__2.i = gmax * z__3.i;
	    z__1.r = z__2.r / dbc, z__1.i = z__2.i / dbc;
	    rho.r = z__1.r, rho.i = z__1.i;
	    z__5.r = 1.f - rho.r, z__5.i = -rho.i;
	    z__6.r = rho.r + 1.f, z__6.i = rho.i;
	    z_div(&z__4, &z__5, &z__6);
	    z__3.r = z__4.r + 1.f, z__3.i = z__4.i;
	    d__1 = y22.r;
	    z__2.r = d__1 * z__3.r, z__2.i = d__1 * z__3.i;
	    z__1.r = z__2.r - y22.r, z__1.i = z__2.i - y22.i;
	    yl.r = z__1.r, yl.i = z__1.i;
	    z_div(&z__1, &c_b245, &yl);
	    zl.r = z__1.r, zl.i = z__1.i;
	    z__3.r = y22.r + yl.r, z__3.i = y22.i + yl.i;
	    z_div(&z__2, &yin, &z__3);
	    z__1.r = y11.r - z__2.r, z__1.i = y11.i - z__2.i;
	    yin.r = z__1.r, yin.i = z__1.i;
	    z_div(&z__1, &c_b245, &yin);
	    zin.r = z__1.r, zin.i = z__1.i;
	    dbc = db10_(&gmax);
	    s_wsfe(&io___672);
	    do_fio(&c__1, (char *)&itt1, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&its1, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&isg1, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&itt2, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&its2, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&isg2, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&dbc, (ftnlen)sizeof(doublereal));
	    do_fio(&c__2, (char *)&zl, (ftnlen)sizeof(doublereal));
	    do_fio(&c__2, (char *)&zin, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	    goto L5;
L4:
	    s_wsfe(&io___673);
	    do_fio(&c__1, (char *)&itt1, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&its1, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&isg1, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&itt2, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&its2, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&isg2, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&c__, (ftnlen)sizeof(doublereal));
	    e_wsfe();
L5:
	    ;
	}
    }
    return 0;

} /* couple_ */

/* Subroutine */ int datagn_(void)
{
    /* Initialized data */

    static char atst[2*13] = "GW" "GX" "GR" "GS" "GE" "GM" "SP" "SM" "GF" 
	    "GA" "SC" "GC" "GH";
    static struct {
	char e_1[8];
	integer e_2;
	} equiv_756 = { "    X   ", 0 };

#define ifx ((integer *)&equiv_756)

    static struct {
	char e_1[8];
	integer e_2;
	} equiv_757 = { "    Y   ", 0 };

#define ify ((integer *)&equiv_757)

    static struct {
	char e_1[8];
	integer e_2;
	} equiv_758 = { "    Z   ", 0 };

#define ifz ((integer *)&equiv_758)

    static doublereal ta = .01745329252;
    static doublereal td = 57.29577951;
    static struct {
	char e_1[16];
	integer e_2;
	} equiv_759 = { "P   R   T   Q   ", 0 };

#define ipt ((integer *)&equiv_759)


    /* Format strings */
    static char fmt_40[] = "(////,33x,\002- - - STRUCTURE SPECIFICATION - "
	    "- -\002,//,37x,\002COORDINATES MUST BE INPUT IN\002,/,37x,\002ME"
	    "TERS OR BE SCALED TO METERS\002,/,37x,\002BEFORE STRUCTURE INPUT"
	    " IS ENDED\002,//)";
    static char fmt_41[] = "(2x,\002WIRE\002,79x,\002NO. OF\002,4x,\002FIRS"
	    "T\002,2x,\002LAST\002,5x,\002TAG\002,/,2x,\002NO.\002,8x,\002X"
	    "1\002,9x,\002Y1\002,9x,\002Z1\002,10x,\002X2\002,9x,\002Y2\002,9"
	    "x,\002Z2\002,6x,\002RADIUS\002,3x,\002SEG.\002,5x,\002SEG.\002,3"
	    "x,\002SEG.\002,5x,\002NO.\002)";
    static char fmt_43[] = "(1x,i5,3f11.5,1x,4f11.5,2x,i5,4x,i5,1x,i5,3x,i5)";
    static char fmt_48[] = "(\002 GEOMETRY DATA CARD ERROR\002)";
    static char fmt_61[] = "(9x,\002ABOVE WIRE IS TAPERED.  SEG. LENGTH RATI"
	    "O =\002,f9.5,/,33x,\002RADIUS FROM\002,f9.5,\002 TO\002,f9.5)";
    static char fmt_38[] = "(1x,i5,2x,\002ARC RADIUS =\002,f9.5,2x,\002FRO"
	    "M\002,f8.3,\002 TO\002,f8.3,\002 DEGREES\002,11x,f11.5,2x,i5,4x,"
	    "i5,1x,i5,3x,i5)";
    static char fmt_124[] = "(5x,\002HELIX STRUCTURE-   AXIAL SPACING BETWEE"
	    "N TURNS =\002,f8.3,\002 TOTAL AXIAL LENGTH =\002,f8.3/1x,i5,2x"
	    ",\002RADIUS OF HELIX =\002,4(2x,f8.3),7x,f11.5,i8,4x,i5,1x,i5,3x"
	    ",i5)";
    static char fmt_51[] = "(1x,i5,a1,f10.5,2f11.5,1x,3f11.5)";
    static char fmt_39[] = "(6x,3f11.5,1x,3f11.5)";
    static char fmt_59[] = "(1x,i5,a1,f10.5,2f11.5,1x,3f11.5,5x,\002SURFAC"
	    "E -\002,i4,\002 BY\002,i3,\002 PATCHES\002)";
    static char fmt_60[] = "(\002 PATCH DATA ERROR\002)";
    static char fmt_44[] = "(6x,\002STRUCTURE REFLECTED ALONG THE AXES\002,3"
	    "(1x,a1),\002.  TAGS INCREMENTED BY\002,i5)";
    static char fmt_45[] = "(6x,\002STRUCTURE ROTATED ABOUT Z-AXIS\002,i3"
	    ",\002 TIMES.  LABELS INCREMENTED BY\002,i5)";
    static char fmt_46[] = "(6x,\002STRUCTURE SCALED BY FACTOR\002,f10.5)";
    static char fmt_47[] = "(6x,\002THE STRUCTURE HAS BEEN MOVED, MOVE DATA "
	    "CARD IS -\002/6x,i3,i5,7f10.5)";
    static char fmt_52[] = "(\002 ERROR - GF MUST BE FIRST GEOMETRY DATA C"
	    "ARD\002)";
    static char fmt_53[] = "(////33x,\002- - - - SEGMENTATION DATA - - - "
	    "-\002,//,40x,\002COORDINATES IN METERS\002,//,25x,\002I+ AND I- "
	    "INDICATE THE SEGMENTS BEFORE AND AFTER I\002,//)";
    static char fmt_54[] = "(2x,\002SEG.\002,3x,\002COORDINATES OF SEG. CENT"
	    "ER\002,5x,\002SEG.\002,5x,\002ORIENTATION ANGLES\002,4x,\002WIR"
	    "E\002,4x,\002CONNECTION DATA\002,3x,\002TAG\002,/,2x,\002NO.\002"
	    ",7x,\002X\002,9x,\002Y\002,9x,\002Z\002,7x,\002LENGTH\002,5x,"
	    "\002ALPHA\002,5x,\002BETA\002,6x,\002RADIUS\002,4x,\002I-\002,3x,"
	    "\002I\002,4x,\002I+\002,4x,\002NO.\002)";
    static char fmt_55[] = "(1x,i5,4f10.5,1x,3f10.5,1x,3i5,2x,i5)";
    static char fmt_56[] = "(\002 SEGMENT DATA ERROR\002)";
    static char fmt_57[] = "(////,44x,\002- - - SURFACE PATCH DATA - - -\002"
	    ",//,49x,\002COORDINATES IN METERS\002,//,1x,\002PATCH\002,5x,"
	    "\002COORD. OF PATCH CENTER\002,7x,\002UNIT NORMAL VECTOR\002,6x"
	    ",\002PATCH\002,12x,\002COMPONENTS OF UNIT TANGENT VECTORS\002,/,"
	    "2x,\002NO.\002,6x,\002X\002,9x,\002Y\002,9x,\002Z\002,9x,\002"
	    "X\002,7x,\002Y\002,7x,\002Z\002,7x,\002AREA\002,7x,\002X1\002,6x,"
	    "\002Y1\002,6x,\002Z1\002,7x,\002X2\002,6x,\002Y2\002,6x,\002Z"
	    "2\002)";
    static char fmt_58[] = "(1x,i4,3f10.5,1x,3f8.4,f10.5,1x,3f8.4,1x,3f8.4)";
    static char fmt_49[] = "(1x,a2,i3,i5,7f10.5)";
    static char fmt_50[] = "(\002 NUMBER OF WIRE SEGMENTS AND SURFACE PATCHE"
	    "S EXCEEDS DIMENSION LIMIT.\002)";

    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2;

    /* Builtin functions */
    integer s_cmp(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), e_wsfe(
	    void), do_fio(integer *, char *, ftnlen);
    /* Subroutine */ int s_stop(char *, ftnlen);
    double pow_dd(doublereal *, doublereal *), sqrt(doublereal), asin(
	    doublereal);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);

    /* Local variables */
    integer i__, j, i1, i2;
#define x2 ((doublereal *)&data_1 + 4500)
#define y2 ((doublereal *)&data_1 + 7500)
#define z2 ((doublereal *)&data_1 + 9000)
    doublereal x4, y4, z4, x3, y3, z3;
    char gm[2];
    integer ns, ix, iy, iz;
    doublereal xs1;
#define t1x ((doublereal *)&data_1 + 4500)
#define t1y ((doublereal *)&data_1 + 7500)
#define t1z ((doublereal *)&data_1 + 9000)
#define t2x ((doublereal *)&data_1 + 10501)
#define t2y ((doublereal *)&data_1 + 12001)
#define t2z ((doublereal *)&data_1 + 13501)
    doublereal xw1, yw1, zw1;
#define cab ((doublereal *)&data_1 + 7500)
    doublereal xw2, yw2, zw2, ys1, zs1, xs2, ys2, zs2;
#define sab ((doublereal *)&data_1 + 9000)
    doublereal rad;
    extern /* Subroutine */ int arc_(integer *, integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *);
    integer itg;
    extern /* Subroutine */ int gfil_(integer *);
    integer iphd, isct;
    extern /* Subroutine */ int wire_(doublereal *, doublereal *, doublereal *
	    , doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *), move_(
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *, integer *);
    extern doublereal atgn2_(doublereal *, doublereal *);
    extern /* Subroutine */ int reflc_(integer *, integer *, integer *, 
	    integer *, integer *), patch_(integer *, integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *), helix_(doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *);
    integer ipsav, nwire, npsav, mpsav;
    doublereal dummy;
    extern /* Subroutine */ int readgm_(integer *, char *, integer *, integer 
	    *, doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, ftnlen), conect_(
	    integer *);

    /* Fortran I/O blocks */
    static cilist io___705 = { 0, 3, 0, fmt_40, 0 };
    static cilist io___706 = { 0, 3, 0, fmt_41, 0 };
    static cilist io___709 = { 0, 3, 0, fmt_43, 0 };
    static cilist io___716 = { 0, 3, 0, fmt_48, 0 };
    static cilist io___717 = { 0, 3, 0, fmt_61, 0 };
    static cilist io___718 = { 0, 3, 0, fmt_38, 0 };
    static cilist io___719 = { 0, 3, 0, fmt_124, 0 };
    static cilist io___720 = { 0, 3, 0, fmt_51, 0 };
    static cilist io___730 = { 0, 3, 0, fmt_51, 0 };
    static cilist io___731 = { 0, 3, 0, fmt_39, 0 };
    static cilist io___732 = { 0, 3, 0, fmt_59, 0 };
    static cilist io___733 = { 0, 3, 0, fmt_39, 0 };
    static cilist io___734 = { 0, 3, 0, fmt_60, 0 };
    static cilist io___736 = { 0, 3, 0, fmt_44, 0 };
    static cilist io___737 = { 0, 3, 0, fmt_45, 0 };
    static cilist io___739 = { 0, 3, 0, fmt_46, 0 };
    static cilist io___740 = { 0, 3, 0, fmt_47, 0 };
    static cilist io___741 = { 0, 3, 0, fmt_52, 0 };
    static cilist io___745 = { 0, 3, 0, fmt_53, 0 };
    static cilist io___746 = { 0, 3, 0, fmt_54, 0 };
    static cilist io___747 = { 0, 3, 0, fmt_55, 0 };
    static cilist io___748 = { 0, 8, 0, 0, 0 };
    static cilist io___749 = { 0, 3, 0, fmt_56, 0 };
    static cilist io___750 = { 0, 3, 0, fmt_57, 0 };
    static cilist io___752 = { 0, 3, 0, fmt_58, 0 };
    static cilist io___753 = { 0, 3, 0, fmt_48, 0 };
    static cilist io___754 = { 0, 3, 0, fmt_49, 0 };
    static cilist io___755 = { 0, 3, 0, fmt_50, 0 };


/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* Max number of segments 	(Windows-95 <= 4 */
/* max nr of 'in-core' alloc.	(MAXMAT <= MA */
/* Max number of LD cards */
/* Max number of EX cards */
/* Max number of segs connected to NT/TL */
/* *** */

/*     DATAGN IS THE MAIN ROUTINE FOR INPUT OF GEOMETRY DATA. */

/* *** */
/* *** */
/* *** */
/* *** */
/* *** */
/* *** */
    data_1.ipsym = 0;
    nwire = 0;
    data_1.n = 0;
    data_1.np = 0;
    data_1.m = 0;
    data_1.mp = 0;
    data_1.n1 = 0;
    data_1.n2 = 1;
    data_1.m1 = 0;
    data_1.m2 = 1;
    isct = 0;
    iphd = 0;

/*     READ GEOMETRY DATA CARD AND BRANCH TO SECTION FOR OPERATION */
/*     REQUESTED */

L1:
    readgm_(&c__2, gm, &itg, &ns, &xw1, &yw1, &zw1, &xw2, &yw2, &zw2, &rad, (
	    ftnlen)2);
    if (data_1.n + data_1.m > data_1.ld) {
	goto L37;
    }
    if (s_cmp(gm, atst + 16, (ftnlen)2, (ftnlen)2) == 0) {
	goto L27;
    }
    if (iphd == 1) {
	goto L2;
    }
    s_wsfe(&io___705);
    e_wsfe();
    s_wsfe(&io___706);
    e_wsfe();
    iphd = 1;
L2:
    if (s_cmp(gm, atst + 20, (ftnlen)2, (ftnlen)2) == 0) {
	goto L10;
    }
    isct = 0;
    if (s_cmp(gm, atst, (ftnlen)2, (ftnlen)2) == 0) {
	goto L3;
    }
    if (s_cmp(gm, atst + 2, (ftnlen)2, (ftnlen)2) == 0) {
	goto L18;
    }
    if (s_cmp(gm, atst + 4, (ftnlen)2, (ftnlen)2) == 0) {
	goto L19;
    }
    if (s_cmp(gm, atst + 6, (ftnlen)2, (ftnlen)2) == 0) {
	goto L21;
    }
    if (s_cmp(gm, atst + 12, (ftnlen)2, (ftnlen)2) == 0) {
	goto L9;
    }
    if (s_cmp(gm, atst + 14, (ftnlen)2, (ftnlen)2) == 0) {
	goto L13;
    }
    if (s_cmp(gm, atst + 8, (ftnlen)2, (ftnlen)2) == 0) {
	goto L29;
    }
    if (s_cmp(gm, atst + 10, (ftnlen)2, (ftnlen)2) == 0) {
	goto L26;
    }
    if (s_cmp(gm, atst + 18, (ftnlen)2, (ftnlen)2) == 0) {
	goto L8;
    }
/* *** */
    if (s_cmp(gm, atst + 24, (ftnlen)2, (ftnlen)2) == 0) {
	goto L123;
    }
/* *** */
    goto L36;

/*     GENERATE SEGMENT DATA FOR STRAIGHT WIRE. */

L3:
    ++nwire;
    i1 = data_1.n + 1;
    i2 = data_1.n + ns;
    s_wsfe(&io___709);
    do_fio(&c__1, (char *)&nwire, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&xw1, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&yw1, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&zw1, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&xw2, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&yw2, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&zw2, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&rad, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&ns, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&i1, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&i2, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&itg, (ftnlen)sizeof(integer));
    e_wsfe();
    if (rad == 0.) {
	goto L4;
    }
    xs1 = 1.f;
    ys1 = 1.f;
    goto L7;
L4:
    readgm_(&c__2, gm, &ix, &iy, &xs1, &ys1, &zs1, &dummy, &dummy, &dummy, &
	    dummy, (ftnlen)2);
/* *** */
    if (s_cmp(gm, atst + 22, (ftnlen)2, (ftnlen)2) == 0) {
	goto L6;
    }
L5:
    s_wsfe(&io___716);
    e_wsfe();
    s_stop("", (ftnlen)0);
L6:
    s_wsfe(&io___717);
    do_fio(&c__1, (char *)&xs1, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&ys1, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&zs1, (ftnlen)sizeof(doublereal));
    e_wsfe();
    if (ys1 == 0. || zs1 == 0.) {
	goto L5;
    }
    rad = ys1;
    d__1 = zs1 / ys1;
    d__2 = (doublereal) (1.f / (ns - 1.f));
    ys1 = pow_dd(&d__1, &d__2);
L7:
    wire_(&xw1, &yw1, &zw1, &xw2, &yw2, &zw2, &rad, &xs1, &ys1, &ns, &itg);
    goto L1;

/*     GENERATE SEGMENT DATA FOR WIRE ARC */

L8:
    ++nwire;
    i1 = data_1.n + 1;
    i2 = data_1.n + ns;
    s_wsfe(&io___718);
    do_fio(&c__1, (char *)&nwire, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&xw1, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&yw1, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&zw1, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&xw2, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&ns, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&i1, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&i2, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&itg, (ftnlen)sizeof(integer));
    e_wsfe();
    arc_(&itg, &ns, &xw1, &yw1, &zw1, &xw2);
    goto L1;
/* *** */

/*     GENERATE HELIX */

L123:
    ++nwire;
    i1 = data_1.n + 1;
    i2 = data_1.n + ns;
    s_wsfe(&io___719);
    do_fio(&c__1, (char *)&xw1, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&yw1, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&nwire, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&zw1, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&xw2, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&yw2, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&zw2, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&rad, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&ns, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&i1, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&i2, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&itg, (ftnlen)sizeof(integer));
    e_wsfe();
    helix_(&xw1, &yw1, &zw1, &xw2, &yw2, &zw2, &rad, &ns, &itg);
    goto L1;

/* *** */

/*     GENERATE SINGLE NEW PATCH */

L9:
    i1 = data_1.m + 1;
    ++ns;
    if (itg != 0) {
	goto L17;
    }
    s_wsfe(&io___720);
    do_fio(&c__1, (char *)&i1, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&ipt[ns - 1], (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&xw1, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&yw1, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&zw1, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&xw2, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&yw2, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&zw2, (ftnlen)sizeof(doublereal));
    e_wsfe();
    if (ns == 2 || ns == 4) {
	isct = 1;
    }
    if (ns > 1) {
	goto L14;
    }
    xw2 *= ta;
    yw2 *= ta;
    goto L16;
L10:
    if (isct == 0) {
	goto L17;
    }
    i1 = data_1.m + 1;
    ++ns;
    if (itg != 0) {
	goto L17;
    }
    if (ns != 2 && ns != 4) {
	goto L17;
    }
    xs1 = x4;
    ys1 = y4;
    zs1 = z4;
    xs2 = x3;
    ys2 = y3;
    zs2 = z3;
    x3 = xw1;
    y3 = yw1;
    z3 = zw1;
    if (ns != 4) {
	goto L11;
    }
    x4 = xw2;
    y4 = yw2;
    z4 = zw2;
L11:
    xw1 = xs1;
    yw1 = ys1;
    zw1 = zs1;
    xw2 = xs2;
    yw2 = ys2;
    zw2 = zs2;
    if (ns == 4) {
	goto L12;
    }
    x4 = xw1 + x3 - xw2;
    y4 = yw1 + y3 - yw2;
    z4 = zw1 + z3 - zw2;
L12:
    s_wsfe(&io___730);
    do_fio(&c__1, (char *)&i1, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&ipt[ns - 1], (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&xw1, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&yw1, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&zw1, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&xw2, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&yw2, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&zw2, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___731);
    do_fio(&c__1, (char *)&x3, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&y3, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&z3, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&x4, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&y4, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&z4, (ftnlen)sizeof(doublereal));
    e_wsfe();
    goto L16;

/*     GENERATE MULTIPLE-PATCH SURFACE */

L13:
    i1 = data_1.m + 1;
    s_wsfe(&io___732);
    do_fio(&c__1, (char *)&i1, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&ipt[1], (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&xw1, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&yw1, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&zw1, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&xw2, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&yw2, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&zw2, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&itg, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&ns, (ftnlen)sizeof(integer));
    e_wsfe();
    if (itg < 1 || ns < 1) {
	goto L17;
    }
L14:
    readgm_(&c__2, gm, &ix, &iy, &x3, &y3, &z3, &x4, &y4, &z4, &dummy, (
	    ftnlen)2);
    if (ns != 2 && itg < 1) {
	goto L15;
    }
    x4 = xw1 + x3 - xw2;
    y4 = yw1 + y3 - yw2;
    z4 = zw1 + z3 - zw2;
L15:
    s_wsfe(&io___733);
    do_fio(&c__1, (char *)&x3, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&y3, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&z3, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&x4, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&y4, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&z4, (ftnlen)sizeof(doublereal));
    e_wsfe();
    if (s_cmp(gm, atst + 20, (ftnlen)2, (ftnlen)2) != 0) {
	goto L17;
    }
L16:
    patch_(&itg, &ns, &xw1, &yw1, &zw1, &xw2, &yw2, &zw2, &x3, &y3, &z3, &x4, 
	    &y4, &z4);
    goto L1;
L17:
    s_wsfe(&io___734);
    e_wsfe();
    s_stop("", (ftnlen)0);

/*     REFLECT STRUCTURE ALONG X,Y, OR Z AXES OR ROTATE TO FORM CYLINDER. */

L18:
    iy = ns / 10;
    iz = ns - iy * 10;
    ix = iy / 10;
    iy -= ix * 10;
    if (ix != 0) {
	ix = 1;
    }
    if (iy != 0) {
	iy = 1;
    }
    if (iz != 0) {
	iz = 1;
    }
    s_wsfe(&io___736);
    do_fio(&c__1, (char *)&ifx[ix], (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&ify[iy], (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&ifz[iz], (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&itg, (ftnlen)sizeof(integer));
    e_wsfe();
    goto L20;
L19:
    s_wsfe(&io___737);
    do_fio(&c__1, (char *)&ns, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&itg, (ftnlen)sizeof(integer));
    e_wsfe();
    ix = -1;
L20:
    reflc_(&ix, &iy, &iz, &itg, &ns);
    goto L1;

/*     SCALE STRUCTURE DIMENSIONS BY FACTOR XW1. */

L21:
    if (data_1.n < data_1.n2) {
	goto L23;
    }
    i__1 = data_1.n;
    for (i__ = data_1.n2; i__ <= i__1; ++i__) {
	data_1.x[i__ - 1] *= xw1;
	data_1.y[i__ - 1] *= xw1;
	data_1.z__[i__ - 1] *= xw1;
	x2[i__ - 1] *= xw1;
	y2[i__ - 1] *= xw1;
	z2[i__ - 1] *= xw1;
/* L22: */
	data_1.bi[i__ - 1] *= xw1;
    }
L23:
    if (data_1.m < data_1.m2) {
	goto L25;
    }
    yw1 = xw1 * xw1;
    ix = data_1.ld + 1 - data_1.m;
    iy = data_1.ld - data_1.m1;
    i__1 = iy;
    for (i__ = ix; i__ <= i__1; ++i__) {
	data_1.x[i__ - 1] *= xw1;
	data_1.y[i__ - 1] *= xw1;
	data_1.z__[i__ - 1] *= xw1;
/* L24: */
	data_1.bi[i__ - 1] *= yw1;
    }
L25:
    s_wsfe(&io___739);
    do_fio(&c__1, (char *)&xw1, (ftnlen)sizeof(doublereal));
    e_wsfe();
    goto L1;

/*     MOVE STRUCTURE OR REPRODUCE ORIGINAL STRUCTURE IN NEW POSITIONS. */

L26:
    s_wsfe(&io___740);
    do_fio(&c__1, (char *)&itg, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&ns, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&xw1, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&yw1, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&zw1, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&xw2, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&yw2, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&zw2, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&rad, (ftnlen)sizeof(doublereal));
    e_wsfe();
    xw1 *= ta;
    yw1 *= ta;
    zw1 *= ta;
    i__1 = (integer) (rad + .5f);
    move_(&xw1, &yw1, &zw1, &xw2, &yw2, &zw2, &i__1, &ns, &itg);
    goto L1;

/*     READ NUMERICAL GREEN'S FUNCTION TAPE */

L27:
    if (data_1.n + data_1.m == 0) {
	goto L28;
    }
    s_wsfe(&io___741);
    e_wsfe();
    s_stop("", (ftnlen)0);
L28:
    gfil_(&itg);
    npsav = data_1.np;
    mpsav = data_1.mp;
    ipsav = data_1.ipsym;
    goto L1;

/*     TERMINATE STRUCTURE GEOMETRY INPUT. */

/* *** */
L29:
    if (ns == 0) {
	goto L290;
    }
    plot_1.iplp1 = 1;
    plot_1.iplp2 = 1;
L290:
    ix = data_1.n1 + data_1.m1;
/* *** */
    if (ix == 0) {
	goto L30;
    }
    data_1.np = data_1.n;
    data_1.mp = data_1.m;
    data_1.ipsym = 0;
L30:
    conect_(&itg);
    if (ix == 0) {
	goto L31;
    }
    data_1.np = npsav;
    data_1.mp = mpsav;
    data_1.ipsym = ipsav;
L31:
    if (data_1.n + data_1.m > data_1.ld) {
	goto L37;
    }
    if (data_1.n == 0) {
	goto L33;
    }
    s_wsfe(&io___745);
    e_wsfe();
    s_wsfe(&io___746);
    e_wsfe();
    i__1 = data_1.n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	xw1 = x2[i__ - 1] - data_1.x[i__ - 1];
	yw1 = y2[i__ - 1] - data_1.y[i__ - 1];
	zw1 = z2[i__ - 1] - data_1.z__[i__ - 1];
	data_1.x[i__ - 1] = (data_1.x[i__ - 1] + x2[i__ - 1]) * .5f;
	data_1.y[i__ - 1] = (data_1.y[i__ - 1] + y2[i__ - 1]) * .5f;
	data_1.z__[i__ - 1] = (data_1.z__[i__ - 1] + z2[i__ - 1]) * .5f;
	xw2 = xw1 * xw1 + yw1 * yw1 + zw1 * zw1;
	yw2 = sqrt(xw2);
	yw2 = (xw2 / yw2 + yw2) * .5f;
	data_1.si[i__ - 1] = yw2;
	cab[i__ - 1] = xw1 / yw2;
	sab[i__ - 1] = yw1 / yw2;
	xw2 = zw1 / yw2;
	if (xw2 > 1.f) {
	    xw2 = 1.f;
	}
	if (xw2 < -1.f) {
	    xw2 = -1.f;
	}
	angl_1.salp[i__ - 1] = xw2;
	xw2 = asin(xw2) * td;
	yw2 = atgn2_(&yw1, &xw1) * td;
	s_wsfe(&io___747);
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&data_1.x[i__ - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&data_1.y[i__ - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&data_1.z__[i__ - 1], (ftnlen)sizeof(doublereal)
		);
	do_fio(&c__1, (char *)&data_1.si[i__ - 1], (ftnlen)sizeof(doublereal))
		;
	do_fio(&c__1, (char *)&xw2, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&yw2, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&data_1.bi[i__ - 1], (ftnlen)sizeof(doublereal))
		;
	do_fio(&c__1, (char *)&data_1.icon1[i__ - 1], (ftnlen)sizeof(integer))
		;
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&data_1.icon2[i__ - 1], (ftnlen)sizeof(integer))
		;
	do_fio(&c__1, (char *)&data_1.itag[i__ - 1], (ftnlen)sizeof(integer));
	e_wsfe();
/* *** */
	if (plot_1.iplp1 != 1) {
	    goto L320;
	}
	s_wsle(&io___748);
	do_lio(&c__5, &c__1, (char *)&data_1.x[i__ - 1], (ftnlen)sizeof(
		doublereal));
	do_lio(&c__5, &c__1, (char *)&data_1.y[i__ - 1], (ftnlen)sizeof(
		doublereal));
	do_lio(&c__5, &c__1, (char *)&data_1.z__[i__ - 1], (ftnlen)sizeof(
		doublereal));
	do_lio(&c__5, &c__1, (char *)&data_1.si[i__ - 1], (ftnlen)sizeof(
		doublereal));
	do_lio(&c__5, &c__1, (char *)&xw2, (ftnlen)sizeof(doublereal));
	do_lio(&c__5, &c__1, (char *)&yw2, (ftnlen)sizeof(doublereal));
	do_lio(&c__5, &c__1, (char *)&data_1.bi[i__ - 1], (ftnlen)sizeof(
		doublereal));
	do_lio(&c__3, &c__1, (char *)&data_1.icon1[i__ - 1], (ftnlen)sizeof(
		integer));
	do_lio(&c__3, &c__1, (char *)&i__, (ftnlen)sizeof(integer));
	do_lio(&c__3, &c__1, (char *)&data_1.icon2[i__ - 1], (ftnlen)sizeof(
		integer));
	e_wsle();
L320:
/* *** */
	if (data_1.si[i__ - 1] > 1e-20 && data_1.bi[i__ - 1] > 0.f) {
	    goto L32;
	}
	s_wsfe(&io___749);
	e_wsfe();
	s_stop("", (ftnlen)0);
L32:
	;
    }
L33:
    if (data_1.m == 0) {
	goto L35;
    }
    s_wsfe(&io___750);
    e_wsfe();
    j = data_1.ld + 1;
    i__1 = data_1.m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	--j;
	xw1 = (t1y[j - 1] * t2z[j - 1] - t1z[j - 1] * t2y[j - 1]) * 
		angl_1.salp[j - 1];
	yw1 = (t1z[j - 1] * t2x[j - 1] - t1x[j - 1] * t2z[j - 1]) * 
		angl_1.salp[j - 1];
	zw1 = (t1x[j - 1] * t2y[j - 1] - t1y[j - 1] * t2x[j - 1]) * 
		angl_1.salp[j - 1];
	s_wsfe(&io___752);
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&data_1.x[j - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&data_1.y[j - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&data_1.z__[j - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&xw1, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&yw1, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&zw1, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&data_1.bi[j - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&t1x[j - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&t1y[j - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&t1z[j - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&t2x[j - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&t2y[j - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&t2z[j - 1], (ftnlen)sizeof(doublereal));
	e_wsfe();
/* L34: */
    }
L35:
    return 0;
L36:
    s_wsfe(&io___753);
    e_wsfe();
    s_wsfe(&io___754);
    do_fio(&c__1, gm, (ftnlen)2);
    do_fio(&c__1, (char *)&itg, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&ns, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&xw1, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&yw1, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&zw1, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&xw2, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&yw2, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&zw2, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&rad, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_stop("", (ftnlen)0);
L37:
    s_wsfe(&io___755);
    e_wsfe();
    s_stop("", (ftnlen)0);

/* L42: */
    return 0;
} /* datagn_ */

#undef sab
#undef cab
#undef t2z
#undef t2y
#undef t2x
#undef t1z
#undef t1y
#undef t1x
#undef z2
#undef y2
#undef x2
#undef ipt
#undef ifz
#undef ify
#undef ifx


doublereal db10_0_(int n__, doublereal *x)
{
    /* System generated locals */
    doublereal ret_val;

    /* Builtin functions */
    double d_lg10(doublereal *);

    /* Local variables */
    doublereal f;

/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* *** */

/*     FUNCTION DB-- RETURNS DB FOR MAGNITUDE (FIELD) OR MAG**2 (POWER) I */

    switch(n__) {
	case 1: goto L_db20;
	}

    f = 10.f;
    goto L1;

L_db20:
    f = 20.f;
L1:
    if (*x < 1e-20) {
	goto L2;
    }
    ret_val = f * d_lg10(x);
    return ret_val;
L2:
    ret_val = -999.99f;
    return ret_val;
} /* db10_ */

doublereal db10_(doublereal *x)
{
    return db10_0_(0, x);
    }

doublereal db20_(doublereal *x)
{
    return db10_0_(1, x);
    }

/* Subroutine */ int efld_(doublereal *xi, doublereal *yi, doublereal *zi, 
	doublereal *ai, integer *ij)
{
    /* Initialized data */

    static doublereal eta = 376.73;
    static doublereal pi = 3.141592654;
    static doublereal tp = 6.283185308;

    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2, d__3;
    doublecomplex z__1, z__2, z__3, z__4, z__5, z__6, z__7, z__8;
    static doublecomplex equiv_8[9];

    /* Builtin functions */
    double sqrt(doublereal), sin(doublereal), cos(doublereal), log(doublereal)
	    ;
    void z_div(doublecomplex *, doublecomplex *, doublecomplex *), z_sqrt(
	    doublecomplex *, doublecomplex *), d_cnjg(doublecomplex *, 
	    doublecomplex *);

    /* Local variables */
    doublereal r__;
    integer ip;
    doublereal rh, zp, px, py, cth, rfl, xij, yij;
    doublecomplex epx, epy;
#define txc (equiv_8 + 6)
#define tyc (equiv_8 + 7)
#define tzc (equiv_8 + 8)
    integer ijx;
    doublereal zij;
#define txk (equiv_8)
#define tyk (equiv_8 + 1)
#define tzk (equiv_8 + 2)
#define txs (equiv_8 + 3)
#define tys (equiv_8 + 4)
#define tzs (equiv_8 + 5)
    extern /* Subroutine */ int rom2_(doublereal *, doublereal *, 
	    doublecomplex *, doublereal *);
#define egnd (equiv_8)
    doublereal shaf;
    extern /* Subroutine */ int eksc_(doublereal *, doublereal *, doublereal *
	    , doublereal *, integer *, doublecomplex *, doublecomplex *, 
	    doublecomplex *, doublecomplex *, doublecomplex *, doublecomplex *
	    );
    doublereal rmag, dmin__;
    doublecomplex terc, refs, tezc, terk, ters, tezk;
    doublereal rhox, rhoy, rhoz;
    doublecomplex tezs;
    extern /* Subroutine */ int sflds_(doublereal *, doublecomplex *), ekscx_(
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *, integer *, integer *, doublecomplex *, 
	    doublecomplex *, doublecomplex *, doublecomplex *, doublecomplex *
	    , doublecomplex *);
    doublecomplex refps;
    doublereal salpr, xspec, yspec, xymag;
    doublecomplex zscrn, zrsin, zratx;
    doublereal rhospc;

/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* *** */

/*     COMPUTE NEAR E FIELDS OF A SEGMENT WITH SINE, COSINE, AND */
/*     CONSTANT CURRENTS.  GROUND EFFECT INCLUDED. */

    xij = *xi - dataj_1.xj;
    yij = *yi - dataj_1.yj;
    ijx = *ij;
    rfl = -1.f;
    i__1 = gnd_1.ksymp;
    for (ip = 1; ip <= i__1; ++ip) {
	if (ip == 2) {
	    ijx = 1;
	}
	rfl = -rfl;
	salpr = dataj_1.salpj * rfl;
	zij = *zi - rfl * dataj_1.zj;
	zp = xij * dataj_1.cabj + yij * dataj_1.sabj + zij * salpr;
	rhox = xij - dataj_1.cabj * zp;
	rhoy = yij - dataj_1.sabj * zp;
	rhoz = zij - salpr * zp;
	rh = sqrt(rhox * rhox + rhoy * rhoy + rhoz * rhoz + *ai * *ai);
	if (rh > 1e-10) {
	    goto L1;
	}
	rhox = 0.f;
	rhoy = 0.f;
	rhoz = 0.f;
	goto L2;
L1:
	rhox /= rh;
	rhoy /= rh;
	rhoz /= rh;
L2:
	r__ = sqrt(zp * zp + rh * rh);
	if (r__ < dataj_1.rkh) {
	    goto L3;
	}

/*     LUMPED CURRENT ELEMENT APPROX. FOR LARGE SEPARATIONS */

	rmag = tp * r__;
	cth = zp / r__;
	px = rh / r__;
	d__1 = cos(rmag);
	d__2 = -sin(rmag);
	z__1.r = d__1, z__1.i = d__2;
	txk->r = z__1.r, txk->i = z__1.i;
	py = tp * r__ * r__;
	d__1 = eta * cth;
	z__3.r = d__1 * txk->r, z__3.i = d__1 * txk->i;
	d__2 = -1. / rmag;
	z__4.r = 1., z__4.i = d__2;
	z__2.r = z__3.r * z__4.r - z__3.i * z__4.i, z__2.i = z__3.r * z__4.i 
		+ z__3.i * z__4.r;
	z__1.r = z__2.r / py, z__1.i = z__2.i / py;
	tyk->r = z__1.r, tyk->i = z__1.i;
	d__1 = eta * px;
	z__3.r = d__1 * txk->r, z__3.i = d__1 * txk->i;
	d__2 = rmag - 1. / rmag;
	z__4.r = 1., z__4.i = d__2;
	z__2.r = z__3.r * z__4.r - z__3.i * z__4.i, z__2.i = z__3.r * z__4.i 
		+ z__3.i * z__4.r;
	d__3 = py * 2.f;
	z__1.r = z__2.r / d__3, z__1.i = z__2.i / d__3;
	tzk->r = z__1.r, tzk->i = z__1.i;
	z__2.r = cth * tyk->r, z__2.i = cth * tyk->i;
	z__3.r = px * tzk->r, z__3.i = px * tzk->i;
	z__1.r = z__2.r - z__3.r, z__1.i = z__2.i - z__3.i;
	tezk.r = z__1.r, tezk.i = z__1.i;
	z__2.r = px * tyk->r, z__2.i = px * tyk->i;
	z__3.r = cth * tzk->r, z__3.i = cth * tzk->i;
	z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
	terk.r = z__1.r, terk.i = z__1.i;
	rmag = sin(pi * dataj_1.s) / pi;
	z__1.r = rmag * tezk.r, z__1.i = rmag * tezk.i;
	tezc.r = z__1.r, tezc.i = z__1.i;
	z__1.r = rmag * terk.r, z__1.i = rmag * terk.i;
	terc.r = z__1.r, terc.i = z__1.i;
	z__1.r = dataj_1.s * tezk.r, z__1.i = dataj_1.s * tezk.i;
	tezk.r = z__1.r, tezk.i = z__1.i;
	z__1.r = dataj_1.s * terk.r, z__1.i = dataj_1.s * terk.i;
	terk.r = z__1.r, terk.i = z__1.i;
	txs->r = 0.f, txs->i = 0.f;
	tys->r = 0.f, tys->i = 0.f;
	tzs->r = 0.f, tzs->i = 0.f;
	goto L6;
L3:
	if (dataj_1.iexk == 1) {
	    goto L4;
	}

/*     EKSC FOR THIN WIRE APPROX. OR EKSCX FOR EXTENDED T.W. APPROX. */

	eksc_(&dataj_1.s, &zp, &rh, &tp, &ijx, &tezs, &ters, &tezc, &terc, &
		tezk, &terk);
	goto L5;
L4:
	ekscx_(&dataj_1.b, &dataj_1.s, &zp, &rh, &tp, &ijx, &dataj_1.ind1, &
		dataj_1.ind2, &tezs, &ters, &tezc, &terc, &tezk, &terk);
L5:
	z__2.r = dataj_1.cabj * tezs.r, z__2.i = dataj_1.cabj * tezs.i;
	z__3.r = rhox * ters.r, z__3.i = rhox * ters.i;
	z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
	txs->r = z__1.r, txs->i = z__1.i;
	z__2.r = dataj_1.sabj * tezs.r, z__2.i = dataj_1.sabj * tezs.i;
	z__3.r = rhoy * ters.r, z__3.i = rhoy * ters.i;
	z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
	tys->r = z__1.r, tys->i = z__1.i;
	z__2.r = salpr * tezs.r, z__2.i = salpr * tezs.i;
	z__3.r = rhoz * ters.r, z__3.i = rhoz * ters.i;
	z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
	tzs->r = z__1.r, tzs->i = z__1.i;
L6:
	z__2.r = dataj_1.cabj * tezk.r, z__2.i = dataj_1.cabj * tezk.i;
	z__3.r = rhox * terk.r, z__3.i = rhox * terk.i;
	z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
	txk->r = z__1.r, txk->i = z__1.i;
	z__2.r = dataj_1.sabj * tezk.r, z__2.i = dataj_1.sabj * tezk.i;
	z__3.r = rhoy * terk.r, z__3.i = rhoy * terk.i;
	z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
	tyk->r = z__1.r, tyk->i = z__1.i;
	z__2.r = salpr * tezk.r, z__2.i = salpr * tezk.i;
	z__3.r = rhoz * terk.r, z__3.i = rhoz * terk.i;
	z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
	tzk->r = z__1.r, tzk->i = z__1.i;
	z__2.r = dataj_1.cabj * tezc.r, z__2.i = dataj_1.cabj * tezc.i;
	z__3.r = rhox * terc.r, z__3.i = rhox * terc.i;
	z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
	txc->r = z__1.r, txc->i = z__1.i;
	z__2.r = dataj_1.sabj * tezc.r, z__2.i = dataj_1.sabj * tezc.i;
	z__3.r = rhoy * terc.r, z__3.i = rhoy * terc.i;
	z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
	tyc->r = z__1.r, tyc->i = z__1.i;
	z__2.r = salpr * tezc.r, z__2.i = salpr * tezc.i;
	z__3.r = rhoz * terc.r, z__3.i = rhoz * terc.i;
	z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
	tzc->r = z__1.r, tzc->i = z__1.i;
	if (ip != 2) {
	    goto L11;
	}
	if (gnd_1.iperf > 0) {
	    goto L10;
	}
	zratx.r = gnd_1.zrati.r, zratx.i = gnd_1.zrati.i;
	rmag = r__;
	xymag = sqrt(xij * xij + yij * yij);

/*     SET PARAMETERS FOR RADIAL WIRE GROUND SCREEN. */

	if (gnd_1.nradl == 0) {
	    goto L7;
	}
	xspec = (*xi * dataj_1.zj + *zi * dataj_1.xj) / (*zi + dataj_1.zj);
	yspec = (*yi * dataj_1.zj + *zi * dataj_1.yj) / (*zi + dataj_1.zj);
	rhospc = sqrt(xspec * xspec + yspec * yspec + gnd_1.t2 * gnd_1.t2);
	if (rhospc > gnd_1.scrwl) {
	    goto L7;
	}
	z__2.r = rhospc * gnd_1.t1.r, z__2.i = rhospc * gnd_1.t1.i;
	d__1 = log(rhospc / gnd_1.t2);
	z__1.r = d__1 * z__2.r, z__1.i = d__1 * z__2.i;
	zscrn.r = z__1.r, zscrn.i = z__1.i;
	z__2.r = zscrn.r * gnd_1.zrati.r - zscrn.i * gnd_1.zrati.i, z__2.i = 
		zscrn.r * gnd_1.zrati.i + zscrn.i * gnd_1.zrati.r;
	z__4.r = eta * gnd_1.zrati.r, z__4.i = eta * gnd_1.zrati.i;
	z__3.r = z__4.r + zscrn.r, z__3.i = z__4.i + zscrn.i;
	z_div(&z__1, &z__2, &z__3);
	zratx.r = z__1.r, zratx.i = z__1.i;
L7:
	if (xymag > 1e-6) {
	    goto L8;
	}

/*     CALCULATION OF REFLECTION COEFFICIENTS WHEN GROUND IS SPECIFIED. */

	px = 0.f;
	py = 0.f;
	cth = 1.f;
	zrsin.r = 1.f, zrsin.i = 0.f;
	goto L9;
L8:
	px = -yij / xymag;
	py = xij / xymag;
	cth = zij / rmag;
	z__4.r = zratx.r * zratx.r - zratx.i * zratx.i, z__4.i = zratx.r * 
		zratx.i + zratx.i * zratx.r;
	d__1 = 1.f - cth * cth;
	z__3.r = d__1 * z__4.r, z__3.i = d__1 * z__4.i;
	z__2.r = 1.f - z__3.r, z__2.i = -z__3.i;
	z_sqrt(&z__1, &z__2);
	zrsin.r = z__1.r, zrsin.i = z__1.i;
L9:
	z__3.r = zratx.r * zrsin.r - zratx.i * zrsin.i, z__3.i = zratx.r * 
		zrsin.i + zratx.i * zrsin.r;
	z__2.r = cth - z__3.r, z__2.i = -z__3.i;
	z__5.r = zratx.r * zrsin.r - zratx.i * zrsin.i, z__5.i = zratx.r * 
		zrsin.i + zratx.i * zrsin.r;
	z__4.r = cth + z__5.r, z__4.i = z__5.i;
	z_div(&z__1, &z__2, &z__4);
	refs.r = z__1.r, refs.i = z__1.i;
	z__4.r = cth * zratx.r, z__4.i = cth * zratx.i;
	z__3.r = z__4.r - zrsin.r, z__3.i = z__4.i - zrsin.i;
	z__2.r = -z__3.r, z__2.i = -z__3.i;
	z__6.r = cth * zratx.r, z__6.i = cth * zratx.i;
	z__5.r = z__6.r + zrsin.r, z__5.i = z__6.i + zrsin.i;
	z_div(&z__1, &z__2, &z__5);
	refps.r = z__1.r, refps.i = z__1.i;
	z__1.r = refps.r - refs.r, z__1.i = refps.i - refs.i;
	refps.r = z__1.r, refps.i = z__1.i;
	z__2.r = px * txk->r, z__2.i = px * txk->i;
	z__3.r = py * tyk->r, z__3.i = py * tyk->i;
	z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
	epy.r = z__1.r, epy.i = z__1.i;
	z__1.r = px * epy.r, z__1.i = px * epy.i;
	epx.r = z__1.r, epx.i = z__1.i;
	z__1.r = py * epy.r, z__1.i = py * epy.i;
	epy.r = z__1.r, epy.i = z__1.i;
	z__2.r = refs.r * txk->r - refs.i * txk->i, z__2.i = refs.r * txk->i 
		+ refs.i * txk->r;
	z__3.r = refps.r * epx.r - refps.i * epx.i, z__3.i = refps.r * epx.i 
		+ refps.i * epx.r;
	z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
	txk->r = z__1.r, txk->i = z__1.i;
	z__2.r = refs.r * tyk->r - refs.i * tyk->i, z__2.i = refs.r * tyk->i 
		+ refs.i * tyk->r;
	z__3.r = refps.r * epy.r - refps.i * epy.i, z__3.i = refps.r * epy.i 
		+ refps.i * epy.r;
	z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
	tyk->r = z__1.r, tyk->i = z__1.i;
	z__1.r = refs.r * tzk->r - refs.i * tzk->i, z__1.i = refs.r * tzk->i 
		+ refs.i * tzk->r;
	tzk->r = z__1.r, tzk->i = z__1.i;
	z__2.r = px * txs->r, z__2.i = px * txs->i;
	z__3.r = py * tys->r, z__3.i = py * tys->i;
	z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
	epy.r = z__1.r, epy.i = z__1.i;
	z__1.r = px * epy.r, z__1.i = px * epy.i;
	epx.r = z__1.r, epx.i = z__1.i;
	z__1.r = py * epy.r, z__1.i = py * epy.i;
	epy.r = z__1.r, epy.i = z__1.i;
	z__2.r = refs.r * txs->r - refs.i * txs->i, z__2.i = refs.r * txs->i 
		+ refs.i * txs->r;
	z__3.r = refps.r * epx.r - refps.i * epx.i, z__3.i = refps.r * epx.i 
		+ refps.i * epx.r;
	z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
	txs->r = z__1.r, txs->i = z__1.i;
	z__2.r = refs.r * tys->r - refs.i * tys->i, z__2.i = refs.r * tys->i 
		+ refs.i * tys->r;
	z__3.r = refps.r * epy.r - refps.i * epy.i, z__3.i = refps.r * epy.i 
		+ refps.i * epy.r;
	z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
	tys->r = z__1.r, tys->i = z__1.i;
	z__1.r = refs.r * tzs->r - refs.i * tzs->i, z__1.i = refs.r * tzs->i 
		+ refs.i * tzs->r;
	tzs->r = z__1.r, tzs->i = z__1.i;
	z__2.r = px * txc->r, z__2.i = px * txc->i;
	z__3.r = py * tyc->r, z__3.i = py * tyc->i;
	z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
	epy.r = z__1.r, epy.i = z__1.i;
	z__1.r = px * epy.r, z__1.i = px * epy.i;
	epx.r = z__1.r, epx.i = z__1.i;
	z__1.r = py * epy.r, z__1.i = py * epy.i;
	epy.r = z__1.r, epy.i = z__1.i;
	z__2.r = refs.r * txc->r - refs.i * txc->i, z__2.i = refs.r * txc->i 
		+ refs.i * txc->r;
	z__3.r = refps.r * epx.r - refps.i * epx.i, z__3.i = refps.r * epx.i 
		+ refps.i * epx.r;
	z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
	txc->r = z__1.r, txc->i = z__1.i;
	z__2.r = refs.r * tyc->r - refs.i * tyc->i, z__2.i = refs.r * tyc->i 
		+ refs.i * tyc->r;
	z__3.r = refps.r * epy.r - refps.i * epy.i, z__3.i = refps.r * epy.i 
		+ refps.i * epy.r;
	z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
	tyc->r = z__1.r, tyc->i = z__1.i;
	z__1.r = refs.r * tzc->r - refs.i * tzc->i, z__1.i = refs.r * tzc->i 
		+ refs.i * tzc->r;
	tzc->r = z__1.r, tzc->i = z__1.i;
L10:
	z__2.r = txk->r * gnd_1.frati.r - txk->i * gnd_1.frati.i, z__2.i = 
		txk->r * gnd_1.frati.i + txk->i * gnd_1.frati.r;
	z__1.r = dataj_1.exk.r - z__2.r, z__1.i = dataj_1.exk.i - z__2.i;
	dataj_1.exk.r = z__1.r, dataj_1.exk.i = z__1.i;
	z__2.r = tyk->r * gnd_1.frati.r - tyk->i * gnd_1.frati.i, z__2.i = 
		tyk->r * gnd_1.frati.i + tyk->i * gnd_1.frati.r;
	z__1.r = dataj_1.eyk.r - z__2.r, z__1.i = dataj_1.eyk.i - z__2.i;
	dataj_1.eyk.r = z__1.r, dataj_1.eyk.i = z__1.i;
	z__2.r = tzk->r * gnd_1.frati.r - tzk->i * gnd_1.frati.i, z__2.i = 
		tzk->r * gnd_1.frati.i + tzk->i * gnd_1.frati.r;
	z__1.r = dataj_1.ezk.r - z__2.r, z__1.i = dataj_1.ezk.i - z__2.i;
	dataj_1.ezk.r = z__1.r, dataj_1.ezk.i = z__1.i;
	z__2.r = txs->r * gnd_1.frati.r - txs->i * gnd_1.frati.i, z__2.i = 
		txs->r * gnd_1.frati.i + txs->i * gnd_1.frati.r;
	z__1.r = dataj_1.exs.r - z__2.r, z__1.i = dataj_1.exs.i - z__2.i;
	dataj_1.exs.r = z__1.r, dataj_1.exs.i = z__1.i;
	z__2.r = tys->r * gnd_1.frati.r - tys->i * gnd_1.frati.i, z__2.i = 
		tys->r * gnd_1.frati.i + tys->i * gnd_1.frati.r;
	z__1.r = dataj_1.eys.r - z__2.r, z__1.i = dataj_1.eys.i - z__2.i;
	dataj_1.eys.r = z__1.r, dataj_1.eys.i = z__1.i;
	z__2.r = tzs->r * gnd_1.frati.r - tzs->i * gnd_1.frati.i, z__2.i = 
		tzs->r * gnd_1.frati.i + tzs->i * gnd_1.frati.r;
	z__1.r = dataj_1.ezs.r - z__2.r, z__1.i = dataj_1.ezs.i - z__2.i;
	dataj_1.ezs.r = z__1.r, dataj_1.ezs.i = z__1.i;
	z__2.r = txc->r * gnd_1.frati.r - txc->i * gnd_1.frati.i, z__2.i = 
		txc->r * gnd_1.frati.i + txc->i * gnd_1.frati.r;
	z__1.r = dataj_1.exc.r - z__2.r, z__1.i = dataj_1.exc.i - z__2.i;
	dataj_1.exc.r = z__1.r, dataj_1.exc.i = z__1.i;
	z__2.r = tyc->r * gnd_1.frati.r - tyc->i * gnd_1.frati.i, z__2.i = 
		tyc->r * gnd_1.frati.i + tyc->i * gnd_1.frati.r;
	z__1.r = dataj_1.eyc.r - z__2.r, z__1.i = dataj_1.eyc.i - z__2.i;
	dataj_1.eyc.r = z__1.r, dataj_1.eyc.i = z__1.i;
	z__2.r = tzc->r * gnd_1.frati.r - tzc->i * gnd_1.frati.i, z__2.i = 
		tzc->r * gnd_1.frati.i + tzc->i * gnd_1.frati.r;
	z__1.r = dataj_1.ezc.r - z__2.r, z__1.i = dataj_1.ezc.i - z__2.i;
	dataj_1.ezc.r = z__1.r, dataj_1.ezc.i = z__1.i;
	goto L12;
L11:
	dataj_1.exk.r = txk->r, dataj_1.exk.i = txk->i;
	dataj_1.eyk.r = tyk->r, dataj_1.eyk.i = tyk->i;
	dataj_1.ezk.r = tzk->r, dataj_1.ezk.i = tzk->i;
	dataj_1.exs.r = txs->r, dataj_1.exs.i = txs->i;
	dataj_1.eys.r = tys->r, dataj_1.eys.i = tys->i;
	dataj_1.ezs.r = tzs->r, dataj_1.ezs.i = tzs->i;
	dataj_1.exc.r = txc->r, dataj_1.exc.i = txc->i;
	dataj_1.eyc.r = tyc->r, dataj_1.eyc.i = tyc->i;
	dataj_1.ezc.r = tzc->r, dataj_1.ezc.i = tzc->i;
L12:
	;
    }
    if (gnd_1.iperf == 2) {
	goto L13;
    }
    return 0;

/*     FIELD DUE TO GROUND USING SOMMERFELD/NORTON */

L13:
    incom_1.sn = sqrt(dataj_1.cabj * dataj_1.cabj + dataj_1.sabj * 
	    dataj_1.sabj);
    if (incom_1.sn < 1e-5) {
	goto L14;
    }
    incom_1.xsn = dataj_1.cabj / incom_1.sn;
    incom_1.ysn = dataj_1.sabj / incom_1.sn;
    goto L15;
L14:
    incom_1.sn = 0.f;
    incom_1.xsn = 1.f;
    incom_1.ysn = 0.f;

/*     DISPLACE OBSERVATION POINT FOR THIN WIRE APPROXIMATION */

L15:
    zij = *zi + dataj_1.zj;
    salpr = -dataj_1.salpj;
    rhox = dataj_1.sabj * zij - salpr * yij;
    rhoy = salpr * xij - dataj_1.cabj * zij;
    rhoz = dataj_1.cabj * yij - dataj_1.sabj * xij;
    rh = rhox * rhox + rhoy * rhoy + rhoz * rhoz;
    if (rh > 1e-10) {
	goto L16;
    }
    incom_1.xo = *xi - *ai * incom_1.ysn;
    incom_1.yo = *yi + *ai * incom_1.xsn;
    incom_1.zo = *zi;
    goto L17;
L16:
    rh = *ai / sqrt(rh);
    if (rhoz < 0.f) {
	rh = -rh;
    }
    incom_1.xo = *xi + rh * rhox;
    incom_1.yo = *yi + rh * rhoy;
    incom_1.zo = *zi + rh * rhoz;
L17:
    r__ = xij * xij + yij * yij + zij * zij;
    if (r__ > .95f) {
	goto L18;
    }

/*     FIELD FROM INTERPOLATION IS INTEGRATED OVER SEGMENT */

    incom_1.isnor = 1;
    d_cnjg(&z__4, &dataj_1.exk);
    z__3.r = dataj_1.exk.r * z__4.r - dataj_1.exk.i * z__4.i, z__3.i = 
	    dataj_1.exk.r * z__4.i + dataj_1.exk.i * z__4.r;
    d_cnjg(&z__6, &dataj_1.eyk);
    z__5.r = dataj_1.eyk.r * z__6.r - dataj_1.eyk.i * z__6.i, z__5.i = 
	    dataj_1.eyk.r * z__6.i + dataj_1.eyk.i * z__6.r;
    z__2.r = z__3.r + z__5.r, z__2.i = z__3.i + z__5.i;
    d_cnjg(&z__8, &dataj_1.ezk);
    z__7.r = dataj_1.ezk.r * z__8.r - dataj_1.ezk.i * z__8.i, z__7.i = 
	    dataj_1.ezk.r * z__8.i + dataj_1.ezk.i * z__8.r;
    z__1.r = z__2.r + z__7.r, z__1.i = z__2.i + z__7.i;
    dmin__ = z__1.r;
    dmin__ = sqrt(dmin__) * .01f;
    shaf = dataj_1.s * .5f;
    d__1 = -shaf;
    rom2_(&d__1, &shaf, egnd, &dmin__);
    goto L19;

/*     NORTON FIELD EQUATIONS AND LUMPED CURRENT ELEMENT APPROXIMATION */

L18:
    incom_1.isnor = 2;
    sflds_(&c_b636, egnd);
    goto L22;
L19:
    zp = xij * dataj_1.cabj + yij * dataj_1.sabj + zij * salpr;
    rh = r__ - zp * zp;
    if (rh > 1e-10) {
	goto L20;
    }
    dmin__ = 0.f;
    goto L21;
L20:
    dmin__ = sqrt(rh / (rh + *ai * *ai));
L21:
    if (dmin__ > .95f) {
	goto L22;
    }
    px = 1.f - dmin__;
    z__4.r = dataj_1.cabj * txk->r, z__4.i = dataj_1.cabj * txk->i;
    z__5.r = dataj_1.sabj * tyk->r, z__5.i = dataj_1.sabj * tyk->i;
    z__3.r = z__4.r + z__5.r, z__3.i = z__4.i + z__5.i;
    z__6.r = salpr * tzk->r, z__6.i = salpr * tzk->i;
    z__2.r = z__3.r + z__6.r, z__2.i = z__3.i + z__6.i;
    z__1.r = px * z__2.r, z__1.i = px * z__2.i;
    terk.r = z__1.r, terk.i = z__1.i;
    z__2.r = dmin__ * txk->r, z__2.i = dmin__ * txk->i;
    z__3.r = dataj_1.cabj * terk.r, z__3.i = dataj_1.cabj * terk.i;
    z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
    txk->r = z__1.r, txk->i = z__1.i;
    z__2.r = dmin__ * tyk->r, z__2.i = dmin__ * tyk->i;
    z__3.r = dataj_1.sabj * terk.r, z__3.i = dataj_1.sabj * terk.i;
    z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
    tyk->r = z__1.r, tyk->i = z__1.i;
    z__2.r = dmin__ * tzk->r, z__2.i = dmin__ * tzk->i;
    z__3.r = salpr * terk.r, z__3.i = salpr * terk.i;
    z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
    tzk->r = z__1.r, tzk->i = z__1.i;
    z__4.r = dataj_1.cabj * txs->r, z__4.i = dataj_1.cabj * txs->i;
    z__5.r = dataj_1.sabj * tys->r, z__5.i = dataj_1.sabj * tys->i;
    z__3.r = z__4.r + z__5.r, z__3.i = z__4.i + z__5.i;
    z__6.r = salpr * tzs->r, z__6.i = salpr * tzs->i;
    z__2.r = z__3.r + z__6.r, z__2.i = z__3.i + z__6.i;
    z__1.r = px * z__2.r, z__1.i = px * z__2.i;
    ters.r = z__1.r, ters.i = z__1.i;
    z__2.r = dmin__ * txs->r, z__2.i = dmin__ * txs->i;
    z__3.r = dataj_1.cabj * ters.r, z__3.i = dataj_1.cabj * ters.i;
    z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
    txs->r = z__1.r, txs->i = z__1.i;
    z__2.r = dmin__ * tys->r, z__2.i = dmin__ * tys->i;
    z__3.r = dataj_1.sabj * ters.r, z__3.i = dataj_1.sabj * ters.i;
    z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
    tys->r = z__1.r, tys->i = z__1.i;
    z__2.r = dmin__ * tzs->r, z__2.i = dmin__ * tzs->i;
    z__3.r = salpr * ters.r, z__3.i = salpr * ters.i;
    z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
    tzs->r = z__1.r, tzs->i = z__1.i;
    z__4.r = dataj_1.cabj * txc->r, z__4.i = dataj_1.cabj * txc->i;
    z__5.r = dataj_1.sabj * tyc->r, z__5.i = dataj_1.sabj * tyc->i;
    z__3.r = z__4.r + z__5.r, z__3.i = z__4.i + z__5.i;
    z__6.r = salpr * tzc->r, z__6.i = salpr * tzc->i;
    z__2.r = z__3.r + z__6.r, z__2.i = z__3.i + z__6.i;
    z__1.r = px * z__2.r, z__1.i = px * z__2.i;
    terc.r = z__1.r, terc.i = z__1.i;
    z__2.r = dmin__ * txc->r, z__2.i = dmin__ * txc->i;
    z__3.r = dataj_1.cabj * terc.r, z__3.i = dataj_1.cabj * terc.i;
    z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
    txc->r = z__1.r, txc->i = z__1.i;
    z__2.r = dmin__ * tyc->r, z__2.i = dmin__ * tyc->i;
    z__3.r = dataj_1.sabj * terc.r, z__3.i = dataj_1.sabj * terc.i;
    z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
    tyc->r = z__1.r, tyc->i = z__1.i;
    z__2.r = dmin__ * tzc->r, z__2.i = dmin__ * tzc->i;
    z__3.r = salpr * terc.r, z__3.i = salpr * terc.i;
    z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
    tzc->r = z__1.r, tzc->i = z__1.i;
L22:
    z__1.r = dataj_1.exk.r + txk->r, z__1.i = dataj_1.exk.i + txk->i;
    dataj_1.exk.r = z__1.r, dataj_1.exk.i = z__1.i;
    z__1.r = dataj_1.eyk.r + tyk->r, z__1.i = dataj_1.eyk.i + tyk->i;
    dataj_1.eyk.r = z__1.r, dataj_1.eyk.i = z__1.i;
    z__1.r = dataj_1.ezk.r + tzk->r, z__1.i = dataj_1.ezk.i + tzk->i;
    dataj_1.ezk.r = z__1.r, dataj_1.ezk.i = z__1.i;
    z__1.r = dataj_1.exs.r + txs->r, z__1.i = dataj_1.exs.i + txs->i;
    dataj_1.exs.r = z__1.r, dataj_1.exs.i = z__1.i;
    z__1.r = dataj_1.eys.r + tys->r, z__1.i = dataj_1.eys.i + tys->i;
    dataj_1.eys.r = z__1.r, dataj_1.eys.i = z__1.i;
    z__1.r = dataj_1.ezs.r + tzs->r, z__1.i = dataj_1.ezs.i + tzs->i;
    dataj_1.ezs.r = z__1.r, dataj_1.ezs.i = z__1.i;
    z__1.r = dataj_1.exc.r + txc->r, z__1.i = dataj_1.exc.i + txc->i;
    dataj_1.exc.r = z__1.r, dataj_1.exc.i = z__1.i;
    z__1.r = dataj_1.eyc.r + tyc->r, z__1.i = dataj_1.eyc.i + tyc->i;
    dataj_1.eyc.r = z__1.r, dataj_1.eyc.i = z__1.i;
    z__1.r = dataj_1.ezc.r + tzc->r, z__1.i = dataj_1.ezc.i + tzc->i;
    dataj_1.ezc.r = z__1.r, dataj_1.ezc.i = z__1.i;
    return 0;
} /* efld_ */

#undef egnd
#undef tzs
#undef tys
#undef txs
#undef tzk
#undef tyk
#undef txk
#undef tzc
#undef tyc
#undef txc


/* Subroutine */ int eksc_(doublereal *s, doublereal *z__, doublereal *rh, 
	doublereal *xk, integer *ij, doublecomplex *ezs, doublecomplex *ers, 
	doublecomplex *ezc, doublecomplex *erc, doublecomplex *ezk, 
	doublecomplex *erk)
{
    /* Initialized data */

    static struct {
	doublereal e_1[2];
	} equiv_0 = { 0., 4.771341189 };


    /* System generated locals */
    doublereal d__1, d__2;
    doublecomplex z__1, z__2, z__3, z__4, z__5, z__6, z__7, z__8, z__9, z__10,
	     z__11, z__12, z__13;

    /* Builtin functions */
    double sin(doublereal), cos(doublereal);

    /* Local variables */
    doublereal z1, z2, cs, sh;
    extern /* Subroutine */ int gx_(doublereal *, doublereal *, doublereal *, 
	    doublecomplex *, doublecomplex *);
    doublereal ss;
    doublecomplex gp1, gp2, gz1, gz2;
#define con ((doublecomplex *)&equiv_0)
    doublereal rhk, shk;
    doublecomplex gzp1, gzp2;
    doublereal cint;
#define conx ((doublereal *)&equiv_0)
    doublereal sint;
    extern /* Subroutine */ int intx_(doublereal *, doublereal *, doublereal *
	    , integer *, doublereal *, doublereal *);

/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* *** */
/*     COMPUTE E FIELD OF SINE, COSINE, AND CONSTANT CURRENT FILAMENTS BY */
/*     THIN WIRE APPROXIMATION. */
    tmi_1.ijx = *ij;
    tmi_1.zpk = *xk * *z__;
    rhk = *xk * *rh;
    tmi_1.rkb2 = rhk * rhk;
    sh = *s * .5f;
    shk = *xk * sh;
    ss = sin(shk);
    cs = cos(shk);
    z2 = sh - *z__;
    z1 = -(sh + *z__);
    gx_(&z1, rh, xk, &gz1, &gp1);
    gx_(&z2, rh, xk, &gz2, &gp2);
    z__1.r = z1 * gp1.r, z__1.i = z1 * gp1.i;
    gzp1.r = z__1.r, gzp1.i = z__1.i;
    z__1.r = z2 * gp2.r, z__1.i = z2 * gp2.i;
    gzp2.r = z__1.r, gzp2.i = z__1.i;
    z__5.r = gz2.r - gz1.r, z__5.i = gz2.i - gz1.i;
    z__4.r = cs * z__5.r, z__4.i = cs * z__5.i;
    z__3.r = *xk * z__4.r, z__3.i = *xk * z__4.i;
    z__7.r = gzp2.r + gzp1.r, z__7.i = gzp2.i + gzp1.i;
    z__6.r = ss * z__7.r, z__6.i = ss * z__7.i;
    z__2.r = z__3.r - z__6.r, z__2.i = z__3.i - z__6.i;
    z__1.r = con->r * z__2.r - con->i * z__2.i, z__1.i = con->r * z__2.i + 
	    con->i * z__2.r;
    ezs->r = z__1.r, ezs->i = z__1.i;
    z__2.r = -con->r, z__2.i = -con->i;
    z__6.r = gz2.r + gz1.r, z__6.i = gz2.i + gz1.i;
    z__5.r = ss * z__6.r, z__5.i = ss * z__6.i;
    z__4.r = *xk * z__5.r, z__4.i = *xk * z__5.i;
    z__8.r = gzp2.r - gzp1.r, z__8.i = gzp2.i - gzp1.i;
    z__7.r = cs * z__8.r, z__7.i = cs * z__8.i;
    z__3.r = z__4.r + z__7.r, z__3.i = z__4.i + z__7.i;
    z__1.r = z__2.r * z__3.r - z__2.i * z__3.i, z__1.i = z__2.r * z__3.i + 
	    z__2.i * z__3.r;
    ezc->r = z__1.r, ezc->i = z__1.i;
    z__3.r = gp2.r - gp1.r, z__3.i = gp2.i - gp1.i;
    z__2.r = con->r * z__3.r - con->i * z__3.i, z__2.i = con->r * z__3.i + 
	    con->i * z__3.r;
    z__1.r = *rh * z__2.r, z__1.i = *rh * z__2.i;
    erk->r = z__1.r, erk->i = z__1.i;
    d__1 = -shk;
    intx_(&d__1, &shk, &rhk, ij, &cint, &sint);
    z__2.r = -con->r, z__2.i = -con->i;
    z__4.r = gzp2.r - gzp1.r, z__4.i = gzp2.i - gzp1.i;
    d__1 = *xk * *xk;
    d__2 = -sint;
    z__6.r = cint, z__6.i = d__2;
    z__5.r = d__1 * z__6.r, z__5.i = d__1 * z__6.i;
    z__3.r = z__4.r + z__5.r, z__3.i = z__4.i + z__5.i;
    z__1.r = z__2.r * z__3.r - z__2.i * z__3.i, z__1.i = z__2.r * z__3.i + 
	    z__2.i * z__3.r;
    ezk->r = z__1.r, ezk->i = z__1.i;
    z__1.r = z1 * gzp1.r, z__1.i = z1 * gzp1.i;
    gzp1.r = z__1.r, gzp1.i = z__1.i;
    z__1.r = z2 * gzp2.r, z__1.i = z2 * gzp2.i;
    gzp2.r = z__1.r, gzp2.i = z__1.i;
    if (*rh < 1e-10) {
	goto L1;
    }
    z__3.r = -con->r, z__3.i = -con->i;
    z__8.r = gzp2.r + gzp1.r, z__8.i = gzp2.i + gzp1.i;
    z__7.r = z__8.r + gz2.r, z__7.i = z__8.i + gz2.i;
    z__6.r = z__7.r + gz1.r, z__6.i = z__7.i + gz1.i;
    z__5.r = ss * z__6.r, z__5.i = ss * z__6.i;
    z__12.r = z2 * gz2.r, z__12.i = z2 * gz2.i;
    z__13.r = z1 * gz1.r, z__13.i = z1 * gz1.i;
    z__11.r = z__12.r - z__13.r, z__11.i = z__12.i - z__13.i;
    z__10.r = cs * z__11.r, z__10.i = cs * z__11.i;
    z__9.r = *xk * z__10.r, z__9.i = *xk * z__10.i;
    z__4.r = z__5.r - z__9.r, z__4.i = z__5.i - z__9.i;
    z__2.r = z__3.r * z__4.r - z__3.i * z__4.i, z__2.i = z__3.r * z__4.i + 
	    z__3.i * z__4.r;
    z__1.r = z__2.r / *rh, z__1.i = z__2.i / *rh;
    ers->r = z__1.r, ers->i = z__1.i;
    z__3.r = -con->r, z__3.i = -con->i;
    z__8.r = gzp2.r - gzp1.r, z__8.i = gzp2.i - gzp1.i;
    z__7.r = z__8.r + gz2.r, z__7.i = z__8.i + gz2.i;
    z__6.r = z__7.r - gz1.r, z__6.i = z__7.i - gz1.i;
    z__5.r = cs * z__6.r, z__5.i = cs * z__6.i;
    z__12.r = z2 * gz2.r, z__12.i = z2 * gz2.i;
    z__13.r = z1 * gz1.r, z__13.i = z1 * gz1.i;
    z__11.r = z__12.r + z__13.r, z__11.i = z__12.i + z__13.i;
    z__10.r = ss * z__11.r, z__10.i = ss * z__11.i;
    z__9.r = *xk * z__10.r, z__9.i = *xk * z__10.i;
    z__4.r = z__5.r + z__9.r, z__4.i = z__5.i + z__9.i;
    z__2.r = z__3.r * z__4.r - z__3.i * z__4.i, z__2.i = z__3.r * z__4.i + 
	    z__3.i * z__4.r;
    z__1.r = z__2.r / *rh, z__1.i = z__2.i / *rh;
    erc->r = z__1.r, erc->i = z__1.i;
    return 0;
L1:
    ers->r = 0.f, ers->i = 0.f;
    erc->r = 0.f, erc->i = 0.f;
    return 0;
} /* eksc_ */

#undef conx
#undef con


/* Subroutine */ int ekscx_(doublereal *bx, doublereal *s, doublereal *z__, 
	doublereal *rhx, doublereal *xk, integer *ij, integer *inx1, integer *
	inx2, doublecomplex *ezs, doublecomplex *ers, doublecomplex *ezc, 
	doublecomplex *erc, doublecomplex *ezk, doublecomplex *erk)
{
    /* Initialized data */

    static struct {
	doublereal e_1[2];
	} equiv_0 = { 0., 4.771341189 };


    /* System generated locals */
    doublereal d__1, d__2;
    doublecomplex z__1, z__2, z__3, z__4, z__5, z__6, z__7, z__8, z__9, z__10,
	     z__11, z__12, z__13, z__14;

    /* Builtin functions */
    double sin(doublereal), cos(doublereal);

    /* Local variables */
    doublereal b, a2, z1, z2, bk, cs, rh, sh;
    extern /* Subroutine */ int gx_(doublereal *, doublereal *, doublereal *, 
	    doublecomplex *, doublecomplex *);
    doublereal ss, bk2;
    doublecomplex gr1, gr2, gz1, gz2;
    integer ira;
#define con ((doublecomplex *)&equiv_0)
    doublereal rhk, shk;
    extern /* Subroutine */ int gxx_(doublereal *, doublereal *, doublereal *,
	     doublereal *, doublereal *, integer *, doublecomplex *, 
	    doublecomplex *, doublecomplex *, doublecomplex *, doublecomplex *
	    , doublecomplex *);
    doublecomplex grk1, grk2, grp1, grp2, gzp1, gzp2, gzz1, gzz2;
    doublereal cint;
#define conx ((doublereal *)&equiv_0)
    doublereal sint;
    extern /* Subroutine */ int intx_(doublereal *, doublereal *, doublereal *
	    , integer *, doublereal *, doublereal *);

/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* *** */
/*     COMPUTE E FIELD OF SINE, COSINE, AND CONSTANT CURRENT FILAMENTS BY */
/*     EXTENDED THIN WIRE APPROXIMATION. */
    if (*rhx < *bx) {
	goto L1;
    }
    rh = *rhx;
    b = *bx;
    ira = 0;
    goto L2;
L1:
    rh = *bx;
    b = *rhx;
    ira = 1;
L2:
    sh = *s * .5f;
    tmi_1.ijx = *ij;
    tmi_1.zpk = *xk * *z__;
    rhk = *xk * rh;
    tmi_1.rkb2 = rhk * rhk;
    shk = *xk * sh;
    ss = sin(shk);
    cs = cos(shk);
    z2 = sh - *z__;
    z1 = -(sh + *z__);
    a2 = b * b;
    if (*inx1 == 2) {
	goto L3;
    }
    gxx_(&z1, &rh, &b, &a2, xk, &ira, &gz1, &gzp1, &gr1, &grp1, &grk1, &gzz1);
    goto L4;
L3:
    gx_(&z1, rhx, xk, &gz1, &grk1);
    z__1.r = z1 * grk1.r, z__1.i = z1 * grk1.i;
    gzp1.r = z__1.r, gzp1.i = z__1.i;
    z__1.r = gz1.r / *rhx, z__1.i = gz1.i / *rhx;
    gr1.r = z__1.r, gr1.i = z__1.i;
    z__1.r = gzp1.r / *rhx, z__1.i = gzp1.i / *rhx;
    grp1.r = z__1.r, grp1.i = z__1.i;
    z__1.r = *rhx * grk1.r, z__1.i = *rhx * grk1.i;
    grk1.r = z__1.r, grk1.i = z__1.i;
    gzz1.r = 0.f, gzz1.i = 0.f;
L4:
    if (*inx2 == 2) {
	goto L5;
    }
    gxx_(&z2, &rh, &b, &a2, xk, &ira, &gz2, &gzp2, &gr2, &grp2, &grk2, &gzz2);
    goto L6;
L5:
    gx_(&z2, rhx, xk, &gz2, &grk2);
    z__1.r = z2 * grk2.r, z__1.i = z2 * grk2.i;
    gzp2.r = z__1.r, gzp2.i = z__1.i;
    z__1.r = gz2.r / *rhx, z__1.i = gz2.i / *rhx;
    gr2.r = z__1.r, gr2.i = z__1.i;
    z__1.r = gzp2.r / *rhx, z__1.i = gzp2.i / *rhx;
    grp2.r = z__1.r, grp2.i = z__1.i;
    z__1.r = *rhx * grk2.r, z__1.i = *rhx * grk2.i;
    grk2.r = z__1.r, grk2.i = z__1.i;
    gzz2.r = 0.f, gzz2.i = 0.f;
L6:
    z__5.r = gz2.r - gz1.r, z__5.i = gz2.i - gz1.i;
    z__4.r = cs * z__5.r, z__4.i = cs * z__5.i;
    z__3.r = *xk * z__4.r, z__3.i = *xk * z__4.i;
    z__7.r = gzp2.r + gzp1.r, z__7.i = gzp2.i + gzp1.i;
    z__6.r = ss * z__7.r, z__6.i = ss * z__7.i;
    z__2.r = z__3.r - z__6.r, z__2.i = z__3.i - z__6.i;
    z__1.r = con->r * z__2.r - con->i * z__2.i, z__1.i = con->r * z__2.i + 
	    con->i * z__2.r;
    ezs->r = z__1.r, ezs->i = z__1.i;
    z__2.r = -con->r, z__2.i = -con->i;
    z__6.r = gz2.r + gz1.r, z__6.i = gz2.i + gz1.i;
    z__5.r = ss * z__6.r, z__5.i = ss * z__6.i;
    z__4.r = *xk * z__5.r, z__4.i = *xk * z__5.i;
    z__8.r = gzp2.r - gzp1.r, z__8.i = gzp2.i - gzp1.i;
    z__7.r = cs * z__8.r, z__7.i = cs * z__8.i;
    z__3.r = z__4.r + z__7.r, z__3.i = z__4.i + z__7.i;
    z__1.r = z__2.r * z__3.r - z__2.i * z__3.i, z__1.i = z__2.r * z__3.i + 
	    z__2.i * z__3.r;
    ezc->r = z__1.r, ezc->i = z__1.i;
    z__2.r = -con->r, z__2.i = -con->i;
    z__8.r = z2 * grp2.r, z__8.i = z2 * grp2.i;
    z__9.r = z1 * grp1.r, z__9.i = z1 * grp1.i;
    z__7.r = z__8.r + z__9.r, z__7.i = z__8.i + z__9.i;
    z__6.r = z__7.r + gr2.r, z__6.i = z__7.i + gr2.i;
    z__5.r = z__6.r + gr1.r, z__5.i = z__6.i + gr1.i;
    z__4.r = ss * z__5.r, z__4.i = ss * z__5.i;
    z__13.r = z2 * gr2.r, z__13.i = z2 * gr2.i;
    z__14.r = z1 * gr1.r, z__14.i = z1 * gr1.i;
    z__12.r = z__13.r - z__14.r, z__12.i = z__13.i - z__14.i;
    z__11.r = cs * z__12.r, z__11.i = cs * z__12.i;
    z__10.r = *xk * z__11.r, z__10.i = *xk * z__11.i;
    z__3.r = z__4.r - z__10.r, z__3.i = z__4.i - z__10.i;
    z__1.r = z__2.r * z__3.r - z__2.i * z__3.i, z__1.i = z__2.r * z__3.i + 
	    z__2.i * z__3.r;
    ers->r = z__1.r, ers->i = z__1.i;
    z__2.r = -con->r, z__2.i = -con->i;
    z__8.r = z2 * grp2.r, z__8.i = z2 * grp2.i;
    z__9.r = z1 * grp1.r, z__9.i = z1 * grp1.i;
    z__7.r = z__8.r - z__9.r, z__7.i = z__8.i - z__9.i;
    z__6.r = z__7.r + gr2.r, z__6.i = z__7.i + gr2.i;
    z__5.r = z__6.r - gr1.r, z__5.i = z__6.i - gr1.i;
    z__4.r = cs * z__5.r, z__4.i = cs * z__5.i;
    z__13.r = z2 * gr2.r, z__13.i = z2 * gr2.i;
    z__14.r = z1 * gr1.r, z__14.i = z1 * gr1.i;
    z__12.r = z__13.r + z__14.r, z__12.i = z__13.i + z__14.i;
    z__11.r = ss * z__12.r, z__11.i = ss * z__12.i;
    z__10.r = *xk * z__11.r, z__10.i = *xk * z__11.i;
    z__3.r = z__4.r + z__10.r, z__3.i = z__4.i + z__10.i;
    z__1.r = z__2.r * z__3.r - z__2.i * z__3.i, z__1.i = z__2.r * z__3.i + 
	    z__2.i * z__3.r;
    erc->r = z__1.r, erc->i = z__1.i;
    z__2.r = grk2.r - grk1.r, z__2.i = grk2.i - grk1.i;
    z__1.r = con->r * z__2.r - con->i * z__2.i, z__1.i = con->r * z__2.i + 
	    con->i * z__2.r;
    erk->r = z__1.r, erk->i = z__1.i;
    d__1 = -shk;
    intx_(&d__1, &shk, &rhk, ij, &cint, &sint);
    bk = b * *xk;
    bk2 = bk * bk * .25f;
    z__2.r = -con->r, z__2.i = -con->i;
    z__5.r = gzp2.r - gzp1.r, z__5.i = gzp2.i - gzp1.i;
    d__1 = *xk * *xk * (1.f - bk2);
    d__2 = -sint;
    z__7.r = cint, z__7.i = d__2;
    z__6.r = d__1 * z__7.r, z__6.i = d__1 * z__7.i;
    z__4.r = z__5.r + z__6.r, z__4.i = z__5.i + z__6.i;
    z__9.r = gzz2.r - gzz1.r, z__9.i = gzz2.i - gzz1.i;
    z__8.r = bk2 * z__9.r, z__8.i = bk2 * z__9.i;
    z__3.r = z__4.r - z__8.r, z__3.i = z__4.i - z__8.i;
    z__1.r = z__2.r * z__3.r - z__2.i * z__3.i, z__1.i = z__2.r * z__3.i + 
	    z__2.i * z__3.r;
    ezk->r = z__1.r, ezk->i = z__1.i;
    return 0;
} /* ekscx_ */

#undef conx
#undef con


/* av03 SUBROUTINE ERROR */
/* *** */
/*     GET REASON FOR FILE ERROR (VAX ONLY).  ERROR SHOULD BE REDUCED TO */
/*     "RETURN END" FOR MACINTOSH. */

/*      IMPLICIT INTEGER (A-Z) */
/*      CHARACTER MSG*80 */
/*      CALL ERRSNS(FNUM,RMSSTS,RMSSTV,IUNIT,CONDVAL) */
/*      CALL SYS$GETMSG(%VAL(RMSSTS),MSGLEN,MSG,,,) */
/*      CALL STR$UPCASE(MSG,MSG) */
/*      IND=INDEX(MSG,',') */
/*      TYPE 1,MSG(IND+2:MSGLEN) */
/* 1     FORMAT(//,'  ****  ERROR  ****   ',//,5X,A,//) */
/* av03 RETURN */
/* av03 END */
/* Subroutine */ int etmns_(doublereal *p1, doublereal *p2, doublereal *p3, 
	doublereal *p4, doublereal *p5, doublereal *p6, integer *ipr, 
	doublecomplex *e)
{
    /* Initialized data */

    static doublereal tp = 6.283185308;
    static doublereal reta = .002654420938;

    /* System generated locals */
    integer i__1, i__2, i__3, i__4, i__5, i__6;
    doublereal d__1, d__2, d__3;
    doublecomplex z__1, z__2, z__3, z__4, z__5, z__6, z__7, z__8;

    /* Builtin functions */
    double cos(doublereal), sin(doublereal);
    void z_sqrt(doublecomplex *, doublecomplex *), z_div(doublecomplex *, 
	    doublecomplex *, doublecomplex *);
    double sqrt(doublereal);

    /* Local variables */
    integer i__;
    doublereal r__;
    integer i1, i2, ii;
    doublecomplex er;
    doublereal ds;
    doublecomplex et, cx, cy, cz;
    integer is;
    doublereal rs, px, py, pz, qx, qy, qz, wx, wy, wz;
    doublecomplex tt1, tt2;
#define t1x ((doublereal *)&data_1 + 4500)
#define t1y ((doublereal *)&data_1 + 7500)
#define t1z ((doublereal *)&data_1 + 9000)
#define t2x ((doublereal *)&data_1 + 10501)
#define t2y ((doublereal *)&data_1 + 12001)
#define t2z ((doublereal *)&data_1 + 13501)
#define cab ((doublereal *)&data_1 + 7500)
#define sab ((doublereal *)&data_1 + 9000)
    doublereal arg, cph, cet;
    doublecomplex erh;
    doublereal cth, dsh;
    integer neq;
    doublecomplex ezh, rrh;
    doublereal sph, sth, set;
    integer npm;
    doublecomplex rrv;
    extern /* Subroutine */ int qdsrc_(integer *, doublecomplex *, 
	    doublecomplex *);

/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* Max number of segments 	(Windows-95 <= 4 */
/* max nr of 'in-core' alloc.	(MAXMAT <= MA */
/* Max number of LD cards */
/* Max number of EX cards */
/* Max number of segs connected to NT/TL */
/* *** */

/*     ETMNS FILLS THE ARRAY E WITH THE NEGATIVE OF THE ELECTRIC FIELD */
/*     INCIDENT ON THE STRUCTURE.  E IS THE RIGHT HAND SIDE OF THE MATRIX */
/*     EQUATION. */

/* av07 COMMON /VSORC/ VQD(30),VSANT(30),VQDS(30),IVQD(30),ISANT(30),IQDS( */
/* av07 130),NVQD,NSANT,NQDS */
/* av07 */
    /* Parameter adjustments */
    --e;

    /* Function Body */
    neq = data_1.n + 2 * data_1.m;
    vsorc_1.nqds = 0;
    if (*ipr > 0 && *ipr != 5) {
	goto L5;
    }

/*     APPLIED FIELD OF VOLTAGE SOURCES FOR TRANSMITTING CASE */

    i__1 = neq;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L1: */
	i__2 = i__;
	e[i__2].r = 0.f, e[i__2].i = 0.f;
    }
    if (vsorc_1.nsant == 0) {
	goto L3;
    }
    i__2 = vsorc_1.nsant;
    for (i__ = 1; i__ <= i__2; ++i__) {
	is = vsorc_1.isant[i__ - 1];
/* L2: */
	i__1 = is;
	i__3 = i__ - 1;
	z__2.r = -vsorc_1.vsant[i__3].r, z__2.i = -vsorc_1.vsant[i__3].i;
	d__1 = data_1.si[is - 1] * data_1.wlam;
	z__1.r = z__2.r / d__1, z__1.i = z__2.i / d__1;
	e[i__1].r = z__1.r, e[i__1].i = z__1.i;
    }
L3:
    if (vsorc_1.nvqd == 0) {
	return 0;
    }
    i__1 = vsorc_1.nvqd;
    for (i__ = 1; i__ <= i__1; ++i__) {
	is = vsorc_1.ivqd[i__ - 1];
/* L4: */
	qdsrc_(&is, &vsorc_1.vqd[i__ - 1], &e[1]);
    }
    return 0;
L5:
    if (*ipr > 3) {
	goto L19;
    }

/*     INCIDENT PLANE WAVE, LINEARLY POLARIZED. */

    cth = cos(*p1);
    sth = sin(*p1);
    cph = cos(*p2);
    sph = sin(*p2);
    cet = cos(*p3);
    set = sin(*p3);
    px = cth * cph * cet - sph * set;
    py = cth * sph * cet + cph * set;
    pz = -sth * cet;
    wx = -sth * cph;
    wy = -sth * sph;
    wz = -cth;
    qx = wy * pz - wz * py;
    qy = wz * px - wx * pz;
    qz = wx * py - wy * px;
    if (gnd_1.ksymp == 1) {
	goto L7;
    }
    if (gnd_1.iperf == 1) {
	goto L6;
    }
    z__5.r = gnd_1.zrati.r * gnd_1.zrati.r - gnd_1.zrati.i * gnd_1.zrati.i, 
	    z__5.i = gnd_1.zrati.r * gnd_1.zrati.i + gnd_1.zrati.i * 
	    gnd_1.zrati.r;
    z__4.r = sth * z__5.r, z__4.i = sth * z__5.i;
    z__3.r = sth * z__4.r, z__3.i = sth * z__4.i;
    z__2.r = 1.f - z__3.r, z__2.i = -z__3.i;
    z_sqrt(&z__1, &z__2);
    rrv.r = z__1.r, rrv.i = z__1.i;
    z__1.r = cth * gnd_1.zrati.r, z__1.i = cth * gnd_1.zrati.i;
    rrh.r = z__1.r, rrh.i = z__1.i;
    z__2.r = rrh.r - rrv.r, z__2.i = rrh.i - rrv.i;
    z__3.r = rrh.r + rrv.r, z__3.i = rrh.i + rrv.i;
    z_div(&z__1, &z__2, &z__3);
    rrh.r = z__1.r, rrh.i = z__1.i;
    z__1.r = gnd_1.zrati.r * rrv.r - gnd_1.zrati.i * rrv.i, z__1.i = 
	    gnd_1.zrati.r * rrv.i + gnd_1.zrati.i * rrv.r;
    rrv.r = z__1.r, rrv.i = z__1.i;
    z__3.r = cth - rrv.r, z__3.i = -rrv.i;
    z__2.r = -z__3.r, z__2.i = -z__3.i;
    z__4.r = cth + rrv.r, z__4.i = rrv.i;
    z_div(&z__1, &z__2, &z__4);
    rrv.r = z__1.r, rrv.i = z__1.i;
    goto L7;
L6:
    rrv.r = -1.f, rrv.i = -0.f;
    rrh.r = -1.f, rrh.i = -0.f;
L7:
    if (*ipr > 1) {
	goto L13;
    }
    if (data_1.n == 0) {
	goto L10;
    }
    i__1 = data_1.n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	arg = -tp * (wx * data_1.x[i__ - 1] + wy * data_1.y[i__ - 1] + wz * 
		data_1.z__[i__ - 1]);
/* L8: */
	i__3 = i__;
	d__1 = -(px * cab[i__ - 1] + py * sab[i__ - 1] + pz * angl_1.salp[i__ 
		- 1]);
	d__2 = cos(arg);
	d__3 = sin(arg);
	z__2.r = d__2, z__2.i = d__3;
	z__1.r = d__1 * z__2.r, z__1.i = d__1 * z__2.i;
	e[i__3].r = z__1.r, e[i__3].i = z__1.i;
    }
    if (gnd_1.ksymp == 1) {
	goto L10;
    }
    d__1 = py * cph - px * sph;
    z__2.r = rrh.r - rrv.r, z__2.i = rrh.i - rrv.i;
    z__1.r = d__1 * z__2.r, z__1.i = d__1 * z__2.i;
    tt1.r = z__1.r, tt1.i = z__1.i;
    z__2.r = px * rrv.r, z__2.i = px * rrv.i;
    z__3.r = sph * tt1.r, z__3.i = sph * tt1.i;
    z__1.r = z__2.r - z__3.r, z__1.i = z__2.i - z__3.i;
    cx.r = z__1.r, cx.i = z__1.i;
    z__2.r = py * rrv.r, z__2.i = py * rrv.i;
    z__3.r = cph * tt1.r, z__3.i = cph * tt1.i;
    z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
    cy.r = z__1.r, cy.i = z__1.i;
    z__2.r = -rrv.r, z__2.i = -rrv.i;
    z__1.r = pz * z__2.r, z__1.i = pz * z__2.i;
    cz.r = z__1.r, cz.i = z__1.i;
    i__3 = data_1.n;
    for (i__ = 1; i__ <= i__3; ++i__) {
	arg = -tp * (wx * data_1.x[i__ - 1] + wy * data_1.y[i__ - 1] - wz * 
		data_1.z__[i__ - 1]);
/* L9: */
	i__1 = i__;
	i__2 = i__;
	i__4 = i__ - 1;
	z__5.r = cab[i__4] * cx.r, z__5.i = cab[i__4] * cx.i;
	i__5 = i__ - 1;
	z__6.r = sab[i__5] * cy.r, z__6.i = sab[i__5] * cy.i;
	z__4.r = z__5.r + z__6.r, z__4.i = z__5.i + z__6.i;
	i__6 = i__ - 1;
	z__7.r = angl_1.salp[i__6] * cz.r, z__7.i = angl_1.salp[i__6] * cz.i;
	z__3.r = z__4.r + z__7.r, z__3.i = z__4.i + z__7.i;
	d__1 = cos(arg);
	d__2 = sin(arg);
	z__8.r = d__1, z__8.i = d__2;
	z__2.r = z__3.r * z__8.r - z__3.i * z__8.i, z__2.i = z__3.r * z__8.i 
		+ z__3.i * z__8.r;
	z__1.r = e[i__2].r - z__2.r, z__1.i = e[i__2].i - z__2.i;
	e[i__1].r = z__1.r, e[i__1].i = z__1.i;
    }
L10:
    if (data_1.m == 0) {
	return 0;
    }
    i__ = data_1.ld + 1;
    i1 = data_1.n - 1;
    i__1 = data_1.m;
    for (is = 1; is <= i__1; ++is) {
	--i__;
	i1 += 2;
	i2 = i1 + 1;
	arg = -tp * (wx * data_1.x[i__ - 1] + wy * data_1.y[i__ - 1] + wz * 
		data_1.z__[i__ - 1]);
	d__1 = cos(arg);
	d__2 = sin(arg);
	z__3.r = d__1, z__3.i = d__2;
	i__2 = i__ - 1;
	z__2.r = angl_1.salp[i__2] * z__3.r, z__2.i = angl_1.salp[i__2] * 
		z__3.i;
	z__1.r = reta * z__2.r, z__1.i = reta * z__2.i;
	tt1.r = z__1.r, tt1.i = z__1.i;
	i__2 = i2;
	d__1 = qx * t1x[i__ - 1] + qy * t1y[i__ - 1] + qz * t1z[i__ - 1];
	z__1.r = d__1 * tt1.r, z__1.i = d__1 * tt1.i;
	e[i__2].r = z__1.r, e[i__2].i = z__1.i;
/* L11: */
	i__2 = i1;
	d__1 = qx * t2x[i__ - 1] + qy * t2y[i__ - 1] + qz * t2z[i__ - 1];
	z__1.r = d__1 * tt1.r, z__1.i = d__1 * tt1.i;
	e[i__2].r = z__1.r, e[i__2].i = z__1.i;
    }
    if (gnd_1.ksymp == 1) {
	return 0;
    }
    d__1 = qy * cph - qx * sph;
    z__2.r = rrv.r - rrh.r, z__2.i = rrv.i - rrh.i;
    z__1.r = d__1 * z__2.r, z__1.i = d__1 * z__2.i;
    tt1.r = z__1.r, tt1.i = z__1.i;
    z__3.r = qx * rrh.r, z__3.i = qx * rrh.i;
    z__4.r = sph * tt1.r, z__4.i = sph * tt1.i;
    z__2.r = z__3.r - z__4.r, z__2.i = z__3.i - z__4.i;
    z__1.r = -z__2.r, z__1.i = -z__2.i;
    cx.r = z__1.r, cx.i = z__1.i;
    z__3.r = qy * rrh.r, z__3.i = qy * rrh.i;
    z__4.r = cph * tt1.r, z__4.i = cph * tt1.i;
    z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
    z__1.r = -z__2.r, z__1.i = -z__2.i;
    cy.r = z__1.r, cy.i = z__1.i;
    z__1.r = qz * rrh.r, z__1.i = qz * rrh.i;
    cz.r = z__1.r, cz.i = z__1.i;
    i__ = data_1.ld + 1;
    i1 = data_1.n - 1;
    i__2 = data_1.m;
    for (is = 1; is <= i__2; ++is) {
	--i__;
	i1 += 2;
	i2 = i1 + 1;
	arg = -tp * (wx * data_1.x[i__ - 1] + wy * data_1.y[i__ - 1] - wz * 
		data_1.z__[i__ - 1]);
	d__1 = cos(arg);
	d__2 = sin(arg);
	z__3.r = d__1, z__3.i = d__2;
	i__1 = i__ - 1;
	z__2.r = angl_1.salp[i__1] * z__3.r, z__2.i = angl_1.salp[i__1] * 
		z__3.i;
	z__1.r = reta * z__2.r, z__1.i = reta * z__2.i;
	tt1.r = z__1.r, tt1.i = z__1.i;
	i__1 = i2;
	i__4 = i2;
	i__5 = i__ - 1;
	z__5.r = t1x[i__5] * cx.r, z__5.i = t1x[i__5] * cx.i;
	i__6 = i__ - 1;
	z__6.r = t1y[i__6] * cy.r, z__6.i = t1y[i__6] * cy.i;
	z__4.r = z__5.r + z__6.r, z__4.i = z__5.i + z__6.i;
	i__3 = i__ - 1;
	z__7.r = t1z[i__3] * cz.r, z__7.i = t1z[i__3] * cz.i;
	z__3.r = z__4.r + z__7.r, z__3.i = z__4.i + z__7.i;
	z__2.r = z__3.r * tt1.r - z__3.i * tt1.i, z__2.i = z__3.r * tt1.i + 
		z__3.i * tt1.r;
	z__1.r = e[i__4].r + z__2.r, z__1.i = e[i__4].i + z__2.i;
	e[i__1].r = z__1.r, e[i__1].i = z__1.i;
/* L12: */
	i__1 = i1;
	i__4 = i1;
	i__5 = i__ - 1;
	z__5.r = t2x[i__5] * cx.r, z__5.i = t2x[i__5] * cx.i;
	i__6 = i__ - 1;
	z__6.r = t2y[i__6] * cy.r, z__6.i = t2y[i__6] * cy.i;
	z__4.r = z__5.r + z__6.r, z__4.i = z__5.i + z__6.i;
	i__3 = i__ - 1;
	z__7.r = t2z[i__3] * cz.r, z__7.i = t2z[i__3] * cz.i;
	z__3.r = z__4.r + z__7.r, z__3.i = z__4.i + z__7.i;
	z__2.r = z__3.r * tt1.r - z__3.i * tt1.i, z__2.i = z__3.r * tt1.i + 
		z__3.i * tt1.r;
	z__1.r = e[i__4].r + z__2.r, z__1.i = e[i__4].i + z__2.i;
	e[i__1].r = z__1.r, e[i__1].i = z__1.i;
    }
    return 0;

/*     INCIDENT PLANE WAVE, ELLIPTIC POLARIZATION. */

L13:
    z__1.r = *p6 * -0.f, z__1.i = *p6 * -1.f;
    tt1.r = z__1.r, tt1.i = z__1.i;
    if (*ipr == 3) {
	z__1.r = -tt1.r, z__1.i = -tt1.i;
	tt1.r = z__1.r, tt1.i = z__1.i;
    }
    if (data_1.n == 0) {
	goto L16;
    }
    z__2.r = qx * tt1.r, z__2.i = qx * tt1.i;
    z__1.r = px + z__2.r, z__1.i = z__2.i;
    cx.r = z__1.r, cx.i = z__1.i;
    z__2.r = qy * tt1.r, z__2.i = qy * tt1.i;
    z__1.r = py + z__2.r, z__1.i = z__2.i;
    cy.r = z__1.r, cy.i = z__1.i;
    z__2.r = qz * tt1.r, z__2.i = qz * tt1.i;
    z__1.r = pz + z__2.r, z__1.i = z__2.i;
    cz.r = z__1.r, cz.i = z__1.i;
    i__1 = data_1.n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	arg = -tp * (wx * data_1.x[i__ - 1] + wy * data_1.y[i__ - 1] + wz * 
		data_1.z__[i__ - 1]);
/* L14: */
	i__4 = i__;
	i__5 = i__ - 1;
	z__5.r = cab[i__5] * cx.r, z__5.i = cab[i__5] * cx.i;
	i__6 = i__ - 1;
	z__6.r = sab[i__6] * cy.r, z__6.i = sab[i__6] * cy.i;
	z__4.r = z__5.r + z__6.r, z__4.i = z__5.i + z__6.i;
	i__3 = i__ - 1;
	z__7.r = angl_1.salp[i__3] * cz.r, z__7.i = angl_1.salp[i__3] * cz.i;
	z__3.r = z__4.r + z__7.r, z__3.i = z__4.i + z__7.i;
	z__2.r = -z__3.r, z__2.i = -z__3.i;
	d__1 = cos(arg);
	d__2 = sin(arg);
	z__8.r = d__1, z__8.i = d__2;
	z__1.r = z__2.r * z__8.r - z__2.i * z__8.i, z__1.i = z__2.r * z__8.i 
		+ z__2.i * z__8.r;
	e[i__4].r = z__1.r, e[i__4].i = z__1.i;
    }
    if (gnd_1.ksymp == 1) {
	goto L16;
    }
    z__3.r = cph * cy.r, z__3.i = cph * cy.i;
    z__4.r = sph * cx.r, z__4.i = sph * cx.i;
    z__2.r = z__3.r - z__4.r, z__2.i = z__3.i - z__4.i;
    z__5.r = rrh.r - rrv.r, z__5.i = rrh.i - rrv.i;
    z__1.r = z__2.r * z__5.r - z__2.i * z__5.i, z__1.i = z__2.r * z__5.i + 
	    z__2.i * z__5.r;
    tt2.r = z__1.r, tt2.i = z__1.i;
    z__2.r = rrv.r * cx.r - rrv.i * cx.i, z__2.i = rrv.r * cx.i + rrv.i * 
	    cx.r;
    z__3.r = sph * tt2.r, z__3.i = sph * tt2.i;
    z__1.r = z__2.r - z__3.r, z__1.i = z__2.i - z__3.i;
    cx.r = z__1.r, cx.i = z__1.i;
    z__2.r = rrv.r * cy.r - rrv.i * cy.i, z__2.i = rrv.r * cy.i + rrv.i * 
	    cy.r;
    z__3.r = cph * tt2.r, z__3.i = cph * tt2.i;
    z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
    cy.r = z__1.r, cy.i = z__1.i;
    z__2.r = -rrv.r, z__2.i = -rrv.i;
    z__1.r = z__2.r * cz.r - z__2.i * cz.i, z__1.i = z__2.r * cz.i + z__2.i * 
	    cz.r;
    cz.r = z__1.r, cz.i = z__1.i;
    i__4 = data_1.n;
    for (i__ = 1; i__ <= i__4; ++i__) {
	arg = -tp * (wx * data_1.x[i__ - 1] + wy * data_1.y[i__ - 1] - wz * 
		data_1.z__[i__ - 1]);
/* L15: */
	i__5 = i__;
	i__6 = i__;
	i__3 = i__ - 1;
	z__5.r = cab[i__3] * cx.r, z__5.i = cab[i__3] * cx.i;
	i__1 = i__ - 1;
	z__6.r = sab[i__1] * cy.r, z__6.i = sab[i__1] * cy.i;
	z__4.r = z__5.r + z__6.r, z__4.i = z__5.i + z__6.i;
	i__2 = i__ - 1;
	z__7.r = angl_1.salp[i__2] * cz.r, z__7.i = angl_1.salp[i__2] * cz.i;
	z__3.r = z__4.r + z__7.r, z__3.i = z__4.i + z__7.i;
	d__1 = cos(arg);
	d__2 = sin(arg);
	z__8.r = d__1, z__8.i = d__2;
	z__2.r = z__3.r * z__8.r - z__3.i * z__8.i, z__2.i = z__3.r * z__8.i 
		+ z__3.i * z__8.r;
	z__1.r = e[i__6].r - z__2.r, z__1.i = e[i__6].i - z__2.i;
	e[i__5].r = z__1.r, e[i__5].i = z__1.i;
    }
L16:
    if (data_1.m == 0) {
	return 0;
    }
    z__2.r = px * tt1.r, z__2.i = px * tt1.i;
    z__1.r = qx - z__2.r, z__1.i = -z__2.i;
    cx.r = z__1.r, cx.i = z__1.i;
    z__2.r = py * tt1.r, z__2.i = py * tt1.i;
    z__1.r = qy - z__2.r, z__1.i = -z__2.i;
    cy.r = z__1.r, cy.i = z__1.i;
    z__2.r = pz * tt1.r, z__2.i = pz * tt1.i;
    z__1.r = qz - z__2.r, z__1.i = -z__2.i;
    cz.r = z__1.r, cz.i = z__1.i;
    i__ = data_1.ld + 1;
    i1 = data_1.n - 1;
    i__5 = data_1.m;
    for (is = 1; is <= i__5; ++is) {
	--i__;
	i1 += 2;
	i2 = i1 + 1;
	arg = -tp * (wx * data_1.x[i__ - 1] + wy * data_1.y[i__ - 1] + wz * 
		data_1.z__[i__ - 1]);
	d__1 = cos(arg);
	d__2 = sin(arg);
	z__3.r = d__1, z__3.i = d__2;
	i__6 = i__ - 1;
	z__2.r = angl_1.salp[i__6] * z__3.r, z__2.i = angl_1.salp[i__6] * 
		z__3.i;
	z__1.r = reta * z__2.r, z__1.i = reta * z__2.i;
	tt2.r = z__1.r, tt2.i = z__1.i;
	i__6 = i2;
	i__3 = i__ - 1;
	z__4.r = t1x[i__3] * cx.r, z__4.i = t1x[i__3] * cx.i;
	i__1 = i__ - 1;
	z__5.r = t1y[i__1] * cy.r, z__5.i = t1y[i__1] * cy.i;
	z__3.r = z__4.r + z__5.r, z__3.i = z__4.i + z__5.i;
	i__2 = i__ - 1;
	z__6.r = t1z[i__2] * cz.r, z__6.i = t1z[i__2] * cz.i;
	z__2.r = z__3.r + z__6.r, z__2.i = z__3.i + z__6.i;
	z__1.r = z__2.r * tt2.r - z__2.i * tt2.i, z__1.i = z__2.r * tt2.i + 
		z__2.i * tt2.r;
	e[i__6].r = z__1.r, e[i__6].i = z__1.i;
/* L17: */
	i__6 = i1;
	i__3 = i__ - 1;
	z__4.r = t2x[i__3] * cx.r, z__4.i = t2x[i__3] * cx.i;
	i__1 = i__ - 1;
	z__5.r = t2y[i__1] * cy.r, z__5.i = t2y[i__1] * cy.i;
	z__3.r = z__4.r + z__5.r, z__3.i = z__4.i + z__5.i;
	i__2 = i__ - 1;
	z__6.r = t2z[i__2] * cz.r, z__6.i = t2z[i__2] * cz.i;
	z__2.r = z__3.r + z__6.r, z__2.i = z__3.i + z__6.i;
	z__1.r = z__2.r * tt2.r - z__2.i * tt2.i, z__1.i = z__2.r * tt2.i + 
		z__2.i * tt2.r;
	e[i__6].r = z__1.r, e[i__6].i = z__1.i;
    }
    if (gnd_1.ksymp == 1) {
	return 0;
    }
    z__3.r = cph * cy.r, z__3.i = cph * cy.i;
    z__4.r = sph * cx.r, z__4.i = sph * cx.i;
    z__2.r = z__3.r - z__4.r, z__2.i = z__3.i - z__4.i;
    z__5.r = rrv.r - rrh.r, z__5.i = rrv.i - rrh.i;
    z__1.r = z__2.r * z__5.r - z__2.i * z__5.i, z__1.i = z__2.r * z__5.i + 
	    z__2.i * z__5.r;
    tt1.r = z__1.r, tt1.i = z__1.i;
    z__3.r = rrh.r * cx.r - rrh.i * cx.i, z__3.i = rrh.r * cx.i + rrh.i * 
	    cx.r;
    z__4.r = sph * tt1.r, z__4.i = sph * tt1.i;
    z__2.r = z__3.r - z__4.r, z__2.i = z__3.i - z__4.i;
    z__1.r = -z__2.r, z__1.i = -z__2.i;
    cx.r = z__1.r, cx.i = z__1.i;
    z__3.r = rrh.r * cy.r - rrh.i * cy.i, z__3.i = rrh.r * cy.i + rrh.i * 
	    cy.r;
    z__4.r = cph * tt1.r, z__4.i = cph * tt1.i;
    z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
    z__1.r = -z__2.r, z__1.i = -z__2.i;
    cy.r = z__1.r, cy.i = z__1.i;
    z__1.r = rrh.r * cz.r - rrh.i * cz.i, z__1.i = rrh.r * cz.i + rrh.i * 
	    cz.r;
    cz.r = z__1.r, cz.i = z__1.i;
    i__ = data_1.ld + 1;
    i1 = data_1.n - 1;
    i__6 = data_1.m;
    for (is = 1; is <= i__6; ++is) {
	--i__;
	i1 += 2;
	i2 = i1 + 1;
	arg = -tp * (wx * data_1.x[i__ - 1] + wy * data_1.y[i__ - 1] - wz * 
		data_1.z__[i__ - 1]);
	d__1 = cos(arg);
	d__2 = sin(arg);
	z__3.r = d__1, z__3.i = d__2;
	i__3 = i__ - 1;
	z__2.r = angl_1.salp[i__3] * z__3.r, z__2.i = angl_1.salp[i__3] * 
		z__3.i;
	z__1.r = reta * z__2.r, z__1.i = reta * z__2.i;
	tt1.r = z__1.r, tt1.i = z__1.i;
	i__3 = i2;
	i__1 = i2;
	i__2 = i__ - 1;
	z__5.r = t1x[i__2] * cx.r, z__5.i = t1x[i__2] * cx.i;
	i__5 = i__ - 1;
	z__6.r = t1y[i__5] * cy.r, z__6.i = t1y[i__5] * cy.i;
	z__4.r = z__5.r + z__6.r, z__4.i = z__5.i + z__6.i;
	i__4 = i__ - 1;
	z__7.r = t1z[i__4] * cz.r, z__7.i = t1z[i__4] * cz.i;
	z__3.r = z__4.r + z__7.r, z__3.i = z__4.i + z__7.i;
	z__2.r = z__3.r * tt1.r - z__3.i * tt1.i, z__2.i = z__3.r * tt1.i + 
		z__3.i * tt1.r;
	z__1.r = e[i__1].r + z__2.r, z__1.i = e[i__1].i + z__2.i;
	e[i__3].r = z__1.r, e[i__3].i = z__1.i;
/* L18: */
	i__3 = i1;
	i__1 = i1;
	i__2 = i__ - 1;
	z__5.r = t2x[i__2] * cx.r, z__5.i = t2x[i__2] * cx.i;
	i__5 = i__ - 1;
	z__6.r = t2y[i__5] * cy.r, z__6.i = t2y[i__5] * cy.i;
	z__4.r = z__5.r + z__6.r, z__4.i = z__5.i + z__6.i;
	i__4 = i__ - 1;
	z__7.r = t2z[i__4] * cz.r, z__7.i = t2z[i__4] * cz.i;
	z__3.r = z__4.r + z__7.r, z__3.i = z__4.i + z__7.i;
	z__2.r = z__3.r * tt1.r - z__3.i * tt1.i, z__2.i = z__3.r * tt1.i + 
		z__3.i * tt1.r;
	z__1.r = e[i__1].r + z__2.r, z__1.i = e[i__1].i + z__2.i;
	e[i__3].r = z__1.r, e[i__3].i = z__1.i;
    }
    return 0;

/*     INCIDENT FIELD OF AN ELEMENTARY CURRENT SOURCE. */

L19:
    wz = cos(*p4);
    wx = wz * cos(*p5);
    wy = wz * sin(*p5);
    wz = sin(*p4);
    ds = *p6 * 59.958f;
    dsh = *p6 / (tp * 2.f);
    npm = data_1.n + data_1.m;
    is = data_1.ld + 1;
    i1 = data_1.n - 1;
    i__3 = npm;
    for (i__ = 1; i__ <= i__3; ++i__) {
	ii = i__;
	if (i__ <= data_1.n) {
	    goto L20;
	}
	--is;
	ii = is;
	i1 += 2;
	i2 = i1 + 1;
L20:
	px = data_1.x[ii - 1] - *p1;
	py = data_1.y[ii - 1] - *p2;
	pz = data_1.z__[ii - 1] - *p3;
	rs = px * px + py * py + pz * pz;
	if (rs < 1e-30) {
	    goto L24;
	}
	r__ = sqrt(rs);
	px /= r__;
	py /= r__;
	pz /= r__;
	cth = px * wx + py * wy + pz * wz;
	sth = sqrt(1.f - cth * cth);
	qx = px - wx * cth;
	qy = py - wy * cth;
	qz = pz - wz * cth;
	arg = sqrt(qx * qx + qy * qy + qz * qz);
	if (arg < 1e-30) {
	    goto L21;
	}
	qx /= arg;
	qy /= arg;
	qz /= arg;
	goto L22;
L21:
	qx = 1.f;
	qy = 0.f;
	qz = 0.f;
L22:
	arg = -tp * r__;
	d__1 = cos(arg);
	d__2 = sin(arg);
	z__1.r = d__1, z__1.i = d__2;
	tt1.r = z__1.r, tt1.i = z__1.i;
	if (i__ > data_1.n) {
	    goto L23;
	}
	d__1 = -1. / (r__ * tp);
	z__2.r = 1., z__2.i = d__1;
	z__1.r = z__2.r / rs, z__1.i = z__2.i / rs;
	tt2.r = z__1.r, tt2.i = z__1.i;
	z__3.r = ds * tt1.r, z__3.i = ds * tt1.i;
	z__2.r = z__3.r * tt2.r - z__3.i * tt2.i, z__2.i = z__3.r * tt2.i + 
		z__3.i * tt2.r;
	z__1.r = cth * z__2.r, z__1.i = cth * z__2.i;
	er.r = z__1.r, er.i = z__1.i;
	d__1 = ds * .5f;
	z__3.r = d__1 * tt1.r, z__3.i = d__1 * tt1.i;
	z__6.r = tp * 0.f, z__6.i = tp * 1.f;
	z__5.r = z__6.r / r__, z__5.i = z__6.i / r__;
	z__4.r = z__5.r + tt2.r, z__4.i = z__5.i + tt2.i;
	z__2.r = z__3.r * z__4.r - z__3.i * z__4.i, z__2.i = z__3.r * z__4.i 
		+ z__3.i * z__4.r;
	z__1.r = sth * z__2.r, z__1.i = sth * z__2.i;
	et.r = z__1.r, et.i = z__1.i;
	z__2.r = cth * er.r, z__2.i = cth * er.i;
	z__3.r = sth * et.r, z__3.i = sth * et.i;
	z__1.r = z__2.r - z__3.r, z__1.i = z__2.i - z__3.i;
	ezh.r = z__1.r, ezh.i = z__1.i;
	z__2.r = sth * er.r, z__2.i = sth * er.i;
	z__3.r = cth * et.r, z__3.i = cth * et.i;
	z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
	erh.r = z__1.r, erh.i = z__1.i;
	z__2.r = wx * ezh.r, z__2.i = wx * ezh.i;
	z__3.r = qx * erh.r, z__3.i = qx * erh.i;
	z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
	cx.r = z__1.r, cx.i = z__1.i;
	z__2.r = wy * ezh.r, z__2.i = wy * ezh.i;
	z__3.r = qy * erh.r, z__3.i = qy * erh.i;
	z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
	cy.r = z__1.r, cy.i = z__1.i;
	z__2.r = wz * ezh.r, z__2.i = wz * ezh.i;
	z__3.r = qz * erh.r, z__3.i = qz * erh.i;
	z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
	cz.r = z__1.r, cz.i = z__1.i;
	i__1 = i__;
	i__2 = i__ - 1;
	z__4.r = cab[i__2] * cx.r, z__4.i = cab[i__2] * cx.i;
	i__5 = i__ - 1;
	z__5.r = sab[i__5] * cy.r, z__5.i = sab[i__5] * cy.i;
	z__3.r = z__4.r + z__5.r, z__3.i = z__4.i + z__5.i;
	i__4 = i__ - 1;
	z__6.r = angl_1.salp[i__4] * cz.r, z__6.i = angl_1.salp[i__4] * cz.i;
	z__2.r = z__3.r + z__6.r, z__2.i = z__3.i + z__6.i;
	z__1.r = -z__2.r, z__1.i = -z__2.i;
	e[i__1].r = z__1.r, e[i__1].i = z__1.i;
	goto L24;
L23:
	px = wy * qz - wz * qy;
	py = wz * qx - wx * qz;
	pz = wx * qy - wy * qx;
	z__5.r = dsh * tt1.r, z__5.i = dsh * tt1.i;
	d__1 = 1.f / r__;
	z__6.r = d__1, z__6.i = tp;
	z__4.r = z__5.r * z__6.r - z__5.i * z__6.i, z__4.i = z__5.r * z__6.i 
		+ z__5.i * z__6.r;
	z__3.r = z__4.r / r__, z__3.i = z__4.i / r__;
	z__2.r = sth * z__3.r, z__2.i = sth * z__3.i;
	i__1 = ii - 1;
	z__1.r = angl_1.salp[i__1] * z__2.r, z__1.i = angl_1.salp[i__1] * 
		z__2.i;
	tt2.r = z__1.r, tt2.i = z__1.i;
	z__1.r = px * tt2.r, z__1.i = px * tt2.i;
	cx.r = z__1.r, cx.i = z__1.i;
	z__1.r = py * tt2.r, z__1.i = py * tt2.i;
	cy.r = z__1.r, cy.i = z__1.i;
	z__1.r = pz * tt2.r, z__1.i = pz * tt2.i;
	cz.r = z__1.r, cz.i = z__1.i;
	i__1 = i2;
	i__2 = ii - 1;
	z__3.r = t1x[i__2] * cx.r, z__3.i = t1x[i__2] * cx.i;
	i__5 = ii - 1;
	z__4.r = t1y[i__5] * cy.r, z__4.i = t1y[i__5] * cy.i;
	z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
	i__4 = ii - 1;
	z__5.r = t1z[i__4] * cz.r, z__5.i = t1z[i__4] * cz.i;
	z__1.r = z__2.r + z__5.r, z__1.i = z__2.i + z__5.i;
	e[i__1].r = z__1.r, e[i__1].i = z__1.i;
	i__1 = i1;
	i__2 = ii - 1;
	z__3.r = t2x[i__2] * cx.r, z__3.i = t2x[i__2] * cx.i;
	i__5 = ii - 1;
	z__4.r = t2y[i__5] * cy.r, z__4.i = t2y[i__5] * cy.i;
	z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
	i__4 = ii - 1;
	z__5.r = t2z[i__4] * cz.r, z__5.i = t2z[i__4] * cz.i;
	z__1.r = z__2.r + z__5.r, z__1.i = z__2.i + z__5.i;
	e[i__1].r = z__1.r, e[i__1].i = z__1.i;
L24:
	;
    }
    return 0;
} /* etmns_ */

#undef sab
#undef cab
#undef t2z
#undef t2y
#undef t2x
#undef t1z
#undef t1y
#undef t1x


/* Subroutine */ int facgf_(doublecomplex *a, doublecomplex *b, doublecomplex 
	*c__, doublecomplex *d__, doublecomplex *bx, integer *ip, integer *ix,
	 integer *np, integer *n1, integer *mp, integer *m1, integer *n1c, 
	integer *n2c)
{
    /* System generated locals */
    integer b_dim1, b_offset, c_dim1, c_offset, d_dim1, d_offset, bx_dim1, 
	    bx_offset, i__1, i__2, i__3, i__4, i__5, i__6, i__7;
    doublecomplex z__1, z__2;
    alist al__1;

    /* Builtin functions */
    integer f_rew(alist *), s_rsue(cilist *), do_uio(integer *, char *, 
	    ftnlen), e_rsue(void), s_wsue(cilist *), e_wsue(void);

    /* Local variables */
    integer i__, j, k, ib, ic, ii, nic, npb, npc;
    doublecomplex sum;
    integer n1cp, ibfl;
    extern /* Subroutine */ int facio_(doublecomplex *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *), reblk_(
	    doublecomplex *, doublecomplex *, integer *, integer *, integer *)
	    , factr_(integer *, doublecomplex *, integer *, integer *);
    integer icass, nlsys, npsys;
    extern /* Subroutine */ int lunscr_(doublecomplex *, integer *, integer *,
	     integer *, integer *, integer *, integer *, integer *);
    integer nblsys;
    extern /* Subroutine */ int solves_(doublecomplex *, integer *, 
	    doublecomplex *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *);

    /* Fortran I/O blocks */
    static cilist io___907 = { 0, 0, 0, 0, 0 };
    static cilist io___910 = { 0, 14, 0, 0, 0 };
    static cilist io___913 = { 0, 15, 0, 0, 0 };
    static cilist io___914 = { 0, 12, 0, 0, 0 };
    static cilist io___916 = { 0, 14, 0, 0, 0 };
    static cilist io___920 = { 0, 11, 0, 0, 0 };
    static cilist io___922 = { 0, 11, 0, 0, 0 };
    static cilist io___923 = { 0, 11, 0, 0, 0 };


/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* *** */
/*     FACGF COMPUTES AND FACTORS D-C(INV(A)B). */
    /* Parameter adjustments */
    --a;
    --ip;
    --ix;
    bx_dim1 = *n1c;
    bx_offset = 1 + bx_dim1;
    bx -= bx_offset;
    c_dim1 = *n1c;
    c_offset = 1 + c_dim1;
    c__ -= c_offset;
    b_dim1 = *n1c;
    b_offset = 1 + b_dim1;
    b -= b_offset;
    d_dim1 = *n2c;
    d_offset = 1 + d_dim1;
    d__ -= d_offset;

    /* Function Body */
    if (*n2c == 0) {
	return 0;
    }
    ibfl = 14;
    if (matpar_1.icasx < 3) {
	goto L1;
    }
/*     CONVERT B FROM BLOCKS OF ROWS ON T14 TO BLOCKS OF COL. ON T16 */
    reblk_(&b[b_offset], &c__[c_offset], n1c, &matpar_1.npbx, n2c);
    ibfl = 16;
L1:
    npb = matpar_1.npbl;
    if (matpar_1.icasx == 2) {
	al__1.aerr = 0;
	al__1.aunit = 14;
	f_rew(&al__1);
    }
/*     COMPUTE INV(A)B AND WRITE ON TAPE14 */
    i__1 = matpar_1.nbbl;
    for (ib = 1; ib <= i__1; ++ib) {
	if (ib == matpar_1.nbbl) {
	    npb = matpar_1.nlbl;
	}
	if (matpar_1.icasx > 1) {
	    io___907.ciunit = ibfl;
	    s_rsue(&io___907);
	    i__2 = npb;
	    for (j = 1; j <= i__2; ++j) {
		i__3 = *n1c;
		for (i__ = 1; i__ <= i__3; ++i__) {
		    do_uio(&c__2, (char *)&bx[i__ + j * bx_dim1], (ftnlen)
			    sizeof(doublereal));
		}
	    }
	    e_rsue();
	}
	solves_(&a[1], &ip[1], &bx[bx_offset], n1c, &npb, np, n1, mp, m1, &
		c__13, &c__13);
	if (matpar_1.icasx == 2) {
	    al__1.aerr = 0;
	    al__1.aunit = 14;
	    f_rew(&al__1);
	}
	if (matpar_1.icasx > 1) {
	    s_wsue(&io___910);
	    i__3 = npb;
	    for (j = 1; j <= i__3; ++j) {
		i__2 = *n1c;
		for (i__ = 1; i__ <= i__2; ++i__) {
		    do_uio(&c__2, (char *)&bx[i__ + j * bx_dim1], (ftnlen)
			    sizeof(doublereal));
		}
	    }
	    e_wsue();
	}
/* L2: */
    }
    if (matpar_1.icasx == 1) {
	goto L3;
    }
    al__1.aerr = 0;
    al__1.aunit = 11;
    f_rew(&al__1);
    al__1.aerr = 0;
    al__1.aunit = 12;
    f_rew(&al__1);
    al__1.aerr = 0;
    al__1.aunit = 15;
    f_rew(&al__1);
    al__1.aerr = 0;
    al__1.aunit = ibfl;
    f_rew(&al__1);
L3:
    npc = matpar_1.npbl;
/*     COMPUTE D-C(INV(A)B) AND WRITE ON TAPE11 */
    i__1 = matpar_1.nbbl;
    for (ic = 1; ic <= i__1; ++ic) {
	if (ic == matpar_1.nbbl) {
	    npc = matpar_1.nlbl;
	}
	if (matpar_1.icasx == 1) {
	    goto L4;
	}
	s_rsue(&io___913);
	i__2 = npc;
	for (j = 1; j <= i__2; ++j) {
	    i__3 = *n1c;
	    for (i__ = 1; i__ <= i__3; ++i__) {
		do_uio(&c__2, (char *)&c__[i__ + j * c_dim1], (ftnlen)sizeof(
			doublereal));
	    }
	}
	e_rsue();
	s_rsue(&io___914);
	i__3 = npc;
	for (j = 1; j <= i__3; ++j) {
	    i__2 = *n2c;
	    for (i__ = 1; i__ <= i__2; ++i__) {
		do_uio(&c__2, (char *)&d__[i__ + j * d_dim1], (ftnlen)sizeof(
			doublereal));
	    }
	}
	e_rsue();
	al__1.aerr = 0;
	al__1.aunit = 14;
	f_rew(&al__1);
L4:
	npb = matpar_1.npbl;
	nic = 0;
	i__2 = matpar_1.nbbl;
	for (ib = 1; ib <= i__2; ++ib) {
	    if (ib == matpar_1.nbbl) {
		npb = matpar_1.nlbl;
	    }
	    if (matpar_1.icasx > 1) {
		s_rsue(&io___916);
		i__3 = npb;
		for (j = 1; j <= i__3; ++j) {
		    i__4 = *n1c;
		    for (i__ = 1; i__ <= i__4; ++i__) {
			do_uio(&c__2, (char *)&b[i__ + j * b_dim1], (ftnlen)
				sizeof(doublereal));
		    }
		}
		e_rsue();
	    }
	    i__4 = npb;
	    for (i__ = 1; i__ <= i__4; ++i__) {
		ii = i__ + nic;
		i__3 = npc;
		for (j = 1; j <= i__3; ++j) {
		    sum.r = 0.f, sum.i = 0.f;
		    i__5 = *n1c;
		    for (k = 1; k <= i__5; ++k) {
/* L5: */
			i__6 = k + i__ * b_dim1;
			i__7 = k + j * c_dim1;
			z__2.r = b[i__6].r * c__[i__7].r - b[i__6].i * c__[
				i__7].i, z__2.i = b[i__6].r * c__[i__7].i + b[
				i__6].i * c__[i__7].r;
			z__1.r = sum.r + z__2.r, z__1.i = sum.i + z__2.i;
			sum.r = z__1.r, sum.i = z__1.i;
		    }
/* L6: */
		    i__6 = ii + j * d_dim1;
		    i__7 = ii + j * d_dim1;
		    z__1.r = d__[i__7].r - sum.r, z__1.i = d__[i__7].i - 
			    sum.i;
		    d__[i__6].r = z__1.r, d__[i__6].i = z__1.i;
		}
	    }
/* L7: */
	    nic += matpar_1.npbl;
	}
	if (matpar_1.icasx > 1) {
	    s_wsue(&io___920);
	    i__2 = matpar_1.npbl;
	    for (j = 1; j <= i__2; ++j) {
		i__6 = *n2c;
		for (i__ = 1; i__ <= i__6; ++i__) {
		    do_uio(&c__2, (char *)&d__[i__ + j * d_dim1], (ftnlen)
			    sizeof(doublereal));
		}
	    }
	    e_wsue();
	}
/* L8: */
    }
    if (matpar_1.icasx == 1) {
	goto L9;
    }
    al__1.aerr = 0;
    al__1.aunit = 11;
    f_rew(&al__1);
    al__1.aerr = 0;
    al__1.aunit = 12;
    f_rew(&al__1);
    al__1.aerr = 0;
    al__1.aunit = 14;
    f_rew(&al__1);
    al__1.aerr = 0;
    al__1.aunit = 15;
    f_rew(&al__1);
L9:
    n1cp = *n1c + 1;
/*     FACTOR D-C(INV(A)B) */
    if (matpar_1.icasx > 1) {
	goto L10;
    }
    factr_(n2c, &d__[d_offset], &ip[n1cp], n2c);
    goto L13;
L10:
    if (matpar_1.icasx == 4) {
	goto L12;
    }
    npb = matpar_1.npbl;
    ic = 0;
    i__1 = matpar_1.nbbl;
    for (ib = 1; ib <= i__1; ++ib) {
	if (ib == matpar_1.nbbl) {
	    npb = matpar_1.nlbl;
	}
	ii = ic + 1;
	ic += *n2c * npb;
/* L11: */
	s_rsue(&io___922);
	i__6 = ic;
	for (i__ = ii; i__ <= i__6; ++i__) {
	    do_uio(&c__2, (char *)&b[i__ + b_dim1], (ftnlen)sizeof(doublereal)
		    );
	}
	e_rsue();
    }
    al__1.aerr = 0;
    al__1.aunit = 11;
    f_rew(&al__1);
    factr_(n2c, &b[b_offset], &ip[n1cp], n2c);
    nic = *n2c * *n2c;
    s_wsue(&io___923);
    i__6 = nic;
    for (i__ = 1; i__ <= i__6; ++i__) {
	do_uio(&c__2, (char *)&b[i__ + b_dim1], (ftnlen)sizeof(doublereal));
    }
    e_wsue();
    al__1.aerr = 0;
    al__1.aunit = 11;
    f_rew(&al__1);
    goto L13;
L12:
    nblsys = matpar_1.nblsym;
    npsys = matpar_1.npsym;
    nlsys = matpar_1.nlsym;
    icass = matpar_1.icase;
    matpar_1.nblsym = matpar_1.nbbl;
    matpar_1.npsym = matpar_1.npbl;
    matpar_1.nlsym = matpar_1.nlbl;
    matpar_1.icase = 3;
    facio_(&b[b_offset], n2c, &c__1, &ix[n1cp], &c__11, &c__12, &c__16, &
	    c__11);
    lunscr_(&b[b_offset], n2c, &c__1, &ip[n1cp], &ix[n1cp], &c__12, &c__11, &
	    c__16);
    matpar_1.nblsym = nblsys;
    matpar_1.npsym = npsys;
    matpar_1.nlsym = nlsys;
    matpar_1.icase = icass;
L13:
    return 0;
} /* facgf_ */

/* Subroutine */ int facio_(doublecomplex *a, integer *nrow, integer *nop, 
	integer *ip, integer *iu1, integer *iu2, integer *iu3, integer *iu4)
{
    /* Format strings */
    static char fmt_4[] = "(\002 CP TIME TAKEN FOR FACTORIZATION = \002,1p,e"
	    "12.5)";

    /* System generated locals */
    integer a_dim1, a_offset, i__1, i__2, i__3;
    alist al__1;

    /* Builtin functions */
    integer f_rew(alist *), s_wsfe(cilist *), do_fio(integer *, char *, 
	    ftnlen), e_wsfe(void);

    /* Local variables */
    integer i1, i2, i3, i4;
    doublereal t1, t2;
    integer ka, kk, it, nbm;
    doublereal time;
    integer ixbp, ifile3, ifile4, ixblk1, ixblk2;
    extern /* Subroutine */ int blckin_(doublecomplex *, integer *, integer *,
	     integer *, integer *, integer *), second_(doublereal *), lfactr_(
	    doublecomplex *, integer *, integer *, integer *, integer *), 
	    blckot_(doublecomplex *, integer *, integer *, integer *, integer 
	    *, integer *);

    /* Fortran I/O blocks */
    static cilist io___944 = { 0, 3, 0, fmt_4, 0 };


/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* *** */

/*     FACIO CONTROLS I/O FOR OUT-OF-CORE FACTORIZATION */

    /* Parameter adjustments */
    --ip;
    a_dim1 = *nrow;
    a_offset = 1 + a_dim1;
    a -= a_offset;

    /* Function Body */
    it = (matpar_1.npsym << 1) * *nrow;
    nbm = matpar_1.nblsym - 1;
    i1 = 1;
    i2 = it;
    i3 = i2 + 1;
    i4 = it << 1;
    time = 0.f;
    al__1.aerr = 0;
    al__1.aunit = *iu1;
    f_rew(&al__1);
    al__1.aerr = 0;
    al__1.aunit = *iu2;
    f_rew(&al__1);
    i__1 = *nop;
    for (kk = 1; kk <= i__1; ++kk) {
	ka = (kk - 1) * *nrow + 1;
	ifile3 = *iu1;
	ifile4 = *iu3;
	i__2 = nbm;
	for (ixblk1 = 1; ixblk1 <= i__2; ++ixblk1) {
	    al__1.aerr = 0;
	    al__1.aunit = *iu3;
	    f_rew(&al__1);
	    al__1.aerr = 0;
	    al__1.aunit = *iu4;
	    f_rew(&al__1);
	    blckin_(&a[a_offset], &ifile3, &i1, &i2, &c__1, &c__17);
	    ixbp = ixblk1 + 1;
	    i__3 = matpar_1.nblsym;
	    for (ixblk2 = ixbp; ixblk2 <= i__3; ++ixblk2) {
		blckin_(&a[a_offset], &ifile3, &i3, &i4, &c__1, &c__18);
		second_(&t1);
		lfactr_(&a[a_offset], nrow, &ixblk1, &ixblk2, &ip[ka]);
		second_(&t2);
		time = time + t2 - t1;
		if (ixblk2 == ixbp) {
		    blckot_(&a[a_offset], iu2, &i1, &i2, &c__1, &c__19);
		}
		if (ixblk1 == nbm && ixblk2 == matpar_1.nblsym) {
		    ifile4 = *iu2;
		}
		blckot_(&a[a_offset], &ifile4, &i3, &i4, &c__1, &c__20);
/* L1: */
	    }
	    ifile3 = *iu3;
	    ifile4 = *iu4;
	    if (ixblk1 / 2 << 1 != ixblk1) {
		goto L2;
	    }
	    ifile3 = *iu4;
	    ifile4 = *iu3;
L2:
	    ;
	}
/* L3: */
    }
    al__1.aerr = 0;
    al__1.aunit = *iu1;
    f_rew(&al__1);
    al__1.aerr = 0;
    al__1.aunit = *iu2;
    f_rew(&al__1);
    al__1.aerr = 0;
    al__1.aunit = *iu3;
    f_rew(&al__1);
    al__1.aerr = 0;
    al__1.aunit = *iu4;
    f_rew(&al__1);
    s_wsfe(&io___944);
    do_fio(&c__1, (char *)&time, (ftnlen)sizeof(doublereal));
    e_wsfe();
    return 0;

} /* facio_ */

/* Subroutine */ int factr_(integer *n, doublecomplex *a, integer *ip, 
	integer *ndim)
{
    /* Format strings */
    static char fmt_10[] = "(\002 \002,\002PIVOT(\002,i3,\002)=\002,1p,e16.8)"
	    ;

    /* System generated locals */
    integer a_dim1, a_offset, i__1, i__2, i__3, i__4, i__5, i__6;
    doublecomplex z__1, z__2;

    /* Builtin functions */
    void d_cnjg(doublecomplex *, doublecomplex *), z_div(doublecomplex *, 
	    doublecomplex *, doublecomplex *);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    integer i__, j, k, r__, pj, pr, jp1, rm1, rp1;
    doublecomplex arj;
    integer iflg;
    doublereal dmax__, elmag;

    /* Fortran I/O blocks */
    static cilist io___958 = { 0, 3, 0, fmt_10, 0 };


/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* Max number of segments 	(Windows-95 <= 4 */
/* max nr of 'in-core' alloc.	(MAXMAT <= MA */
/* Max number of LD cards */
/* Max number of EX cards */
/* Max number of segs connected to NT/TL */
/* *** */

/*     SUBROUTINE TO FACTOR A MATRIX INTO A UNIT LOWER TRIANGULAR MATRIX */
/*     AND AN UPPER TRIANGULAR MATRIX USING THE GAUSS-DOOLITTLE ALGORITHM */
/*     PRESENTED ON PAGES 411-416 OF A. RALSTON--A FIRST COURSE IN */
/*     NUMERICAL ANALYSIS.  COMMENTS BELOW REFER TO COMMENTS IN RALSTONS */
/*     TEXT.    (MATRIX TRANSPOSED. */


/*     Un-transpose the matrix for Gauss elimination */

    /* Parameter adjustments */
    --ip;
    a_dim1 = *ndim;
    a_offset = 1 + a_dim1;
    a -= a_offset;

    /* Function Body */
    i__1 = *n;
    for (i__ = 2; i__ <= i__1; ++i__) {
	i__2 = i__ - 1;
	for (j = 1; j <= i__2; ++j) {
	    i__3 = i__ + j * a_dim1;
	    arj.r = a[i__3].r, arj.i = a[i__3].i;
	    i__3 = i__ + j * a_dim1;
	    i__4 = j + i__ * a_dim1;
	    a[i__3].r = a[i__4].r, a[i__3].i = a[i__4].i;
	    i__3 = j + i__ * a_dim1;
	    a[i__3].r = arj.r, a[i__3].i = arj.i;
/* L11: */
	}
/* L12: */
    }
    iflg = 0;
    i__1 = *n;
    for (r__ = 1; r__ <= i__1; ++r__) {

/*     STEP 1 */

	i__2 = *n;
	for (k = 1; k <= i__2; ++k) {
	    i__3 = k - 1;
	    i__4 = k + r__ * a_dim1;
	    scratm_1.d__[i__3].r = a[i__4].r, scratm_1.d__[i__3].i = a[i__4]
		    .i;
/* L1: */
	}

/*     STEPS 2 AND 3 */

	rm1 = r__ - 1;
	if (rm1 < 1) {
	    goto L4;
	}
	i__2 = rm1;
	for (j = 1; j <= i__2; ++j) {
	    pj = ip[j];
	    i__3 = pj - 1;
	    arj.r = scratm_1.d__[i__3].r, arj.i = scratm_1.d__[i__3].i;
	    i__3 = j + r__ * a_dim1;
	    a[i__3].r = arj.r, a[i__3].i = arj.i;
	    i__3 = pj - 1;
	    i__4 = j - 1;
	    scratm_1.d__[i__3].r = scratm_1.d__[i__4].r, scratm_1.d__[i__3].i 
		    = scratm_1.d__[i__4].i;
	    jp1 = j + 1;
	    i__3 = *n;
	    for (i__ = jp1; i__ <= i__3; ++i__) {
		i__4 = i__ - 1;
		i__5 = i__ - 1;
		i__6 = i__ + j * a_dim1;
		z__2.r = a[i__6].r * arj.r - a[i__6].i * arj.i, z__2.i = a[
			i__6].r * arj.i + a[i__6].i * arj.r;
		z__1.r = scratm_1.d__[i__5].r - z__2.r, z__1.i = scratm_1.d__[
			i__5].i - z__2.i;
		scratm_1.d__[i__4].r = z__1.r, scratm_1.d__[i__4].i = z__1.i;
/* L2: */
	    }
/* L3: */
	}
L4:

/*     STEP 4 */

	i__2 = r__ - 1;
	d_cnjg(&z__2, &scratm_1.d__[r__ - 1]);
	z__1.r = scratm_1.d__[i__2].r * z__2.r - scratm_1.d__[i__2].i * 
		z__2.i, z__1.i = scratm_1.d__[i__2].r * z__2.i + scratm_1.d__[
		i__2].i * z__2.r;
	dmax__ = z__1.r;
	ip[r__] = r__;
	rp1 = r__ + 1;
	if (rp1 > *n) {
	    goto L6;
	}
	i__2 = *n;
	for (i__ = rp1; i__ <= i__2; ++i__) {
	    i__3 = i__ - 1;
	    d_cnjg(&z__2, &scratm_1.d__[i__ - 1]);
	    z__1.r = scratm_1.d__[i__3].r * z__2.r - scratm_1.d__[i__3].i * 
		    z__2.i, z__1.i = scratm_1.d__[i__3].r * z__2.i + 
		    scratm_1.d__[i__3].i * z__2.r;
	    elmag = z__1.r;
	    if (elmag < dmax__) {
		goto L5;
	    }
	    dmax__ = elmag;
	    ip[r__] = i__;
L5:
	    ;
	}
L6:
	if (dmax__ < 1e-10) {
	    iflg = 1;
	}
	pr = ip[r__];
	i__2 = r__ + r__ * a_dim1;
	i__3 = pr - 1;
	a[i__2].r = scratm_1.d__[i__3].r, a[i__2].i = scratm_1.d__[i__3].i;
	i__2 = pr - 1;
	i__3 = r__ - 1;
	scratm_1.d__[i__2].r = scratm_1.d__[i__3].r, scratm_1.d__[i__2].i = 
		scratm_1.d__[i__3].i;

/*     STEP 5 */

	if (rp1 > *n) {
	    goto L8;
	}
	z_div(&z__1, &c_b245, &a[r__ + r__ * a_dim1]);
	arj.r = z__1.r, arj.i = z__1.i;
	i__2 = *n;
	for (i__ = rp1; i__ <= i__2; ++i__) {
	    i__3 = i__ + r__ * a_dim1;
	    i__4 = i__ - 1;
	    z__1.r = scratm_1.d__[i__4].r * arj.r - scratm_1.d__[i__4].i * 
		    arj.i, z__1.i = scratm_1.d__[i__4].r * arj.i + 
		    scratm_1.d__[i__4].i * arj.r;
	    a[i__3].r = z__1.r, a[i__3].i = z__1.i;
/* L7: */
	}
L8:
	if (iflg == 0) {
	    goto L9;
	}
	s_wsfe(&io___958);
	do_fio(&c__1, (char *)&r__, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&dmax__, (ftnlen)sizeof(doublereal));
	e_wsfe();
	iflg = 0;
L9:
	;
    }
    return 0;

} /* factr_ */

/* Subroutine */ int factrs_(integer *np, integer *nrow, doublecomplex *a, 
	integer *ip, integer *ix, integer *iu1, integer *iu2, integer *iu3, 
	integer *iu4)
{
    /* System generated locals */
    integer i__1, i__2, i__3, i__4;
    alist al__1;

    /* Builtin functions */
    integer f_rew(alist *), s_wsue(cilist *), do_uio(integer *, char *, 
	    ftnlen), e_wsue(void), s_rsue(cilist *), e_rsue(void);

    /* Local variables */
    integer i__, j, k, l, i2, j2, ka, kk, ir1, ir2, nop, irr1, irr2;
    extern /* Subroutine */ int facio_(doublecomplex *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *), factr_(
	    integer *, doublecomplex *, integer *, integer *);
    integer icols;
    extern /* Subroutine */ int blckin_(doublecomplex *, integer *, integer *,
	     integer *, integer *, integer *), blckot_(doublecomplex *, 
	    integer *, integer *, integer *, integer *, integer *);
    integer icoldx;
    extern /* Subroutine */ int lunscr_(doublecomplex *, integer *, integer *,
	     integer *, integer *, integer *, integer *, integer *);

    /* Fortran I/O blocks */
    static cilist io___971 = { 0, 0, 0, 0, 0 };
    static cilist io___973 = { 0, 0, 0, 0, 0 };
    static cilist io___975 = { 0, 0, 0, 0, 0 };
    static cilist io___977 = { 0, 0, 0, 0, 0 };


/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* *** */

/*     FACTRS, FOR SYMMETRIC STRUCTURE, TRANSFORMS SUBMATRICIES TO FORM */
/*     MATRICIES OF THE SYMMETRIC MODES AND CALLS ROUTINE TO FACTOR */
/*     MATRICIES.  IF NO SYMMETRY, THE ROUTINE IS CALLED TO FACTOR THE */
/*     COMPLETE MATRIX. */

    /* Parameter adjustments */
    --ix;
    --ip;
    --a;

    /* Function Body */
    nop = *nrow / *np;
    if (matpar_1.icase > 2) {
	goto L2;
    }
    i__1 = nop;
    for (kk = 1; kk <= i__1; ++kk) {
	ka = (kk - 1) * *np + 1;
/* L1: */
	factr_(np, &a[ka], &ip[ka], nrow);
    }
    return 0;
L2:
    if (matpar_1.icase > 3) {
	goto L3;
    }

/*     FACTOR SUBMATRICIES, OR FACTOR COMPLETE MATRIX IF NO SYMMETRY */
/*     EXISTS. */

    facio_(&a[1], nrow, &nop, &ix[1], iu1, iu2, iu3, iu4);
    lunscr_(&a[1], nrow, &nop, &ip[1], &ix[1], iu2, iu3, iu4);
    return 0;

/*     REWRITE THE MATRICES BY COLUMNS ON TAPE 13 */

L3:
    i2 = (matpar_1.npblk << 1) * *nrow;
    al__1.aerr = 0;
    al__1.aunit = *iu2;
    f_rew(&al__1);
    i__1 = nop;
    for (k = 1; k <= i__1; ++k) {
	al__1.aerr = 0;
	al__1.aunit = *iu1;
	f_rew(&al__1);
	icols = matpar_1.npblk;
	ir2 = k * *np;
	ir1 = ir2 - *np + 1;
	i__2 = matpar_1.nbloks;
	for (l = 1; l <= i__2; ++l) {
	    if (matpar_1.nbloks == 1 && k > 1) {
		goto L4;
	    }
	    blckin_(&a[1], iu1, &c__1, &i2, &c__1, &c__602);
	    if (l == matpar_1.nbloks) {
		icols = matpar_1.nlast;
	    }
L4:
	    irr1 = ir1;
	    irr2 = ir2;
	    i__3 = icols;
	    for (icoldx = 1; icoldx <= i__3; ++icoldx) {
		io___971.ciunit = *iu2;
		s_wsue(&io___971);
		i__4 = irr2;
		for (i__ = irr1; i__ <= i__4; ++i__) {
		    do_uio(&c__2, (char *)&a[i__], (ftnlen)sizeof(doublereal))
			    ;
		}
		e_wsue();
		irr1 += *nrow;
		irr2 += *nrow;
/* L5: */
	    }
	}
    }
    al__1.aerr = 0;
    al__1.aunit = *iu1;
    f_rew(&al__1);
    al__1.aerr = 0;
    al__1.aunit = *iu2;
    f_rew(&al__1);
    if (matpar_1.icase == 5) {
	goto L8;
    }
    al__1.aerr = 0;
    al__1.aunit = *iu3;
    f_rew(&al__1);
    irr1 = *np * *np;
    i__3 = nop;
    for (kk = 1; kk <= i__3; ++kk) {
	ir1 = 1 - *np;
	ir2 = 0;
	i__2 = *np;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    ir1 += *np;
	    ir2 += *np;
/* L6: */
	    io___973.ciunit = *iu2;
	    s_rsue(&io___973);
	    i__1 = ir2;
	    for (j = ir1; j <= i__1; ++j) {
		do_uio(&c__2, (char *)&a[j], (ftnlen)sizeof(doublereal));
	    }
	    e_rsue();
	}
	ka = (kk - 1) * *np + 1;
	factr_(np, &a[1], &ip[ka], np);
	io___975.ciunit = *iu3;
	s_wsue(&io___975);
	i__1 = irr1;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_uio(&c__2, (char *)&a[i__], (ftnlen)sizeof(doublereal));
	}
	e_wsue();
/* L7: */
    }
    al__1.aerr = 0;
    al__1.aunit = *iu2;
    f_rew(&al__1);
    al__1.aerr = 0;
    al__1.aunit = *iu3;
    f_rew(&al__1);
    return 0;
L8:
    i2 = (matpar_1.npsym << 1) * *np;
    i__3 = nop;
    for (kk = 1; kk <= i__3; ++kk) {
	j2 = matpar_1.npsym;
	i__1 = matpar_1.nblsym;
	for (l = 1; l <= i__1; ++l) {
	    if (l == matpar_1.nblsym) {
		j2 = matpar_1.nlsym;
	    }
	    ir1 = 1 - *np;
	    ir2 = 0;
	    i__2 = j2;
	    for (j = 1; j <= i__2; ++j) {
		ir1 += *np;
		ir2 += *np;
/* L9: */
		io___977.ciunit = *iu2;
		s_rsue(&io___977);
		i__4 = ir2;
		for (i__ = ir1; i__ <= i__4; ++i__) {
		    do_uio(&c__2, (char *)&a[i__], (ftnlen)sizeof(doublereal))
			    ;
		}
		e_rsue();
	    }
/* L10: */
	    blckot_(&a[1], iu1, &c__1, &i2, &c__1, &c__193);
	}
    }
    al__1.aerr = 0;
    al__1.aunit = *iu1;
    f_rew(&al__1);
    facio_(&a[1], np, &nop, &ix[1], iu1, iu2, iu3, iu4);
    lunscr_(&a[1], np, &nop, &ip[1], &ix[1], iu2, iu3, iu4);
    return 0;
} /* factrs_ */

/* Double Complex */ VOID fbar_(doublecomplex * ret_val, doublecomplex *p)
{
    /* Initialized data */

    static doublereal tosp = 1.128379167;
    static doublereal accs = 1e-12;
    static doublereal sp = 1.772453851;
    static struct {
	doublereal e_1[2];
	} equiv_0 = { 0., 1. };


    /* System generated locals */
    real r__1;
    doublereal d__1;
    doublecomplex z__1, z__2, z__3, z__4, z__5, z__6, z__7;

    /* Builtin functions */
    void z_sqrt(doublecomplex *, doublecomplex *);
    double z_abs(doublecomplex *);
    void d_cnjg(doublecomplex *, doublecomplex *), z_exp(doublecomplex *, 
	    doublecomplex *), z_div(doublecomplex *, doublecomplex *, 
	    doublecomplex *);

    /* Local variables */
    integer i__;
    doublecomplex z__;
#define fj ((doublecomplex *)&equiv_0)
    doublecomplex zs;
#define fjx ((doublereal *)&equiv_0)
    doublereal sms, tms;
    doublecomplex sum, pow, term;
    integer minus;

/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* *** */

/*     FBAR IS SOMMERFELD ATTENUATION FUNCTION FOR NUMERICAL DISTANCE P */

    z_sqrt(&z__2, p);
    z__1.r = fj->r * z__2.r - fj->i * z__2.i, z__1.i = fj->r * z__2.i + fj->i 
	    * z__2.r;
    z__.r = z__1.r, z__.i = z__1.i;
    if (z_abs(&z__) > 3.f) {
	goto L3;
    }

/*     SERIES EXPANSION */

    z__1.r = z__.r * z__.r - z__.i * z__.i, z__1.i = z__.r * z__.i + z__.i * 
	    z__.r;
    zs.r = z__1.r, zs.i = z__1.i;
    sum.r = z__.r, sum.i = z__.i;
    pow.r = z__.r, pow.i = z__.i;
    for (i__ = 1; i__ <= 100; ++i__) {
	z__3.r = -pow.r, z__3.i = -pow.i;
	z__2.r = z__3.r * zs.r - z__3.i * zs.i, z__2.i = z__3.r * zs.i + 
		z__3.i * zs.r;
	d__1 = (doublereal) i__;
	z__1.r = z__2.r / d__1, z__1.i = z__2.i / d__1;
	pow.r = z__1.r, pow.i = z__1.i;
	r__1 = i__ * 2.f + 1.f;
	z__1.r = pow.r / r__1, z__1.i = pow.i / r__1;
	term.r = z__1.r, term.i = z__1.i;
	z__1.r = sum.r + term.r, z__1.i = sum.i + term.i;
	sum.r = z__1.r, sum.i = z__1.i;
	d_cnjg(&z__2, &term);
	z__1.r = term.r * z__2.r - term.i * z__2.i, z__1.i = term.r * z__2.i 
		+ term.i * z__2.r;
	tms = z__1.r;
	d_cnjg(&z__2, &sum);
	z__1.r = sum.r * z__2.r - sum.i * z__2.i, z__1.i = sum.r * z__2.i + 
		sum.i * z__2.r;
	sms = z__1.r;
	if (tms / sms < accs) {
	    goto L2;
	}
/* L1: */
    }
L2:
    z__6.r = tosp * sum.r, z__6.i = tosp * sum.i;
    z__5.r = 1.f - z__6.r, z__5.i = -z__6.i;
    z__4.r = z__5.r * z__.r - z__5.i * z__.i, z__4.i = z__5.r * z__.i + 
	    z__5.i * z__.r;
    z_exp(&z__7, &zs);
    z__3.r = z__4.r * z__7.r - z__4.i * z__7.i, z__3.i = z__4.r * z__7.i + 
	    z__4.i * z__7.r;
    z__2.r = sp * z__3.r, z__2.i = sp * z__3.i;
    z__1.r = 1.f - z__2.r, z__1.i = -z__2.i;
     ret_val->r = z__1.r,  ret_val->i = z__1.i;
    return ;

/*     ASYMPTOTIC EXPANSION */

L3:
    if (z__.r >= 0.f) {
	goto L4;
    }
    minus = 1;
    z__1.r = -z__.r, z__1.i = -z__.i;
    z__.r = z__1.r, z__.i = z__1.i;
    goto L5;
L4:
    minus = 0;
L5:
    z__2.r = z__.r * z__.r - z__.i * z__.i, z__2.i = z__.r * z__.i + z__.i * 
	    z__.r;
    z_div(&z__1, &c_b1440, &z__2);
    zs.r = z__1.r, zs.i = z__1.i;
    sum.r = 0.f, sum.i = 0.f;
    term.r = 1.f, term.i = 0.f;
    for (i__ = 1; i__ <= 6; ++i__) {
	z__3.r = -term.r, z__3.i = -term.i;
	r__1 = i__ * 2.f - 1.f;
	z__2.r = r__1 * z__3.r, z__2.i = r__1 * z__3.i;
	z__1.r = z__2.r * zs.r - z__2.i * zs.i, z__1.i = z__2.r * zs.i + 
		z__2.i * zs.r;
	term.r = z__1.r, term.i = z__1.i;
/* L6: */
	z__1.r = sum.r + term.r, z__1.i = sum.i + term.i;
	sum.r = z__1.r, sum.i = z__1.i;
    }
    if (minus == 1) {
	d__1 = sp * 2.f;
	z__3.r = d__1 * z__.r, z__3.i = d__1 * z__.i;
	z__5.r = z__.r * z__.r - z__.i * z__.i, z__5.i = z__.r * z__.i + 
		z__.i * z__.r;
	z_exp(&z__4, &z__5);
	z__2.r = z__3.r * z__4.r - z__3.i * z__4.i, z__2.i = z__3.r * z__4.i 
		+ z__3.i * z__4.r;
	z__1.r = sum.r - z__2.r, z__1.i = sum.i - z__2.i;
	sum.r = z__1.r, sum.i = z__1.i;
    }
    z__1.r = -sum.r, z__1.i = -sum.i;
     ret_val->r = z__1.r,  ret_val->i = z__1.i;
    return ;
} /* fbar_ */

#undef fjx
#undef fj


/* Subroutine */ int fblock_(integer *nrow, integer *ncol, integer *imax, 
	integer *irngf, integer *ipsym)
{
    /* Format strings */
    static char fmt_14[] = "(//\002 MATRIX FILE STORAGE -  NO. BLOCKS=\002,i"
	    "5,\002 COLUMNS PER BLOCK=\002,i5,\002 COLUMNS IN LAST BLOCK=\002"
	    ",i5)";
    static char fmt_15[] = "(\002 SUBMATRICIES FIT IN CORE\002)";
    static char fmt_16[] = "(\002 SUBMATRIX PARTITIONING -  NO. BLOCKS=\002,"
	    "i5,\002 COLUMNS PER BLOCK=\002,i5,\002 COLUMNS IN LAST BLOCK="
	    "\002,i5)";
    static char fmt_17[] = "(\002 ERROR - INSUFFICIENT STORAGE FOR MATRIX"
	    "\002,2i5)";
    static char fmt_18[] = "(\002 SYMMETRY ERROR - NROW,NCOL=\002,2i5)";

    /* System generated locals */
    integer i__1, i__2, i__3, i__4;
    doublereal d__1, d__2;
    doublecomplex z__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    double cos(doublereal), sin(doublereal);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer i__, j, k, ka, kk;
    doublereal arg;
    integer nop, imx1;
    doublereal phaz;
    doublecomplex deter;

    /* Fortran I/O blocks */
    static cilist io___993 = { 0, 3, 0, fmt_14, 0 };
    static cilist io___994 = { 0, 3, 0, fmt_14, 0 };
    static cilist io___995 = { 0, 3, 0, fmt_15, 0 };
    static cilist io___996 = { 0, 3, 0, fmt_16, 0 };
    static cilist io___1006 = { 0, 3, 0, fmt_17, 0 };
    static cilist io___1007 = { 0, 3, 0, fmt_18, 0 };


/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* *** */
/*     FBLOCK SETS PARAMETERS FOR OUT-OF-CORE SOLUTION FOR THE PRIMARY */
/*     MATRIX (A) */
    imx1 = *imax - *irngf;
    if (*nrow * *ncol > imx1) {
	goto L2;
    }
    matpar_1.nbloks = 1;
    matpar_1.npblk = *nrow;
    matpar_1.nlast = *nrow;
    matpar_1.imat = *nrow * *ncol;
    if (*nrow != *ncol) {
	goto L1;
    }
    matpar_1.icase = 1;
    return 0;
L1:
    matpar_1.icase = 2;
    goto L5;
L2:
    if (*nrow != *ncol) {
	goto L3;
    }
    matpar_1.icase = 3;
    matpar_1.npblk = *imax / (*ncol << 1);
    matpar_1.npsym = imx1 / *ncol;
    if (matpar_1.npsym < matpar_1.npblk) {
	matpar_1.npblk = matpar_1.npsym;
    }
    if (matpar_1.npblk < 1) {
	goto L12;
    }
    matpar_1.nbloks = (*nrow - 1) / matpar_1.npblk;
    matpar_1.nlast = *nrow - matpar_1.nbloks * matpar_1.npblk;
    ++matpar_1.nbloks;
    matpar_1.nblsym = matpar_1.nbloks;
    matpar_1.npsym = matpar_1.npblk;
    matpar_1.nlsym = matpar_1.nlast;
    matpar_1.imat = matpar_1.npblk * *ncol;
    s_wsfe(&io___993);
    do_fio(&c__1, (char *)&matpar_1.nbloks, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&matpar_1.npblk, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&matpar_1.nlast, (ftnlen)sizeof(integer));
    e_wsfe();
    goto L11;
L3:
    matpar_1.npblk = *imax / *ncol;
    if (matpar_1.npblk < 1) {
	goto L12;
    }
    if (matpar_1.npblk > *nrow) {
	matpar_1.npblk = *nrow;
    }
    matpar_1.nbloks = (*nrow - 1) / matpar_1.npblk;
    matpar_1.nlast = *nrow - matpar_1.nbloks * matpar_1.npblk;
    ++matpar_1.nbloks;
    s_wsfe(&io___994);
    do_fio(&c__1, (char *)&matpar_1.nbloks, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&matpar_1.npblk, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&matpar_1.nlast, (ftnlen)sizeof(integer));
    e_wsfe();
    if (*nrow * *nrow > imx1) {
	goto L4;
    }
    matpar_1.icase = 4;
    matpar_1.nblsym = 1;
    matpar_1.npsym = *nrow;
    matpar_1.nlsym = *nrow;
    matpar_1.imat = *nrow * *nrow;
    s_wsfe(&io___995);
    e_wsfe();
    goto L5;
L4:
    matpar_1.icase = 5;
    matpar_1.npsym = *imax / (*nrow << 1);
    matpar_1.nblsym = imx1 / *nrow;
    if (matpar_1.nblsym < matpar_1.npsym) {
	matpar_1.npsym = matpar_1.nblsym;
    }
    if (matpar_1.npsym < 1) {
	goto L12;
    }
    matpar_1.nblsym = (*nrow - 1) / matpar_1.npsym;
    matpar_1.nlsym = *nrow - matpar_1.nblsym * matpar_1.npsym;
    ++matpar_1.nblsym;
    s_wsfe(&io___996);
    do_fio(&c__1, (char *)&matpar_1.nblsym, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&matpar_1.npsym, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&matpar_1.nlsym, (ftnlen)sizeof(integer));
    e_wsfe();
    matpar_1.imat = matpar_1.npsym * *nrow;
L5:
    nop = *ncol / *nrow;
    if (nop * *nrow != *ncol) {
	goto L13;
    }
    if (*ipsym > 0) {
	goto L7;
    }

/*     SET UP SSX MATRIX FOR ROTATIONAL SYMMETRY. */

    phaz = 6.2831853072 / nop;
    i__1 = nop;
    for (i__ = 2; i__ <= i__1; ++i__) {
	i__2 = nop;
	for (j = i__; j <= i__2; ++j) {
	    arg = phaz * (doublereal) (i__ - 1) * (doublereal) (j - 1);
	    i__3 = i__ + (j << 4) - 17;
	    d__1 = cos(arg);
	    d__2 = sin(arg);
	    z__1.r = d__1, z__1.i = d__2;
	    smat_1.ssx[i__3].r = z__1.r, smat_1.ssx[i__3].i = z__1.i;
/* L6: */
	    i__3 = j + (i__ << 4) - 17;
	    i__4 = i__ + (j << 4) - 17;
	    smat_1.ssx[i__3].r = smat_1.ssx[i__4].r, smat_1.ssx[i__3].i = 
		    smat_1.ssx[i__4].i;
	}
    }
    goto L11;

/*     SET UP SSX MATRIX FOR PLANE SYMMETRY */

L7:
    kk = 1;
    smat_1.ssx[0].r = 1.f, smat_1.ssx[0].i = 0.f;
    if (nop == 2 || nop == 4 || nop == 8) {
	goto L8;
    }
    s_stop("", (ftnlen)0);
L8:
    ka = nop / 2;
    if (nop == 8) {
	ka = 3;
    }
    i__3 = ka;
    for (k = 1; k <= i__3; ++k) {
	i__4 = kk;
	for (i__ = 1; i__ <= i__4; ++i__) {
	    i__2 = kk;
	    for (j = 1; j <= i__2; ++j) {
		i__1 = i__ + (j << 4) - 17;
		deter.r = smat_1.ssx[i__1].r, deter.i = smat_1.ssx[i__1].i;
		i__1 = i__ + (j + kk << 4) - 17;
		smat_1.ssx[i__1].r = deter.r, smat_1.ssx[i__1].i = deter.i;
		i__1 = i__ + kk + (j + kk << 4) - 17;
		z__1.r = -deter.r, z__1.i = -deter.i;
		smat_1.ssx[i__1].r = z__1.r, smat_1.ssx[i__1].i = z__1.i;
/* L9: */
		i__1 = i__ + kk + (j << 4) - 17;
		smat_1.ssx[i__1].r = deter.r, smat_1.ssx[i__1].i = deter.i;
	    }
	}
/* L10: */
	kk <<= 1;
    }
L11:
    return 0;
L12:
    s_wsfe(&io___1006);
    do_fio(&c__1, (char *)&(*nrow), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*ncol), (ftnlen)sizeof(integer));
    e_wsfe();
    s_stop("", (ftnlen)0);
L13:
    s_wsfe(&io___1007);
    do_fio(&c__1, (char *)&(*nrow), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*ncol), (ftnlen)sizeof(integer));
    e_wsfe();
    s_stop("", (ftnlen)0);

    return 0;
} /* fblock_ */

/* Subroutine */ int fbngf_(integer *neq, integer *neq2, integer *iresrv, 
	integer *ib11, integer *ic11, integer *id11, integer *ix11)
{
    /* Format strings */
    static char fmt_11[] = "(//,\002 N.G.F. - NUMBER OF NEW UNKNOWNS IS\002,"
	    "i4)";
    static char fmt_8[] = "(\002 FILE STORAGE FOR NEW MATRIX SECTIONS -  ICA"
	    "SX =\002,i2)";
    static char fmt_9[] = "(\002 B FILLED BY ROWS -\002,15x,\002NO. BLOCKS "
	    "=\002,i3,3x,\002ROWS PER BLOCK =\002,i3,3x,\002ROWS IN LAST BLOC"
	    "K =\002,i3)";
    static char fmt_10[] = "(\002 B BY COLUMNS, C AND D BY ROWS -\002,2x,"
	    "\002NO. BLOCKS =\002,i3,4x,\002R/C PER BLOCK =\002,i3,4x,\002R/C"
	    " IN LAST BLOCK =\002,i3)";
    static char fmt_7[] = "(\002 ERROR - INSUFFICIENT STORAGE FOR INTERACTIO"
	    "N MATRICIES\002,\002  IRESRV,IMAT,NEQ,NEQ2 =\002,4i5)";

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer ir, nbcd, nbln, ndln, iresx;

    /* Fortran I/O blocks */
    static cilist io___1013 = { 0, 3, 0, fmt_11, 0 };
    static cilist io___1014 = { 0, 3, 0, fmt_8, 0 };
    static cilist io___1015 = { 0, 3, 0, fmt_9, 0 };
    static cilist io___1016 = { 0, 3, 0, fmt_10, 0 };
    static cilist io___1017 = { 0, 3, 0, fmt_7, 0 };


/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* *** */
/*     FBNGF SETS THE BLOCKING PARAMETERS FOR THE B, C, AND D ARRAYS FOR */
/*     OUT-OF-CORE STORAGE. */
    iresx = *iresrv - matpar_1.imat;
    nbln = *neq * *neq2;
    ndln = *neq2 * *neq2;
    nbcd = (nbln << 1) + ndln;
    if (nbcd > iresx) {
	goto L1;
    }
    matpar_1.icasx = 1;
    *ib11 = matpar_1.imat + 1;
    goto L2;
L1:
    if (matpar_1.icase < 3) {
	goto L3;
    }
    if (nbcd > *iresrv || nbln > iresx) {
	goto L3;
    }
    matpar_1.icasx = 2;
    *ib11 = 1;
L2:
    matpar_1.nbbx = 1;
    matpar_1.npbx = *neq;
    matpar_1.nlbx = *neq;
    matpar_1.nbbl = 1;
    matpar_1.npbl = *neq2;
    matpar_1.nlbl = *neq2;
    goto L5;
L3:
    ir = *iresrv;
    if (matpar_1.icase < 3) {
	ir = iresx;
    }
    matpar_1.icasx = 3;
    if (ndln > ir) {
	matpar_1.icasx = 4;
    }
    nbcd = (*neq << 1) + *neq2;
    matpar_1.npbl = ir / nbcd;
    matpar_1.nlbl = ir / (*neq2 << 1);
    if (matpar_1.nlbl < matpar_1.npbl) {
	matpar_1.npbl = matpar_1.nlbl;
    }
    if (matpar_1.icase < 3) {
	goto L4;
    }
    matpar_1.nlbl = iresx / *neq;
    if (matpar_1.nlbl < matpar_1.npbl) {
	matpar_1.npbl = matpar_1.nlbl;
    }
L4:
    if (matpar_1.npbl < 1) {
	goto L6;
    }
    matpar_1.nbbl = (*neq2 - 1) / matpar_1.npbl;
    matpar_1.nlbl = *neq2 - matpar_1.nbbl * matpar_1.npbl;
    ++matpar_1.nbbl;
    nbln = *neq * matpar_1.npbl;
    ir -= nbln;
    matpar_1.npbx = ir / *neq2;
    if (matpar_1.npbx > *neq) {
	matpar_1.npbx = *neq;
    }
    matpar_1.nbbx = (*neq - 1) / matpar_1.npbx;
    matpar_1.nlbx = *neq - matpar_1.nbbx * matpar_1.npbx;
    ++matpar_1.nbbx;
    *ib11 = 1;
    if (matpar_1.icase < 3) {
	*ib11 = matpar_1.imat + 1;
    }
L5:
    *ic11 = *ib11 + nbln;
    *id11 = *ic11 + nbln;
    *ix11 = matpar_1.imat + 1;
    s_wsfe(&io___1013);
    do_fio(&c__1, (char *)&(*neq2), (ftnlen)sizeof(integer));
    e_wsfe();
    if (matpar_1.icasx == 1) {
	return 0;
    }
    s_wsfe(&io___1014);
    do_fio(&c__1, (char *)&matpar_1.icasx, (ftnlen)sizeof(integer));
    e_wsfe();
    s_wsfe(&io___1015);
    do_fio(&c__1, (char *)&matpar_1.nbbx, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&matpar_1.npbx, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&matpar_1.nlbx, (ftnlen)sizeof(integer));
    e_wsfe();
    s_wsfe(&io___1016);
    do_fio(&c__1, (char *)&matpar_1.nbbl, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&matpar_1.npbl, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&matpar_1.nlbl, (ftnlen)sizeof(integer));
    e_wsfe();
    return 0;
L6:
    s_wsfe(&io___1017);
    do_fio(&c__1, (char *)&(*iresrv), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&matpar_1.imat, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*neq), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*neq2), (ftnlen)sizeof(integer));
    e_wsfe();
    s_stop("", (ftnlen)0);

    return 0;
} /* fbngf_ */

/* Subroutine */ int ffld_(doublereal *thet, doublereal *phi, doublecomplex *
	eth, doublecomplex *eph)
{
    /* Initialized data */

    static doublereal pi = 3.141592654;
    static doublereal tp = 6.283185308;
    static doublereal eta = 376.73;
    static struct {
	doublereal e_1[2];
	} equiv_2 = { 0., -29.97922085 };


    /* System generated locals */
    integer i__1, i__2, i__3;
    doublereal d__1, d__2;
    doublecomplex z__1, z__2, z__3, z__4, z__5, z__6;

    /* Builtin functions */
    double sin(doublereal), cos(doublereal);
    void z_sqrt(doublecomplex *, doublecomplex *), z_div(doublecomplex *, 
	    doublecomplex *, doublecomplex *);
    double tan(doublereal), sqrt(doublereal), log(doublereal);

    /* Local variables */
    doublereal a, b, c__, d__;
    integer i__, k;
    doublereal el, dr;
    integer ip;
    doublereal ri;
    doublecomplex ex, ey, ez, gx, gy, gz;
    doublereal rr;
#define cab ((doublereal *)&data_1 + 7500)
#define sab ((doublereal *)&data_1 + 9000)
    doublecomplex cdp, exa, ccx, ccy, ccz, cix, ciy, ciz, rrh;
    doublereal bot, phx, phy, too, top, thx;
    doublecomplex tix, tiy, tiz;
    doublereal thy, thz;
    doublecomplex rrv;
    doublereal roz, rox, roy, boo, arg, rfl, rrz;
    doublecomplex rrh1, rrh2, rrv1, rrv2;
    doublereal darg, sill, rozs, omega;
    extern /* Subroutine */ int fflds_(doublereal *, doublereal *, doublereal 
	    *, doublecomplex *, doublecomplex *, doublecomplex *, 
	    doublecomplex *);
#define const__ ((doublecomplex *)&equiv_2)
    doublereal tthet;
#define consx ((doublereal *)&equiv_2)
    doublecomplex zscrn, zrsin;

/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* Max number of segments 	(Windows-95 <= 4 */
/* max nr of 'in-core' alloc.	(MAXMAT <= MA */
/* Max number of LD cards */
/* Max number of EX cards */
/* Max number of segs connected to NT/TL */
/* *** */

/*     FFLD CALCULATES THE FAR ZONE RADIATED ELECTRIC FIELDS, */
/*     THE FACTOR EXP(J*K*R)/(R/LAMDA) NOT INCLUDED */

    phx = -sin(*phi);
    phy = cos(*phi);
    roz = cos(*thet);
    rozs = roz;
    thx = roz * phy;
    thy = -roz * phx;
    thz = -sin(*thet);
    rox = -thz * phy;
    roy = thz * phx;
    if (data_1.n == 0) {
	goto L20;
    }

/*     LOOP FOR STRUCTURE IMAGE IF ANY */

    i__1 = gnd_1.ksymp;
    for (k = 1; k <= i__1; ++k) {

/*     CALCULATION OF REFLECTION COEFFECIENTS */

	if (k == 1) {
	    goto L4;
	}
	if (gnd_1.iperf != 1) {
	    goto L1;
	}

/*     FOR PERFECT GROUND */

	rrv.r = -1.f, rrv.i = -0.f;
	rrh.r = -1.f, rrh.i = -0.f;
	goto L2;

/*     FOR INFINITE PLANAR GROUND */

L1:
	z__5.r = gnd_1.zrati.r * gnd_1.zrati.r - gnd_1.zrati.i * 
		gnd_1.zrati.i, z__5.i = gnd_1.zrati.r * gnd_1.zrati.i + 
		gnd_1.zrati.i * gnd_1.zrati.r;
	z__4.r = thz * z__5.r, z__4.i = thz * z__5.i;
	z__3.r = thz * z__4.r, z__3.i = thz * z__4.i;
	z__2.r = 1.f - z__3.r, z__2.i = -z__3.i;
	z_sqrt(&z__1, &z__2);
	zrsin.r = z__1.r, zrsin.i = z__1.i;
	z__4.r = gnd_1.zrati.r * zrsin.r - gnd_1.zrati.i * zrsin.i, z__4.i = 
		gnd_1.zrati.r * zrsin.i + gnd_1.zrati.i * zrsin.r;
	z__3.r = roz - z__4.r, z__3.i = -z__4.i;
	z__2.r = -z__3.r, z__2.i = -z__3.i;
	z__6.r = gnd_1.zrati.r * zrsin.r - gnd_1.zrati.i * zrsin.i, z__6.i = 
		gnd_1.zrati.r * zrsin.i + gnd_1.zrati.i * zrsin.r;
	z__5.r = roz + z__6.r, z__5.i = z__6.i;
	z_div(&z__1, &z__2, &z__5);
	rrv.r = z__1.r, rrv.i = z__1.i;
	z__3.r = roz * gnd_1.zrati.r, z__3.i = roz * gnd_1.zrati.i;
	z__2.r = z__3.r - zrsin.r, z__2.i = z__3.i - zrsin.i;
	z__5.r = roz * gnd_1.zrati.r, z__5.i = roz * gnd_1.zrati.i;
	z__4.r = z__5.r + zrsin.r, z__4.i = z__5.i + zrsin.i;
	z_div(&z__1, &z__2, &z__4);
	rrh.r = z__1.r, rrh.i = z__1.i;
L2:
	if (gnd_1.ifar <= 1) {
	    goto L3;
	}

/*     FOR THE CLIFF PROBLEM, TWO REFLCTION COEFFICIENTS CALCULATED */

	rrv1.r = rrv.r, rrv1.i = rrv.i;
	rrh1.r = rrh.r, rrh1.i = rrh.i;
	tthet = tan(*thet);
	if (gnd_1.ifar == 4) {
	    goto L3;
	}
	z__5.r = gnd_1.zrati2.r * gnd_1.zrati2.r - gnd_1.zrati2.i * 
		gnd_1.zrati2.i, z__5.i = gnd_1.zrati2.r * gnd_1.zrati2.i + 
		gnd_1.zrati2.i * gnd_1.zrati2.r;
	z__4.r = thz * z__5.r, z__4.i = thz * z__5.i;
	z__3.r = thz * z__4.r, z__3.i = thz * z__4.i;
	z__2.r = 1.f - z__3.r, z__2.i = -z__3.i;
	z_sqrt(&z__1, &z__2);
	zrsin.r = z__1.r, zrsin.i = z__1.i;
	z__4.r = gnd_1.zrati2.r * zrsin.r - gnd_1.zrati2.i * zrsin.i, z__4.i =
		 gnd_1.zrati2.r * zrsin.i + gnd_1.zrati2.i * zrsin.r;
	z__3.r = roz - z__4.r, z__3.i = -z__4.i;
	z__2.r = -z__3.r, z__2.i = -z__3.i;
	z__6.r = gnd_1.zrati2.r * zrsin.r - gnd_1.zrati2.i * zrsin.i, z__6.i =
		 gnd_1.zrati2.r * zrsin.i + gnd_1.zrati2.i * zrsin.r;
	z__5.r = roz + z__6.r, z__5.i = z__6.i;
	z_div(&z__1, &z__2, &z__5);
	rrv2.r = z__1.r, rrv2.i = z__1.i;
	z__3.r = roz * gnd_1.zrati2.r, z__3.i = roz * gnd_1.zrati2.i;
	z__2.r = z__3.r - zrsin.r, z__2.i = z__3.i - zrsin.i;
	z__5.r = roz * gnd_1.zrati2.r, z__5.i = roz * gnd_1.zrati2.i;
	z__4.r = z__5.r + zrsin.r, z__4.i = z__5.i + zrsin.i;
	z_div(&z__1, &z__2, &z__4);
	rrh2.r = z__1.r, rrh2.i = z__1.i;
	darg = -tp * 2.f * gnd_1.ch * roz;
L3:
	roz = -roz;
	ccx.r = cix.r, ccx.i = cix.i;
	ccy.r = ciy.r, ccy.i = ciy.i;
	ccz.r = ciz.r, ccz.i = ciz.i;
L4:
	cix.r = 0.f, cix.i = 0.f;
	ciy.r = 0.f, ciy.i = 0.f;
	ciz.r = 0.f, ciz.i = 0.f;

/*     LOOP OVER STRUCTURE SEGMENTS */

	i__2 = data_1.n;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    omega = -(rox * cab[i__ - 1] + roy * sab[i__ - 1] + roz * 
		    angl_1.salp[i__ - 1]);
	    el = pi * data_1.si[i__ - 1];
	    sill = omega * el;
	    top = el + sill;
	    bot = el - sill;
	    if (abs(omega) < 1e-7) {
		goto L5;
	    }
	    a = sin(sill) * 2.f / omega;
	    goto L6;
L5:
	    a = (2.f - omega * omega * el * el / 3.f) * el;
L6:
	    if (abs(top) < 1e-7) {
		goto L7;
	    }
	    too = sin(top) / top;
	    goto L8;
L7:
	    too = 1.f - top * top / 6.f;
L8:
	    if (abs(bot) < 1e-7) {
		goto L9;
	    }
	    boo = sin(bot) / bot;
	    goto L10;
L9:
	    boo = 1.f - bot * bot / 6.f;
L10:
	    b = el * (boo - too);
	    c__ = el * (boo + too);
	    rr = a * crnt_1.air[i__ - 1] + b * crnt_1.bii[i__ - 1] + c__ * 
		    crnt_1.cir[i__ - 1];
	    ri = a * crnt_1.aii[i__ - 1] - b * crnt_1.bir[i__ - 1] + c__ * 
		    crnt_1.cii[i__ - 1];
	    arg = tp * (data_1.x[i__ - 1] * rox + data_1.y[i__ - 1] * roy + 
		    data_1.z__[i__ - 1] * roz);
	    if (k == 2 && gnd_1.ifar >= 2) {
		goto L11;
	    }
	    d__1 = cos(arg);
	    d__2 = sin(arg);
	    z__2.r = d__1, z__2.i = d__2;
	    z__3.r = rr, z__3.i = ri;
	    z__1.r = z__2.r * z__3.r - z__2.i * z__3.i, z__1.i = z__2.r * 
		    z__3.i + z__2.i * z__3.r;
	    exa.r = z__1.r, exa.i = z__1.i;

/*     SUMMATION FOR FAR FIELD INTEGRAL */

	    i__3 = i__ - 1;
	    z__2.r = cab[i__3] * exa.r, z__2.i = cab[i__3] * exa.i;
	    z__1.r = cix.r + z__2.r, z__1.i = cix.i + z__2.i;
	    cix.r = z__1.r, cix.i = z__1.i;
	    i__3 = i__ - 1;
	    z__2.r = sab[i__3] * exa.r, z__2.i = sab[i__3] * exa.i;
	    z__1.r = ciy.r + z__2.r, z__1.i = ciy.i + z__2.i;
	    ciy.r = z__1.r, ciy.i = z__1.i;
	    i__3 = i__ - 1;
	    z__2.r = angl_1.salp[i__3] * exa.r, z__2.i = angl_1.salp[i__3] * 
		    exa.i;
	    z__1.r = ciz.r + z__2.r, z__1.i = ciz.i + z__2.i;
	    ciz.r = z__1.r, ciz.i = z__1.i;
	    goto L17;

/*     CALCULATION OF IMAGE CONTRIBUTION IN CLIFF AND GROUND SCREEN */
/*     PROBLEMS. */

L11:
	    dr = data_1.z__[i__ - 1] * tthet;

/*     SPECULAR POINT DISTANCE */

	    d__ = dr * phy + data_1.x[i__ - 1];
	    if (gnd_1.ifar == 2) {
		goto L13;
	    }
/* Computing 2nd power */
	    d__1 = data_1.y[i__ - 1] - dr * phx;
	    d__ = sqrt(d__ * d__ + d__1 * d__1);
	    if (gnd_1.ifar == 3) {
		goto L13;
	    }
	    if (gnd_1.scrwl - d__ < 0.f) {
		goto L12;
	    }

/*     RADIAL WIRE GROUND SCREEN REFLECTION COEFFICIENT */

	    d__ += gnd_1.t2;
	    z__2.r = d__ * gnd_1.t1.r, z__2.i = d__ * gnd_1.t1.i;
	    d__1 = log(d__ / gnd_1.t2);
	    z__1.r = d__1 * z__2.r, z__1.i = d__1 * z__2.i;
	    zscrn.r = z__1.r, zscrn.i = z__1.i;
	    z__2.r = zscrn.r * gnd_1.zrati.r - zscrn.i * gnd_1.zrati.i, 
		    z__2.i = zscrn.r * gnd_1.zrati.i + zscrn.i * 
		    gnd_1.zrati.r;
	    z__4.r = eta * gnd_1.zrati.r, z__4.i = eta * gnd_1.zrati.i;
	    z__3.r = z__4.r + zscrn.r, z__3.i = z__4.i + zscrn.i;
	    z_div(&z__1, &z__2, &z__3);
	    zscrn.r = z__1.r, zscrn.i = z__1.i;
	    z__5.r = zscrn.r * zscrn.r - zscrn.i * zscrn.i, z__5.i = zscrn.r *
		     zscrn.i + zscrn.i * zscrn.r;
	    z__4.r = thz * z__5.r, z__4.i = thz * z__5.i;
	    z__3.r = thz * z__4.r, z__3.i = thz * z__4.i;
	    z__2.r = 1.f - z__3.r, z__2.i = -z__3.i;
	    z_sqrt(&z__1, &z__2);
	    zrsin.r = z__1.r, zrsin.i = z__1.i;
	    z__3.r = zscrn.r * zrsin.r - zscrn.i * zrsin.i, z__3.i = zscrn.r *
		     zrsin.i + zscrn.i * zrsin.r;
	    z__2.r = roz + z__3.r, z__2.i = z__3.i;
	    d__1 = -roz;
	    z__5.r = zscrn.r * zrsin.r - zscrn.i * zrsin.i, z__5.i = zscrn.r *
		     zrsin.i + zscrn.i * zrsin.r;
	    z__4.r = d__1 + z__5.r, z__4.i = z__5.i;
	    z_div(&z__1, &z__2, &z__4);
	    rrv.r = z__1.r, rrv.i = z__1.i;
	    z__3.r = roz * zscrn.r, z__3.i = roz * zscrn.i;
	    z__2.r = z__3.r + zrsin.r, z__2.i = z__3.i + zrsin.i;
	    z__5.r = roz * zscrn.r, z__5.i = roz * zscrn.i;
	    z__4.r = z__5.r - zrsin.r, z__4.i = z__5.i - zrsin.i;
	    z_div(&z__1, &z__2, &z__4);
	    rrh.r = z__1.r, rrh.i = z__1.i;
	    goto L16;
L12:
	    if (gnd_1.ifar == 4) {
		goto L14;
	    }
	    if (gnd_1.ifar == 5) {
		d__ = dr * phy + data_1.x[i__ - 1];
	    }
L13:
	    if (gnd_1.cl - d__ <= 0.f) {
		goto L15;
	    }
L14:
	    rrv.r = rrv1.r, rrv.i = rrv1.i;
	    rrh.r = rrh1.r, rrh.i = rrh1.i;
	    goto L16;
L15:
	    rrv.r = rrv2.r, rrv.i = rrv2.i;
	    rrh.r = rrh2.r, rrh.i = rrh2.i;
	    arg += darg;
L16:
	    d__1 = cos(arg);
	    d__2 = sin(arg);
	    z__2.r = d__1, z__2.i = d__2;
	    z__3.r = rr, z__3.i = ri;
	    z__1.r = z__2.r * z__3.r - z__2.i * z__3.i, z__1.i = z__2.r * 
		    z__3.i + z__2.i * z__3.r;
	    exa.r = z__1.r, exa.i = z__1.i;

/*     CONTRIBUTION OF EACH IMAGE SEGMENT MODIFIED BY REFLECTION COEF. , */
/*     FOR CLIFF AND GROUND SCREEN PROBLEMS */

	    i__3 = i__ - 1;
	    z__1.r = cab[i__3] * exa.r, z__1.i = cab[i__3] * exa.i;
	    tix.r = z__1.r, tix.i = z__1.i;
	    i__3 = i__ - 1;
	    z__1.r = sab[i__3] * exa.r, z__1.i = sab[i__3] * exa.i;
	    tiy.r = z__1.r, tiy.i = z__1.i;
	    i__3 = i__ - 1;
	    z__1.r = angl_1.salp[i__3] * exa.r, z__1.i = angl_1.salp[i__3] * 
		    exa.i;
	    tiz.r = z__1.r, tiz.i = z__1.i;
	    z__3.r = phx * tix.r, z__3.i = phx * tix.i;
	    z__4.r = phy * tiy.r, z__4.i = phy * tiy.i;
	    z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
	    z__5.r = rrh.r - rrv.r, z__5.i = rrh.i - rrv.i;
	    z__1.r = z__2.r * z__5.r - z__2.i * z__5.i, z__1.i = z__2.r * 
		    z__5.i + z__2.i * z__5.r;
	    cdp.r = z__1.r, cdp.i = z__1.i;
	    z__3.r = tix.r * rrv.r - tix.i * rrv.i, z__3.i = tix.r * rrv.i + 
		    tix.i * rrv.r;
	    z__2.r = cix.r + z__3.r, z__2.i = cix.i + z__3.i;
	    z__4.r = phx * cdp.r, z__4.i = phx * cdp.i;
	    z__1.r = z__2.r + z__4.r, z__1.i = z__2.i + z__4.i;
	    cix.r = z__1.r, cix.i = z__1.i;
	    z__3.r = tiy.r * rrv.r - tiy.i * rrv.i, z__3.i = tiy.r * rrv.i + 
		    tiy.i * rrv.r;
	    z__2.r = ciy.r + z__3.r, z__2.i = ciy.i + z__3.i;
	    z__4.r = phy * cdp.r, z__4.i = phy * cdp.i;
	    z__1.r = z__2.r + z__4.r, z__1.i = z__2.i + z__4.i;
	    ciy.r = z__1.r, ciy.i = z__1.i;
	    z__2.r = tiz.r * rrv.r - tiz.i * rrv.i, z__2.i = tiz.r * rrv.i + 
		    tiz.i * rrv.r;
	    z__1.r = ciz.r - z__2.r, z__1.i = ciz.i - z__2.i;
	    ciz.r = z__1.r, ciz.i = z__1.i;
L17:
	    ;
	}
	if (k == 1) {
	    goto L19;
	}
	if (gnd_1.ifar >= 2) {
	    goto L18;
	}

/*     CALCULATION OF CONTRIBUTION OF STRUCTURE IMAGE FOR INFINITE GROUND */

	z__3.r = phx * cix.r, z__3.i = phx * cix.i;
	z__4.r = phy * ciy.r, z__4.i = phy * ciy.i;
	z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
	z__5.r = rrh.r - rrv.r, z__5.i = rrh.i - rrv.i;
	z__1.r = z__2.r * z__5.r - z__2.i * z__5.i, z__1.i = z__2.r * z__5.i 
		+ z__2.i * z__5.r;
	cdp.r = z__1.r, cdp.i = z__1.i;
	z__3.r = cix.r * rrv.r - cix.i * rrv.i, z__3.i = cix.r * rrv.i + 
		cix.i * rrv.r;
	z__2.r = ccx.r + z__3.r, z__2.i = ccx.i + z__3.i;
	z__4.r = phx * cdp.r, z__4.i = phx * cdp.i;
	z__1.r = z__2.r + z__4.r, z__1.i = z__2.i + z__4.i;
	cix.r = z__1.r, cix.i = z__1.i;
	z__3.r = ciy.r * rrv.r - ciy.i * rrv.i, z__3.i = ciy.r * rrv.i + 
		ciy.i * rrv.r;
	z__2.r = ccy.r + z__3.r, z__2.i = ccy.i + z__3.i;
	z__4.r = phy * cdp.r, z__4.i = phy * cdp.i;
	z__1.r = z__2.r + z__4.r, z__1.i = z__2.i + z__4.i;
	ciy.r = z__1.r, ciy.i = z__1.i;
	z__2.r = ciz.r * rrv.r - ciz.i * rrv.i, z__2.i = ciz.r * rrv.i + 
		ciz.i * rrv.r;
	z__1.r = ccz.r - z__2.r, z__1.i = ccz.i - z__2.i;
	ciz.r = z__1.r, ciz.i = z__1.i;
	goto L19;
L18:
	z__1.r = cix.r + ccx.r, z__1.i = cix.i + ccx.i;
	cix.r = z__1.r, cix.i = z__1.i;
	z__1.r = ciy.r + ccy.r, z__1.i = ciy.i + ccy.i;
	ciy.r = z__1.r, ciy.i = z__1.i;
	z__1.r = ciz.r + ccz.r, z__1.i = ciz.i + ccz.i;
	ciz.r = z__1.r, ciz.i = z__1.i;
L19:
	;
    }
    if (data_1.m > 0) {
	goto L21;
    }
    z__4.r = thx * cix.r, z__4.i = thx * cix.i;
    z__5.r = thy * ciy.r, z__5.i = thy * ciy.i;
    z__3.r = z__4.r + z__5.r, z__3.i = z__4.i + z__5.i;
    z__6.r = thz * ciz.r, z__6.i = thz * ciz.i;
    z__2.r = z__3.r + z__6.r, z__2.i = z__3.i + z__6.i;
    z__1.r = z__2.r * const__->r - z__2.i * const__->i, z__1.i = z__2.r * 
	    const__->i + z__2.i * const__->r;
    eth->r = z__1.r, eth->i = z__1.i;
    z__3.r = phx * cix.r, z__3.i = phx * cix.i;
    z__4.r = phy * ciy.r, z__4.i = phy * ciy.i;
    z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
    z__1.r = z__2.r * const__->r - z__2.i * const__->i, z__1.i = z__2.r * 
	    const__->i + z__2.i * const__->r;
    eph->r = z__1.r, eph->i = z__1.i;
    return 0;
L20:
    cix.r = 0.f, cix.i = 0.f;
    ciy.r = 0.f, ciy.i = 0.f;
    ciz.r = 0.f, ciz.i = 0.f;
L21:
    roz = rozs;

/*     ELECTRIC FIELD COMPONENTS */

    rfl = -1.f;
    i__1 = gnd_1.ksymp;
    for (ip = 1; ip <= i__1; ++ip) {
	rfl = -rfl;
	rrz = roz * rfl;
	fflds_(&rox, &roy, &rrz, &crnt_1.cur[data_1.n], &gx, &gy, &gz);
	if (ip == 2) {
	    goto L22;
	}
	ex.r = gx.r, ex.i = gx.i;
	ey.r = gy.r, ey.i = gy.i;
	ez.r = gz.r, ez.i = gz.i;
	goto L25;
L22:
	if (gnd_1.iperf != 1) {
	    goto L23;
	}
	z__1.r = -gx.r, z__1.i = -gx.i;
	gx.r = z__1.r, gx.i = z__1.i;
	z__1.r = -gy.r, z__1.i = -gy.i;
	gy.r = z__1.r, gy.i = z__1.i;
	z__1.r = -gz.r, z__1.i = -gz.i;
	gz.r = z__1.r, gz.i = z__1.i;
	goto L24;
L23:
	z__5.r = gnd_1.zrati.r * gnd_1.zrati.r - gnd_1.zrati.i * 
		gnd_1.zrati.i, z__5.i = gnd_1.zrati.r * gnd_1.zrati.i + 
		gnd_1.zrati.i * gnd_1.zrati.r;
	z__4.r = thz * z__5.r, z__4.i = thz * z__5.i;
	z__3.r = thz * z__4.r, z__3.i = thz * z__4.i;
	z__2.r = 1.f - z__3.r, z__2.i = -z__3.i;
	z_sqrt(&z__1, &z__2);
	rrv.r = z__1.r, rrv.i = z__1.i;
	z__1.r = roz * gnd_1.zrati.r, z__1.i = roz * gnd_1.zrati.i;
	rrh.r = z__1.r, rrh.i = z__1.i;
	z__2.r = rrh.r - rrv.r, z__2.i = rrh.i - rrv.i;
	z__3.r = rrh.r + rrv.r, z__3.i = rrh.i + rrv.i;
	z_div(&z__1, &z__2, &z__3);
	rrh.r = z__1.r, rrh.i = z__1.i;
	z__1.r = gnd_1.zrati.r * rrv.r - gnd_1.zrati.i * rrv.i, z__1.i = 
		gnd_1.zrati.r * rrv.i + gnd_1.zrati.i * rrv.r;
	rrv.r = z__1.r, rrv.i = z__1.i;
	z__3.r = roz - rrv.r, z__3.i = -rrv.i;
	z__2.r = -z__3.r, z__2.i = -z__3.i;
	z__4.r = roz + rrv.r, z__4.i = rrv.i;
	z_div(&z__1, &z__2, &z__4);
	rrv.r = z__1.r, rrv.i = z__1.i;
	z__3.r = phx * gx.r, z__3.i = phx * gx.i;
	z__4.r = phy * gy.r, z__4.i = phy * gy.i;
	z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
	z__5.r = rrh.r - rrv.r, z__5.i = rrh.i - rrv.i;
	z__1.r = z__2.r * z__5.r - z__2.i * z__5.i, z__1.i = z__2.r * z__5.i 
		+ z__2.i * z__5.r;
	eth->r = z__1.r, eth->i = z__1.i;
	z__2.r = gx.r * rrv.r - gx.i * rrv.i, z__2.i = gx.r * rrv.i + gx.i * 
		rrv.r;
	z__3.r = phx * eth->r, z__3.i = phx * eth->i;
	z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
	gx.r = z__1.r, gx.i = z__1.i;
	z__2.r = gy.r * rrv.r - gy.i * rrv.i, z__2.i = gy.r * rrv.i + gy.i * 
		rrv.r;
	z__3.r = phy * eth->r, z__3.i = phy * eth->i;
	z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
	gy.r = z__1.r, gy.i = z__1.i;
	z__1.r = gz.r * rrv.r - gz.i * rrv.i, z__1.i = gz.r * rrv.i + gz.i * 
		rrv.r;
	gz.r = z__1.r, gz.i = z__1.i;
L24:
	z__1.r = ex.r + gx.r, z__1.i = ex.i + gx.i;
	ex.r = z__1.r, ex.i = z__1.i;
	z__1.r = ey.r + gy.r, z__1.i = ey.i + gy.i;
	ey.r = z__1.r, ey.i = z__1.i;
	z__1.r = ez.r - gz.r, z__1.i = ez.i - gz.i;
	ez.r = z__1.r, ez.i = z__1.i;
L25:
	;
    }
    z__2.r = cix.r * const__->r - cix.i * const__->i, z__2.i = cix.r * 
	    const__->i + cix.i * const__->r;
    z__1.r = ex.r + z__2.r, z__1.i = ex.i + z__2.i;
    ex.r = z__1.r, ex.i = z__1.i;
    z__2.r = ciy.r * const__->r - ciy.i * const__->i, z__2.i = ciy.r * 
	    const__->i + ciy.i * const__->r;
    z__1.r = ey.r + z__2.r, z__1.i = ey.i + z__2.i;
    ey.r = z__1.r, ey.i = z__1.i;
    z__2.r = ciz.r * const__->r - ciz.i * const__->i, z__2.i = ciz.r * 
	    const__->i + ciz.i * const__->r;
    z__1.r = ez.r + z__2.r, z__1.i = ez.i + z__2.i;
    ez.r = z__1.r, ez.i = z__1.i;
    z__3.r = thx * ex.r, z__3.i = thx * ex.i;
    z__4.r = thy * ey.r, z__4.i = thy * ey.i;
    z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
    z__5.r = thz * ez.r, z__5.i = thz * ez.i;
    z__1.r = z__2.r + z__5.r, z__1.i = z__2.i + z__5.i;
    eth->r = z__1.r, eth->i = z__1.i;
    z__2.r = phx * ex.r, z__2.i = phx * ex.i;
    z__3.r = phy * ey.r, z__3.i = phy * ey.i;
    z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
    eph->r = z__1.r, eph->i = z__1.i;
    return 0;
} /* ffld_ */

#undef consx
#undef const__
#undef sab
#undef cab


/* Subroutine */ int fflds_(doublereal *rox, doublereal *roy, doublereal *roz,
	 doublecomplex *scur, doublecomplex *ex, doublecomplex *ey, 
	doublecomplex *ez)
{
    /* Initialized data */

    static doublereal tpi = 6.283185308;
    static struct {
	doublereal e_1[2];
	} equiv_4 = { 0., 188.365 };


    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2;
    doublecomplex z__1, z__2, z__3, z__4, z__5;

    /* Builtin functions */
    double cos(doublereal), sin(doublereal);

    /* Local variables */
    integer i__, j, k;
#define s ((doublereal *)&data_1 + 6000)
    doublecomplex ct;
#define xs ((doublereal *)&data_1)
#define ys ((doublereal *)&data_1 + 1500)
#define zs ((doublereal *)&data_1 + 3000)
    doublereal arg;
#define cons ((doublecomplex *)&equiv_4)
#define consx ((doublereal *)&equiv_4)

/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* Max number of segments 	(Windows-95 <= 4 */
/* max nr of 'in-core' alloc.	(MAXMAT <= MA */
/* Max number of LD cards */
/* Max number of EX cards */
/* Max number of segs connected to NT/TL */
/* *** */
/*     CALCULATES THE XYZ COMPONENTS OF THE ELECTRIC FIELD DUE TO */
/*     SURFACE CURRENTS */
    /* Parameter adjustments */
    --scur;

    /* Function Body */
    ex->r = 0.f, ex->i = 0.f;
    ey->r = 0.f, ey->i = 0.f;
    ez->r = 0.f, ez->i = 0.f;
    i__ = data_1.ld + 1;
    i__1 = data_1.m;
    for (j = 1; j <= i__1; ++j) {
	--i__;
	arg = tpi * (*rox * xs[i__ - 1] + *roy * ys[i__ - 1] + *roz * zs[i__ 
		- 1]);
	d__1 = cos(arg) * s[i__ - 1];
	d__2 = sin(arg) * s[i__ - 1];
	z__1.r = d__1, z__1.i = d__2;
	ct.r = z__1.r, ct.i = z__1.i;
	k = j * 3;
	i__2 = k - 2;
	z__2.r = scur[i__2].r * ct.r - scur[i__2].i * ct.i, z__2.i = scur[
		i__2].r * ct.i + scur[i__2].i * ct.r;
	z__1.r = ex->r + z__2.r, z__1.i = ex->i + z__2.i;
	ex->r = z__1.r, ex->i = z__1.i;
	i__2 = k - 1;
	z__2.r = scur[i__2].r * ct.r - scur[i__2].i * ct.i, z__2.i = scur[
		i__2].r * ct.i + scur[i__2].i * ct.r;
	z__1.r = ey->r + z__2.r, z__1.i = ey->i + z__2.i;
	ey->r = z__1.r, ey->i = z__1.i;
	i__2 = k;
	z__2.r = scur[i__2].r * ct.r - scur[i__2].i * ct.i, z__2.i = scur[
		i__2].r * ct.i + scur[i__2].i * ct.r;
	z__1.r = ez->r + z__2.r, z__1.i = ez->i + z__2.i;
	ez->r = z__1.r, ez->i = z__1.i;
/* L1: */
    }
    z__3.r = *rox * ex->r, z__3.i = *rox * ex->i;
    z__4.r = *roy * ey->r, z__4.i = *roy * ey->i;
    z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
    z__5.r = *roz * ez->r, z__5.i = *roz * ez->i;
    z__1.r = z__2.r + z__5.r, z__1.i = z__2.i + z__5.i;
    ct.r = z__1.r, ct.i = z__1.i;
    z__3.r = *rox * ct.r, z__3.i = *rox * ct.i;
    z__2.r = z__3.r - ex->r, z__2.i = z__3.i - ex->i;
    z__1.r = cons->r * z__2.r - cons->i * z__2.i, z__1.i = cons->r * z__2.i + 
	    cons->i * z__2.r;
    ex->r = z__1.r, ex->i = z__1.i;
    z__3.r = *roy * ct.r, z__3.i = *roy * ct.i;
    z__2.r = z__3.r - ey->r, z__2.i = z__3.i - ey->i;
    z__1.r = cons->r * z__2.r - cons->i * z__2.i, z__1.i = cons->r * z__2.i + 
	    cons->i * z__2.r;
    ey->r = z__1.r, ey->i = z__1.i;
    z__3.r = *roz * ct.r, z__3.i = *roz * ct.i;
    z__2.r = z__3.r - ez->r, z__2.i = z__3.i - ez->i;
    z__1.r = cons->r * z__2.r - cons->i * z__2.i, z__1.i = cons->r * z__2.i + 
	    cons->i * z__2.r;
    ez->r = z__1.r, ez->i = z__1.i;
    return 0;
} /* fflds_ */

#undef consx
#undef cons
#undef zs
#undef ys
#undef xs
#undef s


/* Subroutine */ int gf_(doublereal *zk, doublereal *co, doublereal *si)
{
    /* Builtin functions */
    double sqrt(doublereal), sin(doublereal), cos(doublereal);

    /* Local variables */
    doublereal rk, zdk, rks;

/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* *** */

/*     GF COMPUTES THE INTEGRAND EXP(JKR)/(KR) FOR NUMERICAL INTEGRATION. */

    zdk = *zk - tmi_2.zpk;
    rk = sqrt(tmi_2.rkb2 + zdk * zdk);
    *si = sin(rk) / rk;
    if (tmi_2.ij != 0) {
	goto L1;
    } else {
	goto L2;
    }
L1:
    *co = cos(rk) / rk;
    return 0;
L2:
    if (rk < .2f) {
	goto L3;
    }
    *co = (cos(rk) - 1.f) / rk;
    return 0;
L3:
    rks = rk * rk;
    *co = ((rks * -.00138888889 + .0416666667) * rks - .5f) * rk;
    return 0;
} /* gf_ */

/* Subroutine */ int gfil_(integer *iprt)
{
    /* Initialized data */

    static integer igfl = 20;

    /* Format strings */
    static char fmt_16[] = "(////)";
    static char fmt_14[] = "(5x,\002****************************************"
	    "**********\002,\002**********************************\002)";
    static char fmt_17[] = "(5x,\002**\002,80x,\002**\002)";
    static char fmt_18[] = "(5x,\002** NUMERICAL GREEN'S FUNCTION\002,53x"
	    ",\002**\002,/,5x,\002** NO. SEGMENTS =\002,i4,10x,\002NO. PATCHE"
	    "S =\002,i4,34x,\002**\002)";
    static char fmt_19[] = "(5x,\002** NO. SYMMETRIC SECTIONS =\002,i4,51x"
	    ",\002**\002)";
    static char fmt_20[] = "(5x,\002** N.G.F. MATRIX -  CORE STORAGE =\002,i"
	    "7,\002 COMPLEX NUMBERS,  CASE\002,i2,16x,\002**\002)";
    static char fmt_21[] = "(5x,\002**\002,19x,\002MATRIX SIZE =\002,i7,\002"
	    " COMPLEX NUMBERS\002,25x,\002**\002)";
    static char fmt_22[] = "(5x,\002** FREQUENCY =\002,1p,e12.5,\002 MHZ."
	    "\002,51x,\002**\002)";
    static char fmt_23[] = "(5x,\002** PERFECT GROUND\002,65x,\002**\002)";
    static char fmt_27[] = "(5x,\002** FINITE GROUND.  REFLECTION COEFFICIEN"
	    "T APPROXIMATION\002,27x,\002**\002)";
    static char fmt_28[] = "(5x,\002** FINITE GROUND.  SOMMERFELD SOLUTIO"
	    "N\002,44x,\002**\002)";
    static char fmt_24[] = "(5x,\002** GROUND PARAMETERS - DIELECTRIC CONSTA"
	    "NT =\002,1p,e12.5,26x,\002**\002,/,5x,\002**\002,21x,\002CONDUCT"
	    "IVITY =\002,e12.5,\002 MHOS/M.\002,25x,\002**\002)";
    static char fmt_15[] = "(5x,\002** \002,19a4,\002 **\002)";
    static char fmt_25[] = "(39x,\002NUMERICAL GREEN'S FUNCTION DATA\002,/,4"
	    "1x,\002COORDINATES OF SEGMENT ENDS\002,/,51x,\002(METERS)\002,/,"
	    "5x,\002SEG.\002,11x,\002- - - END ONE - - -\002,26x,\002- - - EN"
	    "D TWO - - -\002,/,6x,\002NO.\002,6x,\002X\002,14x,\002Y\002,14x"
	    ",\002Z\002,14x,\002X\002,14x,\002Y\002,14x,\002Z\002)";
    static char fmt_26[] = "(1x,i7,1p,6e15.6)";

    /* System generated locals */
    integer i__1, i__2, i__3;
    olist o__1;
    alist al__1;

    /* Builtin functions */
    integer f_open(olist *), f_rew(alist *), s_rsue(cilist *), do_uio(integer 
	    *, char *, ftnlen), e_rsue(void), s_wsue(cilist *), e_wsue(void), 
	    s_wsfe(cilist *), e_wsfe(void), do_fio(integer *, char *, ftnlen);

    /* Local variables */
    integer i__, j, k;
    doublereal dx, xi, yi, zi;
#define t2x ((doublereal *)&data_1 + 10501)
#define t2y ((doublereal *)&data_1 + 12001)
#define t2z ((doublereal *)&data_1 + 13501)
    integer neq, iop, nop, nbl2, npeq, iout;
    extern /* Subroutine */ int blckin_(doublecomplex *, integer *, integer *,
	     integer *, integer *, integer *), blckot_(doublecomplex *, 
	    integer *, integer *, integer *, integer *, integer *);

    /* Fortran I/O blocks */
    static cilist io___1100 = { 0, 0, 0, 0, 0 };
    static cilist io___1101 = { 0, 0, 0, 0, 0 };
    static cilist io___1103 = { 0, 0, 0, 0, 0 };
    static cilist io___1104 = { 0, 0, 0, 0, 0 };
    static cilist io___1105 = { 0, 0, 0, 0, 0 };
    static cilist io___1106 = { 0, 0, 0, 0, 0 };
    static cilist io___1107 = { 0, 0, 0, 0, 0 };
    static cilist io___1113 = { 0, 0, 0, 0, 0 };
    static cilist io___1114 = { 0, 0, 0, 0, 0 };
    static cilist io___1115 = { 0, 0, 0, 0, 0 };
    static cilist io___1116 = { 0, 0, 0, 0, 0 };
    static cilist io___1117 = { 0, 0, 0, 0, 0 };
    static cilist io___1118 = { 0, 0, 0, 0, 0 };
    static cilist io___1119 = { 0, 0, 0, 0, 0 };
    static cilist io___1123 = { 0, 0, 0, 0, 0 };
    static cilist io___1124 = { 0, 0, 0, 0, 0 };
    static cilist io___1126 = { 0, 0, 0, 0, 0 };
    static cilist io___1128 = { 0, 0, 0, 0, 0 };
    static cilist io___1129 = { 0, 13, 0, 0, 0 };
    static cilist io___1132 = { 0, 3, 0, fmt_16, 0 };
    static cilist io___1133 = { 0, 3, 0, fmt_14, 0 };
    static cilist io___1134 = { 0, 3, 0, fmt_14, 0 };
    static cilist io___1135 = { 0, 3, 0, fmt_17, 0 };
    static cilist io___1136 = { 0, 3, 0, fmt_18, 0 };
    static cilist io___1137 = { 0, 3, 0, fmt_19, 0 };
    static cilist io___1138 = { 0, 3, 0, fmt_20, 0 };
    static cilist io___1139 = { 0, 3, 0, fmt_21, 0 };
    static cilist io___1140 = { 0, 3, 0, fmt_22, 0 };
    static cilist io___1141 = { 0, 3, 0, fmt_23, 0 };
    static cilist io___1142 = { 0, 3, 0, fmt_27, 0 };
    static cilist io___1143 = { 0, 3, 0, fmt_28, 0 };
    static cilist io___1144 = { 0, 3, 0, fmt_24, 0 };
    static cilist io___1145 = { 0, 3, 0, fmt_17, 0 };
    static cilist io___1146 = { 0, 3, 0, fmt_15, 0 };
    static cilist io___1147 = { 0, 3, 0, fmt_17, 0 };
    static cilist io___1148 = { 0, 3, 0, fmt_14, 0 };
    static cilist io___1149 = { 0, 3, 0, fmt_14, 0 };
    static cilist io___1150 = { 0, 3, 0, fmt_16, 0 };
    static cilist io___1151 = { 0, 3, 0, fmt_25, 0 };
    static cilist io___1152 = { 0, 3, 0, fmt_26, 0 };


/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* Max number of segments 	(Windows-95 <= 4 */
/* max nr of 'in-core' alloc.	(MAXMAT <= MA */
/* Max number of LD cards */
/* Max number of EX cards */
/* Max number of segs connected to NT/TL */
/* *** */

/*     GFIL READS THE N.G.F. FILE */


/* *** ERROR CORRECTED 11/20/89 ******************************* */
/* *** */
    o__1.oerr = 0;
    o__1.ounit = igfl;
    o__1.ofnmlen = 9;
    o__1.ofnm = "NGF2D.NEC";
    o__1.orl = 0;
    o__1.osta = "OLD";
    o__1.oacc = 0;
    o__1.ofm = "UNFORMATTED";
    o__1.oblnk = 0;
    f_open(&o__1);
    al__1.aerr = 0;
    al__1.aunit = igfl;
    f_rew(&al__1);
    io___1100.ciunit = igfl;
    s_rsue(&io___1100);
    do_uio(&c__1, (char *)&data_1.n1, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&data_1.np, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&data_1.m1, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&data_1.mp, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&data_1.wlam, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&save_1.fmhz, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&data_1.ipsym, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&gnd_1.ksymp, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&gnd_1.iperf, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&gnd_1.nradl, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&save_1.epsr, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&save_1.sig, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&save_1.scrwlt, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&save_1.scrwrt, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&zload_1.nlodf, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&save_1.kcom, (ftnlen)sizeof(integer));
    e_rsue();
    data_1.n = data_1.n1;
    data_1.m = data_1.m1;
    data_1.n2 = data_1.n1 + 1;
    data_1.m2 = data_1.m1 + 1;
    if (data_1.n1 == 0) {
	goto L2;
    }
/*     READ SEG. DATA AND CONVERT BACK TO END COORD. IN UNITS OF METERS */
    io___1101.ciunit = igfl;
    s_rsue(&io___1101);
    i__1 = data_1.n1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_uio(&c__1, (char *)&data_1.x[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    i__2 = data_1.n1;
    for (i__ = 1; i__ <= i__2; ++i__) {
	do_uio(&c__1, (char *)&data_1.y[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    i__3 = data_1.n1;
    for (i__ = 1; i__ <= i__3; ++i__) {
	do_uio(&c__1, (char *)&data_1.z__[i__ - 1], (ftnlen)sizeof(doublereal)
		);
    }
    e_rsue();
    io___1103.ciunit = igfl;
    s_rsue(&io___1103);
    i__1 = data_1.n1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_uio(&c__1, (char *)&data_1.si[i__ - 1], (ftnlen)sizeof(doublereal))
		;
    }
    i__2 = data_1.n1;
    for (i__ = 1; i__ <= i__2; ++i__) {
	do_uio(&c__1, (char *)&data_1.bi[i__ - 1], (ftnlen)sizeof(doublereal))
		;
    }
    i__3 = data_1.n1;
    for (i__ = 1; i__ <= i__3; ++i__) {
	do_uio(&c__1, (char *)&data_1.alp[i__ - 1], (ftnlen)sizeof(doublereal)
		);
    }
    e_rsue();
    io___1104.ciunit = igfl;
    s_rsue(&io___1104);
    i__1 = data_1.n1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_uio(&c__1, (char *)&data_1.bet[i__ - 1], (ftnlen)sizeof(doublereal)
		);
    }
    i__2 = data_1.n1;
    for (i__ = 1; i__ <= i__2; ++i__) {
	do_uio(&c__1, (char *)&angl_1.salp[i__ - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_rsue();
    io___1105.ciunit = igfl;
    s_rsue(&io___1105);
    i__1 = data_1.n1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_uio(&c__1, (char *)&data_1.icon1[i__ - 1], (ftnlen)sizeof(integer))
		;
    }
    i__2 = data_1.n1;
    for (i__ = 1; i__ <= i__2; ++i__) {
	do_uio(&c__1, (char *)&data_1.icon2[i__ - 1], (ftnlen)sizeof(integer))
		;
    }
    e_rsue();
    io___1106.ciunit = igfl;
    s_rsue(&io___1106);
    i__1 = data_1.n1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_uio(&c__1, (char *)&data_1.itag[i__ - 1], (ftnlen)sizeof(integer));
    }
    e_rsue();
    if (zload_1.nlodf != 0) {
	io___1107.ciunit = igfl;
	s_rsue(&io___1107);
	i__1 = data_1.n1;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_uio(&c__2, (char *)&zload_1.zarray[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_rsue();
    }
    i__1 = data_1.n1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	xi = data_1.x[i__ - 1] * data_1.wlam;
	yi = data_1.y[i__ - 1] * data_1.wlam;
	zi = data_1.z__[i__ - 1] * data_1.wlam;
	dx = data_1.si[i__ - 1] * .5f * data_1.wlam;
	data_1.x[i__ - 1] = xi - data_1.alp[i__ - 1] * dx;
	data_1.y[i__ - 1] = yi - data_1.bet[i__ - 1] * dx;
	data_1.z__[i__ - 1] = zi - angl_1.salp[i__ - 1] * dx;
	data_1.si[i__ - 1] = xi + data_1.alp[i__ - 1] * dx;
	data_1.alp[i__ - 1] = yi + data_1.bet[i__ - 1] * dx;
	data_1.bet[i__ - 1] = zi + angl_1.salp[i__ - 1] * dx;
	data_1.bi[i__ - 1] *= data_1.wlam;
/* L1: */
    }
L2:
    if (data_1.m1 == 0) {
	goto L4;
    }
    j = data_1.ld - data_1.m1 + 1;
/*     READ PATCH DATA AND CONVERT TO METERS */
    io___1113.ciunit = igfl;
    s_rsue(&io___1113);
    i__1 = data_1.ld;
    for (i__ = j; i__ <= i__1; ++i__) {
	do_uio(&c__1, (char *)&data_1.x[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    i__2 = data_1.ld;
    for (i__ = j; i__ <= i__2; ++i__) {
	do_uio(&c__1, (char *)&data_1.y[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    i__3 = data_1.ld;
    for (i__ = j; i__ <= i__3; ++i__) {
	do_uio(&c__1, (char *)&data_1.z__[i__ - 1], (ftnlen)sizeof(doublereal)
		);
    }
    e_rsue();
    io___1114.ciunit = igfl;
    s_rsue(&io___1114);
    i__1 = data_1.ld;
    for (i__ = j; i__ <= i__1; ++i__) {
	do_uio(&c__1, (char *)&data_1.si[i__ - 1], (ftnlen)sizeof(doublereal))
		;
    }
    i__2 = data_1.ld;
    for (i__ = j; i__ <= i__2; ++i__) {
	do_uio(&c__1, (char *)&data_1.bi[i__ - 1], (ftnlen)sizeof(doublereal))
		;
    }
    i__3 = data_1.ld;
    for (i__ = j; i__ <= i__3; ++i__) {
	do_uio(&c__1, (char *)&data_1.alp[i__ - 1], (ftnlen)sizeof(doublereal)
		);
    }
    e_rsue();
    io___1115.ciunit = igfl;
    s_rsue(&io___1115);
    i__1 = data_1.ld;
    for (i__ = j; i__ <= i__1; ++i__) {
	do_uio(&c__1, (char *)&data_1.bet[i__ - 1], (ftnlen)sizeof(doublereal)
		);
    }
    i__2 = data_1.ld;
    for (i__ = j; i__ <= i__2; ++i__) {
	do_uio(&c__1, (char *)&angl_1.salp[i__ - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_rsue();
/* *** ERROR CORRECTED 11/20/89 ******************************* */
    io___1116.ciunit = igfl;
    s_rsue(&io___1116);
    i__1 = data_1.ld;
    for (i__ = j; i__ <= i__1; ++i__) {
	do_uio(&c__1, (char *)&t2x[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    i__2 = data_1.ld;
    for (i__ = j; i__ <= i__2; ++i__) {
	do_uio(&c__1, (char *)&t2y[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_rsue();
    io___1117.ciunit = igfl;
    s_rsue(&io___1117);
    i__1 = data_1.ld;
    for (i__ = j; i__ <= i__1; ++i__) {
	do_uio(&c__1, (char *)&t2z[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_rsue();
/*      READ (IGFL) (ICON1(I),I=J,LD),(ICON2(I),I=J,LD) */
/*      READ (IGFL) (ITAG(I),I=J,LD) */

    dx = data_1.wlam * data_1.wlam;
    i__1 = data_1.ld;
    for (i__ = j; i__ <= i__1; ++i__) {
	data_1.x[i__ - 1] *= data_1.wlam;
	data_1.y[i__ - 1] *= data_1.wlam;
	data_1.z__[i__ - 1] *= data_1.wlam;
/* L3: */
	data_1.bi[i__ - 1] *= dx;
    }
L4:
    io___1118.ciunit = igfl;
    s_rsue(&io___1118);
    do_uio(&c__1, (char *)&matpar_1.icase, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&matpar_1.nbloks, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&matpar_1.npblk, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&matpar_1.nlast, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&matpar_1.nblsym, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&matpar_1.npsym, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&matpar_1.nlsym, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&matpar_1.imat, (ftnlen)sizeof(integer));
    e_rsue();
    if (gnd_1.iperf == 2) {
	io___1119.ciunit = igfl;
	s_rsue(&io___1119);
	do_uio(&c__880, (char *)&ggrid_1.ar1[0], (ftnlen)sizeof(doublereal));
	do_uio(&c__680, (char *)&ggrid_1.ar2[0], (ftnlen)sizeof(doublereal));
	do_uio(&c__576, (char *)&ggrid_1.ar3[0], (ftnlen)sizeof(doublereal));
	do_uio(&c__2, (char *)&ggrid_1.epscf, (ftnlen)sizeof(doublereal));
	do_uio(&c__3, (char *)&ggrid_1.dxa[0], (ftnlen)sizeof(doublereal));
	do_uio(&c__3, (char *)&ggrid_1.dya[0], (ftnlen)sizeof(doublereal));
	do_uio(&c__3, (char *)&ggrid_1.xsa[0], (ftnlen)sizeof(doublereal));
	do_uio(&c__3, (char *)&ggrid_1.ysa[0], (ftnlen)sizeof(doublereal));
	do_uio(&c__3, (char *)&ggrid_1.nxa[0], (ftnlen)sizeof(integer));
	do_uio(&c__3, (char *)&ggrid_1.nya[0], (ftnlen)sizeof(integer));
	e_rsue();
    }
    neq = data_1.n1 + (data_1.m1 << 1);
    npeq = data_1.np + (data_1.mp << 1);
    nop = neq / npeq;
    if (nop > 1) {
	io___1123.ciunit = igfl;
	s_rsue(&io___1123);
	i__1 = nop;
	for (j = 1; j <= i__1; ++j) {
	    i__2 = nop;
	    for (i__ = 1; i__ <= i__2; ++i__) {
		do_uio(&c__2, (char *)&smat_1.ssx[i__ + (j << 4) - 17], (
			ftnlen)sizeof(doublereal));
	    }
	}
	e_rsue();
    }
    io___1124.ciunit = igfl;
    s_rsue(&io___1124);
    i__2 = neq;
    for (i__ = 1; i__ <= i__2; ++i__) {
	do_uio(&c__1, (char *)&save_1.ip[i__ - 1], (ftnlen)sizeof(integer));
    }
    do_uio(&c__95, (char *)&csave_1.com[0], (ftnlen)sizeof(doublereal));
    e_rsue();
/*     READ MATRIX A AND WRITE TAPE13 FOR OUT OF CORE */
    if (matpar_1.icase > 2) {
	goto L5;
    }
    iout = neq * npeq;
    io___1126.ciunit = igfl;
    s_rsue(&io___1126);
    i__2 = iout;
    for (i__ = 1; i__ <= i__2; ++i__) {
	do_uio(&c__2, (char *)&cmb_1.cm[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_rsue();
    goto L10;
L5:
    al__1.aerr = 0;
    al__1.aunit = 13;
    f_rew(&al__1);
    if (matpar_1.icase != 4) {
	goto L7;
    }
    iout = npeq * npeq;
    i__2 = nop;
    for (k = 1; k <= i__2; ++k) {
	io___1128.ciunit = igfl;
	s_rsue(&io___1128);
	i__1 = iout;
	for (j = 1; j <= i__1; ++j) {
	    do_uio(&c__2, (char *)&cmb_1.cm[j - 1], (ftnlen)sizeof(doublereal)
		    );
	}
	e_rsue();
/* L6: */
	s_wsue(&io___1129);
	i__1 = iout;
	for (j = 1; j <= i__1; ++j) {
	    do_uio(&c__2, (char *)&cmb_1.cm[j - 1], (ftnlen)sizeof(doublereal)
		    );
	}
	e_wsue();
    }
    goto L9;
L7:
    iout = matpar_1.npsym * npeq << 1;
    nbl2 = matpar_1.nblsym << 1;
    i__1 = nop;
    for (iop = 1; iop <= i__1; ++iop) {
	i__2 = nbl2;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    blckin_(cmb_1.cm, &igfl, &c__1, &iout, &c__1, &c__206);
/* L8: */
	    blckot_(cmb_1.cm, &c__13, &c__1, &iout, &c__1, &c__205);
	}
    }
L9:
    al__1.aerr = 0;
    al__1.aunit = 13;
    f_rew(&al__1);
L10:
    al__1.aerr = 0;
    al__1.aunit = igfl;
    f_rew(&al__1);
/*     WRITE(3,N) G.F. HEADING */
    s_wsfe(&io___1132);
    e_wsfe();
    s_wsfe(&io___1133);
    e_wsfe();
    s_wsfe(&io___1134);
    e_wsfe();
    s_wsfe(&io___1135);
    e_wsfe();
    s_wsfe(&io___1136);
    do_fio(&c__1, (char *)&data_1.n1, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&data_1.m1, (ftnlen)sizeof(integer));
    e_wsfe();
    if (nop > 1) {
	s_wsfe(&io___1137);
	do_fio(&c__1, (char *)&nop, (ftnlen)sizeof(integer));
	e_wsfe();
    }
    s_wsfe(&io___1138);
    do_fio(&c__1, (char *)&matpar_1.imat, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&matpar_1.icase, (ftnlen)sizeof(integer));
    e_wsfe();
    if (matpar_1.icase < 3) {
	goto L11;
    }
    nbl2 = neq * npeq;
    s_wsfe(&io___1139);
    do_fio(&c__1, (char *)&nbl2, (ftnlen)sizeof(integer));
    e_wsfe();
L11:
    s_wsfe(&io___1140);
    do_fio(&c__1, (char *)&save_1.fmhz, (ftnlen)sizeof(doublereal));
    e_wsfe();
    if (gnd_1.ksymp == 2 && gnd_1.iperf == 1) {
	s_wsfe(&io___1141);
	e_wsfe();
    }
    if (gnd_1.ksymp == 2 && gnd_1.iperf == 0) {
	s_wsfe(&io___1142);
	e_wsfe();
    }
    if (gnd_1.ksymp == 2 && gnd_1.iperf == 2) {
	s_wsfe(&io___1143);
	e_wsfe();
    }
    if (gnd_1.ksymp == 2 && gnd_1.iperf != 1) {
	s_wsfe(&io___1144);
	do_fio(&c__1, (char *)&save_1.epsr, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&save_1.sig, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    s_wsfe(&io___1145);
    e_wsfe();
    i__2 = save_1.kcom;
    for (j = 1; j <= i__2; ++j) {
/* L12: */
	s_wsfe(&io___1146);
	for (i__ = 1; i__ <= 19; ++i__) {
	    do_fio(&c__1, (char *)&csave_1.com[i__ + j * 19 - 20], (ftnlen)
		    sizeof(doublereal));
	}
	e_wsfe();
    }
    s_wsfe(&io___1147);
    e_wsfe();
    s_wsfe(&io___1148);
    e_wsfe();
    s_wsfe(&io___1149);
    e_wsfe();
    s_wsfe(&io___1150);
    e_wsfe();
    if (*iprt == 0) {
	return 0;
    }
    s_wsfe(&io___1151);
    e_wsfe();
    i__2 = data_1.n1;
    for (i__ = 1; i__ <= i__2; ++i__) {
/* L13: */
	s_wsfe(&io___1152);
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&data_1.x[i__ - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&data_1.y[i__ - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&data_1.z__[i__ - 1], (ftnlen)sizeof(doublereal)
		);
	do_fio(&c__1, (char *)&data_1.si[i__ - 1], (ftnlen)sizeof(doublereal))
		;
	do_fio(&c__1, (char *)&data_1.alp[i__ - 1], (ftnlen)sizeof(doublereal)
		);
	do_fio(&c__1, (char *)&data_1.bet[i__ - 1], (ftnlen)sizeof(doublereal)
		);
	e_wsfe();
    }
    return 0;

} /* gfil_ */

#undef t2z
#undef t2y
#undef t2x


/* Subroutine */ int gfld_(doublereal *rho, doublereal *phi, doublereal *rz, 
	doublecomplex *eth, doublecomplex *epi, doublecomplex *erd, 
	doublecomplex *ux, integer *ksymp)
{
    /* Initialized data */

    static doublereal pi = 3.141592654;
    static doublereal tp = 6.283185308;

    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2;
    doublecomplex z__1, z__2, z__3, z__4, z__5;

    /* Builtin functions */
    double sqrt(doublereal), z_abs(doublecomplex *), atan(doublereal), cos(
	    doublereal), sin(doublereal);

    /* Local variables */
    doublereal a, b, c__;
    integer i__, k;
    doublereal r__, el, ri;
    doublecomplex ex, ey;
    doublereal dx, dy, dz, rr, rx, ry;
#define cab ((doublereal *)&data_1 + 7500)
#define sab ((doublereal *)&data_1 + 9000)
    doublereal arg;
    doublecomplex eph, exa, erh, cix, ciy, ciz, ezh, erv;
    doublereal phx, phy, rix;
    doublecomplex ezv;
    doublereal riy, rhs, rhp, rhx, rhy, cph, sph, rfl, riz, rnx, rny, rnz, 
	    top, bot, too, boo, thx, thy, thz;
    extern /* Subroutine */ int ffld_(doublereal *, doublereal *, 
	    doublecomplex *, doublecomplex *);
    doublereal cbet, calp, sbet, sill, thet, rxyz, omega;
    extern /* Subroutine */ int gwave_(doublecomplex *, doublecomplex *, 
	    doublecomplex *, doublecomplex *, doublecomplex *);

/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* Max number of segments 	(Windows-95 <= 4 */
/* max nr of 'in-core' alloc.	(MAXMAT <= MA */
/* Max number of LD cards */
/* Max number of EX cards */
/* Max number of segs connected to NT/TL */
/* *** */

/*     GFLD COMPUTES THE RADIATED FIELD INCLUDING GROUND WAVE. */

    r__ = sqrt(*rho * *rho + *rz * *rz);
    if (*ksymp == 1) {
	goto L1;
    }
    if (z_abs(ux) > .5f) {
	goto L1;
    }
    if (r__ > 1e5f) {
	goto L1;
    }
    goto L4;

/*     COMPUTATION OF SPACE WAVE ONLY */

L1:
    if (*rz < 1e-20) {
	goto L2;
    }
    thet = atan(*rho / *rz);
    goto L3;
L2:
    thet = pi * .5f;
L3:
    ffld_(&thet, phi, eth, epi);
    arg = -tp * r__;
    d__1 = cos(arg);
    d__2 = sin(arg);
    z__2.r = d__1, z__2.i = d__2;
    z__1.r = z__2.r / r__, z__1.i = z__2.i / r__;
    exa.r = z__1.r, exa.i = z__1.i;
    z__1.r = eth->r * exa.r - eth->i * exa.i, z__1.i = eth->r * exa.i + 
	    eth->i * exa.r;
    eth->r = z__1.r, eth->i = z__1.i;
    z__1.r = epi->r * exa.r - epi->i * exa.i, z__1.i = epi->r * exa.i + 
	    epi->i * exa.r;
    epi->r = z__1.r, epi->i = z__1.i;
    erd->r = 0.f, erd->i = 0.f;
    return 0;

/*     COMPUTATION OF SPACE AND GROUND WAVES. */

L4:
    gwav_1.u.r = ux->r, gwav_1.u.i = ux->i;
    z__1.r = gwav_1.u.r * gwav_1.u.r - gwav_1.u.i * gwav_1.u.i, z__1.i = 
	    gwav_1.u.r * gwav_1.u.i + gwav_1.u.i * gwav_1.u.r;
    gwav_1.u2.r = z__1.r, gwav_1.u2.i = z__1.i;
    phx = -sin(*phi);
    phy = cos(*phi);
    rx = *rho * phy;
    ry = -(*rho) * phx;
    cix.r = 0.f, cix.i = 0.f;
    ciy.r = 0.f, ciy.i = 0.f;
    ciz.r = 0.f, ciz.i = 0.f;

/*     SUMMATION OF FIELD FROM INDIVIDUAL SEGMENTS */

    i__1 = data_1.n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	dx = cab[i__ - 1];
	dy = sab[i__ - 1];
	dz = angl_1.salp[i__ - 1];
	rix = rx - data_1.x[i__ - 1];
	riy = ry - data_1.y[i__ - 1];
	rhs = rix * rix + riy * riy;
	rhp = sqrt(rhs);
	if (rhp < 1e-6) {
	    goto L5;
	}
	rhx = rix / rhp;
	rhy = riy / rhp;
	goto L6;
L5:
	rhx = 1.f;
	rhy = 0.f;
L6:
	calp = 1.f - dz * dz;
	if (calp < 1e-6) {
	    goto L7;
	}
	calp = sqrt(calp);
	cbet = dx / calp;
	sbet = dy / calp;
	cph = rhx * cbet + rhy * sbet;
	sph = rhy * cbet - rhx * sbet;
	goto L8;
L7:
	cph = rhx;
	sph = rhy;
L8:
	el = pi * data_1.si[i__ - 1];
	rfl = -1.f;

/*     INTEGRATION OF (CURRENT)*(PHASE FACTOR) OVER SEGMENT AND IMAGE FOR */
/*     CONSTANT, SINE, AND COSINE CURRENT DISTRIBUTIONS */

	for (k = 1; k <= 2; ++k) {
	    rfl = -rfl;
	    riz = *rz - data_1.z__[i__ - 1] * rfl;
	    rxyz = sqrt(rix * rix + riy * riy + riz * riz);
	    rnx = rix / rxyz;
	    rny = riy / rxyz;
	    rnz = riz / rxyz;
	    omega = -(rnx * dx + rny * dy + rnz * dz * rfl);
	    sill = omega * el;
	    top = el + sill;
	    bot = el - sill;
	    if (abs(omega) < 1e-7) {
		goto L9;
	    }
	    a = sin(sill) * 2.f / omega;
	    goto L10;
L9:
	    a = (2.f - omega * omega * el * el / 3.f) * el;
L10:
	    if (abs(top) < 1e-7) {
		goto L11;
	    }
	    too = sin(top) / top;
	    goto L12;
L11:
	    too = 1.f - top * top / 6.f;
L12:
	    if (abs(bot) < 1e-7) {
		goto L13;
	    }
	    boo = sin(bot) / bot;
	    goto L14;
L13:
	    boo = 1.f - bot * bot / 6.f;
L14:
	    b = el * (boo - too);
	    c__ = el * (boo + too);
	    rr = a * crnt_1.air[i__ - 1] + b * crnt_1.bii[i__ - 1] + c__ * 
		    crnt_1.cir[i__ - 1];
	    ri = a * crnt_1.aii[i__ - 1] - b * crnt_1.bir[i__ - 1] + c__ * 
		    crnt_1.cii[i__ - 1];
	    arg = tp * (data_1.x[i__ - 1] * rnx + data_1.y[i__ - 1] * rny + 
		    data_1.z__[i__ - 1] * rnz * rfl);
	    d__1 = cos(arg);
	    d__2 = sin(arg);
	    z__3.r = d__1, z__3.i = d__2;
	    z__4.r = rr, z__4.i = ri;
	    z__2.r = z__3.r * z__4.r - z__3.i * z__4.i, z__2.i = z__3.r * 
		    z__4.i + z__3.i * z__4.r;
	    z__1.r = z__2.r / tp, z__1.i = z__2.i / tp;
	    exa.r = z__1.r, exa.i = z__1.i;
	    if (k == 2) {
		goto L15;
	    }
	    gwav_1.xx1.r = exa.r, gwav_1.xx1.i = exa.i;
	    gwav_1.r1 = rxyz;
	    gwav_1.zmh = riz;
	    goto L16;
L15:
	    gwav_1.xx2.r = exa.r, gwav_1.xx2.i = exa.i;
	    gwav_1.r2 = rxyz;
	    gwav_1.zph = riz;
L16:
	    ;
	}

/*     CALL SUBROUTINE TO COMPUTE THE FIELD OF SEGMENT INCLUDING GROUND */
/*     WAVE. */

	gwave_(&erv, &ezv, &erh, &ezh, &eph);
	z__3.r = cph * erh.r, z__3.i = cph * erh.i;
	z__2.r = calp * z__3.r, z__2.i = calp * z__3.i;
	z__4.r = dz * erv.r, z__4.i = dz * erv.i;
	z__1.r = z__2.r + z__4.r, z__1.i = z__2.i + z__4.i;
	erh.r = z__1.r, erh.i = z__1.i;
	z__2.r = sph * eph.r, z__2.i = sph * eph.i;
	z__1.r = calp * z__2.r, z__1.i = calp * z__2.i;
	eph.r = z__1.r, eph.i = z__1.i;
	z__3.r = cph * ezh.r, z__3.i = cph * ezh.i;
	z__2.r = calp * z__3.r, z__2.i = calp * z__3.i;
	z__4.r = dz * ezv.r, z__4.i = dz * ezv.i;
	z__1.r = z__2.r + z__4.r, z__1.i = z__2.i + z__4.i;
	ezh.r = z__1.r, ezh.i = z__1.i;
	z__2.r = rhx * erh.r, z__2.i = rhx * erh.i;
	z__3.r = rhy * eph.r, z__3.i = rhy * eph.i;
	z__1.r = z__2.r - z__3.r, z__1.i = z__2.i - z__3.i;
	ex.r = z__1.r, ex.i = z__1.i;
	z__2.r = rhy * erh.r, z__2.i = rhy * erh.i;
	z__3.r = rhx * eph.r, z__3.i = rhx * eph.i;
	z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
	ey.r = z__1.r, ey.i = z__1.i;
	z__1.r = cix.r + ex.r, z__1.i = cix.i + ex.i;
	cix.r = z__1.r, cix.i = z__1.i;
	z__1.r = ciy.r + ey.r, z__1.i = ciy.i + ey.i;
	ciy.r = z__1.r, ciy.i = z__1.i;
/* L17: */
	z__1.r = ciz.r + ezh.r, z__1.i = ciz.i + ezh.i;
	ciz.r = z__1.r, ciz.i = z__1.i;
    }
    arg = -tp * r__;
    d__1 = cos(arg);
    d__2 = sin(arg);
    z__1.r = d__1, z__1.i = d__2;
    exa.r = z__1.r, exa.i = z__1.i;
    z__1.r = cix.r * exa.r - cix.i * exa.i, z__1.i = cix.r * exa.i + cix.i * 
	    exa.r;
    cix.r = z__1.r, cix.i = z__1.i;
    z__1.r = ciy.r * exa.r - ciy.i * exa.i, z__1.i = ciy.r * exa.i + ciy.i * 
	    exa.r;
    ciy.r = z__1.r, ciy.i = z__1.i;
    z__1.r = ciz.r * exa.r - ciz.i * exa.i, z__1.i = ciz.r * exa.i + ciz.i * 
	    exa.r;
    ciz.r = z__1.r, ciz.i = z__1.i;
    rnx = rx / r__;
    rny = ry / r__;
    rnz = *rz / r__;
    thx = rnz * phy;
    thy = -rnz * phx;
    thz = -(*rho) / r__;
    z__3.r = thx * cix.r, z__3.i = thx * cix.i;
    z__4.r = thy * ciy.r, z__4.i = thy * ciy.i;
    z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
    z__5.r = thz * ciz.r, z__5.i = thz * ciz.i;
    z__1.r = z__2.r + z__5.r, z__1.i = z__2.i + z__5.i;
    eth->r = z__1.r, eth->i = z__1.i;
    z__2.r = phx * cix.r, z__2.i = phx * cix.i;
    z__3.r = phy * ciy.r, z__3.i = phy * ciy.i;
    z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
    epi->r = z__1.r, epi->i = z__1.i;
    z__3.r = rnx * cix.r, z__3.i = rnx * cix.i;
    z__4.r = rny * ciy.r, z__4.i = rny * ciy.i;
    z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
    z__5.r = rnz * ciz.r, z__5.i = rnz * ciz.i;
    z__1.r = z__2.r + z__5.r, z__1.i = z__2.i + z__5.i;
    erd->r = z__1.r, erd->i = z__1.i;
    return 0;
} /* gfld_ */

#undef sab
#undef cab


/* Subroutine */ int gfout_(void)
{
    /* Initialized data */

    static integer igfl = 20;

    /* Format strings */
    static char fmt_13[] = "(///,\002 ****NUMERICAL GREEN'S FUNCTION FILE ON"
	    " TAPE\002,i3,\002\r****\002,/,5x,\002MATRIX STORAGE -\002,i7,"
	    "\002 COMPLEX NUMBERS\002,///)";

    /* System generated locals */
    integer i__1, i__2, i__3;
    olist o__1;
    alist al__1;

    /* Builtin functions */
    integer f_open(olist *), s_wsue(cilist *), do_uio(integer *, char *, 
	    ftnlen), e_wsue(void), f_rew(alist *), s_rsue(cilist *), e_rsue(
	    void), s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), 
	    e_wsfe(void);

    /* Local variables */
    integer i__, j, k;
#define t2x ((doublereal *)&data_1 + 10501)
#define t2y ((doublereal *)&data_1 + 12001)
#define t2z ((doublereal *)&data_1 + 13501)
    integer neq, iop, nop, npeq, iout;
    extern /* Subroutine */ int blckin_(doublecomplex *, integer *, integer *,
	     integer *, integer *, integer *), blckot_(doublecomplex *, 
	    integer *, integer *, integer *, integer *, integer *);

    /* Fortran I/O blocks */
    static cilist io___1219 = { 0, 0, 0, 0, 0 };
    static cilist io___1220 = { 0, 0, 0, 0, 0 };
    static cilist io___1222 = { 0, 0, 0, 0, 0 };
    static cilist io___1223 = { 0, 0, 0, 0, 0 };
    static cilist io___1224 = { 0, 0, 0, 0, 0 };
    static cilist io___1225 = { 0, 0, 0, 0, 0 };
    static cilist io___1226 = { 0, 0, 0, 0, 0 };
    static cilist io___1228 = { 0, 0, 0, 0, 0 };
    static cilist io___1229 = { 0, 0, 0, 0, 0 };
    static cilist io___1230 = { 0, 0, 0, 0, 0 };
    static cilist io___1231 = { 0, 0, 0, 0, 0 };
    static cilist io___1232 = { 0, 0, 0, 0, 0 };
    static cilist io___1233 = { 0, 0, 0, 0, 0 };
    static cilist io___1234 = { 0, 0, 0, 0, 0 };
    static cilist io___1235 = { 0, 0, 0, 0, 0 };
    static cilist io___1236 = { 0, 0, 0, 0, 0 };
    static cilist io___1238 = { 0, 0, 0, 0, 0 };
    static cilist io___1240 = { 0, 13, 0, 0, 0 };
    static cilist io___1241 = { 0, 0, 0, 0, 0 };
    static cilist io___1243 = { 0, 3, 0, fmt_13, 0 };


/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* Max number of segments 	(Windows-95 <= 4 */
/* max nr of 'in-core' alloc.	(MAXMAT <= MA */
/* Max number of LD cards */
/* Max number of EX cards */
/* Max number of segs connected to NT/TL */
/* *** */

/*     WRITE N.G.F. FILE */


/* *** ERROR CORRECTED 11/20/89 ******************************* */
/* *** */
/* av04 OPEN(UNIT=IGFL,FILE='NGF2D.NEC',FORM='UNFORMATTED',STATUS='NEW') */
    o__1.oerr = 0;
    o__1.ounit = igfl;
    o__1.ofnmlen = 9;
    o__1.ofnm = "NGF2D.NEC";
    o__1.orl = 0;
    o__1.osta = "UNKNOWN";
    o__1.oacc = 0;
    o__1.ofm = "UNFORMATTED";
    o__1.oblnk = 0;
    f_open(&o__1);
    neq = data_1.n + (data_1.m << 1);
    npeq = data_1.np + (data_1.mp << 1);
    nop = neq / npeq;
    io___1219.ciunit = igfl;
    s_wsue(&io___1219);
    do_uio(&c__1, (char *)&data_1.n, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&data_1.np, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&data_1.m, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&data_1.mp, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&data_1.wlam, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&save_1.fmhz, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&data_1.ipsym, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&gnd_1.ksymp, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&gnd_1.iperf, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&gnd_1.nradl, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&save_1.epsr, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&save_1.sig, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&save_1.scrwlt, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&save_1.scrwrt, (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&zload_1.nload, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&save_1.kcom, (ftnlen)sizeof(integer));
    e_wsue();
    if (data_1.n == 0) {
	goto L1;
    }
    io___1220.ciunit = igfl;
    s_wsue(&io___1220);
    i__1 = data_1.n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_uio(&c__1, (char *)&data_1.x[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    i__2 = data_1.n;
    for (i__ = 1; i__ <= i__2; ++i__) {
	do_uio(&c__1, (char *)&data_1.y[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    i__3 = data_1.n;
    for (i__ = 1; i__ <= i__3; ++i__) {
	do_uio(&c__1, (char *)&data_1.z__[i__ - 1], (ftnlen)sizeof(doublereal)
		);
    }
    e_wsue();
    io___1222.ciunit = igfl;
    s_wsue(&io___1222);
    i__1 = data_1.n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_uio(&c__1, (char *)&data_1.si[i__ - 1], (ftnlen)sizeof(doublereal))
		;
    }
    i__2 = data_1.n;
    for (i__ = 1; i__ <= i__2; ++i__) {
	do_uio(&c__1, (char *)&data_1.bi[i__ - 1], (ftnlen)sizeof(doublereal))
		;
    }
    i__3 = data_1.n;
    for (i__ = 1; i__ <= i__3; ++i__) {
	do_uio(&c__1, (char *)&data_1.alp[i__ - 1], (ftnlen)sizeof(doublereal)
		);
    }
    e_wsue();
    io___1223.ciunit = igfl;
    s_wsue(&io___1223);
    i__1 = data_1.n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_uio(&c__1, (char *)&data_1.bet[i__ - 1], (ftnlen)sizeof(doublereal)
		);
    }
    i__2 = data_1.n;
    for (i__ = 1; i__ <= i__2; ++i__) {
	do_uio(&c__1, (char *)&angl_1.salp[i__ - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsue();
    io___1224.ciunit = igfl;
    s_wsue(&io___1224);
    i__1 = data_1.n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_uio(&c__1, (char *)&data_1.icon1[i__ - 1], (ftnlen)sizeof(integer))
		;
    }
    i__2 = data_1.n;
    for (i__ = 1; i__ <= i__2; ++i__) {
	do_uio(&c__1, (char *)&data_1.icon2[i__ - 1], (ftnlen)sizeof(integer))
		;
    }
    e_wsue();
    io___1225.ciunit = igfl;
    s_wsue(&io___1225);
    i__1 = data_1.n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_uio(&c__1, (char *)&data_1.itag[i__ - 1], (ftnlen)sizeof(integer));
    }
    e_wsue();
    if (zload_1.nload > 0) {
	io___1226.ciunit = igfl;
	s_wsue(&io___1226);
	i__1 = data_1.n;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_uio(&c__2, (char *)&zload_1.zarray[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsue();
    }
L1:
    if (data_1.m == 0) {
	goto L2;
    }
    j = data_1.ld - data_1.m + 1;
    io___1228.ciunit = igfl;
    s_wsue(&io___1228);
    i__1 = data_1.ld;
    for (i__ = j; i__ <= i__1; ++i__) {
	do_uio(&c__1, (char *)&data_1.x[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    i__2 = data_1.ld;
    for (i__ = j; i__ <= i__2; ++i__) {
	do_uio(&c__1, (char *)&data_1.y[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    i__3 = data_1.ld;
    for (i__ = j; i__ <= i__3; ++i__) {
	do_uio(&c__1, (char *)&data_1.z__[i__ - 1], (ftnlen)sizeof(doublereal)
		);
    }
    e_wsue();
    io___1229.ciunit = igfl;
    s_wsue(&io___1229);
    i__1 = data_1.ld;
    for (i__ = j; i__ <= i__1; ++i__) {
	do_uio(&c__1, (char *)&data_1.si[i__ - 1], (ftnlen)sizeof(doublereal))
		;
    }
    i__2 = data_1.ld;
    for (i__ = j; i__ <= i__2; ++i__) {
	do_uio(&c__1, (char *)&data_1.bi[i__ - 1], (ftnlen)sizeof(doublereal))
		;
    }
    i__3 = data_1.ld;
    for (i__ = j; i__ <= i__3; ++i__) {
	do_uio(&c__1, (char *)&data_1.alp[i__ - 1], (ftnlen)sizeof(doublereal)
		);
    }
    e_wsue();
    io___1230.ciunit = igfl;
    s_wsue(&io___1230);
    i__1 = data_1.ld;
    for (i__ = j; i__ <= i__1; ++i__) {
	do_uio(&c__1, (char *)&data_1.bet[i__ - 1], (ftnlen)sizeof(doublereal)
		);
    }
    i__2 = data_1.ld;
    for (i__ = j; i__ <= i__2; ++i__) {
	do_uio(&c__1, (char *)&angl_1.salp[i__ - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsue();

/* *** ERROR CORRECTED 11/20/89 ******************************* */
    io___1231.ciunit = igfl;
    s_wsue(&io___1231);
    i__1 = data_1.ld;
    for (i__ = j; i__ <= i__1; ++i__) {
	do_uio(&c__1, (char *)&t2x[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    i__2 = data_1.ld;
    for (i__ = j; i__ <= i__2; ++i__) {
	do_uio(&c__1, (char *)&t2y[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsue();
    io___1232.ciunit = igfl;
    s_wsue(&io___1232);
    i__1 = data_1.ld;
    for (i__ = j; i__ <= i__1; ++i__) {
	do_uio(&c__1, (char *)&t2z[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsue();
/*      WRITE (IGFL) (ICON1(I),I=J,LD),(ICON2(I),I=J,LD) */
/*      WRITE (IGFL) (ITAG(I),I=J,LD) */

L2:
    io___1233.ciunit = igfl;
    s_wsue(&io___1233);
    do_uio(&c__1, (char *)&matpar_1.icase, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&matpar_1.nbloks, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&matpar_1.npblk, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&matpar_1.nlast, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&matpar_1.nblsym, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&matpar_1.npsym, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&matpar_1.nlsym, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&matpar_1.imat, (ftnlen)sizeof(integer));
    e_wsue();
    if (gnd_1.iperf == 2) {
	io___1234.ciunit = igfl;
	s_wsue(&io___1234);
	do_uio(&c__880, (char *)&ggrid_1.ar1[0], (ftnlen)sizeof(doublereal));
	do_uio(&c__680, (char *)&ggrid_1.ar2[0], (ftnlen)sizeof(doublereal));
	do_uio(&c__576, (char *)&ggrid_1.ar3[0], (ftnlen)sizeof(doublereal));
	do_uio(&c__2, (char *)&ggrid_1.epscf, (ftnlen)sizeof(doublereal));
	do_uio(&c__3, (char *)&ggrid_1.dxa[0], (ftnlen)sizeof(doublereal));
	do_uio(&c__3, (char *)&ggrid_1.dya[0], (ftnlen)sizeof(doublereal));
	do_uio(&c__3, (char *)&ggrid_1.xsa[0], (ftnlen)sizeof(doublereal));
	do_uio(&c__3, (char *)&ggrid_1.ysa[0], (ftnlen)sizeof(doublereal));
	do_uio(&c__3, (char *)&ggrid_1.nxa[0], (ftnlen)sizeof(integer));
	do_uio(&c__3, (char *)&ggrid_1.nya[0], (ftnlen)sizeof(integer));
	e_wsue();
    }
    if (nop > 1) {
	io___1235.ciunit = igfl;
	s_wsue(&io___1235);
	i__1 = nop;
	for (j = 1; j <= i__1; ++j) {
	    i__2 = nop;
	    for (i__ = 1; i__ <= i__2; ++i__) {
		do_uio(&c__2, (char *)&smat_1.ssx[i__ + (j << 4) - 17], (
			ftnlen)sizeof(doublereal));
	    }
	}
	e_wsue();
    }
    io___1236.ciunit = igfl;
    s_wsue(&io___1236);
    i__2 = neq;
    for (i__ = 1; i__ <= i__2; ++i__) {
	do_uio(&c__1, (char *)&save_1.ip[i__ - 1], (ftnlen)sizeof(integer));
    }
    do_uio(&c__95, (char *)&csave_1.com[0], (ftnlen)sizeof(doublereal));
    e_wsue();
    if (matpar_1.icase > 2) {
	goto L3;
    }
    iout = neq * npeq;
    io___1238.ciunit = igfl;
    s_wsue(&io___1238);
    i__2 = iout;
    for (i__ = 1; i__ <= i__2; ++i__) {
	do_uio(&c__2, (char *)&cmb_1.cm[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsue();
    goto L12;
L3:
    if (matpar_1.icase != 4) {
	goto L5;
    }
    al__1.aerr = 0;
    al__1.aunit = 13;
    f_rew(&al__1);
    i__ = npeq * npeq;
    i__2 = nop;
    for (k = 1; k <= i__2; ++k) {
	s_rsue(&io___1240);
	i__1 = i__;
	for (j = 1; j <= i__1; ++j) {
	    do_uio(&c__2, (char *)&cmb_1.cm[j - 1], (ftnlen)sizeof(doublereal)
		    );
	}
	e_rsue();
/* L4: */
	io___1241.ciunit = igfl;
	s_wsue(&io___1241);
	i__1 = i__;
	for (j = 1; j <= i__1; ++j) {
	    do_uio(&c__2, (char *)&cmb_1.cm[j - 1], (ftnlen)sizeof(doublereal)
		    );
	}
	e_wsue();
    }
    al__1.aerr = 0;
    al__1.aunit = 13;
    f_rew(&al__1);
    goto L12;
L5:
    al__1.aerr = 0;
    al__1.aunit = 13;
    f_rew(&al__1);
    al__1.aerr = 0;
    al__1.aunit = 14;
    f_rew(&al__1);
    if (matpar_1.icase == 5) {
	goto L8;
    }
    iout = matpar_1.npblk * neq << 1;
    i__1 = matpar_1.nbloks;
    for (i__ = 1; i__ <= i__1; ++i__) {
	blckin_(cmb_1.cm, &c__13, &c__1, &iout, &c__1, &c__201);
/* L6: */
	blckot_(cmb_1.cm, &igfl, &c__1, &iout, &c__1, &c__202);
    }
    i__1 = matpar_1.nbloks;
    for (i__ = 1; i__ <= i__1; ++i__) {
	blckin_(cmb_1.cm, &c__14, &c__1, &iout, &c__1, &c__203);
/* L7: */
	blckot_(cmb_1.cm, &igfl, &c__1, &iout, &c__1, &c__204);
    }
    goto L12;
L8:
    iout = matpar_1.npsym * npeq << 1;
    i__1 = nop;
    for (iop = 1; iop <= i__1; ++iop) {
	i__2 = matpar_1.nblsym;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    blckin_(cmb_1.cm, &c__13, &c__1, &iout, &c__1, &c__205);
/* L9: */
	    blckot_(cmb_1.cm, &igfl, &c__1, &iout, &c__1, &c__206);
	}
	i__2 = matpar_1.nblsym;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    blckin_(cmb_1.cm, &c__14, &c__1, &iout, &c__1, &c__207);
/* L10: */
	    blckot_(cmb_1.cm, &igfl, &c__1, &iout, &c__1, &c__208);
	}
/* L11: */
    }
    al__1.aerr = 0;
    al__1.aunit = 13;
    f_rew(&al__1);
    al__1.aerr = 0;
    al__1.aunit = 14;
    f_rew(&al__1);
L12:
    al__1.aerr = 0;
    al__1.aunit = igfl;
    f_rew(&al__1);
    s_wsfe(&io___1243);
    do_fio(&c__1, (char *)&igfl, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&matpar_1.imat, (ftnlen)sizeof(integer));
    e_wsfe();
    return 0;

} /* gfout_ */

#undef t2z
#undef t2y
#undef t2x


/* Subroutine */ int gh_(doublereal *zk, doublereal *hr, doublereal *hi)
{
    /* Builtin functions */
    double sqrt(doublereal), cos(doublereal), sin(doublereal);

    /* Local variables */
    doublereal r__, rs, rr2, rr3, ckr, skr;

/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* *** */
/*     INTEGRAND FOR H FIELD OF A WIRE */
    rs = *zk - tmh_1.zpk;
    rs = tmh_1.rhks + rs * rs;
    r__ = sqrt(rs);
    ckr = cos(r__);
    skr = sin(r__);
    rr2 = 1.f / rs;
    rr3 = rr2 / r__;
    *hr = skr * rr2 + ckr * rr3;
    *hi = ckr * rr2 - skr * rr3;
    return 0;
} /* gh_ */

/* Subroutine */ int gwave_(doublecomplex *erv, doublecomplex *ezv, 
	doublecomplex *erh, doublecomplex *ezh, doublecomplex *eph)
{
    /* Initialized data */

    static struct {
	doublereal e_1[2];
	} equiv_0 = { 0., 1. };

    static struct {
	doublereal e_1[2];
	} equiv_1 = { 0., 6.283185308 };

    static struct {
	doublereal e_1[2];
	} equiv_2 = { 0., -188.367 };


    /* System generated locals */
    doublereal d__1;
    doublecomplex z__1, z__2, z__3, z__4, z__5, z__6, z__7, z__8, z__9, z__10,
	     z__11, z__12, z__13, z__14;

    /* Builtin functions */
    double sqrt(doublereal);
    void z_sqrt(doublecomplex *, doublecomplex *), z_div(doublecomplex *, 
	    doublecomplex *, doublecomplex *);

    /* Local variables */
    doublecomplex f, g, v, w, p1, q1, t1, t2, t3, t4, x1, x2, x3, x4, x5, x6, 
	    x7;
#define fj ((doublecomplex *)&equiv_0)
    doublecomplex rh, rv, rk1, rk2, xr1, xr2;
    doublereal cpp;
#define fjx ((doublereal *)&equiv_0)
#define tpj ((doublecomplex *)&equiv_1)
    doublecomplex omr;
    doublereal spp, cpp2, spp2;
    extern /* Double Complex */ VOID fbar_(doublecomplex *, doublecomplex *);
#define econ ((doublecomplex *)&equiv_2)
    doublereal cppp, sppp;
#define tpjx ((doublereal *)&equiv_1)
    doublereal cppp2, sppp2;
#define econx ((doublereal *)&equiv_2)

/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* *** */

/*     GWAVE COMPUTES THE ELECTRIC FIELD, INCLUDING GROUND WAVE, OF A */
/*     CURRENT ELEMENT OVER A GROUND PLANE USING FORMULAS OF K.A. NORTON */
/*     (PROC. IRE, SEPT., 1937, PP.1203,1236.) */

/* av01 DATA PI/3.141592654D+0/,FJX/0.,1./,TPJX/0.,6.283185308D+0/ */
    sppp = gwav_1.zmh / gwav_1.r1;
    sppp2 = sppp * sppp;
    cppp2 = 1.f - sppp2;
    if (cppp2 < 1e-20) {
	cppp2 = 1e-20;
    }
    cppp = sqrt(cppp2);
    spp = gwav_1.zph / gwav_1.r2;
    spp2 = spp * spp;
    cpp2 = 1.f - spp2;
    if (cpp2 < 1e-20) {
	cpp2 = 1e-20;
    }
    cpp = sqrt(cpp2);
    z__2.r = -tpj->r, z__2.i = -tpj->i;
    z__1.r = gwav_1.r1 * z__2.r, z__1.i = gwav_1.r1 * z__2.i;
    rk1.r = z__1.r, rk1.i = z__1.i;
    z__2.r = -tpj->r, z__2.i = -tpj->i;
    z__1.r = gwav_1.r2 * z__2.r, z__1.i = gwav_1.r2 * z__2.i;
    rk2.r = z__1.r, rk2.i = z__1.i;
    z__2.r = cpp2 * gwav_1.u2.r, z__2.i = cpp2 * gwav_1.u2.i;
    z__1.r = 1.f - z__2.r, z__1.i = -z__2.i;
    t1.r = z__1.r, t1.i = z__1.i;
    z_sqrt(&z__1, &t1);
    t2.r = z__1.r, t2.i = z__1.i;
    z_div(&z__3, &c_b245, &rk1);
    z__2.r = 1.f - z__3.r, z__2.i = -z__3.i;
    z_div(&z__1, &z__2, &rk1);
    t3.r = z__1.r, t3.i = z__1.i;
    z_div(&z__3, &c_b245, &rk2);
    z__2.r = 1.f - z__3.r, z__2.i = -z__3.i;
    z_div(&z__1, &z__2, &rk2);
    t4.r = z__1.r, t4.i = z__1.i;
    z__3.r = rk2.r * gwav_1.u2.r - rk2.i * gwav_1.u2.i, z__3.i = rk2.r * 
	    gwav_1.u2.i + rk2.i * gwav_1.u2.r;
    z__2.r = z__3.r * t1.r - z__3.i * t1.i, z__2.i = z__3.r * t1.i + z__3.i * 
	    t1.r;
    d__1 = cpp2 * 2.f;
    z__1.r = z__2.r / d__1, z__1.i = z__2.i / d__1;
    p1.r = z__1.r, p1.i = z__1.i;
    z__3.r = gwav_1.u.r * t2.r - gwav_1.u.i * t2.i, z__3.i = gwav_1.u.r * 
	    t2.i + gwav_1.u.i * t2.r;
    z__2.r = spp - z__3.r, z__2.i = -z__3.i;
    z__5.r = gwav_1.u.r * t2.r - gwav_1.u.i * t2.i, z__5.i = gwav_1.u.r * 
	    t2.i + gwav_1.u.i * t2.r;
    z__4.r = spp + z__5.r, z__4.i = z__5.i;
    z_div(&z__1, &z__2, &z__4);
    rv.r = z__1.r, rv.i = z__1.i;
    z__1.r = 1.f - rv.r, z__1.i = -rv.i;
    omr.r = z__1.r, omr.i = z__1.i;
    z_div(&z__1, &c_b245, &omr);
    w.r = z__1.r, w.i = z__1.i;
    z__3.r = p1.r * 4.f - p1.i * 0.f, z__3.i = p1.r * 0.f + p1.i * 4.f;
    z__2.r = z__3.r * w.r - z__3.i * w.i, z__2.i = z__3.r * w.i + z__3.i * 
	    w.r;
    z__1.r = z__2.r * w.r - z__2.i * w.i, z__1.i = z__2.r * w.i + z__2.i * 
	    w.r;
    w.r = z__1.r, w.i = z__1.i;
    fbar_(&z__1, &w);
    f.r = z__1.r, f.i = z__1.i;
    z__2.r = rk2.r * t1.r - rk2.i * t1.i, z__2.i = rk2.r * t1.i + rk2.i * 
	    t1.r;
    z__4.r = gwav_1.u2.r * 2.f, z__4.i = gwav_1.u2.i * 2.f;
    z__3.r = cpp2 * z__4.r, z__3.i = cpp2 * z__4.i;
    z_div(&z__1, &z__2, &z__3);
    q1.r = z__1.r, q1.i = z__1.i;
    z__3.r = spp * gwav_1.u.r, z__3.i = spp * gwav_1.u.i;
    z__2.r = t2.r - z__3.r, z__2.i = t2.i - z__3.i;
    z__5.r = spp * gwav_1.u.r, z__5.i = spp * gwav_1.u.i;
    z__4.r = t2.r + z__5.r, z__4.i = t2.i + z__5.i;
    z_div(&z__1, &z__2, &z__4);
    rh.r = z__1.r, rh.i = z__1.i;
    z__2.r = rh.r + 1.f, z__2.i = rh.i;
    z_div(&z__1, &c_b245, &z__2);
    v.r = z__1.r, v.i = z__1.i;
    z__3.r = q1.r * 4.f - q1.i * 0.f, z__3.i = q1.r * 0.f + q1.i * 4.f;
    z__2.r = z__3.r * v.r - z__3.i * v.i, z__2.i = z__3.r * v.i + z__3.i * 
	    v.r;
    z__1.r = z__2.r * v.r - z__2.i * v.i, z__1.i = z__2.r * v.i + z__2.i * 
	    v.r;
    v.r = z__1.r, v.i = z__1.i;
    fbar_(&z__1, &v);
    g.r = z__1.r, g.i = z__1.i;
    z__1.r = gwav_1.xx1.r / gwav_1.r1, z__1.i = gwav_1.xx1.i / gwav_1.r1;
    xr1.r = z__1.r, xr1.i = z__1.i;
    z__1.r = gwav_1.xx2.r / gwav_1.r2, z__1.i = gwav_1.xx2.i / gwav_1.r2;
    xr2.r = z__1.r, xr2.i = z__1.i;
    z__1.r = cppp2 * xr1.r, z__1.i = cppp2 * xr1.i;
    x1.r = z__1.r, x1.i = z__1.i;
    z__2.r = cpp2 * rv.r, z__2.i = cpp2 * rv.i;
    z__1.r = z__2.r * xr2.r - z__2.i * xr2.i, z__1.i = z__2.r * xr2.i + 
	    z__2.i * xr2.r;
    x2.r = z__1.r, x2.i = z__1.i;
    z__3.r = cpp2 * omr.r, z__3.i = cpp2 * omr.i;
    z__2.r = z__3.r * f.r - z__3.i * f.i, z__2.i = z__3.r * f.i + z__3.i * 
	    f.r;
    z__1.r = z__2.r * xr2.r - z__2.i * xr2.i, z__1.i = z__2.r * xr2.i + 
	    z__2.i * xr2.r;
    x3.r = z__1.r, x3.i = z__1.i;
    z__5.r = gwav_1.u.r * t2.r - gwav_1.u.i * t2.i, z__5.i = gwav_1.u.r * 
	    t2.i + gwav_1.u.i * t2.r;
    z__4.r = spp * z__5.r, z__4.i = spp * z__5.i;
    z__3.r = z__4.r * 2.f, z__3.i = z__4.i * 2.f;
    z__2.r = z__3.r * xr2.r - z__3.i * xr2.i, z__2.i = z__3.r * xr2.i + 
	    z__3.i * xr2.r;
    z_div(&z__1, &z__2, &rk2);
    x4.r = z__1.r, x4.i = z__1.i;
    z__2.r = xr1.r * t3.r - xr1.i * t3.i, z__2.i = xr1.r * t3.i + xr1.i * 
	    t3.r;
    d__1 = 1.f - sppp2 * 3.f;
    z__1.r = d__1 * z__2.r, z__1.i = d__1 * z__2.i;
    x5.r = z__1.r, x5.i = z__1.i;
    z__2.r = xr2.r * t4.r - xr2.i * t4.i, z__2.i = xr2.r * t4.i + xr2.i * 
	    t4.r;
    d__1 = 1.f - spp2 * 3.f;
    z__1.r = d__1 * z__2.r, z__1.i = d__1 * z__2.i;
    x6.r = z__1.r, x6.i = z__1.i;
    z__6.r = x1.r + x2.r, z__6.i = x1.i + x2.i;
    z__5.r = z__6.r + x3.r, z__5.i = z__6.i + x3.i;
    z__4.r = z__5.r - x4.r, z__4.i = z__5.i - x4.i;
    z__3.r = z__4.r - x5.r, z__3.i = z__4.i - x5.i;
    z__2.r = z__3.r - x6.r, z__2.i = z__3.i - x6.i;
    z__1.r = z__2.r * econ->r - z__2.i * econ->i, z__1.i = z__2.r * econ->i + 
	    z__2.i * econ->r;
    ezv->r = z__1.r, ezv->i = z__1.i;
    d__1 = sppp * cppp;
    z__1.r = d__1 * xr1.r, z__1.i = d__1 * xr1.i;
    x1.r = z__1.r, x1.i = z__1.i;
    z__3.r = spp * rv.r, z__3.i = spp * rv.i;
    z__2.r = cpp * z__3.r, z__2.i = cpp * z__3.i;
    z__1.r = z__2.r * xr2.r - z__2.i * xr2.i, z__1.i = z__2.r * xr2.i + 
	    z__2.i * xr2.r;
    x2.r = z__1.r, x2.i = z__1.i;
    z__5.r = cpp * omr.r, z__5.i = cpp * omr.i;
    z__4.r = z__5.r * gwav_1.u.r - z__5.i * gwav_1.u.i, z__4.i = z__5.r * 
	    gwav_1.u.i + z__5.i * gwav_1.u.r;
    z__3.r = z__4.r * t2.r - z__4.i * t2.i, z__3.i = z__4.r * t2.i + z__4.i * 
	    t2.r;
    z__2.r = z__3.r * f.r - z__3.i * f.i, z__2.i = z__3.r * f.i + z__3.i * 
	    f.r;
    z__1.r = z__2.r * xr2.r - z__2.i * xr2.i, z__1.i = z__2.r * xr2.i + 
	    z__2.i * xr2.r;
    x3.r = z__1.r, x3.i = z__1.i;
    d__1 = spp * cpp;
    z__3.r = d__1 * omr.r, z__3.i = d__1 * omr.i;
    z__2.r = z__3.r * xr2.r - z__3.i * xr2.i, z__2.i = z__3.r * xr2.i + 
	    z__3.i * xr2.r;
    z_div(&z__1, &z__2, &rk2);
    x4.r = z__1.r, x4.i = z__1.i;
    d__1 = sppp * 3.f * cppp;
    z__2.r = d__1 * t3.r, z__2.i = d__1 * t3.i;
    z__1.r = z__2.r * xr1.r - z__2.i * xr1.i, z__1.i = z__2.r * xr1.i + 
	    z__2.i * xr1.r;
    x5.r = z__1.r, x5.i = z__1.i;
    z__6.r = cpp * gwav_1.u.r, z__6.i = cpp * gwav_1.u.i;
    z__5.r = z__6.r * t2.r - z__6.i * t2.i, z__5.i = z__6.r * t2.i + z__6.i * 
	    t2.r;
    z__4.r = z__5.r * omr.r - z__5.i * omr.i, z__4.i = z__5.r * omr.i + 
	    z__5.i * omr.r;
    z__3.r = z__4.r * xr2.r - z__4.i * xr2.i, z__3.i = z__4.r * xr2.i + 
	    z__4.i * xr2.r;
    z_div(&z__2, &z__3, &rk2);
    z__1.r = z__2.r * .5f, z__1.i = z__2.i * .5f;
    x6.r = z__1.r, x6.i = z__1.i;
    d__1 = spp * 3.f * cpp;
    z__2.r = d__1 * t4.r, z__2.i = d__1 * t4.i;
    z__1.r = z__2.r * xr2.r - z__2.i * xr2.i, z__1.i = z__2.r * xr2.i + 
	    z__2.i * xr2.r;
    x7.r = z__1.r, x7.i = z__1.i;
    z__8.r = x1.r + x2.r, z__8.i = x1.i + x2.i;
    z__7.r = z__8.r - x3.r, z__7.i = z__8.i - x3.i;
    z__6.r = z__7.r + x4.r, z__6.i = z__7.i + x4.i;
    z__5.r = z__6.r - x5.r, z__5.i = z__6.i - x5.i;
    z__4.r = z__5.r + x6.r, z__4.i = z__5.i + x6.i;
    z__3.r = z__4.r - x7.r, z__3.i = z__4.i - x7.i;
    z__2.r = -z__3.r, z__2.i = -z__3.i;
    z__1.r = z__2.r * econ->r - z__2.i * econ->i, z__1.i = z__2.r * econ->i + 
	    z__2.i * econ->r;
    erv->r = z__1.r, erv->i = z__1.i;
    z__8.r = x1.r - x2.r, z__8.i = x1.i - x2.i;
    z__7.r = z__8.r + x3.r, z__7.i = z__8.i + x3.i;
    z__6.r = z__7.r - x4.r, z__6.i = z__7.i - x4.i;
    z__5.r = z__6.r - x5.r, z__5.i = z__6.i - x5.i;
    z__4.r = z__5.r - x6.r, z__4.i = z__5.i - x6.i;
    z__3.r = z__4.r + x7.r, z__3.i = z__4.i + x7.i;
    z__2.r = -z__3.r, z__2.i = -z__3.i;
    z__1.r = z__2.r * econ->r - z__2.i * econ->i, z__1.i = z__2.r * econ->i + 
	    z__2.i * econ->r;
    ezh->r = z__1.r, ezh->i = z__1.i;
    z__1.r = sppp2 * xr1.r, z__1.i = sppp2 * xr1.i;
    x1.r = z__1.r, x1.i = z__1.i;
    z__2.r = spp2 * rv.r, z__2.i = spp2 * rv.i;
    z__1.r = z__2.r * xr2.r - z__2.i * xr2.i, z__1.i = z__2.r * xr2.i + 
	    z__2.i * xr2.r;
    x2.r = z__1.r, x2.i = z__1.i;
    z__4.r = gwav_1.u2.r * t1.r - gwav_1.u2.i * t1.i, z__4.i = gwav_1.u2.r * 
	    t1.i + gwav_1.u2.i * t1.r;
    z__3.r = z__4.r * omr.r - z__4.i * omr.i, z__3.i = z__4.r * omr.i + 
	    z__4.i * omr.r;
    z__2.r = z__3.r * f.r - z__3.i * f.i, z__2.i = z__3.r * f.i + z__3.i * 
	    f.r;
    z__1.r = z__2.r * xr2.r - z__2.i * xr2.i, z__1.i = z__2.r * xr2.i + 
	    z__2.i * xr2.r;
    x4.r = z__1.r, x4.i = z__1.i;
    d__1 = 1.f - cppp2 * 3.f;
    z__2.r = d__1 * t3.r, z__2.i = d__1 * t3.i;
    z__1.r = z__2.r * xr1.r - z__2.i * xr1.i, z__1.i = z__2.r * xr1.i + 
	    z__2.i * xr1.r;
    x5.r = z__1.r, x5.i = z__1.i;
    d__1 = 1.f - cpp2 * 3.f;
    z__3.r = d__1 * t4.r, z__3.i = d__1 * t4.i;
    z__7.r = rv.r + 1.f, z__7.i = rv.i;
    z__6.r = gwav_1.u2.r * z__7.r - gwav_1.u2.i * z__7.i, z__6.i = 
	    gwav_1.u2.r * z__7.i + gwav_1.u2.i * z__7.r;
    z__5.r = 1.f - z__6.r, z__5.i = -z__6.i;
    z__9.r = gwav_1.u2.r * omr.r - gwav_1.u2.i * omr.i, z__9.i = gwav_1.u2.r *
	     omr.i + gwav_1.u2.i * omr.r;
    z__8.r = z__9.r * f.r - z__9.i * f.i, z__8.i = z__9.r * f.i + z__9.i * 
	    f.r;
    z__4.r = z__5.r - z__8.r, z__4.i = z__5.i - z__8.i;
    z__2.r = z__3.r * z__4.r - z__3.i * z__4.i, z__2.i = z__3.r * z__4.i + 
	    z__3.i * z__4.r;
    z__1.r = z__2.r * xr2.r - z__2.i * xr2.i, z__1.i = z__2.r * xr2.i + 
	    z__2.i * xr2.r;
    x6.r = z__1.r, x6.i = z__1.i;
    z__5.r = cpp2 * gwav_1.u2.r, z__5.i = cpp2 * gwav_1.u2.i;
    z__4.r = z__5.r * omr.r - z__5.i * omr.i, z__4.i = z__5.r * omr.i + 
	    z__5.i * omr.r;
    z_div(&z__7, &c_b245, &rk2);
    z__6.r = 1.f - z__7.r, z__6.i = -z__7.i;
    z__3.r = z__4.r * z__6.r - z__4.i * z__6.i, z__3.i = z__4.r * z__6.i + 
	    z__4.i * z__6.r;
    z__12.r = gwav_1.u2.r * t1.r - gwav_1.u2.i * t1.i, z__12.i = gwav_1.u2.r *
	     t1.i + gwav_1.u2.i * t1.r;
    z__11.r = z__12.r - spp2, z__11.i = z__12.i;
    z_div(&z__13, &c_b245, &rk2);
    z__10.r = z__11.r - z__13.r, z__10.i = z__11.i - z__13.i;
    z__9.r = f.r * z__10.r - f.i * z__10.i, z__9.i = f.r * z__10.i + f.i * 
	    z__10.r;
    z_div(&z__14, &c_b245, &rk2);
    z__8.r = z__9.r + z__14.r, z__8.i = z__9.i + z__14.i;
    z__2.r = z__3.r * z__8.r - z__3.i * z__8.i, z__2.i = z__3.r * z__8.i + 
	    z__3.i * z__8.r;
    z__1.r = z__2.r * xr2.r - z__2.i * xr2.i, z__1.i = z__2.r * xr2.i + 
	    z__2.i * xr2.r;
    x7.r = z__1.r, x7.i = z__1.i;
    z__6.r = x1.r - x2.r, z__6.i = x1.i - x2.i;
    z__5.r = z__6.r - x4.r, z__5.i = z__6.i - x4.i;
    z__4.r = z__5.r - x5.r, z__4.i = z__5.i - x5.i;
    z__3.r = z__4.r + x6.r, z__3.i = z__4.i + x6.i;
    z__2.r = z__3.r + x7.r, z__2.i = z__3.i + x7.i;
    z__1.r = z__2.r * econ->r - z__2.i * econ->i, z__1.i = z__2.r * econ->i + 
	    z__2.i * econ->r;
    erh->r = z__1.r, erh->i = z__1.i;
    x1.r = xr1.r, x1.i = xr1.i;
    z__1.r = rh.r * xr2.r - rh.i * xr2.i, z__1.i = rh.r * xr2.i + rh.i * 
	    xr2.r;
    x2.r = z__1.r, x2.i = z__1.i;
    z__3.r = rh.r + 1.f, z__3.i = rh.i;
    z__2.r = z__3.r * g.r - z__3.i * g.i, z__2.i = z__3.r * g.i + z__3.i * 
	    g.r;
    z__1.r = z__2.r * xr2.r - z__2.i * xr2.i, z__1.i = z__2.r * xr2.i + 
	    z__2.i * xr2.r;
    x3.r = z__1.r, x3.i = z__1.i;
    z__1.r = t3.r * xr1.r - t3.i * xr1.i, z__1.i = t3.r * xr1.i + t3.i * 
	    xr1.r;
    x4.r = z__1.r, x4.i = z__1.i;
    z__6.r = rv.r + 1.f, z__6.i = rv.i;
    z__5.r = gwav_1.u2.r * z__6.r - gwav_1.u2.i * z__6.i, z__5.i = 
	    gwav_1.u2.r * z__6.i + gwav_1.u2.i * z__6.r;
    z__4.r = 1.f - z__5.r, z__4.i = -z__5.i;
    z__8.r = gwav_1.u2.r * omr.r - gwav_1.u2.i * omr.i, z__8.i = gwav_1.u2.r *
	     omr.i + gwav_1.u2.i * omr.r;
    z__7.r = z__8.r * f.r - z__8.i * f.i, z__7.i = z__8.r * f.i + z__8.i * 
	    f.r;
    z__3.r = z__4.r - z__7.r, z__3.i = z__4.i - z__7.i;
    z__2.r = t4.r * z__3.r - t4.i * z__3.i, z__2.i = t4.r * z__3.i + t4.i * 
	    z__3.r;
    z__1.r = z__2.r * xr2.r - z__2.i * xr2.i, z__1.i = z__2.r * xr2.i + 
	    z__2.i * xr2.r;
    x5.r = z__1.r, x5.i = z__1.i;
    z__5.r = gwav_1.u2.r * .5f, z__5.i = gwav_1.u2.i * .5f;
    z__4.r = z__5.r * omr.r - z__5.i * omr.i, z__4.i = z__5.r * omr.i + 
	    z__5.i * omr.r;
    z__10.r = gwav_1.u2.r * t1.r - gwav_1.u2.i * t1.i, z__10.i = gwav_1.u2.r *
	     t1.i + gwav_1.u2.i * t1.r;
    z__9.r = z__10.r - spp2, z__9.i = z__10.i;
    z_div(&z__11, &c_b245, &rk2);
    z__8.r = z__9.r - z__11.r, z__8.i = z__9.i - z__11.i;
    z__7.r = f.r * z__8.r - f.i * z__8.i, z__7.i = f.r * z__8.i + f.i * 
	    z__8.r;
    z_div(&z__12, &c_b245, &rk2);
    z__6.r = z__7.r + z__12.r, z__6.i = z__7.i + z__12.i;
    z__3.r = z__4.r * z__6.r - z__4.i * z__6.i, z__3.i = z__4.r * z__6.i + 
	    z__4.i * z__6.r;
    z__2.r = z__3.r * xr2.r - z__3.i * xr2.i, z__2.i = z__3.r * xr2.i + 
	    z__3.i * xr2.r;
    z_div(&z__1, &z__2, &rk2);
    x6.r = z__1.r, x6.i = z__1.i;
    z__7.r = x1.r - x2.r, z__7.i = x1.i - x2.i;
    z__6.r = z__7.r + x3.r, z__6.i = z__7.i + x3.i;
    z__5.r = z__6.r - x4.r, z__5.i = z__6.i - x4.i;
    z__4.r = z__5.r + x5.r, z__4.i = z__5.i + x5.i;
    z__3.r = z__4.r + x6.r, z__3.i = z__4.i + x6.i;
    z__2.r = -z__3.r, z__2.i = -z__3.i;
    z__1.r = z__2.r * econ->r - z__2.i * econ->i, z__1.i = z__2.r * econ->i + 
	    z__2.i * econ->r;
    eph->r = z__1.r, eph->i = z__1.i;
    return 0;
} /* gwave_ */

#undef econx
#undef tpjx
#undef econ
#undef tpj
#undef fjx
#undef fj


/* Subroutine */ int gx_(doublereal *zz, doublereal *rh, doublereal *xk, 
	doublecomplex *gz, doublecomplex *gzp)
{
    /* System generated locals */
    doublereal d__1, d__2;
    doublecomplex z__1, z__2, z__3, z__4;

    /* Builtin functions */
    double sqrt(doublereal), sin(doublereal), cos(doublereal);

    /* Local variables */
    doublereal r__, r2, rk;

/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* *** */
/*     SEGMENT END CONTRIBUTIONS FOR THIN WIRE APPROX. */
    r2 = *zz * *zz + *rh * *rh;
    r__ = sqrt(r2);
    rk = *xk * r__;
    d__1 = cos(rk);
    d__2 = -sin(rk);
    z__2.r = d__1, z__2.i = d__2;
    z__1.r = z__2.r / r__, z__1.i = z__2.i / r__;
    gz->r = z__1.r, gz->i = z__1.i;
    z__4.r = 1., z__4.i = rk;
    z__3.r = -z__4.r, z__3.i = -z__4.i;
    z__2.r = z__3.r * gz->r - z__3.i * gz->i, z__2.i = z__3.r * gz->i + 
	    z__3.i * gz->r;
    z__1.r = z__2.r / r2, z__1.i = z__2.i / r2;
    gzp->r = z__1.r, gzp->i = z__1.i;
    return 0;
} /* gx_ */

/* Subroutine */ int gxx_(doublereal *zz, doublereal *rh, doublereal *a, 
	doublereal *a2, doublereal *xk, integer *ira, doublecomplex *g1, 
	doublecomplex *g1p, doublecomplex *g2, doublecomplex *g2p, 
	doublecomplex *g3, doublecomplex *gzp)
{
    /* System generated locals */
    doublereal d__1, d__2;
    doublecomplex z__1, z__2, z__3, z__4;

    /* Builtin functions */
    double sqrt(doublereal), sin(doublereal), cos(doublereal);

    /* Local variables */
    doublereal r__;
    doublecomplex c1, c2, c3;
    doublereal r2, t1, r4, t2, rk;
    doublecomplex gz;
    doublereal rh2, rk2;

/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* *** */
/*     SEGMENT END CONTRIBUTIONS FOR EXT. THIN WIRE APPROX. */
    r2 = *zz * *zz + *rh * *rh;
    r__ = sqrt(r2);
    r4 = r2 * r2;
    rk = *xk * r__;
    rk2 = rk * rk;
    rh2 = *rh * *rh;
    t1 = *a2 * .25f * rh2 / r4;
    t2 = *a2 * .5f / r2;
    z__1.r = 1., z__1.i = rk;
    c1.r = z__1.r, c1.i = z__1.i;
    z__2.r = c1.r * 3.f, z__2.i = c1.i * 3.f;
    z__1.r = z__2.r - rk2, z__1.i = z__2.i;
    c2.r = z__1.r, c2.i = z__1.i;
    z__3.r = 6., z__3.i = rk;
    z__2.r = rk2 * z__3.r, z__2.i = rk2 * z__3.i;
    z__4.r = c1.r * 15.f, z__4.i = c1.i * 15.f;
    z__1.r = z__2.r - z__4.r, z__1.i = z__2.i - z__4.i;
    c3.r = z__1.r, c3.i = z__1.i;
    d__1 = cos(rk);
    d__2 = -sin(rk);
    z__2.r = d__1, z__2.i = d__2;
    z__1.r = z__2.r / r__, z__1.i = z__2.i / r__;
    gz.r = z__1.r, gz.i = z__1.i;
    z__3.r = t1 * c2.r, z__3.i = t1 * c2.i;
    z__2.r = z__3.r + 1.f, z__2.i = z__3.i;
    z__1.r = gz.r * z__2.r - gz.i * z__2.i, z__1.i = gz.r * z__2.i + gz.i * 
	    z__2.r;
    g2->r = z__1.r, g2->i = z__1.i;
    z__3.r = t2 * c1.r, z__3.i = t2 * c1.i;
    z__2.r = z__3.r * gz.r - z__3.i * gz.i, z__2.i = z__3.r * gz.i + z__3.i * 
	    gz.r;
    z__1.r = g2->r - z__2.r, z__1.i = g2->i - z__2.i;
    g1->r = z__1.r, g1->i = z__1.i;
    z__1.r = gz.r / r2, z__1.i = gz.i / r2;
    gz.r = z__1.r, gz.i = z__1.i;
    z__3.r = t1 * c3.r, z__3.i = t1 * c3.i;
    z__2.r = z__3.r - c1.r, z__2.i = z__3.i - c1.i;
    z__1.r = gz.r * z__2.r - gz.i * z__2.i, z__1.i = gz.r * z__2.i + gz.i * 
	    z__2.r;
    g2p->r = z__1.r, g2p->i = z__1.i;
    z__2.r = t2 * c2.r, z__2.i = t2 * c2.i;
    z__1.r = z__2.r * gz.r - z__2.i * gz.i, z__1.i = z__2.r * gz.i + z__2.i * 
	    gz.r;
    gzp->r = z__1.r, gzp->i = z__1.i;
    z__1.r = g2p->r + gzp->r, z__1.i = g2p->i + gzp->i;
    g3->r = z__1.r, g3->i = z__1.i;
    z__1.r = *zz * g3->r, z__1.i = *zz * g3->i;
    g1p->r = z__1.r, g1p->i = z__1.i;
    if (*ira == 1) {
	goto L2;
    }
    z__2.r = g3->r + gzp->r, z__2.i = g3->i + gzp->i;
    z__1.r = *rh * z__2.r, z__1.i = *rh * z__2.i;
    g3->r = z__1.r, g3->i = z__1.i;
    d__1 = -(*zz);
    z__2.r = d__1 * c1.r, z__2.i = d__1 * c1.i;
    z__1.r = z__2.r * gz.r - z__2.i * gz.i, z__1.i = z__2.r * gz.i + z__2.i * 
	    gz.r;
    gzp->r = z__1.r, gzp->i = z__1.i;
    if (*rh > 1e-10) {
	goto L1;
    }
    g2->r = 0.f, g2->i = 0.f;
    g2p->r = 0.f, g2p->i = 0.f;
    return 0;
L1:
    z__1.r = g2->r / *rh, z__1.i = g2->i / *rh;
    g2->r = z__1.r, g2->i = z__1.i;
    z__2.r = *zz * g2p->r, z__2.i = *zz * g2p->i;
    z__1.r = z__2.r / *rh, z__1.i = z__2.i / *rh;
    g2p->r = z__1.r, g2p->i = z__1.i;
    return 0;
L2:
    t2 = *a * .5f;
    d__1 = -t2;
    z__2.r = d__1 * c1.r, z__2.i = d__1 * c1.i;
    z__1.r = z__2.r * gz.r - z__2.i * gz.i, z__1.i = z__2.r * gz.i + z__2.i * 
	    gz.r;
    g2->r = z__1.r, g2->i = z__1.i;
    z__3.r = t2 * gz.r, z__3.i = t2 * gz.i;
    z__2.r = z__3.r * c2.r - z__3.i * c2.i, z__2.i = z__3.r * c2.i + z__3.i * 
	    c2.r;
    z__1.r = z__2.r / r2, z__1.i = z__2.i / r2;
    g2p->r = z__1.r, g2p->i = z__1.i;
    z__2.r = rh2 * g2p->r, z__2.i = rh2 * g2p->i;
    z__4.r = *a * gz.r, z__4.i = *a * gz.i;
    z__3.r = z__4.r * c1.r - z__4.i * c1.i, z__3.i = z__4.r * c1.i + z__4.i * 
	    c1.r;
    z__1.r = z__2.r - z__3.r, z__1.i = z__2.i - z__3.i;
    g3->r = z__1.r, g3->i = z__1.i;
    z__1.r = *zz * g2p->r, z__1.i = *zz * g2p->i;
    g2p->r = z__1.r, g2p->i = z__1.i;
    d__1 = -(*zz);
    z__2.r = d__1 * c1.r, z__2.i = d__1 * c1.i;
    z__1.r = z__2.r * gz.r - z__2.i * gz.i, z__1.i = z__2.r * gz.i + z__2.i * 
	    gz.r;
    gzp->r = z__1.r, gzp->i = z__1.i;
    return 0;
} /* gxx_ */

/* Subroutine */ int helix_(doublereal *s, doublereal *hl, doublereal *a1, 
	doublereal *b1, doublereal *a2, doublereal *b2, doublereal *rad, 
	integer *ns, integer *itg)
{
    /* Initialized data */

    static doublereal pi = 3.1415926;

    /* Format strings */
    static char fmt_104[] = "(5x,\002THE CONE ANGLE OF THE SPIRAL IS\002,f10"
	    ".4)";
    static char fmt_105[] = "(5x,\002THE PITCH ANGLE IS\002,f10.4/5x,\002THE"
	    " LENGTH OF WIRE/TURN IS\002,f10.4)";

    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2;

    /* Builtin functions */
    double cos(doublereal), sin(doublereal), atan(doublereal);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    double sqrt(doublereal);

    /* Local variables */
    integer i__;
#define x2 ((doublereal *)&data_1 + 4500)
#define y2 ((doublereal *)&data_1 + 7500)
#define z2 ((doublereal *)&data_1 + 9000)
    integer ist;
    doublereal hdia, hmaj, hmin, zinc, copy, turn, pitch, turns, sangle;

    /* Fortran I/O blocks */
    static cilist io___1313 = { 0, 3, 0, fmt_104, 0 };
    static cilist io___1319 = { 0, 3, 0, fmt_105, 0 };


/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* Max number of segments 	(Windows-95 <= 4 */
/* max nr of 'in-core' alloc.	(MAXMAT <= MA */
/* Max number of LD cards */
/* Max number of EX cards */
/* Max number of segs connected to NT/TL */
/* *** */
/*     SUBROUTINE HELIX GENERATES SEGMENT GEOMETRY DATA FOR A HELIX OF NS */
/*     SEGMENTS */
    ist = data_1.n + 1;
    data_1.n += *ns;
    data_1.np = data_1.n;
    data_1.mp = data_1.m;
    data_1.ipsym = 0;
    if (*ns < 1) {
	return 0;
    }
    turns = (d__1 = *hl / *s, abs(d__1));
    zinc = (d__1 = *hl / *ns, abs(d__1));
    data_1.z__[ist - 1] = 0.f;
    i__1 = data_1.n;
    for (i__ = ist; i__ <= i__1; ++i__) {
	data_1.bi[i__ - 1] = *rad;
	data_1.itag[i__ - 1] = *itg;
	if (i__ != ist) {
	    data_1.z__[i__ - 1] = data_1.z__[i__ - 2] + zinc;
	}
	z2[i__ - 1] = data_1.z__[i__ - 1] + zinc;
	if (*a2 != *a1) {
	    goto L10;
	}
	if (*b1 == 0.) {
	    *b1 = *a1;
	}
	data_1.x[i__ - 1] = *a1 * cos(pi * 2.f * data_1.z__[i__ - 1] / *s);
	data_1.y[i__ - 1] = *b1 * sin(pi * 2.f * data_1.z__[i__ - 1] / *s);
	x2[i__ - 1] = *a1 * cos(pi * 2.f * z2[i__ - 1] / *s);
	y2[i__ - 1] = *b1 * sin(pi * 2.f * z2[i__ - 1] / *s);
	goto L20;
L10:
	if (*b2 == 0.) {
	    *b2 = *a2;
	}
	data_1.x[i__ - 1] = (*a1 + (*a2 - *a1) * data_1.z__[i__ - 1] / abs(*
		hl)) * cos(pi * 2.f * data_1.z__[i__ - 1] / *s);
	data_1.y[i__ - 1] = (*b1 + (*b2 - *b1) * data_1.z__[i__ - 1] / abs(*
		hl)) * sin(pi * 2.f * data_1.z__[i__ - 1] / *s);
	x2[i__ - 1] = (*a1 + (*a2 - *a1) * z2[i__ - 1] / abs(*hl)) * cos(pi * 
		2.f * z2[i__ - 1] / *s);
	y2[i__ - 1] = (*b1 + (*b2 - *b1) * z2[i__ - 1] / abs(*hl)) * sin(pi * 
		2.f * z2[i__ - 1] / *s);
L20:
	if (*hl > 0.) {
	    goto L25;
	}
	copy = data_1.x[i__ - 1];
	data_1.x[i__ - 1] = data_1.y[i__ - 1];
	data_1.y[i__ - 1] = copy;
	copy = x2[i__ - 1];
	x2[i__ - 1] = y2[i__ - 1];
	y2[i__ - 1] = copy;
L25:
	;
    }
    if (*a2 == *a1) {
	goto L21;
    }
    sangle = atan(*a2 / (abs(*hl) + abs(*hl) * *a1 / (*a2 - *a1)));
    s_wsfe(&io___1313);
    do_fio(&c__1, (char *)&sangle, (ftnlen)sizeof(doublereal));
    e_wsfe();
    return 0;
L21:
    if (*a1 != *b1) {
	goto L30;
    }
    hdia = *a1 * 2.f;
    turn = hdia * pi;
    pitch = atan(*s / (pi * hdia));
    turn /= cos(pitch);
    pitch = pitch * 180.f / pi;
    goto L40;
L30:
    if (*a1 < *b1) {
	goto L34;
    }
    hmaj = *a1 * 2.f;
    hmin = *b1 * 2.f;
    goto L35;
L34:
    hmaj = *b1 * 2.f;
    hmin = *a1 * 2.f;
L35:
/* Computing 2nd power */
    d__1 = hmaj;
/* Computing 2nd power */
    d__2 = hmin;
    hdia = sqrt((d__1 * d__1 + d__2 * d__2) / 2 * hmaj);
    turn = pi * 2.f * hdia;
    pitch = 180.f / pi * atan(*s / (pi * hdia));
L40:
    s_wsfe(&io___1319);
    do_fio(&c__1, (char *)&pitch, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&turn, (ftnlen)sizeof(doublereal));
    e_wsfe();
    return 0;
} /* helix_ */

#undef z2
#undef y2
#undef x2


/* Subroutine */ int hfk_(doublereal *el1, doublereal *el2, doublereal *rhk, 
	doublereal *zpkx, doublereal *sgr, doublereal *sgi)
{
    /* Initialized data */

    static integer nx = 1;
    static integer nm = 65536;
    static integer nts = 4;
    static doublereal rx = 1e-4;

    /* Format strings */
    static char fmt_18[] = "(\002 STEP SIZE LIMITED AT Z=\002,f10.5)";

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    doublereal s, z__;
    extern /* Subroutine */ int gh_(doublereal *, doublereal *, doublereal *);
    doublereal ep, dz, ze;
    integer ns, nt;
    doublereal zp, g1i, g3i, g5i, g2i, g4i, g1r, g2r, g3r, g4r, g5r, t00i, 
	    t01i, t10i, t02i, t11i, t20i, t00r, t01r, t10r, t02r, t11r, t20r, 
	    te1i, te2i, te1r, te2r, zend;
    extern /* Subroutine */ int test_(doublereal *, doublereal *, doublereal *
	    , doublereal *, doublereal *, doublereal *, doublereal *);
    doublereal dzot;

    /* Fortran I/O blocks */
    static cilist io___1360 = { 0, 3, 0, fmt_18, 0 };


/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* *** */
/*     HFK COMPUTES THE H FIELD OF A UNIFORM CURRENT FILAMENT BY */
/*     NUMERICAL INTEGRATION */
    tmh_1.zpk = *zpkx;
    tmh_1.rhks = *rhk * *rhk;
    z__ = *el1;
    ze = *el2;
    s = ze - z__;
    ep = s / (nm * 10.f);
    zend = ze - ep;
    *sgr = 0.f;
    *sgi = 0.f;
    ns = nx;
    nt = 0;
    gh_(&z__, &g1r, &g1i);
L1:
    dz = s / ns;
    zp = z__ + dz;
    if (zp - ze <= 0.) {
	goto L3;
    } else {
	goto L2;
    }
L2:
    dz = ze - z__;
    if (abs(dz) - ep <= 0.) {
	goto L17;
    } else {
	goto L3;
    }
L3:
    dzot = dz * .5f;
    zp = z__ + dzot;
    gh_(&zp, &g3r, &g3i);
    zp = z__ + dz;
    gh_(&zp, &g5r, &g5i);
L4:
    t00r = (g1r + g5r) * dzot;
    t00i = (g1i + g5i) * dzot;
    t01r = (t00r + dz * g3r) * .5f;
    t01i = (t00i + dz * g3i) * .5f;
    t10r = (t01r * 4.f - t00r) / 3.f;
    t10i = (t01i * 4.f - t00i) / 3.f;
    test_(&t01r, &t10r, &te1r, &t01i, &t10i, &te1i, &c_b636);
    if (te1i - rx <= 0.) {
	goto L5;
    } else {
	goto L6;
    }
L5:
    if (te1r - rx <= 0.) {
	goto L8;
    } else {
	goto L6;
    }
L6:
    zp = z__ + dz * .25f;
    gh_(&zp, &g2r, &g2i);
    zp = z__ + dz * .75f;
    gh_(&zp, &g4r, &g4i);
    t02r = (t01r + dzot * (g2r + g4r)) * .5f;
    t02i = (t01i + dzot * (g2i + g4i)) * .5f;
    t11r = (t02r * 4.f - t01r) / 3.f;
    t11i = (t02i * 4.f - t01i) / 3.f;
    t20r = (t11r * 16.f - t10r) / 15.f;
    t20i = (t11i * 16.f - t10i) / 15.f;
    test_(&t11r, &t20r, &te2r, &t11i, &t20i, &te2i, &c_b636);
    if (te2i - rx <= 0.) {
	goto L7;
    } else {
	goto L14;
    }
L7:
    if (te2r - rx <= 0.) {
	goto L9;
    } else {
	goto L14;
    }
L8:
    *sgr += t10r;
    *sgi += t10i;
    nt += 2;
    goto L10;
L9:
    *sgr += t20r;
    *sgi += t20i;
    ++nt;
L10:
    z__ += dz;
    if (z__ - zend >= 0.) {
	goto L17;
    } else {
	goto L11;
    }
L11:
    g1r = g5r;
    g1i = g5i;
    if (nt - nts >= 0) {
	goto L12;
    } else {
	goto L1;
    }
L12:
    if (ns - nx <= 0) {
	goto L1;
    } else {
	goto L13;
    }
L13:
    ns /= 2;
    nt = 1;
    goto L1;
L14:
    nt = 0;
    if (ns - nm >= 0) {
	goto L15;
    } else {
	goto L16;
    }
L15:
    s_wsfe(&io___1360);
    do_fio(&c__1, (char *)&z__, (ftnlen)sizeof(doublereal));
    e_wsfe();
    goto L9;
L16:
    ns <<= 1;
    dz = s / ns;
    dzot = dz * .5f;
    g5r = g3r;
    g5i = g3i;
    g3r = g2r;
    g3i = g2i;
    goto L4;
L17:
    *sgr = *sgr * *rhk * .5f;
    *sgi = *sgi * *rhk * .5f;
    return 0;

} /* hfk_ */

/* Subroutine */ int hintg_(doublereal *xi, doublereal *yi, doublereal *zi)
{
    /* Initialized data */

    static doublereal fpi = 12.56637062;
    static doublereal tp = 6.283185308;

    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2;
    doublecomplex z__1, z__2, z__3, z__4, z__5, z__6, z__7;

    /* Builtin functions */
    double sqrt(doublereal), cos(doublereal), sin(doublereal);
    void z_sqrt(doublecomplex *, doublecomplex *), z_div(doublecomplex *, 
	    doublecomplex *, doublecomplex *);

    /* Local variables */
    doublereal r__, cr;
    integer ip;
    doublereal rk, sr, px, rx, ry, rz, py;
    doublecomplex f1x, f1y, f1z, f2x, f2y, f2z, gam;
    doublereal cth, rfl;
    doublecomplex rrh;
    doublereal rsq;
    doublecomplex rrv;
#define t1xj ((doublereal *)&dataj_1 + 5)
#define t1yj ((doublereal *)&dataj_1 + 6)
#define t1zj ((doublereal *)&dataj_1 + 7)
#define t2xj ((doublereal *)&dataj_1 + 1)
#define t2yj ((doublereal *)&dataj_1 + 27)
#define t2zj ((doublereal *)&dataj_1 + 28)
    doublereal t1zr, t2zr, xymag;

/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* *** */
/*     HINTG COMPUTES THE H FIELD OF A PATCH CURRENT */
    rx = *xi - dataj_1.xj;
    ry = *yi - dataj_1.yj;
    rfl = -1.f;
    dataj_1.exk.r = 0.f, dataj_1.exk.i = 0.f;
    dataj_1.eyk.r = 0.f, dataj_1.eyk.i = 0.f;
    dataj_1.ezk.r = 0.f, dataj_1.ezk.i = 0.f;
    dataj_1.exs.r = 0.f, dataj_1.exs.i = 0.f;
    dataj_1.eys.r = 0.f, dataj_1.eys.i = 0.f;
    dataj_1.ezs.r = 0.f, dataj_1.ezs.i = 0.f;
    i__1 = gnd_1.ksymp;
    for (ip = 1; ip <= i__1; ++ip) {
	rfl = -rfl;
	rz = *zi - dataj_1.zj * rfl;
	rsq = rx * rx + ry * ry + rz * rz;
	if (rsq < 1e-20) {
	    goto L5;
	}
	r__ = sqrt(rsq);
	rk = tp * r__;
	cr = cos(rk);
	sr = sin(rk);
	d__1 = -sr;
	z__5.r = cr, z__5.i = d__1;
	z__7.r = sr, z__7.i = cr;
	z__6.r = rk * z__7.r, z__6.i = rk * z__7.i;
	z__4.r = z__5.r + z__6.r, z__4.i = z__5.i + z__6.i;
	z__3.r = -z__4.r, z__3.i = -z__4.i;
	d__2 = fpi * rsq * r__;
	z__2.r = z__3.r / d__2, z__2.i = z__3.i / d__2;
	z__1.r = dataj_1.s * z__2.r, z__1.i = dataj_1.s * z__2.i;
	gam.r = z__1.r, gam.i = z__1.i;
	z__1.r = rx * gam.r, z__1.i = rx * gam.i;
	dataj_1.exc.r = z__1.r, dataj_1.exc.i = z__1.i;
	z__1.r = ry * gam.r, z__1.i = ry * gam.i;
	dataj_1.eyc.r = z__1.r, dataj_1.eyc.i = z__1.i;
	z__1.r = rz * gam.r, z__1.i = rz * gam.i;
	dataj_1.ezc.r = z__1.r, dataj_1.ezc.i = z__1.i;
	t1zr = *t1zj * rfl;
	t2zr = *t2zj * rfl;
	z__2.r = t1zr * dataj_1.eyc.r, z__2.i = t1zr * dataj_1.eyc.i;
	z__3.r = *t1yj * dataj_1.ezc.r, z__3.i = *t1yj * dataj_1.ezc.i;
	z__1.r = z__2.r - z__3.r, z__1.i = z__2.i - z__3.i;
	f1x.r = z__1.r, f1x.i = z__1.i;
	z__2.r = *t1xj * dataj_1.ezc.r, z__2.i = *t1xj * dataj_1.ezc.i;
	z__3.r = t1zr * dataj_1.exc.r, z__3.i = t1zr * dataj_1.exc.i;
	z__1.r = z__2.r - z__3.r, z__1.i = z__2.i - z__3.i;
	f1y.r = z__1.r, f1y.i = z__1.i;
	z__2.r = *t1yj * dataj_1.exc.r, z__2.i = *t1yj * dataj_1.exc.i;
	z__3.r = *t1xj * dataj_1.eyc.r, z__3.i = *t1xj * dataj_1.eyc.i;
	z__1.r = z__2.r - z__3.r, z__1.i = z__2.i - z__3.i;
	f1z.r = z__1.r, f1z.i = z__1.i;
	z__2.r = t2zr * dataj_1.eyc.r, z__2.i = t2zr * dataj_1.eyc.i;
	z__3.r = *t2yj * dataj_1.ezc.r, z__3.i = *t2yj * dataj_1.ezc.i;
	z__1.r = z__2.r - z__3.r, z__1.i = z__2.i - z__3.i;
	f2x.r = z__1.r, f2x.i = z__1.i;
	z__2.r = *t2xj * dataj_1.ezc.r, z__2.i = *t2xj * dataj_1.ezc.i;
	z__3.r = t2zr * dataj_1.exc.r, z__3.i = t2zr * dataj_1.exc.i;
	z__1.r = z__2.r - z__3.r, z__1.i = z__2.i - z__3.i;
	f2y.r = z__1.r, f2y.i = z__1.i;
	z__2.r = *t2yj * dataj_1.exc.r, z__2.i = *t2yj * dataj_1.exc.i;
	z__3.r = *t2xj * dataj_1.eyc.r, z__3.i = *t2xj * dataj_1.eyc.i;
	z__1.r = z__2.r - z__3.r, z__1.i = z__2.i - z__3.i;
	f2z.r = z__1.r, f2z.i = z__1.i;
	if (ip == 1) {
	    goto L4;
	}
	if (gnd_1.iperf != 1) {
	    goto L1;
	}
	z__1.r = -f1x.r, z__1.i = -f1x.i;
	f1x.r = z__1.r, f1x.i = z__1.i;
	z__1.r = -f1y.r, z__1.i = -f1y.i;
	f1y.r = z__1.r, f1y.i = z__1.i;
	z__1.r = -f1z.r, z__1.i = -f1z.i;
	f1z.r = z__1.r, f1z.i = z__1.i;
	z__1.r = -f2x.r, z__1.i = -f2x.i;
	f2x.r = z__1.r, f2x.i = z__1.i;
	z__1.r = -f2y.r, z__1.i = -f2y.i;
	f2y.r = z__1.r, f2y.i = z__1.i;
	z__1.r = -f2z.r, z__1.i = -f2z.i;
	f2z.r = z__1.r, f2z.i = z__1.i;
	goto L4;
L1:
	xymag = sqrt(rx * rx + ry * ry);
	if (xymag > 1e-6) {
	    goto L2;
	}
	px = 0.f;
	py = 0.f;
	cth = 1.f;
	rrv.r = 1.f, rrv.i = 0.f;
	goto L3;
L2:
	px = -ry / xymag;
	py = rx / xymag;
	cth = rz / r__;
	z__4.r = gnd_1.zrati.r * gnd_1.zrati.r - gnd_1.zrati.i * 
		gnd_1.zrati.i, z__4.i = gnd_1.zrati.r * gnd_1.zrati.i + 
		gnd_1.zrati.i * gnd_1.zrati.r;
	d__1 = 1.f - cth * cth;
	z__3.r = d__1 * z__4.r, z__3.i = d__1 * z__4.i;
	z__2.r = 1.f - z__3.r, z__2.i = -z__3.i;
	z_sqrt(&z__1, &z__2);
	rrv.r = z__1.r, rrv.i = z__1.i;
L3:
	z__1.r = cth * gnd_1.zrati.r, z__1.i = cth * gnd_1.zrati.i;
	rrh.r = z__1.r, rrh.i = z__1.i;
	z__2.r = rrh.r - rrv.r, z__2.i = rrh.i - rrv.i;
	z__3.r = rrh.r + rrv.r, z__3.i = rrh.i + rrv.i;
	z_div(&z__1, &z__2, &z__3);
	rrh.r = z__1.r, rrh.i = z__1.i;
	z__1.r = gnd_1.zrati.r * rrv.r - gnd_1.zrati.i * rrv.i, z__1.i = 
		gnd_1.zrati.r * rrv.i + gnd_1.zrati.i * rrv.r;
	rrv.r = z__1.r, rrv.i = z__1.i;
	z__3.r = cth - rrv.r, z__3.i = -rrv.i;
	z__2.r = -z__3.r, z__2.i = -z__3.i;
	z__4.r = cth + rrv.r, z__4.i = rrv.i;
	z_div(&z__1, &z__2, &z__4);
	rrv.r = z__1.r, rrv.i = z__1.i;
	z__3.r = px * f1x.r, z__3.i = px * f1x.i;
	z__4.r = py * f1y.r, z__4.i = py * f1y.i;
	z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
	z__5.r = rrv.r - rrh.r, z__5.i = rrv.i - rrh.i;
	z__1.r = z__2.r * z__5.r - z__2.i * z__5.i, z__1.i = z__2.r * z__5.i 
		+ z__2.i * z__5.r;
	gam.r = z__1.r, gam.i = z__1.i;
	z__2.r = f1x.r * rrh.r - f1x.i * rrh.i, z__2.i = f1x.r * rrh.i + 
		f1x.i * rrh.r;
	z__3.r = px * gam.r, z__3.i = px * gam.i;
	z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
	f1x.r = z__1.r, f1x.i = z__1.i;
	z__2.r = f1y.r * rrh.r - f1y.i * rrh.i, z__2.i = f1y.r * rrh.i + 
		f1y.i * rrh.r;
	z__3.r = py * gam.r, z__3.i = py * gam.i;
	z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
	f1y.r = z__1.r, f1y.i = z__1.i;
	z__1.r = f1z.r * rrh.r - f1z.i * rrh.i, z__1.i = f1z.r * rrh.i + 
		f1z.i * rrh.r;
	f1z.r = z__1.r, f1z.i = z__1.i;
	z__3.r = px * f2x.r, z__3.i = px * f2x.i;
	z__4.r = py * f2y.r, z__4.i = py * f2y.i;
	z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
	z__5.r = rrv.r - rrh.r, z__5.i = rrv.i - rrh.i;
	z__1.r = z__2.r * z__5.r - z__2.i * z__5.i, z__1.i = z__2.r * z__5.i 
		+ z__2.i * z__5.r;
	gam.r = z__1.r, gam.i = z__1.i;
	z__2.r = f2x.r * rrh.r - f2x.i * rrh.i, z__2.i = f2x.r * rrh.i + 
		f2x.i * rrh.r;
	z__3.r = px * gam.r, z__3.i = px * gam.i;
	z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
	f2x.r = z__1.r, f2x.i = z__1.i;
	z__2.r = f2y.r * rrh.r - f2y.i * rrh.i, z__2.i = f2y.r * rrh.i + 
		f2y.i * rrh.r;
	z__3.r = py * gam.r, z__3.i = py * gam.i;
	z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
	f2y.r = z__1.r, f2y.i = z__1.i;
	z__1.r = f2z.r * rrh.r - f2z.i * rrh.i, z__1.i = f2z.r * rrh.i + 
		f2z.i * rrh.r;
	f2z.r = z__1.r, f2z.i = z__1.i;
L4:
	z__1.r = dataj_1.exk.r + f1x.r, z__1.i = dataj_1.exk.i + f1x.i;
	dataj_1.exk.r = z__1.r, dataj_1.exk.i = z__1.i;
	z__1.r = dataj_1.eyk.r + f1y.r, z__1.i = dataj_1.eyk.i + f1y.i;
	dataj_1.eyk.r = z__1.r, dataj_1.eyk.i = z__1.i;
	z__1.r = dataj_1.ezk.r + f1z.r, z__1.i = dataj_1.ezk.i + f1z.i;
	dataj_1.ezk.r = z__1.r, dataj_1.ezk.i = z__1.i;
	z__1.r = dataj_1.exs.r + f2x.r, z__1.i = dataj_1.exs.i + f2x.i;
	dataj_1.exs.r = z__1.r, dataj_1.exs.i = z__1.i;
	z__1.r = dataj_1.eys.r + f2y.r, z__1.i = dataj_1.eys.i + f2y.i;
	dataj_1.eys.r = z__1.r, dataj_1.eys.i = z__1.i;
	z__1.r = dataj_1.ezs.r + f2z.r, z__1.i = dataj_1.ezs.i + f2z.i;
	dataj_1.ezs.r = z__1.r, dataj_1.ezs.i = z__1.i;
L5:
	;
    }
    return 0;
} /* hintg_ */

#undef t2zj
#undef t2yj
#undef t2xj
#undef t1zj
#undef t1yj
#undef t1xj


/* Subroutine */ int hsfld_(doublereal *xi, doublereal *yi, doublereal *zi, 
	doublereal *ai)
{
    /* Initialized data */

    static doublereal eta = 376.73;

    /* System generated locals */
    integer i__1;
    doublereal d__1;
    doublecomplex z__1, z__2, z__3, z__4;

    /* Builtin functions */
    double sqrt(doublereal), log(doublereal);
    void z_div(doublecomplex *, doublecomplex *, doublecomplex *), z_sqrt(
	    doublecomplex *, doublecomplex *);

    /* Local variables */
    integer ip;
    doublereal rh, px;
    doublecomplex qx, qy, qz;
    doublereal zp, py;
    doublecomplex hpc;
    doublereal cth;
    doublecomplex hpk;
    doublereal rfl;
    doublecomplex hps, rrh;
    doublereal xij, yij, zij, phx, phy, phz;
    doublecomplex rrv;
    doublereal rmag, rhox, rhoy, rhoz, salpr, xspec, yspec;
    extern /* Subroutine */ int hsflx_(doublereal *, doublereal *, doublereal 
	    *, doublecomplex *, doublecomplex *, doublecomplex *);
    doublereal xymag;
    doublecomplex zratx;
    doublereal rhospc;

/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* *** */
/*     HSFLD COMPUTES THE H FIELD FOR CONSTANT, SINE, AND COSINE CURRENT */
/*     ON A SEGMENT INCLUDING GROUND EFFECTS. */
    xij = *xi - dataj_1.xj;
    yij = *yi - dataj_1.yj;
    rfl = -1.f;
    i__1 = gnd_1.ksymp;
    for (ip = 1; ip <= i__1; ++ip) {
	rfl = -rfl;
	salpr = dataj_1.salpj * rfl;
	zij = *zi - rfl * dataj_1.zj;
	zp = xij * dataj_1.cabj + yij * dataj_1.sabj + zij * salpr;
	rhox = xij - dataj_1.cabj * zp;
	rhoy = yij - dataj_1.sabj * zp;
	rhoz = zij - salpr * zp;
	rh = sqrt(rhox * rhox + rhoy * rhoy + rhoz * rhoz + *ai * *ai);
	if (rh > 1e-10) {
	    goto L1;
	}
	dataj_1.exk.r = 0.f, dataj_1.exk.i = 0.f;
	dataj_1.eyk.r = 0.f, dataj_1.eyk.i = 0.f;
	dataj_1.ezk.r = 0.f, dataj_1.ezk.i = 0.f;
	dataj_1.exs.r = 0.f, dataj_1.exs.i = 0.f;
	dataj_1.eys.r = 0.f, dataj_1.eys.i = 0.f;
	dataj_1.ezs.r = 0.f, dataj_1.ezs.i = 0.f;
	dataj_1.exc.r = 0.f, dataj_1.exc.i = 0.f;
	dataj_1.eyc.r = 0.f, dataj_1.eyc.i = 0.f;
	dataj_1.ezc.r = 0.f, dataj_1.ezc.i = 0.f;
	goto L7;
L1:
	rhox /= rh;
	rhoy /= rh;
	rhoz /= rh;
	phx = dataj_1.sabj * rhoz - salpr * rhoy;
	phy = salpr * rhox - dataj_1.cabj * rhoz;
	phz = dataj_1.cabj * rhoy - dataj_1.sabj * rhox;
	hsflx_(&dataj_1.s, &rh, &zp, &hpk, &hps, &hpc);
	if (ip != 2) {
	    goto L6;
	}
	if (gnd_1.iperf == 1) {
	    goto L5;
	}
	zratx.r = gnd_1.zrati.r, zratx.i = gnd_1.zrati.i;
	rmag = sqrt(zp * zp + rh * rh);
	xymag = sqrt(xij * xij + yij * yij);

/*     SET PARAMETERS FOR RADIAL WIRE GROUND SCREEN. */

	if (gnd_1.nradl == 0) {
	    goto L2;
	}
	xspec = (*xi * dataj_1.zj + *zi * dataj_1.xj) / (*zi + dataj_1.zj);
	yspec = (*yi * dataj_1.zj + *zi * dataj_1.yj) / (*zi + dataj_1.zj);
	rhospc = sqrt(xspec * xspec + yspec * yspec + gnd_1.t2 * gnd_1.t2);
	if (rhospc > gnd_1.scrwl) {
	    goto L2;
	}
	z__2.r = rhospc * gnd_1.t1.r, z__2.i = rhospc * gnd_1.t1.i;
	d__1 = log(rhospc / gnd_1.t2);
	z__1.r = d__1 * z__2.r, z__1.i = d__1 * z__2.i;
	rrv.r = z__1.r, rrv.i = z__1.i;
	z__2.r = rrv.r * gnd_1.zrati.r - rrv.i * gnd_1.zrati.i, z__2.i = 
		rrv.r * gnd_1.zrati.i + rrv.i * gnd_1.zrati.r;
	z__4.r = eta * gnd_1.zrati.r, z__4.i = eta * gnd_1.zrati.i;
	z__3.r = z__4.r + rrv.r, z__3.i = z__4.i + rrv.i;
	z_div(&z__1, &z__2, &z__3);
	zratx.r = z__1.r, zratx.i = z__1.i;
L2:
	if (xymag > 1e-6) {
	    goto L3;
	}

/*     CALCULATION OF REFLECTION COEFFICIENTS WHEN GROUND IS SPECIFIED. */

	px = 0.f;
	py = 0.f;
	cth = 1.f;
	rrv.r = 1.f, rrv.i = 0.f;
	goto L4;
L3:
	px = -yij / xymag;
	py = xij / xymag;
	cth = zij / rmag;
	z__4.r = zratx.r * zratx.r - zratx.i * zratx.i, z__4.i = zratx.r * 
		zratx.i + zratx.i * zratx.r;
	d__1 = 1.f - cth * cth;
	z__3.r = d__1 * z__4.r, z__3.i = d__1 * z__4.i;
	z__2.r = 1.f - z__3.r, z__2.i = -z__3.i;
	z_sqrt(&z__1, &z__2);
	rrv.r = z__1.r, rrv.i = z__1.i;
L4:
	z__1.r = cth * zratx.r, z__1.i = cth * zratx.i;
	rrh.r = z__1.r, rrh.i = z__1.i;
	z__3.r = rrh.r - rrv.r, z__3.i = rrh.i - rrv.i;
	z__2.r = -z__3.r, z__2.i = -z__3.i;
	z__4.r = rrh.r + rrv.r, z__4.i = rrh.i + rrv.i;
	z_div(&z__1, &z__2, &z__4);
	rrh.r = z__1.r, rrh.i = z__1.i;
	z__1.r = zratx.r * rrv.r - zratx.i * rrv.i, z__1.i = zratx.r * rrv.i 
		+ zratx.i * rrv.r;
	rrv.r = z__1.r, rrv.i = z__1.i;
	z__2.r = cth - rrv.r, z__2.i = -rrv.i;
	z__3.r = cth + rrv.r, z__3.i = rrv.i;
	z_div(&z__1, &z__2, &z__3);
	rrv.r = z__1.r, rrv.i = z__1.i;
	d__1 = phx * px + phy * py;
	z__2.r = rrv.r - rrh.r, z__2.i = rrv.i - rrh.i;
	z__1.r = d__1 * z__2.r, z__1.i = d__1 * z__2.i;
	qy.r = z__1.r, qy.i = z__1.i;
	z__2.r = px * qy.r, z__2.i = px * qy.i;
	z__3.r = phx * rrh.r, z__3.i = phx * rrh.i;
	z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
	qx.r = z__1.r, qx.i = z__1.i;
	z__2.r = py * qy.r, z__2.i = py * qy.i;
	z__3.r = phy * rrh.r, z__3.i = phy * rrh.i;
	z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
	qy.r = z__1.r, qy.i = z__1.i;
	z__1.r = phz * rrh.r, z__1.i = phz * rrh.i;
	qz.r = z__1.r, qz.i = z__1.i;
	z__2.r = hpk.r * qx.r - hpk.i * qx.i, z__2.i = hpk.r * qx.i + hpk.i * 
		qx.r;
	z__1.r = dataj_1.exk.r - z__2.r, z__1.i = dataj_1.exk.i - z__2.i;
	dataj_1.exk.r = z__1.r, dataj_1.exk.i = z__1.i;
	z__2.r = hpk.r * qy.r - hpk.i * qy.i, z__2.i = hpk.r * qy.i + hpk.i * 
		qy.r;
	z__1.r = dataj_1.eyk.r - z__2.r, z__1.i = dataj_1.eyk.i - z__2.i;
	dataj_1.eyk.r = z__1.r, dataj_1.eyk.i = z__1.i;
	z__2.r = hpk.r * qz.r - hpk.i * qz.i, z__2.i = hpk.r * qz.i + hpk.i * 
		qz.r;
	z__1.r = dataj_1.ezk.r - z__2.r, z__1.i = dataj_1.ezk.i - z__2.i;
	dataj_1.ezk.r = z__1.r, dataj_1.ezk.i = z__1.i;
	z__2.r = hps.r * qx.r - hps.i * qx.i, z__2.i = hps.r * qx.i + hps.i * 
		qx.r;
	z__1.r = dataj_1.exs.r - z__2.r, z__1.i = dataj_1.exs.i - z__2.i;
	dataj_1.exs.r = z__1.r, dataj_1.exs.i = z__1.i;
	z__2.r = hps.r * qy.r - hps.i * qy.i, z__2.i = hps.r * qy.i + hps.i * 
		qy.r;
	z__1.r = dataj_1.eys.r - z__2.r, z__1.i = dataj_1.eys.i - z__2.i;
	dataj_1.eys.r = z__1.r, dataj_1.eys.i = z__1.i;
	z__2.r = hps.r * qz.r - hps.i * qz.i, z__2.i = hps.r * qz.i + hps.i * 
		qz.r;
	z__1.r = dataj_1.ezs.r - z__2.r, z__1.i = dataj_1.ezs.i - z__2.i;
	dataj_1.ezs.r = z__1.r, dataj_1.ezs.i = z__1.i;
	z__2.r = hpc.r * qx.r - hpc.i * qx.i, z__2.i = hpc.r * qx.i + hpc.i * 
		qx.r;
	z__1.r = dataj_1.exc.r - z__2.r, z__1.i = dataj_1.exc.i - z__2.i;
	dataj_1.exc.r = z__1.r, dataj_1.exc.i = z__1.i;
	z__2.r = hpc.r * qy.r - hpc.i * qy.i, z__2.i = hpc.r * qy.i + hpc.i * 
		qy.r;
	z__1.r = dataj_1.eyc.r - z__2.r, z__1.i = dataj_1.eyc.i - z__2.i;
	dataj_1.eyc.r = z__1.r, dataj_1.eyc.i = z__1.i;
	z__2.r = hpc.r * qz.r - hpc.i * qz.i, z__2.i = hpc.r * qz.i + hpc.i * 
		qz.r;
	z__1.r = dataj_1.ezc.r - z__2.r, z__1.i = dataj_1.ezc.i - z__2.i;
	dataj_1.ezc.r = z__1.r, dataj_1.ezc.i = z__1.i;
	goto L7;
L5:
	z__2.r = phx * hpk.r, z__2.i = phx * hpk.i;
	z__1.r = dataj_1.exk.r - z__2.r, z__1.i = dataj_1.exk.i - z__2.i;
	dataj_1.exk.r = z__1.r, dataj_1.exk.i = z__1.i;
	z__2.r = phy * hpk.r, z__2.i = phy * hpk.i;
	z__1.r = dataj_1.eyk.r - z__2.r, z__1.i = dataj_1.eyk.i - z__2.i;
	dataj_1.eyk.r = z__1.r, dataj_1.eyk.i = z__1.i;
	z__2.r = phz * hpk.r, z__2.i = phz * hpk.i;
	z__1.r = dataj_1.ezk.r - z__2.r, z__1.i = dataj_1.ezk.i - z__2.i;
	dataj_1.ezk.r = z__1.r, dataj_1.ezk.i = z__1.i;
	z__2.r = phx * hps.r, z__2.i = phx * hps.i;
	z__1.r = dataj_1.exs.r - z__2.r, z__1.i = dataj_1.exs.i - z__2.i;
	dataj_1.exs.r = z__1.r, dataj_1.exs.i = z__1.i;
	z__2.r = phy * hps.r, z__2.i = phy * hps.i;
	z__1.r = dataj_1.eys.r - z__2.r, z__1.i = dataj_1.eys.i - z__2.i;
	dataj_1.eys.r = z__1.r, dataj_1.eys.i = z__1.i;
	z__2.r = phz * hps.r, z__2.i = phz * hps.i;
	z__1.r = dataj_1.ezs.r - z__2.r, z__1.i = dataj_1.ezs.i - z__2.i;
	dataj_1.ezs.r = z__1.r, dataj_1.ezs.i = z__1.i;
	z__2.r = phx * hpc.r, z__2.i = phx * hpc.i;
	z__1.r = dataj_1.exc.r - z__2.r, z__1.i = dataj_1.exc.i - z__2.i;
	dataj_1.exc.r = z__1.r, dataj_1.exc.i = z__1.i;
	z__2.r = phy * hpc.r, z__2.i = phy * hpc.i;
	z__1.r = dataj_1.eyc.r - z__2.r, z__1.i = dataj_1.eyc.i - z__2.i;
	dataj_1.eyc.r = z__1.r, dataj_1.eyc.i = z__1.i;
	z__2.r = phz * hpc.r, z__2.i = phz * hpc.i;
	z__1.r = dataj_1.ezc.r - z__2.r, z__1.i = dataj_1.ezc.i - z__2.i;
	dataj_1.ezc.r = z__1.r, dataj_1.ezc.i = z__1.i;
	goto L7;
L6:
	z__1.r = phx * hpk.r, z__1.i = phx * hpk.i;
	dataj_1.exk.r = z__1.r, dataj_1.exk.i = z__1.i;
	z__1.r = phy * hpk.r, z__1.i = phy * hpk.i;
	dataj_1.eyk.r = z__1.r, dataj_1.eyk.i = z__1.i;
	z__1.r = phz * hpk.r, z__1.i = phz * hpk.i;
	dataj_1.ezk.r = z__1.r, dataj_1.ezk.i = z__1.i;
	z__1.r = phx * hps.r, z__1.i = phx * hps.i;
	dataj_1.exs.r = z__1.r, dataj_1.exs.i = z__1.i;
	z__1.r = phy * hps.r, z__1.i = phy * hps.i;
	dataj_1.eys.r = z__1.r, dataj_1.eys.i = z__1.i;
	z__1.r = phz * hps.r, z__1.i = phz * hps.i;
	dataj_1.ezs.r = z__1.r, dataj_1.ezs.i = z__1.i;
	z__1.r = phx * hpc.r, z__1.i = phx * hpc.i;
	dataj_1.exc.r = z__1.r, dataj_1.exc.i = z__1.i;
	z__1.r = phy * hpc.r, z__1.i = phy * hpc.i;
	dataj_1.eyc.r = z__1.r, dataj_1.eyc.i = z__1.i;
	z__1.r = phz * hpc.r, z__1.i = phz * hpc.i;
	dataj_1.ezc.r = z__1.r, dataj_1.ezc.i = z__1.i;
L7:
	;
    }
    return 0;
} /* hsfld_ */

/* Subroutine */ int hsflx_(doublereal *s, doublereal *rh, doublereal *zpx, 
	doublecomplex *hpk, doublecomplex *hps, doublecomplex *hpc)
{
    /* Initialized data */

    static doublereal tp = 6.283185308;
    static doublereal pi8 = 25.13274123;
    static struct {
	doublereal e_1[2];
	} equiv_0 = { 0., 1. };

    static struct {
	doublereal e_1[2];
	} equiv_1 = { 0., -6.283185308 };


    /* System generated locals */
    doublereal d__1, d__2, d__3;
    doublecomplex z__1, z__2, z__3, z__4, z__5, z__6, z__7;

    /* Builtin functions */
    double cos(doublereal), sin(doublereal), sqrt(doublereal);
    void z_exp(doublecomplex *, doublecomplex *);

    /* Local variables */
    doublereal r1, r2;
    doublecomplex t1, t2;
    doublereal z1, z2, dh, dk;
#define fj ((doublecomplex *)&equiv_0)
    doublereal zp, rh2, cdk;
    extern /* Subroutine */ int hfk_(doublereal *, doublereal *, doublereal *,
	     doublereal *, doublereal *, doublereal *);
#define fjk ((doublecomplex *)&equiv_1)
    doublereal hki, sdk, hkr;
#define fjx ((doublereal *)&equiv_0)
    doublereal hss, rhz;
    doublecomplex ekr1, ekr2, cons;
#define fjkx ((doublereal *)&equiv_1)

/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* *** */
/*     CALCULATES H FIELD OF SINE COSINE, AND CONSTANT CURRENT OF SEGMENT */
    if (*rh < 1e-10) {
	goto L6;
    }
    if (*zpx < 0.f) {
	goto L1;
    }
    zp = *zpx;
    hss = 1.f;
    goto L2;
L1:
    zp = -(*zpx);
    hss = -1.f;
L2:
    dh = *s * .5f;
    z1 = zp + dh;
    z2 = zp - dh;
    if (z2 < 1e-7) {
	goto L3;
    }
    rhz = *rh / z2;
    goto L4;
L3:
    rhz = 1.f;
L4:
    dk = tp * dh;
    cdk = cos(dk);
    sdk = sin(dk);
    d__1 = -dk;
    d__2 = *rh * tp;
    d__3 = zp * tp;
    hfk_(&d__1, &dk, &d__2, &d__3, &hkr, &hki);
    z__1.r = hkr, z__1.i = hki;
    hpk->r = z__1.r, hpk->i = z__1.i;
    if (rhz < .001) {
	goto L5;
    }
    rh2 = *rh * *rh;
    r1 = sqrt(rh2 + z1 * z1);
    r2 = sqrt(rh2 + z2 * z2);
    z__2.r = r1 * fjk->r, z__2.i = r1 * fjk->i;
    z_exp(&z__1, &z__2);
    ekr1.r = z__1.r, ekr1.i = z__1.i;
    z__2.r = r2 * fjk->r, z__2.i = r2 * fjk->i;
    z_exp(&z__1, &z__2);
    ekr2.r = z__1.r, ekr2.i = z__1.i;
    z__2.r = z1 * ekr1.r, z__2.i = z1 * ekr1.i;
    z__1.r = z__2.r / r1, z__1.i = z__2.i / r1;
    t1.r = z__1.r, t1.i = z__1.i;
    z__2.r = z2 * ekr2.r, z__2.i = z2 * ekr2.i;
    z__1.r = z__2.r / r2, z__1.i = z__2.i / r2;
    t2.r = z__1.r, t2.i = z__1.i;
    z__4.r = ekr2.r - ekr1.r, z__4.i = ekr2.i - ekr1.i;
    z__3.r = cdk * z__4.r, z__3.i = cdk * z__4.i;
    z__6.r = sdk * fj->r, z__6.i = sdk * fj->i;
    z__7.r = t2.r + t1.r, z__7.i = t2.i + t1.i;
    z__5.r = z__6.r * z__7.r - z__6.i * z__7.i, z__5.i = z__6.r * z__7.i + 
	    z__6.i * z__7.r;
    z__2.r = z__3.r - z__5.r, z__2.i = z__3.i - z__5.i;
    z__1.r = hss * z__2.r, z__1.i = hss * z__2.i;
    hps->r = z__1.r, hps->i = z__1.i;
    d__1 = -sdk;
    z__3.r = ekr2.r + ekr1.r, z__3.i = ekr2.i + ekr1.i;
    z__2.r = d__1 * z__3.r, z__2.i = d__1 * z__3.i;
    z__5.r = cdk * fj->r, z__5.i = cdk * fj->i;
    z__6.r = t2.r - t1.r, z__6.i = t2.i - t1.i;
    z__4.r = z__5.r * z__6.r - z__5.i * z__6.i, z__4.i = z__5.r * z__6.i + 
	    z__5.i * z__6.r;
    z__1.r = z__2.r - z__4.r, z__1.i = z__2.i - z__4.i;
    hpc->r = z__1.r, hpc->i = z__1.i;
    z__2.r = -fj->r, z__2.i = -fj->i;
    d__1 = tp * 2.f * *rh;
    z__1.r = z__2.r / d__1, z__1.i = z__2.i / d__1;
    cons.r = z__1.r, cons.i = z__1.i;
    z__1.r = cons.r * hps->r - cons.i * hps->i, z__1.i = cons.r * hps->i + 
	    cons.i * hps->r;
    hps->r = z__1.r, hps->i = z__1.i;
    z__1.r = cons.r * hpc->r - cons.i * hpc->i, z__1.i = cons.r * hpc->i + 
	    cons.i * hpc->r;
    hpc->r = z__1.r, hpc->i = z__1.i;
    return 0;
L5:
    z__2.r = cdk, z__2.i = sdk;
    d__1 = z2 * z2;
    z__1.r = z__2.r / d__1, z__1.i = z__2.i / d__1;
    ekr1.r = z__1.r, ekr1.i = z__1.i;
    d__1 = -sdk;
    z__2.r = cdk, z__2.i = d__1;
    d__2 = z1 * z1;
    z__1.r = z__2.r / d__2, z__1.i = z__2.i / d__2;
    ekr2.r = z__1.r, ekr2.i = z__1.i;
    d__1 = tp * (1.f / z1 - 1.f / z2);
    t1.r = d__1, t1.i = 0.;
    z__4.r = zp * fjk->r, z__4.i = zp * fjk->i;
    z_exp(&z__3, &z__4);
    z__2.r = *rh * z__3.r, z__2.i = *rh * z__3.i;
    z__1.r = z__2.r / pi8, z__1.i = z__2.i / pi8;
    t2.r = z__1.r, t2.i = z__1.i;
    z__5.r = ekr1.r + ekr2.r, z__5.i = ekr1.i + ekr2.i;
    z__4.r = sdk * z__5.r, z__4.i = sdk * z__5.i;
    z__3.r = t1.r + z__4.r, z__3.i = t1.i + z__4.i;
    z__2.r = t2.r * z__3.r - t2.i * z__3.i, z__2.i = t2.r * z__3.i + t2.i * 
	    z__3.r;
    z__1.r = hss * z__2.r, z__1.i = hss * z__2.i;
    hps->r = z__1.r, hps->i = z__1.i;
    z__4.r = -fj->r, z__4.i = -fj->i;
    z__3.r = z__4.r * t1.r - z__4.i * t1.i, z__3.i = z__4.r * t1.i + z__4.i * 
	    t1.r;
    z__6.r = ekr1.r - ekr2.r, z__6.i = ekr1.i - ekr2.i;
    z__5.r = cdk * z__6.r, z__5.i = cdk * z__6.i;
    z__2.r = z__3.r + z__5.r, z__2.i = z__3.i + z__5.i;
    z__1.r = t2.r * z__2.r - t2.i * z__2.i, z__1.i = t2.r * z__2.i + t2.i * 
	    z__2.r;
    hpc->r = z__1.r, hpc->i = z__1.i;
    return 0;
L6:
    hps->r = 0.f, hps->i = 0.f;
    hpc->r = 0.f, hpc->i = 0.f;
    hpk->r = 0.f, hpk->i = 0.f;
    return 0;
} /* hsflx_ */

#undef fjkx
#undef fjx
#undef fjk
#undef fj


/* Subroutine */ int intrp_(doublereal *x, doublereal *y, doublecomplex *f1, 
	doublecomplex *f2, doublecomplex *f3, doublecomplex *f4)
{
    /* Initialized data */

    static integer ixs = -10;
    static integer iys = -10;
    static integer igrs = -10;
    static doublereal dx = 1.;
    static doublereal dy = 1.;
    static doublereal xs = 0.;
    static doublereal ys = 0.;
    static integer nda[3] = { 11,17,9 };
    static integer ndpa[3] = { 110,85,72 };
    static integer ixeg = 0;
    static integer iyeg = 0;

    /* System generated locals */
    integer i__1, i__2;
    doublecomplex z__1, z__2, z__3, z__4, z__5, z__6, z__7;
    static doublecomplex equiv_15[16], equiv_31[16], equiv_47[16], equiv_63[
	    16];

    /* Local variables */
#define a (equiv_15)
#define b (equiv_31)
#define c__ (equiv_47)
#define d__ (equiv_63)
    integer i__, k;
    doublecomplex p1, p2, p3, p4;
#define a11 (equiv_15)
#define a12 (equiv_15 + 4)
#define a13 (equiv_15 + 8)
#define a14 (equiv_15 + 12)
#define a21 (equiv_15 + 1)
#define a22 (equiv_15 + 5)
#define a23 (equiv_15 + 9)
#define a24 (equiv_15 + 13)
#define a31 (equiv_15 + 2)
#define a32 (equiv_15 + 6)
#define a33 (equiv_15 + 10)
#define a34 (equiv_15 + 14)
#define a41 (equiv_15 + 3)
#define a42 (equiv_15 + 7)
#define a43 (equiv_15 + 11)
#define a44 (equiv_15 + 15)
#define b11 (equiv_31)
#define b12 (equiv_31 + 4)
#define b13 (equiv_31 + 8)
#define b14 (equiv_31 + 12)
#define b21 (equiv_31 + 1)
#define b22 (equiv_31 + 5)
#define b23 (equiv_31 + 9)
#define b24 (equiv_31 + 13)
#define b31 (equiv_31 + 2)
#define b32 (equiv_31 + 6)
#define b33 (equiv_31 + 10)
#define b34 (equiv_31 + 14)
#define b41 (equiv_31 + 3)
#define b42 (equiv_31 + 7)
#define b43 (equiv_31 + 11)
#define b44 (equiv_31 + 15)
#define c11 (equiv_47)
#define c12 (equiv_47 + 4)
#define c13 (equiv_47 + 8)
#define c14 (equiv_47 + 12)
#define c21 (equiv_47 + 1)
#define c22 (equiv_47 + 5)
#define c23 (equiv_47 + 9)
#define c24 (equiv_47 + 13)
#define c31 (equiv_47 + 2)
#define c32 (equiv_47 + 6)
#define c33 (equiv_47 + 10)
#define c34 (equiv_47 + 14)
#define c41 (equiv_47 + 3)
#define c42 (equiv_47 + 7)
#define c43 (equiv_47 + 11)
#define c44 (equiv_47 + 15)
#define d11 (equiv_63)
#define d12 (equiv_63 + 4)
#define d13 (equiv_63 + 8)
#define d14 (equiv_63 + 12)
#define d21 (equiv_63 + 1)
#define d22 (equiv_63 + 5)
#define d23 (equiv_63 + 9)
#define d24 (equiv_63 + 13)
#define d31 (equiv_63 + 2)
#define d32 (equiv_63 + 6)
#define d33 (equiv_63 + 10)
#define d34 (equiv_63 + 14)
#define d41 (equiv_63 + 3)
#define d42 (equiv_63 + 7)
#define d43 (equiv_63 + 11)
#define d44 (equiv_63 + 15)
    integer ix, iy, nd;
    doublereal xz, yz;
    doublecomplex fx1, fx2, fx3, fx4;
    doublereal xx, yy;
#define xs2 ((doublereal *)&ggrid_1 + 2145)
#define ys3 ((doublereal *)&ggrid_1 + 2149)
    integer igr, ndp;
#define arl1 ((doublecomplex *)&ggrid_1)
#define arl2 ((doublecomplex *)&ggrid_1 + 440)
#define arl3 ((doublecomplex *)&ggrid_1 + 780)
    integer nxm2, nym2, iadd, iadz, nxms, nyms;

/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* *** */

/*     INTRP USES BIVARIATE CUBIC INTERPOLATION TO OBTAIN THE VALUES OF */
/*     4 FUNCTIONS AT THE POINT (X,Y). */

    if (*x < xs || *y < ys) {
	goto L1;
    }
    ix = (integer) ((*x - xs) / dx) + 1;
    iy = (integer) ((*y - ys) / dy) + 1;

/*     IF POINT LIES IN SAME 4 BY 4 POINT REGION AS PREVIOUS POINT, OLD */
/*     VALUES ARE REUSED */

    if (ix < ixeg || iy < iyeg) {
	goto L1;
    }
    if ((i__1 = ix - ixs, abs(i__1)) < 2 && (i__2 = iy - iys, abs(i__2)) < 2) 
	    {
	goto L12;
    }

/*     DETERMINE CORRECT GRID AND GRID REGION */

L1:
    if (*x > *xs2) {
	goto L2;
    }
    igr = 1;
    goto L3;
L2:
    igr = 2;
    if (*y > *ys3) {
	igr = 3;
    }
L3:
    if (igr == igrs) {
	goto L4;
    }
    igrs = igr;
    dx = ggrid_1.dxa[igrs - 1];
    dy = ggrid_1.dya[igrs - 1];
    xs = ggrid_1.xsa[igrs - 1];
    ys = ggrid_1.ysa[igrs - 1];
    nxm2 = ggrid_1.nxa[igrs - 1] - 2;
    nym2 = ggrid_1.nya[igrs - 1] - 2;
    nxms = (nxm2 + 1) / 3 * 3 + 1;
    nyms = (nym2 + 1) / 3 * 3 + 1;
    nd = nda[igrs - 1];
    ndp = ndpa[igrs - 1];
    ix = (integer) ((*x - xs) / dx) + 1;
    iy = (integer) ((*y - ys) / dy) + 1;
L4:
    ixs = (ix - 1) / 3 * 3 + 2;
    if (ixs < 2) {
	ixs = 2;
    }
    ixeg = -10000;
    if (ixs <= nxm2) {
	goto L5;
    }
    ixs = nxm2;
    ixeg = nxms;
L5:
    iys = (iy - 1) / 3 * 3 + 2;
    if (iys < 2) {
	iys = 2;
    }
    iyeg = -10000;
    if (iys <= nym2) {
	goto L6;
    }
    iys = nym2;
    iyeg = nyms;

/*     COMPUTE COEFFICIENTS OF 4 CUBIC POLYNOMIALS IN X FOR THE 4 GRID */
/*     VALUES OF Y FOR EACH OF THE 4 FUNCTIONS */

L6:
    iadz = ixs + (iys - 3) * nd - ndp;
    for (k = 1; k <= 4; ++k) {
	iadz += ndp;
	iadd = iadz;
	for (i__ = 1; i__ <= 4; ++i__) {
	    iadd += nd;
	    switch (igrs) {
		case 1:  goto L7;
		case 2:  goto L8;
		case 3:  goto L9;
	    }
/*     P1=AR1(IXS-1,IYS-2+I,K) */
L7:
	    i__1 = iadd - 2;
	    p1.r = arl1[i__1].r, p1.i = arl1[i__1].i;
	    i__1 = iadd - 1;
	    p2.r = arl1[i__1].r, p2.i = arl1[i__1].i;
	    i__1 = iadd;
	    p3.r = arl1[i__1].r, p3.i = arl1[i__1].i;
	    i__1 = iadd + 1;
	    p4.r = arl1[i__1].r, p4.i = arl1[i__1].i;
	    goto L10;
L8:
	    i__1 = iadd - 2;
	    p1.r = arl2[i__1].r, p1.i = arl2[i__1].i;
	    i__1 = iadd - 1;
	    p2.r = arl2[i__1].r, p2.i = arl2[i__1].i;
	    i__1 = iadd;
	    p3.r = arl2[i__1].r, p3.i = arl2[i__1].i;
	    i__1 = iadd + 1;
	    p4.r = arl2[i__1].r, p4.i = arl2[i__1].i;
	    goto L10;
L9:
	    i__1 = iadd - 2;
	    p1.r = arl3[i__1].r, p1.i = arl3[i__1].i;
	    i__1 = iadd - 1;
	    p2.r = arl3[i__1].r, p2.i = arl3[i__1].i;
	    i__1 = iadd;
	    p3.r = arl3[i__1].r, p3.i = arl3[i__1].i;
	    i__1 = iadd + 1;
	    p4.r = arl3[i__1].r, p4.i = arl3[i__1].i;
L10:
	    i__1 = i__ + (k << 2) - 5;
	    z__3.r = p4.r - p1.r, z__3.i = p4.i - p1.i;
	    z__5.r = p2.r - p3.r, z__5.i = p2.i - p3.i;
	    z__4.r = z__5.r * 3.f, z__4.i = z__5.i * 3.f;
	    z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
	    z__1.r = z__2.r * .1666666667, z__1.i = z__2.i * .1666666667;
	    a[i__1].r = z__1.r, a[i__1].i = z__1.i;
	    i__1 = i__ + (k << 2) - 5;
	    z__4.r = p2.r * 2.f, z__4.i = p2.i * 2.f;
	    z__3.r = p1.r - z__4.r, z__3.i = p1.i - z__4.i;
	    z__2.r = z__3.r + p3.r, z__2.i = z__3.i + p3.i;
	    z__1.r = z__2.r * .5f, z__1.i = z__2.i * .5f;
	    b[i__1].r = z__1.r, b[i__1].i = z__1.i;
	    i__1 = i__ + (k << 2) - 5;
	    z__5.r = p1.r * 2.f, z__5.i = p1.i * 2.f;
	    z__6.r = p2.r * 3.f, z__6.i = p2.i * 3.f;
	    z__4.r = z__5.r + z__6.r, z__4.i = z__5.i + z__6.i;
	    z__3.r = z__4.r + p4.r, z__3.i = z__4.i + p4.i;
	    z__2.r = z__3.r * .1666666667, z__2.i = z__3.i * .1666666667;
	    z__1.r = p3.r - z__2.r, z__1.i = p3.i - z__2.i;
	    c__[i__1].r = z__1.r, c__[i__1].i = z__1.i;
/* L11: */
	    i__1 = i__ + (k << 2) - 5;
	    d__[i__1].r = p2.r, d__[i__1].i = p2.i;
	}
    }
    xz = (ixs - 1) * dx + xs;
    yz = (iys - 1) * dy + ys;

/*     EVALUATE POLYMOMIALS IN X AND THEN USE CUBIC INTERPOLATION IN Y */
/*     FOR EACH OF THE 4 FUNCTIONS. */

L12:
    xx = (*x - xz) / dx;
    yy = (*y - yz) / dy;
    z__6.r = xx * a11->r, z__6.i = xx * a11->i;
    z__5.r = z__6.r + b11->r, z__5.i = z__6.i + b11->i;
    z__4.r = xx * z__5.r, z__4.i = xx * z__5.i;
    z__3.r = z__4.r + c11->r, z__3.i = z__4.i + c11->i;
    z__2.r = xx * z__3.r, z__2.i = xx * z__3.i;
    z__1.r = z__2.r + d11->r, z__1.i = z__2.i + d11->i;
    fx1.r = z__1.r, fx1.i = z__1.i;
    z__6.r = xx * a21->r, z__6.i = xx * a21->i;
    z__5.r = z__6.r + b21->r, z__5.i = z__6.i + b21->i;
    z__4.r = xx * z__5.r, z__4.i = xx * z__5.i;
    z__3.r = z__4.r + c21->r, z__3.i = z__4.i + c21->i;
    z__2.r = xx * z__3.r, z__2.i = xx * z__3.i;
    z__1.r = z__2.r + d21->r, z__1.i = z__2.i + d21->i;
    fx2.r = z__1.r, fx2.i = z__1.i;
    z__6.r = xx * a31->r, z__6.i = xx * a31->i;
    z__5.r = z__6.r + b31->r, z__5.i = z__6.i + b31->i;
    z__4.r = xx * z__5.r, z__4.i = xx * z__5.i;
    z__3.r = z__4.r + c31->r, z__3.i = z__4.i + c31->i;
    z__2.r = xx * z__3.r, z__2.i = xx * z__3.i;
    z__1.r = z__2.r + d31->r, z__1.i = z__2.i + d31->i;
    fx3.r = z__1.r, fx3.i = z__1.i;
    z__6.r = xx * a41->r, z__6.i = xx * a41->i;
    z__5.r = z__6.r + b41->r, z__5.i = z__6.i + b41->i;
    z__4.r = xx * z__5.r, z__4.i = xx * z__5.i;
    z__3.r = z__4.r + c41->r, z__3.i = z__4.i + c41->i;
    z__2.r = xx * z__3.r, z__2.i = xx * z__3.i;
    z__1.r = z__2.r + d41->r, z__1.i = z__2.i + d41->i;
    fx4.r = z__1.r, fx4.i = z__1.i;
    z__2.r = fx4.r - fx1.r, z__2.i = fx4.i - fx1.i;
    z__4.r = fx2.r - fx3.r, z__4.i = fx2.i - fx3.i;
    z__3.r = z__4.r * 3.f, z__3.i = z__4.i * 3.f;
    z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
    p1.r = z__1.r, p1.i = z__1.i;
    z__4.r = fx2.r * 2.f, z__4.i = fx2.i * 2.f;
    z__3.r = fx1.r - z__4.r, z__3.i = fx1.i - z__4.i;
    z__2.r = z__3.r + fx3.r, z__2.i = z__3.i + fx3.i;
    z__1.r = z__2.r * 3.f, z__1.i = z__2.i * 3.f;
    p2.r = z__1.r, p2.i = z__1.i;
    z__4.r = fx3.r * 6.f, z__4.i = fx3.i * 6.f;
    z__5.r = fx1.r * 2.f, z__5.i = fx1.i * 2.f;
    z__3.r = z__4.r - z__5.r, z__3.i = z__4.i - z__5.i;
    z__6.r = fx2.r * 3.f, z__6.i = fx2.i * 3.f;
    z__2.r = z__3.r - z__6.r, z__2.i = z__3.i - z__6.i;
    z__1.r = z__2.r - fx4.r, z__1.i = z__2.i - fx4.i;
    p3.r = z__1.r, p3.i = z__1.i;
    z__7.r = yy * p1.r, z__7.i = yy * p1.i;
    z__6.r = z__7.r + p2.r, z__6.i = z__7.i + p2.i;
    z__5.r = yy * z__6.r, z__5.i = yy * z__6.i;
    z__4.r = z__5.r + p3.r, z__4.i = z__5.i + p3.i;
    z__3.r = yy * z__4.r, z__3.i = yy * z__4.i;
    z__2.r = z__3.r * .1666666667, z__2.i = z__3.i * .1666666667;
    z__1.r = z__2.r + fx2.r, z__1.i = z__2.i + fx2.i;
    f1->r = z__1.r, f1->i = z__1.i;
    z__6.r = xx * a12->r, z__6.i = xx * a12->i;
    z__5.r = z__6.r + b12->r, z__5.i = z__6.i + b12->i;
    z__4.r = xx * z__5.r, z__4.i = xx * z__5.i;
    z__3.r = z__4.r + c12->r, z__3.i = z__4.i + c12->i;
    z__2.r = xx * z__3.r, z__2.i = xx * z__3.i;
    z__1.r = z__2.r + d12->r, z__1.i = z__2.i + d12->i;
    fx1.r = z__1.r, fx1.i = z__1.i;
    z__6.r = xx * a22->r, z__6.i = xx * a22->i;
    z__5.r = z__6.r + b22->r, z__5.i = z__6.i + b22->i;
    z__4.r = xx * z__5.r, z__4.i = xx * z__5.i;
    z__3.r = z__4.r + c22->r, z__3.i = z__4.i + c22->i;
    z__2.r = xx * z__3.r, z__2.i = xx * z__3.i;
    z__1.r = z__2.r + d22->r, z__1.i = z__2.i + d22->i;
    fx2.r = z__1.r, fx2.i = z__1.i;
    z__6.r = xx * a32->r, z__6.i = xx * a32->i;
    z__5.r = z__6.r + b32->r, z__5.i = z__6.i + b32->i;
    z__4.r = xx * z__5.r, z__4.i = xx * z__5.i;
    z__3.r = z__4.r + c32->r, z__3.i = z__4.i + c32->i;
    z__2.r = xx * z__3.r, z__2.i = xx * z__3.i;
    z__1.r = z__2.r + d32->r, z__1.i = z__2.i + d32->i;
    fx3.r = z__1.r, fx3.i = z__1.i;
    z__6.r = xx * a42->r, z__6.i = xx * a42->i;
    z__5.r = z__6.r + b42->r, z__5.i = z__6.i + b42->i;
    z__4.r = xx * z__5.r, z__4.i = xx * z__5.i;
    z__3.r = z__4.r + c42->r, z__3.i = z__4.i + c42->i;
    z__2.r = xx * z__3.r, z__2.i = xx * z__3.i;
    z__1.r = z__2.r + d42->r, z__1.i = z__2.i + d42->i;
    fx4.r = z__1.r, fx4.i = z__1.i;
    z__2.r = fx4.r - fx1.r, z__2.i = fx4.i - fx1.i;
    z__4.r = fx2.r - fx3.r, z__4.i = fx2.i - fx3.i;
    z__3.r = z__4.r * 3.f, z__3.i = z__4.i * 3.f;
    z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
    p1.r = z__1.r, p1.i = z__1.i;
    z__4.r = fx2.r * 2.f, z__4.i = fx2.i * 2.f;
    z__3.r = fx1.r - z__4.r, z__3.i = fx1.i - z__4.i;
    z__2.r = z__3.r + fx3.r, z__2.i = z__3.i + fx3.i;
    z__1.r = z__2.r * 3.f, z__1.i = z__2.i * 3.f;
    p2.r = z__1.r, p2.i = z__1.i;
    z__4.r = fx3.r * 6.f, z__4.i = fx3.i * 6.f;
    z__5.r = fx1.r * 2.f, z__5.i = fx1.i * 2.f;
    z__3.r = z__4.r - z__5.r, z__3.i = z__4.i - z__5.i;
    z__6.r = fx2.r * 3.f, z__6.i = fx2.i * 3.f;
    z__2.r = z__3.r - z__6.r, z__2.i = z__3.i - z__6.i;
    z__1.r = z__2.r - fx4.r, z__1.i = z__2.i - fx4.i;
    p3.r = z__1.r, p3.i = z__1.i;
    z__7.r = yy * p1.r, z__7.i = yy * p1.i;
    z__6.r = z__7.r + p2.r, z__6.i = z__7.i + p2.i;
    z__5.r = yy * z__6.r, z__5.i = yy * z__6.i;
    z__4.r = z__5.r + p3.r, z__4.i = z__5.i + p3.i;
    z__3.r = yy * z__4.r, z__3.i = yy * z__4.i;
    z__2.r = z__3.r * .1666666667, z__2.i = z__3.i * .1666666667;
    z__1.r = z__2.r + fx2.r, z__1.i = z__2.i + fx2.i;
    f2->r = z__1.r, f2->i = z__1.i;
    z__6.r = xx * a13->r, z__6.i = xx * a13->i;
    z__5.r = z__6.r + b13->r, z__5.i = z__6.i + b13->i;
    z__4.r = xx * z__5.r, z__4.i = xx * z__5.i;
    z__3.r = z__4.r + c13->r, z__3.i = z__4.i + c13->i;
    z__2.r = xx * z__3.r, z__2.i = xx * z__3.i;
    z__1.r = z__2.r + d13->r, z__1.i = z__2.i + d13->i;
    fx1.r = z__1.r, fx1.i = z__1.i;
    z__6.r = xx * a23->r, z__6.i = xx * a23->i;
    z__5.r = z__6.r + b23->r, z__5.i = z__6.i + b23->i;
    z__4.r = xx * z__5.r, z__4.i = xx * z__5.i;
    z__3.r = z__4.r + c23->r, z__3.i = z__4.i + c23->i;
    z__2.r = xx * z__3.r, z__2.i = xx * z__3.i;
    z__1.r = z__2.r + d23->r, z__1.i = z__2.i + d23->i;
    fx2.r = z__1.r, fx2.i = z__1.i;
    z__6.r = xx * a33->r, z__6.i = xx * a33->i;
    z__5.r = z__6.r + b33->r, z__5.i = z__6.i + b33->i;
    z__4.r = xx * z__5.r, z__4.i = xx * z__5.i;
    z__3.r = z__4.r + c33->r, z__3.i = z__4.i + c33->i;
    z__2.r = xx * z__3.r, z__2.i = xx * z__3.i;
    z__1.r = z__2.r + d33->r, z__1.i = z__2.i + d33->i;
    fx3.r = z__1.r, fx3.i = z__1.i;
    z__6.r = xx * a43->r, z__6.i = xx * a43->i;
    z__5.r = z__6.r + b43->r, z__5.i = z__6.i + b43->i;
    z__4.r = xx * z__5.r, z__4.i = xx * z__5.i;
    z__3.r = z__4.r + c43->r, z__3.i = z__4.i + c43->i;
    z__2.r = xx * z__3.r, z__2.i = xx * z__3.i;
    z__1.r = z__2.r + d43->r, z__1.i = z__2.i + d43->i;
    fx4.r = z__1.r, fx4.i = z__1.i;
    z__2.r = fx4.r - fx1.r, z__2.i = fx4.i - fx1.i;
    z__4.r = fx2.r - fx3.r, z__4.i = fx2.i - fx3.i;
    z__3.r = z__4.r * 3.f, z__3.i = z__4.i * 3.f;
    z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
    p1.r = z__1.r, p1.i = z__1.i;
    z__4.r = fx2.r * 2.f, z__4.i = fx2.i * 2.f;
    z__3.r = fx1.r - z__4.r, z__3.i = fx1.i - z__4.i;
    z__2.r = z__3.r + fx3.r, z__2.i = z__3.i + fx3.i;
    z__1.r = z__2.r * 3.f, z__1.i = z__2.i * 3.f;
    p2.r = z__1.r, p2.i = z__1.i;
    z__4.r = fx3.r * 6.f, z__4.i = fx3.i * 6.f;
    z__5.r = fx1.r * 2.f, z__5.i = fx1.i * 2.f;
    z__3.r = z__4.r - z__5.r, z__3.i = z__4.i - z__5.i;
    z__6.r = fx2.r * 3.f, z__6.i = fx2.i * 3.f;
    z__2.r = z__3.r - z__6.r, z__2.i = z__3.i - z__6.i;
    z__1.r = z__2.r - fx4.r, z__1.i = z__2.i - fx4.i;
    p3.r = z__1.r, p3.i = z__1.i;
    z__7.r = yy * p1.r, z__7.i = yy * p1.i;
    z__6.r = z__7.r + p2.r, z__6.i = z__7.i + p2.i;
    z__5.r = yy * z__6.r, z__5.i = yy * z__6.i;
    z__4.r = z__5.r + p3.r, z__4.i = z__5.i + p3.i;
    z__3.r = yy * z__4.r, z__3.i = yy * z__4.i;
    z__2.r = z__3.r * .1666666667, z__2.i = z__3.i * .1666666667;
    z__1.r = z__2.r + fx2.r, z__1.i = z__2.i + fx2.i;
    f3->r = z__1.r, f3->i = z__1.i;
    z__6.r = xx * a14->r, z__6.i = xx * a14->i;
    z__5.r = z__6.r + b14->r, z__5.i = z__6.i + b14->i;
    z__4.r = xx * z__5.r, z__4.i = xx * z__5.i;
    z__3.r = z__4.r + c14->r, z__3.i = z__4.i + c14->i;
    z__2.r = xx * z__3.r, z__2.i = xx * z__3.i;
    z__1.r = z__2.r + d14->r, z__1.i = z__2.i + d14->i;
    fx1.r = z__1.r, fx1.i = z__1.i;
    z__6.r = xx * a24->r, z__6.i = xx * a24->i;
    z__5.r = z__6.r + b24->r, z__5.i = z__6.i + b24->i;
    z__4.r = xx * z__5.r, z__4.i = xx * z__5.i;
    z__3.r = z__4.r + c24->r, z__3.i = z__4.i + c24->i;
    z__2.r = xx * z__3.r, z__2.i = xx * z__3.i;
    z__1.r = z__2.r + d24->r, z__1.i = z__2.i + d24->i;
    fx2.r = z__1.r, fx2.i = z__1.i;
    z__6.r = xx * a34->r, z__6.i = xx * a34->i;
    z__5.r = z__6.r + b34->r, z__5.i = z__6.i + b34->i;
    z__4.r = xx * z__5.r, z__4.i = xx * z__5.i;
    z__3.r = z__4.r + c34->r, z__3.i = z__4.i + c34->i;
    z__2.r = xx * z__3.r, z__2.i = xx * z__3.i;
    z__1.r = z__2.r + d34->r, z__1.i = z__2.i + d34->i;
    fx3.r = z__1.r, fx3.i = z__1.i;
    z__6.r = xx * a44->r, z__6.i = xx * a44->i;
    z__5.r = z__6.r + b44->r, z__5.i = z__6.i + b44->i;
    z__4.r = xx * z__5.r, z__4.i = xx * z__5.i;
    z__3.r = z__4.r + c44->r, z__3.i = z__4.i + c44->i;
    z__2.r = xx * z__3.r, z__2.i = xx * z__3.i;
    z__1.r = z__2.r + d44->r, z__1.i = z__2.i + d44->i;
    fx4.r = z__1.r, fx4.i = z__1.i;
    z__2.r = fx4.r - fx1.r, z__2.i = fx4.i - fx1.i;
    z__4.r = fx2.r - fx3.r, z__4.i = fx2.i - fx3.i;
    z__3.r = z__4.r * 3.f, z__3.i = z__4.i * 3.f;
    z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
    p1.r = z__1.r, p1.i = z__1.i;
    z__4.r = fx2.r * 2.f, z__4.i = fx2.i * 2.f;
    z__3.r = fx1.r - z__4.r, z__3.i = fx1.i - z__4.i;
    z__2.r = z__3.r + fx3.r, z__2.i = z__3.i + fx3.i;
    z__1.r = z__2.r * 3.f, z__1.i = z__2.i * 3.f;
    p2.r = z__1.r, p2.i = z__1.i;
    z__4.r = fx3.r * 6.f, z__4.i = fx3.i * 6.f;
    z__5.r = fx1.r * 2.f, z__5.i = fx1.i * 2.f;
    z__3.r = z__4.r - z__5.r, z__3.i = z__4.i - z__5.i;
    z__6.r = fx2.r * 3.f, z__6.i = fx2.i * 3.f;
    z__2.r = z__3.r - z__6.r, z__2.i = z__3.i - z__6.i;
    z__1.r = z__2.r - fx4.r, z__1.i = z__2.i - fx4.i;
    p3.r = z__1.r, p3.i = z__1.i;
    z__7.r = yy * p1.r, z__7.i = yy * p1.i;
    z__6.r = z__7.r + p2.r, z__6.i = z__7.i + p2.i;
    z__5.r = yy * z__6.r, z__5.i = yy * z__6.i;
    z__4.r = z__5.r + p3.r, z__4.i = z__5.i + p3.i;
    z__3.r = yy * z__4.r, z__3.i = yy * z__4.i;
    z__2.r = z__3.r * .1666666667, z__2.i = z__3.i * .1666666667;
    z__1.r = z__2.r + fx2.r, z__1.i = z__2.i + fx2.i;
    f4->r = z__1.r, f4->i = z__1.i;
    return 0;
} /* intrp_ */

#undef arl3
#undef arl2
#undef arl1
#undef ys3
#undef xs2
#undef d44
#undef d43
#undef d42
#undef d41
#undef d34
#undef d33
#undef d32
#undef d31
#undef d24
#undef d23
#undef d22
#undef d21
#undef d14
#undef d13
#undef d12
#undef d11
#undef c44
#undef c43
#undef c42
#undef c41
#undef c34
#undef c33
#undef c32
#undef c31
#undef c24
#undef c23
#undef c22
#undef c21
#undef c14
#undef c13
#undef c12
#undef c11
#undef b44
#undef b43
#undef b42
#undef b41
#undef b34
#undef b33
#undef b32
#undef b31
#undef b24
#undef b23
#undef b22
#undef b21
#undef b14
#undef b13
#undef b12
#undef b11
#undef a44
#undef a43
#undef a42
#undef a41
#undef a34
#undef a33
#undef a32
#undef a31
#undef a24
#undef a23
#undef a22
#undef a21
#undef a14
#undef a13
#undef a12
#undef a11
#undef d__
#undef c__
#undef b
#undef a


/* Subroutine */ int intx_(doublereal *el1, doublereal *el2, doublereal *b, 
	integer *ij, doublereal *sgr, doublereal *sgi)
{
    /* Initialized data */

    static integer nx = 1;
    static integer nm = 65536;
    static integer nts = 4;
    static doublereal rx = 1e-4;

    /* Format strings */
    static char fmt_20[] = "(\002 STEP SIZE LIMITED AT Z=\002,f10.5)";

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    double sqrt(doublereal), log(doublereal);

    /* Local variables */
    doublereal s, z__;
    extern /* Subroutine */ int gf_(doublereal *, doublereal *, doublereal *);
    doublereal ep, dz, ze;
    integer ns, nt;
    doublereal zp, g1i, g3i, g5i, g2i, g4i, g1r, g2r, g3r, g4r, g5r, t00i, 
	    t01i, t10i, t02i, fnm, t11i, t20i, t00r, fns, t01r, t10r, t02r, 
	    t11r, t20r, te1i, te2i, te1r, te2r, zend;
    extern /* Subroutine */ int test_(doublereal *, doublereal *, doublereal *
	    , doublereal *, doublereal *, doublereal *, doublereal *);
    doublereal dzot;

    /* Fortran I/O blocks */
    static cilist io___1602 = { 0, 3, 0, fmt_20, 0 };


/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* *** */

/*     INTX PERFORMS NUMERICAL INTEGRATION OF EXP(JKR)/R BY THE METHOD OF */
/*     VARIABLE INTERVAL WIDTH ROMBERG INTEGRATION.  THE INTEGRAND VALUE */
/*     IS SUPPLIED BY SUBROUTINE GF. */

    z__ = *el1;
    ze = *el2;
    if (*ij == 0) {
	ze = 0.f;
    }
    s = ze - z__;
    fnm = (doublereal) nm;
    ep = s / (fnm * 10.f);
    zend = ze - ep;
    *sgr = 0.f;
    *sgi = 0.f;
    ns = nx;
    nt = 0;
    gf_(&z__, &g1r, &g1i);
L1:
    fns = (doublereal) ns;
    dz = s / fns;
    zp = z__ + dz;
    if (zp - ze <= 0.) {
	goto L3;
    } else {
	goto L2;
    }
L2:
    dz = ze - z__;
    if (abs(dz) - ep <= 0.) {
	goto L17;
    } else {
	goto L3;
    }
L3:
    dzot = dz * .5f;
    zp = z__ + dzot;
    gf_(&zp, &g3r, &g3i);
    zp = z__ + dz;
    gf_(&zp, &g5r, &g5i);
L4:
    t00r = (g1r + g5r) * dzot;
    t00i = (g1i + g5i) * dzot;
    t01r = (t00r + dz * g3r) * .5f;
    t01i = (t00i + dz * g3i) * .5f;
    t10r = (t01r * 4.f - t00r) / 3.f;
    t10i = (t01i * 4.f - t00i) / 3.f;

/*     TEST CONVERGENCE OF 3 POINT ROMBERG RESULT. */

    test_(&t01r, &t10r, &te1r, &t01i, &t10i, &te1i, &c_b636);
    if (te1i - rx <= 0.) {
	goto L5;
    } else {
	goto L6;
    }
L5:
    if (te1r - rx <= 0.) {
	goto L8;
    } else {
	goto L6;
    }
L6:
    zp = z__ + dz * .25f;
    gf_(&zp, &g2r, &g2i);
    zp = z__ + dz * .75f;
    gf_(&zp, &g4r, &g4i);
    t02r = (t01r + dzot * (g2r + g4r)) * .5f;
    t02i = (t01i + dzot * (g2i + g4i)) * .5f;
    t11r = (t02r * 4.f - t01r) / 3.f;
    t11i = (t02i * 4.f - t01i) / 3.f;
    t20r = (t11r * 16.f - t10r) / 15.f;
    t20i = (t11i * 16.f - t10i) / 15.f;

/*     TEST CONVERGENCE OF 5 POINT ROMBERG RESULT. */

    test_(&t11r, &t20r, &te2r, &t11i, &t20i, &te2i, &c_b636);
    if (te2i - rx <= 0.) {
	goto L7;
    } else {
	goto L14;
    }
L7:
    if (te2r - rx <= 0.) {
	goto L9;
    } else {
	goto L14;
    }
L8:
    *sgr += t10r;
    *sgi += t10i;
    nt += 2;
    goto L10;
L9:
    *sgr += t20r;
    *sgi += t20i;
    ++nt;
L10:
    z__ += dz;
    if (z__ - zend >= 0.) {
	goto L17;
    } else {
	goto L11;
    }
L11:
    g1r = g5r;
    g1i = g5i;
    if (nt - nts >= 0) {
	goto L12;
    } else {
	goto L1;
    }
L12:
    if (ns - nx <= 0) {
	goto L1;
    } else {
	goto L13;
    }

/*     DOUBLE STEP SIZE */

L13:
    ns /= 2;
    nt = 1;
    goto L1;
L14:
    nt = 0;
    if (ns - nm >= 0) {
	goto L15;
    } else {
	goto L16;
    }
L15:
    s_wsfe(&io___1602);
    do_fio(&c__1, (char *)&z__, (ftnlen)sizeof(doublereal));
    e_wsfe();
    goto L9;

/*     HALVE STEP SIZE */

L16:
    ns <<= 1;
    fns = (doublereal) ns;
    dz = s / fns;
    dzot = dz * .5f;
    g5r = g3r;
    g5i = g3i;
    g3r = g2r;
    g3i = g2i;
    goto L4;
L17:
    if (*ij != 0) {
	goto L19;
    } else {
	goto L18;
    }

/*     ADD CONTRIBUTION OF NEAR SINGULARITY FOR DIAGONAL TERM */

L18:
    *sgr = (*sgr + log((sqrt(*b * *b + s * s) + s) / *b)) * 2.f;
    *sgi *= 2.f;
L19:
    return 0;

} /* intx_ */

integer isegno_(integer *itagi, integer *mx)
{
    /* Format strings */
    static char fmt_6[] = "(4x,\002CHECK DATA, PARAMETER SPECIFYING SEGMENT "
	    "POSITION IN A GROUP OF EQUAL TAGS MUST NOT BE ZERO\002)";
    static char fmt_7[] = "(///,10x,\002NO SEGMENT HAS AN ITAG OF \002,i5)";

    /* System generated locals */
    integer ret_val, i__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer do_fio(integer *, char *, ftnlen);

    /* Local variables */
    integer i__, icnt;

    /* Fortran I/O blocks */
    static cilist io___1603 = { 0, 3, 0, fmt_6, 0 };
    static cilist io___1606 = { 0, 3, 0, fmt_7, 0 };


/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* Max number of segments 	(Windows-95 <= 4 */
/* max nr of 'in-core' alloc.	(MAXMAT <= MA */
/* Max number of LD cards */
/* Max number of EX cards */
/* Max number of segs connected to NT/TL */
/* *** */

/*     ISEGNO RETURNS THE SEGMENT NUMBER OF THE MTH SEGMENT HAVING THE */
/*     TAG NUMBER ITAGI.  IF ITAGI=0 SEGMENT NUMBER M IS RETURNED. */

    if (*mx > 0) {
	goto L1;
    }
    s_wsfe(&io___1603);
    e_wsfe();
    s_stop("", (ftnlen)0);
L1:
    icnt = 0;
    if (*itagi != 0) {
	goto L2;
    }
    ret_val = *mx;
    return ret_val;
L2:
    if (data_1.n < 1) {
	goto L4;
    }
    i__1 = data_1.n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (data_1.itag[i__ - 1] != *itagi) {
	    goto L3;
	}
	++icnt;
	if (icnt == *mx) {
	    goto L5;
	}
L3:
	;
    }
L4:
    s_wsfe(&io___1606);
    do_fio(&c__1, (char *)&(*itagi), (ftnlen)sizeof(integer));
    e_wsfe();
    s_stop("", (ftnlen)0);
L5:
    ret_val = i__;
    return ret_val;

} /* isegno_ */

/* Subroutine */ int lfactr_(doublecomplex *a, integer *nrow, integer *ix1, 
	integer *ix2, integer *ip)
{
    /* Format strings */
    static char fmt_17[] = "(\002 \002,\002PIVOT(\002,i3,\002)=\002,1p,e16.8)"
	    ;

    /* System generated locals */
    integer a_dim1, a_offset, i__1, i__2, i__3, i__4, i__5, i__6;
    doublecomplex z__1, z__2;

    /* Builtin functions */
    void d_cnjg(doublecomplex *, doublecomplex *), z_div(doublecomplex *, 
	    doublecomplex *, doublecomplex *);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    integer i__, j, k, r__, j1, j2;
    logical l1, l2, l3;
    integer r1, r2, pj, pr, jp1;
    doublecomplex ajr;
    integer j2p1, j2p2, ixj, iflg;
    doublereal dmax__, elmag;

    /* Fortran I/O blocks */
    static cilist io___1628 = { 0, 3, 0, fmt_17, 0 };


/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* Max number of segments 	(Windows-95 <= 4 */
/* max nr of 'in-core' alloc.	(MAXMAT <= MA */
/* Max number of LD cards */
/* Max number of EX cards */
/* Max number of segs connected to NT/TL */
/* *** */

/*     LFACTR PERFORMS GAUSS-DOOLITTLE MANIPULATIONS ON THE TWO BLOCKS OF */
/*     THE TRANSPOSED MATRIX IN CORE STORAGE.  THE GAUSS-DOOLITTLE */
/*     ALGORITHM IS PRESENTED ON PAGES 411-416 OF A. RALSTON -- A FIRST */
/*     COURSE IN NUMERICAL ANALYSIS.  COMMENTS BELOW REFER TO COMMENTS IN */
/*     RALSTONS TEXT. */

    /* Parameter adjustments */
    --ip;
    a_dim1 = *nrow;
    a_offset = 1 + a_dim1;
    a -= a_offset;

    /* Function Body */
    iflg = 0;

/*     INITIALIZE R1,R2,J1,J2 */

    l1 = *ix1 == 1 && *ix2 == 2;
    l2 = *ix2 - 1 == *ix1;
    l3 = *ix2 == matpar_1.nblsym;
    if (l1) {
	goto L1;
    }
    goto L2;
L1:
    r1 = 1;
    r2 = matpar_1.npsym << 1;
    j1 = 1;
    j2 = -1;
    goto L5;
L2:
    r1 = matpar_1.npsym + 1;
    r2 = matpar_1.npsym << 1;
    j1 = (*ix1 - 1) * matpar_1.npsym + 1;
    if (l2) {
	goto L3;
    }
    goto L4;
L3:
    j2 = j1 + matpar_1.npsym - 2;
    goto L5;
L4:
    j2 = j1 + matpar_1.npsym - 1;
L5:
    if (l3) {
	r2 = matpar_1.npsym + matpar_1.nlsym;
    }
    i__1 = r2;
    for (r__ = r1; r__ <= i__1; ++r__) {

/*     STEP 1 */

	i__2 = *nrow;
	for (k = j1; k <= i__2; ++k) {
	    i__3 = k - 1;
	    i__4 = k + r__ * a_dim1;
	    scratm_1.d__[i__3].r = a[i__4].r, scratm_1.d__[i__3].i = a[i__4]
		    .i;
/* L6: */
	}

/*     STEPS 2 AND 3 */

	if (l1 || l2) {
	    ++j2;
	}
	if (j1 > j2) {
	    goto L9;
	}
	ixj = 0;
	i__2 = j2;
	for (j = j1; j <= i__2; ++j) {
	    ++ixj;
	    pj = ip[j];
	    i__3 = pj - 1;
	    ajr.r = scratm_1.d__[i__3].r, ajr.i = scratm_1.d__[i__3].i;
	    i__3 = j + r__ * a_dim1;
	    a[i__3].r = ajr.r, a[i__3].i = ajr.i;
	    i__3 = pj - 1;
	    i__4 = j - 1;
	    scratm_1.d__[i__3].r = scratm_1.d__[i__4].r, scratm_1.d__[i__3].i 
		    = scratm_1.d__[i__4].i;
	    jp1 = j + 1;
	    i__3 = *nrow;
	    for (i__ = jp1; i__ <= i__3; ++i__) {
		i__4 = i__ - 1;
		i__5 = i__ - 1;
		i__6 = i__ + ixj * a_dim1;
		z__2.r = a[i__6].r * ajr.r - a[i__6].i * ajr.i, z__2.i = a[
			i__6].r * ajr.i + a[i__6].i * ajr.r;
		z__1.r = scratm_1.d__[i__5].r - z__2.r, z__1.i = scratm_1.d__[
			i__5].i - z__2.i;
		scratm_1.d__[i__4].r = z__1.r, scratm_1.d__[i__4].i = z__1.i;
/* L7: */
	    }
/* L8: */
	}
L9:

/*     STEP 4 */

	j2p1 = j2 + 1;
	if (l1 || l2) {
	    goto L11;
	}
	if (*nrow < j2p1) {
	    goto L16;
	}
	i__2 = *nrow;
	for (i__ = j2p1; i__ <= i__2; ++i__) {
	    i__3 = i__ + r__ * a_dim1;
	    i__4 = i__ - 1;
	    a[i__3].r = scratm_1.d__[i__4].r, a[i__3].i = scratm_1.d__[i__4]
		    .i;
/* L10: */
	}
	goto L16;
L11:
	i__2 = j2p1 - 1;
	d_cnjg(&z__2, &scratm_1.d__[j2p1 - 1]);
	z__1.r = scratm_1.d__[i__2].r * z__2.r - scratm_1.d__[i__2].i * 
		z__2.i, z__1.i = scratm_1.d__[i__2].r * z__2.i + scratm_1.d__[
		i__2].i * z__2.r;
	dmax__ = z__1.r;
	ip[j2p1] = j2p1;
	j2p2 = j2 + 2;
	if (j2p2 > *nrow) {
	    goto L13;
	}
	i__2 = *nrow;
	for (i__ = j2p2; i__ <= i__2; ++i__) {
	    i__3 = i__ - 1;
	    d_cnjg(&z__2, &scratm_1.d__[i__ - 1]);
	    z__1.r = scratm_1.d__[i__3].r * z__2.r - scratm_1.d__[i__3].i * 
		    z__2.i, z__1.i = scratm_1.d__[i__3].r * z__2.i + 
		    scratm_1.d__[i__3].i * z__2.r;
	    elmag = z__1.r;
	    if (elmag < dmax__) {
		goto L12;
	    }
	    dmax__ = elmag;
	    ip[j2p1] = i__;
L12:
	    ;
	}
L13:
	if (dmax__ < 1e-10) {
	    iflg = 1;
	}
	pr = ip[j2p1];
	i__2 = j2p1 + r__ * a_dim1;
	i__3 = pr - 1;
	a[i__2].r = scratm_1.d__[i__3].r, a[i__2].i = scratm_1.d__[i__3].i;
	i__2 = pr - 1;
	i__3 = j2p1 - 1;
	scratm_1.d__[i__2].r = scratm_1.d__[i__3].r, scratm_1.d__[i__2].i = 
		scratm_1.d__[i__3].i;

/*     STEP 5 */

	if (j2p2 > *nrow) {
	    goto L15;
	}
	z_div(&z__1, &c_b245, &a[j2p1 + r__ * a_dim1]);
	ajr.r = z__1.r, ajr.i = z__1.i;
	i__2 = *nrow;
	for (i__ = j2p2; i__ <= i__2; ++i__) {
	    i__3 = i__ + r__ * a_dim1;
	    i__4 = i__ - 1;
	    z__1.r = scratm_1.d__[i__4].r * ajr.r - scratm_1.d__[i__4].i * 
		    ajr.i, z__1.i = scratm_1.d__[i__4].r * ajr.i + 
		    scratm_1.d__[i__4].i * ajr.r;
	    a[i__3].r = z__1.r, a[i__3].i = z__1.i;
/* L14: */
	}
L15:
	if (iflg == 0) {
	    goto L16;
	}
	s_wsfe(&io___1628);
	do_fio(&c__1, (char *)&j2, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&dmax__, (ftnlen)sizeof(doublereal));
	e_wsfe();
	iflg = 0;
L16:
	;
    }
    return 0;

} /* lfactr_ */

/* Subroutine */ int load_(integer *ldtyp, integer *ldtag, integer *ldtagf, 
	integer *ldtagt, doublereal *zlr, doublereal *zli, doublereal *zlc)
{
    /* Initialized data */

    static struct {
	doublereal e_1[2];
	} equiv_0 = { 0., 1883698955. };


    /* Format strings */
    static char fmt_25[] = "(//,7x,\002LOCATION\002,10x,\002RESISTANCE\002,3"
	    "x,\002INDUCTANCE\002,2x,\002CAPACITANCE\002,7x,\002IMPEDANCE (OH"
	    "MS)\002,5x,\002CONDUCTIVITY\002,4x,\002TYPE\002,/,4x,\002ITAG"
	    "\002,\002 FROM THRU\002,10x,\002OHMS\002,8x,\002HENRYS\002,7x"
	    ",\002FARADS\002,8x,\002REAL\002,6x,\002IMAGINARY\002,4x,\002MHOS"
	    "/METER\002)";
    static char fmt_26[] = "(/,10x,\002NOTE, SOME OF THE ABOVE SEGMENTS HAVE"
	    " BEEN LOADED TWICE - IMPEDANCES ADDED\002)";
    static char fmt_27[] = "(/,10x,\002IMPROPER LOAD TYPE CHOOSEN, REQUESTED"
	    " TYPE IS \002,i3)";
    static char fmt_29[] = "(\002 ERROR - LOADING MAY NOT BE ADDED TO SEGMEN"
	    "TS IN N.G.F. SECTION\002)";
    static char fmt_28[] = "(/,10x,\002LOADING DATA CARD ERROR, NO SEGMENT H"
	    "AS AN ITAG = \002,i5)";

    /* System generated locals */
    integer i__1, i__2, i__3, i__4;
    doublereal d__1, d__2;
    doublecomplex z__1, z__2, z__3, z__4, z__5;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void), do_fio(integer *, char *, ftnlen);
    /* Subroutine */ int s_stop(char *, ftnlen);
    void z_div(doublecomplex *, doublecomplex *, doublecomplex *);
    double d_imag(doublecomplex *);

    /* Local variables */
    integer i__, l1, l2;
    doublecomplex zt;
    integer nop, ichk;
#define tpcj ((doublecomplex *)&equiv_0)
    integer jump;
    extern /* Subroutine */ int prnt_(integer *, integer *, integer *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, char *, ftnlen);
    extern /* Double Complex */ VOID zint_(doublecomplex *, doublereal *, 
	    doublereal *);
    integer iwarn, istep;
#define tpcjx ((doublereal *)&equiv_0)
    integer ldtags;

    /* Fortran I/O blocks */
    static cilist io___1631 = { 0, 3, 0, fmt_25, 0 };
    static cilist io___1635 = { 0, 3, 0, fmt_26, 0 };
    static cilist io___1640 = { 0, 3, 0, fmt_27, 0 };
    static cilist io___1644 = { 0, 3, 0, fmt_29, 0 };
    static cilist io___1645 = { 0, 3, 0, fmt_28, 0 };


/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* Max number of segments 	(Windows-95 <= 4 */
/* max nr of 'in-core' alloc.	(MAXMAT <= MA */
/* Max number of LD cards */
/* Max number of EX cards */
/* Max number of segs connected to NT/TL */
/* *** */

/*     LOAD CALCULATES THE IMPEDANCE OF SPECIFIED SEGMENTS FOR VARIOUS */
/*     TYPES OF LOADING */

    /* Parameter adjustments */
    --zlc;
    --zli;
    --zlr;
    --ldtagt;
    --ldtagf;
    --ldtag;
    --ldtyp;

    /* Function Body */

/*     WRITE(3,HEADING) */

    s_wsfe(&io___1631);
    e_wsfe();

/*     INITIALIZE D ARRAY, USED FOR TEMPORARY STORAGE OF LOADING */
/*     INFORMATION. */

    i__1 = data_1.n;
    for (i__ = data_1.n2; i__ <= i__1; ++i__) {
/* L1: */
	i__2 = i__ - 1;
	zload_1.zarray[i__2].r = 0.f, zload_1.zarray[i__2].i = 0.f;
    }
    iwarn = 0;

/*     CYCLE OVER LOADING CARDS */

    istep = 0;
L2:
    ++istep;
    if (istep <= zload_1.nload) {
	goto L5;
    }
    if (iwarn == 1) {
	s_wsfe(&io___1635);
	e_wsfe();
    }
    if (data_1.n1 + (data_1.m1 << 1) > 0) {
	goto L4;
    }
    nop = data_1.n / data_1.np;
    if (nop == 1) {
	goto L4;
    }
    i__2 = data_1.np;
    for (i__ = 1; i__ <= i__2; ++i__) {
	i__1 = i__ - 1;
	zt.r = zload_1.zarray[i__1].r, zt.i = zload_1.zarray[i__1].i;
	l1 = i__;
	i__1 = nop;
	for (l2 = 2; l2 <= i__1; ++l2) {
	    l1 += data_1.np;
/* L3: */
	    i__3 = l1 - 1;
	    zload_1.zarray[i__3].r = zt.r, zload_1.zarray[i__3].i = zt.i;
	}
    }
L4:
    return 0;
L5:
    if (ldtyp[istep] <= 5) {
	goto L6;
    }
    s_wsfe(&io___1640);
    do_fio(&c__1, (char *)&ldtyp[istep], (ftnlen)sizeof(integer));
    e_wsfe();
    s_stop("", (ftnlen)0);
L6:
    ldtags = ldtag[istep];
    jump = ldtyp[istep] + 1;
    ichk = 0;

/*     SEARCH SEGMENTS FOR PROPER ITAGS */

    l1 = data_1.n2;
    l2 = data_1.n;
    if (ldtags != 0) {
	goto L7;
    }
    if (ldtagf[istep] == 0 && ldtagt[istep] == 0) {
	goto L7;
    }
    l1 = ldtagf[istep];
    l2 = ldtagt[istep];
    if (l1 > data_1.n1) {
	goto L7;
    }
    s_wsfe(&io___1644);
    e_wsfe();
    s_stop("", (ftnlen)0);
L7:
    i__3 = l2;
    for (i__ = l1; i__ <= i__3; ++i__) {
	if (ldtags == 0) {
	    goto L8;
	}
	if (ldtags != data_1.itag[i__ - 1]) {
	    goto L17;
	}
	if (ldtagf[istep] == 0) {
	    goto L8;
	}
	++ichk;
	if (ichk >= ldtagf[istep] && ichk <= ldtagt[istep]) {
	    goto L9;
	}
	goto L17;
L8:
	ichk = 1;

/*     CALCULATION OF LAMDA*IMPED. PER UNIT LENGTH, JUMP TO APPROPRIATE */
/*     SECTION FOR LOADING TYPE */

L9:
	switch (jump) {
	    case 1:  goto L10;
	    case 2:  goto L11;
	    case 3:  goto L12;
	    case 4:  goto L13;
	    case 5:  goto L14;
	    case 6:  goto L15;
	}
L10:
	d__1 = zlr[istep] / data_1.si[i__ - 1];
	i__1 = istep;
	z__3.r = zli[i__1] * tpcj->r, z__3.i = zli[i__1] * tpcj->i;
	d__2 = data_1.si[i__ - 1] * data_1.wlam;
	z__2.r = z__3.r / d__2, z__2.i = z__3.i / d__2;
	z__1.r = d__1 + z__2.r, z__1.i = z__2.i;
	zt.r = z__1.r, zt.i = z__1.i;
	if ((d__1 = zlc[istep], abs(d__1)) > 1e-20) {
	    z__3.r = data_1.wlam, z__3.i = 0.;
	    i__1 = i__ - 1;
	    z__5.r = data_1.si[i__1] * tpcj->r, z__5.i = data_1.si[i__1] * 
		    tpcj->i;
	    i__2 = istep;
	    z__4.r = zlc[i__2] * z__5.r, z__4.i = zlc[i__2] * z__5.i;
	    z_div(&z__2, &z__3, &z__4);
	    z__1.r = zt.r + z__2.r, z__1.i = zt.i + z__2.i;
	    zt.r = z__1.r, zt.i = z__1.i;
	}
	goto L16;
L11:
	i__1 = i__ - 1;
	z__3.r = data_1.si[i__1] * tpcj->r, z__3.i = data_1.si[i__1] * 
		tpcj->i;
	i__2 = istep;
	z__2.r = zlc[i__2] * z__3.r, z__2.i = zlc[i__2] * z__3.i;
	z__1.r = z__2.r / data_1.wlam, z__1.i = z__2.i / data_1.wlam;
	zt.r = z__1.r, zt.i = z__1.i;
	if ((d__1 = zli[istep], abs(d__1)) > 1e-20) {
	    d__2 = data_1.si[i__ - 1] * data_1.wlam;
	    z__3.r = d__2, z__3.i = 0.;
	    i__1 = istep;
	    z__4.r = zli[i__1] * tpcj->r, z__4.i = zli[i__1] * tpcj->i;
	    z_div(&z__2, &z__3, &z__4);
	    z__1.r = zt.r + z__2.r, z__1.i = zt.i + z__2.i;
	    zt.r = z__1.r, zt.i = z__1.i;
	}
	if ((d__1 = zlr[istep], abs(d__1)) > 1e-20) {
	    d__2 = data_1.si[i__ - 1] / zlr[istep];
	    z__1.r = zt.r + d__2, z__1.i = zt.i;
	    zt.r = z__1.r, zt.i = z__1.i;
	}
	z_div(&z__1, &c_b245, &zt);
	zt.r = z__1.r, zt.i = z__1.i;
	goto L16;
L12:
	d__1 = zlr[istep] * data_1.wlam;
	i__1 = istep;
	z__2.r = zli[i__1] * tpcj->r, z__2.i = zli[i__1] * tpcj->i;
	z__1.r = d__1 + z__2.r, z__1.i = z__2.i;
	zt.r = z__1.r, zt.i = z__1.i;
	if ((d__1 = zlc[istep], abs(d__1)) > 1e-20) {
	    i__1 = i__ - 1;
	    z__5.r = data_1.si[i__1] * tpcj->r, z__5.i = data_1.si[i__1] * 
		    tpcj->i;
	    i__2 = i__ - 1;
	    z__4.r = data_1.si[i__2] * z__5.r, z__4.i = data_1.si[i__2] * 
		    z__5.i;
	    i__4 = istep;
	    z__3.r = zlc[i__4] * z__4.r, z__3.i = zlc[i__4] * z__4.i;
	    z_div(&z__2, &c_b245, &z__3);
	    z__1.r = zt.r + z__2.r, z__1.i = zt.i + z__2.i;
	    zt.r = z__1.r, zt.i = z__1.i;
	}
	goto L16;
L13:
	i__1 = i__ - 1;
	z__3.r = data_1.si[i__1] * tpcj->r, z__3.i = data_1.si[i__1] * 
		tpcj->i;
	i__2 = i__ - 1;
	z__2.r = data_1.si[i__2] * z__3.r, z__2.i = data_1.si[i__2] * z__3.i;
	i__4 = istep;
	z__1.r = zlc[i__4] * z__2.r, z__1.i = zlc[i__4] * z__2.i;
	zt.r = z__1.r, zt.i = z__1.i;
	if ((d__1 = zli[istep], abs(d__1)) > 1e-20) {
	    i__1 = istep;
	    z__3.r = zli[i__1] * tpcj->r, z__3.i = zli[i__1] * tpcj->i;
	    z_div(&z__2, &c_b245, &z__3);
	    z__1.r = zt.r + z__2.r, z__1.i = zt.i + z__2.i;
	    zt.r = z__1.r, zt.i = z__1.i;
	}
	if ((d__1 = zlr[istep], abs(d__1)) > 1e-20) {
	    d__2 = 1.f / (zlr[istep] * data_1.wlam);
	    z__1.r = zt.r + d__2, z__1.i = zt.i;
	    zt.r = z__1.r, zt.i = z__1.i;
	}
	z_div(&z__1, &c_b245, &zt);
	zt.r = z__1.r, zt.i = z__1.i;
	goto L16;
L14:
	i__1 = istep;
	i__2 = istep;
	z__2.r = zlr[i__1], z__2.i = zli[i__2];
	i__4 = i__ - 1;
	z__1.r = z__2.r / data_1.si[i__4], z__1.i = z__2.i / data_1.si[i__4];
	zt.r = z__1.r, zt.i = z__1.i;
	goto L16;
L15:
	d__1 = zlr[istep] * data_1.wlam;
	zint_(&z__1, &d__1, &data_1.bi[i__ - 1]);
	zt.r = z__1.r, zt.i = z__1.i;
L16:
	i__1 = i__ - 1;
	if ((d__1 = zload_1.zarray[i__1].r, abs(d__1)) + (d__2 = d_imag(&
		zload_1.zarray[i__ - 1]), abs(d__2)) > 1e-20) {
	    iwarn = 1;
	}
	i__1 = i__ - 1;
	i__2 = i__ - 1;
	z__1.r = zload_1.zarray[i__2].r + zt.r, z__1.i = zload_1.zarray[i__2]
		.i + zt.i;
	zload_1.zarray[i__1].r = z__1.r, zload_1.zarray[i__1].i = z__1.i;
L17:
	;
    }
    if (ichk != 0) {
	goto L18;
    }
    s_wsfe(&io___1645);
    do_fio(&c__1, (char *)&ldtags, (ftnlen)sizeof(integer));
    e_wsfe();
    s_stop("", (ftnlen)0);

/*     PRINTING THE SEGMENT LOADING DATA, JUMP TO PROPER PRINT */

L18:
    switch (jump) {
	case 1:  goto L19;
	case 2:  goto L20;
	case 3:  goto L21;
	case 4:  goto L22;
	case 5:  goto L23;
	case 6:  goto L24;
    }
L19:
    prnt_(&ldtags, &ldtagf[istep], &ldtagt[istep], &zlr[istep], &zli[istep], &
	    zlc[istep], &c_b636, &c_b636, &c_b636, " SERIES ", (ftnlen)8);
    goto L2;
L20:
    prnt_(&ldtags, &ldtagf[istep], &ldtagt[istep], &zlr[istep], &zli[istep], &
	    zlc[istep], &c_b636, &c_b636, &c_b636, "PARALLEL", (ftnlen)8);
    goto L2;
L21:
    prnt_(&ldtags, &ldtagf[istep], &ldtagt[istep], &zlr[istep], &zli[istep], &
	    zlc[istep], &c_b636, &c_b636, &c_b636, " SERIES (PER METER) ", (
	    ftnlen)20);
    goto L2;
L22:
    prnt_(&ldtags, &ldtagf[istep], &ldtagt[istep], &zlr[istep], &zli[istep], &
	    zlc[istep], &c_b636, &c_b636, &c_b636, "PARALLEL (PER METER)", (
	    ftnlen)20);
    goto L2;
L23:
    prnt_(&ldtags, &ldtagf[istep], &ldtagt[istep], &c_b636, &c_b636, &c_b636, 
	    &zlr[istep], &zli[istep], &c_b636, "FIXED IMPEDANCE ", (ftnlen)16)
	    ;
    goto L2;
L24:
    prnt_(&ldtags, &ldtagf[istep], &ldtagt[istep], &c_b636, &c_b636, &c_b636, 
	    &c_b636, &c_b636, &zlr[istep], "  WIRE  ", (ftnlen)8);
    goto L2;

} /* load_ */

#undef tpcjx
#undef tpcj


/* Subroutine */ int ltsolv_(doublecomplex *a, integer *nrow, integer *ix, 
	doublecomplex *b, integer *neq, integer *nrh, integer *ifl1, integer *
	ifl2)
{
    /* System generated locals */
    integer a_dim1, a_offset, b_dim1, b_offset, i__1, i__2, i__3, i__4, i__5, 
	    i__6;
    doublecomplex z__1, z__2;

    /* Builtin functions */
    void z_div(doublecomplex *, doublecomplex *, doublecomplex *);

    /* Local variables */
    integer i__, j, k, i2, k2, ic, kp, jm1, jp1, ixi, jst;
    doublecomplex sum;
    integer ixblk1;
    extern /* Subroutine */ int blckin_(doublecomplex *, integer *, integer *,
	     integer *, integer *, integer *);

/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* Max number of segments 	(Windows-95 <= 4 */
/* max nr of 'in-core' alloc.	(MAXMAT <= MA */
/* Max number of LD cards */
/* Max number of EX cards */
/* Max number of segs connected to NT/TL */
/* *** */

/*     LTSOLV SOLVES THE MATRIX EQ. Y(R)*LU(T)=B(R) WHERE (R) DENOTES ROW */
/*     VECTOR AND LU(T) DENOTES THE LU DECOMPOSITION OF THE TRANSPOSE OF */
/*     THE ORIGINAL COEFFICIENT MATRIX.  THE LU(T) DECOMPOSITION IS */
/*     STORED ON TAPE 5 IN BLOCKS IN ASCENDING ORDER AND ON FILE 3 IN */
/*     BLOCKS OF DESCENDING ORDER. */


/*     FORWARD SUBSTITUTION */

    /* Parameter adjustments */
    a_dim1 = *nrow;
    a_offset = 1 + a_dim1;
    a -= a_offset;
    --ix;
    b_dim1 = *neq;
    b_offset = 1 + b_dim1;
    b -= b_offset;

    /* Function Body */
    i2 = (matpar_1.npsym << 1) * *nrow;
    i__1 = matpar_1.nblsym;
    for (ixblk1 = 1; ixblk1 <= i__1; ++ixblk1) {
	blckin_(&a[a_offset], ifl1, &c__1, &i2, &c__1, &c__121);
	k2 = matpar_1.npsym;
	if (ixblk1 == matpar_1.nblsym) {
	    k2 = matpar_1.nlsym;
	}
	jst = (ixblk1 - 1) * matpar_1.npsym;
	i__2 = *nrh;
	for (ic = 1; ic <= i__2; ++ic) {
	    j = jst;
	    i__3 = k2;
	    for (k = 1; k <= i__3; ++k) {
		jm1 = j;
		++j;
		sum.r = 0.f, sum.i = 0.f;
		if (jm1 < 1) {
		    goto L2;
		}
		i__4 = jm1;
		for (i__ = 1; i__ <= i__4; ++i__) {
/* L1: */
		    i__5 = i__ + k * a_dim1;
		    i__6 = i__ + ic * b_dim1;
		    z__2.r = a[i__5].r * b[i__6].r - a[i__5].i * b[i__6].i, 
			    z__2.i = a[i__5].r * b[i__6].i + a[i__5].i * b[
			    i__6].r;
		    z__1.r = sum.r + z__2.r, z__1.i = sum.i + z__2.i;
		    sum.r = z__1.r, sum.i = z__1.i;
		}
L2:
		i__5 = j + ic * b_dim1;
		i__6 = j + ic * b_dim1;
		z__2.r = b[i__6].r - sum.r, z__2.i = b[i__6].i - sum.i;
		z_div(&z__1, &z__2, &a[j + k * a_dim1]);
		b[i__5].r = z__1.r, b[i__5].i = z__1.i;
/* L3: */
	    }
/* L4: */
	}
    }

/*     BACKWARD SUBSTITUTION */

    jst = *nrow + 1;
    i__2 = matpar_1.nblsym;
    for (ixblk1 = 1; ixblk1 <= i__2; ++ixblk1) {
	blckin_(&a[a_offset], ifl2, &c__1, &i2, &c__1, &c__122);
	k2 = matpar_1.npsym;
	if (ixblk1 == 1) {
	    k2 = matpar_1.nlsym;
	}
	i__1 = *nrh;
	for (ic = 1; ic <= i__1; ++ic) {
	    kp = k2 + 1;
	    j = jst;
	    i__3 = k2;
	    for (k = 1; k <= i__3; ++k) {
		--kp;
		jp1 = j;
		--j;
		sum.r = 0.f, sum.i = 0.f;
		if (*nrow < jp1) {
		    goto L6;
		}
		i__5 = *nrow;
		for (i__ = jp1; i__ <= i__5; ++i__) {
/* L5: */
		    i__6 = i__ + kp * a_dim1;
		    i__4 = i__ + ic * b_dim1;
		    z__2.r = a[i__6].r * b[i__4].r - a[i__6].i * b[i__4].i, 
			    z__2.i = a[i__6].r * b[i__4].i + a[i__6].i * b[
			    i__4].r;
		    z__1.r = sum.r + z__2.r, z__1.i = sum.i + z__2.i;
		    sum.r = z__1.r, sum.i = z__1.i;
		}
		i__6 = j + ic * b_dim1;
		i__4 = j + ic * b_dim1;
		z__1.r = b[i__4].r - sum.r, z__1.i = b[i__4].i - sum.i;
		b[i__6].r = z__1.r, b[i__6].i = z__1.i;
L6:
		;
	    }
/* L7: */
	}
/* L8: */
	jst -= k2;
    }

/*     UNSCRAMBLE SOLUTION */

    i__2 = *nrh;
    for (ic = 1; ic <= i__2; ++ic) {
	i__1 = *nrow;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    ixi = ix[i__];
/* L9: */
	    i__3 = ixi - 1;
	    i__6 = i__ + ic * b_dim1;
	    scratm_2.y[i__3].r = b[i__6].r, scratm_2.y[i__3].i = b[i__6].i;
	}
	i__3 = *nrow;
	for (i__ = 1; i__ <= i__3; ++i__) {
/* L10: */
	    i__6 = i__ + ic * b_dim1;
	    i__1 = i__ - 1;
	    b[i__6].r = scratm_2.y[i__1].r, b[i__6].i = scratm_2.y[i__1].i;
	}
    }
    return 0;
} /* ltsolv_ */

/* Subroutine */ int lunscr_(doublecomplex *a, integer *nrow, integer *nop, 
	integer *ix, integer *ip, integer *iu2, integer *iu3, integer *iu4)
{
    /* System generated locals */
    integer a_dim1, a_offset, i__1, i__2, i__3, i__4, i__5, i__6;
    alist al__1, al__2;

    /* Builtin functions */
    integer f_rew(alist *), f_back(alist *);

    /* Local variables */
    integer i__, j, k, i1, i2, k1, j2, ka, kk, nb1, nm1, ipi, ipk, ixt;
    doublecomplex temp;
    integer ixblk1;
    extern /* Subroutine */ int blckin_(doublecomplex *, integer *, integer *,
	     integer *, integer *, integer *), blckot_(doublecomplex *, 
	    integer *, integer *, integer *, integer *, integer *);

/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* *** */

/*     S/R WHICH UNSCRAMBLES, SCRAMBLED FACTORED MATRIX */

    /* Parameter adjustments */
    --ip;
    --ix;
    a_dim1 = *nrow;
    a_offset = 1 + a_dim1;
    a -= a_offset;

    /* Function Body */
    i1 = 1;
    i2 = (matpar_1.npsym << 1) * *nrow;
    nm1 = *nrow - 1;
    al__1.aerr = 0;
    al__1.aunit = *iu2;
    f_rew(&al__1);
    al__1.aerr = 0;
    al__1.aunit = *iu3;
    f_rew(&al__1);
    al__1.aerr = 0;
    al__1.aunit = *iu4;
    f_rew(&al__1);
    i__1 = *nop;
    for (kk = 1; kk <= i__1; ++kk) {
	ka = (kk - 1) * *nrow;
	i__2 = matpar_1.nblsym;
	for (ixblk1 = 1; ixblk1 <= i__2; ++ixblk1) {
	    blckin_(&a[a_offset], iu2, &i1, &i2, &c__1, &c__121);
	    k1 = (ixblk1 - 1) * matpar_1.npsym + 2;
	    if (nm1 < k1) {
		goto L3;
	    }
	    j2 = 0;
	    i__3 = nm1;
	    for (k = k1; k <= i__3; ++k) {
		if (j2 < matpar_1.npsym) {
		    ++j2;
		}
		ipk = ip[k + ka];
		i__4 = j2;
		for (j = 1; j <= i__4; ++j) {
		    i__5 = k + j * a_dim1;
		    temp.r = a[i__5].r, temp.i = a[i__5].i;
		    i__5 = k + j * a_dim1;
		    i__6 = ipk + j * a_dim1;
		    a[i__5].r = a[i__6].r, a[i__5].i = a[i__6].i;
		    i__5 = ipk + j * a_dim1;
		    a[i__5].r = temp.r, a[i__5].i = temp.i;
/* L1: */
		}
/* L2: */
	    }
L3:
	    blckot_(&a[a_offset], iu3, &i1, &i2, &c__1, &c__122);
/* L4: */
	}
	i__2 = matpar_1.nblsym;
	for (ixblk1 = 1; ixblk1 <= i__2; ++ixblk1) {
	    al__2.aerr = 0;
	    al__2.aunit = *iu3;
	    f_back(&al__2);
	    if (ixblk1 != 1) {
		al__2.aerr = 0;
		al__2.aunit = *iu3;
		f_back(&al__2);
	    }
	    blckin_(&a[a_offset], iu3, &i1, &i2, &c__1, &c__123);
	    blckot_(&a[a_offset], iu4, &i1, &i2, &c__1, &c__124);
/* L5: */
	}
	i__2 = *nrow;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    ix[i__ + ka] = i__;
/* L6: */
	}
	i__2 = *nrow;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    ipi = ip[i__ + ka];
	    ixt = ix[i__ + ka];
	    ix[i__ + ka] = ix[ipi + ka];
	    ix[ipi + ka] = ixt;
/* L7: */
	}
	if (*nop == 1) {
	    goto L9;
	}
	nb1 = matpar_1.nblsym - 1;
/*     SKIP NB1 LOGICAL RECORDS FORWARD */
	i__2 = nb1;
	for (ixblk1 = 1; ixblk1 <= i__2; ++ixblk1) {
	    blckin_(&a[a_offset], iu3, &i1, &i2, &c__1, &c__125);
/* L8: */
	}
L9:
	;
    }
    al__1.aerr = 0;
    al__1.aunit = *iu2;
    f_rew(&al__1);
    al__1.aerr = 0;
    al__1.aunit = *iu3;
    f_rew(&al__1);
    al__1.aerr = 0;
    al__1.aunit = *iu4;
    f_rew(&al__1);
    return 0;
} /* lunscr_ */

/* Subroutine */ int move_(doublereal *rox, doublereal *roy, doublereal *roz, 
	doublereal *xs, doublereal *ys, doublereal *zs, integer *its, integer 
	*nrpt, integer *itgi)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    double sin(doublereal), cos(doublereal);

    /* Local variables */
    integer i__, k, i1;
#define x2 ((doublereal *)&data_1 + 4500)
#define y2 ((doublereal *)&data_1 + 7500)
#define z2 ((doublereal *)&data_1 + 9000)
    integer ii, ir, kr, ix;
    doublereal xi, yi, zi, xx, xy, xz, yx, yy, yz, zx, zy, zz;
#define t1x ((doublereal *)&data_1 + 4500)
#define t1y ((doublereal *)&data_1 + 7500)
#define t1z ((doublereal *)&data_1 + 9000)
#define t2x ((doublereal *)&data_1 + 10501)
#define t2y ((doublereal *)&data_1 + 12001)
#define t2z ((doublereal *)&data_1 + 13501)
    integer ldi;
    doublereal cph, cth, cps, sph, sth;
    integer nrp;
    doublereal sps;
    extern integer isegno_(integer *, integer *);

/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* Max number of segments 	(Windows-95 <= 4 */
/* max nr of 'in-core' alloc.	(MAXMAT <= MA */
/* Max number of LD cards */
/* Max number of EX cards */
/* Max number of segs connected to NT/TL */
/* *** */

/*     SUBROUTINE MOVE MOVES THE STRUCTURE WITH RESPECT TO ITS */
/*     COORDINATE SYSTEM OR REPRODUCES STRUCTURE IN NEW POSITIONS. */
/*     STRUCTURE IS ROTATED ABOUT X,Y,Z AXES BY ROX,ROY,ROZ */
/*     RESPECTIVELY, THEN SHIFTED BY XS,YS,ZS */

    if (abs(*rox) + abs(*roy) > 1e-10) {
	data_1.ipsym *= 3;
    }
    sps = sin(*rox);
    cps = cos(*rox);
    sth = sin(*roy);
    cth = cos(*roy);
    sph = sin(*roz);
    cph = cos(*roz);
    xx = cph * cth;
    xy = cph * sth * sps - sph * cps;
    xz = cph * sth * cps + sph * sps;
    yx = sph * cth;
    yy = sph * sth * sps + cph * cps;
    yz = sph * sth * cps - cph * sps;
    zx = -sth;
    zy = cth * sps;
    zz = cth * cps;
    nrp = *nrpt;
    if (*nrpt == 0) {
	nrp = 1;
    }
    ix = 1;
    if (data_1.n < data_1.n2) {
	goto L3;
    }
    i1 = isegno_(its, &c__1);
    if (i1 < data_1.n2) {
	i1 = data_1.n2;
    }
    ix = i1;
    k = data_1.n;
    if (*nrpt == 0) {
	k = i1 - 1;
    }
    i__1 = nrp;
    for (ir = 1; ir <= i__1; ++ir) {
	i__2 = data_1.n;
	for (i__ = i1; i__ <= i__2; ++i__) {
	    ++k;
	    xi = data_1.x[i__ - 1];
	    yi = data_1.y[i__ - 1];
	    zi = data_1.z__[i__ - 1];
	    data_1.x[k - 1] = xi * xx + yi * xy + zi * xz + *xs;
	    data_1.y[k - 1] = xi * yx + yi * yy + zi * yz + *ys;
	    data_1.z__[k - 1] = xi * zx + yi * zy + zi * zz + *zs;
	    xi = x2[i__ - 1];
	    yi = y2[i__ - 1];
	    zi = z2[i__ - 1];
	    x2[k - 1] = xi * xx + yi * xy + zi * xz + *xs;
	    y2[k - 1] = xi * yx + yi * yy + zi * yz + *ys;
	    z2[k - 1] = xi * zx + yi * zy + zi * zz + *zs;
	    data_1.bi[k - 1] = data_1.bi[i__ - 1];
	    data_1.itag[k - 1] = data_1.itag[i__ - 1];
	    if (data_1.itag[i__ - 1] != 0) {
		data_1.itag[k - 1] = data_1.itag[i__ - 1] + *itgi;
	    }
/* L1: */
	}
	i1 = data_1.n + 1;
	data_1.n = k;
/* L2: */
    }
L3:
    if (data_1.m < data_1.m2) {
	goto L6;
    }
    i1 = data_1.m2;
    k = data_1.m;
    ldi = data_1.ld + 1;
    if (*nrpt == 0) {
	k = data_1.m1;
    }
    i__1 = nrp;
    for (ii = 1; ii <= i__1; ++ii) {
	i__2 = data_1.m;
	for (i__ = i1; i__ <= i__2; ++i__) {
	    ++k;
	    ir = ldi - i__;
	    kr = ldi - k;
	    xi = data_1.x[ir - 1];
	    yi = data_1.y[ir - 1];
	    zi = data_1.z__[ir - 1];
	    data_1.x[kr - 1] = xi * xx + yi * xy + zi * xz + *xs;
	    data_1.y[kr - 1] = xi * yx + yi * yy + zi * yz + *ys;
	    data_1.z__[kr - 1] = xi * zx + yi * zy + zi * zz + *zs;
	    xi = t1x[ir - 1];
	    yi = t1y[ir - 1];
	    zi = t1z[ir - 1];
	    t1x[kr - 1] = xi * xx + yi * xy + zi * xz;
	    t1y[kr - 1] = xi * yx + yi * yy + zi * yz;
	    t1z[kr - 1] = xi * zx + yi * zy + zi * zz;
	    xi = t2x[ir - 1];
	    yi = t2y[ir - 1];
	    zi = t2z[ir - 1];
	    t2x[kr - 1] = xi * xx + yi * xy + zi * xz;
	    t2y[kr - 1] = xi * yx + yi * yy + zi * yz;
	    t2z[kr - 1] = xi * zx + yi * zy + zi * zz;
	    angl_1.salp[kr - 1] = angl_1.salp[ir - 1];
/* L4: */
	    data_1.bi[kr - 1] = data_1.bi[ir - 1];
	}
	i1 = data_1.m + 1;
/* L5: */
	data_1.m = k;
    }
L6:
    if (*nrpt == 0 && ix == 1) {
	return 0;
    }
    data_1.np = data_1.n;
    data_1.mp = data_1.m;
    data_1.ipsym = 0;
    return 0;
} /* move_ */

#undef t2z
#undef t2y
#undef t2x
#undef t1z
#undef t1y
#undef t1x
#undef z2
#undef y2
#undef x2


/* Subroutine */ int nefld_(doublereal *xob, doublereal *yob, doublereal *zob,
	 doublecomplex *ex, doublecomplex *ey, doublecomplex *ez)
{
    /* System generated locals */
    integer i__1, i__2, i__3, i__4;
    doublereal d__1;
    doublecomplex z__1, z__2, z__3, z__4, z__5, z__6;

    /* Local variables */
    integer i__, jc, jl;
    doublereal ax;
    integer ip;
    doublereal xi, zp;
#define t1x ((doublereal *)&data_1 + 4500)
#define t1y ((doublereal *)&data_1 + 7500)
#define t1z ((doublereal *)&data_1 + 9000)
#define t2x ((doublereal *)&data_1 + 10501)
#define t2y ((doublereal *)&data_1 + 12001)
#define t2z ((doublereal *)&data_1 + 13501)
#define cab ((doublereal *)&data_1 + 7500)
#define sab ((doublereal *)&data_1 + 9000)
    doublecomplex acx, bcx, ccx;
    integer ipr;
#define t1xj ((doublereal *)&dataj_1 + 5)
#define t1yj ((doublereal *)&dataj_1 + 6)
#define t1zj ((doublereal *)&dataj_1 + 7)
#define t2xj ((doublereal *)&dataj_1 + 1)
#define t2yj ((doublereal *)&dataj_1 + 27)
#define t2zj ((doublereal *)&dataj_1 + 28)
    extern /* Subroutine */ int efld_(doublereal *, doublereal *, doublereal *
	    , doublereal *, integer *), unere_(doublereal *, doublereal *, 
	    doublereal *);

/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* Max number of segments 	(Windows-95 <= 4 */
/* max nr of 'in-core' alloc.	(MAXMAT <= MA */
/* Max number of LD cards */
/* Max number of EX cards */
/* Max number of segs connected to NT/TL */
/* *** */

/*     NEFLD COMPUTES THE NEAR FIELD AT SPECIFIED POINTS IN SPACE AFTER */
/*     THE STRUCTURE CURRENTS HAVE BEEN COMPUTED. */

    ex->r = 0.f, ex->i = 0.f;
    ey->r = 0.f, ey->i = 0.f;
    ez->r = 0.f, ez->i = 0.f;
    ax = 0.f;
    if (data_1.n == 0) {
	goto L20;
    }
    i__1 = data_1.n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	dataj_1.xj = *xob - data_1.x[i__ - 1];
	dataj_1.yj = *yob - data_1.y[i__ - 1];
	dataj_1.zj = *zob - data_1.z__[i__ - 1];
	zp = cab[i__ - 1] * dataj_1.xj + sab[i__ - 1] * dataj_1.yj + 
		angl_1.salp[i__ - 1] * dataj_1.zj;
	if (abs(zp) > data_1.si[i__ - 1] * .5001f) {
	    goto L1;
	}
	zp = dataj_1.xj * dataj_1.xj + dataj_1.yj * dataj_1.yj + dataj_1.zj * 
		dataj_1.zj - zp * zp;
	dataj_1.xj = data_1.bi[i__ - 1];
	if (zp > dataj_1.xj * .9f * dataj_1.xj) {
	    goto L1;
	}
	ax = dataj_1.xj;
	goto L2;
L1:
	;
    }
L2:
    i__1 = data_1.n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	dataj_1.s = data_1.si[i__ - 1];
	dataj_1.b = data_1.bi[i__ - 1];
	dataj_1.xj = data_1.x[i__ - 1];
	dataj_1.yj = data_1.y[i__ - 1];
	dataj_1.zj = data_1.z__[i__ - 1];
	dataj_1.cabj = cab[i__ - 1];
	dataj_1.sabj = sab[i__ - 1];
	dataj_1.salpj = angl_1.salp[i__ - 1];
	if (dataj_1.iexk == 0) {
	    goto L18;
	}
	ipr = data_1.icon1[i__ - 1];
	if (ipr < 0) {
	    goto L3;
	} else if (ipr == 0) {
	    goto L8;
	} else {
	    goto L4;
	}
L3:
	ipr = -ipr;
	if (-data_1.icon1[ipr - 1] != i__) {
	    goto L9;
	}
	goto L6;
L4:
	if (ipr != i__) {
	    goto L5;
	}
	if (dataj_1.cabj * dataj_1.cabj + dataj_1.sabj * dataj_1.sabj > 1e-8) 
		{
	    goto L9;
	}
	goto L7;
L5:
	if (data_1.icon2[ipr - 1] != i__) {
	    goto L9;
	}
L6:
	xi = (d__1 = dataj_1.cabj * cab[ipr - 1] + dataj_1.sabj * sab[ipr - 1]
		 + dataj_1.salpj * angl_1.salp[ipr - 1], abs(d__1));
	if (xi < .999999) {
	    goto L9;
	}
	if ((d__1 = data_1.bi[ipr - 1] / dataj_1.b - 1.f, abs(d__1)) > 1e-6) {
	    goto L9;
	}
L7:
	dataj_1.ind1 = 0;
	goto L10;
L8:
	dataj_1.ind1 = 1;
	goto L10;
L9:
	dataj_1.ind1 = 2;
L10:
	ipr = data_1.icon2[i__ - 1];
	if (ipr < 0) {
	    goto L11;
	} else if (ipr == 0) {
	    goto L16;
	} else {
	    goto L12;
	}
L11:
	ipr = -ipr;
	if (-data_1.icon2[ipr - 1] != i__) {
	    goto L17;
	}
	goto L14;
L12:
	if (ipr != i__) {
	    goto L13;
	}
	if (dataj_1.cabj * dataj_1.cabj + dataj_1.sabj * dataj_1.sabj > 1e-8) 
		{
	    goto L17;
	}
	goto L15;
L13:
	if (data_1.icon1[ipr - 1] != i__) {
	    goto L17;
	}
L14:
	xi = (d__1 = dataj_1.cabj * cab[ipr - 1] + dataj_1.sabj * sab[ipr - 1]
		 + dataj_1.salpj * angl_1.salp[ipr - 1], abs(d__1));
	if (xi < .999999) {
	    goto L17;
	}
	if ((d__1 = data_1.bi[ipr - 1] / dataj_1.b - 1.f, abs(d__1)) > 1e-6) {
	    goto L17;
	}
L15:
	dataj_1.ind2 = 0;
	goto L18;
L16:
	dataj_1.ind2 = 1;
	goto L18;
L17:
	dataj_1.ind2 = 2;
L18:
	efld_(xob, yob, zob, &ax, &c__1);
	i__2 = i__ - 1;
	i__3 = i__ - 1;
	z__1.r = crnt_1.air[i__2], z__1.i = crnt_1.aii[i__3];
	acx.r = z__1.r, acx.i = z__1.i;
	i__2 = i__ - 1;
	i__3 = i__ - 1;
	z__1.r = crnt_1.bir[i__2], z__1.i = crnt_1.bii[i__3];
	bcx.r = z__1.r, bcx.i = z__1.i;
	i__2 = i__ - 1;
	i__3 = i__ - 1;
	z__1.r = crnt_1.cir[i__2], z__1.i = crnt_1.cii[i__3];
	ccx.r = z__1.r, ccx.i = z__1.i;
	z__4.r = dataj_1.exk.r * acx.r - dataj_1.exk.i * acx.i, z__4.i = 
		dataj_1.exk.r * acx.i + dataj_1.exk.i * acx.r;
	z__3.r = ex->r + z__4.r, z__3.i = ex->i + z__4.i;
	z__5.r = dataj_1.exs.r * bcx.r - dataj_1.exs.i * bcx.i, z__5.i = 
		dataj_1.exs.r * bcx.i + dataj_1.exs.i * bcx.r;
	z__2.r = z__3.r + z__5.r, z__2.i = z__3.i + z__5.i;
	z__6.r = dataj_1.exc.r * ccx.r - dataj_1.exc.i * ccx.i, z__6.i = 
		dataj_1.exc.r * ccx.i + dataj_1.exc.i * ccx.r;
	z__1.r = z__2.r + z__6.r, z__1.i = z__2.i + z__6.i;
	ex->r = z__1.r, ex->i = z__1.i;
	z__4.r = dataj_1.eyk.r * acx.r - dataj_1.eyk.i * acx.i, z__4.i = 
		dataj_1.eyk.r * acx.i + dataj_1.eyk.i * acx.r;
	z__3.r = ey->r + z__4.r, z__3.i = ey->i + z__4.i;
	z__5.r = dataj_1.eys.r * bcx.r - dataj_1.eys.i * bcx.i, z__5.i = 
		dataj_1.eys.r * bcx.i + dataj_1.eys.i * bcx.r;
	z__2.r = z__3.r + z__5.r, z__2.i = z__3.i + z__5.i;
	z__6.r = dataj_1.eyc.r * ccx.r - dataj_1.eyc.i * ccx.i, z__6.i = 
		dataj_1.eyc.r * ccx.i + dataj_1.eyc.i * ccx.r;
	z__1.r = z__2.r + z__6.r, z__1.i = z__2.i + z__6.i;
	ey->r = z__1.r, ey->i = z__1.i;
/* L19: */
	z__4.r = dataj_1.ezk.r * acx.r - dataj_1.ezk.i * acx.i, z__4.i = 
		dataj_1.ezk.r * acx.i + dataj_1.ezk.i * acx.r;
	z__3.r = ez->r + z__4.r, z__3.i = ez->i + z__4.i;
	z__5.r = dataj_1.ezs.r * bcx.r - dataj_1.ezs.i * bcx.i, z__5.i = 
		dataj_1.ezs.r * bcx.i + dataj_1.ezs.i * bcx.r;
	z__2.r = z__3.r + z__5.r, z__2.i = z__3.i + z__5.i;
	z__6.r = dataj_1.ezc.r * ccx.r - dataj_1.ezc.i * ccx.i, z__6.i = 
		dataj_1.ezc.r * ccx.i + dataj_1.ezc.i * ccx.r;
	z__1.r = z__2.r + z__6.r, z__1.i = z__2.i + z__6.i;
	ez->r = z__1.r, ez->i = z__1.i;
    }
    if (data_1.m == 0) {
	return 0;
    }
L20:
    jc = data_1.n;
    jl = data_1.ld + 1;
    i__1 = data_1.m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	--jl;
	dataj_1.s = data_1.bi[jl - 1];
	dataj_1.xj = data_1.x[jl - 1];
	dataj_1.yj = data_1.y[jl - 1];
	dataj_1.zj = data_1.z__[jl - 1];
	*t1xj = t1x[jl - 1];
	*t1yj = t1y[jl - 1];
	*t1zj = t1z[jl - 1];
	*t2xj = t2x[jl - 1];
	*t2yj = t2y[jl - 1];
	*t2zj = t2z[jl - 1];
	jc += 3;
	i__2 = jc - 3;
	z__3.r = *t1xj * crnt_1.cur[i__2].r, z__3.i = *t1xj * crnt_1.cur[i__2]
		.i;
	i__3 = jc - 2;
	z__4.r = *t1yj * crnt_1.cur[i__3].r, z__4.i = *t1yj * crnt_1.cur[i__3]
		.i;
	z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
	i__4 = jc - 1;
	z__5.r = *t1zj * crnt_1.cur[i__4].r, z__5.i = *t1zj * crnt_1.cur[i__4]
		.i;
	z__1.r = z__2.r + z__5.r, z__1.i = z__2.i + z__5.i;
	acx.r = z__1.r, acx.i = z__1.i;
	i__2 = jc - 3;
	z__3.r = *t2xj * crnt_1.cur[i__2].r, z__3.i = *t2xj * crnt_1.cur[i__2]
		.i;
	i__3 = jc - 2;
	z__4.r = *t2yj * crnt_1.cur[i__3].r, z__4.i = *t2yj * crnt_1.cur[i__3]
		.i;
	z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
	i__4 = jc - 1;
	z__5.r = *t2zj * crnt_1.cur[i__4].r, z__5.i = *t2zj * crnt_1.cur[i__4]
		.i;
	z__1.r = z__2.r + z__5.r, z__1.i = z__2.i + z__5.i;
	bcx.r = z__1.r, bcx.i = z__1.i;
	i__2 = gnd_1.ksymp;
	for (ip = 1; ip <= i__2; ++ip) {
	    dataj_1.ipgnd = ip;
	    unere_(xob, yob, zob);
	    z__3.r = acx.r * dataj_1.exk.r - acx.i * dataj_1.exk.i, z__3.i = 
		    acx.r * dataj_1.exk.i + acx.i * dataj_1.exk.r;
	    z__2.r = ex->r + z__3.r, z__2.i = ex->i + z__3.i;
	    z__4.r = bcx.r * dataj_1.exs.r - bcx.i * dataj_1.exs.i, z__4.i = 
		    bcx.r * dataj_1.exs.i + bcx.i * dataj_1.exs.r;
	    z__1.r = z__2.r + z__4.r, z__1.i = z__2.i + z__4.i;
	    ex->r = z__1.r, ex->i = z__1.i;
	    z__3.r = acx.r * dataj_1.eyk.r - acx.i * dataj_1.eyk.i, z__3.i = 
		    acx.r * dataj_1.eyk.i + acx.i * dataj_1.eyk.r;
	    z__2.r = ey->r + z__3.r, z__2.i = ey->i + z__3.i;
	    z__4.r = bcx.r * dataj_1.eys.r - bcx.i * dataj_1.eys.i, z__4.i = 
		    bcx.r * dataj_1.eys.i + bcx.i * dataj_1.eys.r;
	    z__1.r = z__2.r + z__4.r, z__1.i = z__2.i + z__4.i;
	    ey->r = z__1.r, ey->i = z__1.i;
/* L21: */
	    z__3.r = acx.r * dataj_1.ezk.r - acx.i * dataj_1.ezk.i, z__3.i = 
		    acx.r * dataj_1.ezk.i + acx.i * dataj_1.ezk.r;
	    z__2.r = ez->r + z__3.r, z__2.i = ez->i + z__3.i;
	    z__4.r = bcx.r * dataj_1.ezs.r - bcx.i * dataj_1.ezs.i, z__4.i = 
		    bcx.r * dataj_1.ezs.i + bcx.i * dataj_1.ezs.r;
	    z__1.r = z__2.r + z__4.r, z__1.i = z__2.i + z__4.i;
	    ez->r = z__1.r, ez->i = z__1.i;
	}
    }
    return 0;
} /* nefld_ */

#undef t2zj
#undef t2yj
#undef t2xj
#undef t1zj
#undef t1yj
#undef t1xj
#undef sab
#undef cab
#undef t2z
#undef t2y
#undef t2x
#undef t1z
#undef t1y
#undef t1x


/* Subroutine */ int netwk_(doublecomplex *cm, doublecomplex *cmb, 
	doublecomplex *cmc, doublecomplex *cmd, integer *ip, doublecomplex *
	einc)
{
    /* Initialized data */

    static integer ndimn = 30;
    static integer ndimnp = 31;
    static doublereal tp = 6.283185308;

    /* Format strings */
    static char fmt_59[] = "(1x,\002ERROR - - NETWORK ARRAY DIMENSIONS TOO S"
	    "MALL\002)";
    static char fmt_58[] = "(///,3x,\002MAXIMUM RELATIVE ASYMMETRY OF THE DR"
	    "IVING POINT\002,\002 ADMITTANCE MATRIX IS\002,1p,e10.3,\002 FOR "
	    "SEGMENTS\002,i5,\002 AND\002,i5,/,3x,\002RMS RELATIVE ASYMMETRY "
	    "IS\002,e10.3)";
    static char fmt_61[] = "(///,27x,\002- - - STRUCTURE EXCITATION DATA AT "
	    "NETWORK CONNECTION POINTS - - -\002)";
    static char fmt_60[] = "(/,3x,\002TAG\002,3x,\002SEG.\002,4x,\002VOLTAGE"
	    " (VOLTS)\002,9x,\002CURRENT (AMPS)\002,9x,\002IMPEDANCE (OHMS"
	    ")\002,8x,\002ADMITTANCE (MHOS)\002,6x,\002POWER\002,/,3x,\002NO"
	    ".\002,3x,\002NO.\002,4x,\002REAL\002,8x,\002IMAG.\002,3(7x,\002R"
	    "EAL\002,8x,\002IMAG.\002),5x,\002(WATTS)\002)";
    static char fmt_62[] = "(2(1x,i5),1p,9e12.5)";
    static char fmt_63[] = "(///,42x,\002- - - ANTENNA INPUT PARAMETERS - "
	    "- -\002)";
    static char fmt_64[] = "(1x,i5,\002 *\002,i4,1p,9e12.5)";

    /* System generated locals */
    integer i__1, i__2, i__3, i__4, i__5;
    doublereal d__1, d__2;
    doublecomplex z__1, z__2, z__3, z__4, z__5;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);
    void z_div(doublecomplex *, doublecomplex *, doublecomplex *);
    double z_abs(doublecomplex *), sqrt(doublereal);
    integer do_fio(integer *, char *, ftnlen);
    double sin(doublereal), cos(doublereal);
    void d_cnjg(doublecomplex *, doublecomplex *);

    /* Local variables */
    integer i__, j;
    doublereal asa;
    doublecomplex cmn[900]	/* was [30][30] */;
    doublereal asm__, y11i, y12i;
    doublecomplex rhs[4500], cux;
    integer nop;
    doublereal y11r, y12r, y22r, y22i;
    doublecomplex vlt;
    doublereal pwr;
    integer isc1, isc2;
    extern /* Subroutine */ int cabc_(doublecomplex *);
    integer neqt, nteq, ipnt[30];
    doublecomplex rhnt[30], vsrc[30], rhnx[30];
    integer ntsc;
    doublecomplex ymit;
    integer nseg1, nseg2, neqz2, irow1, irow2;
    extern /* Subroutine */ int factr_(integer *, doublecomplex *, integer *, 
	    integer *);
    integer nteqa[30], ntsca[30];
    extern /* Subroutine */ int solgf_(doublecomplex *, doublecomplex *, 
	    doublecomplex *, doublecomplex *, doublecomplex *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *), solve_(integer *, doublecomplex 
	    *, integer *, doublecomplex *, integer *);

    /* Fortran I/O blocks */
    static cilist io___1748 = { 0, 3, 0, fmt_59, 0 };
    static cilist io___1757 = { 0, 3, 0, fmt_58, 0 };
    static cilist io___1771 = { 0, 3, 0, fmt_59, 0 };
    static cilist io___1773 = { 0, 3, 0, fmt_61, 0 };
    static cilist io___1774 = { 0, 3, 0, fmt_60, 0 };
    static cilist io___1777 = { 0, 3, 0, fmt_62, 0 };
    static cilist io___1778 = { 0, 3, 0, fmt_62, 0 };
    static cilist io___1779 = { 0, 3, 0, fmt_63, 0 };
    static cilist io___1780 = { 0, 3, 0, fmt_60, 0 };
    static cilist io___1781 = { 0, 3, 0, fmt_62, 0 };
    static cilist io___1782 = { 0, 3, 0, fmt_64, 0 };


/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* Max number of segments 	(Windows-95 <= 4 */
/* max nr of 'in-core' alloc.	(MAXMAT <= MA */
/* Max number of LD cards */
/* Max number of EX cards */
/* Max number of segs connected to NT/TL */
/* *** */

/*     SUBROUTINE NETWK SOLVES FOR STRUCTURE CURRENTS FOR A GIVEN */
/*     EXCITATION INCLUDING THE EFFECT OF NON-RADIATING NETWORKS IF */
/*     PRESENT. */

    /* Parameter adjustments */
    --einc;
    --ip;
    --cmd;
    --cmc;
    --cmb;
    --cm;

    /* Function Body */
/*     COMMON /VSORC/ VQD(nsmax),VSANT(nsmax),VQDS(nsmax),IVQD(nsmax), */
/*    &ISANT(nsmax),IQDS(nsmax),NVQD,NSANT,NQDS			! av07 */
/*     COMMON/NETCX/ZPED,PIN,PNLS,X11R(netmx),X11I(netmx),X12R(netmx), */
/*    &X12I(netmx),X22R(netmx),X22I(netmx),NTYP(netmx),ISEG1(netmx), */
/*    &ISEG2(netmx),NEQ,NPEQ,NEQ2,NONET,NTSOL,NPRINT,MASYM	! av06 */
/* av08	Keep VSRC dimension to 30 (for now) as it's use is uncertain. */
/*     DIMENSION CMN(netmx,netmx), RHNT(netmx), IPNT(netmx), */
/*    &NTEQA(netmx), NTSCA(netmx), RHS(3*MAXSEG), VSRC(30), RHNX(netmx) */
/*     DATA NDIMN,NDIMNP/netmx,netmx+1/,TP/6.283185308D+0/	! av06 */
    neqz2 = netcx_2.neq2;
    if (neqz2 == 0) {
	neqz2 = 1;
    }
    netcx_2.pin = 0.f;
    netcx_2.pnls = 0.f;
    neqt = netcx_2.neq + netcx_2.neq2;
    if (netcx_2.ntsol != 0) {
	goto L42;
    }
    nop = netcx_2.neq / netcx_2.npeq;
    if (netcx_2.masym == 0) {
	goto L14;
    }

/*     COMPUTE RELATIVE MATRIX ASYMMETRY */

    irow1 = 0;
    if (netcx_2.nonet == 0) {
	goto L5;
    }
    i__1 = netcx_2.nonet;
    for (i__ = 1; i__ <= i__1; ++i__) {
	nseg1 = netcx_2.iseg1[i__ - 1];
	for (isc1 = 1; isc1 <= 2; ++isc1) {
	    if (irow1 == 0) {
		goto L2;
	    }
	    i__2 = irow1;
	    for (j = 1; j <= i__2; ++j) {
		if (nseg1 == ipnt[j - 1]) {
		    goto L3;
		}
/* L1: */
	    }
L2:
	    ++irow1;
	    ipnt[irow1 - 1] = nseg1;
L3:
	    nseg1 = netcx_2.iseg2[i__ - 1];
	}
/* L4: */
    }
L5:
    if (vsorc_2.nsant == 0) {
	goto L9;
    }
    i__1 = vsorc_2.nsant;
    for (i__ = 1; i__ <= i__1; ++i__) {
	nseg1 = vsorc_2.isant[i__ - 1];
	if (irow1 == 0) {
	    goto L7;
	}
	i__2 = irow1;
	for (j = 1; j <= i__2; ++j) {
	    if (nseg1 == ipnt[j - 1]) {
		goto L8;
	    }
/* L6: */
	}
L7:
	++irow1;
	ipnt[irow1 - 1] = nseg1;
L8:
	;
    }
/* av09 */
/* 9	print *,'irow1=',irow1,'  ndimnp=',ndimnp */
L9:
    if (irow1 < ndimnp) {
	goto L10;
    }
    s_wsfe(&io___1748);
    e_wsfe();
    s_stop("", (ftnlen)0);
L10:
    if (irow1 < 2) {
	goto L14;
    }
    i__1 = irow1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	isc1 = ipnt[i__ - 1];
	asm__ = data_1.si[isc1 - 1];
	i__2 = neqt;
	for (j = 1; j <= i__2; ++j) {
/* L11: */
	    i__3 = j - 1;
	    rhs[i__3].r = 0.f, rhs[i__3].i = 0.f;
	}
	i__3 = isc1 - 1;
	rhs[i__3].r = 1.f, rhs[i__3].i = 0.f;
	solgf_(&cm[1], &cmb[1], &cmc[1], &cmd[1], rhs, &ip[1], &data_1.np, &
		data_1.n1, &data_1.n, &data_1.mp, &data_1.m1, &data_1.m, &
		netcx_2.neq, &netcx_2.neq2, &neqz2);
	cabc_(rhs);
	i__3 = irow1;
	for (j = 1; j <= i__3; ++j) {
	    isc1 = ipnt[j - 1];
/* L12: */
	    i__2 = j + i__ * 30 - 31;
	    i__4 = isc1 - 1;
	    z__1.r = rhs[i__4].r / asm__, z__1.i = rhs[i__4].i / asm__;
	    cmn[i__2].r = z__1.r, cmn[i__2].i = z__1.i;
	}
    }
    asm__ = 0.f;
    asa = 0.f;
    i__2 = irow1;
    for (i__ = 2; i__ <= i__2; ++i__) {
	isc1 = i__ - 1;
	i__4 = isc1;
	for (j = 1; j <= i__4; ++j) {
	    i__3 = i__ + j * 30 - 31;
	    cux.r = cmn[i__3].r, cux.i = cmn[i__3].i;
	    i__3 = j + i__ * 30 - 31;
	    z__2.r = cux.r - cmn[i__3].r, z__2.i = cux.i - cmn[i__3].i;
	    z_div(&z__1, &z__2, &cux);
	    pwr = z_abs(&z__1);
	    asa += pwr * pwr;
	    if (pwr < asm__) {
		goto L13;
	    }
	    asm__ = pwr;
	    nteq = ipnt[i__ - 1];
	    ntsc = ipnt[j - 1];
L13:
	    ;
	}
    }
    asa = sqrt(asa * 2.f / (doublereal) (irow1 * (irow1 - 1)));
    s_wsfe(&io___1757);
    do_fio(&c__1, (char *)&asm__, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&nteq, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&ntsc, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&asa, (ftnlen)sizeof(doublereal));
    e_wsfe();
L14:
    if (netcx_2.nonet == 0) {
	goto L48;
    }

/*     SOLUTION OF NETWORK EQUATIONS */

    i__4 = ndimn;
    for (i__ = 1; i__ <= i__4; ++i__) {
	i__2 = i__ - 1;
	rhnx[i__2].r = 0.f, rhnx[i__2].i = 0.f;
	i__2 = ndimn;
	for (j = 1; j <= i__2; ++j) {
/* L15: */
	    i__3 = i__ + j * 30 - 31;
	    cmn[i__3].r = 0.f, cmn[i__3].i = 0.f;
	}
    }
    nteq = 0;
    ntsc = 0;

/*     SORT NETWORK AND SOURCE DATA AND ASSIGN EQUATION NUMBERS TO */
/*     SEGMENTS. */

    i__3 = netcx_2.nonet;
    for (j = 1; j <= i__3; ++j) {
	nseg1 = netcx_2.iseg1[j - 1];
	nseg2 = netcx_2.iseg2[j - 1];
	if (netcx_2.ntyp[j - 1] > 1) {
	    goto L16;
	}
	y11r = netcx_2.x11r[j - 1];
	y11i = netcx_2.x11i[j - 1];
	y12r = netcx_2.x12r[j - 1];
	y12i = netcx_2.x12i[j - 1];
	y22r = netcx_2.x22r[j - 1];
	y22i = netcx_2.x22i[j - 1];
	goto L17;
L16:
	y22r = tp * netcx_2.x11i[j - 1] / data_1.wlam;
	y12r = 0.f;
	y12i = 1.f / (netcx_2.x11r[j - 1] * sin(y22r));
	y11r = netcx_2.x12r[j - 1];
	y11i = -y12i * cos(y22r);
	y22r = netcx_2.x22r[j - 1];
	y22i = y11i + netcx_2.x22i[j - 1];
	y11i += netcx_2.x12i[j - 1];
	if (netcx_2.ntyp[j - 1] == 2) {
	    goto L17;
	}
	y12r = -y12r;
	y12i = -y12i;
L17:
	if (vsorc_2.nsant == 0) {
	    goto L19;
	}
	i__2 = vsorc_2.nsant;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    if (nseg1 != vsorc_2.isant[i__ - 1]) {
		goto L18;
	    }
	    isc1 = i__;
	    goto L22;
L18:
	    ;
	}
L19:
	isc1 = 0;
	if (nteq == 0) {
	    goto L21;
	}
	i__2 = nteq;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    if (nseg1 != nteqa[i__ - 1]) {
		goto L20;
	    }
	    irow1 = i__;
	    goto L25;
L20:
	    ;
	}
L21:
	++nteq;
	irow1 = nteq;
	nteqa[nteq - 1] = nseg1;
	goto L25;
L22:
	if (ntsc == 0) {
	    goto L24;
	}
	i__2 = ntsc;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    if (nseg1 != ntsca[i__ - 1]) {
		goto L23;
	    }
	    irow1 = ndimnp - i__;
	    goto L25;
L23:
	    ;
	}
L24:
	++ntsc;
	irow1 = ndimnp - ntsc;
	ntsca[ntsc - 1] = nseg1;
	i__2 = ntsc - 1;
	i__4 = isc1 - 1;
	vsrc[i__2].r = vsorc_2.vsant[i__4].r, vsrc[i__2].i = vsorc_2.vsant[
		i__4].i;
L25:
	if (vsorc_2.nsant == 0) {
	    goto L27;
	}
	i__2 = vsorc_2.nsant;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    if (nseg2 != vsorc_2.isant[i__ - 1]) {
		goto L26;
	    }
	    isc2 = i__;
	    goto L30;
L26:
	    ;
	}
L27:
	isc2 = 0;
	if (nteq == 0) {
	    goto L29;
	}
	i__2 = nteq;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    if (nseg2 != nteqa[i__ - 1]) {
		goto L28;
	    }
	    irow2 = i__;
	    goto L33;
L28:
	    ;
	}
L29:
	++nteq;
	irow2 = nteq;
	nteqa[nteq - 1] = nseg2;
	goto L33;
L30:
	if (ntsc == 0) {
	    goto L32;
	}
	i__2 = ntsc;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    if (nseg2 != ntsca[i__ - 1]) {
		goto L31;
	    }
	    irow2 = ndimnp - i__;
	    goto L33;
L31:
	    ;
	}
L32:
	++ntsc;
	irow2 = ndimnp - ntsc;
	ntsca[ntsc - 1] = nseg2;
	i__2 = ntsc - 1;
	i__4 = isc2 - 1;
	vsrc[i__2].r = vsorc_2.vsant[i__4].r, vsrc[i__2].i = vsorc_2.vsant[
		i__4].i;
L33:
	if (ntsc + nteq < ndimnp) {
	    goto L34;
	}
	s_wsfe(&io___1771);
	e_wsfe();
	s_stop("", (ftnlen)0);

/*     FILL NETWORK EQUATION MATRIX AND RIGHT HAND SIDE VECTOR WITH */
/*     NETWORK SHORT-CIRCUIT ADMITTANCE MATRIX COEFFICIENTS. */

L34:
	if (isc1 != 0) {
	    goto L35;
	}
	i__2 = irow1 + irow1 * 30 - 31;
	i__4 = irow1 + irow1 * 30 - 31;
	z__3.r = y11r, z__3.i = y11i;
	i__1 = nseg1 - 1;
	z__2.r = data_1.si[i__1] * z__3.r, z__2.i = data_1.si[i__1] * z__3.i;
	z__1.r = cmn[i__4].r - z__2.r, z__1.i = cmn[i__4].i - z__2.i;
	cmn[i__2].r = z__1.r, cmn[i__2].i = z__1.i;
	i__2 = irow1 + irow2 * 30 - 31;
	i__4 = irow1 + irow2 * 30 - 31;
	z__3.r = y12r, z__3.i = y12i;
	i__1 = nseg1 - 1;
	z__2.r = data_1.si[i__1] * z__3.r, z__2.i = data_1.si[i__1] * z__3.i;
	z__1.r = cmn[i__4].r - z__2.r, z__1.i = cmn[i__4].i - z__2.i;
	cmn[i__2].r = z__1.r, cmn[i__2].i = z__1.i;
	goto L36;
L35:
	i__2 = irow1 - 1;
	i__4 = irow1 - 1;
	z__4.r = y11r, z__4.i = y11i;
	i__1 = isc1 - 1;
	z__3.r = z__4.r * vsorc_2.vsant[i__1].r - z__4.i * vsorc_2.vsant[i__1]
		.i, z__3.i = z__4.r * vsorc_2.vsant[i__1].i + z__4.i * 
		vsorc_2.vsant[i__1].r;
	z__2.r = z__3.r / data_1.wlam, z__2.i = z__3.i / data_1.wlam;
	z__1.r = rhnx[i__4].r + z__2.r, z__1.i = rhnx[i__4].i + z__2.i;
	rhnx[i__2].r = z__1.r, rhnx[i__2].i = z__1.i;
	i__2 = irow2 - 1;
	i__4 = irow2 - 1;
	z__4.r = y12r, z__4.i = y12i;
	i__1 = isc1 - 1;
	z__3.r = z__4.r * vsorc_2.vsant[i__1].r - z__4.i * vsorc_2.vsant[i__1]
		.i, z__3.i = z__4.r * vsorc_2.vsant[i__1].i + z__4.i * 
		vsorc_2.vsant[i__1].r;
	z__2.r = z__3.r / data_1.wlam, z__2.i = z__3.i / data_1.wlam;
	z__1.r = rhnx[i__4].r + z__2.r, z__1.i = rhnx[i__4].i + z__2.i;
	rhnx[i__2].r = z__1.r, rhnx[i__2].i = z__1.i;
L36:
	if (isc2 != 0) {
	    goto L37;
	}
	i__2 = irow2 + irow2 * 30 - 31;
	i__4 = irow2 + irow2 * 30 - 31;
	z__3.r = y22r, z__3.i = y22i;
	i__1 = nseg2 - 1;
	z__2.r = data_1.si[i__1] * z__3.r, z__2.i = data_1.si[i__1] * z__3.i;
	z__1.r = cmn[i__4].r - z__2.r, z__1.i = cmn[i__4].i - z__2.i;
	cmn[i__2].r = z__1.r, cmn[i__2].i = z__1.i;
	i__2 = irow2 + irow1 * 30 - 31;
	i__4 = irow2 + irow1 * 30 - 31;
	z__3.r = y12r, z__3.i = y12i;
	i__1 = nseg2 - 1;
	z__2.r = data_1.si[i__1] * z__3.r, z__2.i = data_1.si[i__1] * z__3.i;
	z__1.r = cmn[i__4].r - z__2.r, z__1.i = cmn[i__4].i - z__2.i;
	cmn[i__2].r = z__1.r, cmn[i__2].i = z__1.i;
	goto L38;
L37:
	i__2 = irow1 - 1;
	i__4 = irow1 - 1;
	z__4.r = y12r, z__4.i = y12i;
	i__1 = isc2 - 1;
	z__3.r = z__4.r * vsorc_2.vsant[i__1].r - z__4.i * vsorc_2.vsant[i__1]
		.i, z__3.i = z__4.r * vsorc_2.vsant[i__1].i + z__4.i * 
		vsorc_2.vsant[i__1].r;
	z__2.r = z__3.r / data_1.wlam, z__2.i = z__3.i / data_1.wlam;
	z__1.r = rhnx[i__4].r + z__2.r, z__1.i = rhnx[i__4].i + z__2.i;
	rhnx[i__2].r = z__1.r, rhnx[i__2].i = z__1.i;
	i__2 = irow2 - 1;
	i__4 = irow2 - 1;
	z__4.r = y22r, z__4.i = y22i;
	i__1 = isc2 - 1;
	z__3.r = z__4.r * vsorc_2.vsant[i__1].r - z__4.i * vsorc_2.vsant[i__1]
		.i, z__3.i = z__4.r * vsorc_2.vsant[i__1].i + z__4.i * 
		vsorc_2.vsant[i__1].r;
	z__2.r = z__3.r / data_1.wlam, z__2.i = z__3.i / data_1.wlam;
	z__1.r = rhnx[i__4].r + z__2.r, z__1.i = rhnx[i__4].i + z__2.i;
	rhnx[i__2].r = z__1.r, rhnx[i__2].i = z__1.i;
L38:
	;
    }

/*     ADD INTERACTION MATRIX ADMITTANCE ELEMENTS TO NETWORK EQUATION */
/*     MATRIX */

    i__3 = nteq;
    for (i__ = 1; i__ <= i__3; ++i__) {
	i__2 = neqt;
	for (j = 1; j <= i__2; ++j) {
/* L39: */
	    i__4 = j - 1;
	    rhs[i__4].r = 0.f, rhs[i__4].i = 0.f;
	}
	irow1 = nteqa[i__ - 1];
	i__4 = irow1 - 1;
	rhs[i__4].r = 1.f, rhs[i__4].i = 0.f;
	solgf_(&cm[1], &cmb[1], &cmc[1], &cmd[1], rhs, &ip[1], &data_1.np, &
		data_1.n1, &data_1.n, &data_1.mp, &data_1.m1, &data_1.m, &
		netcx_2.neq, &netcx_2.neq2, &neqz2);
	cabc_(rhs);
	i__4 = nteq;
	for (j = 1; j <= i__4; ++j) {
	    irow1 = nteqa[j - 1];
/* L40: */
	    i__2 = i__ + j * 30 - 31;
	    i__1 = i__ + j * 30 - 31;
	    i__5 = irow1 - 1;
	    z__1.r = cmn[i__1].r + rhs[i__5].r, z__1.i = cmn[i__1].i + rhs[
		    i__5].i;
	    cmn[i__2].r = z__1.r, cmn[i__2].i = z__1.i;
	}
/* L41: */
    }

/*     FACTOR NETWORK EQUATION MATRIX */

    factr_(&nteq, cmn, ipnt, &ndimn);

/*     ADD TO NETWORK EQUATION RIGHT HAND SIDE THE TERMS DUE TO ELEMENT */
/*     INTERACTIONS */

L42:
    if (netcx_2.nonet == 0) {
	goto L48;
    }
    i__3 = neqt;
    for (i__ = 1; i__ <= i__3; ++i__) {
/* L43: */
	i__2 = i__ - 1;
	i__1 = i__;
	rhs[i__2].r = einc[i__1].r, rhs[i__2].i = einc[i__1].i;
    }
    solgf_(&cm[1], &cmb[1], &cmc[1], &cmd[1], rhs, &ip[1], &data_1.np, &
	    data_1.n1, &data_1.n, &data_1.mp, &data_1.m1, &data_1.m, &
	    netcx_2.neq, &netcx_2.neq2, &neqz2);
    cabc_(rhs);
    i__2 = nteq;
    for (i__ = 1; i__ <= i__2; ++i__) {
	irow1 = nteqa[i__ - 1];
/* L44: */
	i__1 = i__ - 1;
	i__3 = i__ - 1;
	i__5 = irow1 - 1;
	z__1.r = rhnx[i__3].r + rhs[i__5].r, z__1.i = rhnx[i__3].i + rhs[i__5]
		.i;
	rhnt[i__1].r = z__1.r, rhnt[i__1].i = z__1.i;
    }

/*     SOLVE NETWORK EQUATIONS */

    solve_(&nteq, cmn, ipnt, rhnt, &ndimn);

/*     ADD FIELDS DUE TO NETWORK VOLTAGES TO ELECTRIC FIELDS APPLIED TO */
/*     STRUCTURE AND SOLVE FOR INDUCED CURRENT */

    i__1 = nteq;
    for (i__ = 1; i__ <= i__1; ++i__) {
	irow1 = nteqa[i__ - 1];
/* L45: */
	i__3 = irow1;
	i__5 = irow1;
	i__2 = i__ - 1;
	z__1.r = einc[i__5].r - rhnt[i__2].r, z__1.i = einc[i__5].i - rhnt[
		i__2].i;
	einc[i__3].r = z__1.r, einc[i__3].i = z__1.i;
    }
    solgf_(&cm[1], &cmb[1], &cmc[1], &cmd[1], &einc[1], &ip[1], &data_1.np, &
	    data_1.n1, &data_1.n, &data_1.mp, &data_1.m1, &data_1.m, &
	    netcx_2.neq, &netcx_2.neq2, &neqz2);
    cabc_(&einc[1]);
    if (netcx_2.nprint == 0) {
	s_wsfe(&io___1773);
	e_wsfe();
    }
    if (netcx_2.nprint == 0) {
	s_wsfe(&io___1774);
	e_wsfe();
    }
    i__3 = nteq;
    for (i__ = 1; i__ <= i__3; ++i__) {
	irow1 = nteqa[i__ - 1];
	i__5 = i__ - 1;
	i__2 = irow1 - 1;
	z__2.r = data_1.si[i__2] * rhnt[i__5].r, z__2.i = data_1.si[i__2] * 
		rhnt[i__5].i;
	z__1.r = data_1.wlam * z__2.r, z__1.i = data_1.wlam * z__2.i;
	vlt.r = z__1.r, vlt.i = z__1.i;
	i__5 = irow1;
	z__1.r = data_1.wlam * einc[i__5].r, z__1.i = data_1.wlam * einc[i__5]
		.i;
	cux.r = z__1.r, cux.i = z__1.i;
	z_div(&z__1, &cux, &vlt);
	ymit.r = z__1.r, ymit.i = z__1.i;
	z_div(&z__1, &vlt, &cux);
	netcx_2.zped.r = z__1.r, netcx_2.zped.i = z__1.i;
	irow2 = data_1.itag[irow1 - 1];
	d_cnjg(&z__2, &cux);
	z__1.r = vlt.r * z__2.r - vlt.i * z__2.i, z__1.i = vlt.r * z__2.i + 
		vlt.i * z__2.r;
	pwr = z__1.r * .5f;
	netcx_2.pnls -= pwr;
/* L46: */
	if (netcx_2.nprint == 0) {
	    s_wsfe(&io___1777);
	    do_fio(&c__1, (char *)&irow2, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&irow1, (ftnlen)sizeof(integer));
	    do_fio(&c__2, (char *)&vlt, (ftnlen)sizeof(doublereal));
	    do_fio(&c__2, (char *)&cux, (ftnlen)sizeof(doublereal));
	    do_fio(&c__2, (char *)&netcx_2.zped, (ftnlen)sizeof(doublereal));
	    do_fio(&c__2, (char *)&ymit, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&pwr, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
    }
    if (ntsc == 0) {
	goto L49;
    }
    i__3 = ntsc;
    for (i__ = 1; i__ <= i__3; ++i__) {
	irow1 = ntsca[i__ - 1];
	i__5 = i__ - 1;
	vlt.r = vsrc[i__5].r, vlt.i = vsrc[i__5].i;
	i__5 = irow1;
	z__1.r = data_1.wlam * einc[i__5].r, z__1.i = data_1.wlam * einc[i__5]
		.i;
	cux.r = z__1.r, cux.i = z__1.i;
	z_div(&z__1, &cux, &vlt);
	ymit.r = z__1.r, ymit.i = z__1.i;
	z_div(&z__1, &vlt, &cux);
	netcx_2.zped.r = z__1.r, netcx_2.zped.i = z__1.i;
	irow2 = data_1.itag[irow1 - 1];
	d_cnjg(&z__2, &cux);
	z__1.r = vlt.r * z__2.r - vlt.i * z__2.i, z__1.i = vlt.r * z__2.i + 
		vlt.i * z__2.r;
	pwr = z__1.r * .5f;
	netcx_2.pnls -= pwr;
/* L47: */
	if (netcx_2.nprint == 0) {
	    s_wsfe(&io___1778);
	    do_fio(&c__1, (char *)&irow2, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&irow1, (ftnlen)sizeof(integer));
	    do_fio(&c__2, (char *)&vlt, (ftnlen)sizeof(doublereal));
	    do_fio(&c__2, (char *)&cux, (ftnlen)sizeof(doublereal));
	    do_fio(&c__2, (char *)&netcx_2.zped, (ftnlen)sizeof(doublereal));
	    do_fio(&c__2, (char *)&ymit, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&pwr, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
    }
    goto L49;

/*     SOLVE FOR CURRENTS WHEN NO NETWORKS ARE PRESENT */

L48:
    solgf_(&cm[1], &cmb[1], &cmc[1], &cmd[1], &einc[1], &ip[1], &data_1.np, &
	    data_1.n1, &data_1.n, &data_1.mp, &data_1.m1, &data_1.m, &
	    netcx_2.neq, &netcx_2.neq2, &neqz2);
    cabc_(&einc[1]);
    ntsc = 0;
L49:
    if (vsorc_2.nsant + vsorc_2.nvqd == 0) {
	return 0;
    }
    s_wsfe(&io___1779);
    e_wsfe();
    s_wsfe(&io___1780);
    e_wsfe();
    if (vsorc_2.nsant == 0) {
	goto L56;
    }
    i__3 = vsorc_2.nsant;
    for (i__ = 1; i__ <= i__3; ++i__) {
	isc1 = vsorc_2.isant[i__ - 1];
	i__5 = i__ - 1;
	vlt.r = vsorc_2.vsant[i__5].r, vlt.i = vsorc_2.vsant[i__5].i;
	if (ntsc == 0) {
	    goto L51;
	}
	i__5 = ntsc;
	for (j = 1; j <= i__5; ++j) {
	    if (ntsca[j - 1] == isc1) {
		goto L52;
	    }
/* L50: */
	}
L51:
	i__5 = isc1;
	z__1.r = data_1.wlam * einc[i__5].r, z__1.i = data_1.wlam * einc[i__5]
		.i;
	cux.r = z__1.r, cux.i = z__1.i;
	irow1 = 0;
	goto L54;
L52:
	irow1 = ndimnp - j;
	i__5 = irow1 - 1;
	cux.r = rhnx[i__5].r, cux.i = rhnx[i__5].i;
	i__5 = nteq;
	for (j = 1; j <= i__5; ++j) {
/* L53: */
	    i__2 = j + irow1 * 30 - 31;
	    i__1 = j - 1;
	    z__2.r = cmn[i__2].r * rhnt[i__1].r - cmn[i__2].i * rhnt[i__1].i, 
		    z__2.i = cmn[i__2].r * rhnt[i__1].i + cmn[i__2].i * rhnt[
		    i__1].r;
	    z__1.r = cux.r - z__2.r, z__1.i = cux.i - z__2.i;
	    cux.r = z__1.r, cux.i = z__1.i;
	}
	i__2 = isc1;
	z__2.r = einc[i__2].r + cux.r, z__2.i = einc[i__2].i + cux.i;
	z__1.r = data_1.wlam * z__2.r, z__1.i = data_1.wlam * z__2.i;
	cux.r = z__1.r, cux.i = z__1.i;
L54:
	z_div(&z__1, &cux, &vlt);
	ymit.r = z__1.r, ymit.i = z__1.i;
	z_div(&z__1, &vlt, &cux);
	netcx_2.zped.r = z__1.r, netcx_2.zped.i = z__1.i;
	d_cnjg(&z__2, &cux);
	z__1.r = vlt.r * z__2.r - vlt.i * z__2.i, z__1.i = vlt.r * z__2.i + 
		vlt.i * z__2.r;
	pwr = z__1.r * .5f;
	netcx_2.pin += pwr;
	if (irow1 != 0) {
	    netcx_2.pnls += pwr;
	}
	irow2 = data_1.itag[isc1 - 1];
/* L55: */
	s_wsfe(&io___1781);
	do_fio(&c__1, (char *)&irow2, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&isc1, (ftnlen)sizeof(integer));
	do_fio(&c__2, (char *)&vlt, (ftnlen)sizeof(doublereal));
	do_fio(&c__2, (char *)&cux, (ftnlen)sizeof(doublereal));
	do_fio(&c__2, (char *)&netcx_2.zped, (ftnlen)sizeof(doublereal));
	do_fio(&c__2, (char *)&ymit, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&pwr, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
L56:
    if (vsorc_2.nvqd == 0) {
	return 0;
    }
    i__3 = vsorc_2.nvqd;
    for (i__ = 1; i__ <= i__3; ++i__) {
	isc1 = vsorc_2.ivqd[i__ - 1];
	i__2 = i__ - 1;
	vlt.r = vsorc_2.vqd[i__2].r, vlt.i = vsorc_2.vqd[i__2].i;
	i__2 = isc1 - 1;
	i__1 = isc1 - 1;
	z__1.r = crnt_1.air[i__2], z__1.i = crnt_1.aii[i__1];
	cux.r = z__1.r, cux.i = z__1.i;
	i__2 = isc1 - 1;
	i__1 = isc1 - 1;
	z__1.r = crnt_1.bir[i__2], z__1.i = crnt_1.bii[i__1];
	ymit.r = z__1.r, ymit.i = z__1.i;
	i__2 = isc1 - 1;
	i__1 = isc1 - 1;
	z__1.r = crnt_1.cir[i__2], z__1.i = crnt_1.cii[i__1];
	netcx_2.zped.r = z__1.r, netcx_2.zped.i = z__1.i;
	pwr = data_1.si[isc1 - 1] * tp * .5f;
	d__1 = sin(pwr);
	z__4.r = d__1 * ymit.r, z__4.i = d__1 * ymit.i;
	z__3.r = cux.r - z__4.r, z__3.i = cux.i - z__4.i;
	d__2 = cos(pwr);
	z__5.r = d__2 * netcx_2.zped.r, z__5.i = d__2 * netcx_2.zped.i;
	z__2.r = z__3.r + z__5.r, z__2.i = z__3.i + z__5.i;
	z__1.r = data_1.wlam * z__2.r, z__1.i = data_1.wlam * z__2.i;
	cux.r = z__1.r, cux.i = z__1.i;
	z_div(&z__1, &cux, &vlt);
	ymit.r = z__1.r, ymit.i = z__1.i;
	z_div(&z__1, &vlt, &cux);
	netcx_2.zped.r = z__1.r, netcx_2.zped.i = z__1.i;
	d_cnjg(&z__2, &cux);
	z__1.r = vlt.r * z__2.r - vlt.i * z__2.i, z__1.i = vlt.r * z__2.i + 
		vlt.i * z__2.r;
	pwr = z__1.r * .5f;
	netcx_2.pin += pwr;
	irow2 = data_1.itag[isc1 - 1];
/* L57: */
	s_wsfe(&io___1782);
	do_fio(&c__1, (char *)&irow2, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&isc1, (ftnlen)sizeof(integer));
	do_fio(&c__2, (char *)&vlt, (ftnlen)sizeof(doublereal));
	do_fio(&c__2, (char *)&cux, (ftnlen)sizeof(doublereal));
	do_fio(&c__2, (char *)&netcx_2.zped, (ftnlen)sizeof(doublereal));
	do_fio(&c__2, (char *)&ymit, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&pwr, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    return 0;

} /* netwk_ */

/* Subroutine */ int nfpat_(void)
{
    /* Initialized data */

    static doublereal ta = .01745329252;

    /* Format strings */
    static char fmt_10[] = "(///,35x,\002- - - NEAR ELECTRIC FIELDS - - -"
	    "\002,//,12x,\002-  LOCATION  -\002,21x,\002-  EX  -\002,15x,\002"
	    "-  EY  -\002,15x,\002-  EZ  -\002,/,8x,\002X\002,10x,\002Y\002,1"
	    "0x,\002Z\002,10x,\002MAGNITUDE\002,3x,\002PHASE\002,6x,\002MAGNI"
	    "TUDE\002,3x,\002PHASE\002,6x,\002MAGNITUDE\002,3x,\002PHASE\002,"
	    "/,6x,\002METERS\002,5x,\002METERS\002,5x,\002METERS\002,8x,\002V"
	    "OLTS/M\002,3x,\002DEGREES\002,6x,\002VOLTS/M\002,3x,\002DEGREE"
	    "S\002,6x,\002VOLTS/M\002,3x,\002DEGREES\002)";
    static char fmt_12[] = "(///,35x,\002- - - NEAR MAGNETIC FIELDS - - -"
	    "\002,//,12x,\002-  LOCATION  -\002,21x,\002-  HX  -\002,15x,\002"
	    "-  HY  -\002,15x,\002-  HZ  -\002,/,8x,\002X\002,10x,\002Y\002,1"
	    "0x,\002Z\002,10x,\002MAGNITUDE\002,3x,\002PHASE\002,6x,\002MAGNI"
	    "TUDE\002,3x,\002PHASE\002,6x,\002MAGNITUDE\002,3x,\002PHASE\002,"
	    "/,6x,\002METERS\002,5x,\002METERS\002,5x,\002METERS\002,9x,\002A"
	    "MPS/M\002,3x,\002DEGREES\002,7x,\002AMPS/M\002,3x,\002DEGREES"
	    "\002,7x,\002AMPS/M\002,3x,\002DEGREES\002)";
    static char fmt_11[] = "(2x,3(2x,f9.4),1x,3(3x,1p,e11.4,2x,0p,f7.2))";

    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void);
    double cos(doublereal), sin(doublereal), z_abs(doublecomplex *);
    integer do_fio(integer *, char *, ftnlen), s_wsle(cilist *), do_lio(
	    integer *, integer *, char *, ftnlen), e_wsle(void);

    /* Local variables */
    integer i__, j, kk;
    doublecomplex ex, ey, ez;
    doublereal cth, cph, xob, sph, yob, zob, sth, xxx, tmp1, tmp2, tmp3, tmp4,
	     tmp5, tmp6;
    extern doublereal cang_(doublecomplex *);
    doublereal xnrt, ynrt, znrt;
    extern /* Subroutine */ int nefld_(doublereal *, doublereal *, doublereal 
	    *, doublecomplex *, doublecomplex *, doublecomplex *), nhfld_(
	    doublereal *, doublereal *, doublereal *, doublecomplex *, 
	    doublecomplex *, doublecomplex *);

    /* Fortran I/O blocks */
    static cilist io___1784 = { 0, 3, 0, fmt_10, 0 };
    static cilist io___1785 = { 0, 3, 0, fmt_12, 0 };
    static cilist io___1808 = { 0, 3, 0, fmt_11, 0 };
    static cilist io___1810 = { 0, 8, 0, 0, 0 };
    static cilist io___1811 = { 0, 8, 0, 0, 0 };
    static cilist io___1812 = { 0, 8, 0, 0, 0 };
    static cilist io___1813 = { 0, 8, 0, 0, 0 };
    static cilist io___1814 = { 0, 8, 0, 0, 0 };
    static cilist io___1815 = { 0, 8, 0, 0, 0 };
    static cilist io___1816 = { 0, 8, 0, 0, 0 };
    static cilist io___1817 = { 0, 8, 0, 0, 0 };


/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* Max number of segments 	(Windows-95 <= 4 */
/* max nr of 'in-core' alloc.	(MAXMAT <= MA */
/* Max number of LD cards */
/* Max number of EX cards */
/* Max number of segs connected to NT/TL */
/* *** */
/*     COMPUTE NEAR E OR H FIELDS OVER A RANGE OF POINTS */
/* *** */
/* *** */
    if (fpat_1.nfeh == 1) {
	goto L1;
    }
    s_wsfe(&io___1784);
    e_wsfe();
    goto L2;
L1:
    s_wsfe(&io___1785);
    e_wsfe();
L2:
    znrt = fpat_1.znr - fpat_1.dznr;
    i__1 = fpat_1.nrz;
    for (i__ = 1; i__ <= i__1; ++i__) {
	znrt += fpat_1.dznr;
	if (fpat_1.near__ == 0) {
	    goto L3;
	}
	cth = cos(ta * znrt);
	sth = sin(ta * znrt);
L3:
	ynrt = fpat_1.ynr - fpat_1.dynr;
	i__2 = fpat_1.nry;
	for (j = 1; j <= i__2; ++j) {
	    ynrt += fpat_1.dynr;
	    if (fpat_1.near__ == 0) {
		goto L4;
	    }
	    cph = cos(ta * ynrt);
	    sph = sin(ta * ynrt);
L4:
	    xnrt = fpat_1.xnr - fpat_1.dxnr;
	    i__3 = fpat_1.nrx;
	    for (kk = 1; kk <= i__3; ++kk) {
		xnrt += fpat_1.dxnr;
		if (fpat_1.near__ == 0) {
		    goto L5;
		}
		xob = xnrt * sth * cph;
		yob = xnrt * sth * sph;
		zob = xnrt * cth;
		goto L6;
L5:
		xob = xnrt;
		yob = ynrt;
		zob = znrt;
L6:
		tmp1 = xob / data_1.wlam;
		tmp2 = yob / data_1.wlam;
		tmp3 = zob / data_1.wlam;
		if (fpat_1.nfeh == 1) {
		    goto L7;
		}
		nefld_(&tmp1, &tmp2, &tmp3, &ex, &ey, &ez);
		goto L8;
L7:
		nhfld_(&tmp1, &tmp2, &tmp3, &ex, &ey, &ez);
L8:
		tmp1 = z_abs(&ex);
		tmp2 = cang_(&ex);
		tmp3 = z_abs(&ey);
		tmp4 = cang_(&ey);
		tmp5 = z_abs(&ez);
		tmp6 = cang_(&ez);
		s_wsfe(&io___1808);
		do_fio(&c__1, (char *)&xob, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&yob, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&zob, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&tmp1, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&tmp2, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&tmp3, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&tmp4, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&tmp5, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&tmp6, (ftnlen)sizeof(doublereal));
		e_wsfe();
/* *** */
		if (plot_1.iplp1 != 2) {
		    goto L9;
		}
		switch (plot_1.iplp4) {
		    case 1:  goto L14;
		    case 2:  goto L15;
		    case 3:  goto L16;
		}
L14:
		xxx = xob;
		goto L17;
L15:
		xxx = yob;
		goto L17;
L16:
		xxx = zob;
L17:
		if (plot_1.iplp2 != 2) {
		    goto L13;
		}
		if (plot_1.iplp3 == 1) {
		    s_wsle(&io___1810);
		    do_lio(&c__5, &c__1, (char *)&xxx, (ftnlen)sizeof(
			    doublereal));
		    do_lio(&c__5, &c__1, (char *)&tmp1, (ftnlen)sizeof(
			    doublereal));
		    do_lio(&c__5, &c__1, (char *)&tmp2, (ftnlen)sizeof(
			    doublereal));
		    e_wsle();
		}
		if (plot_1.iplp3 == 2) {
		    s_wsle(&io___1811);
		    do_lio(&c__5, &c__1, (char *)&xxx, (ftnlen)sizeof(
			    doublereal));
		    do_lio(&c__5, &c__1, (char *)&tmp3, (ftnlen)sizeof(
			    doublereal));
		    do_lio(&c__5, &c__1, (char *)&tmp4, (ftnlen)sizeof(
			    doublereal));
		    e_wsle();
		}
		if (plot_1.iplp3 == 3) {
		    s_wsle(&io___1812);
		    do_lio(&c__5, &c__1, (char *)&xxx, (ftnlen)sizeof(
			    doublereal));
		    do_lio(&c__5, &c__1, (char *)&tmp5, (ftnlen)sizeof(
			    doublereal));
		    do_lio(&c__5, &c__1, (char *)&tmp6, (ftnlen)sizeof(
			    doublereal));
		    e_wsle();
		}
		if (plot_1.iplp3 == 4) {
		    s_wsle(&io___1813);
		    do_lio(&c__5, &c__1, (char *)&xxx, (ftnlen)sizeof(
			    doublereal));
		    do_lio(&c__5, &c__1, (char *)&tmp1, (ftnlen)sizeof(
			    doublereal));
		    do_lio(&c__5, &c__1, (char *)&tmp2, (ftnlen)sizeof(
			    doublereal));
		    do_lio(&c__5, &c__1, (char *)&tmp3, (ftnlen)sizeof(
			    doublereal));
		    do_lio(&c__5, &c__1, (char *)&tmp4, (ftnlen)sizeof(
			    doublereal));
		    do_lio(&c__5, &c__1, (char *)&tmp5, (ftnlen)sizeof(
			    doublereal));
		    do_lio(&c__5, &c__1, (char *)&tmp6, (ftnlen)sizeof(
			    doublereal));
		    e_wsle();
		}
		goto L9;
L13:
		if (plot_1.iplp2 != 1) {
		    goto L9;
		}
		if (plot_1.iplp3 == 1) {
		    s_wsle(&io___1814);
		    do_lio(&c__5, &c__1, (char *)&xxx, (ftnlen)sizeof(
			    doublereal));
		    do_lio(&c__7, &c__1, (char *)&ex, (ftnlen)sizeof(
			    doublecomplex));
		    e_wsle();
		}
		if (plot_1.iplp3 == 2) {
		    s_wsle(&io___1815);
		    do_lio(&c__5, &c__1, (char *)&xxx, (ftnlen)sizeof(
			    doublereal));
		    do_lio(&c__7, &c__1, (char *)&ey, (ftnlen)sizeof(
			    doublecomplex));
		    e_wsle();
		}
		if (plot_1.iplp3 == 3) {
		    s_wsle(&io___1816);
		    do_lio(&c__5, &c__1, (char *)&xxx, (ftnlen)sizeof(
			    doublereal));
		    do_lio(&c__7, &c__1, (char *)&ez, (ftnlen)sizeof(
			    doublecomplex));
		    e_wsle();
		}
		if (plot_1.iplp3 == 4) {
		    s_wsle(&io___1817);
		    do_lio(&c__5, &c__1, (char *)&xxx, (ftnlen)sizeof(
			    doublereal));
		    do_lio(&c__7, &c__1, (char *)&ex, (ftnlen)sizeof(
			    doublecomplex));
		    do_lio(&c__7, &c__1, (char *)&ey, (ftnlen)sizeof(
			    doublecomplex));
		    do_lio(&c__7, &c__1, (char *)&ez, (ftnlen)sizeof(
			    doublecomplex));
		    e_wsle();
		}
/* *** */
L9:
		;
	    }
	}
    }
    return 0;

} /* nfpat_ */

/* Subroutine */ int nhfld_(doublereal *xob, doublereal *yob, doublereal *zob,
	 doublecomplex *hx, doublecomplex *hy, doublecomplex *hz)
{
    /* System generated locals */
    integer i__1, i__2, i__3, i__4;
    doublereal d__1;
    doublecomplex z__1, z__2, z__3, z__4, z__5, z__6;

    /* Local variables */
    integer i__, jc, jl;
    doublereal ax, zp;
#define xs ((doublereal *)&data_1)
#define ys ((doublereal *)&data_1 + 1500)
#define zs ((doublereal *)&data_1 + 3000)
#define t1x ((doublereal *)&data_1 + 4500)
#define t1y ((doublereal *)&data_1 + 7500)
#define t1z ((doublereal *)&data_1 + 9000)
#define t2x ((doublereal *)&data_1 + 10501)
#define t2y ((doublereal *)&data_1 + 12001)
#define t2z ((doublereal *)&data_1 + 13501)
#define cab ((doublereal *)&data_1 + 7500)
#define sab ((doublereal *)&data_1 + 9000)
    doublecomplex acx, bcx, ccx, con;
#define t1xj ((doublereal *)&dataj_1 + 5)
#define t1yj ((doublereal *)&dataj_1 + 6)
#define t1zj ((doublereal *)&dataj_1 + 7)
#define t2xj ((doublereal *)&dataj_1 + 1)
#define t2yj ((doublereal *)&dataj_1 + 27)
#define t2zj ((doublereal *)&dataj_1 + 28)
    doublereal delt;
    doublecomplex exmx, exmy, exmz, expx, expy, expz, eypx, eymx, eypy, eymy, 
	    eypz, eymz, ezpx, ezmx, ezpy, ezmy, ezpz, ezmz;
    extern /* Subroutine */ int nefld_(doublereal *, doublereal *, doublereal 
	    *, doublecomplex *, doublecomplex *, doublecomplex *), hsfld_(
	    doublereal *, doublereal *, doublereal *, doublereal *), hintg_(
	    doublereal *, doublereal *, doublereal *);


/*     NHFLD COMPUTES THE NEAR FIELD AT SPECIFIED POINTS IN SPACE AFTER */
/*     THE STRUCTURE CURRENTS HAVE BEEN COMPUTED. */

/* Max number of segments 	(Windows-95 <= 4 */
/* max nr of 'in-core' alloc.	(MAXMAT <= MA */
/* Max number of LD cards */
/* Max number of EX cards */
/* Max number of segs connected to NT/TL */
/* *************************************** */
/* *************************************** */
/* *************************************** */
    if (gnd_1.iperf == 2) {
	goto L6;
    }
/* *************************************** */
    hx->r = 0.f, hx->i = 0.f;
    hy->r = 0.f, hy->i = 0.f;
    hz->r = 0.f, hz->i = 0.f;
    ax = 0.f;
    if (data_1.n == 0) {
	goto L4;
    }
    i__1 = data_1.n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	dataj_1.xj = *xob - data_1.x[i__ - 1];
	dataj_1.yj = *yob - data_1.y[i__ - 1];
	dataj_1.zj = *zob - data_1.z__[i__ - 1];
	zp = cab[i__ - 1] * dataj_1.xj + sab[i__ - 1] * dataj_1.yj + 
		angl_1.salp[i__ - 1] * dataj_1.zj;
	if (abs(zp) > data_1.si[i__ - 1] * .5001f) {
	    goto L1;
	}
	zp = dataj_1.xj * dataj_1.xj + dataj_1.yj * dataj_1.yj + dataj_1.zj * 
		dataj_1.zj - zp * zp;
	dataj_1.xj = data_1.bi[i__ - 1];
	if (zp > dataj_1.xj * .9f * dataj_1.xj) {
	    goto L1;
	}
	ax = dataj_1.xj;
	goto L2;
L1:
	;
    }
L2:
    i__1 = data_1.n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	dataj_1.s = data_1.si[i__ - 1];
	dataj_1.b = data_1.bi[i__ - 1];
	dataj_1.xj = data_1.x[i__ - 1];
	dataj_1.yj = data_1.y[i__ - 1];
	dataj_1.zj = data_1.z__[i__ - 1];
	dataj_1.cabj = cab[i__ - 1];
	dataj_1.sabj = sab[i__ - 1];
	dataj_1.salpj = angl_1.salp[i__ - 1];
	hsfld_(xob, yob, zob, &ax);
	i__2 = i__ - 1;
	i__3 = i__ - 1;
	z__1.r = crnt_1.air[i__2], z__1.i = crnt_1.aii[i__3];
	acx.r = z__1.r, acx.i = z__1.i;
	i__2 = i__ - 1;
	i__3 = i__ - 1;
	z__1.r = crnt_1.bir[i__2], z__1.i = crnt_1.bii[i__3];
	bcx.r = z__1.r, bcx.i = z__1.i;
	i__2 = i__ - 1;
	i__3 = i__ - 1;
	z__1.r = crnt_1.cir[i__2], z__1.i = crnt_1.cii[i__3];
	ccx.r = z__1.r, ccx.i = z__1.i;
	z__4.r = dataj_1.exk.r * acx.r - dataj_1.exk.i * acx.i, z__4.i = 
		dataj_1.exk.r * acx.i + dataj_1.exk.i * acx.r;
	z__3.r = hx->r + z__4.r, z__3.i = hx->i + z__4.i;
	z__5.r = dataj_1.exs.r * bcx.r - dataj_1.exs.i * bcx.i, z__5.i = 
		dataj_1.exs.r * bcx.i + dataj_1.exs.i * bcx.r;
	z__2.r = z__3.r + z__5.r, z__2.i = z__3.i + z__5.i;
	z__6.r = dataj_1.exc.r * ccx.r - dataj_1.exc.i * ccx.i, z__6.i = 
		dataj_1.exc.r * ccx.i + dataj_1.exc.i * ccx.r;
	z__1.r = z__2.r + z__6.r, z__1.i = z__2.i + z__6.i;
	hx->r = z__1.r, hx->i = z__1.i;
	z__4.r = dataj_1.eyk.r * acx.r - dataj_1.eyk.i * acx.i, z__4.i = 
		dataj_1.eyk.r * acx.i + dataj_1.eyk.i * acx.r;
	z__3.r = hy->r + z__4.r, z__3.i = hy->i + z__4.i;
	z__5.r = dataj_1.eys.r * bcx.r - dataj_1.eys.i * bcx.i, z__5.i = 
		dataj_1.eys.r * bcx.i + dataj_1.eys.i * bcx.r;
	z__2.r = z__3.r + z__5.r, z__2.i = z__3.i + z__5.i;
	z__6.r = dataj_1.eyc.r * ccx.r - dataj_1.eyc.i * ccx.i, z__6.i = 
		dataj_1.eyc.r * ccx.i + dataj_1.eyc.i * ccx.r;
	z__1.r = z__2.r + z__6.r, z__1.i = z__2.i + z__6.i;
	hy->r = z__1.r, hy->i = z__1.i;
/* L3: */
	z__4.r = dataj_1.ezk.r * acx.r - dataj_1.ezk.i * acx.i, z__4.i = 
		dataj_1.ezk.r * acx.i + dataj_1.ezk.i * acx.r;
	z__3.r = hz->r + z__4.r, z__3.i = hz->i + z__4.i;
	z__5.r = dataj_1.ezs.r * bcx.r - dataj_1.ezs.i * bcx.i, z__5.i = 
		dataj_1.ezs.r * bcx.i + dataj_1.ezs.i * bcx.r;
	z__2.r = z__3.r + z__5.r, z__2.i = z__3.i + z__5.i;
	z__6.r = dataj_1.ezc.r * ccx.r - dataj_1.ezc.i * ccx.i, z__6.i = 
		dataj_1.ezc.r * ccx.i + dataj_1.ezc.i * ccx.r;
	z__1.r = z__2.r + z__6.r, z__1.i = z__2.i + z__6.i;
	hz->r = z__1.r, hz->i = z__1.i;
    }
    if (data_1.m == 0) {
	return 0;
    }
L4:
    jc = data_1.n;
    jl = data_1.ld + 1;
    i__1 = data_1.m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	--jl;
	dataj_1.s = data_1.bi[jl - 1];
	dataj_1.xj = data_1.x[jl - 1];
	dataj_1.yj = data_1.y[jl - 1];
	dataj_1.zj = data_1.z__[jl - 1];
	*t1xj = t1x[jl - 1];
	*t1yj = t1y[jl - 1];
	*t1zj = t1z[jl - 1];
	*t2xj = t2x[jl - 1];
	*t2yj = t2y[jl - 1];
	*t2zj = t2z[jl - 1];
	hintg_(xob, yob, zob);
	jc += 3;
	i__2 = jc - 3;
	z__3.r = *t1xj * crnt_1.cur[i__2].r, z__3.i = *t1xj * crnt_1.cur[i__2]
		.i;
	i__3 = jc - 2;
	z__4.r = *t1yj * crnt_1.cur[i__3].r, z__4.i = *t1yj * crnt_1.cur[i__3]
		.i;
	z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
	i__4 = jc - 1;
	z__5.r = *t1zj * crnt_1.cur[i__4].r, z__5.i = *t1zj * crnt_1.cur[i__4]
		.i;
	z__1.r = z__2.r + z__5.r, z__1.i = z__2.i + z__5.i;
	acx.r = z__1.r, acx.i = z__1.i;
	i__2 = jc - 3;
	z__3.r = *t2xj * crnt_1.cur[i__2].r, z__3.i = *t2xj * crnt_1.cur[i__2]
		.i;
	i__3 = jc - 2;
	z__4.r = *t2yj * crnt_1.cur[i__3].r, z__4.i = *t2yj * crnt_1.cur[i__3]
		.i;
	z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
	i__4 = jc - 1;
	z__5.r = *t2zj * crnt_1.cur[i__4].r, z__5.i = *t2zj * crnt_1.cur[i__4]
		.i;
	z__1.r = z__2.r + z__5.r, z__1.i = z__2.i + z__5.i;
	bcx.r = z__1.r, bcx.i = z__1.i;
	z__3.r = acx.r * dataj_1.exk.r - acx.i * dataj_1.exk.i, z__3.i = 
		acx.r * dataj_1.exk.i + acx.i * dataj_1.exk.r;
	z__2.r = hx->r + z__3.r, z__2.i = hx->i + z__3.i;
	z__4.r = bcx.r * dataj_1.exs.r - bcx.i * dataj_1.exs.i, z__4.i = 
		bcx.r * dataj_1.exs.i + bcx.i * dataj_1.exs.r;
	z__1.r = z__2.r + z__4.r, z__1.i = z__2.i + z__4.i;
	hx->r = z__1.r, hx->i = z__1.i;
	z__3.r = acx.r * dataj_1.eyk.r - acx.i * dataj_1.eyk.i, z__3.i = 
		acx.r * dataj_1.eyk.i + acx.i * dataj_1.eyk.r;
	z__2.r = hy->r + z__3.r, z__2.i = hy->i + z__3.i;
	z__4.r = bcx.r * dataj_1.eys.r - bcx.i * dataj_1.eys.i, z__4.i = 
		bcx.r * dataj_1.eys.i + bcx.i * dataj_1.eys.r;
	z__1.r = z__2.r + z__4.r, z__1.i = z__2.i + z__4.i;
	hy->r = z__1.r, hy->i = z__1.i;
/* L5: */
	z__3.r = acx.r * dataj_1.ezk.r - acx.i * dataj_1.ezk.i, z__3.i = 
		acx.r * dataj_1.ezk.i + acx.i * dataj_1.ezk.r;
	z__2.r = hz->r + z__3.r, z__2.i = hz->i + z__3.i;
	z__4.r = bcx.r * dataj_1.ezs.r - bcx.i * dataj_1.ezs.i, z__4.i = 
		bcx.r * dataj_1.ezs.i + bcx.i * dataj_1.ezs.r;
	z__1.r = z__2.r + z__4.r, z__1.i = z__2.i + z__4.i;
	hz->r = z__1.r, hz->i = z__1.i;
    }
    return 0;

/*     GET H BY FINITE DIFFERENCE OF E FOR SOMMERFELD GROUND */
/*     CON=j/(2*pi*eta) */
/*     DELT is the increment for getting central differences */

L6:
    delt = .001f;
    con.r = 0.f, con.i = 4.2246e-4f;
    d__1 = *xob + delt;
    nefld_(&d__1, yob, zob, &expx, &eypx, &ezpx);
    d__1 = *xob - delt;
    nefld_(&d__1, yob, zob, &exmx, &eymx, &ezmx);
    d__1 = *yob + delt;
    nefld_(xob, &d__1, zob, &expy, &eypy, &ezpy);
    d__1 = *yob - delt;
    nefld_(xob, &d__1, zob, &exmy, &eymy, &ezmy);
    d__1 = *zob + delt;
    nefld_(xob, yob, &d__1, &expz, &eypz, &ezpz);
    d__1 = *zob - delt;
    nefld_(xob, yob, &d__1, &exmz, &eymz, &ezmz);
    z__5.r = ezpy.r - ezmy.r, z__5.i = ezpy.i - ezmy.i;
    z__4.r = z__5.r - eypz.r, z__4.i = z__5.i - eypz.i;
    z__3.r = z__4.r + eymz.r, z__3.i = z__4.i + eymz.i;
    z__2.r = con.r * z__3.r - con.i * z__3.i, z__2.i = con.r * z__3.i + con.i 
	    * z__3.r;
    d__1 = delt * 2.f;
    z__1.r = z__2.r / d__1, z__1.i = z__2.i / d__1;
    hx->r = z__1.r, hx->i = z__1.i;
    z__5.r = expz.r - exmz.r, z__5.i = expz.i - exmz.i;
    z__4.r = z__5.r - ezpx.r, z__4.i = z__5.i - ezpx.i;
    z__3.r = z__4.r + ezmx.r, z__3.i = z__4.i + ezmx.i;
    z__2.r = con.r * z__3.r - con.i * z__3.i, z__2.i = con.r * z__3.i + con.i 
	    * z__3.r;
    d__1 = delt * 2.f;
    z__1.r = z__2.r / d__1, z__1.i = z__2.i / d__1;
    hy->r = z__1.r, hy->i = z__1.i;
    z__5.r = eypx.r - eymx.r, z__5.i = eypx.i - eymx.i;
    z__4.r = z__5.r - expy.r, z__4.i = z__5.i - expy.i;
    z__3.r = z__4.r + exmy.r, z__3.i = z__4.i + exmy.i;
    z__2.r = con.r * z__3.r - con.i * z__3.i, z__2.i = con.r * z__3.i + con.i 
	    * z__3.r;
    d__1 = delt * 2.f;
    z__1.r = z__2.r / d__1, z__1.i = z__2.i / d__1;
    hz->r = z__1.r, hz->i = z__1.i;
    return 0;
} /* nhfld_ */

#undef t2zj
#undef t2yj
#undef t2xj
#undef t1zj
#undef t1yj
#undef t1xj
#undef sab
#undef cab
#undef t2z
#undef t2y
#undef t2x
#undef t1z
#undef t1y
#undef t1x
#undef zs
#undef ys
#undef xs


/* Subroutine */ int patch_0_(int n__, integer *nx, integer *ny, doublereal *
	x1, doublereal *y1, doublereal *z1, doublereal *x2, doublereal *y2, 
	doublereal *z2, doublereal *x3, doublereal *y3, doublereal *z3, 
	doublereal *x4, doublereal *y4, doublereal *z4)
{
    /* Format strings */
    static char fmt_14[] = "(\002 ERROR -- CORNERS OF QUADRILATERAL PATCH DO"
	    " NOT LIE IN\rA PLANE\002)";

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    double cos(doublereal), sin(doublereal), sqrt(doublereal);
    integer s_wsfe(cilist *), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    integer mi;
    doublereal xa;
    integer ix, iy;
    doublereal xs, ys, zs, xt, yt, zt, xn2, yn2, zn2, s1x;
#define t1x ((doublereal *)&data_1 + 4500)
#define t1y ((doublereal *)&data_1 + 7500)
#define t1z ((doublereal *)&data_1 + 9000)
#define t2x ((doublereal *)&data_1 + 10501)
#define t2y ((doublereal *)&data_1 + 12001)
#define t2z ((doublereal *)&data_1 + 13501)
    doublereal s1y, s1z, s2x, s2y, s2z;
    integer mia, ntp, nxp, nyp;
    doublereal xnv, ynv, znv, xst, saln, salpn;

    /* Fortran I/O blocks */
    static cilist io___1886 = { 0, 3, 0, fmt_14, 0 };


/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* Max number of segments 	(Windows-95 <= 4 */
/* max nr of 'in-core' alloc.	(MAXMAT <= MA */
/* Max number of LD cards */
/* Max number of EX cards */
/* Max number of segs connected to NT/TL */
/* *** */
/*     PATCH GENERATES AND MODIFIES PATCH GEOMETRY DATA */
/*     NEW PATCHES.  FOR NX=0, NY=1,2,3,4 PATCH IS (RESPECTIVELY) */
/*     ARBITRARY, RECTAGULAR, TRIANGULAR, OR QUADRILATERAL. */
/*     FOR NX AND NY .GT. 0 A RECTANGULAR SURFACE IS PRODUCED WITH */
/*     NX BY NY RECTANGULAR PATCHES. */
    switch(n__) {
	case 1: goto L_subph;
	}

    ++data_1.m;
    mi = data_1.ld + 1 - data_1.m;
    ntp = *ny;
    if (*nx > 0) {
	ntp = 2;
    }
    if (ntp > 1) {
	goto L2;
    }
    data_1.x[mi - 1] = *x1;
    data_1.y[mi - 1] = *y1;
    data_1.z__[mi - 1] = *z1;
    data_1.bi[mi - 1] = *z2;
    znv = cos(*x2);
    xnv = znv * cos(*y2);
    ynv = znv * sin(*y2);
    znv = sin(*x2);
    xa = sqrt(xnv * xnv + ynv * ynv);
    if (xa < 1e-6) {
	goto L1;
    }
    t1x[mi - 1] = -ynv / xa;
    t1y[mi - 1] = xnv / xa;
    t1z[mi - 1] = 0.f;
    goto L6;
L1:
    t1x[mi - 1] = 1.f;
    t1y[mi - 1] = 0.f;
    t1z[mi - 1] = 0.f;
    goto L6;
L2:
    s1x = *x2 - *x1;
    s1y = *y2 - *y1;
    s1z = *z2 - *z1;
    s2x = *x3 - *x2;
    s2y = *y3 - *y2;
    s2z = *z3 - *z2;
    if (*nx == 0) {
	goto L3;
    }
    s1x /= *nx;
    s1y /= *nx;
    s1z /= *nx;
    s2x /= *ny;
    s2y /= *ny;
    s2z /= *ny;
L3:
    xnv = s1y * s2z - s1z * s2y;
    ynv = s1z * s2x - s1x * s2z;
    znv = s1x * s2y - s1y * s2x;
    xa = sqrt(xnv * xnv + ynv * ynv + znv * znv);
    xnv /= xa;
    ynv /= xa;
    znv /= xa;
    xst = sqrt(s1x * s1x + s1y * s1y + s1z * s1z);
    t1x[mi - 1] = s1x / xst;
    t1y[mi - 1] = s1y / xst;
    t1z[mi - 1] = s1z / xst;
    if (ntp > 2) {
	goto L4;
    }
    data_1.x[mi - 1] = *x1 + (s1x + s2x) * .5f;
    data_1.y[mi - 1] = *y1 + (s1y + s2y) * .5f;
    data_1.z__[mi - 1] = *z1 + (s1z + s2z) * .5f;
    data_1.bi[mi - 1] = xa;
    goto L6;
L4:
    if (ntp == 4) {
	goto L5;
    }
    data_1.x[mi - 1] = (*x1 + *x2 + *x3) / 3.f;
    data_1.y[mi - 1] = (*y1 + *y2 + *y3) / 3.f;
    data_1.z__[mi - 1] = (*z1 + *z2 + *z3) / 3.f;
    data_1.bi[mi - 1] = xa * .5f;
    goto L6;
L5:
    s1x = *x3 - *x1;
    s1y = *y3 - *y1;
    s1z = *z3 - *z1;
    s2x = *x4 - *x1;
    s2y = *y4 - *y1;
    s2z = *z4 - *z1;
    xn2 = s1y * s2z - s1z * s2y;
    yn2 = s1z * s2x - s1x * s2z;
    zn2 = s1x * s2y - s1y * s2x;
    xst = sqrt(xn2 * xn2 + yn2 * yn2 + zn2 * zn2);
    salpn = 1.f / ((xa + xst) * 3.f);
    data_1.x[mi - 1] = (xa * (*x1 + *x2 + *x3) + xst * (*x1 + *x3 + *x4)) * 
	    salpn;
    data_1.y[mi - 1] = (xa * (*y1 + *y2 + *y3) + xst * (*y1 + *y3 + *y4)) * 
	    salpn;
    data_1.z__[mi - 1] = (xa * (*z1 + *z2 + *z3) + xst * (*z1 + *z3 + *z4)) * 
	    salpn;
    data_1.bi[mi - 1] = (xa + xst) * .5f;
    s1x = (xnv * xn2 + ynv * yn2 + znv * zn2) / xst;
    if (s1x > .9998f) {
	goto L6;
    }
    s_wsfe(&io___1886);
    e_wsfe();
    s_stop("", (ftnlen)0);
L6:
    t2x[mi - 1] = ynv * t1z[mi - 1] - znv * t1y[mi - 1];
    t2y[mi - 1] = znv * t1x[mi - 1] - xnv * t1z[mi - 1];
    t2z[mi - 1] = xnv * t1y[mi - 1] - ynv * t1x[mi - 1];
    angl_1.salp[mi - 1] = 1.f;
    if (*nx == 0) {
	goto L8;
    }
    data_1.m = data_1.m + *nx * *ny - 1;
    xn2 = data_1.x[mi - 1] - s1x - s2x;
    yn2 = data_1.y[mi - 1] - s1y - s2y;
    zn2 = data_1.z__[mi - 1] - s1z - s2z;
    xs = t1x[mi - 1];
    ys = t1y[mi - 1];
    zs = t1z[mi - 1];
    xt = t2x[mi - 1];
    yt = t2y[mi - 1];
    zt = t2z[mi - 1];
    ++mi;
    i__1 = *ny;
    for (iy = 1; iy <= i__1; ++iy) {
	xn2 += s2x;
	yn2 += s2y;
	zn2 += s2z;
	i__2 = *nx;
	for (ix = 1; ix <= i__2; ++ix) {
	    xst = (doublereal) ix;
	    --mi;
	    data_1.x[mi - 1] = xn2 + xst * s1x;
	    data_1.y[mi - 1] = yn2 + xst * s1y;
	    data_1.z__[mi - 1] = zn2 + xst * s1z;
	    data_1.bi[mi - 1] = xa;
	    angl_1.salp[mi - 1] = 1.f;
	    t1x[mi - 1] = xs;
	    t1y[mi - 1] = ys;
	    t1z[mi - 1] = zs;
	    t2x[mi - 1] = xt;
	    t2y[mi - 1] = yt;
/* L7: */
	    t2z[mi - 1] = zt;
	}
    }
L8:
    data_1.ipsym = 0;
    data_1.np = data_1.n;
    data_1.mp = data_1.m;
    return 0;
/*     DIVIDE PATCH FOR WIRE CONNECTION */

L_subph:
    if (*ny > 0) {
	goto L10;
    }
    if (*nx == data_1.m) {
	goto L10;
    }
    nxp = *nx + 1;
    ix = data_1.ld - data_1.m;
    i__2 = data_1.m;
    for (iy = nxp; iy <= i__2; ++iy) {
	++ix;
	nyp = ix - 3;
	data_1.x[nyp - 1] = data_1.x[ix - 1];
	data_1.y[nyp - 1] = data_1.y[ix - 1];
	data_1.z__[nyp - 1] = data_1.z__[ix - 1];
	data_1.bi[nyp - 1] = data_1.bi[ix - 1];
	angl_1.salp[nyp - 1] = angl_1.salp[ix - 1];
	t1x[nyp - 1] = t1x[ix - 1];
	t1y[nyp - 1] = t1y[ix - 1];
	t1z[nyp - 1] = t1z[ix - 1];
	t2x[nyp - 1] = t2x[ix - 1];
	t2y[nyp - 1] = t2y[ix - 1];
/* L9: */
	t2z[nyp - 1] = t2z[ix - 1];
    }
L10:
    mi = data_1.ld + 1 - *nx;
    xs = data_1.x[mi - 1];
    ys = data_1.y[mi - 1];
    zs = data_1.z__[mi - 1];
    xa = data_1.bi[mi - 1] * .25f;
    xst = sqrt(xa) * .5f;
    s1x = t1x[mi - 1];
    s1y = t1y[mi - 1];
    s1z = t1z[mi - 1];
    s2x = t2x[mi - 1];
    s2y = t2y[mi - 1];
    s2z = t2z[mi - 1];
    saln = angl_1.salp[mi - 1];
    xt = xst;
    yt = xst;
    if (*ny > 0) {
	goto L11;
    }
    mia = mi;
    goto L12;
L11:
    ++data_1.m;
    ++data_1.mp;
    mia = data_1.ld + 1 - data_1.m;
L12:
    for (ix = 1; ix <= 4; ++ix) {
	data_1.x[mia - 1] = xs + xt * s1x + yt * s2x;
	data_1.y[mia - 1] = ys + xt * s1y + yt * s2y;
	data_1.z__[mia - 1] = zs + xt * s1z + yt * s2z;
	data_1.bi[mia - 1] = xa;
	t1x[mia - 1] = s1x;
	t1y[mia - 1] = s1y;
	t1z[mia - 1] = s1z;
	t2x[mia - 1] = s2x;
	t2y[mia - 1] = s2y;
	t2z[mia - 1] = s2z;
	angl_1.salp[mia - 1] = saln;
	if (ix == 2) {
	    yt = -yt;
	}
	if (ix == 1 || ix == 3) {
	    xt = -xt;
	}
	--mia;
/* L13: */
    }
    data_1.m += 3;
    if (*nx <= data_1.mp) {
	data_1.mp += 3;
    }
    if (*ny > 0) {
	data_1.z__[mi - 1] = 1e4f;
    }
    return 0;

} /* patch_ */

#undef t2z
#undef t2y
#undef t2x
#undef t1z
#undef t1y
#undef t1x


/* Subroutine */ int patch_(integer *nx, integer *ny, doublereal *x1, 
	doublereal *y1, doublereal *z1, doublereal *x2, doublereal *y2, 
	doublereal *z2, doublereal *x3, doublereal *y3, doublereal *z3, 
	doublereal *x4, doublereal *y4, doublereal *z4)
{
    return patch_0_(0, nx, ny, x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4)
	    ;
    }

/* Subroutine */ int subph_(integer *nx, integer *ny, doublereal *x1, 
	doublereal *y1, doublereal *z1, doublereal *x2, doublereal *y2, 
	doublereal *z2, doublereal *x3, doublereal *y3, doublereal *z3, 
	doublereal *x4, doublereal *y4, doublereal *z4)
{
    return patch_0_(1, nx, ny, x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4)
	    ;
    }

/* Subroutine */ int pcint_(doublereal *xi, doublereal *yi, doublereal *zi, 
	doublereal *cabi, doublereal *sabi, doublereal *salpi, doublecomplex *
	e)
{
    /* Initialized data */

    static doublereal tpi = 6.283185308;
    static integer nint = 10;

    /* System generated locals */
    integer i__1, i__2;
    doublecomplex z__1, z__2, z__3, z__4, z__5;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    doublereal d__;
    doublecomplex e1, e2, e3, e4, e5, e6, e7, e8, e9;
    integer i1, i2;
    doublereal g1, g2, g3, s1, s2, g4, f2, f1, da, ds, xs, s2x, xxj, xyj, xzj,
	     xss, yss, zss;
#define t1xj ((doublereal *)&dataj_1 + 5)
#define t1yj ((doublereal *)&dataj_1 + 6)
#define t1zj ((doublereal *)&dataj_1 + 7)
#define t2xj ((doublereal *)&dataj_1 + 1)
#define t2yj ((doublereal *)&dataj_1 + 27)
#define t2zj ((doublereal *)&dataj_1 + 28)
    doublereal fcon, gcon;
    extern /* Subroutine */ int unere_(doublereal *, doublereal *, doublereal 
	    *);

/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* *** */
/*     INTEGRATE OVER PATCHES AT WIRE CONNECTION POINT */
    /* Parameter adjustments */
    --e;

    /* Function Body */
    d__ = sqrt(dataj_1.s) * .5f;
    ds = d__ * 4.f / (doublereal) nint;
    da = ds * ds;
    gcon = 1.f / dataj_1.s;
    fcon = 1.f / (tpi * 2.f * d__);
    xxj = dataj_1.xj;
    xyj = dataj_1.yj;
    xzj = dataj_1.zj;
    xs = dataj_1.s;
    dataj_1.s = da;
    s1 = d__ + ds * .5f;
    xss = dataj_1.xj + s1 * (*t1xj + *t2xj);
    yss = dataj_1.yj + s1 * (*t1yj + *t2yj);
    zss = dataj_1.zj + s1 * (*t1zj + *t2zj);
    s1 += d__;
    s2x = s1;
    e1.r = 0.f, e1.i = 0.f;
    e2.r = 0.f, e2.i = 0.f;
    e3.r = 0.f, e3.i = 0.f;
    e4.r = 0.f, e4.i = 0.f;
    e5.r = 0.f, e5.i = 0.f;
    e6.r = 0.f, e6.i = 0.f;
    e7.r = 0.f, e7.i = 0.f;
    e8.r = 0.f, e8.i = 0.f;
    e9.r = 0.f, e9.i = 0.f;
    i__1 = nint;
    for (i1 = 1; i1 <= i__1; ++i1) {
	s1 -= ds;
	s2 = s2x;
	xss -= ds * *t1xj;
	yss -= ds * *t1yj;
	zss -= ds * *t1zj;
	dataj_1.xj = xss;
	dataj_1.yj = yss;
	dataj_1.zj = zss;
	i__2 = nint;
	for (i2 = 1; i2 <= i__2; ++i2) {
	    s2 -= ds;
	    dataj_1.xj -= ds * *t2xj;
	    dataj_1.yj -= ds * *t2yj;
	    dataj_1.zj -= ds * *t2zj;
	    unere_(xi, yi, zi);
	    z__3.r = *cabi * dataj_1.exk.r, z__3.i = *cabi * dataj_1.exk.i;
	    z__4.r = *sabi * dataj_1.eyk.r, z__4.i = *sabi * dataj_1.eyk.i;
	    z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
	    z__5.r = *salpi * dataj_1.ezk.r, z__5.i = *salpi * dataj_1.ezk.i;
	    z__1.r = z__2.r + z__5.r, z__1.i = z__2.i + z__5.i;
	    dataj_1.exk.r = z__1.r, dataj_1.exk.i = z__1.i;
	    z__3.r = *cabi * dataj_1.exs.r, z__3.i = *cabi * dataj_1.exs.i;
	    z__4.r = *sabi * dataj_1.eys.r, z__4.i = *sabi * dataj_1.eys.i;
	    z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
	    z__5.r = *salpi * dataj_1.ezs.r, z__5.i = *salpi * dataj_1.ezs.i;
	    z__1.r = z__2.r + z__5.r, z__1.i = z__2.i + z__5.i;
	    dataj_1.exs.r = z__1.r, dataj_1.exs.i = z__1.i;
	    g1 = (d__ + s1) * (d__ + s2) * gcon;
	    g2 = (d__ - s1) * (d__ + s2) * gcon;
	    g3 = (d__ - s1) * (d__ - s2) * gcon;
	    g4 = (d__ + s1) * (d__ - s2) * gcon;
	    f2 = (s1 * s1 + s2 * s2) * tpi;
	    f1 = s1 / f2 - (g1 - g2 - g3 + g4) * fcon;
	    f2 = s2 / f2 - (g1 + g2 - g3 - g4) * fcon;
	    z__2.r = g1 * dataj_1.exk.r, z__2.i = g1 * dataj_1.exk.i;
	    z__1.r = e1.r + z__2.r, z__1.i = e1.i + z__2.i;
	    e1.r = z__1.r, e1.i = z__1.i;
	    z__2.r = g2 * dataj_1.exk.r, z__2.i = g2 * dataj_1.exk.i;
	    z__1.r = e2.r + z__2.r, z__1.i = e2.i + z__2.i;
	    e2.r = z__1.r, e2.i = z__1.i;
	    z__2.r = g3 * dataj_1.exk.r, z__2.i = g3 * dataj_1.exk.i;
	    z__1.r = e3.r + z__2.r, z__1.i = e3.i + z__2.i;
	    e3.r = z__1.r, e3.i = z__1.i;
	    z__2.r = g4 * dataj_1.exk.r, z__2.i = g4 * dataj_1.exk.i;
	    z__1.r = e4.r + z__2.r, z__1.i = e4.i + z__2.i;
	    e4.r = z__1.r, e4.i = z__1.i;
	    z__2.r = g1 * dataj_1.exs.r, z__2.i = g1 * dataj_1.exs.i;
	    z__1.r = e5.r + z__2.r, z__1.i = e5.i + z__2.i;
	    e5.r = z__1.r, e5.i = z__1.i;
	    z__2.r = g2 * dataj_1.exs.r, z__2.i = g2 * dataj_1.exs.i;
	    z__1.r = e6.r + z__2.r, z__1.i = e6.i + z__2.i;
	    e6.r = z__1.r, e6.i = z__1.i;
	    z__2.r = g3 * dataj_1.exs.r, z__2.i = g3 * dataj_1.exs.i;
	    z__1.r = e7.r + z__2.r, z__1.i = e7.i + z__2.i;
	    e7.r = z__1.r, e7.i = z__1.i;
	    z__2.r = g4 * dataj_1.exs.r, z__2.i = g4 * dataj_1.exs.i;
	    z__1.r = e8.r + z__2.r, z__1.i = e8.i + z__2.i;
	    e8.r = z__1.r, e8.i = z__1.i;
/* L1: */
	    z__3.r = f1 * dataj_1.exk.r, z__3.i = f1 * dataj_1.exk.i;
	    z__2.r = e9.r + z__3.r, z__2.i = e9.i + z__3.i;
	    z__4.r = f2 * dataj_1.exs.r, z__4.i = f2 * dataj_1.exs.i;
	    z__1.r = z__2.r + z__4.r, z__1.i = z__2.i + z__4.i;
	    e9.r = z__1.r, e9.i = z__1.i;
	}
    }
    e[1].r = e1.r, e[1].i = e1.i;
    e[2].r = e2.r, e[2].i = e2.i;
    e[3].r = e3.r, e[3].i = e3.i;
    e[4].r = e4.r, e[4].i = e4.i;
    e[5].r = e5.r, e[5].i = e5.i;
    e[6].r = e6.r, e[6].i = e6.i;
    e[7].r = e7.r, e[7].i = e7.i;
    e[8].r = e8.r, e[8].i = e8.i;
    e[9].r = e9.r, e[9].i = e9.i;
    dataj_1.xj = xxj;
    dataj_1.yj = xyj;
    dataj_1.zj = xzj;
    dataj_1.s = xs;
    return 0;
} /* pcint_ */

#undef t2zj
#undef t2yj
#undef t2xj
#undef t1zj
#undef t1yj
#undef t1xj


/* Subroutine */ int prnt_(integer *in1, integer *in2, integer *in3, 
	doublereal *fl1, doublereal *fl2, doublereal *fl3, doublereal *fl4, 
	doublereal *fl5, doublereal *fl6, char *ctype, ftnlen ctype_len)
{
    /* Format strings */
    static char fmt_90[] = "(i5)";
    static char fmt_91[] = "(1p,e13.4)";
    static char fmt_92[] = "(/,3x,3a,3x,6a,3x,a)";

    /* System generated locals */
    icilist ici__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfi(icilist *), do_fio(integer *, char *, ftnlen), e_wsfi(void)
	    , s_wsfe(cilist *), e_wsfe(void);

    /* Local variables */
    integer i__;
    char cflt[13*6], cint[5*3];

    /* Fortran I/O blocks */
    static cilist io___1942 = { 0, 3, 0, fmt_92, 0 };



/*     Purpose: */
/*     PRNT prints the input data for impedance loading, inserting blanks */
/*     for numbers that are zero. */

/*     INPUT: */
/*     IN1-3 = INTEGER VALUES TO BE PRINTED */
/*     FL1-6 = REAL VALUES TO BE PRINTED */
/*     CTYPE = CHARACTER STRING TO BE PRINTED */


    for (i__ = 1; i__ <= 3; ++i__) {
/* L1: */
	s_copy(cint + (i__ - 1) * 5, "     ", (ftnlen)5, (ftnlen)5);
    }
    if (*in1 == 0 && *in2 == 0 && *in3 == 0) {
	s_copy(cint, "  ALL", (ftnlen)5, (ftnlen)5);
    } else {
	if (*in1 != 0) {
	    ici__1.icierr = 0;
	    ici__1.icirnum = 1;
	    ici__1.icirlen = 5;
	    ici__1.iciunit = cint;
	    ici__1.icifmt = fmt_90;
	    s_wsfi(&ici__1);
	    do_fio(&c__1, (char *)&(*in1), (ftnlen)sizeof(integer));
	    e_wsfi();
	}
	if (*in2 != 0) {
	    ici__1.icierr = 0;
	    ici__1.icirnum = 1;
	    ici__1.icirlen = 5;
	    ici__1.iciunit = cint + 5;
	    ici__1.icifmt = fmt_90;
	    s_wsfi(&ici__1);
	    do_fio(&c__1, (char *)&(*in2), (ftnlen)sizeof(integer));
	    e_wsfi();
	}
	if (*in3 != 0) {
	    ici__1.icierr = 0;
	    ici__1.icirnum = 1;
	    ici__1.icirlen = 5;
	    ici__1.iciunit = cint + 10;
	    ici__1.icifmt = fmt_90;
	    s_wsfi(&ici__1);
	    do_fio(&c__1, (char *)&(*in3), (ftnlen)sizeof(integer));
	    e_wsfi();
	}
    }
    for (i__ = 1; i__ <= 6; ++i__) {
/* L2: */
	s_copy(cflt + (i__ - 1) * 13, "     ", (ftnlen)13, (ftnlen)5);
    }
    if (abs(*fl1) > 1e-30f) {
	ici__1.icierr = 0;
	ici__1.icirnum = 1;
	ici__1.icirlen = 13;
	ici__1.iciunit = cflt;
	ici__1.icifmt = fmt_91;
	s_wsfi(&ici__1);
	do_fio(&c__1, (char *)&(*fl1), (ftnlen)sizeof(doublereal));
	e_wsfi();
    }
    if (abs(*fl2) > 1e-30f) {
	ici__1.icierr = 0;
	ici__1.icirnum = 1;
	ici__1.icirlen = 13;
	ici__1.iciunit = cflt + 13;
	ici__1.icifmt = fmt_91;
	s_wsfi(&ici__1);
	do_fio(&c__1, (char *)&(*fl2), (ftnlen)sizeof(doublereal));
	e_wsfi();
    }
    if (abs(*fl3) > 1e-30f) {
	ici__1.icierr = 0;
	ici__1.icirnum = 1;
	ici__1.icirlen = 13;
	ici__1.iciunit = cflt + 26;
	ici__1.icifmt = fmt_91;
	s_wsfi(&ici__1);
	do_fio(&c__1, (char *)&(*fl3), (ftnlen)sizeof(doublereal));
	e_wsfi();
    }
    if (abs(*fl4) > 1e-30f) {
	ici__1.icierr = 0;
	ici__1.icirnum = 1;
	ici__1.icirlen = 13;
	ici__1.iciunit = cflt + 39;
	ici__1.icifmt = fmt_91;
	s_wsfi(&ici__1);
	do_fio(&c__1, (char *)&(*fl4), (ftnlen)sizeof(doublereal));
	e_wsfi();
    }
    if (abs(*fl5) > 1e-30f) {
	ici__1.icierr = 0;
	ici__1.icirnum = 1;
	ici__1.icirlen = 13;
	ici__1.iciunit = cflt + 52;
	ici__1.icifmt = fmt_91;
	s_wsfi(&ici__1);
	do_fio(&c__1, (char *)&(*fl5), (ftnlen)sizeof(doublereal));
	e_wsfi();
    }
    if (abs(*fl6) > 1e-30f) {
	ici__1.icierr = 0;
	ici__1.icirnum = 1;
	ici__1.icirlen = 13;
	ici__1.iciunit = cflt + 65;
	ici__1.icifmt = fmt_91;
	s_wsfi(&ici__1);
	do_fio(&c__1, (char *)&(*fl6), (ftnlen)sizeof(doublereal));
	e_wsfi();
    }
    s_wsfe(&io___1942);
    for (i__ = 1; i__ <= 3; ++i__) {
	do_fio(&c__1, cint + (i__ - 1) * 5, (ftnlen)5);
    }
    for (i__ = 1; i__ <= 6; ++i__) {
	do_fio(&c__1, cflt + (i__ - 1) * 13, (ftnlen)13);
    }
    do_fio(&c__1, ctype, ctype_len);
    e_wsfe();
    return 0;

} /* prnt_ */

/* Subroutine */ int qdsrc_(integer *is, doublecomplex *v, doublecomplex *e)
{
    /* Initialized data */

    static doublereal tp = 6.283185308;
    static struct {
	doublereal e_1[2];
	} equiv_0 = { 0., -.01666666667 };


    /* System generated locals */
    integer i__1, i__2, i__3, i__4, i__5, i__6, i__7, i__8;
    doublereal d__1;
    doublecomplex z__1, z__2, z__3, z__4, z__5, z__6, z__7, z__8;

    /* Builtin functions */
    double log(doublereal), cos(doublereal), sin(doublereal);

    /* Local variables */
    integer i__, j, i1;
    doublereal ai;
    integer ij;
    doublereal xi;
    integer jx;
    doublereal yi, zi, tx, ty, tz;
#define t1x ((doublereal *)&data_1 + 4500)
#define t1y ((doublereal *)&data_1 + 7500)
#define t1z ((doublereal *)&data_1 + 9000)
#define t2x ((doublereal *)&data_1 + 10501)
#define t2y ((doublereal *)&data_1 + 12001)
#define t2z ((doublereal *)&data_1 + 13501)
#define cab ((doublereal *)&data_1 + 7500)
#define ccj ((doublecomplex *)&equiv_0)
#define sab ((doublereal *)&data_1 + 9000)
    doublecomplex etc;
    extern /* Subroutine */ int tbf_(integer *, integer *);
    doublecomplex etk, ets;
    integer ipr;
    doublereal cabi;
    extern /* Subroutine */ int efld_(doublereal *, doublereal *, doublereal *
	    , doublereal *, integer *);
    doublereal sabi;
#define ccjx ((doublereal *)&equiv_0)
    doublecomplex curd;
    extern /* Subroutine */ int hsfld_(doublereal *, doublereal *, doublereal 
	    *, doublereal *);
    doublereal salpi;

/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* Max number of segments 	(Windows-95 <= 4 */
/* max nr of 'in-core' alloc.	(MAXMAT <= MA */
/* Max number of LD cards */
/* Max number of EX cards */
/* Max number of segs connected to NT/TL */
/* *** */
/*     FILL INCIDENT FIELD ARRAY FOR CHARGE DISCONTINUITY VOLTAGE SOURCE */
/* av07 COMMON /VSORC/ VQD(30),VSANT(30),VQDS(30),IVQD(30),ISANT(30),IQDS( */
/* av07 130),NVQD,NSANT,NQDS */
/* av07 */
    /* Parameter adjustments */
    --e;

    /* Function Body */
    i__ = data_1.icon1[(84008 + (0 + (*is - 1 << 2)) - 84008) / 4];
    data_1.icon1[*is - 1] = 0;
    tbf_(is, &c__0);
    data_1.icon1[*is - 1] = i__;
    dataj_1.s = data_1.si[*is - 1] * .5f;
    z__2.r = ccj->r * v->r - ccj->i * v->i, z__2.i = ccj->r * v->i + ccj->i * 
	    v->r;
    d__1 = (log(dataj_1.s * 2.f / data_1.bi[*is - 1]) - 1.f) * (segj_1.bx[
	    segj_1.jsno - 1] * cos(tp * dataj_1.s) + segj_1.cx[segj_1.jsno - 
	    1] * sin(tp * dataj_1.s)) * data_1.wlam;
    z__1.r = z__2.r / d__1, z__1.i = z__2.i / d__1;
    curd.r = z__1.r, curd.i = z__1.i;
    ++vsorc_1.nqds;
    i__1 = vsorc_1.nqds - 1;
    vsorc_1.vqds[i__1].r = v->r, vsorc_1.vqds[i__1].i = v->i;
    vsorc_1.iqds[vsorc_1.nqds - 1] = *is;
    i__1 = segj_1.jsno;
    for (jx = 1; jx <= i__1; ++jx) {
	j = segj_1.jco[jx - 1];
	dataj_1.s = data_1.si[j - 1];
	dataj_1.b = data_1.bi[j - 1];
	dataj_1.xj = data_1.x[j - 1];
	dataj_1.yj = data_1.y[j - 1];
	dataj_1.zj = data_1.z__[j - 1];
	dataj_1.cabj = cab[j - 1];
	dataj_1.sabj = sab[j - 1];
	dataj_1.salpj = angl_1.salp[j - 1];
	if (dataj_1.iexk == 0) {
	    goto L16;
	}
	ipr = data_1.icon1[j - 1];
	if (ipr < 0) {
	    goto L1;
	} else if (ipr == 0) {
	    goto L6;
	} else {
	    goto L2;
	}
L1:
	ipr = -ipr;
	if (-data_1.icon1[ipr - 1] != j) {
	    goto L7;
	}
	goto L4;
L2:
	if (ipr != j) {
	    goto L3;
	}
	if (dataj_1.cabj * dataj_1.cabj + dataj_1.sabj * dataj_1.sabj > 1e-8) 
		{
	    goto L7;
	}
	goto L5;
L3:
	if (data_1.icon2[ipr - 1] != j) {
	    goto L7;
	}
L4:
	xi = (d__1 = dataj_1.cabj * cab[ipr - 1] + dataj_1.sabj * sab[ipr - 1]
		 + dataj_1.salpj * angl_1.salp[ipr - 1], abs(d__1));
	if (xi < .999999) {
	    goto L7;
	}
	if ((d__1 = data_1.bi[ipr - 1] / dataj_1.b - 1.f, abs(d__1)) > 1e-6) {
	    goto L7;
	}
L5:
	dataj_1.ind1 = 0;
	goto L8;
L6:
	dataj_1.ind1 = 1;
	goto L8;
L7:
	dataj_1.ind1 = 2;
L8:
	ipr = data_1.icon2[j - 1];
	if (ipr < 0) {
	    goto L9;
	} else if (ipr == 0) {
	    goto L14;
	} else {
	    goto L10;
	}
L9:
	ipr = -ipr;
	if (-data_1.icon2[ipr - 1] != j) {
	    goto L15;
	}
	goto L12;
L10:
	if (ipr != j) {
	    goto L11;
	}
	if (dataj_1.cabj * dataj_1.cabj + dataj_1.sabj * dataj_1.sabj > 1e-8) 
		{
	    goto L15;
	}
	goto L13;
L11:
	if (data_1.icon1[ipr - 1] != j) {
	    goto L15;
	}
L12:
	xi = (d__1 = dataj_1.cabj * cab[ipr - 1] + dataj_1.sabj * sab[ipr - 1]
		 + dataj_1.salpj * angl_1.salp[ipr - 1], abs(d__1));
	if (xi < .999999) {
	    goto L15;
	}
	if ((d__1 = data_1.bi[ipr - 1] / dataj_1.b - 1.f, abs(d__1)) > 1e-6) {
	    goto L15;
	}
L13:
	dataj_1.ind2 = 0;
	goto L16;
L14:
	dataj_1.ind2 = 1;
	goto L16;
L15:
	dataj_1.ind2 = 2;
L16:
	i__2 = data_1.n;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    ij = i__ - j;
	    xi = data_1.x[i__ - 1];
	    yi = data_1.y[i__ - 1];
	    zi = data_1.z__[i__ - 1];
	    ai = data_1.bi[i__ - 1];
	    efld_(&xi, &yi, &zi, &ai, &ij);
	    cabi = cab[i__ - 1];
	    sabi = sab[i__ - 1];
	    salpi = angl_1.salp[i__ - 1];
	    z__3.r = cabi * dataj_1.exk.r, z__3.i = cabi * dataj_1.exk.i;
	    z__4.r = sabi * dataj_1.eyk.r, z__4.i = sabi * dataj_1.eyk.i;
	    z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
	    z__5.r = salpi * dataj_1.ezk.r, z__5.i = salpi * dataj_1.ezk.i;
	    z__1.r = z__2.r + z__5.r, z__1.i = z__2.i + z__5.i;
	    etk.r = z__1.r, etk.i = z__1.i;
	    z__3.r = cabi * dataj_1.exs.r, z__3.i = cabi * dataj_1.exs.i;
	    z__4.r = sabi * dataj_1.eys.r, z__4.i = sabi * dataj_1.eys.i;
	    z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
	    z__5.r = salpi * dataj_1.ezs.r, z__5.i = salpi * dataj_1.ezs.i;
	    z__1.r = z__2.r + z__5.r, z__1.i = z__2.i + z__5.i;
	    ets.r = z__1.r, ets.i = z__1.i;
	    z__3.r = cabi * dataj_1.exc.r, z__3.i = cabi * dataj_1.exc.i;
	    z__4.r = sabi * dataj_1.eyc.r, z__4.i = sabi * dataj_1.eyc.i;
	    z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
	    z__5.r = salpi * dataj_1.ezc.r, z__5.i = salpi * dataj_1.ezc.i;
	    z__1.r = z__2.r + z__5.r, z__1.i = z__2.i + z__5.i;
	    etc.r = z__1.r, etc.i = z__1.i;
/* L17: */
	    i__3 = i__;
	    i__4 = i__;
	    i__5 = jx - 1;
	    z__5.r = segj_1.ax[i__5] * etk.r, z__5.i = segj_1.ax[i__5] * 
		    etk.i;
	    i__6 = jx - 1;
	    z__6.r = segj_1.bx[i__6] * ets.r, z__6.i = segj_1.bx[i__6] * 
		    ets.i;
	    z__4.r = z__5.r + z__6.r, z__4.i = z__5.i + z__6.i;
	    i__7 = jx - 1;
	    z__7.r = segj_1.cx[i__7] * etc.r, z__7.i = segj_1.cx[i__7] * 
		    etc.i;
	    z__3.r = z__4.r + z__7.r, z__3.i = z__4.i + z__7.i;
	    z__2.r = z__3.r * curd.r - z__3.i * curd.i, z__2.i = z__3.r * 
		    curd.i + z__3.i * curd.r;
	    z__1.r = e[i__4].r - z__2.r, z__1.i = e[i__4].i - z__2.i;
	    e[i__3].r = z__1.r, e[i__3].i = z__1.i;
	}
	if (data_1.m == 0) {
	    goto L19;
	}
	ij = data_1.ld + 1;
	i1 = data_1.n;
	i__3 = data_1.m;
	for (i__ = 1; i__ <= i__3; ++i__) {
	    --ij;
	    xi = data_1.x[ij - 1];
	    yi = data_1.y[ij - 1];
	    zi = data_1.z__[ij - 1];
	    hsfld_(&xi, &yi, &zi, &c_b636);
	    ++i1;
	    tx = t2x[ij - 1];
	    ty = t2y[ij - 1];
	    tz = t2z[ij - 1];
	    z__3.r = tx * dataj_1.exk.r, z__3.i = tx * dataj_1.exk.i;
	    z__4.r = ty * dataj_1.eyk.r, z__4.i = ty * dataj_1.eyk.i;
	    z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
	    z__5.r = tz * dataj_1.ezk.r, z__5.i = tz * dataj_1.ezk.i;
	    z__1.r = z__2.r + z__5.r, z__1.i = z__2.i + z__5.i;
	    etk.r = z__1.r, etk.i = z__1.i;
	    z__3.r = tx * dataj_1.exs.r, z__3.i = tx * dataj_1.exs.i;
	    z__4.r = ty * dataj_1.eys.r, z__4.i = ty * dataj_1.eys.i;
	    z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
	    z__5.r = tz * dataj_1.ezs.r, z__5.i = tz * dataj_1.ezs.i;
	    z__1.r = z__2.r + z__5.r, z__1.i = z__2.i + z__5.i;
	    ets.r = z__1.r, ets.i = z__1.i;
	    z__3.r = tx * dataj_1.exc.r, z__3.i = tx * dataj_1.exc.i;
	    z__4.r = ty * dataj_1.eyc.r, z__4.i = ty * dataj_1.eyc.i;
	    z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
	    z__5.r = tz * dataj_1.ezc.r, z__5.i = tz * dataj_1.ezc.i;
	    z__1.r = z__2.r + z__5.r, z__1.i = z__2.i + z__5.i;
	    etc.r = z__1.r, etc.i = z__1.i;
	    i__4 = i1;
	    i__5 = i1;
	    i__6 = jx - 1;
	    z__6.r = segj_1.ax[i__6] * etk.r, z__6.i = segj_1.ax[i__6] * 
		    etk.i;
	    i__7 = jx - 1;
	    z__7.r = segj_1.bx[i__7] * ets.r, z__7.i = segj_1.bx[i__7] * 
		    ets.i;
	    z__5.r = z__6.r + z__7.r, z__5.i = z__6.i + z__7.i;
	    i__2 = jx - 1;
	    z__8.r = segj_1.cx[i__2] * etc.r, z__8.i = segj_1.cx[i__2] * 
		    etc.i;
	    z__4.r = z__5.r + z__8.r, z__4.i = z__5.i + z__8.i;
	    z__3.r = z__4.r * curd.r - z__4.i * curd.i, z__3.i = z__4.r * 
		    curd.i + z__4.i * curd.r;
	    i__8 = ij - 1;
	    z__2.r = angl_1.salp[i__8] * z__3.r, z__2.i = angl_1.salp[i__8] * 
		    z__3.i;
	    z__1.r = e[i__5].r + z__2.r, z__1.i = e[i__5].i + z__2.i;
	    e[i__4].r = z__1.r, e[i__4].i = z__1.i;
	    ++i1;
	    tx = t1x[ij - 1];
	    ty = t1y[ij - 1];
	    tz = t1z[ij - 1];
	    z__3.r = tx * dataj_1.exk.r, z__3.i = tx * dataj_1.exk.i;
	    z__4.r = ty * dataj_1.eyk.r, z__4.i = ty * dataj_1.eyk.i;
	    z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
	    z__5.r = tz * dataj_1.ezk.r, z__5.i = tz * dataj_1.ezk.i;
	    z__1.r = z__2.r + z__5.r, z__1.i = z__2.i + z__5.i;
	    etk.r = z__1.r, etk.i = z__1.i;
	    z__3.r = tx * dataj_1.exs.r, z__3.i = tx * dataj_1.exs.i;
	    z__4.r = ty * dataj_1.eys.r, z__4.i = ty * dataj_1.eys.i;
	    z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
	    z__5.r = tz * dataj_1.ezs.r, z__5.i = tz * dataj_1.ezs.i;
	    z__1.r = z__2.r + z__5.r, z__1.i = z__2.i + z__5.i;
	    ets.r = z__1.r, ets.i = z__1.i;
	    z__3.r = tx * dataj_1.exc.r, z__3.i = tx * dataj_1.exc.i;
	    z__4.r = ty * dataj_1.eyc.r, z__4.i = ty * dataj_1.eyc.i;
	    z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
	    z__5.r = tz * dataj_1.ezc.r, z__5.i = tz * dataj_1.ezc.i;
	    z__1.r = z__2.r + z__5.r, z__1.i = z__2.i + z__5.i;
	    etc.r = z__1.r, etc.i = z__1.i;
/* L18: */
	    i__4 = i1;
	    i__5 = i1;
	    i__6 = jx - 1;
	    z__6.r = segj_1.ax[i__6] * etk.r, z__6.i = segj_1.ax[i__6] * 
		    etk.i;
	    i__7 = jx - 1;
	    z__7.r = segj_1.bx[i__7] * ets.r, z__7.i = segj_1.bx[i__7] * 
		    ets.i;
	    z__5.r = z__6.r + z__7.r, z__5.i = z__6.i + z__7.i;
	    i__2 = jx - 1;
	    z__8.r = segj_1.cx[i__2] * etc.r, z__8.i = segj_1.cx[i__2] * 
		    etc.i;
	    z__4.r = z__5.r + z__8.r, z__4.i = z__5.i + z__8.i;
	    z__3.r = z__4.r * curd.r - z__4.i * curd.i, z__3.i = z__4.r * 
		    curd.i + z__4.i * curd.r;
	    i__8 = ij - 1;
	    z__2.r = angl_1.salp[i__8] * z__3.r, z__2.i = angl_1.salp[i__8] * 
		    z__3.i;
	    z__1.r = e[i__5].r + z__2.r, z__1.i = e[i__5].i + z__2.i;
	    e[i__4].r = z__1.r, e[i__4].i = z__1.i;
	}
L19:
	if (zload_1.nload > 0 || zload_1.nlodf > 0) {
	    i__4 = j;
	    i__5 = j;
	    i__6 = j - 1;
	    z__3.r = zload_1.zarray[i__6].r * curd.r - zload_1.zarray[i__6].i 
		    * curd.i, z__3.i = zload_1.zarray[i__6].r * curd.i + 
		    zload_1.zarray[i__6].i * curd.r;
	    d__1 = segj_1.ax[jx - 1] + segj_1.cx[jx - 1];
	    z__2.r = d__1 * z__3.r, z__2.i = d__1 * z__3.i;
	    z__1.r = e[i__5].r + z__2.r, z__1.i = e[i__5].i + z__2.i;
	    e[i__4].r = z__1.r, e[i__4].i = z__1.i;
	}
/* L20: */
    }
    return 0;
} /* qdsrc_ */

#undef ccjx
#undef sab
#undef ccj
#undef cab
#undef t2z
#undef t2y
#undef t2x
#undef t1z
#undef t1y
#undef t1x


/* Subroutine */ int rdpat_(void)
{
    /* Initialized data */

    static struct {
	char e_1[24];
	doublereal e_2;
	} equiv_2061 = { "LINEAR  RIGHT   LEFT    ", 0. };

#define hpol ((doublereal *)&equiv_2061)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2062 = { "        ", 0. };

#define hblk (*(doublereal *)&equiv_2062)

    static struct {
	char e_1[8];
	doublereal e_2;
	} equiv_2063 = { "CIRCLE  ", 0. };

#define hcir (*(doublereal *)&equiv_2063)

    static struct {
	char e_1[32];
	doublereal e_2;
	} equiv_2064 = { "    -   POWER   - DIRE  CTIVE   ", 0. };

#define igtp ((doublereal *)&equiv_2064)

    static struct {
	char e_1[32];
	doublereal e_2;
	} equiv_2065 = { " MAJOR   MINOR   VERT.   HOR.   ", 0. };

#define igax ((doublereal *)&equiv_2065)

    static struct {
	char e_1[80];
	doublereal e_2;
	} equiv_2066 = { " MAJOR   AXIS    MINOR   AXIS      VER  TICAL    H"
		"ORIZ  ONTAL           TOTAL   ", 0. };

#define igntp ((doublereal *)&equiv_2066)

    static doublereal pi = 3.141592654;
    static doublereal ta = .01745329252;
    static doublereal td = 57.29577951;

    /* Format strings */
    static char fmt_35[] = "(///,31x,\002- - - FAR FIELD GROUND PARAMETERS -"
	    " - -\002,//)";
    static char fmt_36[] = "(40x,\002RADIAL WIRE GROUND SCREEN\002,/,40x,i5"
	    ",\002 WIRES\002,/,40x,\002WIRE LENGTH=\002,f8.2,\002 METERS\002,"
	    "/,40x,\002WIRE RADIUS=\002,1p,e10.3,\002 METERS\002)";
    static char fmt_37[] = "(40x,a6,\002 CLIFF\002,/,40x,\002EDGE DISTANCE"
	    "=\002,f9.2,\002 METERS\002,/,40x,\002HEIGHT=\002,f8.2,\002 METERS"
	    "\002,/,40x,\002SECOND MEDIUM -\002,/,40x,\002RELATIVE DIELECTRIC"
	    " CONST.=\002,f7.3,/,40x,\002CONDUCTIVITY=\002,1p,e10.3,\002 MHO"
	    "S\002)";
    static char fmt_41[] = "(///,28x,\002 - - - RADIATED FIELDS NEAR GROUND "
	    "- - -\002,//,8x,\002- - - LOCATION - - -\002,10x,\002- - E(THETA"
	    ") - -\002,8x,\002- - E(PHI) - -\002,8x,\002- - E(RADIAL) - -\002"
	    ",/,7x,\002RHO\002,6x,\002PHI\002,9x,\002Z\002,12x,\002MAG\002,6x,"
	    "\002PHASE\002,9x,\002MAG\002,6x,\002PHASE\002,9x,\002MAG\002,6x"
	    ",\002PHASE\002,/,5x,\002METERS\002,3x,\002DEGREES\002,4x,\002MET"
	    "ERS\002,8x,\002VOLTS/M\002,3x,\002DEGREES\002,6x,\002VOLTS/M\002"
	    ",3x,\002DEGREES\002,6x,\002VOLTS/M\002,3x,\002DEGREES\002,/)";
    static char fmt_38[] = "(///,48x,\002- - - RADIATION PATTERNS - - -\002)";
    static char fmt_39[] = "(54x,\002RANGE=\002,1p,e13.6,\002 METERS\002,/,5"
	    "4x,\002EXP(-JKR)/R=\002,e12.5,\002 AT PHASE\002,0p,f7.2,\002 DEG"
	    "REES\002,/)";
    static char fmt_40[] = "(/,2x,\002- - ANGLES - -\002,7x,2a6,\002GAINS "
	    "-\002,7x,\002- - - POLARIZATION - - -\002,4x,\002- - - E(THETA) "
	    "- - -\002,4x,\002- - - E(PHI) - - -\002,/,2x,\002THETA\002,5x"
	    ",\002PHI\002,7x,a6,2x,a6,3x,\002TOTAL\002,6x,\002AXIAL\002,5x"
	    ",\002TILT\002,3x,\002SENSE\002,2(5x,\002MAGNITUDE\002,4x,\002PHA"
	    "SE \002),/,2(1x,\002DEGREES\002,1x),3(6x,\002DB\002),8x,\002RATIO"
	    "\002,5x,\002DEG.\002,8x,2(6x,\002VOLTS/M\002,4x,\002DEGREES\002))"
	    ;
    static char fmt_42[] = "(1x,f7.2,f9.2,3x,3f8.2,f11.5,f9.2,2x,a6,2(1p,e15"
	    ".5,0p,f9.2))";
    static char fmt_43[] = "(3x,f9.2,2x,f7.2,2x,f9.2,1x,3(3x,1p,e11.4,2x,0p,"
	    "f7.2))";
    static char fmt_44[] = "(//,3x,\002AVERAGE POWER GAIN=\002,1p,e12.5,7x"
	    ",\002SOLID ANGLE USED IN AVERAGING=(\002,0p,f7.4,\002)*PI STERAD"
	    "IANS.\002,//)";
    static char fmt_45[] = "(//,37x,\002- - - - NORMALIZED GAIN - - - -\002,"
	    "//,37x,2a6,\002GAIN\002,/,38x,\002NORMALIZATION FACTOR =\002,f9."
	    "2,\002 DB\002,//,3(4x,\002- - ANGLES - -\002,6x,\002GAIN\002,7x)"
	    ",/,3(4x,\002THETA\002,5x,\002PHI\002,8x,\002DB\002,8x),/,3(3x"
	    ",\002DEGREES\002,2x,\002DEGREES\002,16x))";
    static char fmt_46[] = "(3(1x,2f9.2,1x,f9.2,6x))";

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2;
    doublecomplex z__1, z__2, z__3;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void), do_fio(integer *, char *, ftnlen);
    void z_div(doublecomplex *, doublecomplex *, doublecomplex *), z_sqrt(
	    doublecomplex *, doublecomplex *);
    double d_int(doublereal *), z_abs(doublecomplex *);
    void d_cnjg(doublecomplex *, doublecomplex *);
    double sqrt(doublereal), cos(doublereal), sin(doublereal);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);

    /* Local variables */
    integer i__, j;
    doublereal da;
    extern doublereal db10_(doublereal *);
    doublereal pha;
    doublecomplex erd, eph, eth;
    doublereal phi;
    integer kph, kth;
    doublereal tha, gnv, gnh, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6;
    extern doublereal cang_(doublecomplex *);
    extern /* Subroutine */ int ffld_(doublereal *, doublereal *, 
	    doublecomplex *, doublecomplex *), gfld_(doublereal *, doublereal 
	    *, doublereal *, doublecomplex *, doublecomplex *, doublecomplex *
	    , doublecomplex *, integer *);
    doublereal erda, epha, etha, prad, gcon, gcop, gmax, exra, pint, exrm, 
	    thet, erdm, ethm, ephm, dfaz, gnmj, gnmn, gtot, dfaz2, ephm2;
    extern doublereal atgn2_(doublereal *, doublereal *);
    doublereal ethm2;
    integer itmp1, itmp2, itmp3, itmp4;
    doublereal hclif, cdfaz, tilta, axrat, isens, emajr2, eminr2, tstor1, 
	    tstor2, stilta;

    /* Fortran I/O blocks */
    static cilist io___1983 = { 0, 3, 0, fmt_35, 0 };
    static cilist io___1984 = { 0, 3, 0, fmt_36, 0 };
    static cilist io___1986 = { 0, 3, 0, fmt_37, 0 };
    static cilist io___1987 = { 0, 3, 0, fmt_41, 0 };
    static cilist io___1992 = { 0, 3, 0, fmt_38, 0 };
    static cilist io___1995 = { 0, 3, 0, fmt_39, 0 };
    static cilist io___1996 = { 0, 3, 0, fmt_40, 0 };
    static cilist io___2042 = { 0, 3, 0, fmt_42, 0 };
    static cilist io___2043 = { 0, 8, 0, 0, 0 };
    static cilist io___2044 = { 0, 8, 0, 0, 0 };
    static cilist io___2045 = { 0, 8, 0, 0, 0 };
    static cilist io___2046 = { 0, 8, 0, 0, 0 };
    static cilist io___2047 = { 0, 8, 0, 0, 0 };
    static cilist io___2048 = { 0, 8, 0, 0, 0 };
    static cilist io___2049 = { 0, 8, 0, 0, 0 };
    static cilist io___2050 = { 0, 8, 0, 0, 0 };
    static cilist io___2051 = { 0, 8, 0, 0, 0 };
    static cilist io___2052 = { 0, 8, 0, 0, 0 };
    static cilist io___2053 = { 0, 3, 0, fmt_43, 0 };
    static cilist io___2054 = { 0, 3, 0, fmt_44, 0 };
    static cilist io___2055 = { 0, 3, 0, fmt_45, 0 };
    static cilist io___2058 = { 0, 3, 0, fmt_46, 0 };
    static cilist io___2059 = { 0, 3, 0, fmt_46, 0 };
    static cilist io___2060 = { 0, 3, 0, fmt_46, 0 };


/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* Max number of segments 	(Windows-95 <= 4 */
/* max nr of 'in-core' alloc.	(MAXMAT <= MA */
/* Max number of LD cards */
/* Max number of EX cards */
/* Max number of segs connected to NT/TL */
/* *** */
/*     COMPUTE RADIATION PATTERN, GAIN, NORMALIZED GAIN */
/*     INTEGER HPOL,HBLK,HCIR,HCLIF */
/* *** */
/* *** */
    if (gnd_1.ifar < 2) {
	goto L2;
    }
    s_wsfe(&io___1983);
    e_wsfe();
    if (gnd_1.ifar <= 3) {
	goto L1;
    }
    s_wsfe(&io___1984);
    do_fio(&c__1, (char *)&gnd_1.nradl, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&save_1.scrwlt, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&save_1.scrwrt, (ftnlen)sizeof(doublereal));
    e_wsfe();
    if (gnd_1.ifar == 4) {
	goto L2;
    }
L1:
    if (gnd_1.ifar == 2 || gnd_1.ifar == 5) {
	hclif = hpol[0];
    }
    if (gnd_1.ifar == 3 || gnd_1.ifar == 6) {
	hclif = hcir;
    }
    gnd_1.cl = fpat_1.clt / data_1.wlam;
    gnd_1.ch = fpat_1.cht / data_1.wlam;
    d__1 = -fpat_1.sig2 * data_1.wlam * 59.96f;
    z__3.r = fpat_1.epsr2, z__3.i = d__1;
    z_div(&z__2, &c_b245, &z__3);
    z_sqrt(&z__1, &z__2);
    gnd_1.zrati2.r = z__1.r, gnd_1.zrati2.i = z__1.i;
    s_wsfe(&io___1986);
    do_fio(&c__1, (char *)&hclif, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&fpat_1.clt, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&fpat_1.cht, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&fpat_1.epsr2, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&fpat_1.sig2, (ftnlen)sizeof(doublereal));
    e_wsfe();
L2:
    if (gnd_1.ifar != 1) {
	goto L3;
    }
    s_wsfe(&io___1987);
    e_wsfe();
    goto L5;
L3:
    i__ = (fpat_1.ipd << 1) + 1;
    j = i__ + 1;
    itmp1 = (fpat_1.iax << 1) + 1;
    itmp2 = itmp1 + 1;
    s_wsfe(&io___1992);
    e_wsfe();
    if (fpat_1.rfld < 1e-20) {
	goto L4;
    }
    exrm = 1.f / fpat_1.rfld;
    exra = fpat_1.rfld / data_1.wlam;
    exra = (exra - d_int(&exra)) * -360.f;
    s_wsfe(&io___1995);
    do_fio(&c__1, (char *)&fpat_1.rfld, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&exrm, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&exra, (ftnlen)sizeof(doublereal));
    e_wsfe();
L4:
    s_wsfe(&io___1996);
    do_fio(&c__1, (char *)&igtp[i__ - 1], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&igtp[j - 1], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&igax[itmp1 - 1], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&igax[itmp2 - 1], (ftnlen)sizeof(doublereal));
    e_wsfe();
L5:
    if (fpat_1.ixtyp == 0 || fpat_1.ixtyp == 5) {
	goto L7;
    }
    if (fpat_1.ixtyp == 4) {
	goto L6;
    }
    prad = 0.f;
    gcon = pi * 4.f / (fpat_1.xpr6 * fpat_1.xpr6 + 1.f);
    gcop = gcon;
    goto L8;
L6:
    fpat_1.pinr = fpat_1.xpr6 * 394.51f * fpat_1.xpr6 * data_1.wlam * 
	    data_1.wlam;
L7:
    gcop = data_1.wlam * data_1.wlam * 2.f * pi / (fpat_1.pinr * 376.73f);
    prad = fpat_1.pinr - fpat_1.ploss - fpat_1.pnlr;
    gcon = gcop;
    if (fpat_1.ipd != 0) {
	gcon = gcon * fpat_1.pinr / prad;
    }
L8:
    i__ = 0;
    gmax = -1e10f;
    pint = 0.f;
    tmp1 = fpat_1.dph * ta;
    tmp2 = fpat_1.dth * .5f * ta;
    phi = fpat_1.phis - fpat_1.dph;
    i__1 = fpat_1.nph;
    for (kph = 1; kph <= i__1; ++kph) {
	phi += fpat_1.dph;
	pha = phi * ta;
	thet = fpat_1.thets - fpat_1.dth;
	i__2 = fpat_1.nth;
	for (kth = 1; kth <= i__2; ++kth) {
	    thet += fpat_1.dth;
	    if (gnd_1.ksymp == 2 && thet > 90.01f && gnd_1.ifar != 1) {
		goto L29;
	    }
	    tha = thet * ta;
	    if (gnd_1.ifar == 1) {
		goto L9;
	    }
	    ffld_(&tha, &pha, &eth, &eph);
	    goto L10;
L9:
	    d__1 = fpat_1.rfld / data_1.wlam;
	    d__2 = thet / data_1.wlam;
	    gfld_(&d__1, &pha, &d__2, &eth, &eph, &erd, &gnd_1.zrati, &
		    gnd_1.ksymp);
	    erdm = z_abs(&erd);
	    erda = cang_(&erd);
L10:
	    d_cnjg(&z__2, &eth);
	    z__1.r = eth.r * z__2.r - eth.i * z__2.i, z__1.i = eth.r * z__2.i 
		    + eth.i * z__2.r;
	    ethm2 = z__1.r;
	    ethm = sqrt(ethm2);
	    etha = cang_(&eth);
	    d_cnjg(&z__2, &eph);
	    z__1.r = eph.r * z__2.r - eph.i * z__2.i, z__1.i = eph.r * z__2.i 
		    + eph.i * z__2.r;
	    ephm2 = z__1.r;
	    ephm = sqrt(ephm2);
	    epha = cang_(&eph);
	    if (gnd_1.ifar == 1) {
		goto L28;
	    }
/*     ELLIPTICAL POLARIZATION CALC. */
	    if (ethm2 > 1e-20 || ephm2 > 1e-20) {
		goto L11;
	    }
	    tilta = 0.f;
	    emajr2 = 0.f;
	    eminr2 = 0.f;
	    axrat = 0.f;
	    isens = hblk;
	    goto L16;
L11:
	    dfaz = epha - etha;
	    if (epha < 0.f) {
		goto L12;
	    }
	    dfaz2 = dfaz - 360.f;
	    goto L13;
L12:
	    dfaz2 = dfaz + 360.f;
L13:
	    if (abs(dfaz) > abs(dfaz2)) {
		dfaz = dfaz2;
	    }
	    cdfaz = cos(dfaz * ta);
	    tstor1 = ethm2 - ephm2;
	    tstor2 = ephm * 2.f * ethm * cdfaz;
	    tilta = atgn2_(&tstor2, &tstor1) * .5f;
	    stilta = sin(tilta);
	    tstor1 = tstor1 * stilta * stilta;
	    tstor2 = tstor2 * stilta * cos(tilta);
	    emajr2 = -tstor1 + tstor2 + ethm2;
	    eminr2 = tstor1 - tstor2 + ephm2;
	    if (eminr2 < 0.f) {
		eminr2 = 0.f;
	    }
	    axrat = sqrt(eminr2 / emajr2);
	    tilta *= td;
	    if (axrat > 1e-5) {
		goto L14;
	    }
	    isens = hpol[0];
	    goto L16;
L14:
	    if (dfaz > 0.f) {
		goto L15;
	    }
	    isens = hpol[1];
	    goto L16;
L15:
	    isens = hpol[2];
L16:
	    d__1 = gcon * emajr2;
	    gnmj = db10_(&d__1);
	    d__1 = gcon * eminr2;
	    gnmn = db10_(&d__1);
	    d__1 = gcon * ethm2;
	    gnv = db10_(&d__1);
	    d__1 = gcon * ephm2;
	    gnh = db10_(&d__1);
	    d__1 = gcon * (ethm2 + ephm2);
	    gtot = db10_(&d__1);
	    if (fpat_1.inor < 1) {
		goto L23;
	    }
	    ++i__;
	    if (i__ > 6000) {
		goto L23;
	    }
	    switch (fpat_1.inor) {
		case 1:  goto L17;
		case 2:  goto L18;
		case 3:  goto L19;
		case 4:  goto L20;
		case 5:  goto L21;
	    }
L17:
	    tstor1 = gnmj;
	    goto L22;
L18:
	    tstor1 = gnmn;
	    goto L22;
L19:
	    tstor1 = gnv;
	    goto L22;
L20:
	    tstor1 = gnh;
	    goto L22;
L21:
	    tstor1 = gtot;
L22:
	    scratm_3.gain[i__ - 1] = tstor1;
	    if (tstor1 > gmax) {
		gmax = tstor1;
	    }
L23:
	    if (fpat_1.iavp == 0) {
		goto L24;
	    }
	    tstor1 = gcop * (ethm2 + ephm2);
	    tmp3 = tha - tmp2;
	    tmp4 = tha + tmp2;
	    if (kth == 1) {
		tmp3 = tha;
	    }
	    if (kth == fpat_1.nth) {
		tmp4 = tha;
	    }
	    da = (d__1 = tmp1 * (cos(tmp3) - cos(tmp4)), abs(d__1));
	    if (kph == 1 || kph == fpat_1.nph) {
		da *= .5f;
	    }
	    pint += tstor1 * da;
	    if (fpat_1.iavp == 2) {
		goto L29;
	    }
L24:
	    if (fpat_1.iax == 1) {
		goto L25;
	    }
	    tmp5 = gnmj;
	    tmp6 = gnmn;
	    goto L26;
L25:
	    tmp5 = gnv;
	    tmp6 = gnh;
L26:
	    ethm *= data_1.wlam;
	    ephm *= data_1.wlam;
	    if (fpat_1.rfld < 1e-20) {
		goto L27;
	    }
	    ethm *= exrm;
	    etha += exra;
	    ephm *= exrm;
	    epha += exra;
L27:
	    s_wsfe(&io___2042);
	    do_fio(&c__1, (char *)&thet, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&phi, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&tmp5, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&tmp6, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&gtot, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&axrat, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&tilta, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&isens, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&ethm, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&etha, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&ephm, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&epha, (ftnlen)sizeof(doublereal));
	    e_wsfe();
/*      GO TO 29 */
/* *** */
/* 28    WRITE(3,43)  RFLD,PHI,THET,ETHM,ETHA,EPHM,EPHA,ERDM,ERDA */
	    if (plot_1.iplp1 != 3) {
		goto L299;
	    }
	    if (plot_1.iplp3 == 0) {
		goto L290;
	    }
	    if (plot_1.iplp2 == 1 && plot_1.iplp3 == 1) {
		s_wsle(&io___2043);
		do_lio(&c__5, &c__1, (char *)&thet, (ftnlen)sizeof(doublereal)
			);
		do_lio(&c__5, &c__1, (char *)&ethm, (ftnlen)sizeof(doublereal)
			);
		do_lio(&c__5, &c__1, (char *)&etha, (ftnlen)sizeof(doublereal)
			);
		e_wsle();
	    }
	    if (plot_1.iplp2 == 1 && plot_1.iplp3 == 2) {
		s_wsle(&io___2044);
		do_lio(&c__5, &c__1, (char *)&thet, (ftnlen)sizeof(doublereal)
			);
		do_lio(&c__5, &c__1, (char *)&ephm, (ftnlen)sizeof(doublereal)
			);
		do_lio(&c__5, &c__1, (char *)&epha, (ftnlen)sizeof(doublereal)
			);
		e_wsle();
	    }
	    if (plot_1.iplp2 == 2 && plot_1.iplp3 == 1) {
		s_wsle(&io___2045);
		do_lio(&c__5, &c__1, (char *)&phi, (ftnlen)sizeof(doublereal))
			;
		do_lio(&c__5, &c__1, (char *)&ethm, (ftnlen)sizeof(doublereal)
			);
		do_lio(&c__5, &c__1, (char *)&etha, (ftnlen)sizeof(doublereal)
			);
		e_wsle();
	    }
	    if (plot_1.iplp2 == 2 && plot_1.iplp3 == 2) {
		s_wsle(&io___2046);
		do_lio(&c__5, &c__1, (char *)&phi, (ftnlen)sizeof(doublereal))
			;
		do_lio(&c__5, &c__1, (char *)&ephm, (ftnlen)sizeof(doublereal)
			);
		do_lio(&c__5, &c__1, (char *)&epha, (ftnlen)sizeof(doublereal)
			);
		e_wsle();
	    }
	    if (plot_1.iplp4 == 0) {
		goto L299;
	    }
L290:
	    if (plot_1.iplp2 == 1 && plot_1.iplp4 == 1) {
		s_wsle(&io___2047);
		do_lio(&c__5, &c__1, (char *)&thet, (ftnlen)sizeof(doublereal)
			);
		do_lio(&c__5, &c__1, (char *)&tmp5, (ftnlen)sizeof(doublereal)
			);
		e_wsle();
	    }
	    if (plot_1.iplp2 == 1 && plot_1.iplp4 == 2) {
		s_wsle(&io___2048);
		do_lio(&c__5, &c__1, (char *)&thet, (ftnlen)sizeof(doublereal)
			);
		do_lio(&c__5, &c__1, (char *)&tmp6, (ftnlen)sizeof(doublereal)
			);
		e_wsle();
	    }
	    if (plot_1.iplp2 == 1 && plot_1.iplp4 == 3) {
		s_wsle(&io___2049);
		do_lio(&c__5, &c__1, (char *)&thet, (ftnlen)sizeof(doublereal)
			);
		do_lio(&c__5, &c__1, (char *)&gtot, (ftnlen)sizeof(doublereal)
			);
		e_wsle();
	    }
	    if (plot_1.iplp2 == 2 && plot_1.iplp4 == 1) {
		s_wsle(&io___2050);
		do_lio(&c__5, &c__1, (char *)&phi, (ftnlen)sizeof(doublereal))
			;
		do_lio(&c__5, &c__1, (char *)&tmp5, (ftnlen)sizeof(doublereal)
			);
		e_wsle();
	    }
	    if (plot_1.iplp2 == 2 && plot_1.iplp4 == 2) {
		s_wsle(&io___2051);
		do_lio(&c__5, &c__1, (char *)&phi, (ftnlen)sizeof(doublereal))
			;
		do_lio(&c__5, &c__1, (char *)&tmp6, (ftnlen)sizeof(doublereal)
			);
		e_wsle();
	    }
	    if (plot_1.iplp2 == 2 && plot_1.iplp4 == 3) {
		s_wsle(&io___2052);
		do_lio(&c__5, &c__1, (char *)&phi, (ftnlen)sizeof(doublereal))
			;
		do_lio(&c__5, &c__1, (char *)&gtot, (ftnlen)sizeof(doublereal)
			);
		e_wsle();
	    }
	    goto L299;
L28:
	    s_wsfe(&io___2053);
	    do_fio(&c__1, (char *)&fpat_1.rfld, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&phi, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&thet, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&ethm, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&etha, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&ephm, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&epha, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&erdm, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&erda, (ftnlen)sizeof(doublereal));
	    e_wsfe();
L299:
/* *** */
L29:
	    ;
	}
    }
    if (fpat_1.iavp == 0) {
	goto L30;
    }
    tmp3 = fpat_1.thets * ta;
    tmp4 = tmp3 + fpat_1.dth * ta * (doublereal) (fpat_1.nth - 1);
    tmp3 = (d__1 = fpat_1.dph * ta * (doublereal) (fpat_1.nph - 1) * (cos(
	    tmp3) - cos(tmp4)), abs(d__1));
    pint /= tmp3;
    tmp3 /= pi;
    s_wsfe(&io___2054);
    do_fio(&c__1, (char *)&pint, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&tmp3, (ftnlen)sizeof(doublereal));
    e_wsfe();
L30:
    if (fpat_1.inor == 0) {
	goto L34;
    }
    if (abs(fpat_1.gnor) > 1e-20) {
	gmax = fpat_1.gnor;
    }
    itmp1 = (fpat_1.inor - 1 << 1) + 1;
    itmp2 = itmp1 + 1;
    s_wsfe(&io___2055);
    do_fio(&c__1, (char *)&igntp[itmp1 - 1], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&igntp[itmp2 - 1], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&gmax, (ftnlen)sizeof(doublereal));
    e_wsfe();
    itmp2 = fpat_1.nph * fpat_1.nth;
    if (itmp2 > 6000) {
	itmp2 = 6000;
    }
    itmp1 = (itmp2 + 2) / 3;
    itmp2 = itmp1 * 3 - itmp2;
    itmp3 = itmp1;
    itmp4 = itmp1 << 1;
    if (itmp2 == 2) {
	--itmp4;
    }
    i__2 = itmp1;
    for (i__ = 1; i__ <= i__2; ++i__) {
	++itmp3;
	++itmp4;
	j = (i__ - 1) / fpat_1.nth;
	tmp1 = fpat_1.thets + (doublereal) (i__ - j * fpat_1.nth - 1) * 
		fpat_1.dth;
	tmp2 = fpat_1.phis + (doublereal) j * fpat_1.dph;
	j = (itmp3 - 1) / fpat_1.nth;
	tmp3 = fpat_1.thets + (doublereal) (itmp3 - j * fpat_1.nth - 1) * 
		fpat_1.dth;
	tmp4 = fpat_1.phis + (doublereal) j * fpat_1.dph;
	j = (itmp4 - 1) / fpat_1.nth;
	tmp5 = fpat_1.thets + (doublereal) (itmp4 - j * fpat_1.nth - 1) * 
		fpat_1.dth;
	tmp6 = fpat_1.phis + (doublereal) j * fpat_1.dph;
	tstor1 = scratm_3.gain[i__ - 1] - gmax;
	if (i__ == itmp1 && itmp2 != 0) {
	    goto L32;
	}
	tstor2 = scratm_3.gain[itmp3 - 1] - gmax;
	pint = scratm_3.gain[itmp4 - 1] - gmax;
/* L31: */
	s_wsfe(&io___2058);
	do_fio(&c__1, (char *)&tmp1, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&tmp2, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&tstor1, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&tmp3, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&tmp4, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&tstor2, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&tmp5, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&tmp6, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&pint, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    goto L34;
L32:
    if (itmp2 == 2) {
	goto L33;
    }
    tstor2 = scratm_3.gain[itmp3 - 1] - gmax;
    s_wsfe(&io___2059);
    do_fio(&c__1, (char *)&tmp1, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&tmp2, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&tstor1, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&tmp3, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&tmp4, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&tstor2, (ftnlen)sizeof(doublereal));
    e_wsfe();
    goto L34;
L33:
    s_wsfe(&io___2060);
    do_fio(&c__1, (char *)&tmp1, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&tmp2, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&tstor1, (ftnlen)sizeof(doublereal));
    e_wsfe();
L34:
    return 0;

} /* rdpat_ */

#undef igntp
#undef igax
#undef igtp
#undef hcir
#undef hblk
#undef hpol


/* Subroutine */ int readgm_(integer *inunit__, char *code, integer *i1, 
	integer *i2, doublereal *r1, doublereal *r2, doublereal *r3, 
	doublereal *r4, doublereal *r5, doublereal *r6, doublereal *r7, 
	ftnlen code_len)
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer ieof;
    doublereal reaval[7];
    integer intval[2];
    extern /* Subroutine */ int parsit_(integer *, integer *, integer *, char 
	    *, integer *, doublereal *, integer *, ftnlen);


/*  READGM reads a geometry record and parses it. */

/*  *****  Passed variables */
/*     CODE        two letter mnemonic code */
/*     I1 - I2     integer values from record */
/*     R1 - R7     real values from record */


/*  Call the routine to read the record and parse it. */

    parsit_(inunit__, &c__2, &c__7, code, intval, reaval, &ieof, code_len);

/*  Set the return variables to the buffer array elements. */

    if (ieof < 0) {
	s_copy(code, "GE", code_len, (ftnlen)2);
    }
    *i1 = intval[0];
    *i2 = intval[1];
    *r1 = reaval[0];
    *r2 = reaval[1];
    *r3 = reaval[2];
    *r4 = reaval[3];
    *r5 = reaval[4];
    *r6 = reaval[5];
    *r7 = reaval[6];
    return 0;
} /* readgm_ */

/* Subroutine */ int readmn_(integer *inunit__, char *code, integer *i1, 
	integer *i2, integer *i3, integer *i4, doublereal *f1, doublereal *f2,
	 doublereal *f3, doublereal *f4, doublereal *f5, doublereal *f6, 
	ftnlen code_len)
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    integer ieof;
    doublereal reaval[6];
    integer intval[4];
    extern /* Subroutine */ int parsit_(integer *, integer *, integer *, char 
	    *, integer *, doublereal *, integer *, ftnlen);


/*  READMN reads a control record and parses it. */


/*  Call the routine to read the record and parse it. */

    parsit_(inunit__, &c__4, &c__6, code, intval, reaval, &ieof, code_len);

/*  Set the return variables to the buffer array elements. */
    if (ieof < 0) {
	s_copy(code, "EN", code_len, (ftnlen)2);
    }
    *i1 = intval[0];
    *i2 = intval[1];
    *i3 = intval[2];
    *i4 = intval[3];
    *f1 = reaval[0];
    *f2 = reaval[1];
    *f3 = reaval[2];
    *f4 = reaval[3];
    *f5 = reaval[4];
    *f6 = reaval[5];
    return 0;
} /* readmn_ */

/* Subroutine */ int parsit_(integer *inunit__, integer *maxint, integer *
	maxrea, char *cmnd, integer *intfld, doublereal *reafld, integer *
	ieof, ftnlen cmnd_len)
{
    /* Format strings */
    static char fmt_8000[] = "(a80)";
    static char fmt_8001[] = "(//,\002 ***** CARD ERROR - TOO MANY FIELDS IN"
	    " RECORD\002)";
    static char fmt_8002[] = "(//,\002 ***** CARD ERROR - INVALID NUMBER AT "
	    "INTEGER\002,\002 POSITION \002,i1)";
    static char fmt_8003[] = "(//,\002 ***** CARD ERROR - INVALID NUMBER AT "
	    "REAL\002,\002 POSITION \002,i1)";
    static char fmt_8004[] = "(\002 ***** TEXT -->  \002,a80)";

    /* System generated locals */
    address a__1[3];
    integer i__1, i__2, i__3[3];
    icilist ici__1;

    /* Builtin functions */
    integer s_rsfe(cilist *), do_fio(integer *, char *, ftnlen), e_rsfe(void);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), e_wsfe(void), i_indx(char *, char *, ftnlen, 
	    ftnlen), s_rsli(icilist *), do_lio(integer *, integer *, char *, 
	    ftnlen), e_rsli(void);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen),
	     s_stop(char *, ftnlen);

    /* Local variables */
    integer i__, j, k;
    char rec[80];
    integer ind, inde, last, bgnfld[12], endfld[12];
    char buffer[20];
    extern /* Subroutine */ int upcase_(char *, char *, integer *, ftnlen, 
	    ftnlen);
    integer length;
    logical fldtrm;
    integer totfld, totcol;

    /* Fortran I/O blocks */
    static cilist io___2073 = { 1, 0, 1, fmt_8000, 0 };
    static cilist io___2084 = { 0, 3, 0, fmt_8001, 0 };
    static cilist io___2089 = { 0, 3, 0, fmt_8002, 0 };
    static cilist io___2090 = { 0, 3, 0, fmt_8003, 0 };
    static cilist io___2091 = { 0, 3, 0, fmt_8004, 0 };


/*  UPDATED:  21 July 87 */
/*  Called by:   READGM    READMN */
/*  PARSIT reads an input record and parses it. */
/*  *****  Passed variables */
/*     MAXINT     total number of integers in record */
/*     MAXREA     total number of real values in record */
/*     CMND       two letter mnemonic code */
/*     INTFLD     integer values from record */
/*     REAFLD     real values from record */
/*  *****  Internal Variables */
/*     BGNFLD     list of starting indices */
/*     BUFFER     text buffer */
/*     ENDFLD     list of ending indices */
/*     FLDTRM     flag to indicate that pointer is in field position */
/*     REC        input line as read */
/*     TOTCOL     total number of columns in REC */
/*     TOTFLD     number of numeric fields */

    /* Parameter adjustments */
    --intfld;
    --reafld;

    /* Function Body */
    io___2073.ciunit = *inunit__;
    *ieof = s_rsfe(&io___2073);
    if (*ieof != 0) {
	goto L100003;
    }
    *ieof = do_fio(&c__1, rec, (ftnlen)80);
    if (*ieof != 0) {
	goto L100003;
    }
    *ieof = e_rsfe();
L100003:
    upcase_(rec, rec, &totcol, (ftnlen)80, (ftnlen)80);

/*  Store opcode and clear field arrays. */

    s_copy(cmnd, rec, (ftnlen)2, (ftnlen)2);
    i__1 = *maxint;
    for (i__ = 1; i__ <= i__1; ++i__) {
	intfld[i__] = 0;
/* L3000: */
    }
    i__1 = *maxrea;
    for (i__ = 1; i__ <= i__1; ++i__) {
	reafld[i__] = 0.f;
/* L3010: */
    }
    for (i__ = 1; i__ <= 12; ++i__) {
	bgnfld[i__ - 1] = 0;
	endfld[i__ - 1] = 0;
/* L3020: */
    }

/*  Find the beginning and ending of each field as well as the total number of */
/*  fields. */

    totfld = 0;
    fldtrm = FALSE_;
    last = *maxrea + *maxint;
    i__1 = totcol;
    for (j = 3; j <= i__1; ++j) {
	k = *(unsigned char *)&rec[j - 1];

/*  Check for end of line comment (`!').  This is a new modification to allow */
/*  VAX-like comments at the end of data records, i.e. */
/*       GW 1 7 0 0 0 0 0 .5 .0001 ! DIPOLE WIRE */
/*       GE ! END OF GEOMETRY */

	if (k == 33) {
	    if (fldtrm) {
		endfld[totfld - 1] = j - 1;
	    }
	    goto L5000;

/*  Set the ending index when the character is a comma or space and the pointer */
/*  is in a field position (FLDTRM = .TRUE.). */

	} else if (k == 32 || k == 44) {
	    if (fldtrm) {
		endfld[totfld - 1] = j - 1;
		fldtrm = FALSE_;
	    }

/*  Set the beginning index when the character is not a comma or space and the */
/*  pointer is not currently in a field position (FLDTRM = .FALSE). */

	} else if (! fldtrm) {
	    ++totfld;
	    fldtrm = TRUE_;
	    bgnfld[totfld - 1] = j;
	}
/* L4000: */
    }
    if (fldtrm) {
	endfld[totfld - 1] = totcol;
    }
/*  Check to see if the total number of value fields is within the precribed */
/*  limits. */
L5000:
    if (totfld == 0) {
	return 0;
    } else if (totfld > last) {
	s_wsfe(&io___2084);
	e_wsfe();
	goto L9010;
    }
    j = min(totfld,*maxint);
/*  Parse out integer values and store into integer buffer array. */
    i__1 = j;
    for (i__ = 1; i__ <= i__1; ++i__) {
	length = endfld[i__ - 1] - bgnfld[i__ - 1] + 1;
	i__2 = bgnfld[i__ - 1] - 1;
	s_copy(buffer, rec + i__2, (ftnlen)20, endfld[i__ - 1] - i__2);
	ind = i_indx(buffer, ".", length, (ftnlen)1);
	if (ind > 0 && ind < length) {
	    goto L9000;
	}
	if (ind == length) {
	    --length;
	}
	ici__1.icierr = 1;
	ici__1.iciend = 0;
	ici__1.icirnum = 1;
	ici__1.icirlen = length;
	ici__1.iciunit = buffer;
	ici__1.icifmt = 0;
	i__2 = s_rsli(&ici__1);
	if (i__2 != 0) {
	    goto L9000;
	}
	i__2 = do_lio(&c__3, &c__1, (char *)&intfld[i__], (ftnlen)sizeof(
		integer));
	if (i__2 != 0) {
	    goto L9000;
	}
	i__2 = e_rsli();
	if (i__2 != 0) {
	    goto L9000;
	}
/* L5090: */
    }
/*  Parse out real values and store into real buffer array. */
    if (totfld > *maxint) {
	j = *maxint + 1;
	i__1 = totfld;
	for (i__ = j; i__ <= i__1; ++i__) {
	    length = endfld[i__ - 1] - bgnfld[i__ - 1] + 1;
	    i__2 = bgnfld[i__ - 1] - 1;
	    s_copy(buffer, rec + i__2, (ftnlen)20, endfld[i__ - 1] - i__2);
	    ind = i_indx(buffer, ".", length, (ftnlen)1);
	    if (ind == 0) {
		inde = i_indx(buffer, "E", length, (ftnlen)1);
		++length;
		if (inde == 0) {
		    *(unsigned char *)&buffer[length - 1] = '.';
		} else {
/* Writing concatenation */
		    i__3[0] = inde - 1, a__1[0] = buffer;
		    i__3[1] = 1, a__1[1] = ".";
		    i__3[2] = length - 1 - (inde - 1), a__1[2] = buffer + (
			    inde - 1);
		    s_cat(buffer, a__1, i__3, &c__3, (ftnlen)20);
		}
	    }
	    ici__1.icierr = 1;
	    ici__1.iciend = 0;
	    ici__1.icirnum = 1;
	    ici__1.icirlen = length;
	    ici__1.iciunit = buffer;
	    ici__1.icifmt = 0;
	    i__2 = s_rsli(&ici__1);
	    if (i__2 != 0) {
		goto L9000;
	    }
	    i__2 = do_lio(&c__5, &c__1, (char *)&reafld[i__ - *maxint], (
		    ftnlen)sizeof(doublereal));
	    if (i__2 != 0) {
		goto L9000;
	    }
	    i__2 = e_rsli();
	    if (i__2 != 0) {
		goto L9000;
	    }
/* L6000: */
	}
    }
    return 0;
/*  Print out text of record line when error occurs. */
L9000:
    if (i__ <= *maxint) {
	s_wsfe(&io___2089);
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	e_wsfe();
    } else {
	i__ -= *maxint;
	s_wsfe(&io___2090);
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	e_wsfe();
    }
L9010:
    s_wsfe(&io___2091);
    do_fio(&c__1, rec, (ftnlen)80);
    e_wsfe();
    s_stop("CARD ERROR", (ftnlen)10);

/*  Input formats and output messages. */

    return 0;
} /* parsit_ */

/* Subroutine */ int upcase_(char *intext, char *outtxt, integer *length, 
	ftnlen intext_len, ftnlen outtxt_len)
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer i_len(char *, ftnlen);

    /* Local variables */
    integer i__, j;


/*  UPCASE finds the length of INTEXT and converts it to upper case. */



    *length = i_len(intext, intext_len);
    i__1 = *length;
    for (i__ = 1; i__ <= i__1; ++i__) {
	j = *(unsigned char *)&intext[i__ - 1];
	if (j >= 96) {
	    j += -32;
	}
	*(unsigned char *)&outtxt[i__ - 1] = (char) j;
/* L3000: */
    }
    return 0;
} /* upcase_ */

/* Subroutine */ int reblk_(doublecomplex *b, doublecomplex *bx, integer *nb, 
	integer *nbx, integer *n2c)
{
    /* System generated locals */
    integer b_dim1, b_offset, bx_dim1, bx_offset, i__1, i__2, i__3, i__4, 
	    i__5, i__6;
    alist al__1;

    /* Builtin functions */
    integer f_rew(alist *), s_rsue(cilist *), do_uio(integer *, char *, 
	    ftnlen), e_rsue(void), s_wsue(cilist *), e_wsue(void);

    /* Local variables */
    integer i__, j, ib, ix, nib, npb, ibx, nix, npx;

    /* Fortran I/O blocks */
    static cilist io___2100 = { 0, 14, 0, 0, 0 };
    static cilist io___2104 = { 0, 16, 0, 0, 0 };


/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* *** */
/*     REBLOCK ARRAY B IN N.G.F. SOLUTION FROM BLOCKS OF ROWS ON TAPE14 */
/*     TO BLOCKS OF COLUMNS ON TAPE16 */
    /* Parameter adjustments */
    b_dim1 = *nb;
    b_offset = 1 + b_dim1;
    b -= b_offset;
    bx_dim1 = *nbx;
    bx_offset = 1 + bx_dim1;
    bx -= bx_offset;

    /* Function Body */
    al__1.aerr = 0;
    al__1.aunit = 16;
    f_rew(&al__1);
    nib = 0;
    npb = matpar_1.npbl;
    i__1 = matpar_1.nbbl;
    for (ib = 1; ib <= i__1; ++ib) {
	if (ib == matpar_1.nbbl) {
	    npb = matpar_1.nlbl;
	}
	al__1.aerr = 0;
	al__1.aunit = 14;
	f_rew(&al__1);
	nix = 0;
	npx = matpar_1.npbx;
	i__2 = matpar_1.nbbx;
	for (ibx = 1; ibx <= i__2; ++ibx) {
	    if (ibx == matpar_1.nbbx) {
		npx = matpar_1.nlbx;
	    }
	    s_rsue(&io___2100);
	    i__3 = *n2c;
	    for (j = 1; j <= i__3; ++j) {
		i__4 = npx;
		for (i__ = 1; i__ <= i__4; ++i__) {
		    do_uio(&c__2, (char *)&bx[i__ + j * bx_dim1], (ftnlen)
			    sizeof(doublereal));
		}
	    }
	    e_rsue();
	    i__4 = npx;
	    for (i__ = 1; i__ <= i__4; ++i__) {
		ix = i__ + nix;
		i__3 = npb;
		for (j = 1; j <= i__3; ++j) {
/* L1: */
		    i__5 = ix + j * b_dim1;
		    i__6 = i__ + (j + nib) * bx_dim1;
		    b[i__5].r = bx[i__6].r, b[i__5].i = bx[i__6].i;
		}
	    }
/* L2: */
	    nix += matpar_1.npbx;
	}
	s_wsue(&io___2104);
	i__2 = npb;
	for (j = 1; j <= i__2; ++j) {
	    i__5 = *nb;
	    for (i__ = 1; i__ <= i__5; ++i__) {
		do_uio(&c__2, (char *)&b[i__ + j * b_dim1], (ftnlen)sizeof(
			doublereal));
	    }
	}
	e_wsue();
/* L3: */
	nib += matpar_1.npbl;
    }
    al__1.aerr = 0;
    al__1.aunit = 14;
    f_rew(&al__1);
    al__1.aerr = 0;
    al__1.aunit = 16;
    f_rew(&al__1);
    return 0;
} /* reblk_ */

/* Subroutine */ int reflc_(integer *ix, integer *iy, integer *iz, integer *
	itx, integer *nop)
{
    /* Format strings */
    static char fmt_24[] = "(\002 GEOMETRY DATA ERROR--SEGMENT\002,i5,\002 L"
	    "IES IN PLANE OF SYMMETRY\002)";
    static char fmt_25[] = "(\002 GEOMETRY DATA ERROR--PATCH\002,i4,\002 LIE"
	    "S IN PLANE OF SYMMETRY\002)";

    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);
    double cos(doublereal), sin(doublereal);

    /* Local variables */
    integer i__, j, k;
    doublereal e1, e2;
#define x2 ((doublereal *)&data_1 + 4500)
#define y2 ((doublereal *)&data_1 + 7500)
#define z2 ((doublereal *)&data_1 + 9000)
    doublereal cs, xk, yk;
    integer nx;
    doublereal ss;
#define t1x ((doublereal *)&data_1 + 4500)
#define t1y ((doublereal *)&data_1 + 7500)
#define t1z ((doublereal *)&data_1 + 9000)
#define t2x ((doublereal *)&data_1 + 10501)
#define t2y ((doublereal *)&data_1 + 12001)
#define t2z ((doublereal *)&data_1 + 13501)
    doublereal sam;
    integer iti, nxx;
    doublereal fnop;
    integer itagi;

    /* Fortran I/O blocks */
    static cilist io___2119 = { 0, 3, 0, fmt_24, 0 };
    static cilist io___2122 = { 0, 3, 0, fmt_25, 0 };
    static cilist io___2123 = { 0, 3, 0, fmt_24, 0 };
    static cilist io___2124 = { 0, 3, 0, fmt_25, 0 };
    static cilist io___2125 = { 0, 3, 0, fmt_24, 0 };
    static cilist io___2126 = { 0, 3, 0, fmt_25, 0 };


/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* Max number of segments 	(Windows-95 <= 4 */
/* max nr of 'in-core' alloc.	(MAXMAT <= MA */
/* Max number of LD cards */
/* Max number of EX cards */
/* Max number of segs connected to NT/TL */
/* *** */

/*     REFLC REFLECTS PARTIAL STRUCTURE ALONG X,Y, OR Z AXES OR ROTATES */
/*     STRUCTURE TO COMPLETE A SYMMETRIC STRUCTURE. */

    data_1.np = data_1.n;
    data_1.mp = data_1.m;
    data_1.ipsym = 0;
    iti = *itx;
    if (*ix < 0) {
	goto L19;
    }
    if (*nop == 0) {
	return 0;
    }
    data_1.ipsym = 1;
    if (*iz == 0) {
	goto L6;
    }

/*     REFLECT ALONG Z AXIS */

    data_1.ipsym = 2;
    if (data_1.n < data_1.n2) {
	goto L3;
    }
    i__1 = data_1.n;
    for (i__ = data_1.n2; i__ <= i__1; ++i__) {
	nx = i__ + data_1.n - data_1.n1;
	e1 = data_1.z__[i__ - 1];
	e2 = z2[i__ - 1];
	if (abs(e1) + abs(e2) > 1e-5 && e1 * e2 >= -1e-6) {
	    goto L1;
	}
	s_wsfe(&io___2119);
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	e_wsfe();
	s_stop("", (ftnlen)0);
L1:
	data_1.x[nx - 1] = data_1.x[i__ - 1];
	data_1.y[nx - 1] = data_1.y[i__ - 1];
	data_1.z__[nx - 1] = -e1;
	x2[nx - 1] = x2[i__ - 1];
	y2[nx - 1] = y2[i__ - 1];
	z2[nx - 1] = -e2;
	itagi = data_1.itag[i__ - 1];
	if (itagi == 0) {
	    data_1.itag[nx - 1] = 0;
	}
	if (itagi != 0) {
	    data_1.itag[nx - 1] = itagi + iti;
	}
/* L2: */
	data_1.bi[nx - 1] = data_1.bi[i__ - 1];
    }
    data_1.n = (data_1.n << 1) - data_1.n1;
    iti <<= 1;
L3:
    if (data_1.m < data_1.m2) {
	goto L6;
    }
    nxx = data_1.ld + 1 - data_1.m1;
    i__1 = data_1.m;
    for (i__ = data_1.m2; i__ <= i__1; ++i__) {
	--nxx;
	nx = nxx - data_1.m + data_1.m1;
	if ((d__1 = data_1.z__[nxx - 1], abs(d__1)) > 1e-10) {
	    goto L4;
	}
	s_wsfe(&io___2122);
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	e_wsfe();
	s_stop("", (ftnlen)0);
L4:
	data_1.x[nx - 1] = data_1.x[nxx - 1];
	data_1.y[nx - 1] = data_1.y[nxx - 1];
	data_1.z__[nx - 1] = -data_1.z__[nxx - 1];
	t1x[nx - 1] = t1x[nxx - 1];
	t1y[nx - 1] = t1y[nxx - 1];
	t1z[nx - 1] = -t1z[nxx - 1];
	t2x[nx - 1] = t2x[nxx - 1];
	t2y[nx - 1] = t2y[nxx - 1];
	t2z[nx - 1] = -t2z[nxx - 1];
	angl_1.salp[nx - 1] = -angl_1.salp[nxx - 1];
/* L5: */
	data_1.bi[nx - 1] = data_1.bi[nxx - 1];
    }
    data_1.m = (data_1.m << 1) - data_1.m1;
L6:
    if (*iy == 0) {
	goto L12;
    }

/*     REFLECT ALONG Y AXIS */

    if (data_1.n < data_1.n2) {
	goto L9;
    }
    i__1 = data_1.n;
    for (i__ = data_1.n2; i__ <= i__1; ++i__) {
	nx = i__ + data_1.n - data_1.n1;
	e1 = data_1.y[i__ - 1];
	e2 = y2[i__ - 1];
	if (abs(e1) + abs(e2) > 1e-5 && e1 * e2 >= -1e-6) {
	    goto L7;
	}
	s_wsfe(&io___2123);
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	e_wsfe();
	s_stop("", (ftnlen)0);
L7:
	data_1.x[nx - 1] = data_1.x[i__ - 1];
	data_1.y[nx - 1] = -e1;
	data_1.z__[nx - 1] = data_1.z__[i__ - 1];
	x2[nx - 1] = x2[i__ - 1];
	y2[nx - 1] = -e2;
	z2[nx - 1] = z2[i__ - 1];
	itagi = data_1.itag[i__ - 1];
	if (itagi == 0) {
	    data_1.itag[nx - 1] = 0;
	}
	if (itagi != 0) {
	    data_1.itag[nx - 1] = itagi + iti;
	}
/* L8: */
	data_1.bi[nx - 1] = data_1.bi[i__ - 1];
    }
    data_1.n = (data_1.n << 1) - data_1.n1;
    iti <<= 1;
L9:
    if (data_1.m < data_1.m2) {
	goto L12;
    }
    nxx = data_1.ld + 1 - data_1.m1;
    i__1 = data_1.m;
    for (i__ = data_1.m2; i__ <= i__1; ++i__) {
	--nxx;
	nx = nxx - data_1.m + data_1.m1;
	if ((d__1 = data_1.y[nxx - 1], abs(d__1)) > 1e-10) {
	    goto L10;
	}
	s_wsfe(&io___2124);
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	e_wsfe();
	s_stop("", (ftnlen)0);
L10:
	data_1.x[nx - 1] = data_1.x[nxx - 1];
	data_1.y[nx - 1] = -data_1.y[nxx - 1];
	data_1.z__[nx - 1] = data_1.z__[nxx - 1];
	t1x[nx - 1] = t1x[nxx - 1];
	t1y[nx - 1] = -t1y[nxx - 1];
	t1z[nx - 1] = t1z[nxx - 1];
	t2x[nx - 1] = t2x[nxx - 1];
	t2y[nx - 1] = -t2y[nxx - 1];
	t2z[nx - 1] = t2z[nxx - 1];
	angl_1.salp[nx - 1] = -angl_1.salp[nxx - 1];
/* L11: */
	data_1.bi[nx - 1] = data_1.bi[nxx - 1];
    }
    data_1.m = (data_1.m << 1) - data_1.m1;
L12:
    if (*ix == 0) {
	goto L18;
    }

/*     REFLECT ALONG X AXIS */

    if (data_1.n < data_1.n2) {
	goto L15;
    }
    i__1 = data_1.n;
    for (i__ = data_1.n2; i__ <= i__1; ++i__) {
	nx = i__ + data_1.n - data_1.n1;
	e1 = data_1.x[i__ - 1];
	e2 = x2[i__ - 1];
	if (abs(e1) + abs(e2) > 1e-5 && e1 * e2 >= -1e-6) {
	    goto L13;
	}
	s_wsfe(&io___2125);
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	e_wsfe();
	s_stop("", (ftnlen)0);
L13:
	data_1.x[nx - 1] = -e1;
	data_1.y[nx - 1] = data_1.y[i__ - 1];
	data_1.z__[nx - 1] = data_1.z__[i__ - 1];
	x2[nx - 1] = -e2;
	y2[nx - 1] = y2[i__ - 1];
	z2[nx - 1] = z2[i__ - 1];
	itagi = data_1.itag[i__ - 1];
	if (itagi == 0) {
	    data_1.itag[nx - 1] = 0;
	}
	if (itagi != 0) {
	    data_1.itag[nx - 1] = itagi + iti;
	}
/* L14: */
	data_1.bi[nx - 1] = data_1.bi[i__ - 1];
    }
    data_1.n = (data_1.n << 1) - data_1.n1;
L15:
    if (data_1.m < data_1.m2) {
	goto L18;
    }
    nxx = data_1.ld + 1 - data_1.m1;
    i__1 = data_1.m;
    for (i__ = data_1.m2; i__ <= i__1; ++i__) {
	--nxx;
	nx = nxx - data_1.m + data_1.m1;
	if ((d__1 = data_1.x[nxx - 1], abs(d__1)) > 1e-10) {
	    goto L16;
	}
	s_wsfe(&io___2126);
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	e_wsfe();
	s_stop("", (ftnlen)0);
L16:
	data_1.x[nx - 1] = -data_1.x[nxx - 1];
	data_1.y[nx - 1] = data_1.y[nxx - 1];
	data_1.z__[nx - 1] = data_1.z__[nxx - 1];
	t1x[nx - 1] = -t1x[nxx - 1];
	t1y[nx - 1] = t1y[nxx - 1];
	t1z[nx - 1] = t1z[nxx - 1];
	t2x[nx - 1] = -t2x[nxx - 1];
	t2y[nx - 1] = t2y[nxx - 1];
	t2z[nx - 1] = t2z[nxx - 1];
	angl_1.salp[nx - 1] = -angl_1.salp[nxx - 1];
/* L17: */
	data_1.bi[nx - 1] = data_1.bi[nxx - 1];
    }
    data_1.m = (data_1.m << 1) - data_1.m1;
L18:
    return 0;

/*     REPRODUCE STRUCTURE WITH ROTATION TO FORM CYLINDRICAL STRUCTURE */

L19:
    fnop = (doublereal) (*nop);
    data_1.ipsym = -1;
    sam = 6.283185308 / fnop;
    cs = cos(sam);
    ss = sin(sam);
    if (data_1.n < data_1.n2) {
	goto L21;
    }
    data_1.n = data_1.n1 + (data_1.n - data_1.n1) * *nop;
    nx = data_1.np + 1;
    i__1 = data_1.n;
    for (i__ = nx; i__ <= i__1; ++i__) {
	k = i__ - data_1.np + data_1.n1;
	xk = data_1.x[k - 1];
	yk = data_1.y[k - 1];
	data_1.x[i__ - 1] = xk * cs - yk * ss;
	data_1.y[i__ - 1] = xk * ss + yk * cs;
	data_1.z__[i__ - 1] = data_1.z__[k - 1];
	xk = x2[k - 1];
	yk = y2[k - 1];
	x2[i__ - 1] = xk * cs - yk * ss;
	y2[i__ - 1] = xk * ss + yk * cs;
	z2[i__ - 1] = z2[k - 1];
	itagi = data_1.itag[k - 1];
	if (itagi == 0) {
	    data_1.itag[i__ - 1] = 0;
	}
	if (itagi != 0) {
	    data_1.itag[i__ - 1] = itagi + iti;
	}
/* L20: */
	data_1.bi[i__ - 1] = data_1.bi[k - 1];
    }
L21:
    if (data_1.m < data_1.m2) {
	goto L23;
    }
    data_1.m = data_1.m1 + (data_1.m - data_1.m1) * *nop;
    nx = data_1.mp + 1;
    k = data_1.ld + 1 - data_1.m1;
    i__1 = data_1.m;
    for (i__ = nx; i__ <= i__1; ++i__) {
	--k;
	j = k - data_1.mp + data_1.m1;
	xk = data_1.x[k - 1];
	yk = data_1.y[k - 1];
	data_1.x[j - 1] = xk * cs - yk * ss;
	data_1.y[j - 1] = xk * ss + yk * cs;
	data_1.z__[j - 1] = data_1.z__[k - 1];
	xk = t1x[k - 1];
	yk = t1y[k - 1];
	t1x[j - 1] = xk * cs - yk * ss;
	t1y[j - 1] = xk * ss + yk * cs;
	t1z[j - 1] = t1z[k - 1];
	xk = t2x[k - 1];
	yk = t2y[k - 1];
	t2x[j - 1] = xk * cs - yk * ss;
	t2y[j - 1] = xk * ss + yk * cs;
	t2z[j - 1] = t2z[k - 1];
	angl_1.salp[j - 1] = angl_1.salp[k - 1];
/* L22: */
	data_1.bi[j - 1] = data_1.bi[k - 1];
    }
L23:
    return 0;

} /* reflc_ */

#undef t2z
#undef t2y
#undef t2x
#undef t1z
#undef t1y
#undef t1x
#undef z2
#undef y2
#undef x2


/* Subroutine */ int rom2_(doublereal *a, doublereal *b, doublecomplex *sum, 
	doublereal *dmin__)
{
    /* Initialized data */

    static integer nm = 65536;
    static integer nts = 4;
    static integer nx = 1;
    static integer n = 9;
    static doublereal rx = 1e-4;

    /* Format strings */
    static char fmt_18[] = "(\002 ERROR - B LESS THAN A IN ROM2\002)";
    static char fmt_19[] = "(\002 ROM2 -- STEP SIZE LIMITED AT Z =\002,1p,e1"
	    "2.5)";

    /* System generated locals */
    integer i__1, i__2, i__3, i__4;
    doublereal d__1;
    doublecomplex z__1, z__2, z__3, z__4;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);
    double d_imag(doublecomplex *), sqrt(doublereal);
    integer do_fio(integer *, char *, ftnlen);

    /* Local variables */
    integer i__;
    doublereal s, z__;
    doublecomplex g1[9], g2[9], g3[9], g4[9], g5[9], t00, t01[9], t10[9], t02,
	     t11, t20[9];
    doublereal ep, ti, dz, ze;
    integer ns, nt;
    doublereal tr, zend;
    extern /* Subroutine */ int test_(doublereal *, doublereal *, doublereal *
	    , doublereal *, doublereal *, doublereal *, doublereal *);
    doublereal dzot, tmag1, tmag2;
    extern /* Subroutine */ int sflds_(doublereal *, doublecomplex *);

    /* Fortran I/O blocks */
    static cilist io___2143 = { 0, 3, 0, fmt_18, 0 };
    static cilist io___2166 = { 0, 3, 0, fmt_19, 0 };


/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* *** */

/*     FOR THE SOMMERFELD GROUND OPTION, ROM2 INTEGRATES OVER THE SOURCE */
/*     SEGMENT TO OBTAIN THE TOTAL FIELD DUE TO GROUND.  THE METHOD OF */
/*     VARIABLE INTERVAL WIDTH ROMBERG INTEGRATION IS USED.  THERE ARE 9 */
/*     FIELD COMPONENTS - THE X, Y, AND Z COMPONENTS DUE TO CONSTANT, */
/*     SINE, AND COSINE CURRENT DISTRIBUTIONS. */

    /* Parameter adjustments */
    --sum;

    /* Function Body */
    z__ = *a;
    ze = *b;
    s = *b - *a;
    if (s >= 0.f) {
	goto L1;
    }
    s_wsfe(&io___2143);
    e_wsfe();
    s_stop("", (ftnlen)0);
L1:
    ep = s / (nm * 1e4f);
    zend = ze - ep;
    i__1 = n;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L2: */
	i__2 = i__;
	sum[i__2].r = 0.f, sum[i__2].i = 0.f;
    }
    ns = nx;
    nt = 0;
    sflds_(&z__, g1);
L3:
    dz = s / ns;
    if (z__ + dz <= ze) {
	goto L4;
    }
    dz = ze - z__;
    if (dz <= ep) {
	goto L17;
    }
L4:
    dzot = dz * .5f;
    d__1 = z__ + dzot;
    sflds_(&d__1, g3);
    d__1 = z__ + dz;
    sflds_(&d__1, g5);
L5:
    tmag1 = 0.f;
    tmag2 = 0.f;

/*     EVALUATE 3 POINT ROMBERG RESULT AND TEST CONVERGENCE. */

    i__2 = n;
    for (i__ = 1; i__ <= i__2; ++i__) {
	i__1 = i__ - 1;
	i__3 = i__ - 1;
	z__2.r = g1[i__1].r + g5[i__3].r, z__2.i = g1[i__1].i + g5[i__3].i;
	z__1.r = dzot * z__2.r, z__1.i = dzot * z__2.i;
	t00.r = z__1.r, t00.i = z__1.i;
	i__1 = i__ - 1;
	i__3 = i__ - 1;
	z__3.r = dz * g3[i__3].r, z__3.i = dz * g3[i__3].i;
	z__2.r = t00.r + z__3.r, z__2.i = t00.i + z__3.i;
	z__1.r = z__2.r * .5f, z__1.i = z__2.i * .5f;
	t01[i__1].r = z__1.r, t01[i__1].i = z__1.i;
	i__1 = i__ - 1;
	i__3 = i__ - 1;
	z__3.r = t01[i__3].r * 4.f, z__3.i = t01[i__3].i * 4.f;
	z__2.r = z__3.r - t00.r, z__2.i = z__3.i - t00.i;
	z__1.r = z__2.r / 3.f, z__1.i = z__2.i / 3.f;
	t10[i__1].r = z__1.r, t10[i__1].i = z__1.i;
	if (i__ > 3) {
	    goto L6;
	}
	i__1 = i__ - 1;
	tr = t01[i__1].r;
	ti = d_imag(&t01[i__ - 1]);
	tmag1 = tmag1 + tr * tr + ti * ti;
	i__1 = i__ - 1;
	tr = t10[i__1].r;
	ti = d_imag(&t10[i__ - 1]);
	tmag2 = tmag2 + tr * tr + ti * ti;
L6:
	;
    }
    tmag1 = sqrt(tmag1);
    tmag2 = sqrt(tmag2);
    test_(&tmag1, &tmag2, &tr, &c_b636, &c_b636, &ti, dmin__);
    if (tr > rx) {
	goto L8;
    }
    i__2 = n;
    for (i__ = 1; i__ <= i__2; ++i__) {
/* L7: */
	i__1 = i__;
	i__3 = i__;
	i__4 = i__ - 1;
	z__1.r = sum[i__3].r + t10[i__4].r, z__1.i = sum[i__3].i + t10[i__4]
		.i;
	sum[i__1].r = z__1.r, sum[i__1].i = z__1.i;
    }
    nt += 2;
    goto L12;
L8:
    d__1 = z__ + dz * .25f;
    sflds_(&d__1, g2);
    d__1 = z__ + dz * .75f;
    sflds_(&d__1, g4);
    tmag1 = 0.f;
    tmag2 = 0.f;

/*     EVALUATE 5 POINT ROMBERG RESULT AND TEST CONVERGENCE. */

    i__1 = n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__3 = i__ - 1;
	i__4 = i__ - 1;
	i__2 = i__ - 1;
	z__4.r = g2[i__4].r + g4[i__2].r, z__4.i = g2[i__4].i + g4[i__2].i;
	z__3.r = dzot * z__4.r, z__3.i = dzot * z__4.i;
	z__2.r = t01[i__3].r + z__3.r, z__2.i = t01[i__3].i + z__3.i;
	z__1.r = z__2.r * .5f, z__1.i = z__2.i * .5f;
	t02.r = z__1.r, t02.i = z__1.i;
	z__3.r = t02.r * 4.f, z__3.i = t02.i * 4.f;
	i__3 = i__ - 1;
	z__2.r = z__3.r - t01[i__3].r, z__2.i = z__3.i - t01[i__3].i;
	z__1.r = z__2.r / 3.f, z__1.i = z__2.i / 3.f;
	t11.r = z__1.r, t11.i = z__1.i;
	i__3 = i__ - 1;
	z__3.r = t11.r * 16.f, z__3.i = t11.i * 16.f;
	i__4 = i__ - 1;
	z__2.r = z__3.r - t10[i__4].r, z__2.i = z__3.i - t10[i__4].i;
	z__1.r = z__2.r / 15.f, z__1.i = z__2.i / 15.f;
	t20[i__3].r = z__1.r, t20[i__3].i = z__1.i;
	if (i__ > 3) {
	    goto L9;
	}
	tr = t11.r;
	ti = d_imag(&t11);
	tmag1 = tmag1 + tr * tr + ti * ti;
	i__3 = i__ - 1;
	tr = t20[i__3].r;
	ti = d_imag(&t20[i__ - 1]);
	tmag2 = tmag2 + tr * tr + ti * ti;
L9:
	;
    }
    tmag1 = sqrt(tmag1);
    tmag2 = sqrt(tmag2);
    test_(&tmag1, &tmag2, &tr, &c_b636, &c_b636, &ti, dmin__);
    if (tr > rx) {
	goto L14;
    }
L10:
    i__1 = n;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L11: */
	i__3 = i__;
	i__4 = i__;
	i__2 = i__ - 1;
	z__1.r = sum[i__4].r + t20[i__2].r, z__1.i = sum[i__4].i + t20[i__2]
		.i;
	sum[i__3].r = z__1.r, sum[i__3].i = z__1.i;
    }
    ++nt;
L12:
    z__ += dz;
    if (z__ > zend) {
	goto L17;
    }
    i__3 = n;
    for (i__ = 1; i__ <= i__3; ++i__) {
/* L13: */
	i__4 = i__ - 1;
	i__2 = i__ - 1;
	g1[i__4].r = g5[i__2].r, g1[i__4].i = g5[i__2].i;
    }
    if (nt < nts || ns <= nx) {
	goto L3;
    }
    ns /= 2;
    nt = 1;
    goto L3;
L14:
    nt = 0;
    if (ns < nm) {
	goto L15;
    }
    s_wsfe(&io___2166);
    do_fio(&c__1, (char *)&z__, (ftnlen)sizeof(doublereal));
    e_wsfe();
    goto L10;
L15:
    ns <<= 1;
    dz = s / ns;
    dzot = dz * .5f;
    i__4 = n;
    for (i__ = 1; i__ <= i__4; ++i__) {
	i__2 = i__ - 1;
	i__3 = i__ - 1;
	g5[i__2].r = g3[i__3].r, g5[i__2].i = g3[i__3].i;
/* L16: */
	i__2 = i__ - 1;
	i__3 = i__ - 1;
	g3[i__2].r = g2[i__3].r, g3[i__2].i = g2[i__3].i;
    }
    goto L5;
L17:
    return 0;

} /* rom2_ */

/* Subroutine */ int sbf_(integer *i__, integer *is, doublereal *aa, 
	doublereal *bb, doublereal *cc)
{
    /* Initialized data */

    static doublereal pi = 3.141592654;
    static integer jmax = 30;

    /* Format strings */
    static char fmt_25[] = "(\002 SBF - SEGMENT CONNECTION ERROR FOR SEGMEN"
	    "T\002,i5)";

    /* Builtin functions */
    double sin(doublereal), cos(doublereal), log(doublereal);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    doublereal d__, cd, aj, ap, sd, pp, pm, qp, qm, cdh, sdh, omc, sig, xxi;
    integer iend, jend, june, jcox, jsno, njun1, njun2;

    /* Fortran I/O blocks */
    static cilist io___2190 = { 0, 3, 0, fmt_25, 0 };


/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* Max number of segments 	(Windows-95 <= 4 */
/* max nr of 'in-core' alloc.	(MAXMAT <= MA */
/* Max number of LD cards */
/* Max number of EX cards */
/* Max number of segs connected to NT/TL */
/* *** */
/*     COMPUTE COMPONENT OF BASIS FUNCTION I ON SEGMENT IS. */
    *aa = 0.f;
    *bb = 0.f;
    *cc = 0.f;
    june = 0;
    jsno = 0;
    pp = 0.f;
    jcox = data_1.icon1[*i__ - 1];
    if (jcox > 10000) {
	jcox = *i__;
    }
    jend = -1;
    iend = -1;
    sig = -1.f;
    if (jcox < 0) {
	goto L1;
    } else if (jcox == 0) {
	goto L11;
    } else {
	goto L2;
    }
L1:
    jcox = -jcox;
    goto L3;
L2:
    sig = -sig;
    jend = -jend;
L3:
    ++jsno;
    if (jsno >= jmax) {
	goto L24;
    }
    d__ = pi * data_1.si[jcox - 1];
    sdh = sin(d__);
    cdh = cos(d__);
    sd = sdh * 2.f * cdh;
    if (d__ > .015f) {
	goto L4;
    }
    omc = d__ * 4.f * d__;
    omc = ((omc * .0013888889 - .041666666667) * omc + .5f) * omc;
    goto L5;
L4:
    omc = 1.f - cdh * cdh + sdh * sdh;
L5:
    aj = 1.f / (log(1.f / (pi * data_1.bi[jcox - 1])) - .577215664);
    pp -= omc / sd * aj;
    if (jcox != *is) {
	goto L6;
    }
    *aa = aj / sd * sig;
    *bb = aj / (cdh * 2.f);
    *cc = -aj / (sdh * 2.f) * sig;
    june = iend;
L6:
    if (jcox == *i__) {
	goto L9;
    }
    if (jend == 1) {
	goto L7;
    }
    jcox = data_1.icon1[jcox - 1];
    goto L8;
L7:
    jcox = data_1.icon2[jcox - 1];
L8:
    if (abs(jcox) == *i__) {
	goto L10;
    }
    if (jcox < 0) {
	goto L1;
    } else if (jcox == 0) {
	goto L24;
    } else {
	goto L2;
    }
L9:
    if (jcox == *is) {
	*bb = -(*bb);
    }
L10:
    if (iend == 1) {
	goto L12;
    }
L11:
    pm = -pp;
    pp = 0.f;
    njun1 = jsno;
    jcox = data_1.icon2[*i__ - 1];
    if (jcox > 10000) {
	jcox = *i__;
    }
    jend = 1;
    iend = 1;
    sig = -1.f;
    if (jcox < 0) {
	goto L1;
    } else if (jcox == 0) {
	goto L12;
    } else {
	goto L2;
    }
L12:
    njun2 = jsno - njun1;
    d__ = pi * data_1.si[*i__ - 1];
    sdh = sin(d__);
    cdh = cos(d__);
    sd = sdh * 2.f * cdh;
    cd = cdh * cdh - sdh * sdh;
    if (d__ > .015f) {
	goto L13;
    }
    omc = d__ * 4.f * d__;
    omc = ((omc * .0013888889 - .041666666667) * omc + .5f) * omc;
    goto L14;
L13:
    omc = 1.f - cd;
L14:
    ap = 1.f / (log(1.f / (pi * data_1.bi[*i__ - 1])) - .577215664);
    aj = ap;
    if (njun1 == 0) {
	goto L19;
    }
    if (njun2 == 0) {
	goto L21;
    }
    qp = sd * (pm * pp + aj * ap) + cd * (pm * ap - pp * aj);
    qm = (ap * omc - pp * sd) / qp;
    qp = -(aj * omc + pm * sd) / qp;
    if (june < 0) {
	goto L15;
    } else if (june == 0) {
	goto L18;
    } else {
	goto L16;
    }
L15:
    *aa *= qm;
    *bb *= qm;
    *cc *= qm;
    goto L17;
L16:
    *aa = -(*aa) * qp;
    *bb *= qp;
    *cc = -(*cc) * qp;
L17:
    if (*i__ != *is) {
	return 0;
    }
L18:
    *aa += -1.f;
    *bb += (aj * qm + ap * qp) * sdh / sd;
    *cc += (aj * qm - ap * qp) * cdh / sd;
    return 0;
L19:
    if (njun2 == 0) {
	goto L23;
    }
    qp = pi * data_1.bi[*i__ - 1];
    xxi = qp * qp;
    xxi = qp * (1.f - xxi * .5f) / (1.f - xxi);
    qp = -(omc + xxi * sd) / (sd * (ap + xxi * pp) + cd * (xxi * ap - pp));
    if (june != 1) {
	goto L20;
    }
    *aa = -(*aa) * qp;
    *bb *= qp;
    *cc = -(*cc) * qp;
    if (*i__ != *is) {
	return 0;
    }
L20:
    *aa += -1.f;
    d__ = cd - xxi * sd;
    *bb += (sdh + ap * qp * (cdh - xxi * sdh)) / d__;
    *cc += (cdh + ap * qp * (sdh + xxi * cdh)) / d__;
    return 0;
L21:
    qm = pi * data_1.bi[*i__ - 1];
    xxi = qm * qm;
    xxi = qm * (1.f - xxi * .5f) / (1.f - xxi);
    qm = (omc + xxi * sd) / (sd * (aj - xxi * pm) + cd * (pm + xxi * aj));
    if (june != -1) {
	goto L22;
    }
    *aa *= qm;
    *bb *= qm;
    *cc *= qm;
    if (*i__ != *is) {
	return 0;
    }
L22:
    *aa += -1.f;
    d__ = cd - xxi * sd;
    *bb += (aj * qm * (cdh - xxi * sdh) - sdh) / d__;
    *cc += (cdh - aj * qm * (sdh + xxi * cdh)) / d__;
    return 0;
L23:
    *aa = -1.f;
    qp = pi * data_1.bi[*i__ - 1];
    xxi = qp * qp;
    xxi = qp * (1.f - xxi * .5f) / (1.f - xxi);
    *cc = 1.f / (cdh - xxi * sdh);
    return 0;
L24:
    s_wsfe(&io___2190);
    do_fio(&c__1, (char *)&(*i__), (ftnlen)sizeof(integer));
    e_wsfe();
    s_stop("", (ftnlen)0);

    return 0;
} /* sbf_ */

/* av02 SUBROUTINE SECOND (CPUSECD) */

/*     Purpose: */
/*     SECOND returns cpu time in seconds.  Must be customized!!! */

/*     VAX or other (modify subroutine stopwtch): */

/* av02 REAL*8 CPUSECD */
/* av02 CALL STOPWTCH(CPUSECS,WALLTOT,CPUSPLT,WALLSPLT) */
/* av02 CPUSECD=60.*CPUSECS */
/*     MACINTOSH: */
/*      CPUSECD= LONG(362)/60.0 */
/* av02 RETURN */
/* av02 END */
/* ********************************************************************** */
/* av03   subroutine stopwtch(cputot,walltot,cpusplt,wallsplt) */

/*       This routine operates as a stopwatch. */
/*       When first called, the routine initializes the clock. */
/*       On subsequent calls, the routine returns: */

/*       Outputs: cputot   -- elapsed CPU time since initialization */
/*                walltot  -- elapsed wallclock time since initialization */
/*                cpusplt  -- split (delta) CPU time since previous call */
/*                wallsplt -- split wallclock time since previous call */

/*       These outputs will all be zero (or very close to it) on the */
/*       first (initialization) call. */

/*       Internal times (cpuinit,wallinit,cpunow,wallnow) are stored in */
/*       seconds.  cpuinit  and cpunow  are stored as reals, */
/*                 wallinit and wallnow are stored as integers. */
/*       Output times are converted to real minutes. */

/* History: */
/*   Date       Author            Reason */
/*   ---------  ----------------  ------------------------------------ */
/*    early-90  Scott L. Ray      initial version */
/*      mid-90  Scott L. Ray      support for additional machines */
/*   14-JAN-91                    ---- Version 2.2/release    ---- */
/*   23-MAY-91  Scott L. Ray      UNICOS branch */
/*   29-JAN-92  Scott L. Ray      FPS and NLTSS support dropped */
/*   29-JAN-92  Scott L. Ray      switch to cpp conditional compilation */
/*   18-SEP-92      Conditional compilation disabled for use in NEC */

/*  (C) Copyright 1990, 1992. */
/*  The Regents of the University of California.  All rights reserved. */
/* ---------------------------------------------------------------------- */

/* parameter list */

/* av03        real cputot,walltot,cpusplt,wallsplt */

/* locals (non sysdep) */

/* av03        logical initiz */
/* av03        integer wallinit,walllast,wallnow */
/* av03        real cpuinit,cpulast,cpunow */
/* av03        save initiz,cpuinit,cpulast,wallinit,walllast */

/* locals (sysdep) */

/* #include "machines.h" */
/* #ifdef VAX_VMS */
/*        integer istatus,iwall,icpu */
/*        real rwall */
/*        dimension iwall(2) */
/* #endif */
/* #ifdef SUN4TIMER */
/* av03        integer time */
/* av03        real tarray */
/* av03        dimension tarray(2) */
/* #endif */
/* #ifdef CONVEX */
/*        real time, secnds, tarray */
/*        dimension tarray(2) */
/*        external secnds */
/* #endif */
/* #ifdef IBM_RISC */
/*        integer icpu */
/*        integer mclock */
/* #endif */
/* #ifdef IRIS4D */
/*        external time */
/* #endif */
/* #ifdef STARDENT */
/*        integer stime */
/*        real tarray */
/*        dimension tarray(2) */
/* #endif */
/* #ifdef UNICOS */
/*        real rwall */
/* #endif */

/* data initialization */

/* av03        data initiz/.false./ */

/* ---------------------------------------------------------------------- */

/* av03        if (.not. initiz) then */

/* ...      set the flag showing that the clock has been initialized */

/* av03           initiz = .true. */

/* ...      set the initial times to default value of zero.  These may */
/*          be changed, depending on how an individual machine handles */
/*          its timer. */

/* av03           cpuinit  = 0.0 */
/* av03           wallinit = 0 */

/* ...      initialize the timer (may not be necessary on all machines) */

/* #ifdef VAX_VMS */
/*           istatus = lib$init_timer() */
/* #endif */

/* #ifdef SUN4TIMER */
/*          CPU timer on SUN4 initializes automatically on job startup. */
/*          However, we want t=0 to be defined when this routine is first */
/*          called.  Hence, define initial CPU time here. */
/*          Wall clock timer counts in seconds from 1-Jan-70  Thus, */
/*          initial wall clock time is non-zero.  It is obtained here. */

/* av03           cpuinit  = etime(tarray) */
/* av03           wallinit = time() */
/* #endif */

/* #ifdef CONVEX */
/*           cpuinit = etime(tarray) */
/*           time = secnds(0.0) */
/*           wallinit = ifix(time) */
/* #endif */

/* #ifdef IBM_RISC */
/*          no known wall clock timer */

/*           icpu = mclock( ) */
/*           cpuinit  = float(icpu)/100.0 */
/*           wallinit = 0 */
/* #endif */

/* #ifdef STARDENT */
/*          CPU timer on STARDENT initializes automatically on job */
/*          startup. */
/*          However, we want t=0 to be defined when this routine is first */
/*          called.  Hence, define initial CPU time here. */
/*          Wall clock timer counts in seconds from 1-Jan-70  Thus, */
/*          initial wall clock time is non-zero.  It is obtained here. */

/*           cpuinit  = etime(tarray) */
/*           wallinit = stime() */
/* #endif */

/* #ifdef UNICOS */
/*          I hope that the "second" routine is true UNICOS and not a */
/*          local (LLNL) feature that was added on to keep things */
/*          consistent with NLTSS. */
/*          The "timef" routine returns real milliseconds; first */
/*          call initializes the timer and should return zero (not */
/*          that we care -- this routine works by taking differences). */

/*           call second(cpuinit) */
/*           call timef(rwall) */
/*           wallinit = ifix(rwall*1.0e-03) */
/* #endif */

/* ...      since this is the first call to this routine, */
/*          initialize the previous call times to the initial time. */

/* av03           cpulast  =  cpuinit */
/* av03           walllast = wallinit */

/* av03        end if */

/* ...   Find the current cpu and wall times */

/* #ifdef HASTIMER */
/* #ifdef VAX_VMS */

/*       function "lib$stat_timer" is called as: */
/*       error_status = lib$stat_timer(input_code,output_result,junk) */
/*       where, */
/*        input_code = 1 returns elapsed wall clock time in VAX_VMS */
/*           binary internal format.  This format takes 64 bits to store, */
/*           hence output_result should be a 32 bit integer array of */
/*           length 2. */
/*           This internal format is converted to a floating point number */
/*           by calling "lib$cvtf_from_internal_time".  This function */
/*           is poorly documented in the VAX_VMS manuals.  Here are some */
/*           details:  First argument = 28 ==> result in real hours */
/*                                    = 29 ==> result in real minutes */
/*                                    = 30 ==> result in real seconds */
/*           The input to "lib$cvtf_from_internal_time" goes in the 3rd */
/*           argument, the result is returned in the 2nd argument. */
/*           input_code = 2 returns elapsed cpu time as an integer in */
/*           units of 10msec.  This is converted to seconds here. */

/*        istatus = lib$stat_timer(1,iwall,) */
/*        istatus = lib$cvtf_from_internal_time(30,rwall,iwall) */
/*        wallnow = rwall */
/*        istatus = lib$stat_timer(2,icpu,) */
/*        cpunow = icpu*(10.0e-3) */
/* #endif */

/* #ifdef SUN4TIMER */
/*       there is some ambiguity in the manual as to how to use */
/*       etime.  Function returns: */
/*          "elapsed execution time" = tarray(1) + tarray(2) */
/*                                   = user time + system time */
/*       I am uncertain whether to let cpunow = return value or */
/*       else tarray(1). */

/* av03        cpunow  = etime(tarray) */
/* av03        wallnow = time() */
/* #endif */

/* #ifdef CONVEX */
/*           cpunow = etime(tarray) */
/*           time = secnds(0.0) */
/*           wallnow = ifix(time) */
/* #endif */

/* #ifdef IBM_RISC */
/*       no known wall clock timer */

/*        icpu = mclock( ) */
/*        cpunow  = float(icpu)/100.0 */
/*        wallnow = 0 */
/* #endif */

/* #ifdef STARDENT */
/*       there is some ambiguity in the manual as to how to use */
/*       etime.  Function returns: */
/*          "elapsed execution time" = tarray(1) + tarray(2) */
/*                                   = user time + system time */
/*       I am uncertain whether to let cpunow = return value or */
/*       else tarray(1). */

/*        cpunow  = etime(tarray) */
/*        wallnow = stime() */
/* #endif */

/* #ifdef UNICOS */
/*       I hope that the "second" routine is true UNICOS and not a */
/*       local (LLNL) feature that was added on to keep things */
/*       consistent with NLTSS. */
/*       The "timef" routine returns real milliseconds. */

/*        call second(cpunow) */
/*        call timef(rwall) */
/*        wallnow = ifix(rwall*1.0e-03) */
/* #endif */
/* #else */
/*       for machines without timers or with unknown timers, */
/*       set things to zero now to ensure that something is returned */
/*        cpunow  = 0.0 */
/*        wallnow = 0 */
/* #endif */

/* ...   calculate elapsed and split cpu and wall clock times, */
/*       convert to minutes on output. */

/* av03        cputot   = (cpunow  - cpuinit )/60.0 */
/* av03        walltot  = float(wallnow - wallinit)/60.0 */
/* av03        cpusplt  = (cpunow  - cpulast )/60.0 */
/* av03        wallsplt = float(wallnow - walllast)/60.0 */

/* ...   save "now" times in "last" times */

/* av03        cpulast  = cpunow */
/* av03        walllast = wallnow */

/* av03        return */
/* ********************************************************************** */
/* av03        end */
/* Subroutine */ int sflds_(doublereal *t, doublecomplex *e)
{
    /* Initialized data */

    static doublereal pi = 3.141592654;
    static doublereal tp = 6.283185308;
    static doublereal pot = 1.570796327;

    /* System generated locals */
    doublereal d__1, d__2;
    doublecomplex z__1, z__2, z__3, z__4;

    /* Builtin functions */
    double sqrt(doublereal), sin(doublereal), cos(doublereal), atan(
	    doublereal);

    /* Local variables */
    doublecomplex er, et;
    doublereal rk, xt, yt, zt, r2s, cph;
    doublecomplex eph, erh, hrh, ezh;
    doublereal rho, sph;
    doublecomplex erv;
    doublereal rhs;
    doublecomplex hrv, ezv;
    doublereal rhx;
    doublecomplex hzv;
    doublereal rhy, phx, phy, sfac, thet, zphs;
    extern /* Subroutine */ int gwave_(doublecomplex *, doublecomplex *, 
	    doublecomplex *, doublecomplex *, doublecomplex *), intrp_(
	    doublereal *, doublereal *, doublecomplex *, doublecomplex *, 
	    doublecomplex *, doublecomplex *);

/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* *** */

/*     SFLDX RETURNS THE FIELD DUE TO GROUND FOR A CURRENT ELEMENT ON */
/*     THE SOURCE SEGMENT AT T RELATIVE TO THE SEGMENT CENTER. */

    /* Parameter adjustments */
    --e;

    /* Function Body */
    xt = dataj_1.xj + *t * dataj_1.cabj;
    yt = dataj_1.yj + *t * dataj_1.sabj;
    zt = dataj_1.zj + *t * dataj_1.salpj;
    rhx = incom_1.xo - xt;
    rhy = incom_1.yo - yt;
    rhs = rhx * rhx + rhy * rhy;
    rho = sqrt(rhs);
    if (rho > 0.f) {
	goto L1;
    }
    rhx = 1.f;
    rhy = 0.f;
    phx = 0.f;
    phy = 1.f;
    goto L2;
L1:
    rhx /= rho;
    rhy /= rho;
    phx = -rhy;
    phy = rhx;
L2:
    cph = rhx * incom_1.xsn + rhy * incom_1.ysn;
    sph = rhy * incom_1.xsn - rhx * incom_1.ysn;
    if (abs(cph) < 1e-10) {
	cph = 0.f;
    }
    if (abs(sph) < 1e-10) {
	sph = 0.f;
    }
    gwav_1.zph = incom_1.zo + zt;
    zphs = gwav_1.zph * gwav_1.zph;
    r2s = rhs + zphs;
    gwav_1.r2 = sqrt(r2s);
    rk = gwav_1.r2 * tp;
    d__1 = cos(rk);
    d__2 = -sin(rk);
    z__1.r = d__1, z__1.i = d__2;
    gwav_1.xx2.r = z__1.r, gwav_1.xx2.i = z__1.i;
    if (incom_1.isnor == 1) {
	goto L3;
    }

/*     USE NORTON APPROXIMATION FOR FIELD DUE TO GROUND.  CURRENT IS */
/*     LUMPED AT SEGMENT CENTER WITH CURRENT MOMENT FOR CONSTANT, SINE, */
/*     OR COSINE DISTRIBUTION. */

    gwav_1.zmh = 1.f;
    gwav_1.r1 = 1.f;
    gwav_1.xx1.r = 0.f, gwav_1.xx1.i = 0.f;
    gwave_(&erv, &ezv, &erh, &ezh, &eph);
    z__3.r = gnd_1.frati.r * -0.f - gnd_1.frati.i * -4.77134f, z__3.i = 
	    gnd_1.frati.r * -4.77134f + gnd_1.frati.i * -0.f;
    z__2.r = z__3.r * gwav_1.xx2.r - z__3.i * gwav_1.xx2.i, z__2.i = z__3.r * 
	    gwav_1.xx2.i + z__3.i * gwav_1.xx2.r;
    d__1 = r2s * gwav_1.r2;
    z__1.r = z__2.r / d__1, z__1.i = z__2.i / d__1;
    et.r = z__1.r, et.i = z__1.i;
    z__2.r = et.r * 2.f, z__2.i = et.i * 2.f;
    z__3.r = 1., z__3.i = rk;
    z__1.r = z__2.r * z__3.r - z__2.i * z__3.i, z__1.i = z__2.r * z__3.i + 
	    z__2.i * z__3.r;
    er.r = z__1.r, er.i = z__1.i;
    d__1 = 1. - rk * rk;
    z__2.r = d__1, z__2.i = rk;
    z__1.r = et.r * z__2.r - et.i * z__2.i, z__1.i = et.r * z__2.i + et.i * 
	    z__2.r;
    et.r = z__1.r, et.i = z__1.i;
    z__4.r = er.r + et.r, z__4.i = er.i + et.i;
    z__3.r = rho * z__4.r, z__3.i = rho * z__4.i;
    z__2.r = gwav_1.zph * z__3.r, z__2.i = gwav_1.zph * z__3.i;
    z__1.r = z__2.r / r2s, z__1.i = z__2.i / r2s;
    hrv.r = z__1.r, hrv.i = z__1.i;
    z__3.r = zphs * er.r, z__3.i = zphs * er.i;
    z__4.r = rhs * et.r, z__4.i = rhs * et.i;
    z__2.r = z__3.r - z__4.r, z__2.i = z__3.i - z__4.i;
    z__1.r = z__2.r / r2s, z__1.i = z__2.i / r2s;
    hzv.r = z__1.r, hzv.i = z__1.i;
    z__3.r = rhs * er.r, z__3.i = rhs * er.i;
    z__4.r = zphs * et.r, z__4.i = zphs * et.i;
    z__2.r = z__3.r - z__4.r, z__2.i = z__3.i - z__4.i;
    z__1.r = z__2.r / r2s, z__1.i = z__2.i / r2s;
    hrh.r = z__1.r, hrh.i = z__1.i;
    z__1.r = erv.r - hrv.r, z__1.i = erv.i - hrv.i;
    erv.r = z__1.r, erv.i = z__1.i;
    z__1.r = ezv.r - hzv.r, z__1.i = ezv.i - hzv.i;
    ezv.r = z__1.r, ezv.i = z__1.i;
    z__1.r = erh.r + hrh.r, z__1.i = erh.i + hrh.i;
    erh.r = z__1.r, erh.i = z__1.i;
    z__1.r = ezh.r + hrv.r, z__1.i = ezh.i + hrv.i;
    ezh.r = z__1.r, ezh.i = z__1.i;
    z__1.r = eph.r + et.r, z__1.i = eph.i + et.i;
    eph.r = z__1.r, eph.i = z__1.i;
    z__1.r = dataj_1.salpj * erv.r, z__1.i = dataj_1.salpj * erv.i;
    erv.r = z__1.r, erv.i = z__1.i;
    z__1.r = dataj_1.salpj * ezv.r, z__1.i = dataj_1.salpj * ezv.i;
    ezv.r = z__1.r, ezv.i = z__1.i;
    z__2.r = incom_1.sn * erh.r, z__2.i = incom_1.sn * erh.i;
    z__1.r = cph * z__2.r, z__1.i = cph * z__2.i;
    erh.r = z__1.r, erh.i = z__1.i;
    z__2.r = incom_1.sn * ezh.r, z__2.i = incom_1.sn * ezh.i;
    z__1.r = cph * z__2.r, z__1.i = cph * z__2.i;
    ezh.r = z__1.r, ezh.i = z__1.i;
    z__2.r = incom_1.sn * eph.r, z__2.i = incom_1.sn * eph.i;
    z__1.r = sph * z__2.r, z__1.i = sph * z__2.i;
    eph.r = z__1.r, eph.i = z__1.i;
    z__1.r = erv.r + erh.r, z__1.i = erv.i + erh.i;
    erh.r = z__1.r, erh.i = z__1.i;
    z__3.r = rhx * erh.r, z__3.i = rhx * erh.i;
    z__4.r = phx * eph.r, z__4.i = phx * eph.i;
    z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
    z__1.r = dataj_1.s * z__2.r, z__1.i = dataj_1.s * z__2.i;
    e[1].r = z__1.r, e[1].i = z__1.i;
    z__3.r = rhy * erh.r, z__3.i = rhy * erh.i;
    z__4.r = phy * eph.r, z__4.i = phy * eph.i;
    z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
    z__1.r = dataj_1.s * z__2.r, z__1.i = dataj_1.s * z__2.i;
    e[2].r = z__1.r, e[2].i = z__1.i;
    z__2.r = ezv.r + ezh.r, z__2.i = ezv.i + ezh.i;
    z__1.r = dataj_1.s * z__2.r, z__1.i = dataj_1.s * z__2.i;
    e[3].r = z__1.r, e[3].i = z__1.i;
    e[4].r = 0.f, e[4].i = 0.f;
    e[5].r = 0.f, e[5].i = 0.f;
    e[6].r = 0.f, e[6].i = 0.f;
    sfac = pi * dataj_1.s;
    sfac = sin(sfac) / sfac;
    z__1.r = sfac * e[1].r, z__1.i = sfac * e[1].i;
    e[7].r = z__1.r, e[7].i = z__1.i;
    z__1.r = sfac * e[2].r, z__1.i = sfac * e[2].i;
    e[8].r = z__1.r, e[8].i = z__1.i;
    z__1.r = sfac * e[3].r, z__1.i = sfac * e[3].i;
    e[9].r = z__1.r, e[9].i = z__1.i;
    return 0;

/*     INTERPOLATE IN SOMMERFELD FIELD TABLES */

L3:
    if (rho < 1e-12) {
	goto L4;
    }
    thet = atan(gwav_1.zph / rho);
    goto L5;
L4:
    thet = pot;
L5:
    intrp_(&gwav_1.r2, &thet, &erv, &ezv, &erh, &eph);
/*     COMBINE VERTICAL AND HORIZONTAL COMPONENTS AND CONVERT TO X,Y,Z */
/*     COMPONENTS.  MULTIPLY BY EXP(-JKR)/R. */
    z__1.r = gwav_1.xx2.r / gwav_1.r2, z__1.i = gwav_1.xx2.i / gwav_1.r2;
    gwav_1.xx2.r = z__1.r, gwav_1.xx2.i = z__1.i;
    sfac = incom_1.sn * cph;
    z__3.r = dataj_1.salpj * erv.r, z__3.i = dataj_1.salpj * erv.i;
    z__4.r = sfac * erh.r, z__4.i = sfac * erh.i;
    z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
    z__1.r = gwav_1.xx2.r * z__2.r - gwav_1.xx2.i * z__2.i, z__1.i = 
	    gwav_1.xx2.r * z__2.i + gwav_1.xx2.i * z__2.r;
    erh.r = z__1.r, erh.i = z__1.i;
    z__3.r = dataj_1.salpj * ezv.r, z__3.i = dataj_1.salpj * ezv.i;
    z__4.r = sfac * erv.r, z__4.i = sfac * erv.i;
    z__2.r = z__3.r - z__4.r, z__2.i = z__3.i - z__4.i;
    z__1.r = gwav_1.xx2.r * z__2.r - gwav_1.xx2.i * z__2.i, z__1.i = 
	    gwav_1.xx2.r * z__2.i + gwav_1.xx2.i * z__2.r;
    ezh.r = z__1.r, ezh.i = z__1.i;
    d__1 = incom_1.sn * sph;
    z__2.r = d__1 * gwav_1.xx2.r, z__2.i = d__1 * gwav_1.xx2.i;
    z__1.r = z__2.r * eph.r - z__2.i * eph.i, z__1.i = z__2.r * eph.i + 
	    z__2.i * eph.r;
    eph.r = z__1.r, eph.i = z__1.i;
/*     X,Y,Z FIELDS FOR CONSTANT CURRENT */
    z__2.r = rhx * erh.r, z__2.i = rhx * erh.i;
    z__3.r = phx * eph.r, z__3.i = phx * eph.i;
    z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
    e[1].r = z__1.r, e[1].i = z__1.i;
    z__2.r = rhy * erh.r, z__2.i = rhy * erh.i;
    z__3.r = phy * eph.r, z__3.i = phy * eph.i;
    z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
    e[2].r = z__1.r, e[2].i = z__1.i;
    e[3].r = ezh.r, e[3].i = ezh.i;
    rk = tp * *t;
/*     X,Y,Z FIELDS FOR SINE CURRENT */
    sfac = sin(rk);
    z__1.r = sfac * e[1].r, z__1.i = sfac * e[1].i;
    e[4].r = z__1.r, e[4].i = z__1.i;
    z__1.r = sfac * e[2].r, z__1.i = sfac * e[2].i;
    e[5].r = z__1.r, e[5].i = z__1.i;
    z__1.r = sfac * e[3].r, z__1.i = sfac * e[3].i;
    e[6].r = z__1.r, e[6].i = z__1.i;
/*     X,Y,Z FIELDS FOR COSINE CURRENT */
    sfac = cos(rk);
    z__1.r = sfac * e[1].r, z__1.i = sfac * e[1].i;
    e[7].r = z__1.r, e[7].i = z__1.i;
    z__1.r = sfac * e[2].r, z__1.i = sfac * e[2].i;
    e[8].r = z__1.r, e[8].i = z__1.i;
    z__1.r = sfac * e[3].r, z__1.i = sfac * e[3].i;
    e[9].r = z__1.r, e[9].i = z__1.i;
    return 0;
} /* sflds_ */

/* Subroutine */ int solgf_(doublecomplex *a, doublecomplex *b, doublecomplex 
	*c__, doublecomplex *d__, doublecomplex *xy, integer *ip, integer *np,
	 integer *n1, integer *n, integer *mp, integer *m1, integer *m, 
	integer *n1c, integer *n2c, integer *n2cz)
{
    /* System generated locals */
    integer b_dim1, b_offset, c_dim1, c_offset, d_dim1, d_offset, i__1, i__2, 
	    i__3, i__4, i__5;
    doublecomplex z__1, z__2;
    alist al__1;

    /* Builtin functions */
    integer s_rsue(cilist *), do_uio(integer *, char *, ftnlen), e_rsue(void),
	     f_rew(alist *);

    /* Local variables */
    integer i__, j, n2, ii, jj, ni, jp, ifl, npb, neq, npm;
    doublecomplex sum;
    integer neqs, icass;
    extern /* Subroutine */ int solve_(integer *, doublecomplex *, integer *, 
	    doublecomplex *, integer *);
    integer nlsys, npsys, nblsys;
    extern /* Subroutine */ int solves_(doublecomplex *, integer *, 
	    doublecomplex *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *), ltsolv_(
	    doublecomplex *, integer *, integer *, doublecomplex *, integer *,
	     integer *, integer *, integer *);

    /* Fortran I/O blocks */
    static cilist io___2230 = { 0, 15, 0, 0, 0 };
    static cilist io___2233 = { 0, 11, 0, 0, 0 };
    static cilist io___2238 = { 0, 14, 0, 0, 0 };


/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* Max number of segments 	(Windows-95 <= 4 */
/* max nr of 'in-core' alloc.	(MAXMAT <= MA */
/* Max number of LD cards */
/* Max number of EX cards */
/* Max number of segs connected to NT/TL */
/* *** */
/*     SOLVE FOR CURRENT IN N.G.F. PROCEDURE */
    /* Parameter adjustments */
    --a;
    --xy;
    --ip;
    c_dim1 = *n1c;
    c_offset = 1 + c_dim1;
    c__ -= c_offset;
    b_dim1 = *n1c;
    b_offset = 1 + b_dim1;
    b -= b_offset;
    d_dim1 = *n2cz;
    d_offset = 1 + d_dim1;
    d__ -= d_offset;

    /* Function Body */
    ifl = 14;
    if (matpar_1.icasx > 0) {
	ifl = 13;
    }
    if (*n2c > 0) {
	goto L1;
    }
/*     NORMAL SOLUTION.  NOT N.G.F. */
    solves_(&a[1], &ip[1], &xy[1], n1c, &c__1, np, n, mp, m, &c__13, &ifl);
    goto L22;
L1:
    if (*n1 == *n || *m1 == 0) {
	goto L5;
    }
/*     REORDER EXCITATION ARRAY */
    n2 = *n1 + 1;
    jj = *n + 1;
    npm = *n + (*m1 << 1);
    i__1 = npm;
    for (i__ = n2; i__ <= i__1; ++i__) {
/* L2: */
	i__2 = i__ - 1;
	i__3 = i__;
	scratm_2.y[i__2].r = xy[i__3].r, scratm_2.y[i__2].i = xy[i__3].i;
    }
    j = *n1;
    i__2 = npm;
    for (i__ = jj; i__ <= i__2; ++i__) {
	++j;
/* L3: */
	i__3 = j;
	i__1 = i__ - 1;
	xy[i__3].r = scratm_2.y[i__1].r, xy[i__3].i = scratm_2.y[i__1].i;
    }
    i__3 = *n;
    for (i__ = n2; i__ <= i__3; ++i__) {
	++j;
/* L4: */
	i__1 = j;
	i__2 = i__ - 1;
	xy[i__1].r = scratm_2.y[i__2].r, xy[i__1].i = scratm_2.y[i__2].i;
    }
L5:
    neqs = segj_1.nscon + (segj_1.npcon << 1);
    if (neqs == 0) {
	goto L7;
    }
    neq = *n1c + *n2c;
    neqs = neq - neqs + 1;
/*     COMPUTE INV(A)E1 */
    i__1 = neq;
    for (i__ = neqs; i__ <= i__1; ++i__) {
/* L6: */
	i__2 = i__;
	xy[i__2].r = 0.f, xy[i__2].i = 0.f;
    }
L7:
    solves_(&a[1], &ip[1], &xy[1], n1c, &c__1, np, n1, mp, m1, &c__13, &ifl);
    ni = 0;
    npb = matpar_1.npbl;
/*     COMPUTE E2-C(INV(A)E1) */
    i__2 = matpar_1.nbbl;
    for (jj = 1; jj <= i__2; ++jj) {
	if (jj == matpar_1.nbbl) {
	    npb = matpar_1.nlbl;
	}
	if (matpar_1.icasx > 1) {
	    s_rsue(&io___2230);
	    i__1 = npb;
	    for (j = 1; j <= i__1; ++j) {
		i__3 = *n1c;
		for (i__ = 1; i__ <= i__3; ++i__) {
		    do_uio(&c__2, (char *)&c__[i__ + j * c_dim1], (ftnlen)
			    sizeof(doublereal));
		}
	    }
	    e_rsue();
	}
	ii = *n1c + ni;
	i__3 = npb;
	for (i__ = 1; i__ <= i__3; ++i__) {
	    sum.r = 0.f, sum.i = 0.f;
	    i__1 = *n1c;
	    for (j = 1; j <= i__1; ++j) {
/* L8: */
		i__4 = j + i__ * c_dim1;
		i__5 = j;
		z__2.r = c__[i__4].r * xy[i__5].r - c__[i__4].i * xy[i__5].i, 
			z__2.i = c__[i__4].r * xy[i__5].i + c__[i__4].i * xy[
			i__5].r;
		z__1.r = sum.r + z__2.r, z__1.i = sum.i + z__2.i;
		sum.r = z__1.r, sum.i = z__1.i;
	    }
	    j = ii + i__;
/* L9: */
	    i__4 = j;
	    i__5 = j;
	    z__1.r = xy[i__5].r - sum.r, z__1.i = xy[i__5].i - sum.i;
	    xy[i__4].r = z__1.r, xy[i__4].i = z__1.i;
	}
/* L10: */
	ni += matpar_1.npbl;
    }
    if (matpar_1.icasx > 1) {
	al__1.aerr = 0;
	al__1.aunit = 15;
	f_rew(&al__1);
    }
    jj = *n1c + 1;
/*     COMPUTE INV(D)(E2-C(INV(A)E1)) = I2 */
    if (matpar_1.icasx > 1) {
	goto L11;
    }
    solve_(n2c, &d__[d_offset], &ip[jj], &xy[jj], n2c);
    goto L13;
L11:
    if (matpar_1.icasx == 4) {
	goto L12;
    }
    ni = *n2c * *n2c;
    s_rsue(&io___2233);
    i__2 = ni;
    for (j = 1; j <= i__2; ++j) {
	do_uio(&c__2, (char *)&b[j + b_dim1], (ftnlen)sizeof(doublereal));
    }
    e_rsue();
    al__1.aerr = 0;
    al__1.aunit = 11;
    f_rew(&al__1);
    solve_(n2c, &b[b_offset], &ip[jj], &xy[jj], n2c);
    goto L13;
L12:
    nblsys = matpar_1.nblsym;
    npsys = matpar_1.npsym;
    nlsys = matpar_1.nlsym;
    icass = matpar_1.icase;
    matpar_1.nblsym = matpar_1.nbbl;
    matpar_1.npsym = matpar_1.npbl;
    matpar_1.nlsym = matpar_1.nlbl;
    matpar_1.icase = 3;
    al__1.aerr = 0;
    al__1.aunit = 11;
    f_rew(&al__1);
    al__1.aerr = 0;
    al__1.aunit = 16;
    f_rew(&al__1);
    ltsolv_(&b[b_offset], n2c, &ip[jj], &xy[jj], n2c, &c__1, &c__11, &c__16);
    al__1.aerr = 0;
    al__1.aunit = 11;
    f_rew(&al__1);
    al__1.aerr = 0;
    al__1.aunit = 16;
    f_rew(&al__1);
    matpar_1.nblsym = nblsys;
    matpar_1.npsym = npsys;
    matpar_1.nlsym = nlsys;
    matpar_1.icase = icass;
L13:
    ni = 0;
    npb = matpar_1.npbl;
/*     COMPUTE INV(A)E1-(INV(A)B)I2 = I1 */
    i__2 = matpar_1.nbbl;
    for (jj = 1; jj <= i__2; ++jj) {
	if (jj == matpar_1.nbbl) {
	    npb = matpar_1.nlbl;
	}
	if (matpar_1.icasx > 1) {
	    s_rsue(&io___2238);
	    i__4 = npb;
	    for (j = 1; j <= i__4; ++j) {
		i__5 = *n1c;
		for (i__ = 1; i__ <= i__5; ++i__) {
		    do_uio(&c__2, (char *)&b[i__ + j * b_dim1], (ftnlen)
			    sizeof(doublereal));
		}
	    }
	    e_rsue();
	}
	ii = *n1c + ni;
	i__5 = *n1c;
	for (i__ = 1; i__ <= i__5; ++i__) {
	    sum.r = 0.f, sum.i = 0.f;
	    i__4 = npb;
	    for (j = 1; j <= i__4; ++j) {
		jp = ii + j;
/* L14: */
		i__3 = i__ + j * b_dim1;
		i__1 = jp;
		z__2.r = b[i__3].r * xy[i__1].r - b[i__3].i * xy[i__1].i, 
			z__2.i = b[i__3].r * xy[i__1].i + b[i__3].i * xy[i__1]
			.r;
		z__1.r = sum.r + z__2.r, z__1.i = sum.i + z__2.i;
		sum.r = z__1.r, sum.i = z__1.i;
	    }
/* L15: */
	    i__3 = i__;
	    i__1 = i__;
	    z__1.r = xy[i__1].r - sum.r, z__1.i = xy[i__1].i - sum.i;
	    xy[i__3].r = z__1.r, xy[i__3].i = z__1.i;
	}
/* L16: */
	ni += matpar_1.npbl;
    }
    if (matpar_1.icasx > 1) {
	al__1.aerr = 0;
	al__1.aunit = 14;
	f_rew(&al__1);
    }
    if (*n1 == *n || *m1 == 0) {
	goto L20;
    }
/*     REORDER CURRENT ARRAY */
    i__2 = npm;
    for (i__ = n2; i__ <= i__2; ++i__) {
/* L17: */
	i__3 = i__ - 1;
	i__1 = i__;
	scratm_2.y[i__3].r = xy[i__1].r, scratm_2.y[i__3].i = xy[i__1].i;
    }
    jj = *n1c + 1;
    j = *n1;
    i__3 = npm;
    for (i__ = jj; i__ <= i__3; ++i__) {
	++j;
/* L18: */
	i__1 = j;
	i__2 = i__ - 1;
	xy[i__1].r = scratm_2.y[i__2].r, xy[i__1].i = scratm_2.y[i__2].i;
    }
    i__1 = *n1c;
    for (i__ = n2; i__ <= i__1; ++i__) {
	++j;
/* L19: */
	i__2 = j;
	i__3 = i__ - 1;
	xy[i__2].r = scratm_2.y[i__3].r, xy[i__2].i = scratm_2.y[i__3].i;
    }
L20:
    if (segj_1.nscon == 0) {
	goto L22;
    }
    j = neqs - 1;
    i__2 = segj_1.nscon;
    for (i__ = 1; i__ <= i__2; ++i__) {
	++j;
	jj = segj_1.iscon[i__ - 1];
/* L21: */
	i__3 = jj;
	i__1 = j;
	xy[i__3].r = xy[i__1].r, xy[i__3].i = xy[i__1].i;
    }
L22:
    return 0;
} /* solgf_ */

/* Subroutine */ int solve_(integer *n, doublecomplex *a, integer *ip, 
	doublecomplex *b, integer *ndim)
{
    /* System generated locals */
    integer a_dim1, a_offset, i__1, i__2, i__3, i__4, i__5, i__6;
    doublecomplex z__1, z__2;

    /* Builtin functions */
    void z_div(doublecomplex *, doublecomplex *, doublecomplex *);

    /* Local variables */
    integer i__, j, k, pi, ip1;
    doublecomplex sum;

/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* Max number of segments 	(Windows-95 <= 4 */
/* max nr of 'in-core' alloc.	(MAXMAT <= MA */
/* Max number of LD cards */
/* Max number of EX cards */
/* Max number of segs connected to NT/TL */
/* *** */

/*     SUBROUTINE TO SOLVE THE MATRIX EQUATION LU*X=B WHERE L IS A UNIT */
/*     LOWER TRIANGULAR MATRIX AND U IS AN UPPER TRIANGULAR MATRIX BOTH */
/*     OF WHICH ARE STORED IN A.  THE RHS VECTOR B IS INPUT AND THE */
/*     SOLUTION IS RETURNED THROUGH VECTOR B. */


/*     FORWARD SUBSTITUTION */

    /* Parameter adjustments */
    --b;
    --ip;
    a_dim1 = *ndim;
    a_offset = 1 + a_dim1;
    a -= a_offset;

    /* Function Body */
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	pi = ip[i__];
	i__2 = i__ - 1;
	i__3 = pi;
	scratm_2.y[i__2].r = b[i__3].r, scratm_2.y[i__2].i = b[i__3].i;
	i__2 = pi;
	i__3 = i__;
	b[i__2].r = b[i__3].r, b[i__2].i = b[i__3].i;
	ip1 = i__ + 1;
	if (ip1 > *n) {
	    goto L2;
	}
	i__2 = *n;
	for (j = ip1; j <= i__2; ++j) {
	    i__3 = j;
	    i__4 = j;
	    i__5 = j + i__ * a_dim1;
	    i__6 = i__ - 1;
	    z__2.r = a[i__5].r * scratm_2.y[i__6].r - a[i__5].i * scratm_2.y[
		    i__6].i, z__2.i = a[i__5].r * scratm_2.y[i__6].i + a[i__5]
		    .i * scratm_2.y[i__6].r;
	    z__1.r = b[i__4].r - z__2.r, z__1.i = b[i__4].i - z__2.i;
	    b[i__3].r = z__1.r, b[i__3].i = z__1.i;
/* L1: */
	}
L2:
/* L3: */
	;
    }

/*     BACKWARD SUBSTITUTION */

    i__1 = *n;
    for (k = 1; k <= i__1; ++k) {
	i__ = *n - k + 1;
	sum.r = 0.f, sum.i = 0.f;
	ip1 = i__ + 1;
	if (ip1 > *n) {
	    goto L5;
	}
	i__2 = *n;
	for (j = ip1; j <= i__2; ++j) {
	    i__3 = i__ + j * a_dim1;
	    i__4 = j;
	    z__2.r = a[i__3].r * b[i__4].r - a[i__3].i * b[i__4].i, z__2.i = 
		    a[i__3].r * b[i__4].i + a[i__3].i * b[i__4].r;
	    z__1.r = sum.r + z__2.r, z__1.i = sum.i + z__2.i;
	    sum.r = z__1.r, sum.i = z__1.i;
/* L4: */
	}
L5:
	i__2 = i__;
	i__3 = i__ - 1;
	z__2.r = scratm_2.y[i__3].r - sum.r, z__2.i = scratm_2.y[i__3].i - 
		sum.i;
	z_div(&z__1, &z__2, &a[i__ + i__ * a_dim1]);
	b[i__2].r = z__1.r, b[i__2].i = z__1.i;
/* L6: */
    }
    return 0;
} /* solve_ */

/* Subroutine */ int solves_(doublecomplex *a, integer *ip, doublecomplex *b, 
	integer *neq, integer *nrh, integer *np, integer *n, integer *mp, 
	integer *m, integer *ifl1, integer *ifl2)
{
    /* System generated locals */
    integer b_dim1, b_offset, i__1, i__2, i__3, i__4, i__5, i__6;
    doublecomplex z__1, z__2, z__3;
    alist al__1;

    /* Builtin functions */
    void d_cnjg(doublecomplex *, doublecomplex *);
    integer f_rew(alist *), s_rsue(cilist *), do_uio(integer *, char *, 
	    ftnlen), e_rsue(void);

    /* Local variables */
    integer i__, j, k, ia, ib, ic, kk, nop;
    doublecomplex sum;
    doublereal fnop;
    integer npeq, nrow;
    doublereal fnorm;
    extern /* Subroutine */ int solve_(integer *, doublecomplex *, integer *, 
	    doublecomplex *, integer *), ltsolv_(doublecomplex *, integer *, 
	    integer *, doublecomplex *, integer *, integer *, integer *, 
	    integer *);

    /* Fortran I/O blocks */
    static cilist io___2259 = { 0, 0, 0, 0, 0 };


/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* Max number of segments 	(Windows-95 <= 4 */
/* max nr of 'in-core' alloc.	(MAXMAT <= MA */
/* Max number of LD cards */
/* Max number of EX cards */
/* Max number of segs connected to NT/TL */
/* *** */

/*     SUBROUTINE SOLVES, FOR SYMMETRIC STRUCTURES, HANDLES THE */
/*     TRANSFORMATION OF THE RIGHT HAND SIDE VECTOR AND SOLUTION OF THE */
/*     MATRIX EQ. */

    /* Parameter adjustments */
    --a;
    --ip;
    b_dim1 = *neq;
    b_offset = 1 + b_dim1;
    b -= b_offset;

    /* Function Body */
    npeq = *np + (*mp << 1);
    nop = *neq / npeq;
    fnop = (doublereal) nop;
    fnorm = 1.f / fnop;
    nrow = *neq;
    if (matpar_1.icase > 3) {
	nrow = npeq;
    }
    if (nop == 1) {
	goto L11;
    }
    i__1 = *nrh;
    for (ic = 1; ic <= i__1; ++ic) {
	if (*n == 0 || *m == 0) {
	    goto L6;
	}
	i__2 = *neq;
	for (i__ = 1; i__ <= i__2; ++i__) {
/* L1: */
	    i__3 = i__ - 1;
	    i__4 = i__ + ic * b_dim1;
	    scratm_2.y[i__3].r = b[i__4].r, scratm_2.y[i__3].i = b[i__4].i;
	}
	kk = *mp << 1;
	ia = *np;
	ib = *n;
	j = *np;
	i__3 = nop;
	for (k = 1; k <= i__3; ++k) {
	    if (k == 1) {
		goto L3;
	    }
	    i__4 = *np;
	    for (i__ = 1; i__ <= i__4; ++i__) {
		++ia;
		++j;
/* L2: */
		i__2 = j + ic * b_dim1;
		i__5 = ia - 1;
		b[i__2].r = scratm_2.y[i__5].r, b[i__2].i = scratm_2.y[i__5]
			.i;
	    }
	    if (k == nop) {
		goto L5;
	    }
L3:
	    i__2 = kk;
	    for (i__ = 1; i__ <= i__2; ++i__) {
		++ib;
		++j;
/* L4: */
		i__5 = j + ic * b_dim1;
		i__4 = ib - 1;
		b[i__5].r = scratm_2.y[i__4].r, b[i__5].i = scratm_2.y[i__4]
			.i;
	    }
L5:
	    ;
	}

/*     TRANSFORM MATRIX EQ. RHS VECTOR ACCORDING TO SYMMETRY MODES */

L6:
	i__3 = npeq;
	for (i__ = 1; i__ <= i__3; ++i__) {
	    i__5 = nop;
	    for (k = 1; k <= i__5; ++k) {
		ia = i__ + (k - 1) * npeq;
/* L7: */
		i__4 = k - 1;
		i__2 = ia + ic * b_dim1;
		scratm_2.y[i__4].r = b[i__2].r, scratm_2.y[i__4].i = b[i__2]
			.i;
	    }
	    sum.r = scratm_2.y[0].r, sum.i = scratm_2.y[0].i;
	    i__4 = nop;
	    for (k = 2; k <= i__4; ++k) {
/* L8: */
		i__2 = k - 1;
		z__1.r = sum.r + scratm_2.y[i__2].r, z__1.i = sum.i + 
			scratm_2.y[i__2].i;
		sum.r = z__1.r, sum.i = z__1.i;
	    }
	    i__2 = i__ + ic * b_dim1;
	    z__1.r = fnorm * sum.r, z__1.i = fnorm * sum.i;
	    b[i__2].r = z__1.r, b[i__2].i = z__1.i;
	    i__2 = nop;
	    for (k = 2; k <= i__2; ++k) {
		ia = i__ + (k - 1) * npeq;
		sum.r = scratm_2.y[0].r, sum.i = scratm_2.y[0].i;
		i__4 = nop;
		for (j = 2; j <= i__4; ++j) {
/* L9: */
		    i__5 = j - 1;
		    d_cnjg(&z__3, &smat_1.ssx[k + (j << 4) - 17]);
		    z__2.r = scratm_2.y[i__5].r * z__3.r - scratm_2.y[i__5].i 
			    * z__3.i, z__2.i = scratm_2.y[i__5].r * z__3.i + 
			    scratm_2.y[i__5].i * z__3.r;
		    z__1.r = sum.r + z__2.r, z__1.i = sum.i + z__2.i;
		    sum.r = z__1.r, sum.i = z__1.i;
		}
/* L10: */
		i__5 = ia + ic * b_dim1;
		z__1.r = fnorm * sum.r, z__1.i = fnorm * sum.i;
		b[i__5].r = z__1.r, b[i__5].i = z__1.i;
	    }
	}
    }
L11:
    if (matpar_1.icase < 3) {
	goto L12;
    }
    al__1.aerr = 0;
    al__1.aunit = *ifl1;
    f_rew(&al__1);
    al__1.aerr = 0;
    al__1.aunit = *ifl2;
    f_rew(&al__1);

/*     SOLVE EACH MODE EQUATION */

L12:
    i__5 = nop;
    for (kk = 1; kk <= i__5; ++kk) {
	ia = (kk - 1) * npeq + 1;
	ib = ia;
	if (matpar_1.icase != 4) {
	    goto L13;
	}
	i__ = npeq * npeq;
	io___2259.ciunit = *ifl1;
	s_rsue(&io___2259);
	i__2 = i__;
	for (j = 1; j <= i__2; ++j) {
	    do_uio(&c__2, (char *)&a[j], (ftnlen)sizeof(doublereal));
	}
	e_rsue();
	ib = 1;
L13:
	if (matpar_1.icase == 3 || matpar_1.icase == 5) {
	    goto L15;
	}
	i__2 = *nrh;
	for (ic = 1; ic <= i__2; ++ic) {
/* L14: */
	    solve_(&npeq, &a[ib], &ip[ia], &b[ia + ic * b_dim1], &nrow);
	}
	goto L16;
L15:
	ltsolv_(&a[1], &npeq, &ip[ia], &b[ia + b_dim1], neq, nrh, ifl1, ifl2);
L16:
	;
    }
    if (nop == 1) {
	return 0;
    }

/*     INVERSE TRANSFORM THE MODE SOLUTIONS */

    i__5 = *nrh;
    for (ic = 1; ic <= i__5; ++ic) {
	i__2 = npeq;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    i__3 = nop;
	    for (k = 1; k <= i__3; ++k) {
		ia = i__ + (k - 1) * npeq;
/* L17: */
		i__1 = k - 1;
		i__4 = ia + ic * b_dim1;
		scratm_2.y[i__1].r = b[i__4].r, scratm_2.y[i__1].i = b[i__4]
			.i;
	    }
	    sum.r = scratm_2.y[0].r, sum.i = scratm_2.y[0].i;
	    i__1 = nop;
	    for (k = 2; k <= i__1; ++k) {
/* L18: */
		i__4 = k - 1;
		z__1.r = sum.r + scratm_2.y[i__4].r, z__1.i = sum.i + 
			scratm_2.y[i__4].i;
		sum.r = z__1.r, sum.i = z__1.i;
	    }
	    i__4 = i__ + ic * b_dim1;
	    b[i__4].r = sum.r, b[i__4].i = sum.i;
	    i__4 = nop;
	    for (k = 2; k <= i__4; ++k) {
		ia = i__ + (k - 1) * npeq;
		sum.r = scratm_2.y[0].r, sum.i = scratm_2.y[0].i;
		i__1 = nop;
		for (j = 2; j <= i__1; ++j) {
/* L19: */
		    i__3 = j - 1;
		    i__6 = k + (j << 4) - 17;
		    z__2.r = scratm_2.y[i__3].r * smat_1.ssx[i__6].r - 
			    scratm_2.y[i__3].i * smat_1.ssx[i__6].i, z__2.i = 
			    scratm_2.y[i__3].r * smat_1.ssx[i__6].i + 
			    scratm_2.y[i__3].i * smat_1.ssx[i__6].r;
		    z__1.r = sum.r + z__2.r, z__1.i = sum.i + z__2.i;
		    sum.r = z__1.r, sum.i = z__1.i;
		}
/* L20: */
		i__3 = ia + ic * b_dim1;
		b[i__3].r = sum.r, b[i__3].i = sum.i;
	    }
	}
	if (*n == 0 || *m == 0) {
	    goto L26;
	}
	i__3 = *neq;
	for (i__ = 1; i__ <= i__3; ++i__) {
/* L21: */
	    i__4 = i__ - 1;
	    i__2 = i__ + ic * b_dim1;
	    scratm_2.y[i__4].r = b[i__2].r, scratm_2.y[i__4].i = b[i__2].i;
	}
	kk = *mp << 1;
	ia = *np;
	ib = *n;
	j = *np;
	i__4 = nop;
	for (k = 1; k <= i__4; ++k) {
	    if (k == 1) {
		goto L23;
	    }
	    i__2 = *np;
	    for (i__ = 1; i__ <= i__2; ++i__) {
		++ia;
		++j;
/* L22: */
		i__3 = ia + ic * b_dim1;
		i__6 = j - 1;
		b[i__3].r = scratm_2.y[i__6].r, b[i__3].i = scratm_2.y[i__6]
			.i;
	    }
	    if (k == nop) {
		goto L25;
	    }
L23:
	    i__3 = kk;
	    for (i__ = 1; i__ <= i__3; ++i__) {
		++ib;
		++j;
/* L24: */
		i__6 = ib + ic * b_dim1;
		i__2 = j - 1;
		b[i__6].r = scratm_2.y[i__2].r, b[i__6].i = scratm_2.y[i__2]
			.i;
	    }
L25:
	    ;
	}
L26:
	;
    }
    return 0;
} /* solves_ */

/* Subroutine */ int tbf_(integer *i__, integer *icap)
{
    /* Initialized data */

    static doublereal pi = 3.141592654;
    static integer jmax = 30;

    /* Format strings */
    static char fmt_29[] = "(\002 TBF - SEGMENT CONNECTION ERROR FOR SEGMEN"
	    "T\002,i5)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    double sin(doublereal), cos(doublereal), log(doublereal);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    doublereal d__, cd, aj, ap, sd, pp, pm, qp, qm, cdh, sdh, omc, sig, xxi;
    integer iend, jend, jcox, njun1, njun2, jsnop;

    /* Fortran I/O blocks */
    static cilist io___2282 = { 0, 3, 0, fmt_29, 0 };


/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* Max number of segments 	(Windows-95 <= 4 */
/* max nr of 'in-core' alloc.	(MAXMAT <= MA */
/* Max number of LD cards */
/* Max number of EX cards */
/* Max number of segs connected to NT/TL */
/* *** */
/*     COMPUTE BASIS FUNCTION I */
    segj_1.jsno = 0;
    pp = 0.f;
    jcox = data_1.icon1[*i__ - 1];
    if (jcox > 10000) {
	jcox = *i__;
    }
    jend = -1;
    iend = -1;
    sig = -1.f;
    if (jcox < 0) {
	goto L1;
    } else if (jcox == 0) {
	goto L10;
    } else {
	goto L2;
    }
L1:
    jcox = -jcox;
    goto L3;
L2:
    sig = -sig;
    jend = -jend;
L3:
    ++segj_1.jsno;
    if (segj_1.jsno >= jmax) {
	goto L28;
    }
    segj_1.jco[segj_1.jsno - 1] = jcox;
    d__ = pi * data_1.si[jcox - 1];
    sdh = sin(d__);
    cdh = cos(d__);
    sd = sdh * 2.f * cdh;
    if (d__ > .015f) {
	goto L4;
    }
    omc = d__ * 4.f * d__;
    omc = ((omc * .0013888889 - .041666666667) * omc + .5f) * omc;
    goto L5;
L4:
    omc = 1.f - cdh * cdh + sdh * sdh;
L5:
    aj = 1.f / (log(1.f / (pi * data_1.bi[jcox - 1])) - .577215664);
    pp -= omc / sd * aj;
    segj_1.ax[segj_1.jsno - 1] = aj / sd * sig;
    segj_1.bx[segj_1.jsno - 1] = aj / (cdh * 2.f);
    segj_1.cx[segj_1.jsno - 1] = -aj / (sdh * 2.f) * sig;
    if (jcox == *i__) {
	goto L8;
    }
    if (jend == 1) {
	goto L6;
    }
    jcox = data_1.icon1[jcox - 1];
    goto L7;
L6:
    jcox = data_1.icon2[jcox - 1];
L7:
    if (abs(jcox) == *i__) {
	goto L9;
    }
    if (jcox < 0) {
	goto L1;
    } else if (jcox == 0) {
	goto L28;
    } else {
	goto L2;
    }
L8:
    segj_1.bx[segj_1.jsno - 1] = -segj_1.bx[segj_1.jsno - 1];
L9:
    if (iend == 1) {
	goto L11;
    }
L10:
    pm = -pp;
    pp = 0.f;
    njun1 = segj_1.jsno;
    jcox = data_1.icon2[*i__ - 1];
    if (jcox > 10000) {
	jcox = *i__;
    }
    jend = 1;
    iend = 1;
    sig = -1.f;
    if (jcox < 0) {
	goto L1;
    } else if (jcox == 0) {
	goto L11;
    } else {
	goto L2;
    }
L11:
    njun2 = segj_1.jsno - njun1;
    jsnop = segj_1.jsno + 1;
    segj_1.jco[jsnop - 1] = *i__;
    d__ = pi * data_1.si[*i__ - 1];
    sdh = sin(d__);
    cdh = cos(d__);
    sd = sdh * 2.f * cdh;
    cd = cdh * cdh - sdh * sdh;
    if (d__ > .015f) {
	goto L12;
    }
    omc = d__ * 4.f * d__;
    omc = ((omc * .0013888889 - .041666666667) * omc + .5f) * omc;
    goto L13;
L12:
    omc = 1.f - cd;
L13:
    ap = 1.f / (log(1.f / (pi * data_1.bi[*i__ - 1])) - .577215664);
    aj = ap;
    if (njun1 == 0) {
	goto L16;
    }
    if (njun2 == 0) {
	goto L20;
    }
    qp = sd * (pm * pp + aj * ap) + cd * (pm * ap - pp * aj);
    qm = (ap * omc - pp * sd) / qp;
    qp = -(aj * omc + pm * sd) / qp;
    segj_1.bx[jsnop - 1] = (aj * qm + ap * qp) * sdh / sd;
    segj_1.cx[jsnop - 1] = (aj * qm - ap * qp) * cdh / sd;
    i__1 = njun1;
    for (iend = 1; iend <= i__1; ++iend) {
	segj_1.ax[iend - 1] *= qm;
	segj_1.bx[iend - 1] *= qm;
/* L14: */
	segj_1.cx[iend - 1] *= qm;
    }
    jend = njun1 + 1;
    i__1 = segj_1.jsno;
    for (iend = jend; iend <= i__1; ++iend) {
	segj_1.ax[iend - 1] = -segj_1.ax[iend - 1] * qp;
	segj_1.bx[iend - 1] *= qp;
/* L15: */
	segj_1.cx[iend - 1] = -segj_1.cx[iend - 1] * qp;
    }
    goto L27;
L16:
    if (njun2 == 0) {
	goto L24;
    }
    if (*icap != 0) {
	goto L17;
    }
    xxi = 0.f;
    goto L18;
L17:
    qp = pi * data_1.bi[*i__ - 1];
    xxi = qp * qp;
    xxi = qp * (1.f - xxi * .5f) / (1.f - xxi);
L18:
    qp = -(omc + xxi * sd) / (sd * (ap + xxi * pp) + cd * (xxi * ap - pp));
    d__ = cd - xxi * sd;
    segj_1.bx[jsnop - 1] = (sdh + ap * qp * (cdh - xxi * sdh)) / d__;
    segj_1.cx[jsnop - 1] = (cdh + ap * qp * (sdh + xxi * cdh)) / d__;
    i__1 = njun2;
    for (iend = 1; iend <= i__1; ++iend) {
	segj_1.ax[iend - 1] = -segj_1.ax[iend - 1] * qp;
	segj_1.bx[iend - 1] *= qp;
/* L19: */
	segj_1.cx[iend - 1] = -segj_1.cx[iend - 1] * qp;
    }
    goto L27;
L20:
    if (*icap != 0) {
	goto L21;
    }
    xxi = 0.f;
    goto L22;
L21:
    qm = pi * data_1.bi[*i__ - 1];
    xxi = qm * qm;
    xxi = qm * (1.f - xxi * .5f) / (1.f - xxi);
L22:
    qm = (omc + xxi * sd) / (sd * (aj - xxi * pm) + cd * (pm + xxi * aj));
    d__ = cd - xxi * sd;
    segj_1.bx[jsnop - 1] = (aj * qm * (cdh - xxi * sdh) - sdh) / d__;
    segj_1.cx[jsnop - 1] = (cdh - aj * qm * (sdh + xxi * cdh)) / d__;
    i__1 = njun1;
    for (iend = 1; iend <= i__1; ++iend) {
	segj_1.ax[iend - 1] *= qm;
	segj_1.bx[iend - 1] *= qm;
/* L23: */
	segj_1.cx[iend - 1] *= qm;
    }
    goto L27;
L24:
    segj_1.bx[jsnop - 1] = 0.f;
    if (*icap != 0) {
	goto L25;
    }
    xxi = 0.f;
    goto L26;
L25:
    qp = pi * data_1.bi[*i__ - 1];
    xxi = qp * qp;
    xxi = qp * (1.f - xxi * .5f) / (1.f - xxi);
L26:
    segj_1.cx[jsnop - 1] = 1.f / (cdh - xxi * sdh);
L27:
    segj_1.jsno = jsnop;
    segj_1.ax[segj_1.jsno - 1] = -1.f;
    return 0;
L28:
    s_wsfe(&io___2282);
    do_fio(&c__1, (char *)&(*i__), (ftnlen)sizeof(integer));
    e_wsfe();
    s_stop("", (ftnlen)0);

    return 0;
} /* tbf_ */

/* Subroutine */ int test_(doublereal *f1r, doublereal *f2r, doublereal *tr, 
	doublereal *f1i, doublereal *f2i, doublereal *ti, doublereal *dmin__)
{
    /* System generated locals */
    doublereal d__1;

    /* Local variables */
    doublereal den;

/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* *** */

/*     TEST FOR CONVERGENCE IN NUMERICAL INTEGRATION */

    den = abs(*f2r);
    *tr = abs(*f2i);
    if (den < *tr) {
	den = *tr;
    }
    if (den < *dmin__) {
	den = *dmin__;
    }
    if (den < 1e-37) {
	goto L1;
    }
    *tr = (d__1 = (*f1r - *f2r) / den, abs(d__1));
    *ti = (d__1 = (*f1i - *f2i) / den, abs(d__1));
    return 0;
L1:
    *tr = 0.f;
    *ti = 0.f;
    return 0;
} /* test_ */

/* Subroutine */ int trio_(integer *j)
{
    /* Initialized data */

    static integer jmax = 30;

    /* Format strings */
    static char fmt_10[] = "(\002 TRIO - SEGMENT CONNENTION ERROR FOR SEGM"
	    "ENT\002,i5)";

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int sbf_(integer *, integer *, doublereal *, 
	    doublereal *, doublereal *);
    integer iend, jend, jcox;

    /* Fortran I/O blocks */
    static cilist io___2288 = { 0, 3, 0, fmt_10, 0 };


/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* Max number of segments 	(Windows-95 <= 4 */
/* max nr of 'in-core' alloc.	(MAXMAT <= MA */
/* Max number of LD cards */
/* Max number of EX cards */
/* Max number of segs connected to NT/TL */
/* *** */
/*     COMPUTE THE COMPONENTS OF ALL BASIS FUNCTIONS ON SEGMENT J */
    segj_1.jsno = 0;
    jcox = data_1.icon1[*j - 1];
    if (jcox > 10000) {
	goto L7;
    }
    jend = -1;
    iend = -1;
    if (jcox < 0) {
	goto L1;
    } else if (jcox == 0) {
	goto L7;
    } else {
	goto L2;
    }
L1:
    jcox = -jcox;
    goto L3;
L2:
    jend = -jend;
L3:
    if (jcox == *j) {
	goto L6;
    }
    ++segj_1.jsno;
    if (segj_1.jsno >= jmax) {
	goto L9;
    }
    sbf_(&jcox, j, &segj_1.ax[segj_1.jsno - 1], &segj_1.bx[segj_1.jsno - 1], &
	    segj_1.cx[segj_1.jsno - 1]);
    segj_1.jco[segj_1.jsno - 1] = jcox;
    if (jend == 1) {
	goto L4;
    }
    jcox = data_1.icon1[jcox - 1];
    goto L5;
L4:
    jcox = data_1.icon2[jcox - 1];
L5:
    if (jcox < 0) {
	goto L1;
    } else if (jcox == 0) {
	goto L9;
    } else {
	goto L2;
    }
L6:
    if (iend == 1) {
	goto L8;
    }
L7:
    jcox = data_1.icon2[*j - 1];
    if (jcox > 10000) {
	goto L8;
    }
    jend = 1;
    iend = 1;
    if (jcox < 0) {
	goto L1;
    } else if (jcox == 0) {
	goto L8;
    } else {
	goto L2;
    }
L8:
    ++segj_1.jsno;
    sbf_(j, j, &segj_1.ax[segj_1.jsno - 1], &segj_1.bx[segj_1.jsno - 1], &
	    segj_1.cx[segj_1.jsno - 1]);
    segj_1.jco[segj_1.jsno - 1] = *j;
    return 0;
L9:
    s_wsfe(&io___2288);
    do_fio(&c__1, (char *)&(*j), (ftnlen)sizeof(integer));
    e_wsfe();
    s_stop("", (ftnlen)0);

    return 0;
} /* trio_ */

/* Subroutine */ int unere_(doublereal *xob, doublereal *yob, doublereal *zob)
{
    /* Initialized data */

    static doublereal tpi = 6.283185308;
    static doublereal const__ = 4.771341188;

    /* System generated locals */
    doublereal d__1, d__2, d__3;
    doublecomplex z__1, z__2, z__3, z__4, z__5;

    /* Builtin functions */
    double sqrt(doublereal), cos(doublereal), sin(doublereal);
    void z_sqrt(doublecomplex *, doublecomplex *), z_div(doublecomplex *, 
	    doublecomplex *, doublecomplex *);

    /* Local variables */
    doublereal r__;
    doublecomplex q1, q2;
    doublereal r2;
    doublecomplex er;
    doublereal rt, px, py, rx, ry, zr, rz, tt1, tt2;
    doublecomplex edp;
    doublereal cth;
    doublecomplex rrh, rrv;
#define t1xj ((doublereal *)&dataj_1 + 5)
#define t1yj ((doublereal *)&dataj_1 + 6)
#define t1zj ((doublereal *)&dataj_1 + 7)
#define t2xj ((doublereal *)&dataj_1 + 1)
#define t2yj ((doublereal *)&dataj_1 + 27)
#define t2zj ((doublereal *)&dataj_1 + 28)
    doublereal t1zr, t2zr, xymag;

/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* *** */
/*     CALCULATES THE ELECTRIC FIELD DUE TO UNIT CURRENT IN THE T1 AND T2 */
/*     DIRECTIONS ON A PATCH */
/*     CONST=ETA/(8.*PI**2) */
    zr = dataj_1.zj;
    t1zr = *t1zj;
    t2zr = *t2zj;
    if (dataj_1.ipgnd != 2) {
	goto L1;
    }
    zr = -zr;
    t1zr = -t1zr;
    t2zr = -t2zr;
L1:
    rx = *xob - dataj_1.xj;
    ry = *yob - dataj_1.yj;
    rz = *zob - zr;
    r2 = rx * rx + ry * ry + rz * rz;
    if (r2 > 1e-20) {
	goto L2;
    }
    dataj_1.exk.r = 0.f, dataj_1.exk.i = 0.f;
    dataj_1.eyk.r = 0.f, dataj_1.eyk.i = 0.f;
    dataj_1.ezk.r = 0.f, dataj_1.ezk.i = 0.f;
    dataj_1.exs.r = 0.f, dataj_1.exs.i = 0.f;
    dataj_1.eys.r = 0.f, dataj_1.eys.i = 0.f;
    dataj_1.ezs.r = 0.f, dataj_1.ezs.i = 0.f;
    return 0;
L2:
    r__ = sqrt(r2);
    tt1 = -tpi * r__;
    tt2 = tt1 * tt1;
    rt = r2 * r__;
    d__1 = sin(tt1);
    d__2 = -cos(tt1);
    z__2.r = d__1, z__2.i = d__2;
    d__3 = const__ * dataj_1.s;
    z__1.r = d__3 * z__2.r, z__1.i = d__3 * z__2.i;
    er.r = z__1.r, er.i = z__1.i;
    d__1 = tt2 - 1.f;
    z__3.r = d__1, z__3.i = tt1;
    z__2.r = z__3.r * er.r - z__3.i * er.i, z__2.i = z__3.r * er.i + z__3.i * 
	    er.r;
    z__1.r = z__2.r / rt, z__1.i = z__2.i / rt;
    q1.r = z__1.r, q1.i = z__1.i;
    d__1 = 3.f - tt2;
    d__2 = tt1 * -3.f;
    z__3.r = d__1, z__3.i = d__2;
    z__2.r = z__3.r * er.r - z__3.i * er.i, z__2.i = z__3.r * er.i + z__3.i * 
	    er.r;
    d__3 = rt * r2;
    z__1.r = z__2.r / d__3, z__1.i = z__2.i / d__3;
    q2.r = z__1.r, q2.i = z__1.i;
    d__1 = *t1xj * rx + *t1yj * ry + t1zr * rz;
    z__1.r = d__1 * q2.r, z__1.i = d__1 * q2.i;
    er.r = z__1.r, er.i = z__1.i;
    z__2.r = *t1xj * q1.r, z__2.i = *t1xj * q1.i;
    z__3.r = rx * er.r, z__3.i = rx * er.i;
    z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
    dataj_1.exk.r = z__1.r, dataj_1.exk.i = z__1.i;
    z__2.r = *t1yj * q1.r, z__2.i = *t1yj * q1.i;
    z__3.r = ry * er.r, z__3.i = ry * er.i;
    z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
    dataj_1.eyk.r = z__1.r, dataj_1.eyk.i = z__1.i;
    z__2.r = t1zr * q1.r, z__2.i = t1zr * q1.i;
    z__3.r = rz * er.r, z__3.i = rz * er.i;
    z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
    dataj_1.ezk.r = z__1.r, dataj_1.ezk.i = z__1.i;
    d__1 = *t2xj * rx + *t2yj * ry + t2zr * rz;
    z__1.r = d__1 * q2.r, z__1.i = d__1 * q2.i;
    er.r = z__1.r, er.i = z__1.i;
    z__2.r = *t2xj * q1.r, z__2.i = *t2xj * q1.i;
    z__3.r = rx * er.r, z__3.i = rx * er.i;
    z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
    dataj_1.exs.r = z__1.r, dataj_1.exs.i = z__1.i;
    z__2.r = *t2yj * q1.r, z__2.i = *t2yj * q1.i;
    z__3.r = ry * er.r, z__3.i = ry * er.i;
    z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
    dataj_1.eys.r = z__1.r, dataj_1.eys.i = z__1.i;
    z__2.r = t2zr * q1.r, z__2.i = t2zr * q1.i;
    z__3.r = rz * er.r, z__3.i = rz * er.i;
    z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
    dataj_1.ezs.r = z__1.r, dataj_1.ezs.i = z__1.i;
    if (dataj_1.ipgnd == 1) {
	goto L6;
    }
    if (gnd_1.iperf != 1) {
	goto L3;
    }
    z__1.r = -dataj_1.exk.r, z__1.i = -dataj_1.exk.i;
    dataj_1.exk.r = z__1.r, dataj_1.exk.i = z__1.i;
    z__1.r = -dataj_1.eyk.r, z__1.i = -dataj_1.eyk.i;
    dataj_1.eyk.r = z__1.r, dataj_1.eyk.i = z__1.i;
    z__1.r = -dataj_1.ezk.r, z__1.i = -dataj_1.ezk.i;
    dataj_1.ezk.r = z__1.r, dataj_1.ezk.i = z__1.i;
    z__1.r = -dataj_1.exs.r, z__1.i = -dataj_1.exs.i;
    dataj_1.exs.r = z__1.r, dataj_1.exs.i = z__1.i;
    z__1.r = -dataj_1.eys.r, z__1.i = -dataj_1.eys.i;
    dataj_1.eys.r = z__1.r, dataj_1.eys.i = z__1.i;
    z__1.r = -dataj_1.ezs.r, z__1.i = -dataj_1.ezs.i;
    dataj_1.ezs.r = z__1.r, dataj_1.ezs.i = z__1.i;
    goto L6;
L3:
    xymag = sqrt(rx * rx + ry * ry);
    if (xymag > 1e-6) {
	goto L4;
    }
    px = 0.f;
    py = 0.f;
    cth = 1.f;
    rrv.r = 1.f, rrv.i = 0.f;
    goto L5;
L4:
    px = -ry / xymag;
    py = rx / xymag;
    cth = rz / sqrt(xymag * xymag + rz * rz);
    z__4.r = gnd_1.zrati.r * gnd_1.zrati.r - gnd_1.zrati.i * gnd_1.zrati.i, 
	    z__4.i = gnd_1.zrati.r * gnd_1.zrati.i + gnd_1.zrati.i * 
	    gnd_1.zrati.r;
    d__1 = 1.f - cth * cth;
    z__3.r = d__1 * z__4.r, z__3.i = d__1 * z__4.i;
    z__2.r = 1.f - z__3.r, z__2.i = -z__3.i;
    z_sqrt(&z__1, &z__2);
    rrv.r = z__1.r, rrv.i = z__1.i;
L5:
    z__1.r = cth * gnd_1.zrati.r, z__1.i = cth * gnd_1.zrati.i;
    rrh.r = z__1.r, rrh.i = z__1.i;
    z__2.r = rrh.r - rrv.r, z__2.i = rrh.i - rrv.i;
    z__3.r = rrh.r + rrv.r, z__3.i = rrh.i + rrv.i;
    z_div(&z__1, &z__2, &z__3);
    rrh.r = z__1.r, rrh.i = z__1.i;
    z__1.r = gnd_1.zrati.r * rrv.r - gnd_1.zrati.i * rrv.i, z__1.i = 
	    gnd_1.zrati.r * rrv.i + gnd_1.zrati.i * rrv.r;
    rrv.r = z__1.r, rrv.i = z__1.i;
    z__3.r = cth - rrv.r, z__3.i = -rrv.i;
    z__2.r = -z__3.r, z__2.i = -z__3.i;
    z__4.r = cth + rrv.r, z__4.i = rrv.i;
    z_div(&z__1, &z__2, &z__4);
    rrv.r = z__1.r, rrv.i = z__1.i;
    z__3.r = px * dataj_1.exk.r, z__3.i = px * dataj_1.exk.i;
    z__4.r = py * dataj_1.eyk.r, z__4.i = py * dataj_1.eyk.i;
    z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
    z__5.r = rrh.r - rrv.r, z__5.i = rrh.i - rrv.i;
    z__1.r = z__2.r * z__5.r - z__2.i * z__5.i, z__1.i = z__2.r * z__5.i + 
	    z__2.i * z__5.r;
    edp.r = z__1.r, edp.i = z__1.i;
    z__2.r = dataj_1.exk.r * rrv.r - dataj_1.exk.i * rrv.i, z__2.i = 
	    dataj_1.exk.r * rrv.i + dataj_1.exk.i * rrv.r;
    z__3.r = px * edp.r, z__3.i = px * edp.i;
    z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
    dataj_1.exk.r = z__1.r, dataj_1.exk.i = z__1.i;
    z__2.r = dataj_1.eyk.r * rrv.r - dataj_1.eyk.i * rrv.i, z__2.i = 
	    dataj_1.eyk.r * rrv.i + dataj_1.eyk.i * rrv.r;
    z__3.r = py * edp.r, z__3.i = py * edp.i;
    z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
    dataj_1.eyk.r = z__1.r, dataj_1.eyk.i = z__1.i;
    z__1.r = dataj_1.ezk.r * rrv.r - dataj_1.ezk.i * rrv.i, z__1.i = 
	    dataj_1.ezk.r * rrv.i + dataj_1.ezk.i * rrv.r;
    dataj_1.ezk.r = z__1.r, dataj_1.ezk.i = z__1.i;
    z__3.r = px * dataj_1.exs.r, z__3.i = px * dataj_1.exs.i;
    z__4.r = py * dataj_1.eys.r, z__4.i = py * dataj_1.eys.i;
    z__2.r = z__3.r + z__4.r, z__2.i = z__3.i + z__4.i;
    z__5.r = rrh.r - rrv.r, z__5.i = rrh.i - rrv.i;
    z__1.r = z__2.r * z__5.r - z__2.i * z__5.i, z__1.i = z__2.r * z__5.i + 
	    z__2.i * z__5.r;
    edp.r = z__1.r, edp.i = z__1.i;
    z__2.r = dataj_1.exs.r * rrv.r - dataj_1.exs.i * rrv.i, z__2.i = 
	    dataj_1.exs.r * rrv.i + dataj_1.exs.i * rrv.r;
    z__3.r = px * edp.r, z__3.i = px * edp.i;
    z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
    dataj_1.exs.r = z__1.r, dataj_1.exs.i = z__1.i;
    z__2.r = dataj_1.eys.r * rrv.r - dataj_1.eys.i * rrv.i, z__2.i = 
	    dataj_1.eys.r * rrv.i + dataj_1.eys.i * rrv.r;
    z__3.r = py * edp.r, z__3.i = py * edp.i;
    z__1.r = z__2.r + z__3.r, z__1.i = z__2.i + z__3.i;
    dataj_1.eys.r = z__1.r, dataj_1.eys.i = z__1.i;
    z__1.r = dataj_1.ezs.r * rrv.r - dataj_1.ezs.i * rrv.i, z__1.i = 
	    dataj_1.ezs.r * rrv.i + dataj_1.ezs.i * rrv.r;
    dataj_1.ezs.r = z__1.r, dataj_1.ezs.i = z__1.i;
L6:
    return 0;
} /* unere_ */

#undef t2zj
#undef t2yj
#undef t2xj
#undef t1zj
#undef t1yj
#undef t1xj


/* Subroutine */ int wire_(doublereal *xw1, doublereal *yw1, doublereal *zw1, 
	doublereal *xw2, doublereal *yw2, doublereal *zw2, doublereal *rad, 
	doublereal *rdel, doublereal *rrad, integer *ns, integer *itg)
{
    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    double sqrt(doublereal), pow_di(doublereal *, integer *);

    /* Local variables */
    integer i__;
#define x2 ((doublereal *)&data_1 + 4500)
#define y2 ((doublereal *)&data_1 + 7500)
#define z2 ((doublereal *)&data_1 + 9000)
    doublereal rd, xd, yd, zd, xs1, ys1, zs1, xs2, ys2, zs2, fns;
    integer ist;
    doublereal delz, radz;

/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* Max number of segments 	(Windows-95 <= 4 */
/* max nr of 'in-core' alloc.	(MAXMAT <= MA */
/* Max number of LD cards */
/* Max number of EX cards */
/* Max number of segs connected to NT/TL */
/* *** */

/*     SUBROUTINE WIRE GENERATES SEGMENT GEOMETRY DATA FOR A STRAIGHT */
/*     WIRE OF NS SEGMENTS. */

    ist = data_1.n + 1;
    data_1.n += *ns;
    data_1.np = data_1.n;
    data_1.mp = data_1.m;
    data_1.ipsym = 0;
    if (*ns < 1) {
	return 0;
    }
    xd = *xw2 - *xw1;
    yd = *yw2 - *yw1;
    zd = *zw2 - *zw1;
    if ((d__1 = *rdel - 1.f, abs(d__1)) < 1e-6) {
	goto L1;
    }
    delz = sqrt(xd * xd + yd * yd + zd * zd);
    xd /= delz;
    yd /= delz;
    zd /= delz;
    delz = delz * (1.f - *rdel) / (1.f - pow_di(rdel, ns));
    rd = *rdel;
    goto L2;
L1:
    fns = (doublereal) (*ns);
    xd /= fns;
    yd /= fns;
    zd /= fns;
    delz = 1.f;
    rd = 1.f;
L2:
    radz = *rad;
    xs1 = *xw1;
    ys1 = *yw1;
    zs1 = *zw1;
    i__1 = data_1.n;
    for (i__ = ist; i__ <= i__1; ++i__) {
	data_1.itag[i__ - 1] = *itg;
	xs2 = xs1 + xd * delz;
	ys2 = ys1 + yd * delz;
	zs2 = zs1 + zd * delz;
	data_1.x[i__ - 1] = xs1;
	data_1.y[i__ - 1] = ys1;
	data_1.z__[i__ - 1] = zs1;
	x2[i__ - 1] = xs2;
	y2[i__ - 1] = ys2;
	z2[i__ - 1] = zs2;
	data_1.bi[i__ - 1] = radz;
	delz *= rd;
	radz *= *rrad;
	xs1 = xs2;
	ys1 = ys2;
/* L3: */
	zs1 = zs2;
    }
    x2[data_1.n - 1] = *xw2;
    y2[data_1.n - 1] = *yw2;
    z2[data_1.n - 1] = *zw2;
    return 0;
} /* wire_ */

#undef z2
#undef y2
#undef x2


/* Double Complex */ VOID zint_(doublecomplex * ret_val, doublereal *sigl, 
	doublereal *rolam)
{
    /* Initialized data */

    static doublereal pi = 3.1415926;
    static doublereal pot = 1.5707963;
    static doublereal tp = 6.2831853;
    static doublereal tpcmu = 2368.705;
    static doublereal cmotp = 60.;
    static struct {
	doublereal e_1[2];
	} equiv_0 = { 0., 1. };

    static struct {
	doublereal e_1[2];
	} equiv_1 = { .70710678, .70710678 };

    static struct {
	doublereal e_1[28];
	} equiv_15 = { 6e-7, 1.9e-6, -3.4e-6, 5.1e-6, -2.52e-5, 0., -9.06e-5, 
		-9.01e-5, 0., -9.765e-4, .0110486, -.0110485, 0., -.3926991, 
		1.6e-6, -3.2e-6, 1.17e-5, -2.4e-6, 3.46e-5, 3.38e-5, 5e-7, 
		2.452e-4, -.0013813, .0013811, -.0625001, -1e-7, .7071068, 
		.7071068 };


    /* System generated locals */
    doublereal d__1, d__2, d__3, d__4;
    doublecomplex z__1, z__2, z__3, z__4, z__5, z__6, z__7, z__8, z__9, z__10,
	     z__11, z__12, z__13, z__14, z__15, z__16, z__17, z__18, z__19, 
	    z__20, z__21, z__22, z__23, z__24, z__25, z__26, z__27, z__28, 
	    z__29, z__30, z__31, z__32, z__33, z__34, z__35, z__36, z__37, 
	    z__38, z__39, z__40, z__41, z__42, z__43;

    /* Builtin functions */
    double sqrt(doublereal);
    void z_div(doublecomplex *, doublecomplex *, doublecomplex *), z_exp(
	    doublecomplex *, doublecomplex *);

    /* Local variables */
    doublereal s, x, y;
#define fj ((doublecomplex *)&equiv_0)
#define cn ((doublecomplex *)&equiv_1)
#define cc1 ((doublecomplex *)&equiv_15)
#define cc2 ((doublecomplex *)&equiv_15 + 1)
#define cc3 ((doublecomplex *)&equiv_15 + 2)
#define cc4 ((doublecomplex *)&equiv_15 + 3)
#define cc5 ((doublecomplex *)&equiv_15 + 4)
#define cc6 ((doublecomplex *)&equiv_15 + 5)
#define cc7 ((doublecomplex *)&equiv_15 + 6)
#define cc8 ((doublecomplex *)&equiv_15 + 7)
#define cc9 ((doublecomplex *)&equiv_15 + 8)
    doublecomplex br1, br2;
#define cc10 ((doublecomplex *)&equiv_15 + 9)
#define cc11 ((doublecomplex *)&equiv_15 + 10)
#define cc12 ((doublecomplex *)&equiv_15 + 11)
#define cc13 ((doublecomplex *)&equiv_15 + 12)
#define cc14 ((doublecomplex *)&equiv_15 + 13)
    doublereal bei;
#define ccn ((doublereal *)&equiv_15)
    doublereal ber;
#define fjx ((doublereal *)&equiv_0)
#define cnx ((doublereal *)&equiv_1)

/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/* *** */

/*     ZINT COMPUTES THE INTERNAL IMPEDANCE OF A CIRCULAR WIRE */


    x = sqrt(tpcmu * *sigl) * *rolam;
    if (x > 110.f) {
	goto L2;
    }
    if (x > 8.f) {
	goto L1;
    }
    y = x / 8.f;
    y *= y;
    s = y * y;
    ber = ((((((s * -9.01e-6 + .00122552) * s - .08349609) * s + 2.641914) * 
	    s - 32.363456) * s + 113.77778) * s - 64.f) * s + 1.f;
    bei = ((((((s * 1.1346e-4 - .01103667) * s + .52185615) * s - 10.567658) *
	     s + 72.817777) * s - 113.77778) * s + 16.f) * y;
    z__1.r = ber, z__1.i = bei;
    br1.r = z__1.r, br1.i = z__1.i;
    ber = ((((((s * -3.94e-6 + 4.5957e-4) * s - .02609253) * s + .66047849) * 
	    s - 6.0681481) * s + 14.222222) * s - 4.f) * y * x;
    bei = ((((((s * 4.609e-5 - .00379386) * s + .14677204) * s - 2.3116751) * 
	    s + 11.377778) * s - 10.666667) * s + .5f) * x;
    z__1.r = ber, z__1.i = bei;
    br2.r = z__1.r, br2.i = z__1.i;
    z_div(&z__1, &br1, &br2);
    br1.r = z__1.r, br1.i = z__1.i;
    goto L3;
L1:
    d__1 = -8.f / x;
    d__2 = sqrt(pot / x);
    z__7.r = -cn->r, z__7.i = -cn->i;
    z__6.r = x * z__7.r, z__6.i = x * z__7.i;
    z__19.r = d__1 * cc1->r, z__19.i = d__1 * cc1->i;
    z__18.r = z__19.r + cc2->r, z__18.i = z__19.i + cc2->i;
    z__17.r = d__1 * z__18.r, z__17.i = d__1 * z__18.i;
    z__16.r = z__17.r + cc3->r, z__16.i = z__17.i + cc3->i;
    z__15.r = d__1 * z__16.r, z__15.i = d__1 * z__16.i;
    z__14.r = z__15.r + cc4->r, z__14.i = z__15.i + cc4->i;
    z__13.r = d__1 * z__14.r, z__13.i = d__1 * z__14.i;
    z__12.r = z__13.r + cc5->r, z__12.i = z__13.i + cc5->i;
    z__11.r = d__1 * z__12.r, z__11.i = d__1 * z__12.i;
    z__10.r = z__11.r + cc6->r, z__10.i = z__11.i + cc6->i;
    z__9.r = d__1 * z__10.r, z__9.i = d__1 * z__10.i;
    z__8.r = z__9.r + cc7->r, z__8.i = z__9.i + cc7->i;
    z__5.r = z__6.r + z__8.r, z__5.i = z__6.i + z__8.i;
    z_exp(&z__4, &z__5);
    z__3.r = d__2 * z__4.r, z__3.i = d__2 * z__4.i;
    z__2.r = fj->r * z__3.r - fj->i * z__3.i, z__2.i = fj->r * z__3.i + fj->i 
	    * z__3.r;
    z__1.r = z__2.r / pi, z__1.i = z__2.i / pi;
    br2.r = z__1.r, br2.i = z__1.i;
    d__1 = 8.f / x;
    z__5.r = x * cn->r, z__5.i = x * cn->i;
    z__17.r = d__1 * cc1->r, z__17.i = d__1 * cc1->i;
    z__16.r = z__17.r + cc2->r, z__16.i = z__17.i + cc2->i;
    z__15.r = d__1 * z__16.r, z__15.i = d__1 * z__16.i;
    z__14.r = z__15.r + cc3->r, z__14.i = z__15.i + cc3->i;
    z__13.r = d__1 * z__14.r, z__13.i = d__1 * z__14.i;
    z__12.r = z__13.r + cc4->r, z__12.i = z__13.i + cc4->i;
    z__11.r = d__1 * z__12.r, z__11.i = d__1 * z__12.i;
    z__10.r = z__11.r + cc5->r, z__10.i = z__11.i + cc5->i;
    z__9.r = d__1 * z__10.r, z__9.i = d__1 * z__10.i;
    z__8.r = z__9.r + cc6->r, z__8.i = z__9.i + cc6->i;
    z__7.r = d__1 * z__8.r, z__7.i = d__1 * z__8.i;
    z__6.r = z__7.r + cc7->r, z__6.i = z__7.i + cc7->i;
    z__4.r = z__5.r + z__6.r, z__4.i = z__5.i + z__6.i;
    z_exp(&z__3, &z__4);
    d__2 = sqrt(tp * x);
    z__2.r = z__3.r / d__2, z__2.i = z__3.i / d__2;
    z__1.r = z__2.r + br2.r, z__1.i = z__2.i + br2.i;
    br1.r = z__1.r, br1.i = z__1.i;
    d__1 = 8.f / x;
    d__2 = 8.f / x;
    d__3 = -8.f / x;
    z__6.r = x * cn->r, z__6.i = x * cn->i;
    z__18.r = d__1 * cc1->r, z__18.i = d__1 * cc1->i;
    z__17.r = z__18.r + cc2->r, z__17.i = z__18.i + cc2->i;
    z__16.r = d__1 * z__17.r, z__16.i = d__1 * z__17.i;
    z__15.r = z__16.r + cc3->r, z__15.i = z__16.i + cc3->i;
    z__14.r = d__1 * z__15.r, z__14.i = d__1 * z__15.i;
    z__13.r = z__14.r + cc4->r, z__13.i = z__14.i + cc4->i;
    z__12.r = d__1 * z__13.r, z__12.i = d__1 * z__13.i;
    z__11.r = z__12.r + cc5->r, z__11.i = z__12.i + cc5->i;
    z__10.r = d__1 * z__11.r, z__10.i = d__1 * z__11.i;
    z__9.r = z__10.r + cc6->r, z__9.i = z__10.i + cc6->i;
    z__8.r = d__1 * z__9.r, z__8.i = d__1 * z__9.i;
    z__7.r = z__8.r + cc7->r, z__7.i = z__8.i + cc7->i;
    z__5.r = z__6.r + z__7.r, z__5.i = z__6.i + z__7.i;
    z_exp(&z__4, &z__5);
    d__4 = sqrt(tp * x);
    z__3.r = z__4.r / d__4, z__3.i = z__4.i / d__4;
    z__30.r = d__2 * cc8->r, z__30.i = d__2 * cc8->i;
    z__29.r = z__30.r + cc9->r, z__29.i = z__30.i + cc9->i;
    z__28.r = d__2 * z__29.r, z__28.i = d__2 * z__29.i;
    z__27.r = z__28.r + cc10->r, z__27.i = z__28.i + cc10->i;
    z__26.r = d__2 * z__27.r, z__26.i = d__2 * z__27.i;
    z__25.r = z__26.r + cc11->r, z__25.i = z__26.i + cc11->i;
    z__24.r = d__2 * z__25.r, z__24.i = d__2 * z__25.i;
    z__23.r = z__24.r + cc12->r, z__23.i = z__24.i + cc12->i;
    z__22.r = d__2 * z__23.r, z__22.i = d__2 * z__23.i;
    z__21.r = z__22.r + cc13->r, z__21.i = z__22.i + cc13->i;
    z__20.r = d__2 * z__21.r, z__20.i = d__2 * z__21.i;
    z__19.r = z__20.r + cc14->r, z__19.i = z__20.i + cc14->i;
    z__2.r = z__3.r * z__19.r - z__3.i * z__19.i, z__2.i = z__3.r * z__19.i + 
	    z__3.i * z__19.r;
    z__43.r = d__3 * cc8->r, z__43.i = d__3 * cc8->i;
    z__42.r = z__43.r + cc9->r, z__42.i = z__43.i + cc9->i;
    z__41.r = d__3 * z__42.r, z__41.i = d__3 * z__42.i;
    z__40.r = z__41.r + cc10->r, z__40.i = z__41.i + cc10->i;
    z__39.r = d__3 * z__40.r, z__39.i = d__3 * z__40.i;
    z__38.r = z__39.r + cc11->r, z__38.i = z__39.i + cc11->i;
    z__37.r = d__3 * z__38.r, z__37.i = d__3 * z__38.i;
    z__36.r = z__37.r + cc12->r, z__36.i = z__37.i + cc12->i;
    z__35.r = d__3 * z__36.r, z__35.i = d__3 * z__36.i;
    z__34.r = z__35.r + cc13->r, z__34.i = z__35.i + cc13->i;
    z__33.r = d__3 * z__34.r, z__33.i = d__3 * z__34.i;
    z__32.r = z__33.r + cc14->r, z__32.i = z__33.i + cc14->i;
    z__31.r = br2.r * z__32.r - br2.i * z__32.i, z__31.i = br2.r * z__32.i + 
	    br2.i * z__32.r;
    z__1.r = z__2.r - z__31.r, z__1.i = z__2.i - z__31.i;
    br2.r = z__1.r, br2.i = z__1.i;
    z_div(&z__1, &br1, &br2);
    br1.r = z__1.r, br1.i = z__1.i;
    goto L3;
L2:
    br1.r = .70710678, br1.i = -.70710678;
L3:
    d__1 = sqrt(cmotp / *sigl);
    z__3.r = d__1 * fj->r, z__3.i = d__1 * fj->i;
    z__2.r = z__3.r * br1.r - z__3.i * br1.i, z__2.i = z__3.r * br1.i + 
	    z__3.i * br1.r;
    z__1.r = z__2.r / *rolam, z__1.i = z__2.i / *rolam;
     ret_val->r = z__1.r,  ret_val->i = z__1.i;
    return ;
} /* zint_ */

#undef cnx
#undef fjx
#undef ccn
#undef cc14
#undef cc13
#undef cc12
#undef cc11
#undef cc10
#undef cc9
#undef cc8
#undef cc7
#undef cc6
#undef cc5
#undef cc4
#undef cc3
#undef cc2
#undef cc1
#undef cn
#undef fj


