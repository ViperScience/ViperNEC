//
//  const.h
//  ViperNEC
//
//  Created by Dylan Crocker on 7/16/15.
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

#ifndef VIPERNEC_CONST_H
#define VIPERNEC_CONST_H

#include <limits.h>

// This constant is used to indicate a wire end is not connected to anything.
// Implemented in: connect_2.c
#define NEC_NO_CONNECTION INT_MIN

// This constant is used to separate wire and patch connection numbers (e.g.,
// if a wire is connected to segment 1 and patch 1 they are denoted as 1 and
// NEC_PATCH_OFFSET + 1 respectively. This number must be larger than the
// maximum allowable number of segments.
// Implemented in: connect_2.c
#define NEC_PATCH_OFFSET 100000

// This constant is used to indicate a particular segment cannot be found in the
// data buffers. A segment in index must be greater than or equal to zero so any
// negative number should do.
// Implemented in: isegno_2.c
#define NEC_SEGMENT_NOT_FOUND -999

// This constant is a z-axis offset used to effectively remove patches from the
// simulation area.
// Implemented in: subph_2.c
#define NEC_OUT_OF_SOLUTION_OFFSET 1e4

// This constant is the minimum wire radius (radius must be larger than this).
// Implemented in: datagn_2.c
#define NEC_MIN_WIRE_RADIUS 0.0

// This constant is the minimum wire length (length must be larger than this).
// Implemented in: datagn_2.c
#define NEC_MIN_WIRE_LENGTH 1e-20

#endif
