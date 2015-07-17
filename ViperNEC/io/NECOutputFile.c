//
//  NECOutputFile.c
//  ViperNEC
//
//  Created by Dylan Crocker on 12/9/14.
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

#include "NECOutputFile.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "const.h"

#define BUFF_SIZE 512

NECOutputFile* NECOutputFileMake(const char *outputFilePath) {
  
  // Allocate an NECOutputFile object on the heap.
  NECOutputFile *ret_val = malloc(sizeof(NECOutputFile));
  
  // Get the length of path string.
  size_t path_len = strlen(outputFilePath);
  
  // Allocate memory and copy the string over...
  ret_val->filePath = malloc((path_len + 1)*sizeof(char));
  strcpy(ret_val->filePath, outputFilePath);
  
  // Attempt to create the file.
  FILE *file = fopen(outputFilePath, "w+");
  if (!file) { return NULL; }
  
  // Close the file
  fclose(file);
  
  return ret_val;
}

void NECOutputFileDelete(NECOutputFile *file) {
  
  if (!file) {
    return; // No file to delete.
  }
  
  // Free the memory holding the file path.
  if (file->filePath) {
    free(file->filePath);
    file->filePath = NULL;
  }
  
  // Free the struct
  free(file);
  
  // set pointer to null
  file = NULL;
  
}

bool NECOutputFileWriteLine(NECOutputFile *file, const char *line) {
  
  if (!file) { return false; }
  
  // Attempt to open the file for writting (append mode).
  FILE *file_p = fopen(file->filePath, "a+");
  if (!file_p) { return false; }
  
  // Write the line (pre-formatted) to the file.
  fprintf(file_p, "%s", line);
  fprintf(file_p, "%s", "\n");
  
  // Close the file.
  fclose(file_p);
  
  return true; // return true if everything completes successfully.
}

bool NECOutputFileWrite(NECOutputFile *file, const char *chars) {
  
  if (!file) { return false; }
  
  // Attempt to open the file for writting (append mode).
  FILE *file_p = fopen(file->filePath, "a+");
  if (!file_p) { return false; }
  
  // Write the characters (pre-formatted) to the file.
  fprintf(file_p, "%s", chars);
  
  // Close the file.
  fclose(file_p);
  
  return true; // return true if everything completes successfully.
}

/******************************************************************************/
// Geometry Data Helper Functions (datagn_2)
/******************************************************************************/

#define WIRE_SPEC_FORMAT_STRING " %5zu%11.5f%11.5f%11.5f %11.5f%11.5f%11.5f%11.5f  %5li    %5zu %5zu   %5li"
#define PATCH_SPEC_FORMAT_STRING " %5zu%s%10.5f%11.5f%11.5f %11.5f%11.5f%11.5f"
#define PATCH_SPEC_P2_FORMAT_STRING "      %11.5f%11.5f%11.5f %11.5f%11.5f%11.5f"
#define MULTI_PATCH_SPEC_P1_FORMAT_STRING " %5zuP   %10.5f%11.5f%11.5f %11.5f%11.5f%11.5f     SURFACE -%4li BY %3li PATCHES"
#define MULTI_PATCH_SPEC_P2_FORMAT_STRING "      %11.5f%11.5f%11.5f %11.5f%11.5f%11.5f"
#define TAPPER_FORMAT_STRING "         ABOVE WIRE IS TAPERED.  SEG. LENGTH RATIO =%9.5f\n                                 RADIUS FROM%9.5f TO%9.5f"
#define ARC_FORMAT_STRING " %5zu  ARC RADIUS =%9.5f  FROM%8.3f TO%8.3f DEGREES           %11.5f  %5li    %5li %5li   %5li"
#define HELIX_FORMAT_STRING "     HELIX STRUCTURE-   AXIAL SPACING BETWEEN TURNS =%8.3f TOTAL AXIAL LENGTH =%8.3f %5li  RADIUS OF HELIX =  %8.3f  %8.3f  %8.3f  %8.3f       %11.5f%8li    %5li %5li   %5li"
#define MOVE_FORMAT_STRING "      THE STRUCTURE HAS BEEN MOVED, MOVE DATA CARD IS -      %3li%5li%10.5f%10.5f%10.5f%10.5f%10.5f%10.5f%10.5f"
#define ROTATE_FORMAT_STIRNG "      STRUCTURE ROTATED ABOUT Z-AXIS%3li TIMES.  LABELS INCREMENTED BY%5li"
#define GEOMETRY_ERROR_FORMAT_STRING " GEOMETRY DATA CARD ERROR\n %s%3li%5li%10.5f%10.5f%10.5f%10.5f%10.5f%10.5f%10.5f"
#define WIRE_SEGMENTATION_HEADER_STRING_1 "\n\n\n\n                                 - - - - SEGMENTATION DATA - - - -\n\n                                        COORDINATES IN METERS\n\n                         I+ AND I- INDICATE THE SEGMENTS BEFORE AND AFTER I\n\n"
#define WIRE_SEGMENTATION_HEADER_STRING_2 "  SEG.   COORDINATES OF SEG. CENTER     SEG.     ORIENTATION ANGLES    WIRE    CONNECTION DATA   TAG\n  NO.       X         Y         Z       LENGTH     ALPHA     BETA      RADIUS    I-   I    I+    NO."
#define WIRE_SEGMENTATION_FORMAT_STRING " %5zu%10.5f%10.5f%10.5f%10.5f %10.5f%10.5f%10.5f %s%5li%s %5li"
#define PATCH_DATA_HEADER_STRING "\n\n\n\n                                            - - - SURFACE PATCH DATA - - - \n\n                                                 COORDINATES IN METERS\n\n PATCH     COORD. OF PATCH CENTER       UNIT NORMAL VECTOR      PATCH         COMPONENTS OF UNIT TANGENT VECTORS\n  NO.      X         Y         Z         X       Y       Z       AREA       X1      Y1      Z1       X2      Y2      Z2"
#define PATCH_DATA_FORMAT_STRING " %4li%10.5f%10.5f%10.5f %8.4f%8.4f%8.4f%10.5f %8.4f%8.4f%8.4f %8.4f%8.4f%8.4f"
#define REFLECT_STRUCTURE_FORMAT_STRING "      STRUCTURE REFLECTED ALONG THE AXES %s %s %s3.  TAGS INCREMENTED BY%5li"

bool NECOutputFileWriteWireStructureSpec(NECOutputFile *file, size_t nwire,
                                         double s1_x, double s1_y, double s1_z,
                                         double s2_x, double s2_y, double s2_z,
                                         double radius, size_t num_segs,
                                         size_t star_seg, size_t stop_seg,
                                         long tag) {
  char buffer[BUFF_SIZE];
  sprintf(buffer, WIRE_SPEC_FORMAT_STRING, nwire, s1_x, s1_y, s1_z, s2_x, s2_y, s2_z,
          radius, num_segs, star_seg, stop_seg, tag);
  return NECOutputFileWriteLine(file, buffer);
}

bool NECOutputFileWritePatchStructureSpec(NECOutputFile *file, size_t p_num,
                                          const char* ipt, double x1, double y1,
                                          double z1, double x2, double y2,
                                          double z2) {
  char buffer[BUFF_SIZE];
  sprintf(buffer, PATCH_SPEC_FORMAT_STRING, p_num, ipt, x1, y1, z1, x2, y2, z2);
  return NECOutputFileWriteLine(file, buffer);
}

bool NECOutputFileWritePatchStructureSpecPart2(NECOutputFile *file, double x3,
                                               double y3, double z3, double x4,
                                               double y4, double z4) {
  char buffer[BUFF_SIZE];
  sprintf(buffer, PATCH_SPEC_P2_FORMAT_STRING, x3, y3, z3, x4, y4, z4);
  return NECOutputFileWriteLine(file, buffer);
}

bool NECOutputFileWriteMultiPatchSpecP1(NECOutputFile *file, size_t p_num,
                                        double x1, double y1, double z1,
                                        double x2, double y2, double z2,
                                        long nx, long ny) {
  char buffer[BUFF_SIZE];
  sprintf(buffer, MULTI_PATCH_SPEC_P1_FORMAT_STRING, p_num, x1, y1, z1, x2, y2,
          z2, nx, ny);
  return NECOutputFileWriteLine(file, buffer);
}

bool NECOutputFileWriteMultiPatchSpecP2(NECOutputFile *file, double x3,
                                        double y3, double z3, double x4,
                                        double y4, double z4) {
  char buffer[BUFF_SIZE];
  sprintf(buffer, MULTI_PATCH_SPEC_P2_FORMAT_STRING, x3, y3, z3, x4, y4, z4);
  return NECOutputFileWriteLine(file, buffer);
}

bool NECOutputFileWriteWireTapperData(NECOutputFile *file, double rdel,
                                      double rad1, double rad2) {
  char buffer[BUFF_SIZE];
  sprintf(buffer, TAPPER_FORMAT_STRING, rdel, rad1, rad2);
  return NECOutputFileWriteLine(file, buffer);
}

bool NECOutputFileWriteArcData(NECOutputFile *file,  size_t nwire, double rada,
                               double ang1, double ang2, double rad,
                               long num_segs, long start_seg, long last_seg,
                               long tag) {
  char buffer[BUFF_SIZE];
  sprintf(buffer, ARC_FORMAT_STRING, nwire, rada, ang1, ang2, rad, num_segs,
          start_seg, last_seg, tag);
  return NECOutputFileWriteLine(file, buffer);
}

bool NECOutputFileWriteHelixData(NECOutputFile *file, double nturns,
                                 double zlen, size_t nwire, double hr1,
                                 double hr2, double wr1, double wr2,
                                 double ispx, size_t num_segs, size_t first_seg,
                                 size_t last__seg, long tag) {
  char buffer[BUFF_SIZE];
  sprintf(buffer, HELIX_FORMAT_STRING, nturns, zlen, nwire, hr1, hr2, wr1, wr2,
          ispx, num_segs, first_seg, last__seg, tag);
  return NECOutputFileWriteLine(file, buffer);
}

bool NECOutputFileWriteGeometryCardError(NECOutputFile *file, const char* code,
                                         long int_1, long int_2, double real_1,
                                         double real_2, double real_3,
                                         double real_4, double real_5,
                                         double real_6, double real_7) {
  char buffer[BUFF_SIZE];
  sprintf(buffer, GEOMETRY_ERROR_FORMAT_STRING, code, int_1, int_2, real_1,
          real_2, real_3, real_5, real_5, real_6, real_7);
  return NECOutputFileWriteLine(file, buffer);
}

bool NECOutputFileWriteZAxisRotation(NECOutputFile *file, long i1, long i2) {
  char buffer[BUFF_SIZE];
  sprintf(buffer, ROTATE_FORMAT_STIRNG, i1, i2);
  return NECOutputFileWriteLine(file, buffer);
}

bool NECOutputFileWriteStructureMoved(NECOutputFile *file, long i1, long i2,
                                      double f1, double f2, double f3,
                                      double f4, double f5, double f6,
                                      double f7) {
  char buffer[BUFF_SIZE];
  sprintf(buffer, MOVE_FORMAT_STRING, i1, i2, f1, f2, f3, f4, f5, f6, f7);
  return NECOutputFileWriteLine(file, buffer);
}

bool NECOutputFileWriteScaleStructure(NECOutputFile *file, double scale_fac) {
  char buffer[BUFF_SIZE];
  sprintf(buffer, "      STRUCTURE SCALED BY FACTOR%10.5f", scale_fac);
  return NECOutputFileWriteLine(file, buffer);
}

bool NECOutputFileWriteWireSementationHeader(NECOutputFile *file) {
  return (NECOutputFileWriteLine(file, WIRE_SEGMENTATION_HEADER_STRING_1) &&
          NECOutputFileWriteLine(file, WIRE_SEGMENTATION_HEADER_STRING_2));
}

bool NECOutputFileWriteWireSementationData(NECOutputFile *file, size_t seg_no,
                                           double x, double y, double z,
                                           double length, double alpha,
                                           double beta, double rad, long im,
                                           long ip, long tag) {
  char ip_text[6] = "     ";
  if (ip > NEC_PATCH_OFFSET) {
    ip -= NEC_PATCH_OFFSET;
    sprintf(ip_text, "%4liP", ip);
  } else if (ip == NEC_NO_CONNECTION) {
    sprintf(ip_text, "   NC");
  } else {
    sprintf(ip_text, "%5li", ip);
  }
  char im_text[6] = "     ";
  if (im > NEC_PATCH_OFFSET) {
    im -= NEC_PATCH_OFFSET;
    sprintf(im_text, "%4liP", im);
  } else if (im == NEC_NO_CONNECTION) {
    sprintf(im_text, "   NC");
  } else {
    sprintf(im_text, "%5li", im);
  }
  char buffer[BUFF_SIZE];
  sprintf(buffer, WIRE_SEGMENTATION_FORMAT_STRING, seg_no, x, y, z, length,
          alpha, beta, rad, im_text, seg_no, ip_text, tag);
  return NECOutputFileWriteLine(file, buffer);
}

bool NECOutputFileWritePatchDataHeader(NECOutputFile *file) {
  return NECOutputFileWriteLine(file, PATCH_DATA_HEADER_STRING);
}

bool NECOutputFileWritePatchData(NECOutputFile *file, size_t patch_no, double x,
                                 double y, double z, double un_x, double un_y,
                                 double un_z, double area, double ut_x1,
                                 double ut_y1, double ut_z1, double ut_x2,
                                 double ut_y2, double ut_z2) {
  char buffer[BUFF_SIZE];
  sprintf(buffer, PATCH_DATA_FORMAT_STRING, patch_no, x, y, z, un_x, un_y, un_z,
          area, ut_x1, ut_y1, ut_z1, ut_x2, ut_y2, ut_z2);
  return NECOutputFileWriteLine(file, buffer);
}

bool NECOutputFileWriteReflectionData(NECOutputFile *file, long ix, long iy,
                                      long iz, long itx) {
  char *x_str = (ix) ? "X   " : "    ";
  char *y_str = (ix) ? "Y   " : "    ";
  char *z_str = (ix) ? "Z   " : "    ";
  char buffer[BUFF_SIZE];
  sprintf(buffer, REFLECT_STRUCTURE_FORMAT_STRING, x_str, y_str, z_str, itx);
  return NECOutputFileWriteLine(file, buffer);
}

////////////////////////////////////////////////////////////////////////////////
// Convenience functions for writing geometry information from connect_2.
////////////////////////////////////////////////////////////////////////////////

#define SEGMENTS_USED_FORMAT_STRING "\n   TOTAL SEGMENTS USED= %5li     NO. SEG. IN A SYMMETRIC CELL= %5li     SYMMETRY FLAG=%3li"
#define PATCHES_USED_FORMAT_STRING "   TOTAL PATCHES USED=%5li      NO. PATCHES IN A SYMMETRIC CELL=%5li"
#define FOLDS_SYMMETRY_FORMAT_STRING "STRUCTURE HAS\%4li FOLD ROTATIONAL SYMMETRY\n"
#define PLANES_SYMMETRY_FORMAT_STRING " STRUCTURE HAS %2li PLANES OF SYMMETRY\n"
#define MULTIWIRE_JUNCTIONS_HEADER_FORMAT_STRING "\n\n         - MULTIPLE WIRE JUNCTIONS -\n JUNCTION    SEGMENTS  (- FOR END 1, + FOR END 2)"


bool NECOutputFileWriteGroundSpec(NECOutputFile *file, long ignd) {
  if (!NECOutputFileWriteLine(file, "\n   GROUND PLANE SPECIFIED.")) {
    return false;
  }
  if (ignd > 0) {
    return NECOutputFileWriteLine(file, "\n   WHERE WIRE ENDS TOUCH GROUND, "
                                  "CURRENT WILL BE INTERPOLATED TO IMAGE IN "
                                  "GROUND PLANE.\n");
  }
  return true;
}

bool NECOutputFileWriteSegmentsUsed(NECOutputFile *file, size_t n, size_t np,
                               long ipsym) {
  char buffer[BUFF_SIZE];
  sprintf(buffer, SEGMENTS_USED_FORMAT_STRING, n, np, ipsym);
  return NECOutputFileWriteLine(file, buffer);
}

bool NECOutputFileWritePatchesUsed(NECOutputFile *file, size_t m, size_t mp) {
  char buffer[BUFF_SIZE];
  sprintf(buffer, PATCHES_USED_FORMAT_STRING, m, mp);
  return NECOutputFileWriteLine(file, buffer);
}

bool NECOutputFileWriteFoldRotationalSymmetry(NECOutputFile *file, long iseg) {
  char buffer[BUFF_SIZE];
  sprintf(buffer, FOLDS_SYMMETRY_FORMAT_STRING, iseg);
  return NECOutputFileWriteLine(file, buffer);
}

bool NECOutputFileWritePlanesOfSymmetry(NECOutputFile *file, long ic) {
  char buffer[BUFF_SIZE];
  sprintf(buffer, PLANES_SYMMETRY_FORMAT_STRING, ic);
  return NECOutputFileWriteLine(file, buffer);
}

bool NECOutputFileWriteMultiwireJunctionsHeader(NECOutputFile *file) {
  return NECOutputFileWriteLine(file, MULTIWIRE_JUNCTIONS_HEADER_FORMAT_STRING);
}

bool NECOutputFileWriteMultiwireJunction(NECOutputFile *file, long iseg,
                                         long *jco, long ic) {
  char buffer[BUFF_SIZE];
  sprintf(buffer, " %5li     ", iseg);
  if (!NECOutputFileWrite(file, buffer)) { return false; }
  for (int i = 0; i < ic; i++) {
    if (i == 20) {
      if (!NECOutputFileWrite(file, "\n           ")) { return false; }
    }
    sprintf(buffer, "%5li", jco[i]);
    if (!NECOutputFileWrite(file, buffer)) { return false; }
  }
  return NECOutputFileWriteLine(file, "");
}

////////////////////////////////////////////////////////////////////////////////
// Convenience functions for writing geometry information from helix_2.
////////////////////////////////////////////////////////////////////////////////

#define CONE_ANGLE_FORMAT_STRING "     THE CONE ANGLE OF THE SPIRAL IS%10.4f"
#define PITCH_ANGLE_FORMAT_STRING "     THE PITCH ANGLE IS%10.4f"
#define WIRE_TURN_LENGTH_FORMAT_STRING "     THE LENGTH OF WIRE/TURN IS%10.4f"

bool NECOutputFileWriteConeAngle(NECOutputFile *file, double angle) {
  char buffer[BUFF_SIZE];
  sprintf(buffer, CONE_ANGLE_FORMAT_STRING, angle);
  return NECOutputFileWriteLine(file, buffer);
}

bool NECOutputFileWritePitchAngle(NECOutputFile *file, double angle) {
  char buffer[BUFF_SIZE];
  sprintf(buffer, PITCH_ANGLE_FORMAT_STRING, angle);
  return NECOutputFileWriteLine(file, buffer);
}

bool NECOutputFileWriteWireTurnLength(NECOutputFile *file, double length) {
  char buffer[BUFF_SIZE];
  sprintf(buffer, WIRE_TURN_LENGTH_FORMAT_STRING, length);
  return NECOutputFileWriteLine(file, buffer);
}
