      SUBROUTINE FACIO (A,NROW,NOP,IP,IU1,IU2,IU3,IU4)
C
C     FACIO CONTROLS I/O FOR OUT-OF-CORE FACTORIZATION
C
      COMPLEX A
      COMMON /MATPAR/ ICASE,NBLOKS,NPBLK,NLAST,NBLSYM,NPSYM,NLSYM,IMAT,I
     1CASX,NBBX,NPBX,NLBX,NBBL,NPBL,NLBL
      DIMENSION A(NROW,1), IP(NROW)
      IT=2*NPSYM*NROW
      NBM=NBLSYM-1
      I1=1
      I2=IT
      I3=I2+1
      I4=2*IT
      TIME=0.
      REWIND IU1
      REWIND IU2
      DO 3 KK=1,NOP
      KA=(KK-1)*NROW+1
      IFILE3=IU1
      IFILE4=IU3
      DO 2 IXBLK1=1,NBM
      REWIND IU3
      REWIND IU4
      CALL BLCKIN (A,IFILE3,I1,I2,1,17)
      IXBP=IXBLK1+1
      DO 1 IXBLK2=IXBP,NBLSYM
      CALL BLCKIN (A,IFILE3,I3,I4,1,18)
      CALL SECOND (T1)
      CALL LFACTR (A,NROW,IXBLK1,IXBLK2,IP(KA))
      CALL SECOND (T2)
      TIME=TIME+T2-T1
      IF (IXBLK2.EQ.IXBP) CALL BLCKOT (A,IU2,I1,I2,1,19)
      IF (IXBLK1.EQ.NBM.AND.IXBLK2.EQ.NBLSYM) IFILE4=IU2
      CALL BLCKOT (A,IFILE4,I3,I4,1,20)
1     CONTINUE
      IFILE3=IU3
      IFILE4=IU4
      IF ((IXBLK1/2)*2.NE.IXBLK1) GO TO 2
      IFILE3=IU4
      IFILE4=IU3
2     CONTINUE
3     CONTINUE
      REWIND IU1
      REWIND IU2
      REWIND IU3
      REWIND IU4
      PRINT 4  TIME
      RETURN
C
4     FORMAT (35H CP TIME TAKEN FOR FACTORIZATION = ,1P,E12.5)
      END