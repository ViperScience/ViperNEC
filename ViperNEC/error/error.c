//
//  error.c
//  ViperNEC
//
//  Created by Dylan Crocker on 7/31/14.
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

#include "error.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

NECError *NECErrorMake(bool flag, NECErrorCode code, const char* message) {
  NECError *new_error = malloc(sizeof(NECError));
  new_error->flag = flag;
  new_error->code = code;
  strncpy(new_error->message, message, MESSAGE_SIZE);
  return new_error;
}

void NECErrorDelete(NECError *error) {
  if (error != NULL) {
    free(error);
    error = NULL;
  }
}

////////////////////////////////////////////////////////////////////////////////
// Convenience methods for creating widely used error blocks.
////////////////////////////////////////////////////////////////////////////////

#define MESSAGE_OUT_OF_MEMORY "System out of memory!"
#define MESSAGE_NO_INPUT_DATA "No input NEC simulation data provided."
#define MESSAGE_INVALID_INPUT "Invalid input to function call."

NECError *NECErrorMakeNoError() {
  return NECErrorMake(false, NoError, "");
}

NECError *NECErrorMakeOutOfMemeory() {
  return NECErrorMake(true, OutOFMemoryError, MESSAGE_OUT_OF_MEMORY);
}

NECError *NECErrorMakeNoInputData() {
  return NECErrorMake(true, NoInputDataError, MESSAGE_NO_INPUT_DATA);
}

NECError *NECErrorMakeInvalidInput() {
  return NECErrorMake(true, InvalidInputError, MESSAGE_INVALID_INPUT);
}

////////////////////////////////////////////////////////////////////////////////
// Errors Defined in the NEC documentation.
////////////////////////////////////////////////////////////////////////////////

NECError *NECErrorMake001() {
  return NECErrorMake(true, Error001, "Check data, parameter specifying"
      " segment position in a group of equal tags cannot be zero.");
}

NECError *NECErrorMake002(size_t segment) {
  char msg[MESSAGE_SIZE];
  sprintf(msg, "Connect - segment connection error for segment %li.", segment);
  return NECErrorMake(true, Error002, msg);
}

NECError *NECErrorMake003(size_t card_no, size_t step_1, size_t step_2) {
  char msg[MESSAGE_SIZE];
  sprintf(msg, "DATA FAULT ON LOADING CARD NO. %li ITAG STEP1 %li IS GREATER "
      "THAN ITAG STEP2 %li.", card_no, step_1, step_2);
  return NECErrorMake(true, Error003, msg);
}

NECError *NECErrorMake004(size_t unit, size_t nblks, size_t neof) {
  char msg[MESSAGE_SIZE];
  sprintf(msg, "EOF ON UNIT %li NBLKS = %li NEOF = %li", unit, nblks, neof);
  return NECErrorMake(true, Error004, msg);
}

NECError *NECErrorMake005() {
  return NECErrorMake(true, Error005, "ERROR - ARC ANGLE EXCEEDS 360 DEGREES.");
}

NECError *NECErrorMake006() {
  return NECErrorMake(true, Error006, "ERROR - B LESS THAN A IN ROM2.");
}

NECError *NECErrorMake007() {
  return NECErrorMake(true, Error007, "ERROR - FR/GN CARD IS NOT ALLOWED WITH "
                      "N.G.F.");
}

NECError *NECErrorMake008() {
  return NECErrorMake(true, Error008, "ERROR - CORNERS OF QUADRILATERAL PATCH "
                      "DO NOT LIE IN A PLANE.");
}

NECError *NECErrorMake009() {
  return NECErrorMake(true, Error009,
                      "ERROR - COUPLING IS NOT BETWEEN 0 AND 1.");
}

NECError *NECErrorMake010() {
  return NECErrorMake(true, Error010,
                      "ERROR - GF MUST BE FIRST GEOMETRY DATA CARD.");
}

NECError *NECErrorMake011() {
  return NECErrorMake(true, Error011, "ERROR IN GROUND PARAMETERS");
}

NECError *NECErrorMake012() {
  return NECErrorMake(true, Error012, "ERROR - INSUFFICIENT STORAGE FOR "
                      "INTERACTION MATRICES.");
}

NECError *NECErrorMake013() {
  return NECErrorMake(true, Error013,
                      "ERROR - INSUFFICIENT STORAGE FOR MATRIX.");
}

NECError *NECErrorMake014() {
  return NECErrorMake(true, Error014,
                      "ERROR - NETWORK ARRAY DIMENSIONS TOO SMALL.");
}

NECError *NECErrorMake015() {
  return NECErrorMake(true, Error015, "ERROR - LOADING MAY NOT BE ADDED TO "
                      "SEGMENTS IN N.G.F. SECTION.");
}

NECError *NECErrorMake016() {
  return NECErrorMake(true, Error016,
                      "ERROR - N.G.F. IN USE. CANNOT WRITE NEW N.G.F.");
}

NECError *NECErrorMake017() {
  return NECErrorMake(true, Error017, "ERROR - NO. NEW SEGMENTS CONNECTED TO "
                      "N.G.F. SEGMENTS OR PATCHES.");
}

NECError *NECErrorMake018() {
  return NECErrorMake(true, Error018,
                      "FAULTY DATA CARD LABEL AFTER GEOMETRY SECTION.");
}

NECError *NECErrorMake019() {
  return NECErrorMake(true, Error019, "GEOMETRY DATA CARD ERROR.");
}

NECError *NECErrorMake020(size_t patch) {
  char msg[MESSAGE_SIZE];
  sprintf(msg, "GEOMETRY DATA ERROR - PATCH %li LIES IN PLANE OF SYMMETRY.",
          patch);
  return NECErrorMake(true, Error020, msg);
}

NECError *NECErrorMake021(size_t segment) {
  char msg[MESSAGE_SIZE];
  sprintf(msg, "GEOMETRY DATA ERROR - SEGMENT %li EXTENDS BELOW GROUND.",
          segment);
  return NECErrorMake(true, Error021, msg);
}

NECError *NECErrorMake022(size_t segment) {
  char msg[MESSAGE_SIZE];
  sprintf(msg, "GEOMETRY DATA ERROR - SEGMENT %li LIES IN GROUND PLANE.",
          segment);
  return NECErrorMake(true, Error022, msg);
}

NECError *NECErrorMake023(size_t segment) {
  char msg[MESSAGE_SIZE];
  sprintf(msg, "GEOMETRY DATA ERROR - SEGMENT %li LIES IN PLANE OF SYMMETRY.",
          segment);
  return NECErrorMake(true, Error023, msg);
}

NECError *NECErrorMake024(int load_type) {
  char msg[MESSAGE_SIZE];
  sprintf(msg, "IMPROPER LOAD TYPE CHOSEN, REQUESTED TYPE IS %i.",
          load_type);
  return NECErrorMake(true, Error024, msg);
}

NECError *NECErrorMake025() {
  return NECErrorMake(true, Error025, "INCORRECT LABEL FOR A COMMENT CARD.");
}

NECError *NECErrorMake026(size_t tag) {
  char msg[MESSAGE_SIZE];
  sprintf(msg, "LOADING DATA CARD ERROR, NO SEGMENT HAS AN ITAG = %li.", tag);
  return NECErrorMake(true, Error026, msg);
}

NECError *NECErrorMake027(size_t tag) {
  char msg[MESSAGE_SIZE];
  sprintf(msg, "NO SEGMENT HAS AN ITAG OF %li.", tag);
  return NECErrorMake(true, Error027, msg);
}

NECError *NECErrorMake028() {
  return NECErrorMake(false, Error028, "NOTE, SOME OF THE ABOVE SEGMENTS HAVE "
                      "BEEN LOADED TWICE, IMPEDANCES ADDED.");
}

NECError *NECErrorMake029() {
  return NECErrorMake(false, Error029, "NUMBER OF EXCITATION CARDS EXCEEDS "
                      "STORAGE ALLOTTED.");
}

NECError *NECErrorMake030() {
  return NECErrorMake(false, Error030,
                      "NUMBER OF LOADING CARDS EXCEEDS STORAGE ALLOTTED.");
}

NECError *NECErrorMake031() {
  return NECErrorMake(true, Error031,
                      "NUMBER OF NETWORK CARDS EXCEEDS STORAGE ALLOTTED.");
}

NECError *NECErrorMake032() {
  return NECErrorMake(true, Error032, "NUMBER OF SEGMENTS IN COUPLING "
                      "CALCULATION (CP) EXCEEDS LIMIT.");
}

NECError *NECErrorMake033() {
  return NECErrorMake(true, Error033, "NUMBER OF WIRE SEGMENTS AND/OR SURFACE "
                      "PATCHES EXCEEDS DIMENSION LIMIT.");
}

NECError *NECErrorMake034() {
  return NECErrorMake(true, Error034, "PATCH DATA ERROR.");
}

NECError *NECErrorMake035(size_t pass, double element) {
  char msg[MESSAGE_SIZE];
  sprintf(msg, "PIVOT( %lu ) = %f.", pass, element);
  return NECErrorMake(true, Error035, msg);
}

NECError *NECErrorMake036() {
  return NECErrorMake(true, Error036, "RADIAL WIRE G.S. APPROXIMATION MAY NOT "
                      "BE USED WITH SOMOMERFELD GROUND OPTION.");
}

NECError *NECErrorMake037() {
  return NECErrorMake(true, Error037, "RECEIVING PATTERN STORAGE TOO SMALL, "
                      "ARRAY TRUNCATED.");
}

NECError *NECErrorMake038(size_t z) {
  char msg[MESSAGE_SIZE];
  sprintf(msg, "STEP SIZE LIMITED AT Z = %lu.", z);
  return NECErrorMake(true, Error038, msg);
}

NECError *NECErrorMake039(size_t segment) {
  char msg[MESSAGE_SIZE];
  sprintf(msg, "SBF - SEGMENT CONNECTION ERROR FOR SEGMENT  %lu.", segment);
  return NECErrorMake(true, Error039, msg);
}

NECError *NECErrorMake040() {
  return NECErrorMake(true, Error040, "SEGMENT DATA ERROR.");
}

NECError *NECErrorMake041(size_t z) {
  char msg[MESSAGE_SIZE];
  sprintf(msg, "STEP SIZE LIMITED AT Z = %lu.", z);
  return NECErrorMake(true, Error041, msg);
}

NECError *NECErrorMake042() {
  return NECErrorMake(true, Error042, "STORAGE FOR IMPEDANCE NORMALIZATION "
                      "TOO SMALL, ARRAY TRUNCATED.S");
}

NECError *NECErrorMake043(size_t row, size_t col) {
  char msg[MESSAGE_SIZE];
  sprintf(msg, "SYMMETRY ERROR - NROW, NCOL = %lu, %lu.", row, col);
  return NECErrorMake(true, Error044, msg);
}

NECError *NECErrorMake044(size_t segment) {
  char msg[MESSAGE_SIZE];
  sprintf(msg, "TBF - SEGMENT CONNECTION ERROR FOR SEGMENT %lu.", segment);
  return NECErrorMake(true, Error044, msg);
}

NECError *NECErrorMake045(size_t segment) {
  char msg[MESSAGE_SIZE];
  sprintf(msg, "TRIO - SEGMENT CONNECTION ERROR FOR SEGMENT %lu.", segment);
  return NECErrorMake(true, Error045, msg);
}

NECError *NECErrorMake046() {
  return NECErrorMake(true, Error046, "WHEN MULTIPLE FREQUENCIES ARE "
                      "REQUESTED, ONLY ONE NEAR FIELD CARD CAN BE USED - LAST "
                      "CARD READ IS USED.");
}
