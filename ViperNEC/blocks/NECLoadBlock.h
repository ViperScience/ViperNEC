//
//  NECLoadBlock.h
//  ViperNEC
//
//  Created by Dylan Crocker on 1/3/15.
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

#ifndef VIPERNEC_NECLOADBLOCK_H
#define VIPERNEC_NECLOADBLOCK_H

#include "types.h"

/** NECLoadBlock
 * This structure holds the data related to load(s) on the antenna(s). The
 * impeadances of each segment (whether from a lumped element or the impedance
 * of the material) is stored in |zarray|. This data was originally in a common
 * block in the original FORTRAN code. F2c translated this to a struct. This
 * struct has been updated to use buffers instead of fixed length arrays.
 *
 * Original NEC documentation:
 *
 * COMMON/ZLOAD/ ZARRAY(300)
 *
 * Routines Using /ZLOAD/
 *     MAIN, CMNGF, CMSET, GFIL, GFOUT, LOAD, QDSRC
 *
 * ZARRAY(I) = Z_I/(delta_I/wl), where Z_I is the total impedance on segment I,
 *     delta_I is the length of segment I, and wl is the wavelengtn.
 *
 * @since v1.0
 */
typedef struct zload_block {
  complex_t *zarray;
  long nload;
  long nlodf;
} NECLoadBlock;

#endif
