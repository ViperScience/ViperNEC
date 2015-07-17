//
//  NECNetworkBlock.h
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

#ifndef VIPERNEC_NECNETWORKBLOCK_H
#define VIPERNEC_NECNETWORKBLOCK_H

#include "types.h"

/**
 *  Original NEC documentation:
 *
 *  <ul>COMMON/NETCX/</ul> ZPED, PIN, PNLS, NEQ, NPEQ, NEQ2, NONET, NTSOL, 
 *      NPRINT, MASYM, ISEG1(30), ISEG2(30), X11R(30), X11I(30), X12R(30), 
 *      X12I(30), X22R(30), X22I(30), NTYP(30)
 *
 *  <ul>Routines Using /NETCX/</ul>
 *      MAIN, NETWK
 *      Variables are defined under subroutine NETWK.
 *
 *  @since v1.0
 */
typedef struct netcx_block {
  
  /**
   *  Impedance
   */
  complex_t zped;
  
  /**
   *  Network or transmission line specification parameters (depends on ntyp).
   *  ntyp = 1
   *    x11r, x11i = real and imaginary parts of Y11
   *    x12r, x12i = real and imaginary parts of Y12 = Y21
   *    x22r, x22i = real and imaginary parts of Y22
   *  ntyp = 2 or 3
   *    x11r = characteristic impedance of the transmission line
   *    x11i = length of transmission line in meters
   *    x12r = real part of shunt admittance on end 1 of line
   *    x12i = imaginary part of shunt admittance on end 1 of line
   *    x22r = real part of shunt admittance on end 2 of line
   *    x22i = imaginary part of shunt admittance on end 2 of line
   */
  double x11r[30], x11i[30], x12r[30], x12i[30], x22r[30], x22i[30];
  
  /**
   *  Total input power from sources
   */
  double pin;
  
  /**
   *  Power lost in networks
   */
  double pnls;
  
  /**
   *  Type of Ith network (1 = sort circuit admittance parameters, 
   *  2 = strait transmission line, 3 = twisted transmission line)
   */
  long ntyp[30];
  
  /**
   *  The number of the segment to which end 1 of the Ith two-port network is
   *  connected
   */
  long iseg1[30];
  
  /**
   *  The number of the segment to which end 2 of the Ith two-port network is
   *  connected
   */
  long iseg2[30];
  
  /**
   *  The number of two=port networks for which data is given.
   */
  long nonet;
  
  /**
   *  Flag to indicate network equations do not need to be recomputed
   */
  bool ntsol;
  
  /**
   *  Flag to request matrix asymmetry calculation (if true)
   */
  bool masym;
  
  // Not explicitly defined in the netwk documentation - figure out later.
  long neq, npeq, neq2, nprint;
  
} NECNetworkBlock;

#endif
