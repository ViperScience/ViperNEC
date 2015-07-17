//
//  NECGroundBlock.h
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

#ifndef VIPERNEC_NECGROUNDBLOCK_H
#define VIPERNEC_NECGROUNDBLOCK_H

#include "types.h"

/** NECGroundBlock
 *  This struct contains parameters of the ground including the two-medium
 *  ground and radial-wire ground-screen cases. It was implamnted as a common
 *  block in the original FORTRAN.
 *
 *  Original NEC Documentation:
 *
 *  <ul>COMMON/GND/</ul> ZRATI, ZRATI2, FRATI, CL, CH, SCRWL, SCRWR, NRADL, 
 *  KSYMP, IFAR, IPERF, T1, T2
 *
 *  <ul>Routines Using /CND/</ul>
 *      MAIN, CMSW, EFLD, ETMNS, FFLD, GFIL, GFOUT, HINTG, HSFLD, NEFLD, RDPAT,
 *  SFLDS, UNERE
 *
 *      /GND/ contains parameters of the ground including the two-medium ground
 *  and radial-wire ground-screen cases. The symbol definitions are as follows.
 *
 *      ZRATI = [er - j*sig/(w*e0)]^(-1/2)
 *              where sig is ground conductivity (mhos/meter), er is the
 *              relative dlelectrlc constant, e0 is the permittivity of
 *              free space (farads/meter), and w = 2*pi*f.
 *      ZRATI2 = same as ZRATI, but for a second ground medium
 *      FRATI = (k1^2 - k2^2)/(k1^2 + k2^2) where k2 = w*sqrt(m0*e0) and 
 *              k1 = k2/ZRATI
 *      CL = distance in wavelengths of cliff edge from origin
 *      CH = cliff height in wavelengths
 *      SCRWL = lenth of wires in radial-wire ground screen (normalized to 
 *              wavelength)
 *      SCRWR = radius of wires in screen in wavelengths
 *      NRADL = number of radials in ground screen; zero implies no screen
 *              (input quantity, GN card)
 *      KSYMP = ground flag (=1, no ground; =2, ground present)
 *      IFAR = input integer flag on RP card; speclfies type of field
 *             computation or type of ground system for far fields
 *      IPERF = flag to select type of ground (see GN card)
 *      TI, T2 = constants for the radial-wire ground-screen impedance
 *
 *  @since v1.0
 */
typedef struct gnd_block {
  
  complex_t zrati;
  complex_t zrati2;
  complex_t frati;
  complex_t t1;
  double t2;
  double cl;
  double ch;
  double scrwl;
  double scrwr;
  long nradl;
  long ksymp;
  long ifar;
  long iperf;
  
} NECGroundBlock;

#endif
