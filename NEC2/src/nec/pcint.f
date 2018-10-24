      SUBROUTINE PCINT (XI,YI,ZI,CABI,SABI,SALPI,E)
C     INTEGRATE OVER PATCHES AT WIRE CONNECTION POINT
      COMPLEX EXK,EYK,EZK,EXS,EYS,EZS,EXC,EYC,EZC,E,E1,E2,E3,E4,E5,E6,E7
     1,E8,E9
      COMMON /DATAJ/ S,B,XJ,YJ,ZJ,CABJ,SABJ,SALPJ,EXK,EYK,EZK,EXS,EYS,EZ
     1S,EXC,EYC,EZC,RKH,IND1,INDD1,IND2,INDD2,IEXK,IPGND
      DIMENSION E(9)
      EQUIVALENCE (T1XJ,CABJ), (T1YJ,SABJ), (T1ZJ,SALPJ), (T2XJ,B), (T2Y
     1J,IND1), (T2ZJ,IND2)
      DATA TPI/6.283185308/,NINT/10/
      D=SQRT(S)*.5
      DS=4.*D/FLOAT(NINT)
      DA=DS*DS
      GCON=1./S
      FCON=1./(2.*TPI*D)
      XXJ=XJ
      XYJ=YJ
      XZJ=ZJ
      XS=S
      S=DA
      S1=D+DS*.5
      XSS=XJ+S1*(T1XJ+T2XJ)
      YSS=YJ+S1*(T1YJ+T2YJ)
      ZSS=ZJ+S1*(T1ZJ+T2ZJ)
      S1=S1+D
      S2X=S1
      E1=(0.,0.)
      E2=(0.,0.)
      E3=(0.,0.)
      E4=(0.,0.)
      E5=(0.,0.)
      E6=(0.,0.)
      E7=(0.,0.)
      E8=(0.,0.)
      E9=(0.,0.)
      DO 1 I1=1,NINT
      S1=S1-DS
      S2=S2X
      XSS=XSS-DS*T1XJ
      YSS=YSS-DS*T1YJ
      ZSS=ZSS-DS*T1ZJ
      XJ=XSS
      YJ=YSS
      ZJ=ZSS
      DO 1 I2=1,NINT
      S2=S2-DS
      XJ=XJ-DS*T2XJ
      YJ=YJ-DS*T2YJ
      ZJ=ZJ-DS*T2ZJ
      CALL UNERE (XI,YI,ZI)
      EXK=EXK*CABI+EYK*SABI+EZK*SALPI
      EXS=EXS*CABI+EYS*SABI+EZS*SALPI
      G1=(D+S1)*(D+S2)*GCON
      G2=(D-S1)*(D+S2)*GCON
      G3=(D-S1)*(D-S2)*GCON
      G4=(D+S1)*(D-S2)*GCON
      F2=(S1*S1+S2*S2)*TPI
      F1=S1/F2-(G1-G2-G3+G4)*FCON
      F2=S2/F2-(G1+G2-G3-G4)*FCON
      E1=E1+EXK*G1
      E2=E2+EXK*G2
      E3=E3+EXK*G3
      E4=E4+EXK*G4
      E5=E5+EXS*G1
      E6=E6+EXS*G2
      E7=E7+EXS*G3
      E8=E8+EXS*G4
1     E9=E9+EXK*F1+EXS*F2
      E(1)=E1
      E(2)=E2
      E(3)=E3
      E(4)=E4
      E(5)=E5
      E(6)=E6
      E(7)=E7
      E(8)=E8
      E(9)=E9
      XJ=XXJ
      YJ=XYJ
      ZJ=XZJ
      S=XS
      RETURN
      END