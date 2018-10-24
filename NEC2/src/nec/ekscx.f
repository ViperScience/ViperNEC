      SUBROUTINE EKSCX (BX,S,Z,RHX,XK,IJ,INX1,INX2,EZS,ERS,EZC,ERC,EZK,E
     1RK)
C     COMPUTE E FIELD OF SINE, COSINE, AND CONSTANT CURRENT FILAMENTS BY
C     EXTENDED THIN WIRE APPROXIMATION.
      COMPLEX CON,GZ1,GZ2,GZP1,GZP2,GR1,GR2,GRP1,GRP2,EZS,EZC,ERS,ERC,GR
     1K1,GRK2,EZK,ERK,GZZ1,GZZ2
      COMMON /TMI/ ZPK,RKB2,IJX
      DIMENSION CONX(2)
      EQUIVALENCE (CONX,CON)
      DATA CONX/0.,4.771341189/
      IF (RHX.LT.BX) GO TO 1
      RH=RHX
      B=BX
      IRA=0
      GO TO 2
1     RH=BX
      B=RHX
      IRA=1
2     SH=.5*S
      IJX=IJ
      ZPK=XK*Z
      RHK=XK*RH
      RKB2=RHK*RHK
      SHK=XK*SH
      SS=SIN(SHK)
      CS=COS(SHK)
      Z2=SH-Z
      Z1=-(SH+Z)
      A2=B*B
      IF (INX1.EQ.2) GO TO 3
      CALL GXX (Z1,RH,B,A2,XK,IRA,GZ1,GZP1,GR1,GRP1,GRK1,GZZ1)
      GO TO 4
3     CALL GX (Z1,RHX,XK,GZ1,GRK1)
      GZP1=GRK1*Z1
      GR1=GZ1/RHX
      GRP1=GZP1/RHX
      GRK1=GRK1*RHX
      GZZ1=(0.,0.)
4     IF (INX2.EQ.2) GO TO 5
      CALL GXX (Z2,RH,B,A2,XK,IRA,GZ2,GZP2,GR2,GRP2,GRK2,GZZ2)
      GO TO 6
5     CALL GX (Z2,RHX,XK,GZ2,GRK2)
      GZP2=GRK2*Z2
      GR2=GZ2/RHX
      GRP2=GZP2/RHX
      GRK2=GRK2*RHX
      GZZ2=(0.,0.)
6     EZS=CON*((GZ2-GZ1)*CS*XK-(GZP2+GZP1)*SS)
      EZC=-CON*((GZ2+GZ1)*SS*XK+(GZP2-GZP1)*CS)
      ERS=-CON*((Z2*GRP2+Z1*GRP1+GR2+GR1)*SS-(Z2*GR2-Z1*GR1)*CS*XK)
      ERC=-CON*((Z2*GRP2-Z1*GRP1+GR2-GR1)*CS+(Z2*GR2+Z1*GR1)*SS*XK)
      ERK=CON*(GRK2-GRK1)
      CALL INTX (-SHK,SHK,RHK,IJ,CINT,SINT)
      BK=B*XK
      BK2=BK*BK*.25
      EZK=-CON*(GZP2-GZP1+XK*XK*(1.-BK2)*CMPLX(CINT,-SINT)-BK2*(GZZ2-GZZ
     11))
      RETURN
      END