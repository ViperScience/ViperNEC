      SUBROUTINE HINTG (XI,YI,ZI)
C     HINTG COMPUTES THE H FIELD OF A PATCH CURRENT
      COMPLEX EXK,EYK,EZK,EXS,EYS,EZS,EXC,EYC,EZC,ZRATI,ZRATI2,GAM,F1X,F
     11Y,F1Z,F2X,F2Y,F2Z,RRV,RRH,T1,FRATI
      COMMON /DATAJ/ S,B,XJ,YJ,ZJ,CABJ,SABJ,SALPJ,EXK,EYK,EZK,EXS,EYS,E
     1ZS,EXC,EYC,EZC,RKH,IND1,INDD1,IND2,INDD2,IEXK,IPGND
      COMMON /GND/ZRATI,ZRATI2,FRATI,CL,CH,SCRWL,SCRWR,NRADL,KSYMP,IFAR,
     1IPERF,T1,T2
      EQUIVALENCE (T1XJ,CABJ), (T1YJ,SABJ), (T1ZJ,SALPJ), (T2XJ,B), (T2Y
     1J,IND1), (T2ZJ,IND2)
      DATA FPI/12.56637062/,TP/6.283185308/
      RX=XI-XJ
      RY=YI-YJ
      RFL=-1.
      EXK=(0.,0.)
      EYK=(0.,0.)
      EZK=(0.,0.)
      EXS=(0.,0.)
      EYS=(0.,0.)
      EZS=(0.,0.)
      DO 5 IP=1,KSYMP
      RFL=-RFL
      RZ=ZI-ZJ*RFL
      RSQ=RX*RX+RY*RY+RZ*RZ
      IF (RSQ.LT.1.E-20) GO TO 5
      R=SQRT(RSQ)
      RK=TP*R
      CR=COS(RK)
      SR=SIN(RK)
      GAM=-(CMPLX(CR,-SR)+RK*CMPLX(SR,CR))/(FPI*RSQ*R)*S
      EXC=GAM*RX
      EYC=GAM*RY
      EZC=GAM*RZ
      T1ZR=T1ZJ*RFL
      T2ZR=T2ZJ*RFL
      F1X=EYC*T1ZR-EZC*T1YJ
      F1Y=EZC*T1XJ-EXC*T1ZR
      F1Z=EXC*T1YJ-EYC*T1XJ
      F2X=EYC*T2ZR-EZC*T2YJ
      F2Y=EZC*T2XJ-EXC*T2ZR
      F2Z=EXC*T2YJ-EYC*T2XJ
      IF (IP.EQ.1) GO TO 4
      IF (IPERF.NE.1) GO TO 1
      F1X=-F1X
      F1Y=-F1Y
      F1Z=-F1Z
      F2X=-F2X
      F2Y=-F2Y
      F2Z=-F2Z
      GO TO 4
1     XYMAG=SQRT(RX*RX+RY*RY)
      IF (XYMAG.GT.1.E-6) GO TO 2
      PX=0.
      PY=0.
      CTH=1.
      RRV=(1.,0.)
      GO TO 3
2     PX=-RY/XYMAG
      PY=RX/XYMAG
      CTH=RZ/R
      RRV=CSQRT(1.-ZRATI*ZRATI*(1.-CTH*CTH))
3     RRH=ZRATI*CTH
      RRH=(RRH-RRV)/(RRH+RRV)
      RRV=ZRATI*RRV
      RRV=-(CTH-RRV)/(CTH+RRV)
      GAM=(F1X*PX+F1Y*PY)*(RRV-RRH)
      F1X=F1X*RRH+GAM*PX
      F1Y=F1Y*RRH+GAM*PY
      F1Z=F1Z*RRH
      GAM=(F2X*PX+F2Y*PY)*(RRV-RRH)
      F2X=F2X*RRH+GAM*PX
      F2Y=F2Y*RRH+GAM*PY
      F2Z=F2Z*RRH
4     EXK=EXK+F1X
      EYK=EYK+F1Y
      EZK=EZK+F1Z
      EXS=EXS+F2X
      EYS=EYS+F2Y
      EZS=EZS+F2Z
5     CONTINUE
      RETURN
      END