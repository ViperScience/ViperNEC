      SUBROUTINE GXX (ZZ,RH,A,A2,XK,IRA,G1,G1P,G2,G2P,G3,GZP)
C     SEGMENT END CONTRIBUTIONS FOR EXT. THIN WIRE APPROX.
      COMPLEX GZ,C1,C2,C3,G1,G1P,G2,G2P,G3,GZP
      R2=ZZ*ZZ+RH*RH
      R=SQRT(R2)
      R4=R2*R2
      RK=XK*R
      RK2=RK*RK
      RH2=RH*RH
      T1=.25*A2*RH2/R4
      T2=.5*A2/R2
      C1=CMPLX(1.,RK)
      C2=3.*C1-RK2
      C3=CMPLX(6.,RK)*RK2-15.*C1
      GZ=CMPLX(COS(RK),-SIN(RK))/R
      G2=GZ*(1.+T1*C2)
      G1=G2-T2*C1*GZ
      GZ=GZ/R2
      G2P=GZ*(T1*C3-C1)
      GZP=T2*C2*GZ
      G3=G2P+GZP
      G1P=G3*ZZ
      IF (IRA.EQ.1) GO TO 2
      G3=(G3+GZP)*RH
      GZP=-ZZ*C1*GZ
      IF (RH.GT.1.E-10) GO TO 1
      G2=0.
      G2P=0.
      RETURN
1     G2=G2/RH
      G2P=G2P*ZZ/RH
      RETURN
2     T2=.5*A
      G2=-T2*C1*GZ
      G2P=T2*GZ*C2/R2
      G3=RH2*G2P-A*GZ*C1
      G2P=G2P*ZZ
      GZP=-ZZ*C1*GZ
      RETURN
      END