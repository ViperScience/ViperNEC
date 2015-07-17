//
//  NECSaveBlock.h
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

#ifndef VIPERNEC_NECSAVEBLOCK_H
#define VIPERNEC_NECSAVEBLOCK_H

/** NECSaveBlock
 *
 *  Original NEC documentation:
 *
 *  <ul>COMMON/SAVE/</ul> IP(6OO), KCOM, COM(13,5), EPSR, SIG, SCRWLT, SCRWRT, FMHZ
 *
 *  <ul>Routines Using / SAVE/</ul>
 *      MAIN, GFIL, GFOUT, RDPAT
 *
 *  <ul>Symbol Definitions:</ul>
 *      IP = vector of indices of pivot elements used in factoring the matrix
 *      KCOM = number of CM or CE data cards (maximum 5)
 *      COM = array storing the contents of CH or CE cards
 *      EPSR = relative dielectric constant of the ground
 *      SIG = conductivity of the ground
 *      SCRWLT = length of radials in radial wire ground screen approximation
 *               (meters)
 *      SCRWRT = radius of wires in radial wire ground screen approximation
 *               (meters)
 *      FMHZ = frequency in MHz
 *
 *  @since v1.0
 */
typedef struct save_block {
  
  /**
   *  Vector of indices of pivot elements used in factoring the matrix
   */
  long *ip;
  
  /**
   *  The number of comment cards read
   */
  long kcom;
  
  /**
   *  Array storing the contents of CH or CE cards (text)
   */
  char **com;
  
  /**
   *  Relative permittivity (er)
   */
  double epsr;
  
  /**
   *  Conductivity of ground (sigma in mhos/meter on GN card)
   */
  double sig;
  
  /**
   *  Length of radials in radial wire screen (GN card) in meters
   */
  double scrwlt;
  
  /**
   *  Radius of wires in radial wire ground screen in meters
   */
  double scrwrt;
  
  /**
   *  Frequency in MHz
   */
  double fmhz;
  
} NECSaveBlock;

#endif
