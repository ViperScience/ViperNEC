//
//  NECSEGJBlock.c
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

#include "NECCurrentExpansionBlock.h"

#include <stdlib.h>

#define STARTING_BUFFER_SIZE 30

NECCurrentExpansionBlock *NECCurrentExpansionBlockMake() {
  NECCurrentExpansionBlock *ret_val =
      calloc(1, sizeof(NECCurrentExpansionBlock));
  if (ret_val != NULL) {
    ret_val->ax = malloc(STARTING_BUFFER_SIZE*sizeof(double));
    if (ret_val->ax == NULL) { NECCurrentExpansionBlockDelete(ret_val); }
    ret_val->bx = malloc(STARTING_BUFFER_SIZE*sizeof(double));
    if (ret_val->bx == NULL) { NECCurrentExpansionBlockDelete(ret_val); }
    ret_val->cx = malloc(STARTING_BUFFER_SIZE*sizeof(double));
    if (ret_val->cx == NULL) { NECCurrentExpansionBlockDelete(ret_val); }
    ret_val->jco = malloc(STARTING_BUFFER_SIZE*sizeof(long));
    if (ret_val->jco == NULL) { NECCurrentExpansionBlockDelete(ret_val); }
  }
  ret_val->jsize = STARTING_BUFFER_SIZE;
  return ret_val;
}

void NECCurrentExpansionBlockDelete(NECCurrentExpansionBlock *segj) {
  if (segj != NULL) {
    if (segj->ax != NULL) { free(segj->ax); }
    if (segj->bx != NULL) { free(segj->bx); }
    if (segj->cx != NULL) { free(segj->cx); }
    if (segj->jco != NULL) { free(segj->jco); }
    if (segj->ipcon != NULL) { free(segj->ipcon); }
    if (segj->iscon != NULL) { free(segj->iscon); }
    free(segj);
    segj = NULL;
  }
}

bool NECCurrentExpansionBlockBufferSize(NECCurrentExpansionBlock *segj,
                                        size_t min_size) {
  size_t new_buff_size = segj->jsize * 2;
  if ((segj != NULL) && (segj->jsize < min_size)) {
    do {
      void *new_ax_ptr = realloc(segj->ax, new_buff_size*sizeof(double));
      if (new_ax_ptr == NULL) { return false; }
      segj->ax = new_ax_ptr;
      void *new_bx_ptr = realloc(segj->bx, new_buff_size*sizeof(double));
      if (new_bx_ptr == NULL) { return false; }
      segj->bx = new_bx_ptr;
      void *new_cx_ptr = realloc(segj->cx, new_buff_size*sizeof(double));
      if (new_cx_ptr == NULL) { return false; }
      segj->cx = new_cx_ptr;
      void *new_jco_ptr = realloc(segj->jco, new_buff_size*sizeof(long));
      if (new_jco_ptr == NULL) { return false; }
      segj->jco = new_jco_ptr;
      segj->jsize = new_buff_size;
    } while (segj->jsize < min_size);
  }
  return true;
}

// These shouldn't be used much so re-allocating the buffer each time should
// be ok. Maybe revisit this later.

bool NECCurrentExpansionBlockPushBackISCON(NECCurrentExpansionBlock *segj,
                                           long iscon) {
  size_t new_buff_size = segj->nscon + 1;
  void *new_ptr = realloc(segj->iscon, new_buff_size*sizeof(long));
  if (new_ptr == NULL) { return false; }
  segj->iscon = new_ptr;
  segj->iscon[segj->nscon] = iscon;
  segj->nscon++;
  return true;
}

bool NECCurrentExpansionBlockPushBackIPCON(NECCurrentExpansionBlock *segj, long ipcon) {
  size_t new_buff_size = segj->npcon + 1;
  void *new_ptr = realloc(segj->ipcon, new_buff_size*sizeof(long));
  if (new_ptr == NULL) { return false; }
  segj->ipcon = new_ptr;
  segj->ipcon[segj->npcon] = ipcon;
  segj->npcon++;
  return true;
}
