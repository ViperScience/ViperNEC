//
//  NECDataBlock.h
//  ViperNEC
//
//  Created by Dylan Crocker on 7/15/14.
//  Copyright 2014 Viper Science
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//

#ifndef NEC_DATA_BLOCK_H
#define NEC_DATA_BLOCK_H

#include <stdlib.h>
#include <stdbool.h>

/** NECDataBlock
 * A struct containing a lot of data that was originally in a
 * common block in the original FORTRAN code. F2c translated this to a struct.
 * This struct has been updated to use buffers instead of fixed length arrays.
 * As part of this update separate buffers are defined for wire and patch data
 * instead of filling a fixed length array from both ends. New buffers include:
 * xp, yp, zp, t1x, t1y, t1z, t2x, t2y, t2z, pa. Additionally ld now referes to
 * the length of the wire buffers only while lp referes to the length of the
 * patch data buffers.
 *
 * Original NEC Documentation:
 *
 * COMMON/DATA/ LD, N1, ,N2, N, NP, M1, M2, M, MP, X(300), Y(300), Z(300),
 * SI(300), BI(300), ALP(300), BET(300), wlam(300), ICON1(300), ICON2(300),
 * ITAG(300), ICONX(300), WLAM, IPSYM
 *
 * Routines Using /DATA/
 *     MAIN, ARC, CABC, CMNGF, CMSET, CMSS, CMSW, CMWS, CMWW, CONECT, DATAGN,
 * ETMNS, FFLD, FFLDS, GFIL, GFLD, GFOUT, ISEGNO, LOAD, MOVE, NEFLD, NETWK,
 * NFPAT, NHFLD, PATCH, QDSIC, RDPAT, REFLC, SBF, TBF, TRIO, WIRE
 *
 * /DATA/ Parameters for Wire Segments
 *     The arrays in /DATA/ are used to store the parameters defining the
 * segments. Two forms of the segment parameters are used.
 * During geometry input in routines ARC, CONECT, DATAGN, MOVE, REFLEC and
 * WIRE, the coordinates of the segment ends are stored. The symbol meanings in
 * the geometry routines are:
 *
 *    X(I) = X1
 *    Y(I) = Y1
 *    Z(I) = Z1
 *    SI(I) = X2 [equivalenced to X2(I)]
 *    ALP(I) = Y2 [equivalenced to Y2(I)]
 *    BET(I) = Z2 [equivalenced to Z2(I)]
 *
 * where X1, Y1, Z1 are the coordinates of the first end of the segment, and X2,
 * Y2, Z2 are the coordinates of the second end, as illustrated in figure 11.
 * Coordiantes may have any units but must be scaled to meters before data input
 * is ended since the main program requires meters.
 *     In the main program, the segment data is converted to: the coordinates of
 * the segment center, components of the unit vector in the direction of the
 * segment, and the segment length. The symbol meanings after the geometry
 * section are:
 *
 *    X(I) = X1, see figure 11
 *    Y(I) = Y1, see figure 11
 *    Z(I) = Z1, see figure 11
 *    SI(I) = segment length
 *    ALP(I) = cos(alpha)*cos(beta) [equivalenced to CAB(I)]
 *    BET(I) = cos(alpha)*sin(beta) [equivalenced to SAB(I)]
 *
 * The z component of the unit vector in the drection of the segment,
 * sin(alpha), is stored in /ANGL/.
 *     The other symbol meanings in /DATA/ for segments are:
 *
 *     BI(I) =    radius of segment I
 *     ICON1(I) = connection number for end 1 of segment I. If k is a positive
 *                integer less then 10,000, the meaning of ICON1 is as follows.
 *
 *                ICON1(I) = 0: no connection
 *                ICON1(I) = ±k: end 1 connects to segment k. If more than
 *                           one segment connects to end 1 of segment I, then
 *                           k is the number of the next connected segment
 *                           encountered by starting at I and going through
 *                           the list of segments in cyclic order.
 *                ICON1(I) = +k: parallel reference directions with end 2 of
 *                           the other segment connecting to end 1 of segment I.
 *                ICON1(I) = -k: opposed reference directions.
 *                ICON1(I) = I: end 1 of segment I connects to a ground plane.
 *                ICON1(I) = 10,000 + k: end 1 of segment I connects to a
 *                           surface with the 4 patches around the connection
 *                           point numbered k, k + 1, k + 2 and k + 3.
 *
 *     ICON2(I) = connection number for end 2 of segment 1.
 *     ITAG(I)  = tag number of segment I. This number is assigned during
 *                structure input to permit later reference to the segment
 *                without knowing the segment index I in the data arrays.
 *     ICONX(I) = equation number for the new basis function when segment I
 *                is in a numerical Green's function file and a new segment
 *                connects to segment I modifying the old basis function.
 *
 * /DATA/ Parameters for Surface Patches
 *     Patch paramters are set in subroutine PATCH. The input paramters for a
 * patch are the coordinates of the patch center, patch area, and orientation of
 * the outward, normal unit vector, n. The parameters stored in /DATA/ are the
 * center point coordinates, area, and the components of the two surface unit
 * vectors, t1 and t2. The vector t1 is parallel to a side of the triangular,
 * rectangular, or quadrilateral patch. For a patch of arbitrary shape, it is
 * chosen by the following rules:
 *
 *     For a horizontal patch, t1 = x;
 *     For a nonhorizontal patch, t1 = (z X n)/|z X n|;
 *     t2 is then chosen as t2 = n X t1
 *
 * With J = LD + 1 - I, the parameters for patch I are stored as follows.
 *
 *     X(J), Y(J), Z(J) = x, y, and z coordinates of the patch center
 *     SI(J), ALP(J), BET(J) = x, y, z components of t1 (equivelenced to T1X,
 *                             T1Y, T1Z)
 *     ICON1(J), ICON2(J), ITAG(J) = x, y, z components of t2 (equivelenced to
 *                                   T2X, T2Y, T2Z)
 *     BI(J) = patch area
 *
 * Scalar variables in /DATA/ are:
 *
 *     IPSYM = symmetry flag. The meanings of IPSYM are:
 *         IPSYM = 0: no symmetry
 *         IPSYM > 0: plane symmetry
 *         IPSYM < 0: cylindrical symmetry
 *         IPSYM = 2: plane symmetry about Z = 0
 *         |IPSYM| > 2: structure has been rotated about x or y axis. If ground
 *                      plane is indicated by IGND != 0 in the call to
 *                      subroutine CONECT and IPSYM = 2, symmetry about a
 *                      horizontal plane is removed by multiplying NP by 2. If
 *                      |IPSYM| > 2 and IGND != 0, all symmetry is removed by
 *                      setting NP = N and IPSYM = 0 in CONECT.
 *     LD = length of arrays in /DATA/
 *     N1 = number of segments in NGF. If NGF is not used N1 = 0.
 *     N2 = N1 + 1
 *     N  = total number of wire segments
 *     NP = number of segments in a symmetric cell
 *     M1 = number of patches in NGF
 *     M2 = M1 + 1
 *     M  = total number of patches
 *     MP = number of patches in symmetric cell
 *     WLAM = wavelength in meters
 *
 * @since v1.0
 */
typedef struct data_block {
  
  // Wire data
  double *x, *y, *z;
  double *si;
  double *bi;
  double *alp;
  double *bet;
  long int *icon1;
  long int *icon2;
  long int *itag;
  long int *iconx;
  size_t ld;
  size_t n1;
  size_t n2;
  size_t n;
  size_t np;
  
  // Patch data
  double *xp, *yp, *zp;
  double *t1x, *t1y, *t1z;
  double *t2x, *t2y, *t2z;
  double *pa;
  size_t lp;
  size_t m1;
  size_t m2;
  size_t m;
  size_t mp;
  
  // Other
  double wlam;
  int ipsym;
  
} NECDataBlock;

/**
 * NECDataBlock
 * Create a new NECDataBlock struct. The structed is created on the heap 
 * (malloc) and a pointer is returned.
 *
 * @param buff_size Initial buffer size - used in the malloc call.
 * @since v1.0
 */
NECDataBlock *NECDataBlockMake(size_t wire_buff_size, size_t patch_buff_size);

/**
 * NECDataBlockDelete
 * Frees all the allocated memory and sets input pointer to NULL.
 *
 * @param data The block to be cleaned up.
 * @since v1.0
 */
void NECDataBlockDelete(NECDataBlock *data);

/**
 * Print the contents of the data block to the console output for visual
 * inspection.
 *
 * @param data The block to be printed.
 * @since v1.0
 */
void NECDataBlockPrint(NECDataBlock *data);

/** NECDataBlockResizeBuffers
 * This function attempts to reallocate the buffers in the given data block to
 * a different size. If any reallocation is unsucessful the function returns
 * false - at this point all buffers may not be the same size in memory but ld
 * will remain unchanged. All buffers still must be deallocated to
 * avoid a memory leak.
 *
 * @param data The NECDataBlock of which the buffers will be resized.
 * @param wire_buff_size The new size for the wire segment data buffers.
 * @param patch_buff_size The new size for the surface patch data buffers.
 * @return Logical true (1) if successful.
 * @since v1.0
 */
bool NECDataBlockResizeBuffers(NECDataBlock *data, size_t wire_buff_size,
                               size_t patch_buff_size);

/** NECDataBlockDoubleBuffers
 * This function uses NECDataBlockResizeBuffers to double the buffers in |data|.
 *
 * @param data The NECDataBlock of which the buffers will be resized.
 * @return True if successful.
 * @since v1.0
 */
bool NECDataBlockDoubleBuffers(NECDataBlock *data);

/** NECDataBlockDoubleWireBuffers
 * Resize only the buffers containing wire segment data. The buffer size is
 * doubled.
 *
 * @param data The NECDataBlock of which the buffers will be resized.
 * @return True if successful.
 * @since v1.0
 */
bool NECDataBlockDoubleWireBuffers(NECDataBlock *data);

/** NECDataBlockDoublePatchBuffers
 * Resize only the buffers containing surface patch data. The buffer size is 
 * doubled.
 *
 * @param data The NECDataBlock of which the buffers will be resized.
 * @return True if successful.
 * @since v1.0
 */
bool NECDataBlockDoublePatchBuffers(NECDataBlock *data);

/** NECDataBlockEnlargeBuffers
 * Resize all the buffers containing surface patch and wire segment data. The 
 * buffer size is doubled until the minimum size is surpassed.
 *
 * @param data The NECDataBlock of which the buffers will be resized.
 * @param wmin Minimum desired size of the buffers storing wire segment data.
 * @param pmin Minimum desired size of the buffers storing surface patch data.
 * @return True if successful.
 * @since v1.0
 */
bool NECDataBlockEnlargeBuffers(NECDataBlock *data, size_t wmin, size_t pmin);

/** NECDataBlockEnlargeWireBuffers
 * Resize only the buffers containing wire segment data. The buffer size is
 * doubled until the minimum size is surpassed.
 *
 * @param data The NECDataBlock of which the buffers will be resized.
 * @param min Minimum desired size of the buffers storing wire segment data.
 * @return True if successful.
 * @since v1.0
 */
bool NECDataBlockEnlargeWireBuffers(NECDataBlock *data, size_t min);

/** NECDataBlockEnlargePatchBuffers
 * Resize only the buffers containing surface patch data. The buffer size is
 * doubled until the minimum size is surpassed.
 *
 * @param data The NECDataBlock of which the buffers will be resized.
 * @param min Minimum desired size of the buffers storing surface patch data.
 * @return True if successful.
 * @since v1.0
 */
bool NECDataBlockEnlargePatchBuffers(NECDataBlock *data, size_t min);

#endif
