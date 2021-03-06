//
//  parsit_2.c
//  ViperNEC
//
//  Created by Dylan Crocker on 7/16/14.
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
#include "types.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAX_FIELDS 12
#define BUFF_SIZE 20 

/** parsit_2
 * This function (parsit_2) is a cleaned up and modified version of the function
 * generated by f2c (parsit_). Major changes include the removal of the f2c
 * FORTRAN style I/O which would read the input file, instead the line of text
 * is passed as an input variable. Additionaly, standard C functions (strtol and
 * strtod) are used to convert the numerical values from the text instead of the
 * messy code that parsed out the values manually.
 *
 * Original FORTRAN description:
 * PARSIT reads an input record and parses it.
 *
 * @param card The line of text representing the record (card) to be parsed.
 * @param maxint The total number of integers in record.
 * @param maxrea The total number of real values in record.
 * @param cmnd A two letter mnemonic code indicating the card type.
 * @param intfld Integer values from the record (card).
 * @param reafld Real values from the record (card).
 * @since v1.0
 */
void parsit_2(char *card, char *cmnd, int cmnd_len, int *maxint, int *maxrea,
              int *intfld, double *reafld) {
  
  // Check inputs...
  if (card == NULL) { return; }
  
  // Make sure the text is in upper case.
  int totcol = (int)strlen(card); // total number of columns in card text
  upcase_2(card, card, totcol);
  
  // Store the opcode.
  strncpy(cmnd, card, 2);
  
  // Clear the field arrays.
  int bgnfld[MAX_FIELDS]; // list of starting indices
  int endfld[MAX_FIELDS]; // list of ending indices
  for (int i = 0; i < *maxint; ++i) { intfld[i] = 0; }
  for (int j = 0; j < *maxrea; ++j) { reafld[j] = 0; }
  for (int k = 0; k < MAX_FIELDS; ++k) {
    bgnfld[k] = 0;
    endfld[k] = 0;
  }
  
  bool fldtrm = false; // flag to indicate that pointer is in field position
  int totfld = 0; // number of numeric fields
  char k; // temp variable used to hold a char from the text being parsed.
  
  // Find the beginning and ending of each field as well as the total number of
  // fields.
  for (ftnlen j = cmnd_len; j < totcol; ++j) {
    k = card[j]; // Get the char to analyze.
    if (k == 33) {
      // Check for end of line comment ('!'). This is a new modification to allow
      // VAX-like comments at the end of data records, e.g.,
      //       GW 1 7 0 0 0 0 0 .5 .0001 ! DIPOLE WIRE
      //       GE ! END OF GEOMETRY
      if (fldtrm) {
        // The current index is the ending symbol, the last index was the end of
        // the field (j - 1). This will never error out because fldtrm should be
        // false at the start and j should start at index 2 (cmnd_len).
        endfld[totfld - 1] = j - 1;
        fldtrm = false;
      }
    } else if (k == 32 || k == 44) {
      // Set the ending index when the character is a comma or space and the
      // pointer is in a field position (FLDTRM = TRUE).
      if (fldtrm) {
        // The current index is the ending symbol, the last index was the end of
        // the field (j - 1). This will never error out because fldtrm should be
        // false at the start and j should start at index 2 (cmnd_len).
        endfld[totfld - 1] = j - 1;
        fldtrm = false;
      }
    } else if (!fldtrm) {
      // Set the beginning index when the character is not a comma or space and
      // the pointer is not currently in a field position (FLDTRM = FALSE).
      ++totfld;
      fldtrm = true;
      bgnfld[totfld - 1] = j; // The current index starts the field.
    }
  }
  
  if (fldtrm) { endfld[totfld - 1] = totcol; }
  
  // Check to see if the total number of value fields is within the precribed
  // limits.
  if (totfld == 0) {
    return; // Some cards have no data fields (e.g., the EK card).
  } else if (totfld > (*maxrea + *maxint)) {
    // Ignore fields outside the expected number of fields. If the user is
    // stupid then the code will try to work any way...
    totfld = (*maxrea + *maxint);
  }
  
  // Initialize a buffer to hold the textual versions of the inputs.
  int bufflen = 20;
  char buffer[bufflen]; // text buffer.
  for (int i = 0; i < bufflen; ++i) {
    buffer[i] = '\0';
  }
  
  //  Parse out integer values and store into integer buffer array.
  for (int n = 0; n < fmin(totfld, *maxint); ++n) {
    int fld_len = endfld[n] - bgnfld[n] + 1; // Length of the field (must add 1).
    
    // Copy out the field from the original text.
    strncpy(buffer, card + bgnfld[n], fld_len);
    for (int i = fld_len; i < bufflen; ++i) {
      buffer[i] = '\0';
    }
    
    // The old version had code here to look for a decimal point and freak out
    // if it found one. The strtol function will stop when it gets to a decimal
    // or return 0 if the decimal is first.
    intfld[n] = (int)strtol(buffer, NULL, 0);
  }
  
  //  Parse out real values and store into real buffer array.
  if (totfld > *maxint) {
    for (int m = *maxint; m < totfld; ++m) {
      int fld_len = endfld[m] - bgnfld[m] + 1; // Length of the field (must add 1).
      
      // Copy out the field from the original text.
      strncpy(buffer, card + bgnfld[m], fld_len);
      for (int i = fld_len; i < bufflen; ++i) {
        buffer[i] = '\0';
      }
      
      // The old code was way more involved trying to parse the textual
      // representation of a double. The strtod function takes care of this
      // automatically.
      reafld[m - *maxint] = strtod(buffer, NULL);
    }
  }
  
}
