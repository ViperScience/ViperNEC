//
//  readgm_.c
//  ViperNEC
//
//  Created by Dylan Crocker on 7/5/14.
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

#include "cards.h"

#define NUM_INTS  2
#define NUM_REALS 7

/**
 * This function (readgm_2) is a cleaned up version of the function generated by
 * f2c (readgm_) with some modifications. The main modification is that the
 * string of text for parsing is passed as an input parameter.
 *
 * Original FORTRAN documentation:
 * READGM reads a geometry record and parses it.
 *
 * @param card The line of text representing the record (card) to be read.
 * @param code The two letter mnemonic code inidicating card type.
 * @param i1 - i2 Integer values from the record.
 * @param r1 - r7 Real values from the record.
 *
 * @since v1.0
 */
void readgm_2(char *card, char *code, int code_len, int *i1, int *i2,
              double *r1, double *r2, double *r3, double *r4, double *r5,
              double *r6, double *r7) {
  
  // Local variables
  int numInts = NUM_INTS;
  int numReals = NUM_REALS;
  int intval[NUM_INTS];
  double reaval[NUM_REALS];
  
  // Call parsit_ to parse the actual line.
  parsit_2(card, code, code_len, &numInts, &numReals, intval, reaval);
  
  //  Set the return variables to the buffer array elements.
  *i1 = intval[0];
  *i2 = intval[1];
  *r1 = reaval[0];
  *r2 = reaval[1];
  *r3 = reaval[2];
  *r4 = reaval[3];
  *r5 = reaval[4];
  *r6 = reaval[5];
  *r7 = reaval[6];
}
