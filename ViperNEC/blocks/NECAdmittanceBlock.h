//
//  NECAdmittanceBlock.h
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

#ifndef VIPERNEC_NECADMITTANCEBLOCK_H
#define VIPERNEC_NECADMITTANCEBLOCK_H

#include "types.h"

/** NECAdmittanceBlock
 *
 *  Original NEC documentation:
 *
 *  <ul>COMMON/YPARM</ul> NCOUP, ICOUP, NCTAG(5), NCSEQ(5), YllA(5), Y12A(20)
 *
 *  <ul>Routines Using /YPARM/</ul>
 *      MAIN, COUPLE
 *
 *  <ul>Symbol Definitions</ul>
 *      NCOUP = number of segments between which coupling will be computed
 *      ICOUP = number of segments in the coupling array that have been
 *              excited. When ICOUP = NCOUP subroutine COUPLE completes the
 *              coupling calculation
 *      NCTAG(I) = tag number of segment I
 *      NCSEG(I) = number of segment in set of segments having tag NCTAG(I)
 *      Y11A(I) = self admittance of Ith segment specified 
 *      Y12A(I) = mutual admittances stored in order (1,2), (1,3), ... (2,3),
 *                (2,4), ... etc.
 *
 *  @since v1.0
 */
typedef struct yparm_block {
  complex_t y11a[5], y12a[20];
  long ncoup, icoup, nctag[5], ncseg[5];
} NECAdmittanceBlock;

#endif
