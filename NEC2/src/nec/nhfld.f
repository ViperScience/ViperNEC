      SUBROUTINE NHFLD (XOB,YOB,ZOB,HX,HY,HZ)
C
C     NHFLD COMPUTES THE NEAR FIELD AT SPECIFIED POINTS IN SPACE AFTER
C     THE STRUCTURE CURRENTS HAVE BEEN COMPUTED.
C
      COMPLEX HX,HY,HZ,CUR,ACX,BCX,CCX,EXK,EYK,EZK,EXS,EYS,EZS,EXC,EYC,E
     1ZC
      COMMON /DATA/ LD,N1,N2,N,NP,M1,M2,M,MP,X(300),Y(300),Z(300),SI(300
     1),BI(300),ALP(300),BET(300),ICON1(300),ICON2(300),ITAG(300),ICONX(
     2300),WLAM,IPSYM
      COMMON /ANGL/ SALP(300)
      COMMON /CRNT/ AIR(300),AII(300),BIR(300),BII(300),CIR(300),CII(300
     1),CUR(900)
      COMMON /DATAJ/ S,B,XJ,YJ,ZJ,CABJ,SABJ,SALPJ,EXK,EYK,EZK,EXS,EYS,EZ
     1S,EXC,EYC,EZC,RKH,IND1,INDD1,IND2,INDD2,IEXK,IPGND
      DIMENSION CAB(1), SAB(1)
      DIMENSION T1X(1), T1Y(1), T1Z(1), T2X(1), T2Y(1), T2Z(1), XS(1), Y
     1S(1), ZS(1)
      EQUIVALENCE (T1X,SI), (T1Y,ALP), (T1Z,BET), (T2X,ICON1), (T2Y,ICON
     12), (T2Z,ITAG), (XS,X), (YS,Y), (ZS,Z)
      EQUIVALENCE (T1XJ,CABJ), (T1YJ,SABJ), (T1ZJ,SALPJ), (T2XJ,B), (T2Y
     1J,IND1), (T2ZJ,IND2)
      EQUIVALENCE (CAB,ALP), (SAB,BET)
      HX=(0.,0.)
      HY=(0.,0.)
      HZ=(0.,0.)
      AX=0.
      IF (N.EQ.0) GO TO 4
      DO 1 I=1,N
      XJ=XOB-X(I)
      YJ=YOB-Y(I)
      ZJ=ZOB-Z(I)
      ZP=CAB(I)*XJ+SAB(I)*YJ+SALP(I)*ZJ
      IF (ABS(ZP).GT.0.5001*SI(I)) GO TO 1
      ZP=XJ*XJ+YJ*YJ+ZJ*ZJ-ZP*ZP
      XJ=BI(I)
      IF (ZP.GT.0.9*XJ*XJ) GO TO 1
      AX=XJ
      GO TO 2
1     CONTINUE
2     DO 3 I=1,N
      S=SI(I)
      B=BI(I)
      XJ=X(I)
      YJ=Y(I)
      ZJ=Z(I)
      CABJ=CAB(I)
      SABJ=SAB(I)
      SALPJ=SALP(I)
      CALL HSFLD (XOB,YOB,ZOB,AX)
      ACX=DCMPLX(AIR(I),AII(I))
      BCX=DCMPLX(BIR(I),BII(I))
      CCX=DCMPLX(CIR(I),CII(I))
      HX=HX+EXK*ACX+EXS*BCX+EXC*CCX
      HY=HY+EYK*ACX+EYS*BCX+EYC*CCX
3     HZ=HZ+EZK*ACX+EZS*BCX+EZC*CCX
      IF (M.EQ.0) RETURN
4     JC=N
      JL=LD+1
      DO 5 I=1,M
      JL=JL-1
      S=BI(JL)
      XJ=X(JL)
      YJ=Y(JL)
      ZJ=Z(JL)
      T1XJ=T1X(JL)
      T1YJ=T1Y(JL)
      T1ZJ=T1Z(JL)
      T2XJ=T2X(JL)
      T2YJ=T2Y(JL)
      T2ZJ=T2Z(JL)
      CALL HINTG (XOB,YOB,ZOB)
      JC=JC+3
      ACX=T1XJ*CUR(JC-2)+T1YJ*CUR(JC-1)+T1ZJ*CUR(JC)
      BCX=T2XJ*CUR(JC-2)+T2YJ*CUR(JC-1)+T2ZJ*CUR(JC)
      HX=HX+ACX*EXK+BCX*EXS
      HY=HY+ACX*EYK+BCX*EYS
5     HZ=HZ+ACX*EZK+BCX*EZS
      RETURN
      END