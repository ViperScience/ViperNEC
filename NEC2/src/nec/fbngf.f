      SUBROUTINE FBNGF (NEQ,NEQ2,IRESRV,IB11,IC11,ID11,IX11)
C     FBNGF SETS THE BLOCKING PARAMETERS FOR THE B, C, AND D ARRAYS FOR
C     OUT-OF-CORE STORAGE.
      COMMON /MATPAR/ ICASE,NBLOKS,NPBLK,NLAST,NBLSYM,NPSYM,NLSYM,IMAT,I
     1CASX,NBBX,NPBX,NLBX,NBBL,NPBL,NLBL
      IRESX=IRESRV-IMAT
      NBLN=NEQ*NEQ2
      NDLN=NEQ2*NEQ2
      NBCD=2*NBLN+NDLN
      IF (NBCD.GT.IRESX) GO TO 1
      ICASX=1
      IB11=IMAT+1
      GO TO 2
1     IF (ICASE.LT.3) GO TO 3
      IF (NBCD.GT.IRESRV.OR.NBLN.GT.IRESX) GO TO 3
      ICASX=2
      IB11=1
2     NBBX=1
      NPBX=NEQ
      NLBX=NEQ
      NBBL=1
      NPBL=NEQ2
      NLBL=NEQ2
      GO TO 5
3     IR=IRESRV
      IF (ICASE.LT.3) IR=IRESX
      ICASX=3
      IF (NDLN.GT.IR) ICASX=4
      NBCD=2*NEQ+NEQ2
      NPBL=IR/NBCD
      NLBL=IR/(2*NEQ2)
      IF (NLBL.LT.NPBL) NPBL=NLBL
      IF (ICASE.LT.3) GO TO 4
      NLBL=IRESX/NEQ
      IF (NLBL.LT.NPBL) NPBL=NLBL
4     IF (NPBL.LT.1) GO TO 6
      NBBL=(NEQ2-1)/NPBL
      NLBL=NEQ2-NBBL*NPBL
      NBBL=NBBL+1
      NBLN=NEQ*NPBL
      IR=IR-NBLN
      NPBX=IR/NEQ2
      IF (NPBX.GT.NEQ) NPBX=NEQ
      NBBX=(NEQ-1)/NPBX
      NLBX=NEQ-NBBX*NPBX
      NBBX=NBBX+1
      IB11=1
      IF (ICASE.LT.3) IB11=IMAT+1
5     IC11=IB11+NBLN
      ID11=IC11+NBLN
      IX11=IMAT+1
      PRINT 11, NEQ2
      IF (ICASX.EQ.1) RETURN
      PRINT 8, ICASX
      PRINT 9, NBBX,NPBX,NLBX
      PRINT 10, NBBL,NPBL,NLBL
      RETURN
6     PRINT 7, IRESRV,IMAT,NEQ,NEQ2
      STOP
C
7     FORMAT (55H ERROR - INSUFFICIENT STORAGE FOR INTERACTION MATRICIES
     1,24H  IRESRV,IMAT,NEQ,NEQ2 =,4I5)
8     FORMAT (48H FILE STORAGE FOR NEW MATRIX SECTIONS -  ICASX =,I2)
9     FORMAT (19H B FILLED BY ROWS -,15X,12HNO. BLOCKS =,I3,3X,16HROWS P
     1ER BLOCK =,I3,3X,20HROWS IN LAST BLOCK =,I3)
10    FORMAT (32H B BY COLUMNS, C AND D BY ROWS -,2X,12HNO. BLOCKS =,I3,
     14X,15HR/C PER BLOCK =,I3,4X,19HR/C IN LAST BLOCK =,I3)
11    FORMAT (//,35H N.G.F. - NUMBER OF NEW UNKNOWNS IS,I4)
      END