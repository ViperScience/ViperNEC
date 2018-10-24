      SUBROUTINE ARC (ITG,NS,RADA,ANG1,ANG2,RAD)
C
C     ARC GENERATES SEGMENT GEOMETRY DATA FOR AN ARC OF NS SEGMENTS
C
      COMMON /DATA/ LD,N1,N2,N,NP,M1,M2,M,MP,X(300),Y(300),Z(300),SI(300
     1),BI(300),ALP(300),BET(300),ICON1(300),ICON2(300),ITAG(300),ICONX(
     2300),WLAM,IPSYM
      DIMENSION X2(1), Y2(1), Z2(1)
      EQUIVALENCE (X2,SI), (Y2,ALP), (Z2,BET)
      DATA TA/.01745329252/
      IST=N+1
      N=N+NS
      NP=N
      MP=M
      IPSYM=0
      IF (NS.LT.1) RETURN
      IF (ABS(ANG2-ANG1).LT.360.00001) GO TO 1
      PRINT 3
      STOP
1     ANG=ANG1*TA
      DANG=(ANG2-ANG1)*TA/NS
      XS1=RADA*COS(ANG)
      ZS1=RADA*SIN(ANG)
      DO 2 I=IST,N
      ANG=ANG+DANG
      XS2=RADA*COS(ANG)
      ZS2=RADA*SIN(ANG)
      X(I)=XS1
      Y(I)=0.
      Z(I)=ZS1
      X2(I)=XS2
      Y2(I)=0.
      Z2(I)=ZS2
      XS1=XS2
      ZS1=ZS2
      BI(I)=RAD
2     ITAG(I)=ITG
      RETURN
C
3     FORMAT (40H ERROR -- ARC ANGLE EXCEEDS 360. DEGREES)
      END
