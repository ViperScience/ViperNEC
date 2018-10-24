      SUBROUTINE PRNT (IN1,IN2,IN3,FL1,FL2,FL3,FL4,FL5,FL6,IA,ICHAR)
C                                                                       
C     PRNT SETS UP THE PRINT FORMATS FOR IMPEDANCE LOADING              
C
      DIMENSION IVAR(13), IA(1), IFORM(8), IN(3), INT(3), FL(6), FLT(6)
      INTEGER  HALL
      DATA IFORM/5H(/3X,,3HI5,,3H5X,,3HA5,,6HE13.4,,4H13X,,3H3X,,5H2A10)
     1/
C                                                                       
C     NUMBER OF CHARACTERS PER COMPUTER WORD IS NCPW                    
C                                                                        
      DATA NCPW/10/,HALL/4H ALL/
      NWORDS=(ICHAR-1)/NCPW+1
      IN(1)= IN1
      IN(2)= IN2
      IN(3)= IN3
      FL(1)= FL1
      FL(2)= FL2
      FL(3)= FL3
      FL(4)= FL4
      FL(5)= FL5
      FL(6)= FL6
C                                                                       
C     INTEGER FORMAT                                                    
C 
      NINT=0
      IVAR(1)= IFORM(1)
      K=1
      I1=1
      IF (.NOT.(IN1.EQ.0.AND.IN2.EQ.0.AND.IN3.EQ.0)) GO TO 1
      INT(1)= HALL
      NINT=1
      I1=2
      K= K+1
      IVAR(K)=IFORM(4)
    1 DO 3 I=I1,3
      K= K+1
      IF (IN(I).EQ.0) GO TO 2
      NINT=NINT+1
      INT(NINT)=IN(I)
      IVAR(K)=IFORM(2)
      GO TO 3
    2 IVAR( K)= IFORM(3)
    3 CONTINUE
      K=K+1
      IVAR(K)=IFORM(7)
C                                                                       
C     DFLOATING POINT FORMAT                                            
C                                                     
      NFLT=0
      DO 5 I=1,6
      K=K+1
      IF (ABS(FL(I)).LT.1.E-20) GO TO 4
      NFLT=NFLT+1
      FLT(NFLT)=FL(I)
      IVAR(K)=IFORM(5)
      GO TO 5
    4 IVAR(K)=IFORM(6)
    5 CONTINUE
      K=K+1
      IVAR(K)=IFORM(7)
      K=K+1
      IVAR(K)=IFORM(8)
      PRINT IVAR, (INT(I),I=1,NINT),(FLT(J),J=1,NFLT),(IA(L),L=1,NWORDS)
      RETURN
      END