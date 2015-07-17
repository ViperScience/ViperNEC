//
//  NECWaveBlock.h
//  ViperNEC
//
//  Created by Dylan Crocker on 1/7/15.
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

#ifndef VIPERNEC_NECWAVEBLOCK_H
#define VIPERNEC_NECWAVEBLOCK_H

#include "types.h"

/**
 *  Original NEC documentation:
 *
 *  <ul>COMMON/GWAV/</ul> U, U2, XX1, XX2, R1, R2, ZMH, ZPH
 *
 *  <ul>Routines Using /GWAV/</ul>
 *      MAIL, GFLD, GWAVE, SFLDS
 *
 *  <ul>Symbol Definitions</ul>
 *      U = (er - j*sig(w*e0)^-1/2
 *          er = relative dielectric constant; sig = conductivity or ground
 *      U2 = U^2
 *      XX1, XX2 : defined in GFLD and SFLDS
 *      R1 = distance from current element to point at which field is evaluated
 *      R2 = distance from image of current element to point at which field is
 *           evaluated
 *      ZMH = Z - Z'
 *      ZPH = Z + Z' Where Z is the height of the field evaluation point and Z'
 *            is the height of the current element
 *
 *  @since v1.0
 */
typedef struct gwav_block {
  complex_t u, u2, xx1, xx2;
  double r1, r2, zmh, zph;
} NECWaveBlock;

#endif
