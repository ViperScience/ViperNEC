      SUBROUTINE HSFLX (S,RH,ZPX,HPK,HPS,HPC)
C     CALCULATES H FIELD OF SINE COSINE, AND CONSTANT CURRENT OF SEGMENT
      COMPLEX FJ,FJK,EKR1,EKR2,T1,T2,CONS,HPS,HPC,HPK
      DIMENSION FJX(2), FJKX(2)
      EQUIVALENCE (FJ,FJX), (FJK,FJKX)
      DATA TP/6.283185308/,FJX/0.,1./,FJKX/0.,-6.283185308/
      DATA PI8/25.13274123/
      IF (RH.LT.1.E-10) GO TO 6
      IF (ZPX.LT.0.) GO TO 1
      ZP=ZPX
      HSS=1.
      GO TO 2
1     ZP=-ZPX
      HSS=-1.
2     DH=.5*S
      Z1=ZP+DH
      Z2=ZP-DH
      IF (Z2.LT.1.E-7) GO TO 3
      RHZ=RH/Z2
      GO TO 4
3     RHZ=1.
4     DK=TP*DH
      CDK=COS(DK)
      SDK=SIN(DK)
      CALL HFK (-DK,DK,RH*TP,ZP*TP,HKR,HKI)
      HPK=CMPLX(HKR,HKI)
      IF (RHZ.LT.1.E-3) GO TO 5
      RH2=RH*RH
      R1=SQRT(RH2+Z1*Z1)
      R2=SQRT(RH2+Z2*Z2)
      EKR1=CEXP(FJK*R1)
      EKR2=CEXP(FJK*R2)
      T1=Z1*EKR1/R1
      T2=Z2*EKR2/R2
      HPS=(CDK*(EKR2-EKR1)-FJ*SDK*(T2+T1))*HSS
      HPC=-SDK*(EKR2+EKR1)-FJ*CDK*(T2-T1)
      CONS=-FJ/(2.*TP*RH)
      HPS=CONS*HPS
      HPC=CONS*HPC
      RETURN
5     EKR1=CMPLX(CDK,SDK)/(Z2*Z2)
      EKR2=CMPLX(CDK,-SDK)/(Z1*Z1)
      T1=TP*(1./Z1-1./Z2)
      T2=CEXP(FJK*ZP)*RH/PI8
      HPS=T2*(T1+(EKR1+EKR2)*SDK)*HSS
      HPC=T2*(-FJ*T1+(EKR1-EKR2)*CDK)
      RETURN
6     HPS=(0.,0.)
      HPC=(0.,0.)
      HPK=(0.,0.)
      RETURN
      END