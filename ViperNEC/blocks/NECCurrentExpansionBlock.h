//
//  NECCurrentExpansionBlock.h
//  ViperNEC
//
//  Created by Dylan Crocker on 7/25/14.
//  Copyright 2014 Viper Science
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

#ifndef NEC_SEGJ_BLOCK_H
#define NEC_SEGJ_BLOCK_H

#include <stdlib.h>
#include <stdbool.h>

/** NECCurrentExpansionBlock
 *
 * <u>Original NEC documentation:</u>
 *
 * COMMON/SEGJ/ AX(30), BX(30), CX(30), JCO(30), JSNO, ISCON(50), NSCON,
 * IPCON(10), NPLON
 *
 * Routines Using /SEGJ/
 * MAIN, CABC, CMNGF, CMSET, CMSW, CMWS, CMWW, CONECT, QDSRC, SFLDS, TBF, TRIO
 *
 *     /SEGJ/ is used to store the parameters defining current expansion
 * functions. The equations for the current expansion functions are given in
 * Section III-1 of Part I. The i th current expansion function consist of a
 * center section on segment i and branches on each segment connected to segment
 * i. On segment j, where j is i or the number of a segment connected to segment
 * i, the i expansion function is
 *
 *      i       i   i                  i
 *     f (s) = A + B sin[k(s - sj)] + C cos[k(s - sj)]
 *      j       j   j                  j
 *
 * with the constants defined in Part I to match conditions on the current. A
 * super script i has been added to indicate the number of the current expansion
 * function.
 *     When subroutine TBF is called for expansion function i, it locates each
 * segment connected to segment i and stores the segment number, j, in array
 * JCO. TBF also computes the constants A, B, and C for segment j and stores
 * them in AX, BX, and CX, respectively.
 *     After all connected segments have been found, i is stored in the next
 * location in JCO, and A, B, and C, (for segment i) are stored in the
 * corresponding locations in AX, BX, and CX.
 *     /SEGJ/ is also used by subroutine TRIO. When TRIO is called for segment
 * j, it locates each segment i connected to segment j and stores i in array
 * JCO. TRIO calls SBF to compute the constants A, B, and C for the branch of
 * expansion function i that extends onto segment j and stores these in AX, BX,
 * and C. The total number of entries, including i - j, is stored in JSNO. The
 * remaining parameters are used with the NGF solution.
 *
 *     ISCON(I) = number of the segment in the NGF file having equation number
 *                I in the set of equations for modified basis functions.
 *                This is used when a new segment or patch connects to the NGF
 *                segment.
 *     NSCON    = number of entries in ISCON
 *     IPCON(I) = number of the patch in the NGF file having equation number I
 *                in the set of equations for modified patch basis functions.
 *                This is used when a new aegnent connects to the NGF patch
 *     NPCON    = Number of entries in IPCON
 *
 *
 * @since v1.0
 */
typedef struct segj_block {
  
  double *ax;   // Constants A for expansion function
  double *bx;   // Constants B for expansion function
  double *cx;   // Constants C for expansion function
  long   *jco;  // Segment numbers
  size_t jsno;  // Number of values stored in jco, ax, bx, and cx.
  size_t jsize; // Size of the buffers jco, ax, bx, and cx.
  
  // N.G.F. Data
  long   *iscon;
  size_t nscon;
  long   *ipcon;
  size_t npcon;
  
} NECCurrentExpansionBlock;

NECCurrentExpansionBlock *NECCurrentExpansionBlockMake();
void NECCurrentExpansionBlockDelete(NECCurrentExpansionBlock *segj);
bool NECCurrentExpansionBlockBufferSize(NECCurrentExpansionBlock *segj, size_t min_size);
bool NECCurrentExpansionBlockPushBackISCON(NECCurrentExpansionBlock *segj, long iscon);
bool NECCurrentExpansionBlockPushBackIPCON(NECCurrentExpansionBlock *segj, long ipcon);

#endif
