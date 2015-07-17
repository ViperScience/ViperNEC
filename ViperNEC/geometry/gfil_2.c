//
//  gfil_2.c
//  ViperNEC
//
//  Created by Dylan Crocker on 7/18/14.
//  Copyright 2014 Viper Science
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

#include "types.h"
#include "blocks.h"

// The below are used to keep the code shorter and prevent more massive code
// updating since the original version (translated by f2c) used these.
#define x     ((*data).x)
#define y     ((*data).y)
#define z     ((*data).z)
#define si    ((*data).si)
#define bi    ((*data).bi)
#define alp   ((*data).alp)
#define bet   ((*data).bet)
#define wlam  ((*data).wlam)
#define icon1 ((*data).icon1)
#define icon2 ((*data).icon2)
#define itag  ((*data).itag)
#define ld    ((*data).ld)
#define n1    ((*data).n1)
#define n2    ((*data).n2)
#define n     ((*data).n)
#define np    ((*data).np)
#define m1    ((*data).m1)
#define m2    ((*data).m2)
#define m     ((*data).m)
#define mp    ((*data).mp)
#define ipsym ((*data).ipsym)
#define cm ((*cmb).cm)

#define icase  (matpar_1.icase)
#define nbloks (matpar_1.nbloks)
#define npblk  (matpar_1.npblk)
#define nlast  (matpar_1.nlast)
#define nblsym (matpar_1.nblsym)
#define npsym  (matpar_1.npsym)
#define nlsym  (matpar_1.nlsym)
#define imat   (matpar_1.imat)

#define epsr   (save_1.epsr)
#define sig    (save_1.sig)
#define scrwlt (save_1.scrwlt)
#define scrwrt (save_1.scrwrt)
#define fmhz   (save_1.fmhz)
#define ip     (save_1.ip)
#define kcom   (save_1.kcom)

#define com (csave_1.com)

#define nradl (gnd_1.nradl)
#define ksymp (gnd_1.ksymp)
#define iperf (gnd_1.iperf)

#define zarray (zload.zarray)
#define nlodf  (zload.nlodf)

#define ar1   (ggrid_1.ar1)
#define ar2   (ggrid_1.ar2)
#define ar3   (ggrid_1.ar3)
#define epscf (ggrid_1.epscf)
#define dxa   (ggrid_1.dxa)
#define dya   (ggrid_1.dya)
#define xsa   (ggrid_1.xsa)
#define ysa   (ggrid_1.ysa)
#define nxa   (ggrid_1.nxa)
#define nya   (ggrid_1.nya)

#define salp ((*angl).salp)

#define ssx (smat_1.ssx)


/*<       SUBROUTINE GFIL (IPRT) >*/

/* *** */
/*     DOUBLE PRECISION 6/4/85 */

/*<       INCLUDE 'NEC2DPAR.INC' >*/
/*<       PARAMETER (IRESRV=MAXMAT**2) >*/
/*<       PARAMETER (MAXSEG=1500, MAXMAT=1500) >*/
/*<       IMPLICIT REAL*8(A-H,O-Z) >*/
/* *** */

/*     GFIL READS THE N.G.F. FILE */

/*<       COMPLEX*16 CM,SSX,ZRATI,ZRATI2,T1,ZARRAY,AR1,AR2,AR3,EPSCF,FRATI >*/
/*<        >*/
/*<       COMMON /CMB/ CM(IRESRV) >*/
/*<       COMMON /ANGL/ SALP(MAXSEG) >*/
/*<        >*/
/*<        >*/
/*<        >*/
/*<       COMMON /SMAT/ SSX(16,16) >*/
/*<       COMMON /ZLOAD/ ZARRAY(MAXSEG),NLOAD,NLODF >*/
/*<       COMMON/SAVE/EPSR,SIG,SCRWLT,SCRWRT,FMHZ,IP(2*MAXSEG),KCOM >*/
/*<       COMMON/CSAVE/COM(19,5) >*/

/* *** ERROR CORRECTED 11/20/89 ******************************* */
/*<       DIMENSION T2X(1),T2Y(1),T2Z(1) >*/
/*<       EQUIVALENCE (T2X,ICON1),(T2Y,ICON2),(T2Z,ITAG) >*/
/* *** */
/*<       DATA IGFL/20/ >*/
/*<       OPEN(UNIT=IGFL,FILE='NGF2D.NEC',FORM='UNFORMATTED',STATUS='OLD') >*/

int gfil_2(NECDataBlock *data, NECMatrixBlock *cmb, NECAngleBlock *angl, int *iprt)
{
 
  /* Initialized data */
  
//  static int igfl = 20;
  
//  /* Format strings */
//  static char fmt_16[] = "(////)";
//  static char fmt_14[] = "(5x,\002**************************************************\002,\002**********************************\002)";
//  static char fmt_17[] = "(5x,\002**\002,80x,\002**\002)";
//  static char fmt_18[] = "(5x,\002** NUMERICAL GREEN'S FUNCTION\002,53x,\002**\002,/,5x,\002** NO. SEGMENTS =\002,i4,10x,\002NO. PATCHES =\002,i4,34x,\002**\002)";
//  static char fmt_19[] = "(5x,\002** NO. SYMMETRIC SECTIONS =\002,i4,51x,\002**\002)";
//  static char fmt_20[] = "(5x,\002** N.G.F. MATRIX -  CORE STORAGE =\002,i7,\002 COMPLEX NUMBERS,  CASE\002,i2,16x,\002**\002)";
//  static char fmt_21[] = "(5x,\002**\002,19x,\002MATRIX SIZE =\002,i7,\002 COMPLEX NUMBERS\002,25x,\002**\002)";
//  static char fmt_22[] = "(5x,\002** FREQUENCY =\002,1p,e12.5,\002 MHZ.\002,51x,\002**\002)";
//  static char fmt_23[] = "(5x,\002** PERFECT GROUND\002,65x,\002**\002)";
//  static char fmt_27[] = "(5x,\002** FINITE GROUND.  REFLECTION COEFFICIENT APPROXIMATION\002,27x,\002**\002)";
//  static char fmt_28[] = "(5x,\002** FINITE GROUND.  SOMMERFELD SOLUTION\002,44x,\002**\002)";
//  static char fmt_24[] = "(5x,\002** GROUND PARAMETERS - DIELECTRIC CONSTANT =\002,1p,e12.5,26x,\002**\002,/,5x,\002**\002,21x,\002CONDUCTIVITY =\002,e12.5,\002 MHOS/M.\002,25x,\002**\002)";
//  static char fmt_15[] = "(5x,\002** \002,19a4,\002 **\002)";
//  static char fmt_25[] = "(39x,\002NUMERICAL GREEN'S FUNCTION DATA\002,/,41x,\002COORDINATES OF SEGMENT ENDS\002,/,51x,\002(METERS)\002,/,5x,\002SEG.\002,11x,\002- - - END ONE - - -\002,26x,\002- - - END TWO - - -\002,/,6x,\002NO.\002,6x,\002X\002,14x,\002Y\002,14x,\002Z\002,14x,\002X\002,14x,\002Y\002,14x,\002Z\002)";
//  static char fmt_26[] = "(1x,i7,1p,6e15.6)";
//  
//  /* System generated locals */
//  int i__1, i__2, i__3, i__4, i__5, i__6, i__7;
//  olist o__1;
//  alist al__1;
//  
//  
//  /* Local variables */
//  static integer i__, j, k;
//  static doublereal dx, xi, yi, zi;
//#define t2x ((doublereal *)&data_1 + 10501)
//#define t2y ((doublereal *)&data_1 + 12001)
//#define t2z ((doublereal *)&data_1 + 13501)
//  static integer neq, iop, nop, nbl2, npeq, iout;
//  
//  /* Fortran I/O blocks */
//  static cilist io___902 = { 0, 0, 0, 0, 0 };
//  static cilist io___903 = { 0, 0, 0, 0, 0 };
//  static cilist io___905 = { 0, 0, 0, 0, 0 };
//  static cilist io___906 = { 0, 0, 0, 0, 0 };
//  static cilist io___907 = { 0, 0, 0, 0, 0 };
//  static cilist io___908 = { 0, 0, 0, 0, 0 };
//  static cilist io___909 = { 0, 0, 0, 0, 0 };
//  static cilist io___915 = { 0, 0, 0, 0, 0 };
//  static cilist io___916 = { 0, 0, 0, 0, 0 };
//  static cilist io___917 = { 0, 0, 0, 0, 0 };
//  static cilist io___918 = { 0, 0, 0, 0, 0 };
//  static cilist io___919 = { 0, 0, 0, 0, 0 };
//  static cilist io___920 = { 0, 0, 0, 0, 0 };
//  static cilist io___921 = { 0, 0, 0, 0, 0 };
//  static cilist io___925 = { 0, 0, 0, 0, 0 };
//  static cilist io___926 = { 0, 0, 0, 0, 0 };
//  static cilist io___928 = { 0, 0, 0, 0, 0 };
//  static cilist io___930 = { 0, 0, 0, 0, 0 };
//  static cilist io___931 = { 0, 13, 0, 0, 0 };
//  static cilist io___934 = { 0, 3, 0, fmt_16, 0 };
//  static cilist io___935 = { 0, 3, 0, fmt_14, 0 };
//  static cilist io___936 = { 0, 3, 0, fmt_14, 0 };
//  static cilist io___937 = { 0, 3, 0, fmt_17, 0 };
//  static cilist io___938 = { 0, 3, 0, fmt_18, 0 };
//  static cilist io___939 = { 0, 3, 0, fmt_19, 0 };
//  static cilist io___940 = { 0, 3, 0, fmt_20, 0 };
//  static cilist io___941 = { 0, 3, 0, fmt_21, 0 };
//  static cilist io___942 = { 0, 3, 0, fmt_22, 0 };
//  static cilist io___943 = { 0, 3, 0, fmt_23, 0 };
//  static cilist io___944 = { 0, 3, 0, fmt_27, 0 };
//  static cilist io___945 = { 0, 3, 0, fmt_28, 0 };
//  static cilist io___946 = { 0, 3, 0, fmt_24, 0 };
//  static cilist io___947 = { 0, 3, 0, fmt_17, 0 };
//  static cilist io___948 = { 0, 3, 0, fmt_15, 0 };
//  static cilist io___949 = { 0, 3, 0, fmt_17, 0 };
//  static cilist io___950 = { 0, 3, 0, fmt_14, 0 };
//  static cilist io___951 = { 0, 3, 0, fmt_14, 0 };
//  static cilist io___952 = { 0, 3, 0, fmt_16, 0 };
//  static cilist io___953 = { 0, 3, 0, fmt_25, 0 };
//  static cilist io___954 = { 0, 3, 0, fmt_26, 0 };
  
//  o__1.oerr = 0;
//  o__1.ounit = igfl;
//  o__1.ofnmlen = 9;
//  o__1.ofnm = "NGF2D.NEC";
//  o__1.orl = 0;
//  o__1.osta = "OLD";
//  o__1.oacc = 0;
//  o__1.ofm = "UNFORMATTED";
//  o__1.oblnk = 0;
//  f_open(&o__1);
//  /*<       REWIND IGFL >*/
//  al__1.aerr = 0;
//  al__1.aunit = igfl;
//  f_rew(&al__1);
//  /*<        >*/
//  io___902.ciunit = igfl;
//  s_rsue(&io___902);
//  integer c__1 = 1;
//  do_uio(&c__1, (char *)&n1, (ftnlen)sizeof(integer));
//  do_uio(&c__1, (char *)&np, (ftnlen)sizeof(integer));
//  do_uio(&c__1, (char *)&m1, (ftnlen)sizeof(integer));
//  do_uio(&c__1, (char *)&mp, (ftnlen)sizeof(integer));
//  do_uio(&c__1, (char *)&wlam, (ftnlen)sizeof(doublereal));
//  do_uio(&c__1, (char *)&fmhz, (ftnlen)sizeof(doublereal));
//  do_uio(&c__1, (char *)&ipsym, (ftnlen)sizeof(integer));
//  do_uio(&c__1, (char *)&ksymp, (ftnlen)sizeof(integer));
//  do_uio(&c__1, (char *)&iperf, (ftnlen)sizeof(integer));
//  do_uio(&c__1, (char *)&nradl, (ftnlen)sizeof(integer));
//  do_uio(&c__1, (char *)&epsr, (ftnlen)sizeof(doublereal));
//  do_uio(&c__1, (char *)&sig, (ftnlen)sizeof(doublereal));
//  do_uio(&c__1, (char *)&scrwlt, (ftnlen)sizeof(doublereal));
//  do_uio(&c__1, (char *)&scrwrt, (ftnlen)sizeof(doublereal));
//  do_uio(&c__1, (char *)&nlodf, (ftnlen)sizeof(integer));
//  do_uio(&c__1, (char *)&kcom, (ftnlen)sizeof(integer));
//  e_rsue();
//  /*<       N=N1 >*/
//  n = n1;
//  /*<       M=M1 >*/
//  m = m1;
//  /*<       N2=N1+1 >*/
//  n2 = n1 + 1;
//  /*<       M2=M1+1 >*/
//  m2 = m1 + 1;
//  /*<       IF (N1.EQ.0) GO TO 2 >*/
//  if (n1 == 0) {
//    goto L2;
//  }
  
  /*     READ SEG. DATA AND CONVERT BACK TO END COORD. IN UNITS OF METERS */

  //  /*<       READ (IGFL) (X(I),I=1,N1),(Y(I),I=1,N1),(Z(I),I=1,N1) >*/
//  io___903.ciunit = igfl;
//  s_rsue(&io___903);
//  i__1 = n1;
//  for (i__ = 1; i__ <= i__1; ++i__) {
//    do_uio(&c__1, (char *)&x[(i__2 = i__ - 1) < 1500 && 0 <= i__2 ? i__2 : s_rnge("x", i__2, "gfil_", (ftnlen)4270)], (ftnlen)sizeof(doublereal));
//  }
//  i__3 = n1;
//  for (i__ = 1; i__ <= i__3; ++i__) {
//    do_uio(&c__1, (char *)&y[(i__4 = i__ - 1) < 1500 && 0 <= i__4 ? i__4 : s_rnge("y", i__4, "gfil_", (ftnlen)4270)], (ftnlen)sizeof(doublereal));
//  }
//  i__5 = n1;
//  for (i__ = 1; i__ <= i__5; ++i__) {
//    do_uio(&c__1, (char *)&z__[(i__6 = i__ - 1) < 1500 && 0 <= i__6 ? i__6 : s_rnge("z", i__6, "gfil_", (ftnlen)4270)], (ftnlen)sizeof(doublereal));
//  }
//  e_rsue();
//  
//  /*<       READ (IGFL) (SI(I),I=1,N1),(BI(I),I=1,N1),(ALP(I),I=1,N1) >*/
//  io___905.ciunit = igfl;
//  s_rsue(&io___905);
//  i__2 = n1;
//  for (i__ = 1; i__ <= i__2; ++i__) {
//    do_uio(&c__1, (char *)&si[(i__1 = i__ - 1) < 1500 && 0 <= i__1 ? i__1 : s_rnge("si", i__1, "gfil_", (ftnlen)4271)], (ftnlen)sizeof(doublereal));
//  }
//  i__4 = n1;
//  for (i__ = 1; i__ <= i__4; ++i__) {
//    do_uio(&c__1, (char *)&bi[(i__3 = i__ - 1) < 1500 && 0 <= i__3 ? i__3 : s_rnge("bi", i__3, "gfil_", (ftnlen)4271)], (ftnlen)sizeof(doublereal));
//  }
//  i__6 = n1;
//  for (i__ = 1; i__ <= i__6; ++i__) {
//    do_uio(&c__1, (char *)&alp[(i__5 = i__ - 1) < 1500 && 0 <= i__5 ? i__5 : s_rnge("alp", i__5, "gfil_", (ftnlen)4271)], (ftnlen)sizeof(doublereal));
//  }
//  e_rsue();
//  /*<       READ (IGFL) (BET(I),I=1,N1),(SALP(I),I=1,N1) >*/
//  io___906.ciunit = igfl;
//  s_rsue(&io___906);
//  i__1 = n1;
//  for (i__ = 1; i__ <= i__1; ++i__) {
//    do_uio(&c__1, (char *)&bet[(i__2 = i__ - 1) < 1500 && 0 <= i__2 ? i__2 : s_rnge("bet", i__2, "gfil_", (ftnlen)4272)], (ftnlen)sizeof(doublereal));
//  }
//  i__3 = n1;
//  for (i__ = 1; i__ <= i__3; ++i__) {
//    do_uio(&c__1, (char *)&salp[(i__4 = i__ - 1) < 1500 && 0 <= i__4 ? i__4 : s_rnge("salp", i__4, "gfil_", (ftnlen)4272)], (ftnlen)sizeof(doublereal));
//  }
//  e_rsue();
//  /*<       READ (IGFL) (ICON1(I),I=1,N1),(ICON2(I),I=1,N1) >*/
//  io___907.ciunit = igfl;
//  s_rsue(&io___907);
//  i__2 = n1;
//  for (i__ = 1; i__ <= i__2; ++i__) {
//    do_uio(&c__1, (char *)&icon1[(i__1 = i__ - 1) < 3000 && 0 <= i__1 ? i__1 : s_rnge("icon1", i__1, "gfil_", (ftnlen)4273)], (ftnlen)sizeof(integer));
//  }
//  i__4 = n1;
//  for (i__ = 1; i__ <= i__4; ++i__) {
//    do_uio(&c__1, (char *)&icon2[(i__3 = i__ - 1) < 3000 && 0 <= i__3 ? i__3 : s_rnge("icon2", i__3, "gfil_", (ftnlen)4273)], (ftnlen)sizeof(integer));
//  }
//  e_rsue();
//  /*<       READ (IGFL) (ITAG(I),I=1,N1) >*/
//  io___908.ciunit = igfl;
//  s_rsue(&io___908);
//  i__1 = n1;
//  for (i__ = 1; i__ <= i__1; ++i__) {
//    do_uio(&c__1, (char *)&itag[(i__2 = i__ - 1) < 3000 && 0 <= i__2 ? i__2 : s_rnge("itag", i__2, "gfil_", (ftnlen)4274)], (ftnlen)sizeof(integer));
//  }
//  e_rsue();
//  /*<       IF (NLODF.NE.0) READ (IGFL) (ZARRAY(I),I=1,N1) >*/
//  if (nlodf != 0) {
//    io___909.ciunit = igfl;
//    s_rsue(&io___909);
//    i__2 = n1;
//    for (i__ = 1; i__ <= i__2; ++i__) {
//      do_uio(&c__2, (char *)&zarray[(i__1 = i__ - 1) < 1500 && 0 <= i__1 ? i__1 : s_rnge("zarray", i__1, "gfil_", (ftnlen)4275)], (ftnlen)sizeof(doublereal));
//    }
//    e_rsue();
//  }
//  /*<       DO 1 I=1,N1 >*/
//  i__1 = n1;
//  for (i__ = 1; i__ <= i__1; ++i__) {
//    /*<       XI=X(I)*WLAM >*/
//    xi = x[(i__2 = i__ - 1) < 1500 && 0 <= i__2 ? i__2 : s_rnge("x", i__2, "gfil_", (ftnlen)4277)] * wlam;
//    /*<       YI=Y(I)*WLAM >*/
//    yi = y[(i__2 = i__ - 1) < 1500 && 0 <= i__2 ? i__2 : s_rnge("y", i__2, "gfil_", (ftnlen)4278)] * wlam;
//    /*<       ZI=Z(I)*WLAM >*/
//    zi = z__[(i__2 = i__ - 1) < 1500 && 0 <= i__2 ? i__2 : s_rnge("z", i__2, "gfil_", (ftnlen)4279)] * wlam;
//    /*<       DX=SI(I)*.5*WLAM >*/
//    dx = si[(i__2 = i__ - 1) < 1500 && 0 <= i__2 ? i__2 : s_rnge("si",
//                                                                 i__2, "gfil_", (ftnlen)4280)] * .5f * wlam;
//    /*<       X(I)=XI-ALP(I)*DX >*/
//    x[(i__2 = i__ - 1) < 1500 && 0 <= i__2 ? i__2 : s_rnge("x", i__2, "gfil_", (ftnlen)4281)] = xi - alp[(i__3 = i__ - 1) < 1500 && 0 <= i__3 ? i__3 : s_rnge("alp", i__3, "gfil_", (ftnlen)4281)]
//    * dx;
//    /*<       Y(I)=YI-BET(I)*DX >*/
//    y[(i__2 = i__ - 1) < 1500 && 0 <= i__2 ? i__2 : s_rnge("y", i__2, "gfil_", (ftnlen)4282)] = yi - bet[(i__3 = i__ - 1) < 1500 && 0 <= i__3 ? i__3 : s_rnge("bet", i__3, "gfil_", (ftnlen)4282)]
//    * dx;
//    /*<       Z(I)=ZI-SALP(I)*DX >*/
//    z__[(i__2 = i__ - 1) < 1500 && 0 <= i__2 ? i__2 : s_rnge("z", i__2, "gfil_", (ftnlen)4283)] = zi - salp[(i__3 = i__ - 1) < 1500 && 0 <= i__3 ? i__3 : s_rnge("salp", i__3, "gfil_", (ftnlen)4283)] * dx;
//    /*<       SI(I)=XI+ALP(I)*DX >*/
//    si[(i__2 = i__ - 1) < 1500 && 0 <= i__2 ? i__2 : s_rnge("si", i__2, "gfil_", (ftnlen)4284)] = xi + alp[(i__3 = i__ - 1) < 1500 && 0 <= i__3 ? i__3 : s_rnge("alp", i__3, "gfil_", (ftnlen)4284)]
//    * dx;
//    /*<       ALP(I)=YI+BET(I)*DX >*/
//    alp[(i__2 = i__ - 1) < 1500 && 0 <= i__2 ? i__2 : s_rnge("alp", i__2, "gfil_", (ftnlen)4285)] = yi + bet[(i__3 = i__ - 1) < 1500 && 0 <= i__3 ? i__3 : s_rnge("bet", i__3, "gfil_", (ftnlen)4285)]
//    * dx;
//    /*<       BET(I)=ZI+SALP(I)*DX >*/
//    bet[(i__2 = i__ - 1) < 1500 && 0 <= i__2 ? i__2 : s_rnge("bet", i__2, "gfil_", (ftnlen)4286)] = zi + salp[(i__3 = i__ - 1) < 1500 && 0 <= i__3 ? i__3 : s_rnge("salp", i__3, "gfil_", (ftnlen)4286)] * dx;
//    /*<       BI(I)=BI(I)*WLAM >*/
//    bi[(i__2 = i__ - 1) < 1500 && 0 <= i__2 ? i__2 : s_rnge("bi", i__2, "gfil_", (ftnlen)4287)] = bi[(i__3 = i__ - 1) < 1500 && 0 <= i__3 ? i__3 : s_rnge("bi", i__3, "gfil_", (ftnlen)4287)] *
//    wlam;
//    /*< 1     CONTINUE >*/
//    /* L1: */
//  }
//  /*< 2     IF (M1.EQ.0) GO TO 4 >*/
//L2:
//  if (m1 == 0) {
//    goto L4;
//  }
//  /*<       J=LD-M1+1 >*/
//  j = ld - m1 + 1;
//  /*     READ PATCH DATA AND CONVERT TO METERS */
//  /*<       READ (IGFL) (X(I),I=J,LD),(Y(I),I=J,LD),(Z(I),I=J,LD) >*/
//  io___915.ciunit = igfl;
//  s_rsue(&io___915);
//  i__1 = ld;
//  for (i__ = j; i__ <= i__1; ++i__) {
//    do_uio(&c__1, (char *)&x[(i__2 = i__ - 1) < 1500 && 0 <= i__2 ? i__2 : s_rnge("x", i__2, "gfil_", (ftnlen)4292)], (ftnlen)sizeof(doublereal));
//  }
//  i__3 = ld;
//  for (i__ = j; i__ <= i__3; ++i__) {
//    do_uio(&c__1, (char *)&y[(i__4 = i__ - 1) < 1500 && 0 <= i__4 ? i__4 : s_rnge("y", i__4, "gfil_", (ftnlen)4292)], (ftnlen)sizeof(doublereal));
//  }
//  i__5 = ld;
//  for (i__ = j; i__ <= i__5; ++i__) {
//    do_uio(&c__1, (char *)&z__[(i__6 = i__ - 1) < 1500 && 0 <= i__6 ? i__6 : s_rnge("z", i__6, "gfil_", (ftnlen)4292)], (ftnlen)sizeof(doublereal));
//  }
//  e_rsue();
//  /*<       READ (IGFL) (SI(I),I=J,LD),(BI(I),I=J,LD),(ALP(I),I=J,LD) >*/
//  io___916.ciunit = igfl;
//  s_rsue(&io___916);
//  i__2 = ld;
//  for (i__ = j; i__ <= i__2; ++i__) {
//    do_uio(&c__1, (char *)&si[(i__1 = i__ - 1) < 1500 && 0 <= i__1 ? i__1 : s_rnge("si", i__1, "gfil_", (ftnlen)4293)], (ftnlen)sizeof(doublereal));
//  }
//  i__4 = ld;
//  for (i__ = j; i__ <= i__4; ++i__) {
//    do_uio(&c__1, (char *)&bi[(i__3 = i__ - 1) < 1500 && 0 <= i__3 ? i__3 : s_rnge("bi", i__3, "gfil_", (ftnlen)4293)], (ftnlen)sizeof(doublereal));
//  }
//  i__6 = ld;
//  for (i__ = j; i__ <= i__6; ++i__) {
//    do_uio(&c__1, (char *)&alp[(i__5 = i__ - 1) < 1500 && 0 <= i__5 ? i__5 : s_rnge("alp", i__5, "gfil_", (ftnlen)4293)], (ftnlen)sizeof(doublereal));
//  }
//  e_rsue();
//  /*<       READ (IGFL) (BET(I),I=J,LD),(SALP(I),I=J,LD) >*/
//  io___917.ciunit = igfl;
//  s_rsue(&io___917);
//  i__1 = ld;
//  for (i__ = j; i__ <= i__1; ++i__) {
//    do_uio(&c__1, (char *)&bet[(i__2 = i__ - 1) < 1500 && 0 <= i__2 ? i__2 : s_rnge("bet", i__2, "gfil_", (ftnlen)4294)], (ftnlen)sizeof(doublereal));
//  }
//  i__3 = ld;
//  for (i__ = j; i__ <= i__3; ++i__) {
//    do_uio(&c__1, (char *)&salp[(i__4 = i__ - 1) < 1500 && 0 <= i__4 ? i__4 : s_rnge("salp", i__4, "gfil_", (ftnlen)4294)], (ftnlen)sizeof(doublereal));
//  }
//  e_rsue();
//  /* *** ERROR CORRECTED 11/20/89 ******************************* */
//  /*<       READ (IGFL) (T2X(I),I=J,LD),(T2Y(I),I=J,LD) >*/
//  io___918.ciunit = igfl;
//  s_rsue(&io___918);
//  i__2 = ld;
//  for (i__ = j; i__ <= i__2; ++i__) {
//    do_uio(&c__1, (char *)&t2x[(i__1 = i__ - 1) < 1 && 0 <= i__1 ? i__1 : s_rnge("t2x", i__1, "gfil_", (ftnlen)4296)], (ftnlen)sizeof(doublereal));
//  }
//  i__4 = ld;
//  for (i__ = j; i__ <= i__4; ++i__) {
//    do_uio(&c__1, (char *)&t2y[(i__3 = i__ - 1) < 1 && 0 <= i__3 ? i__3 : s_rnge("t2y", i__3, "gfil_", (ftnlen)4296)], (ftnlen)sizeof(doublereal));
//  }
//  e_rsue();
//  /*<       READ (IGFL) (T2Z(I),I=J,LD) >*/
//  io___919.ciunit = igfl;
//  s_rsue(&io___919);
//  i__1 = ld;
//  for (i__ = j; i__ <= i__1; ++i__) {
//    do_uio(&c__1, (char *)&t2z[(i__2 = i__ - 1) < 1 && 0 <= i__2 ? i__2 : s_rnge("t2z", i__2, "gfil_", (ftnlen)4297)], (ftnlen)sizeof(doublereal));
//  }
//  e_rsue();
//  /*      READ (IGFL) (ICON1(I),I=J,LD),(ICON2(I),I=J,LD) */
//  /*      READ (IGFL) (ITAG(I),I=J,LD) */
//  
//  /*<       DX=WLAM*WLAM >*/
//  dx = wlam * wlam;
//  /*<       DO 3 I=J,LD >*/
//  i__2 = ld;
//  for (i__ = j; i__ <= i__2; ++i__) {
//    /*<       X(I)=X(I)*WLAM >*/
//    x[(i__1 = i__ - 1) < 1500 && 0 <= i__1 ? i__1 : s_rnge("x", i__1, "gfil_", (ftnlen)4303)] = x[(i__3 = i__ - 1) < 1500 && 0 <= i__3 ? i__3 : s_rnge("x", i__3, "gfil_", (ftnlen)4303)] * wlam;
//    /*<       Y(I)=Y(I)*WLAM >*/
//    y[(i__1 = i__ - 1) < 1500 && 0 <= i__1 ? i__1 : s_rnge("y", i__1, "gfil_", (ftnlen)4304)] = y[(i__3 = i__ - 1) < 1500 && 0 <= i__3 ? i__3 : s_rnge("y", i__3, "gfil_", (ftnlen)4304)] * wlam;
//    /*<       Z(I)=Z(I)*WLAM >*/
//    z__[(i__1 = i__ - 1) < 1500 && 0 <= i__1 ? i__1 : s_rnge("z", i__1, "gfil_", (ftnlen)4305)] = z__[(i__3 = i__ - 1) < 1500 && 0 <= i__3 ? i__3 : s_rnge("z", i__3, "gfil_", (ftnlen)4305)] * wlam;
//    /*< 3     BI(I)=BI(I)*DX >*/
//    /* L3: */
//    bi[(i__1 = i__ - 1) < 1500 && 0 <= i__1 ? i__1 : s_rnge("bi", i__1, "gfil_", (ftnlen)4306)] = bi[(i__3 = i__ - 1) < 1500 && 0 <= i__3 ? i__3 : s_rnge("bi", i__3, "gfil_", (ftnlen)4306)] * dx;
//  }
//  /*< 4     READ (IGFL) ICASE,NBLOKS,NPBLK,NLAST,NBLSYM,NPSYM,NLSYM,IMAT >*/
//L4:
//  io___920.ciunit = igfl;
//  s_rsue(&io___920);
//  do_uio(&c__1, (char *)&icase, (ftnlen)sizeof(integer));
//  do_uio(&c__1, (char *)&nbloks, (ftnlen)sizeof(integer));
//  do_uio(&c__1, (char *)&npblk, (ftnlen)sizeof(integer));
//  do_uio(&c__1, (char *)&nlast, (ftnlen)sizeof(integer));
//  do_uio(&c__1, (char *)&nblsym, (ftnlen)sizeof(integer));
//  do_uio(&c__1, (char *)&npsym, (ftnlen)sizeof(integer));
//  do_uio(&c__1, (char *)&nlsym, (ftnlen)sizeof(integer));
//  do_uio(&c__1, (char *)&imat, (ftnlen)sizeof(integer));
//  e_rsue();
//  /*<        >*/
//  if (iperf == 2) {
//    io___921.ciunit = igfl;
//    s_rsue(&io___921);
//    do_uio(&c__880, (char *)&ar1[0], (ftnlen)sizeof(doublereal));
//    do_uio(&c__680, (char *)&ar2[0], (ftnlen)sizeof(doublereal));
//    do_uio(&c__576, (char *)&ar3[0], (ftnlen)sizeof(doublereal));
//    do_uio(&c__2, (char *)&epscf, (ftnlen)sizeof(doublereal));
//    do_uio(&c__3, (char *)&dxa[0], (ftnlen)sizeof(doublereal));
//    do_uio(&c__3, (char *)&dya[0], (ftnlen)sizeof(doublereal));
//    do_uio(&c__3, (char *)&xsa[0], (ftnlen)sizeof(doublereal));
//    do_uio(&c__3, (char *)&ysa[0], (ftnlen)sizeof(doublereal));
//    do_uio(&c__3, (char *)&nxa[0], (ftnlen)sizeof(integer));
//    do_uio(&c__3, (char *)&nya[0], (ftnlen)sizeof(integer));
//    e_rsue();
//  }
//  /*<       NEQ=N1+2*M1 >*/
//  neq = n1 + (m1 << 1);
//  /*<       NPEQ=NP+2*MP >*/
//  npeq = np + (mp << 1);
//  /*<       NOP=NEQ/NPEQ >*/
//  nop = neq / npeq;
//  /*<       IF (NOP.GT.1) READ (IGFL) ((SSX(I,J),I=1,NOP),J=1,NOP) >*/
//  if (nop > 1) {
//    io___925.ciunit = igfl;
//    s_rsue(&io___925);
//    i__1 = nop;
//    for (j = 1; j <= i__1; ++j) {
//      i__3 = nop;
//      for (i__ = 1; i__ <= i__3; ++i__) {
//        do_uio(&c__2, (char *)&ssx[(i__2 = i__ + (j << 4) - 17) < 256 && 0 <= i__2 ? i__2 : s_rnge("ssx", i__2, "gfil_", (ftnlen)4313)], (ftnlen)sizeof(doublereal));
//      }
//    }
//    e_rsue();
//  }
//  /*<       READ (IGFL) (IP(I),I=1,NEQ),COM >*/
//  io___926.ciunit = igfl;
//  s_rsue(&io___926);
//  i__2 = neq;
//  for (i__ = 1; i__ <= i__2; ++i__) {
//    do_uio(&c__1, (char *)&ip[(i__3 = i__ - 1) < 3000 && 0 <= i__3 ? i__3 : s_rnge("ip", i__3, "gfil_", (ftnlen)4314)], (ftnlen)sizeof(integer));
//  }
//  do_uio(&c__95, (char *)&com[0], (ftnlen)sizeof(doublereal));
//  e_rsue();
//  /*     READ MATRIX A AND WRITE TAPE13 FOR OUT OF CORE */
//  /*<       IF (ICASE.GT.2) GO TO 5 >*/
//  if (icase > 2) {
//    goto L5;
//  }
//  /*<       IOUT=NEQ*NPEQ >*/
//  iout = neq * npeq;
//  /*<       READ (IGFL) (CM(I),I=1,IOUT) >*/
//  io___928.ciunit = igfl;
//  s_rsue(&io___928);
//  i__3 = iout;
//  for (i__ = 1; i__ <= i__3; ++i__) {
//    do_uio(&c__2, (char *)&cm[(i__2 = i__ - 1) < 2250000 && 0 <= i__2 ? i__2 : s_rnge("cm", i__2, "gfil_", (ftnlen)4318)], (ftnlen)sizeof(doublereal));
//  }
//  e_rsue();
//  /*<       GO TO 10 >*/
//  goto L10;
//  /*< 5     REWIND 13 >*/
//L5:
//  al__1.aerr = 0;
//  al__1.aunit = 13;
//  f_rew(&al__1);
//  /*<       IF (ICASE.NE.4) GO TO 7 >*/
//  if (icase != 4) {
//    goto L7;
//  }
//  /*<       IOUT=NPEQ*NPEQ >*/
//  iout = npeq * npeq;
//  /*<       DO 6 K=1,NOP >*/
//  i__2 = nop;
//  for (k = 1; k <= i__2; ++k) {
//    /*<       READ (IGFL) (CM(J),J=1,IOUT) >*/
//    io___930.ciunit = igfl;
//    s_rsue(&io___930);
//    i__3 = iout;
//    for (j = 1; j <= i__3; ++j) {
//      do_uio(&c__2, (char *)&cm[(i__1 = j - 1) < 2250000 && 0 <= i__1 ? i__1 : s_rnge("cm", i__1, "gfil_", (ftnlen)4324)], (ftnlen)sizeof(doublereal));
//    }
//    e_rsue();
//    /*< 6     WRITE (13) (CM(J),J=1,IOUT) >*/
//    /* L6: */
//    s_wsue(&io___931);
//    i__1 = iout;
//    for (j = 1; j <= i__1; ++j) {
//      do_uio(&c__2, (char *)&cm[(i__3 = j - 1) < 2250000 && 0 <= i__3 ? i__3 : s_rnge("cm", i__3, "gfil_", (ftnlen)4325)], (ftnlen)sizeof(doublereal));
//    }
//    e_wsue();
//  }
//  /*<       GO TO 9 >*/
//  goto L9;
//  /*< 7     IOUT=NPSYM*NPEQ*2 >*/
//L7:
//  iout = npsym * npeq << 1;
//  /*<       NBL2=2*NBLSYM >*/
//  nbl2 = nblsym << 1;
//  /*<       DO 8 IOP=1,NOP >*/
//  i__3 = nop;
//  for (iop = 1; iop <= i__3; ++iop) {
//    /*<       DO 8 I=1,NBL2 >*/
//    i__1 = nbl2;
//    for (i__ = 1; i__ <= i__1; ++i__) {
//      /*<       CALL BLCKIN (CM,IGFL,1,IOUT,1,206) >*/
//      blckin_(cm, &igfl, &c__1, &iout, &c__1, &c__206);
//      /*< 8     CALL BLCKOT (CM,13,1,IOUT,1,205) >*/
//      /* L8: */
//      blckot_(cm, &c__13, &c__1, &iout, &c__1, &c__205);
//    }
//  }
//  /*< 9     REWIND 13 >*/
//L9:
//  al__1.aerr = 0;
//  al__1.aunit = 13;
//  f_rew(&al__1);
//  /*< 10    REWIND IGFL >*/
//L10:
//  al__1.aerr = 0;
//  al__1.aunit = igfl;
//  f_rew(&al__1);
//  /*     WRITE(3,N) G.F. HEADING */
//  /*<       WRITE(3,16) >*/
//  s_wsfe(&io___934);
//  e_wsfe();
//  /*<       WRITE(3,14) >*/
//  s_wsfe(&io___935);
//  e_wsfe();
//  /*<       WRITE(3,14) >*/
//  s_wsfe(&io___936);
//  e_wsfe();
//  /*<       WRITE(3,17) >*/
//  s_wsfe(&io___937);
//  e_wsfe();
//  /*<       WRITE(3,18)  N1,M1 >*/
//  s_wsfe(&io___938);
//  do_fio(&c__1, (char *)&n1, (ftnlen)sizeof(integer));
//  do_fio(&c__1, (char *)&m1, (ftnlen)sizeof(integer));
//  e_wsfe();
//  /*<       IF (NOP.GT.1) WRITE(3,19)  NOP >*/
//  if (nop > 1) {
//    s_wsfe(&io___939);
//    do_fio(&c__1, (char *)&nop, (ftnlen)sizeof(integer));
//    e_wsfe();
//  }
//  /*<       WRITE(3,20)  IMAT,ICASE >*/
//  s_wsfe(&io___940);
//  do_fio(&c__1, (char *)&imat, (ftnlen)sizeof(integer));
//  do_fio(&c__1, (char *)&icase, (ftnlen)sizeof(integer));
//  e_wsfe();
//  /*<       IF (ICASE.LT.3) GO TO 11 >*/
//  if (icase < 3) {
//    goto L11;
//  }
//  /*<       NBL2=NEQ*NPEQ >*/
//  nbl2 = neq * npeq;
//  /*<       WRITE(3,21)  NBL2 >*/
//  s_wsfe(&io___941);
//  do_fio(&c__1, (char *)&nbl2, (ftnlen)sizeof(integer));
//  e_wsfe();
//  /*< 11    WRITE(3,22)  FMHZ >*/
//L11:
//  s_wsfe(&io___942);
//  do_fio(&c__1, (char *)&fmhz, (ftnlen)sizeof(doublereal));
//  e_wsfe();
//  /*<       IF (KSYMP.EQ.2.AND.IPERF.EQ.1) WRITE(3,23) >*/
//  if (ksymp == 2 && iperf == 1) {
//    s_wsfe(&io___943);
//    e_wsfe();
//  }
//  /*<       IF (KSYMP.EQ.2.AND.IPERF.EQ.0) WRITE(3,27) >*/
//  if (ksymp == 2 && iperf == 0) {
//    s_wsfe(&io___944);
//    e_wsfe();
//  }
//  /*<       IF (KSYMP.EQ.2.AND.IPERF.EQ.2) WRITE(3,28) >*/
//  if (ksymp == 2 && iperf == 2) {
//    s_wsfe(&io___945);
//    e_wsfe();
//  }
//  /*<       IF (KSYMP.EQ.2.AND.IPERF.NE.1) WRITE(3,24)  EPSR,SIG >*/
//  if (ksymp == 2 && iperf != 1) {
//    s_wsfe(&io___946);
//    do_fio(&c__1, (char *)&epsr, (ftnlen)sizeof(doublereal));
//    do_fio(&c__1, (char *)&sig, (ftnlen)sizeof(doublereal));
//    e_wsfe();
//  }
//  /*<       WRITE(3,17) >*/
//  s_wsfe(&io___947);
//  e_wsfe();
//  /*<       DO 12 J=1,KCOM >*/
//  i__1 = kcom;
//  for (j = 1; j <= i__1; ++j) {
//    /*< 12    WRITE(3,15)  (COM(I,J),I=1,19) >*/
//    /* L12: */
//    s_wsfe(&io___948);
//    for (i__ = 1; i__ <= 19; ++i__) {
//      do_fio(&c__1, (char *)&com[(i__3 = i__ + j * 19 - 20) < 95 && 0 <= i__3 ? i__3 : s_rnge("com", i__3, "gfil_", (ftnlen)4353)], (ftnlen)sizeof(doublereal));
//    }
//    e_wsfe();
//  }
//  /*<       WRITE(3,17) >*/
//  s_wsfe(&io___949);
//  e_wsfe();
//  /*<       WRITE(3,14) >*/
//  s_wsfe(&io___950);
//  e_wsfe();
//  /*<       WRITE(3,14) >*/
//  s_wsfe(&io___951);
//  e_wsfe();
//  /*<       WRITE(3,16) >*/
//  s_wsfe(&io___952);
//  e_wsfe();
//  /*<       IF (IPRT.EQ.0) RETURN >*/
//  if (*iprt == 0) {
//    return 0;
//  }
//  /*<       WRITE(3,25) >*/
//  s_wsfe(&io___953);
//  e_wsfe();
//  /*<       DO 13 I=1,N1 >*/
//  i__3 = n1;
//  for (i__ = 1; i__ <= i__3; ++i__) {
//    /*< 13    WRITE(3,26)  I,X(I),Y(I),Z(I),SI(I),ALP(I),BET(I) >*/
//    /* L13: */
//    s_wsfe(&io___954);
//    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
//    do_fio(&c__1, (char *)&x[(i__1 = i__ - 1) < 1500 && 0 <= i__1 ? i__1 : s_rnge("x", i__1, "gfil_", (ftnlen)4361)], (ftnlen)sizeof(doublereal));
//    do_fio(&c__1, (char *)&y[(i__2 = i__ - 1) < 1500 && 0 <= i__2 ? i__2 : s_rnge("y", i__2, "gfil_", (ftnlen)4361)], (ftnlen)sizeof(doublereal));
//    do_fio(&c__1, (char *)&z__[(i__4 = i__ - 1) < 1500 && 0 <= i__4 ? i__4 : s_rnge("z", i__4, "gfil_", (ftnlen)4361)], (ftnlen)sizeof(doublereal));
//    do_fio(&c__1, (char *)&si[(i__5 = i__ - 1) < 1500 && 0 <= i__5 ? i__5 : s_rnge("si", i__5, "gfil_", (ftnlen)4361)], (ftnlen)sizeof(doublereal));
//    do_fio(&c__1, (char *)&alp[(i__6 = i__ - 1) < 1500 && 0 <= i__6 ? i__6 : s_rnge("alp", i__6, "gfil_", (ftnlen)4361)], (ftnlen)sizeof(doublereal));
//    do_fio(&c__1, (char *)&bet[(i__7 = i__ - 1) < 1500 && 0 <= i__7 ? i__7 : s_rnge("bet", i__7, "gfil_", (ftnlen)4361)], (ftnlen)sizeof(doublereal));
//    e_wsfe();
//  }
//  /*<       RETURN >*/
  return 0;
  
  /*< 14     >*/
  /*< 15    FORMAT (5X,3H** ,19A4,3H **) >*/
  /*< 16    FORMAT (////) >*/
  /*< 17    FORMAT (5X,2H**,80X,2H**) >*/
  /*< 18     >*/
  /*< 19    FORMAT (5X,27H** NO. SYMMETRIC SECTIONS =,I4,51X,2H**) >*/
  /*< 20     >*/
  /*< 21     >*/
  /*< 22    FORMAT (5X,14H** FREQUENCY =,1P,E12.5,5H MHZ.,51X,2H**) >*/
  /*< 23    FORMAT (5X,17H** PERFECT GROUND,65X,2H**) >*/
  /*< 24     >*/
  /*< 25     >*/
  /*< 26    FORMAT (1X,I7,1P,6E15.6) >*/
  /*< 27     >*/
  /*< 28    FORMAT (5X,38H** FINITE GROUND.  SOMMERFELD SOLUTION,44X,2H**) >*/
  /*<       END >*/
} /* gfil_ */

//#undef x
//#undef y
//#undef z__
//#undef si
//#undef bi
//#undef alp
//#undef bet
//#undef wlam
//#undef icon1
//#undef icon2
//#undef itag
//#undef ld
//#undef n1
//#undef n2
//#undef n
//#undef np
//#undef m1
//#undef m2
//#undef m
//#undef mp
//#undef ipsym
//#undef cm
//#undef icase
//#undef nbloks
//#undef npblk
//#undef nlast
//#undef nblsym
//#undef npsym
//#undef nlsym
//#undef imat
//#undef epsr
//#undef sig
//#undef scrwlt
//#undef scrwrt
//#undef fmhz
//#undef ip
//#undef kcom
//#undef com
//#undef nradl
//#undef ksymp
//#undef iperf
//#undef zarray
//#undef nlodf
//#undef ar1
//#undef ar2
//#undef ar3
//#undef epscf
//#undef dxa
//#undef dya
//#undef xsa
//#undef ysa
//#undef nxa
//#undef nya
//#undef salp
//#undef ssx
