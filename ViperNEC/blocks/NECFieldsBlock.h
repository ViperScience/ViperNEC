//
//  NECFieldsBlock.h
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

#ifndef VIPERNEC_NECFIELDSBLOCK_H
#define VIPERNEC_NECFIELDSBLOCK_H

#include "types.h"

/**
 *  Original NEC documentation:
 *
 *  <ul>COMMON/DATAJ/</ul> S, B, XJ, YJ, ZJ, CABJ, SABJ, SALPJ, EXK, EYK, EZK,
 *      EXS, EYS, EZS, EXC, EYC, EZC, RKH, IEXK, IND1, IND2, IPGND
 *
 *  <ul>Routines Using /DATAJ/</ul>
 *      CMNGF, CMSET, CMSS, CMSW, CMWS, CMWW, EFLD, HINTG, HSFLD, NEFLD, NHFLD,
 *  PCINT, QDSRC, SFLDS, UNERE
 *
 *      /DATAJ/ is used to pass the parameters of the source segment or patch to
 *  the routines that compute the E or H field and to return the field 
 *  components.
 *
 *  <ul>/DATAJ/ Parameters for Wire Segments</ul>
 *      S = segment length
 *      B = segment radius
 *      XJ, YJ, ZJ = coordinates of segment center
 *      CABJ, SABJ, SALPJ = x, y, and z, respectively, of the unit vector in the
 *                          direction of the segment
 *      EXK, EYK, EZK = x, y, and z component of the E or H field due to a 
 *                      constant current
 *      EXS, EYS, EZS = x, y, and z component of the E or H field due to a
 *                      sin(ks) current
 *      EXC, EYC, EZC = x, y, and z component of the E or H field due to a
 *                      cos(ks) current
 *      RKH = minimum distance for use of the Hertzian dipole approximation for
 *            computing the E field of a segment
 *      IEXX = flag to select thin wire approximation or extended thin wire
 *             approximation for E field (IEXX = 1 for extended thin wire
 *             approximation).
 *      IND1 = flag to inhibit use of the extended thin wire approximation on 
 *             end 1 of the source segment. This is used when there is a bend or
 *             change in radius at end 1. IND1 = 2 inhibit the extended thin 
 *             wire approximation.
 *      IND2 = flag to inhibit use of the extended thin wire approximation on 
 *             end 2 of the source segment
 *      IPGND = not used
 *
 *  <ul>/DATAJ/ Parameters for Surface Patches</ul>
 *      S = patch area in units of wavelength squared
 *      B = x component of t2 for the patch
 *      XJ, YJ, ZJ = x, y, and z components of the position of the patch center
 *      CABJ, SABJ, SALPJ = x, y, and z components of t1
 *      EXK, EYK, EZK = x, y, and z component of E or H due to a current with
 *                      unit magnitude in the direction t1 on the patch
 *      EXS, EYS, EZS = E or H due to a current t2 on the patch
 *      EXC, EYC, EZC = not used, may serve as intermediate variables in some
 *                      routines
 *      IND1 = y component of t2
 *      IND2 = z component of t2
 *      IPGND = flag to request calculation of the direct field or field 
 *              refected from the ground (two for ground)
 *
 *  @since v1.0
 */
typedef struct dataj_block {
  double s, b, xj, yj, zj, cabj, sabj, salpj, rkh;
  complex_t exk, eyk, ezk, exs, eys, ezs, exc, eyc, ezc;
  long ind1, indd1, ind2, indd2, iexk, ipgnd;
} NECFieldsBlock;

#endif


