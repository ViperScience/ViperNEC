//
//  label_id.c
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

/**
 * This functions returns an Enum of type NECCardLabel which represents the 
 * line (or card) label from the current line of the input file.
 *
 * @param readLabel This is the line label read from the input file (char[2]).
 * @return NECCardLabel enum type representing the label (CardLabel_Unkown if
 * the type cannot be determined).
 * @since v1.0
 */
NECCardLabel label_id(const char *readLabel) {
  
  // Create static (unchangeing) variables that represent all possible labels.
  static int numLabels = 35;
  static char labels[35][2] = {
    {"CE"}, {"FR"}, {"LD"}, {"GN"}, {"EX"}, {"NT"}, {"XQ"}, {"NE"}, {"GD"},
    {"RP"}, {"CM"}, {"NX"}, {"EN"}, {"TL"}, {"PT"}, {"KH"}, {"NH"}, {"PQ"},
    {"EK"}, {"WG"}, {"CP"}, {"PL"}, {"GW"}, {"GX"}, {"GR"}, {"GS"}, {"GE"},
    {"GM"}, {"SP"}, {"SM"}, {"GF"}, {"GA"}, {"SC"}, {"GC"}, {"GH"}
  };
  
  // Serach through the possible labels and return the index. This value can
  // then be used in a switch statement to determine the appropriate action.
  for (int index = 0; index < numLabels; ++index) {
    if ((*readLabel == labels[index][0]) &&
        (*(readLabel + 1) == labels[index][1])) {
      return index;
    }
  }
  return CardLabel_Unkown;
}