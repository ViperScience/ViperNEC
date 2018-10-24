      SUBROUTINE REBLK (B,BX,NB,NBX,N2C)
C     REBLOCK ARRAY B IN N.G.F. SOLUTION FROM BLOCKS OF ROWS ON TAPE14
C     TO BLOCKS OF COLUMNS ON TAPE16
      COMPLEX B,BX
      COMMON /MATPAR/ ICASE,NBLOKS,NPBLK,NLAST,NBLSYM,NPSYM,NLSYM,IMAT,I
     1CASX,NBBX,NPBX,NLBX,NBBL,NPBL,NLBL
      DIMENSION B(NB,1), BX(NBX,1)
      REWIND 16
      NIB=0
      NPB=NPBL
      DO 3 IB=1,NBBL
      IF (IB.EQ.NBBL) NPB=NLBL
      REWIND 14
      NIX=0
      NPX=NPBX
      DO 2 IBX=1,NBBX
      IF (IBX.EQ.NBBX) NPX=NLBX
      READ (14) ((BX(I,J),I=1,NPX),J=1,N2C)
      DO 1 I=1,NPX
      IX=I+NIX
      DO 1 J=1,NPB
1     B(IX,J)=BX(I,J+NIB)
2     NIX=NIX+NPBX
      WRITE (16) ((B(I,J),I=1,NB),J=1,NPB)
3     NIB=NIB+NPBL
      REWIND 14
      REWIND 16
      RETURN
      END