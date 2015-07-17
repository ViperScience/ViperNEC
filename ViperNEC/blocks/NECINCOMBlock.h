//
//  NECINCOMBlock.h
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

#ifndef VIPERNEC_NECINCOMBLOCK_H
#define VIPERNEC_NECINCOMBLOCK_H

/**
 *  Original NEC documentation:
 *
 *  <ul>COMMON/INCOM/</ul> XO, YO, ZO, SN, XSN, YSN, ISNOR
 *
 *  <ul>Routines Using /GWAV/</ul>
 *      EFLD, SFLDS
 *
 *  <ul>Symbol Definitions</ul>
 *      XO, YO, ZO = point at which field due to ground will be evaluated
 *      SN = cos(alpha) (See Figure 11)
 *      XSN = cos(beta)
 *      YSN = sin(beta)
 *      ISNOR = 1 to evaluate field due to ground by interpolation
 *              0 to use Norton's approximation
 *
 *  @since v1.0
 */
struct {
  double xo, yo, zo, sn, xsn, ysn;
  int isnor;
} incom_;

#endif
