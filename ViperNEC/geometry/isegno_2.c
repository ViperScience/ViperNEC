//
//  isegno_2.c
//  ViperNEC
//
//  Created by Dylan Crocker on 7/26/14.
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

#include "blocks.h"
#include "error.h"
#include "const.h"

/**
 *  This function (seg_idx) is a cleaned up version of the function isegno_ 
 *  which was generated by F2c. It has been modified to return the index of the 
 *  specified which starts at zero rather than the segment number which starts
 *  with 1. Additional modifications include the removal of a global data 
 *  structure containing all the buffers to hold the geometry data, which has
 *  been replaced by a data object (pointer) that is passed as an input to the
 *  function. Additionally, the function has been modified to so that the
 *  segment tag 0 does not have to be the first set of segments.
 *
 *  @param data  NECDataBlock in which the parsed geometry data is stored. This
 *               cannot be NULL or the function will not execute.
 *  @param itagi The input tag number (given tag).
 *  @param mx    The input quantity specifying the position in the set of
 *               segments with the given tag (starts at 1).
 *  @param erb   NECError block (pointer to a pointer) to hold error info.
 *
 *  @return Segment index of the mx-th segment having the given tag.
 *
 *  @since v1.0
 */
size_t seg_idx(NECDataBlock *data, long itagi, long mx, NECError **erb) {
  size_t ret_val = NEC_SEGMENT_NOT_FOUND;
  
  // Error if mx is less than 1.
  if (mx < 1) {
    if (erb) { *erb = NECErrorMake001(); }
    return ret_val;
  }
  
  // If the tag is at the start of the data, the number mx is returned.
  if (itagi == data->itag[0]) { return (mx - 1); } // Save a bit of time.
  
  // Only run the check if the buffer actually contains segment data.
  if (data->n > 0) {
    // Loop through all the segments looking for a match.
    int icnt = 0; // counter
    for (size_t i = 0; i < data->n; ++i) {
      // First match the tag number.
      if (data->itag[i] == itagi) {
        ++icnt; // Count the segments with the given tag.
        if (icnt == mx) {
          ret_val = i;
          break; // Break the loop if the segment is found.
        }
      }
    }
  }
  
  // Another error... Segment not found.
  if (ret_val == NEC_SEGMENT_NOT_FOUND) {
    if (erb) { *erb = NECErrorMake027(itagi); }
  }
  return ret_val;
}

/**
 *  This function returns the segment number (not index) of the specified 
 *  segment. The segment number starts at 1. The function seg_idx is used to 
 *  find the segment index which is incremented and returned provided no errors
 *  occur.
 *
 *  Original NEC Documentation:
 *
 *  PURPOSE
 *      To determine the segment number of the mth segment ordered by increasing
 *  segment numbers in the set of segments with tag numbers equal to the given
 *  tag number. With a given tag of zero, segment number m is returned.
 *
 *  METHOD
 *      Search segments consecutively and check their tag numbers against a
 *  given tag.
 *
 *  @param data  NECDataBlock in which the parsed geometry data is stored. This
 *               cannot be NULL or the function will not execute.
 *  @param itagi The input tag number (given tag).
 *  @param mx    The input quantity specifying the position in the set of
 *               segments with the given tag (starts at 1).
 *  @param erb   NECError block (pointer to a pointer) to hold error info.
 *
 *  @return Segment index of the mx-th segment having the given tag.
 *
 *  @since v1.0
 */
size_t isegno_2(NECDataBlock *data, long itagi, long mx, NECError **er) {
  size_t idx = seg_idx(data, itagi, mx, er);
  if (er) {
    if ((**er).flag) {
      return NEC_SEGMENT_NOT_FOUND;
    }
  }
  return (idx + 1);
}
