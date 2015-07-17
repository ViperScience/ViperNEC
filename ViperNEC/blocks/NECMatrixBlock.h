//
//  NECMatrixBlock.h
//  ViperNEC
//
//  Created by Dylan Crocker on 1/2/15.
//  Copyright 2015 Viper Science
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

#ifndef VIPERNEC_NECMATRIXBLOCK_H
#define VIPERNEC_NECMATRIXBLOCK_H

#include "types.h"

/** NECMatrixBlock
 * This structure holds interaction matrix for the simulation. This was 
 * originally in a common block in the original FORTRAN code. F2c translated 
 * this to a struct. This struct has been updated to use buffers instead of 
 * fixed length arrays.
 * 
 * Original NEC Documentation:
 *
 * COMON/CMB/ CM(4000)
 *
 * Routines Using /CMB/
 *   MAIN, GFIL. GFOUT
 *
 * The interaction matrix is stored in array CM. If the matrix is too large to 
 * fit in CM, then pairs of blocks of the matrix are stored in CM as they are 
 * needed.
 *
 * @since v1.0
 */
typedef struct cmb_block {
  
  /**
   *  The interaction matrix is stored in array |cm|.
   */
  complex_t *cm;
  
} NECMatrixBlock;

#endif
