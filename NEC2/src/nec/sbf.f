      SUBROUTINE SBF (I,IS,AA,BB,CC)
C     COMPUTE COMPONENT OF BASIS FUNCTION I ON SEGMENT IS.
      COMMON /DATA/ LD,N1,N2,N,NP,M1,M2,M,MP,X(300),Y(300),Z(300),SI(300
     1),BI(300),ALP(300),BET(300),ICON1(300),ICON2(300),ITAG(300),ICONX(
     2300),WLAM,IPSYM
      DATA PI/3.141592654/,JMAX/30/
      AA=0.
      BB=0.
      CC=0.
      JUNE=0
      JSNO=0
      PP=0.
      JCOX=ICON1(I)
      IF (JCOX.GT.10000) JCOX=I
      JEND=-1
      IEND=-1
      SIG=-1.
      IF (JCOX) 1,11,2
1     JCOX=-JCOX
      GO TO 3
2     SIG=-SIG
      JEND=-JEND
3     JSNO=JSNO+1
      IF (JSNO.GE.JMAX) GO TO 24
      D=PI*SI(JCOX)
      SDH=SIN(D)
      CDH=COS(D)
      SD=2.*SDH*CDH
      IF (D.GT.0.015) GO TO 4
      OMC=4.*D*D
      OMC=((1.3888889E-3*OMC-4.1666666667E-2)*OMC+.5)*OMC
      GO TO 5
4     OMC=1.-CDH*CDH+SDH*SDH
5     AJ=1./(ALOG(1./(PI*BI(JCOX)))-.577215664)
      PP=PP-OMC/SD*AJ
      IF (JCOX.NE.IS) GO TO 6
      AA=AJ/SD*SIG
      BB=AJ/(2.*CDH)
      CC=-AJ/(2.*SDH)*SIG
      JUNE=IEND
6     IF (JCOX.EQ.I) GO TO 9
      IF (JEND.EQ.1) GO TO 7
      JCOX=ICON1(JCOX)
      GO TO 8
7     JCOX=ICON2(JCOX)
8     IF (IABS(JCOX).EQ.I) GO TO 10
      IF (JCOX) 1,24,2
9     IF (JCOX.EQ.IS) BB=-BB
10    IF (IEND.EQ.1) GO TO 12
11    PM=-PP
      PP=0.
      NJUN1=JSNO
      JCOX=ICON2(I)
      IF (JCOX.GT.10000) JCOX=I
      JEND=1
      IEND=1
      SIG=-1.
      IF (JCOX) 1,12,2
12    NJUN2=JSNO-NJUN1
      D=PI*SI(I)
      SDH=SIN(D)
      CDH=COS(D)
      SD=2.*SDH*CDH
      CD=CDH*CDH-SDH*SDH
      IF (D.GT.0.015) GO TO 13
      OMC=4.*D*D
      OMC=((1.3888889E-3*OMC-4.1666666667E-2)*OMC+.5)*OMC
      GO TO 14
13    OMC=1.-CD
14    AP=1./(ALOG(1./(PI*BI(I)))-.577215664)
      AJ=AP
      IF (NJUN1.EQ.0) GO TO 19
      IF (NJUN2.EQ.0) GO TO 21
      QP=SD*(PM*PP+AJ*AP)+CD*(PM*AP-PP*AJ)
      QM=(AP*OMC-PP*SD)/QP
      QP=-(AJ*OMC+PM*SD)/QP
      IF (JUNE) 15,18,16
15    AA=AA*QM
      BB=BB*QM
      CC=CC*QM
      GO TO 17
16    AA=-AA*QP
      BB=BB*QP
      CC=-CC*QP
17    IF (I.NE.IS) RETURN
18    AA=AA-1.
      BB=BB+(AJ*QM+AP*QP)*SDH/SD
      CC=CC+(AJ*QM-AP*QP)*CDH/SD
      RETURN
19    IF (NJUN2.EQ.0) GO TO 23
      QP=PI*BI(I)
      XXI=QP*QP
      XXI=QP*(1.-.5*XXI)/(1.-XXI)
      QP=-(OMC+XXI*SD)/(SD*(AP+XXI*PP)+CD*(XXI*AP-PP))
      IF (JUNE.NE.1) GO TO 20
      AA=-AA*QP
      BB=BB*QP
      CC=-CC*QP
      IF (I.NE.IS) RETURN
20    AA=AA-1.
      D=CD-XXI*SD
      BB=BB+(SDH+AP*QP*(CDH-XXI*SDH))/D
      CC=CC+(CDH+AP*QP*(SDH+XXI*CDH))/D
      RETURN
21    QM=PI*BI(I)
      XXI=QM*QM
      XXI=QM*(1.-.5*XXI)/(1.-XXI)
      QM=(OMC+XXI*SD)/(SD*(AJ-XXI*PM)+CD*(PM+XXI*AJ))
      IF (JUNE.NE.-1) GO TO 22
      AA=AA*QM
      BB=BB*QM
      CC=CC*QM
      IF (I.NE.IS) RETURN
22    AA=AA-1.
      D=CD-XXI*SD
      BB=BB+(AJ*QM*(CDH-XXI*SDH)-SDH)/D
      CC=CC+(CDH-AJ*QM*(SDH+XXI*CDH))/D
      RETURN
23    AA=-1.
      QP=PI*BI(I)
      XXI=QP*QP
      XXI=QP*(1.-.5*XXI)/(1.-XXI)
      CC=1./(CDH-XXI*SDH)
      RETURN
24    PRINT 25, I
      STOP
C
25    FORMAT (43H SBF - SEGMENT CONNECTION ERROR FOR SEGMENT,I5)
      END