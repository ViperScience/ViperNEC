      SUBROUTINE RDPAT
C     COMPUTE RADIATION PATTERN, GAIN, NORMALIZED GAIN
      INTEGER HPOL,HBLK,HCIR,HCLIF
      COMPLEX ETH,EPH,ERD,ZRATI,ZRATI2,T1,FRATI
      COMMON /DATA/ LD,N1,N2,N,NP,M1,M2,M,MP,X(300),Y(300),Z(300),SI(300
     1),BI(300),ALP(300),BET(300),ICON1(300),ICON2(300),ITAG(300),ICONX(
     2300),WLAM,IPSYM
      COMMON/SAVE/ IP(600),KCOM,COM(19,5),EPSR,SIG,SCRWLT,SCRWRT,FMHZ
      COMMON /GND/ZRATI,ZRATI2,FRATI,CL,CH,SCRWL,SCRWR,NRADL,KSYMP,IFAR,
     1IPERF,T1,T2
      COMMON /FPAT/ NTH,NPH,IPD,IAVP,INOR,IAX,THETS,PHIS,DTH,DPH,RFLD,GN
     1OR,CLT,CHT,EPSR2,SIG2,IXTYP,XPR6,PINR,PNLR,PLOSS,NEAR,NFEH,NRX,NRY
     2,NRZ,XNR,YNR,ZNR,DXNR,DYNR,DZNR
      COMMON /SCRATM/ GAIN(1200)
      DIMENSION IGTP(4), IGAX(4), IGNTP(10), HPOL(3)
      DATA HPOL/6HLINEAR,5HRIGHT,4HLEFT/,HBLK,HCIR/1H ,6HCIRCLE/
      DATA IGTP/6H    - ,6HPOWER ,6H- DIRE,6HCTIVE /
      DATA IGAX/6H MAJOR,6H MINOR,6H VERT.,6H HOR. /
      DATA IGNTP/6H MAJOR,6H AXIS ,6H MINOR,6H AXIS ,6H   VER,6HTICAL ,6
     1H HORIZ,6HONTAL ,6H      ,6HTOTAL /
      DATA PI,TA,TD/3.141592654,1.745329252E-02,57.29577951/
      DATA NORMAX/1200/
      IF (IFAR.LT.2) GO TO 2
      PRINT 35
      IF (IFAR.LE.3) GO TO 1
      PRINT 36, NRADL,SCRWLT,SCRWRT
      IF (IFAR.EQ.4) GO TO 2
1     IF (IFAR.EQ.2.OR.IFAR.EQ.5) HCLIF=HPOL(1)
      IF (IFAR.EQ.3.OR.IFAR.EQ.6) HCLIF=HCIR
      CL=CLT/WLAM
      CH=CHT/WLAM
      ZRATI2=CSQRT(1./CMPLX(EPSR2,-SIG2*WLAM*59.96))
      PRINT 37, HCLIF,CLT,CHT,EPSR2,SIG2
2     IF (IFAR.NE.1) GO TO 3
      PRINT 41
      GO TO 5
3     I=2*IPD+1
      J=I+1
      ITMP1=2*IAX+1
      ITMP2=ITMP1+1
      PRINT 38
      IF (RFLD.LT.1.E-20) GO TO 4
      EXRM=1./RFLD
      EXRA=RFLD/WLAM
      EXRA=-360.*(EXRA-AINT(EXRA))
      PRINT 39, RFLD,EXRM,EXRA
4     PRINT 40, IGTP(I),IGTP(J),IGAX(ITMP1),IGAX(ITMP2)
5     IF (IXTYP.EQ.0.OR.IXTYP.EQ.5) GO TO 7
      IF (IXTYP.EQ.4) GO TO 6
      PRAD=0.
      GCON=4.*PI/(1.+XPR6*XPR6)
      GCOP=GCON
      GO TO 8
6     PINR=394.51*XPR6*XPR6*WLAM*WLAM
7     GCOP=WLAM*WLAM*2.*PI/(376.73*PINR)
      PRAD=PINR-PLOSS-PNLR
      GCON=GCOP
      IF (IPD.NE.0) GCON=GCON*PINR/PRAD
8     I=0
      GMAX=-1.E10
      PINT=0.
      TMP1=DPH*TA
      TMP2=.5*DTH*TA
      PHI=PHIS-DPH
      DO 29 KPH=1,NPH
      PHI=PHI+DPH
      PHA=PHI*TA
      THET=THETS-DTH
      DO 29 KTH=1,NTH
      THET=THET+DTH
      IF (KSYMP.EQ.2.AND.THET.GT.90.01.AND.IFAR.NE.1) GO TO 29
      THA=THET*TA
      IF (IFAR.EQ.1) GO TO 9
      CALL FFLD (THA,PHA,ETH,EPH)
      GO TO 10
9     CALL GFLD (RFLD/WLAM,PHA,THET/WLAM,ETH,EPH,ERD,ZRATI,KSYMP)
      ERDM=CABS(ERD)
      ERDA=CANG(ERD)
10    ETHM2=REAL(ETH*CONJG(ETH))
      ETHM=SQRT(ETHM2)
      ETHA=CANG(ETH)
      EPHM2=REAL(EPH*CONJG(EPH))
      EPHM=SQRT(EPHM2)
      EPHA=CANG(EPH)
      IF (IFAR.EQ.1) GO TO 28
C     ELLIPTICAL POLARIZATION CALC.
      IF (ETHM2.GT.1.E-20.OR.EPHM2.GT.1.E-20) GO TO 11
      TILTA=0.
      EMAJR2=0.
      EMINR2=0.
      AXRAT=0.
      ISENS=HBLK
      GO TO 16
11    DFAZ=EPHA-ETHA
      IF (EPHA.LT.0.) GO TO 12
      DFAZ2=DFAZ-360.
      GO TO 13
12    DFAZ2=DFAZ+360.
13    IF (ABS(DFAZ).GT.ABS(DFAZ2)) DFAZ=DFAZ2
      CDFAZ=COS(DFAZ*TA)
      TSTOR1=ETHM2-EPHM2
      TSTOR2=2.*EPHM*ETHM*CDFAZ
      TILTA=.5*ATGN2(TSTOR2,TSTOR1)
      STILTA=SIN(TILTA)
      TSTOR1=TSTOR1*STILTA*STILTA
      TSTOR2=TSTOR2*STILTA*COS(TILTA)
      EMAJR2=-TSTOR1+TSTOR2+ETHM2
      EMINR2=TSTOR1-TSTOR2+EPHM2
      IF (EMINR2.LT.0.) EMINR2=0.
      AXRAT=SQRT(EMINR2/EMAJR2)
      TILTA=TILTA*TD
      IF (AXRAT.GT.1.E-5) GO TO 14
      ISENS=HPOL(1)
      GO TO 16
14    IF (DFAZ.GT.0.) GO TO 15
      ISENS=HPOL(2)
      GO TO 16
15    ISENS=HPOL(3)
16    GNMJ=DB10(GCON*EMAJR2)
      GNMN=DB10(GCON*EMINR2)
      GNV=DB10(GCON*ETHM2)
      GNH=DB10(GCON*EPHM2)
      GTOT=DB10(GCON*(ETHM2+EPHM2))
      IF (INOR.LT.1) GO TO 23
      I=I+1
      IF (I.GT.NORMAX) GO TO 23
      GO TO (17,18,19,20,21), INOR
17    TSTOR1=GNMJ
      GO TO 22
18    TSTOR1=GNMN
      GO TO 22
19    TSTOR1=GNV
      GO TO 22
20    TSTOR1=GNH
      GO TO 22
21    TSTOR1=GTOT
22    GAIN(I)=TSTOR1
      IF (TSTOR1.GT.GMAX) GMAX=TSTOR1
23    IF (IAVP.EQ.0) GO TO 24
      TSTOR1=GCOP*(ETHM2+EPHM2)
      TMP3=THA-TMP2
      TMP4=THA+TMP2
      IF (KTH.EQ.1) TMP3=THA
      IF (KTH.EQ.NTH) TMP4=THA
      DA=ABS(TMP1*(COS(TMP3)-COS(TMP4)))
      IF (KPH.EQ.1.OR.KPH.EQ.NPH) DA=.5*DA
      PINT=PINT+TSTOR1*DA
      IF (IAVP.EQ.2) GO TO 29
24    IF (IAX.EQ.1) GO TO 25
      TMP5=GNMJ
      TMP6=GNMN
      GO TO 26
25    TMP5=GNV
      TMP6=GNH
26    ETHM=ETHM*WLAM
      EPHM=EPHM*WLAM
      IF (RFLD.LT.1.E-20) GO TO 27
      ETHM=ETHM*EXRM
      ETHA=ETHA+EXRA
      EPHM=EPHM*EXRM
      EPHA=EPHA+EXRA
27    PRINT 42, THET,PHI,TMP5,TMP6,GTOT,AXRAT,TILTA,ISENS,ETHM,ETHA,EPHM
     1,EPHA
      GO TO 29
28    PRINT 43, RFLD,PHI,THET,ETHM,ETHA,EPHM,EPHA,ERDM,ERDA
29    CONTINUE
      IF (IAVP.EQ.0) GO TO 30
      TMP3=THETS*TA
      TMP4=TMP3+DTH*TA*FLOAT(NTH-1)
      TMP3=ABS(DPH*TA*FLOAT(NPH-1)*(COS(TMP3)-COS(TMP4)))
      PINT=PINT/TMP3
      TMP3=TMP3/PI
      PRINT 44, PINT,TMP3
30    IF (INOR.EQ.0) GO TO 34
      IF (ABS(GNOR).GT.1.E-20) GMAX=GNOR
      ITMP1=(INOR-1)*2+1
      ITMP2=ITMP1+1
      PRINT 45, IGNTP(ITMP1),IGNTP(ITMP2),GMAX
      ITMP2=NPH*NTH
      IF (ITMP2.GT.NORMAX) ITMP2=NORMAX
      ITMP1=(ITMP2+2)/3
      ITMP2=ITMP1*3-ITMP2
      ITMP3=ITMP1
      ITMP4=2*ITMP1
      IF (ITMP2.EQ.2) ITMP4=ITMP4-1
      DO 31 I=1,ITMP1
      ITMP3=ITMP3+1
      ITMP4=ITMP4+1
      J=(I-1)/NTH
      TMP1=THETS+FLOAT(I-J*NTH-1)*DTH
      TMP2=PHIS+FLOAT(J)*DPH
      J=(ITMP3-1)/NTH
      TMP3=THETS+FLOAT(ITMP3-J*NTH-1)*DTH
      TMP4=PHIS+FLOAT(J)*DPH
      J=(ITMP4-1)/NTH
      TMP5=THETS+FLOAT(ITMP4-J*NTH-1)*DTH
      TMP6=PHIS+FLOAT(J)*DPH
      TSTOR1=GAIN(I)-GMAX
      IF (I.EQ.ITMP1.AND.ITMP2.NE.0) GO TO 32
      TSTOR2=GAIN(ITMP3)-GMAX
      PINT=GAIN(ITMP4)-GMAX
31    PRINT 46, TMP1,TMP2,TSTOR1,TMP3,TMP4,TSTOR2,TMP5,TMP6,PINT
      GO TO 34
32    IF (ITMP2.EQ.2) GO TO 33
      TSTOR2=GAIN(ITMP3)-GMAX
      WRITE(3,46)  TMP1,TMP2,TSTOR1,TMP3,TMP4,TSTOR2
      GO TO 34
33    WRITE(3,46)  TMP1,TMP2,TSTOR1
34    RETURN
C
35    FORMAT (///,31X,39H- - - FAR FIELD GROUND PARAMETERS - - -,//)
36    FORMAT (40X,25HRADIAL WIRE GROUND SCREEN,/,40X,I5,6H WIRES,/,40X,1
     12HWIRE LENGTH=,F8.2,7H METERS,/,40X,12HWIRE RADIUS=,E10.3,7H METER
     2S)
37    FORMAT (40X,A6,6H CLIFF,/,40X,14HEDGE DISTANCE=,F9.2,7H METERS,/,4
     10X,7HHEIGHT=,F8.2,7H METERS,/,40X,15HSECOND MEDIUM -,/,40X,27HRELA
     2TIVE DIELECTRIC CONST.=,F7.3,/,40X,13HCONDUCTIVITY=,E10.3,5H MHOS)
38    FORMAT (///,48X,30H- - - RADIATION PATTERNS - - -)
39    FORMAT (54X,6HRANGE=,E13.6,7H METERS,/,54X,12HEXP(-JKR)/R=,E12.5,9
     1H AT PHASE,0P,F7.2,8H DEGREES,/)
40    FORMAT (/,2X,14H- - ANGLES - -,7X,2A6,7HGAINS -,7X,24H- - - POLARI
     1ZATION - - -,4X,20H- - - E(THETA) - - -,4X,16H- - - E(PHI) - -,2H
     2-,/,2X,5HTHETA,5X,3HPHI,7X,A6,2X,A6,3X,5HTOTAL,6X,5HAXIAL,5X,4HTIL
     3T,3X,5HSENSE,2(5X,9HMAGNITUDE,4X,6HPHASE ),/,2(1X,7HDEGREES,1X),3(
     46X,2HDB),8X,5HRATIO,5X,4HDEG.,8X,2(6X,7HVOLTS/M,4X,7HDEGREES))
41    FORMAT (///,28X,40H - - - RADIATED FIELDS NEAR GROUND - - -,//,8X,
     120H- - - LOCATION - - -,10X,16H- - E(THETA) - -,8X,14H- - E(PHI) -
     2 -,8X,17H- - E(RADIAL) - -,/,7X,3HRHO,6X,3HPHI,9X,1HZ,12X,3HMAG,6X
     3,5HPHASE,9X,3HMAG,6X,5HPHASE,9X,3HMAG,6X,5HPHASE,/,5X,6HMETERS,3X,
     47HDEGREES,4X,6HMETERS,8X,7HVOLTS/M,3X,7HDEGREES,6X,7HVOLTS/M,3X,7H
     5DEGREES,6X,7HVOLTS/M,3X,7HDEGREES,/)
42    FORMAT(1X,F7.2,F9.2,3X,3F8.2,F11.5,F9.2,2X,A6,2(1P,E15.5,0P,F9.2))
43    FORMAT (3X,F9.2,2X,F7.2,2X,F9.2,1X,3(3X,1P,E11.4,2X,0P,F7.2))
44    FORMAT (//,3X,19HAVERAGE POWER GAIN=,1P,E12.5,7X, 31HSOLID ANGLE U
     1SED IN AVERAGING=(,0P,F7.4,16H)*PI STERADIANS.,//)
45    FORMAT (//,37X,31H- - - - NORMALIZED GAIN - - - -,//,37X,2A6,4HGAI
     1N,/,38X,22HNORMALIZATION FACTOR =,F9.2,3H DB,//,3(4X,14H- - ANGLES
     2 - -,6X,4HGAIN,7X),/,3(4X,5HTHETA,5X,3HPHI,8X,2HDB,8X),/,3(3X,7HDE
     3GREES,2X,7HDEGREES,16X))
46    FORMAT (3(1X,2F9.2,1X,F9.2,6X))
      END