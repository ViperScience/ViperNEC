//
//  NECTMIBlock.h
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

#ifndef VIPERNEC_NECTMIBLOCK_H
#define VIPERNEC_NECTMIBLOCK_H

/** NECTMIBlock
 *
 *  Original NEC documentation:
 *
 *  <ul>COMMON/TMI/</ul> ZPK, RKB2, IJX
 *
 *  <ul>Routines Using /TMI/</ul>
 *      EKSC, EKSCX, GF
 *
 *      /TMI/ is used to pass values from EKSC or EKSCX to GF. The meanings of
 *  the variables are listed in subroutines EKSC and ZKSCX.
 *
 *  @since v1.0
 */
typedef struct tmi_block {
  
  /**
   *  zpk = k*z where k = 2*pi/wl (wavelength, wl, = 1), and z = z coordinate of
   *  field point.
   */
  double zpk;
  
  /**
   *  rkb2 = (k*p)^2 where k = 2*pi/wl (wavelength, wl, = 1), and p = rho 
   *  coordinate of field point.
   */
  double rkb2;
  
  /**
   *  If equal to 0, the field point is on the source segment.
   */
  long ijx;
  
} NECTMIBlock;

#endif
