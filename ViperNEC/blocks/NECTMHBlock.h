//
//  NECTMHBlock.h
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

#ifndef VIPERNEC_NECTMHBLOCK_H
#define VIPERNEC_NECTMHBLOCK_H

/** NECTMHBlock
 *
 *  Original NEC documentation:
 *
 *  <ul>COMMON/TMH/</ul> ZPK, RHKS
 *
 *  <ul>Routines Using /TMH/</ul>
 *      GH, HFK
 *
 *      /TMH/ is used to pass values from HFK to GH. The variables ZPK and RHKS
 *  are defined in the discussion of subroutine HFK.
 *
 *  @since v1.0
 */
typedef struct tmh_block {
  
  /**
   *  k*z' where k = 2*pi/wl (wavelength, wl, = 1), and  z' = z coordinate of 
   *  observation point.
   */
  double zpk;
  
  /**
   *  (k*p')^2 where k = 2*pi/wl (wavelength, wl, = 1), and  p' = rho coordinate
   *  of observation point.
   */
  double rhks;
  
} NECTMHBlock;

#endif
