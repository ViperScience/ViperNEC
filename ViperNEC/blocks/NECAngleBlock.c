//
//  NECAngleBlock.c
//  ViperNEC
//
//  Created by Dylan Crocker on 7/21/14.
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

#include "NECAngleBlock.h"

NECAngleBlock *NECAngleBlockMake(size_t asize, size_t ssize) {
  NECAngleBlock *new_block = calloc(1, sizeof(NECAngleBlock));
  if (new_block != NULL) {
    new_block->alpha = malloc(asize*sizeof(double));
    new_block->salp = malloc(ssize*sizeof(double));
    new_block->la = asize;
    new_block->ls = ssize;
    if ((new_block->alpha == NULL) || (new_block->salp == NULL)) {
      NECAngleBlockDelete(new_block);
    }
  }
  return new_block;
}

void NECAngleBlockDelete(NECAngleBlock *block) {
  if (block != NULL) {
    if (block->alpha != NULL) { free(block->alpha); }
    if (block->salp != NULL) { free(block->salp); }
    free(block);
    block = NULL;
  }
}

bool NECAngleBlockResizeBuffers(NECAngleBlock *blck, size_t wsz, size_t psz) {
  
  // Resize the wire segment data buffer.
  if (blck->la != wsz) {
    void *new_ptr1 = realloc(blck->alpha, wsz*sizeof(double));
    if (new_ptr1 == NULL) { return false; }
    blck->alpha = new_ptr1;
    blck->la = wsz;
  }
  
  // Resize the surface patch data buffer.
  if (blck->ls != psz) {
    void *new_ptr2 = realloc(blck->salp, psz*sizeof(double));
    if (new_ptr2 == NULL) { return false; }
    blck->salp = new_ptr2;
    blck->ls = psz;
  }
  
  return true;
}

bool NECAngleBlockEnlargeWireBuffer(NECAngleBlock *block, size_t min_size) {
  int ret_val = true;
  if (block->la < min_size) {
    do {
      ret_val = NECAngleBlockResizeBuffers(block, block->la * 2, block->ls);
    } while (block->la < min_size);
  }
  return ret_val;
}

bool NECAngleBlockEnlargePatchBuffer(NECAngleBlock *block, size_t min_size) {
  int ret_val = true;
  if (block->ls < min_size) {
    do {
      ret_val = NECAngleBlockResizeBuffers(block, block->la, block->ls * 2);
    } while (block->ls < min_size);
  }
  return ret_val;
}
