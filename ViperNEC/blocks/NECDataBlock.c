//
//  NECDataBlock.c
//  ViperNEC
//
//  Created by Dylan Crocker on 7/15/14.
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

#include "NECDataBlock.h"
#include <stdio.h>

NECDataBlock *NECDataBlockMake(size_t wire_buff_size, size_t ptch_buff_size) {
  NECDataBlock *new_data = calloc(1, sizeof(NECDataBlock));
  new_data->x = malloc(wire_buff_size*sizeof(double));
  new_data->y = malloc(wire_buff_size*sizeof(double));
  new_data->z = malloc(wire_buff_size*sizeof(double));
  new_data->si = malloc(wire_buff_size*sizeof(double));
  new_data->bi = malloc(wire_buff_size*sizeof(double));
  new_data->alp = malloc(wire_buff_size*sizeof(double));
  new_data->bet = malloc(wire_buff_size*sizeof(double));
  new_data->itag = malloc(wire_buff_size*sizeof(long int));
  new_data->icon1 = malloc(wire_buff_size*sizeof(long int));
  new_data->icon2 = malloc(wire_buff_size*sizeof(long int));
  new_data->iconx = malloc(wire_buff_size*sizeof(long int));
  new_data->xp = malloc(ptch_buff_size*sizeof(double));
  new_data->yp = malloc(ptch_buff_size*sizeof(double));
  new_data->zp = malloc(ptch_buff_size*sizeof(double));
  new_data->t1x = malloc(ptch_buff_size*sizeof(double));
  new_data->t1y = malloc(ptch_buff_size*sizeof(double));
  new_data->t1z = malloc(ptch_buff_size*sizeof(double));
  new_data->t2x = malloc(ptch_buff_size*sizeof(double));
  new_data->t2y = malloc(ptch_buff_size*sizeof(double));
  new_data->t2z = malloc(ptch_buff_size*sizeof(double));
  new_data->pa = malloc(ptch_buff_size*sizeof(double));
  new_data->ld = wire_buff_size;
  new_data->lp = ptch_buff_size;
  new_data->n2 = 1; // n1 is 0 since calloc
  new_data->m2 = 1; // m1 is 0 since calloc
  return new_data;
}

void NECDataBlockDelete(NECDataBlock *data) {
  if (data != NULL) {
    if (data->x != NULL) { free(data->x); }
    if (data->y != NULL) { free(data->y); }
    if (data->z != NULL) { free(data->z); }
    if (data->si != NULL) { free(data->si); }
    if (data->bi != NULL) { free(data->bi); }
    if (data->alp != NULL) { free(data->alp); }
    if (data->bet != NULL) { free(data->bet); }
    if (data->itag != NULL) { free(data->itag); }
    if (data->icon1 != NULL) { free(data->icon1); }
    if (data->icon2 != NULL) { free(data->icon2); }
    if (data->iconx != NULL) { free(data->iconx); }
    if (data->xp != NULL) { free(data->xp); }
    if (data->yp != NULL) { free(data->yp); }
    if (data->zp != NULL) { free(data->zp); }
    if (data->t1x != NULL) { free(data->t1x); }
    if (data->t1y != NULL) { free(data->t1y); }
    if (data->t1z != NULL) { free(data->t1z); }
    if (data->t2x != NULL) { free(data->t2x); }
    if (data->t2y != NULL) { free(data->t2y); }
    if (data->t2z != NULL) { free(data->t2z); }
    if (data->pa != NULL) { free(data->pa); }
    free(data);
    data = NULL;
  }
}

void NECDataBlockPrint(NECDataBlock *data) {
  
  // Print the wire segment data...
  printf("\nWire Data: segment start and stop (xyz) and connection data.\n");
  for (size_t i = 0; i < data->n; ++i) {
    printf("%f %f %f\n", data->x[i], data->y[i], data->z[i]);
    printf("%f %f %f\n", data->si[i], data->alp[i], data->bet[i]);
    printf("%li %li\n", data->icon1[i], data->icon2[i]);
    printf("%s","\n");
  }
  
  // Print the surface patch data...
  printf("\nPatch Data\n x        y        z       area\n");
  for (size_t i = 0; i < data->m; ++i) {
    printf("%f %f %f %f\n", data->xp[i], data->yp[i], data->zp[i], data->pa[i]);
    printf("%s","\n");
  }
  
}

bool NECDataBlockResizeBuffers(NECDataBlock *data,
                               size_t wire_buff_size,
                               size_t patch_buff_size) {
  // This function attempts to reallocate the buffers in the given data block to
  // a different size. If any reallocation is unsucessful the function returns
  // false - at this point all buffers may not be the same size in memory but ld
  // will remain unchanged. All buffers still must be deallocated to
  // avoid a memory leak.
  
  if (data->ld != wire_buff_size) {
    
    void *new_x_ptr = realloc(data->x, wire_buff_size*sizeof(double));
    if (new_x_ptr == NULL) { return false; }
    data->x = new_x_ptr;
    
    void *new_y_ptr = realloc(data->y, wire_buff_size*sizeof(double));
    if (new_y_ptr == NULL) { return false; }
    data->y = new_y_ptr;
    
    void *new_z_ptr = realloc(data->z, wire_buff_size*sizeof(double));
    if (new_z_ptr == NULL) { return false; }
    data->z = new_z_ptr;
    
    void *new_si_ptr = realloc(data->si, wire_buff_size*sizeof(double));
    if (new_si_ptr == NULL) { return false; }
    data->si = new_si_ptr;
    
    void *new_bi_ptr = realloc(data->bi, wire_buff_size*sizeof(double));
    if (new_bi_ptr == NULL) { return false; }
    data->bi = new_bi_ptr;
    
    void *new_alp_ptr = realloc(data->alp, wire_buff_size*sizeof(double));
    if (new_alp_ptr == NULL) { return false; }
    data->alp = new_alp_ptr;
    
    void *new_bet_ptr = realloc(data->bet, wire_buff_size*sizeof(double));
    if (new_bet_ptr == NULL) { return false; }
    data->bet = new_bet_ptr;
    
    void *new_itag_ptr = realloc(data->itag, wire_buff_size*sizeof(long int));
    if (new_itag_ptr == NULL) { return false; }
    data->itag = new_itag_ptr;

    void *new_icon1_ptr = realloc(data->icon1, wire_buff_size*sizeof(long int));
    if (new_icon1_ptr == NULL) { return false; }
    data->icon1 = new_icon1_ptr;
    
    void *new_icon2_ptr = realloc(data->icon2, wire_buff_size*sizeof(long int));
    if (new_icon2_ptr == NULL) { return false; }
    data->icon2 = new_icon2_ptr;
    
    void *new_iconx_ptr = realloc(data->iconx, wire_buff_size*sizeof(long int));
    if (new_iconx_ptr == NULL) { return false; }
    data->iconx = new_iconx_ptr;
    
    data->ld = wire_buff_size;
    
  }
  
  if (data->lp != patch_buff_size) {
    
    void *new_xp_ptr = realloc(data->xp, patch_buff_size*sizeof(double));
    if (new_xp_ptr == NULL) { return false; }
    data->xp = new_xp_ptr;
    
    void *new_zp_ptr = realloc(data->zp, patch_buff_size*sizeof(double));
    if (new_zp_ptr == NULL) { return false; }
    data->zp = new_zp_ptr;
    
    void *new_yp_ptr = realloc(data->yp, patch_buff_size*sizeof(double));
    if (new_yp_ptr == NULL) { return false; }
    data->yp = new_yp_ptr;
    
    void *new_t1x_ptr = realloc(data->t1x, patch_buff_size*sizeof(double));
    if (new_t1x_ptr == NULL) { return false; }
    data->t1x = new_t1x_ptr;
    
    void *new_t1y_ptr = realloc(data->t1y, patch_buff_size*sizeof(double));
    if (new_t1y_ptr == NULL) { return false; }
    data->t1y = new_t1y_ptr;
    
    void *new_t1z_ptr = realloc(data->t1z, patch_buff_size*sizeof(double));
    if (new_t1z_ptr == NULL) { return false; }
    data->t1z = new_t1z_ptr;
    
    void *new_t2x_ptr = realloc(data->t2x, patch_buff_size*sizeof(double));
    if (new_t2x_ptr == NULL) { return false; }
    data->t2x = new_t2x_ptr;
    
    void *new_t2y_ptr = realloc(data->t2y, patch_buff_size*sizeof(double));
    if (new_t2y_ptr == NULL) { return false; }
    data->t2y = new_t2y_ptr;
    
    void *new_t2z_ptr = realloc(data->t2z, patch_buff_size*sizeof(double));
    if (new_t2z_ptr == NULL) { return false; }
    data->t2z = new_t2z_ptr;
   
    void *new_pa_ptr = realloc(data->pa, patch_buff_size*sizeof(double));
    if (new_pa_ptr == NULL) { return false; }
    data->pa = new_pa_ptr;
    
    data->lp = patch_buff_size;
    
  }
  
  return true;
}

bool NECDataBlockDoubleBuffers(NECDataBlock *data) {
  return NECDataBlockResizeBuffers(data, data->ld*2, data->lp*2);
}

bool NECDataBlockDoubleWireBuffers(NECDataBlock *data) {
  return NECDataBlockResizeBuffers(data, data->ld*2, data->lp);
}

bool NECDataBlockDoublePatchBuffers(NECDataBlock *data) {
  return NECDataBlockResizeBuffers(data, data->ld, data->lp*2);
}

bool NECDataBlockEnlargeBuffers(NECDataBlock *data, size_t wmn, size_t pmn) {
  return NECDataBlockEnlargeWireBuffers(data, wmn) &&
         NECDataBlockEnlargePatchBuffers(data, pmn);
}

bool NECDataBlockEnlargeWireBuffers(NECDataBlock *data, size_t min) {
  int ret_val = true;
  if (data->ld <= min) {
    do {
      ret_val = NECDataBlockDoubleWireBuffers(data);
    } while (data->ld < min);
  }
  return ret_val;
}

bool NECDataBlockEnlargePatchBuffers(NECDataBlock *data, size_t min) {
  int ret_val = true;
  if (data->lp <= min) {
    do {
      ret_val = NECDataBlockDoublePatchBuffers(data);
    } while (data->lp < min);
  }
  return ret_val;
}
