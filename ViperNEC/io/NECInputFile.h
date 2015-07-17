//
//  NECInputFile.h
//  ViperNEC
//
//  Created by Dylan Crocker on 7/14/14.
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

#ifndef NEC_INPUT_FILE_H
#define NEC_INPUT_FILE_H

/** NECInputFile
 * This struct holds the data read from an NEC input file. It is created by the
 * NECInputFileMake function and should be cleaned up with the function
 * NECInputFileDelete. Once parsed it contains the textual data from a given
 * input file and can then be used to pass inout file data to other code for 
 * processing.
 *
 * @since v1.0
 */
typedef struct input_file {
  
  /** Buffer for storing pointers to the comment card text data read from the
   * input file.
   *
   * @since v1.0
   */
  char **commentCards;
  
  /** Buffer for storing pointers to the geometry card text data read from the
   * input file.
   *
   * @since v1.0
   */
  char **geometryCards;
  
  /** Buffer for storing pointers to the control card text data read from the 
   * input file.
   *
   * @since v1.0
   */
  char **controlCards;
  
  /** The number of comment cards found in the input file (not including the 
   * comment end card).
   *
   * @since v1.0
   */
  size_t commentCardCount;
  
  /** The number of comment cards found in the input file (not including the 
   * geometry end card).
   *
   * @since v1.0
   */
  size_t geometryCardCount;
  
  /** The number of control cards found in the input file.
   *
   * @since v1.0
   */
  size_t controlCardCount;
  
  /** Counts the total cards in the file (including the end cards).
   *
   * @since v1.0
   */
  size_t cardCount;
  
} NECInputFile;

/** NECInputFileMake
 * Read an NEC input file and fill an NECInputFile struct. If a file error 
 * occurs the returned value is NULL.
 *
 * @param inputFilePath Path to the NEC input file to be read.
 * @since v1.0
 */
NECInputFile* NECInputFileMake(const char *inputFilePath);

/** NECInputFileDelete
 * Frees all dynamically allocated memory in the given NECInputFile struct
 * as well as the struct's memory itself. The input pointer will be set to NULL.
 *
 * @param file An NECInputFile object that has been initialized (mallaoc) and
 *             has dynamically created arrays that need released.
 * @since v1.0
 */
void NECInputFileDelete(NECInputFile *file);

#endif
