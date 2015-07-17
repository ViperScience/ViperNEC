//
//  NECAngleBlock.h
//  ViperNEC
//
//  Created by Dylan Crocker on 7/21/14.
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

#ifndef NEC_ANGLE_BLOCK_H
#define NEC_ANGLE_BLOCK_H

#include <stdlib.h>
#include "types.h"

/** NECAngleBlock
 * This structure holds angle geometry information for wires and patches. This
 * data was originally in a common block in the original FORTRAN code. F2c
 * translated this to a struct. This struct has been updated to use buffers
 * instead of fixed length arrays. The data has been separated into separate
 * buffers for the wire and patch data.
 *
 * Original NEC Documentation:
 *
 * COMMON/ANGL/ SALP (300)
 *
 * Routines using /ANGL/
 *     CADC, CMSS, CMSW, CMWS, CMWW, DATAGN, ETMNS, FFLD, GFIL, GFLD, GFOUT,
 * MOVE, NEFLD, NHFLD, PATCH, QDSRC, REFLC
 *
 * /ANGL/ Parameters for Wire Segments
 *     SALP(I) = sin(a), where a = elevation angle of segment I (see figure 11).
 *
 * /ANGL/ Parameters for Surface Patches
 *     SALP(LD - I + l) = +1 if t1 X t2 = n for patch I, or
 *                      = -1 if t1 X t2 = -n for patch I
 *
 * The second case occurs when the patch has been produced by reflection of a
 * patch originally input.
 *
 * @since v1.0
 */
typedef struct angl_block {
  double *alpha; // Alpha angle for wire segments
  double *salp;  // Surface patch direction
  size_t la; // Length of alpha buffer
  size_t ls; // Length of salp buffer
} NECAngleBlock;

/** NECAngleBlockMake
 * This function creates an NECAngleBlock struct with buffers intitialized to
 * the specified sizes.
 *
 * @param asize Initial size of the wire segment data buffer (alpha angle).
 * @param nsize Initial size of the surface patch data buffer.
 * @return Initialized NECAngleBlock struct.
 * @since v1.0
 */
NECAngleBlock *NECAngleBlockMake(size_t asize, size_t nsize);

void NECAngleBlockDelete(NECAngleBlock *block);
bool NECAngleBlockResizeBuffers(NECAngleBlock *blck, size_t wsiz, size_t psiz);
bool NECAngleBlockEnlargeWireBuffer(NECAngleBlock *blck, size_t min_size);
bool NECAngleBlockEnlargePatchBuffer(NECAngleBlock *blck, size_t min_size);

#endif
