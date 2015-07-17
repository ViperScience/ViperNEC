//
//  NECSourceBlock.h
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

#ifndef VIPERNEC_NECSOURCEBLOCK_H
#define VIPERNEC_NECSOURCEBLOCK_H

#include "types.h"

/** NECSourceBlock
 *
 *  Original NEC documentation:
 *
 *  <ul>COMMON/VSORC/</ul> VQD(10), VSANT(10), VQDS(10), IVQD(10), ISANT(10), 
 *      IQDS(10), NVQD, NSANT, NQDS
 *
 *  <ul>Routines Using /VSORC/</ul>
 *      MAIN, CABC, COUPLE, ETMNS, NETWK, QDSRC
 *
 *      The arrays in /VSORC/ contain the strengths and locations of voltage
 *  sources on wires. Separate arrays are used for applied-field voltage sources
 *  and current-derivative discontinuity voltage sources. The variables are
 *  defined as follows.
 *
 *      ISANT(I) = number of the segment on which the Ith applied-field source
 *                 is located
 *      IVQD(I) = IQDS(I) = number of the segment on end 1 of which the Ith
 *                current-slope discontinuity voltage source is located
 *      VQD(I) = VQDS(I) = voltage of the Ith current-slope discontinuity source
 *      VSANT(I) = voltage of tne Ith applied-field voltage source
 *      NSANT = number of applied-field voltage sources
 *      NVQD = NQDS = number of current-slope discontinuity voltage sources
 *
 *      NVQD, IVQOD, and VQD are set in MAIN from the input data. NQDS, IQDS,
 *  and VQDS are set in subroutine QDSKC. The latter were included to allow for
 *  current-slope discontinuities other than voltage sources, such as lumped
 *  loads. Loading by this means has not been implemented in NEC-2 however.
 *
 *  @since v1.0
 */
typedef struct vsorc_block {
  complex_t vqd[30], vsant[30], vqds[30];
  long ivqd[30], isant[30], iqds[30], nvqd, nsant, nqds;
} NECSourceBlock;

#endif
