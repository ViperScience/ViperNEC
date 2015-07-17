//
//  upcase_2.c
//  ViperNEC
//
//  Created by Dylan Crocker on 6/28/14.
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

/**
 * This function (upcase_2) is a cleaned up version of the function generated by
 * f2c (upcase_) with some modifications. The main change is the removal of
 * superfluous variables. The length the input and output buffers should be the
 * same.
 *
 * Original FORTRAN documentation:
 * UPCASE finds the length of INTEXT and converts it to upper case.
 *
 * @param intext The text to be converted.
 * @param outtxt The buffer to which the converted text is stored.
 * @param length The length of the text to be converted. Note: the output buffer
 *               must at minimum contain room for length+1 characters.
 * @since v1.0
 */
void upcase_2(char *intext, char *outtxt, int length) {
  char j;
  for (int index = 0; index < length; ++index) {
    j = intext[index];
    if (j >= 96) {
      j += -32;
    }
    outtxt[index] = j;
  }
}
