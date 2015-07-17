//
//  geometry.h
//  ViperNEC
//
//  Created by Dylan Crocker on 7/16/15.
//  Copyright 2015 Viper Science
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

#ifndef VIPERNEC_GEOMETRY_H
#define VIPERNEC_GEOMETRY_H

#include "blocks.h"
#include "error.h"
#include "io.h"

void datagn_2(NECInputFile *input, NECDataBlock **data, NECAngleBlock **angl,
              NECPlotBlock **plot, NECCurrentExpansionBlock **segj,
              NECOutputFile **output_file, NECError **error);

void readgm_2(char *card, char *code, size_t code_len, int *i1, int *i2,
              double *r1, double *r2, double *r3, double *r4,
              double *r5, double *r6, double *r7);

bool wire_2(NECDataBlock *data, double *xw1, double *yw1,
            double *zw1, double *xw2, double *yw2,
            double *zw2, double *rad, double *rdel,
            double *rrad, int *ns, int *itg,
            NECError **error_block);

bool helix_2(NECDataBlock *data, double *s, double *hl, double *a1, double *b1,
             double *a2, double *b2, double *rad, int *ns, int *itg,
             NECOutputFile *outfile, NECError **error);

bool arc_2(NECDataBlock *data, int *itg, int *ns, double *rada,
           double *ang1, double *ang2, double *rad,
           NECError **error_block);

bool patch_2(NECDataBlock *data, NECAngleBlock *angl, int *nx,
             int *ny, double *x1, double *y1, double *z1,
             double *x2, double *y2, double *z2, double *x3,
             double *y3, double *z3, double *x4, double *y4,
             double *z4, NECError **error_block);

bool subph_2(NECDataBlock *data, NECAngleBlock *angl, size_t nx, int ny,
             NECError **error_block);

bool connect_2(NECDataBlock *data, NECCurrentExpansionBlock *segj,
               NECAngleBlock *angl, int *ignd, NECOutputFile *outfile,
               NECError **error);

bool move_2(NECDataBlock *data, NECAngleBlock *angl, double *rox,
            double *roy, double *roz, double *xs, double *ys,
            double *zs, int *its, int *nrpt, int *itgi,
            NECError **error_block);

size_t isegno_2(NECDataBlock *data, long itagi, long mx, NECError **error);

bool reflc_2(NECDataBlock *data, NECAngleBlock *angl, int *ix, int *iy,
             int *iz, int *itx, int *nop, NECError **error_block);

#endif
