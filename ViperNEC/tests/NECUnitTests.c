//
//  NECUnitTests.c
//  ViperNEC
//
//  Created by Dylan Crocker on 8/23/14.
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

#include "NECUnitTests.h"
#include "const.h"
#include "blocks.h"
#include "types.h"
#include "cards.h"
#include "geometry.h"
#include "util.h"

#include <math.h>
#include <string.h>
#include <stdio.h>

//
// Useful for debugging:
// printf("%f %f",data->z[19],data->z[39]);
//

// One main function that will call all the unit test functions.
void run_all_unit_tests() {
  atgn__test();
  cang__test();
  dB_functions_test();
  upcase_2_test();
  parsit_2_test();
  readgm_2_test();
  wire_2_test();
  arc_2_test();
  helix_2_test();
  patch_2_test();
  subph_2_test();
  move_2_test();
  reflc_2_test();
  isegno_2_test();
  connect_2_test();
  gfil_2_test();
  NECInputFileMake_test();
  NECOutputFile_test();
  datagn_2_test_with_example_1();
  datagn_2_test_with_example_2();
  datagn_2_test_with_example_3();
  datagn_2_test_with_example_4();
  datagn_2_test_with_example_5();
  datagn_2_test_with_example_6();
  datagn_2_test_with_example_7();
}

// Test the atgn_ function (arctangent)
void atgn__test() {
  double x = sqrt(3), y = 1;
  assert(atgn2_(&x, &y) == M_PI/3);
  x = 0, y = 0;
  assert(atgn2_(&x, &y) == 0);
}

// Test the cang_ function.
// Calculates the phase angle of a complex number (degrees)
void cang__test() {
  complex_t c;
  c.i = 1;
  c.r = 1;
  assert(cang_(&c) == 45);
}

// Test the dB functions
void dB_functions_test() {
  double x = 10;
  assert(db10_(&x) == 10);
  assert(db20_(&x) == 20);
}

// Convert lower to upper case (test upcase_2).
void upcase_2_test() {
  int strsz = 5;
  char lower[] = "abcd";
  char upper[strsz];
  upcase_2(lower, upper, strsz);
  assert(strcmp(upper,"ABCD") == 0);
}

// Test parsit_2
void parsit_2_test() {
  int numInts = 2;
  int numReals = 7;
  int intval[2];
  double reaval[7];
  char code[] = "GM";
  char test_card[] = "GW 0 8 0. 0. -.25 0. 0. .25 .00001\n";
  parsit_2(test_card, code, 2, &numInts, &numReals, intval, reaval);
  assert(intval[0] == 0);
  assert(intval[1] == 8);
  assert(reaval[0] == 0.f);
  assert(reaval[1] == 0.f);
  assert(reaval[2] == -0.25);
  assert(reaval[3] == 0.f);
  assert(reaval[4] == 0.f);
  assert(reaval[5] == 0.25);
  assert(reaval[6] == 0.00001);
}

// Test readgm_2 by feeding it a test input card string.
void readgm_2_test() {
  int i1 = 0, i2 = 0; // The first two ints on the geometry card.
  double f1, f2, f3, f4, f5, f6, f7; // Real values read from card.
  char test_card[] = "GW 0 8 0. 0. -.25 0. 0. .25 .00001\n";
  char code[] = "GM";
  readgm_2(test_card, code, 2, &i1, &i2, &f1, &f2, &f3, &f4, &f5, &f6, &f7);
  assert(i1 == 0);
  assert(i2 == 8);
  assert(f1 == 0.f);
  assert(f2 == 0.f);
  assert(f3 == -0.25);
  assert(f4 == 0.f);
  assert(f5 == 0.f);
  assert(f6 == 0.25);
  assert(f7 == 0.00001);
}

// Unit tests for wire_2
void wire_2_test() {
  
  // Setup
  /****************************************************************************/
  
  // Create data storage blocks that will be used by the tests.
  NECDataBlock *data = NECDataBlockMake(1, 1);
  
  // Tests
  /****************************************************************************/
  int itg = 0, ns = 20;
  double xw1 = 0.0, yw1 = 0.0, zw1 = 0.0;
  double xw2 = 0.25, yw2 = 0.0, zw2 = 0.0;
  double rad = 0.00001;
  double rdel = 1.0;
  double rrad = 1.0;
  bool result = wire_2(data, &xw1, &yw1, &zw1, &xw2, &yw2, &zw2, &rad, &rdel, &rrad, &ns, &itg, NULL);
  assert(result);
  assert(data->ld >= ns);
  assert(data->n == ns);
  assert(data->x[0] == 0);
  assert(fabs(data->x[19] - (0.25 - 0.25/20)) < 1e-10);
  assert(data->si[19] == 0.25);
  assert(data->bi[10] == 0.00001);
  
  //NECDataBlockPrint(data); // visualize the data
  
  // Tear down
  /****************************************************************************/
  NECDataBlockDelete(data);
  
}

// Unit tests for arc_2
void arc_2_test() {
  
  // Setup
  /****************************************************************************/
  
  // Create data storage blocks that will be used by the tests.
  NECDataBlock *data = NECDataBlockMake(1, 1);
  
  // Tests
  /****************************************************************************/
  int itg = 1, ns = 10;
  double rad = 0.001, rada = 0.25, ang1 = 0.0, ang2 = 90;
  bool result = arc_2(data, &itg, &ns, &rada, &ang1, &ang2, &rad, NULL);
  assert(result);
  assert(data->ld >= ns);
  assert(data->n == ns);
  assert(data->bi[0] == 0.001);
  assert(data->x[0] == 0.25);
  assert(fabs(data->si[9]) < 1e-10);
  assert(data->y[5] == 0.0);
  assert(data->x[5] != 0.0);
  assert(data->si[5] != 0.0);
  
  // Tear down
  /****************************************************************************/
  NECDataBlockDelete(data);
  
}

// Unit tests for helix_2
void helix_2_test() {
  
  // Setup
  /****************************************************************************/
  NECDataBlock *data = NECDataBlockMake(1, 1);
  
  // Tests
  /****************************************************************************/
  
  double s = 0, hl = 0, a1 = 0, b1 = 0, a2 = 0, b2 = 0, rad = 0.001;
  int ns = 12, itg = 0;
  bool result = helix_2(data, &s, &hl, &a1, &b1, &a2, &b2, &rad, &ns, &itg, NULL, NULL);
  assert(result);
  assert(data->ld >= ns);
  assert(data->n == ns);
  // Check the calculated results later!! Don't forget!
  
  // Tear down
  /****************************************************************************/
  NECDataBlockDelete(data);
  
}

// Unit tests for patch_2
void patch_2_test() {
  
  // Setup
  /****************************************************************************/
  NECDataBlock *data = NECDataBlockMake(1, 1);
  NECAngleBlock *angl = NECAngleBlockMake(1, 1);
  
  // Tests
  /****************************************************************************/
  
  // Put in a plate of patches (5 x 4) sitting in the x,y plane.
  int nx = 5, ny = 4;
  double x1 = 0.0, y1 = 0.0, z1 = 0.0;
  double x2 = .25, y2 = 0.0, z2 = 0.0;
  double x3 = .25, y3 = 0.2, z3 = 0.0;
  double x4 = 0.0, y4 = 0.2, z4 = 0.0;
  bool result = patch_2(data, angl, &nx, &ny, &x1, &y1, &z1, &x2, &y2, &z2, &x3, &y3, &z3, &x4, &y4, &z4, NULL);
  assert(result);
  
  //NECDataBlockPrint(data); // Display the data for visual inspection.
  
  assert(data->m == 20);
  assert(data->lp >= 20);
  assert(fabs(data->pa[1] - 0.0025) < 1e-6);
  assert(fabs(data->pa[15] - 0.0025) < 1e-6);
  assert(data->pa[1] == data->pa[10]);
  assert(data->zp[0] == 0);
  assert(data->zp[9] == 0);
  assert(data->yp[0] == 0.025);
  assert(data->xp[0] == 0.025);
  assert(data->yp[19] == 0.175);
  assert(data->xp[19] == 0.225);
  
  // Test a single triangle patch.
  nx = 0; ny = 2 + 1;
  x1 = 0.0, y1 = 0.0, z1 = 0.0;
  x2 = .25, y2 = 0.0, z2 = 0.0;
  x3 = 0.0, y3 = 0.0, z3 = -0.25;
  result = patch_2(data, angl, &nx, &ny, &x1, &y1, &z1, &x2, &y2, &z2, &x3, &y3, &z3, &x4, &y4, &z4, NULL);
  assert(result);
  
  //NECDataBlockPrint(data); // Display the data for visual inspection.
  
  assert(data->m == 21);
  assert(data->lp >= 21);
  assert(fabs(data->pa[20] - 0.0625/2) < 1e-6);
  assert(fabs(data->xp[20] - 0.08333333333333) < 1e-6);
  assert(fabs(data->zp[20] + 0.08333333333333) < 1e-6);
  assert(data->yp[20] == 0.0);
  
  // Test a single quadrilateral patch.
  nx = 0; ny = 3 + 1; // ny = ns + 1
  x1 = 0.0, y1 = 0.2, z1 = 0.0;
  x2 = .25, y2 = 0.2, z2 = 0.0;
  x3 = .25, y3 = 0.3, z3 = -0.2;
  x4 = 0.0, y4 = 0.3, z4 = -0.2;
  result = patch_2(data, angl, &nx, &ny, &x1, &y1, &z1, &x2, &y2, &z2, &x3, &y3, &z3, &x4, &y4, &z4, NULL);
  assert(result);
  
  //NECDataBlockPrint(data); // Display the data for visual inspection.
  
  assert(data->m == 22);
  assert(data->lp >= 22);
  assert(fabs(data->xp[21] - 0.125) < 1e-9);
  assert(fabs(data->yp[21] - 0.25) < 1e-9);
  assert(fabs(data->zp[21] + 0.1) < 1e-9);
  assert(fabs(data->pa[21] - 0.0559017) < 1e-9);
  
  // Shapeless patch...
  nx = 0, ny = 0 + 1; // ny = ns + 1
  x1 = 0.0, y1 = 0.0, z1 = 0.0;
  x2 = 45., y2 = 45., z2 = 0.0625;
  result = patch_2(data, angl, &nx, &ny, &x1, &y1, &z1, &x2, &y2, &z2, &x3, &y3, &z3, &x4, &y4, &z4, NULL);
  
  //NECDataBlockPrint(data); // Display the data for visual inspection.
  
  assert(result);
  assert(data->m == 23);
  assert(data->lp >= 23);
  assert(data->pa[22] == z2);
  
  // Verify the T vectors are being calculated correctly
  
  nx = 0, ny = 2;
  x1 = 0.0, y1 = 0.0, z1 = 1.0; // Point 1
  x2 = 0.1, y2 = 0.0, z2 = 1.0; // Point 2
  x3 = 0.1, y3 = 0.2, z3 = 1.0; // Point 3
  x4 = 0.0, y4 = 0.2, z4 = 1.0; // Point 4
  result = patch_2(data, angl, &nx, &ny, &x1, &y1, &z1, &x2, &y2, &z2, &x3, &y3, &z3, &x4, &y4, &z4, NULL);
  assert(result);
  result = patch_2(data, angl, &nx, &ny, &x4, &y4, &z4, &x3, &y3, &z3, &x2, &y2, &z2, &x1, &y1, &z1, NULL);
  assert(result);
  ny = 3;
  x1 = 0.0, y1 = 0.0, z1 = 2.0; // Point 1
  x2 = 0.1, y2 = 0.2, z2 = 2.0; // Point 2
  x3 = 0.0, y3 = 0.2, z3 = 2.0; // Point 3
  result = patch_2(data, angl, &nx, &ny, &x1, &y1, &z1, &x2, &y2, &z2, &x3, &y3, &z3, &x4, &y4, &z4, NULL);
  assert(result);
  
  //NECDataBlockPrint(data); // Display the data for visual inspection.
  
  assert(data->t1x[23] == 1); // 1
  assert(data->t1y[23] == 0); // 0
  assert(data->t1z[23] == 0); // 0 <- x unit vector
  
  assert(data->t2x[23] == 0); // 0
  assert(data->t2y[23] == 1); // 1
  assert(data->t2z[23] == 0); // 0 <- y unit vector
  
  assert(data->t1x[24] == 1); // 1
  assert(data->t1y[24] == 0); // 0
  assert(data->t1z[24] == 0); // 0 <- x unit vector
  
  assert(data->t2x[24] == 0);  // 0
  assert(data->t2y[24] == -1); // -1
  assert(data->t2z[24] == 0);  // 0 <- -y unit vector
  
  // Triangle patch t-vectors
  assert(fabs(data->t1x[25] - 0.447214) < 1e-6);
  assert(fabs(data->t1y[25] - 0.894427) < 1e-6);
  assert(fabs(data->t1z[25] - 0.000000) < 1e-6);
  assert(fabs(data->t2x[25] + 0.894427) < 1e-6);
  assert(fabs(data->t2y[25] - 0.447214) < 1e-6);
  assert(fabs(data->t2z[25] - 0.000000) < 1e-6);
  
  // Tear down
  /****************************************************************************/
  NECDataBlockDelete(data);
  NECAngleBlockDelete(angl);

}

// Unit tests for move_2
void move_2_test() {
  
  // Setup - create a data block and fill it with segments.
  /****************************************************************************/
  NECDataBlock *data = NECDataBlockMake(1, 1);
  NECAngleBlock *angl = NECAngleBlockMake(1, 1);
  
  // Put in a wire lying parallel to the z axis in the x-z plane.
  int itg = 0, ns = 20;
  double xw1 = 0.25, yw1 = 0.0, zw1 = 0.0;
  double xw2 = 0.25, yw2 = 0.0, zw2 = 1.0;
  double rad = 0.00001, rdel = 1.0, rrad = 1.0;
  wire_2(data, &xw1, &yw1, &zw1, &xw2, &yw2, &zw2, &rad, &rdel, &rrad, &ns, &itg, NULL);
  
  // Put in a plate of patches (5 x 4) sitting in the x,y plane.
  int nx = 5, ny = 4;
  double x1 = 0.0, y1 = 0.0, z1 = 0.0;
  double x2 = .25, y2 = 0.0, z2 = 0.0;
  double x3 = .25, y3 = 0.2, z3 = 0.0;
  double x4 = 0.0, y4 = 0.2, z4 = 0.0;
  patch_2(data, angl, &nx, &ny, &x1, &y1, &z1, &x2, &y2, &z2, &x3, &y3, &z3, &x4, &y4, &z4, NULL);
  
  // Tests
  /****************************************************************************/
  
  int itgi = 1, its = 0, nrpt = 1;
  double rox = M_PI, roy = 0, roz = 0, xs = -0.5, ys = 0, zs = 0;
  bool result = move_2(data, angl, &rox, &roy, &roz, &xs, &ys, &zs, &its, &nrpt, &itgi, NULL);
  
  // Make sure the function completed without errors.
  assert(result);
  
  // visualize the data
  //NECDataBlockPrint(data);
  
  // Check the wire segment data.
  assert(data->z[19] == -data->z[39]);
  assert(data->z[9] == -data->z[29]);
  assert(data->x[19] == data->x[39] - xs);
  assert(data->x[14] == data->x[34] - xs);
  assert(fabs(data->y[19] - data->y[39]) < 1e-10);
  assert(fabs(data->y[14] - data->y[34]) < 1e-10);
  
  // Check the patch data.
  assert(fabs(data->zp[19] - data->zp[39]) < 1e-10);
  assert(fabs(data->zp[9]  - data->zp[29]) < 1e-10);
  assert(fabs(data->x[19] - (data->x[39] - xs)) < 1e-10);
  assert(fabs(data->x[14] - (data->x[34] - xs)) < 1e-10);
  assert(fabs(data->y[19] + (data->y[39] - ys)) < 1e-10);
  assert(fabs(data->y[14] + (data->y[34] - ys)) < 1e-10);
  
  // Tear down
  /****************************************************************************/
  NECDataBlockDelete(data);
  NECAngleBlockDelete(angl);
  
}

// Unit tests for isegno_2
void isegno_2_test() {
  
  // Setup - create a data block and fill it with segments.
  /****************************************************************************/
  NECDataBlock *data = NECDataBlockMake(1, 1);

  int itg = 1, ns = 10;
  double rad = 0.001, rada = 0.25, ang1 = 0.0, ang2 = 90;
  arc_2(data, &itg, &ns, &rada, &ang1, &ang2, &rad, NULL);
  
  itg = 0, ns = 20;
  rad = 0.00001;
  double xw1 = 0.0, yw1 = 0.0, zw1 = 0.0;
  double xw2 = 0.25, yw2 = 0.0, zw2 = 0.0;
  double rdel = 1.0, rrad = 1.0;
  wire_2(data, &xw1, &yw1, &zw1, &xw2, &yw2, &zw2, &rad, &rdel, &rrad, &ns, &itg, NULL);
  
  itg = 2, ns = 10;
  rad = 0.001, rada = 0.3, ang1 = 185.5, ang2 = 220.3;
  arc_2(data, &itg, &ns, &rada, &ang1, &ang2, &rad, NULL);
  
  // Tests
  /****************************************************************************/
  
  assert(isegno_2(data, 0, 5, NULL) == 15);
  assert(isegno_2(data, 1, 4, NULL) == 04);
  assert(isegno_2(data, 2, 3, NULL) == 33);
  
  // Tear down
  /****************************************************************************/
  NECDataBlockDelete(data);
  
}

// Unit tests for reflc_2
void reflc_2_test() {
  
  // Setup - create a data block and fill it with segments.
  /****************************************************************************/
  NECDataBlock *data = NECDataBlockMake(1, 1);
  NECAngleBlock *angl = NECAngleBlockMake(1, 1);
  
  // Put a wire parallel to the z-axis in the x-z plane
  int itg = 0, ns = 20;
  double xw1 = 0.25, yw1 = 0.0, zw1 = 0.0;
  double xw2 = 0.25, yw2 = 0.0, zw2 = 1.0;
  double rad = 0.00001, rdel = 1.0, rrad = 1.0;
  wire_2(data, &xw1, &yw1, &zw1, &xw2, &yw2, &zw2, &rad, &rdel, &rrad, &ns, &itg, NULL);
  
  // Put in a single patch in the x-z plane.
  int nx = 0, ny = 2;
  double x1 = 0.0, y1 = 0.0, z1 = 0.0;
  double x2 = .25, y2 = 0.0, z2 = 0.0;
  double x3 = .25, y3 = 0.0, z3 = 0.2;
  double x4 = 0.0, y4 = 0.0, z4 = 0.2;
  patch_2(data, angl, &nx, &ny, &x1, &y1, &z1, &x2, &y2, &z2, &x3, &y3, &z3, &x4, &y4, &z4, NULL);
  
  // Tests
  /****************************************************************************/
  
  // Reflect in the x-y plane (reflectalong the z-axis)
  int ix = 0, iy = 0, iz = 1, itx = 0, nop = 1;
  bool result = reflc_2(data, angl, &ix, &iy, &iz, &itx, &nop, NULL);
  assert(result);
  
  //NECDataBlockPrint(data); // visualize the data
  
  assert(data->ld >= 2 * ns);
  assert(data->n == 2 * ns);
  assert(data->x[0] == 0.25);
  assert(data->x[19] == xw2);
  assert(data->x[39] == xw2);
  assert(data->y[19] == yw2);
  assert(data->y[39] == yw2);
  assert(fabs(data->z[19] + data->z[39]) < 1e-10);
  assert(fabs(data->z[9]  + data->z[29]) < 1e-10);
  
  // Rotate to form cylindrical structure
  ix = -1, nop = 4;
  result = reflc_2(data, angl, &ix, &iy, &iz, &itx, &nop, NULL);
  assert(result);
  
  //NECDataBlockPrint(data); // visualize the data
  
  // Verify the wire segment data.
  assert(data->ld >= nop * 2 * ns);
  assert(data->n == nop * 2 * ns);
  assert(data->x[4] == xw2);
  assert(data->y[4] == yw2);
  assert(data->z[4] == zw2 / ns * 4);
  assert(data->z[19] == data->z[2 * ns + 19]);
  assert(data->z[19] == data->z[4 * ns + 19]);
  assert(data->z[19] == data->z[6 * ns + 19]);
  assert(data->z[24] == data->z[2 * ns + 24]);
  assert(data->z[24] == data->z[4 * ns + 24]);
  assert(data->z[24] == data->z[6 * ns + 24]);
  assert(fabs(data->x[4]  + data->x[5 * ns + 4])  < 1e-10);
  assert(fabs(data->x[44] + data->x[5 * ns + 44]) < 1e-10);
  assert(fabs(data->x[41] + data->x[5 * ns + 41]) < 1e-10);
  assert(fabs(data->y[4]  + data->y[5 * ns + 4])  < 1e-10);
  assert(fabs(data->y[44] + data->y[5 * ns + 44]) < 1e-10);
  assert(fabs(data->y[41] + data->y[5 * ns + 41]) < 1e-10);
  assert(data->bet[19] == data->bet[2 * ns + 19]);
  assert(data->bet[19] == data->bet[4 * ns + 19]);
  assert(data->bet[19] == data->bet[6 * ns + 19]);
  assert(data->bet[24] == data->bet[2 * ns + 24]);
  assert(data->bet[24] == data->bet[4 * ns + 24]);
  assert(data->bet[24] == data->bet[6 * ns + 24]);
  assert(fabs(data->si[4]  + data->si[5 * ns + 4])  < 1e-10);
  assert(fabs(data->si[44] + data->si[5 * ns + 44]) < 1e-10);
  assert(fabs(data->si[41] + data->si[5 * ns + 41]) < 1e-10);
  assert(fabs(data->alp[4]  + data->alp[5 * ns + 4])  < 1e-10);
  assert(fabs(data->alp[44] + data->alp[5 * ns + 44]) < 1e-10);
  assert(fabs(data->alp[41] + data->alp[5 * ns + 41]) < 1e-10);
  assert(data->bi[19] == data->bi[2 * ns + 19]);
  
  // Verify the patch data.
  assert(data->lp >= nop * 2);
  assert(data->m == nop * 2);
  assert(data->pa[2] == 0.05);
  assert(data->pa[5] == 0.05);
  assert(data->zp[0] == 0.1);
  assert(data->yp[0] == 0.0);
  assert(data->xp[0] == 0.125);
  assert(data->zp[1] == -0.1);
  assert(data->yp[3] == 0.125);
  assert(data->xp[5] == -0.125);
  assert(angl->salp[0] ==  1);
  assert(angl->salp[1] == -1);
  assert(angl->salp[2] ==  1);
  assert(angl->salp[3] == -1);
  
  // Tear down
  /****************************************************************************/
  NECDataBlockDelete(data);
  NECAngleBlockDelete(angl);
  
}

// Unit tests for subph_2
void subph_2_test() {
  
  size_t OUT_OF_SOLUTION_OFFSET = 1e4;
  
  // Setup
  /****************************************************************************/
  
  // Fill the patch data arrays with three patches which will be split.
  
  bool result;
  
  NECDataBlock *data = NECDataBlockMake(1, 1);
  NECAngleBlock *angl = NECAngleBlockMake(1, 1);
  
  // Put in a single patch in the x-z plane.
  int nx = 0, ny = 2;
  double x1 = 0.0, y1 = 0.0, z1 = 0.0;
  double x2 = 1.0, y2 = 0.0, z2 = 0.0;
  double x3 = 1.0, y3 = 0.0, z3 = 1.0;
  double x4 = 0.0, y4 = 0.0, z4 = 1.0;
  result = patch_2(data, angl, &nx, &ny, &x1, &y1, &z1, &x2, &y2, &z2, &x3, &y3, &z3, &x4, &y4, &z4, NULL);
  assert(result);
  
  x1 = 0.0, y1 = 1.0, z1 = 0.0;
  x2 = 1.0, y2 = 1.0, z2 = 0.0;
  x3 = 1.0, y3 = 1.0, z3 = 1.0;
  x4 = 0.0, y4 = 1.0, z4 = 1.0;
  result = patch_2(data, angl, &nx, &ny, &x1, &y1, &z1, &x2, &y2, &z2, &x3, &y3, &z3, &x4, &y4, &z4, NULL);
  assert(result);
  
  x1 = 0.0, y1 = 2.0, z1 = 0.0;
  x2 = 1.0, y2 = 2.0, z2 = 0.0;
  x3 = 1.0, y3 = 2.0, z3 = 1.0;
  x4 = 0.0, y4 = 2.0, z4 = 1.0;
  result = patch_2(data, angl, &nx, &ny, &x1, &y1, &z1, &x2, &y2, &z2, &x3, &y3, &z3, &x4, &y4, &z4, NULL);
  assert(result);
  
  //NECDataBlockPrint(data); // Display the data for visual inspection.

  // Tests
  /****************************************************************************/
  
  // Split the first patch in the array so that it shifts all the other patches
  // up. Make sure the new data is added correctly (replacing the original
  // patch and adding three new ones) and the other patches are shifted.
  size_t p_index = 0; // Fist patch
  int mode = 0; // Split in place
  result = subph_2(data, angl, p_index, mode, NULL);
  assert(result);
  assert(data->m == 6);
  
  // Split the middle patch with the option that the old patch is removed and 4
  // new ones replace it (make sure z component of the old patch is moved way
  // out of the solution space).
  p_index = 5; // Third original patch
  mode = 0; // Split in place
  result = subph_2(data, angl, p_index, mode, NULL);
  assert(result);
  assert(data->m == 9);
  
  // Split the patch at the end and make sure the new patches are added to the
  // end of the data buffers correctly.
  p_index = 4; // Second original patch
  mode = 1; // Add for new patches, leave old patch but move out of simulation.
  result = subph_2(data, angl, p_index, mode, NULL);
  assert(result);
  assert(data->m == 13);
  
  //NECDataBlockPrint(data); // Display the data for visual inspection.
  
  // Check several points throughout the data.
  assert(data->xp[0] == 0.75);
  assert(data->xp[4] == 0.50);
  assert(data->xp[8] == 0.75);
  assert(data->xp[12] == .75);
  assert(data->yp[0] == 0.00);
  assert(data->yp[4] == 1.00);
  assert(data->yp[8] == 2.00);
  assert(data->yp[12] == 1.0);
  assert(data->zp[0] == 0.75);
  assert(data->zp[4] == OUT_OF_SOLUTION_OFFSET);
  assert(data->zp[8] == 0.25);
  assert(data->zp[12] == 0.25);
  assert(data->pa[0] == 0.25);
  assert(data->pa[4] == 1.00);
  assert(data->pa[8] == 0.25);
  assert(data->pa[12] == .25);
  
  // Tear down
  /****************************************************************************/
  NECDataBlockDelete(data);
  NECAngleBlockDelete(angl);
  
}

// Unit tests for connect_2
void connect_2_test() {
  
  // Setup
  /****************************************************************************/
  NECDataBlock *data = NECDataBlockMake(1, 1);
  NECAngleBlock *angl = NECAngleBlockMake(1, 1);
  NECCurrentExpansionBlock *segj = NECCurrentExpansionBlockMake();
  
  // Make an output file struct
  NECOutputFile *out_file = NECOutputFileMake("test_connect_2.txt");
  
  //
  // Add data to buffers:
  //
  
  // Two wires arranged such that segment 1 (index 0) has connections on both
  // ends.
  
  int itg = 4, ns = 2;
  double xw1 = 10.0, yw1 = 0.0, zw1 = 0.0;
  double xw2 = 10.25, yw2 = 0.0, zw2 = 0.0;
  double rad = 0.00001, rdel = 1.0, rrad = 1.0;
  wire_2(data, &xw1, &yw1, &zw1, &xw2, &yw2, &zw2, &rad, &rdel, &rrad, &ns, &itg, NULL);
  
  itg = 5, ns = 2;
  xw1 = 9.75, yw1 = 0.0, zw1 = 0.0;
  xw2 = 10.0, yw2 = 0.0, zw2 = 0.0;
  rad = 0.00001, rdel = 1.0, rrad = 1.0;
  wire_2(data, &xw1, &yw1, &zw1, &xw2, &yw2, &zw2, &rad, &rdel, &rrad, &ns, &itg, NULL);
  
  // Two connecting wires which also connect to a patch at one end and a random
  // patch not connected to anything.
  
  itg = 0, ns = 2;
  xw1 = 0.0, yw1 = 0.0, zw1 = 0.0;
  xw2 = 0.25, yw2 = 0.0, zw2 = 0.0;
  rad = 0.00001, rdel = 1.0, rrad = 1.0;
  wire_2(data, &xw1, &yw1, &zw1, &xw2, &yw2, &zw2, &rad, &rdel, &rrad, &ns, &itg, NULL);
  
  itg = 1, ns = 2;
  xw1 = 0.25, yw1 = 0.0, zw1 = 0.0;
  xw2 = 0.50, yw2 = 0.0, zw2 = 0.0;
  rad = 0.00001, rdel = 1.0, rrad = 1.0;
  wire_2(data, &xw1, &yw1, &zw1, &xw2, &yw2, &zw2, &rad, &rdel, &rrad, &ns, &itg, NULL);
  
  // Shapeless patch...
  int nx = 0, ny = 0 + 1; // ny = ns + 1
  double x1 = 0.0, y1 = 0.0, z1 = 5.0;
  double x2 = 45., y2 = 45., z2 = 0.0625;
  double x3 = 0.0, y3 = 0.0, z3 =  0.0;
  double x4 = 0.0, y4 = 0.0, z4 =  0.0;
  patch_2(data, angl, &nx, &ny, &x1, &y1, &z1, &x2, &y2, &z2, &x3, &y3, &z3, &x4, &y4, &z4, NULL);
  
  nx = 0, ny = 2;
  x1 = 0.0, y1 = -0.2, z1 = -0.2;
  x2 = 0.0, y2 =  0.2, z2 = -0.2;
  x3 = 0.0, y3 =  0.2, z3 =  0.2;
  x4 = 0.0, y4 = -0.2, z4 =  0.2;
  patch_2(data, angl, &nx, &ny, &x1, &y1, &z1, &x2, &y2, &z2, &x3, &y3, &z3, &x4, &y4, &z4, NULL);
  
  // Add 4 wire segments that all connect at one end
  
  itg = 3, ns = 1;
  rad = 0.0001, rdel = 1.0, rrad = 1.0;
  zw1 = 10., zw2 = 10.;
  
  xw1 = 0.0, yw1 = 0.0;
  xw2 = 0.5, yw2 = 0.0;
  wire_2(data, &xw1, &yw1, &zw1, &xw2, &yw2, &zw2, &rad, &rdel, &rrad, &ns, &itg, NULL);
  
  xw1 = 0.0, yw1 = 0.0;
  xw2 = -.5, yw2 = 0.0;
  wire_2(data, &xw1, &yw1, &zw1, &xw2, &yw2, &zw2, &rad, &rdel, &rrad, &ns, &itg, NULL);
  
  xw1 = 0.0, yw1 = 0.0;
  xw2 = 0.0, yw2 = 0.5;
  wire_2(data, &xw1, &yw1, &zw1, &xw2, &yw2, &zw2, &rad, &rdel, &rrad, &ns, &itg, NULL);
  
  xw1 = 0.0, yw1 = 0.0;
  xw2 = 0.0, yw2 = -.5;
  wire_2(data, &xw1, &yw1, &zw1, &xw2, &yw2, &zw2, &rad, &rdel, &rrad, &ns, &itg, NULL);
  
  // Tests
  /****************************************************************************/
  // Run connect_2 and verify the connections were found and any wire-patch
  // connections were handled appropriately (subph_2 used to split the patch).
  
  int ignd = 0;
  bool result = connect_2(data, segj, angl, &ignd, out_file, NULL);
  assert(result);
  
  // Print the data and connections
  //NECDataBlockPrint(data); // Display the data for visual inspection.
  
  // Make sure subph was called (the results of subph are verfied in the subph
  // unit tests.
  assert(data->m == 5);
  
  // Make sure the connection data is set appropriately.
  assert(data->icon1[0] == 4);
  assert(data->icon1[1] == 1);
  assert(data->icon1[2] == NEC_NO_CONNECTION);
  assert(data->icon1[3] == 3);
  assert(data->icon1[4] == NEC_PATCH_OFFSET + 2);
  assert(data->icon1[5] == 5);
  assert(data->icon1[6] == 6);
  assert(data->icon1[7] == 7);
  assert(data->icon1[8] == -10);
  assert(data->icon1[9] == -11);
  assert(data->icon1[10] == -12);
  assert(data->icon1[11] == -9);
  assert(data->icon2[0] == 2);
  assert(data->icon2[1] == NEC_NO_CONNECTION);
  assert(data->icon2[2] == 4);
  assert(data->icon2[3] == 1);
  assert(data->icon2[4] == 6);
  assert(data->icon2[5] == 7);
  assert(data->icon2[6] == 8);
  assert(data->icon2[7] == NEC_NO_CONNECTION);
  assert(data->icon2[8] == NEC_NO_CONNECTION);
  assert(data->icon2[9] == NEC_NO_CONNECTION);
  assert(data->icon2[10] == NEC_NO_CONNECTION);
  assert(data->icon2[11] == NEC_NO_CONNECTION);
  
  // Tear down
  /****************************************************************************/
  NECDataBlockDelete(data);
  NECAngleBlockDelete(angl);
  NECCurrentExpansionBlockDelete(segj);
  
}

// Unit tests for gfil_2
void gfil_2_test() {
  
}

// Unit tests for NECInputFileMake
// Tests reading in an NEC simulation file.
void NECInputFileMake_test() {
  
  // Setup
  /****************************************************************************/
  
  // Define paramters of an actual NEC input file and specify the path.
  char file_name[] = "EX2.nec";
  char card[] = "CMEXAMPLE 2.  CENTER FED LINEAR ANTENNA.\n";
  int num_geometry_cards_in_file = 2;
  int num_control_cards_in_file  = 8;
  int num_comment_cards_in_file  = 4;
  int total_cards = num_geometry_cards_in_file + num_control_cards_in_file +
                    num_comment_cards_in_file;
  
  // Tests
  /****************************************************************************/
  
  // Read the input file.
  NECInputFile *input = NECInputFileMake(file_name);
  
  assert(input != NULL);
  assert(input->geometryCardCount == num_geometry_cards_in_file);
  assert(input->controlCardCount  == num_control_cards_in_file);
  assert(input->commentCardCount  == num_comment_cards_in_file);
  assert(input->cardCount == total_cards);
  assert(strcmp(input->commentCards[0],card) == 0);
  
  // Tear down
  /****************************************************************************/
  NECInputFileDelete(input);
  
}

// Test the output file functions.
void NECOutputFile_test() {
  
  // Make an output file struct
  NECOutputFile *out_file = NECOutputFileMake("test_output_file.txt");
  
  // Result variable
  bool pass;
  
  // Write data to it...
  pass = NECOutputFileWriteLine(out_file, "This is a sample line of data...\n");
  assert(pass);
  
  // Pretend to write a line of wire segment data.
  char buffer[128];
  sprintf(
      buffer,
      " %5i%11.5f%11.5f%11.5f %11.5f%11.5f%11.5f%11.5f  %5i    %5i %5i   %5i",
      4, 0., 0., 0., 0., 0., .25, .02, 2, 1, 2, 1
  );
  pass = NECOutputFileWriteLine(out_file, buffer);
  assert(pass);
  
  // Clean up the object
  NECOutputFileDelete(out_file);
  
}

// Unit tests for datagn_2
// Test datagn_2 with Example 1 (from the NEC2 users manual).
void datagn_2_test_with_example_1() {
  
  // Setup
  /****************************************************************************/

  // Read the input file.
  char file_name[] = "EX1.nec";
  NECInputFile *input = NECInputFileMake(file_name);
  
  // Declare data structures that will contain the geometry data (similar to the
  // FORTRAN common blocks in the original code) as well as facilitate
  // functionality (error handling, saving data, etc.).
  NECDataBlock  *data = NULL;
  NECAngleBlock *angl = NULL;
  NECCurrentExpansionBlock  *segj = NULL;
  NECPlotBlock  *plot = NULL;
  NECError      *error_block = NECErrorMake(false, 0, "No Error");
  NECOutputFile *output_file = NECOutputFileMake("datagn_2_test_EX1.txt");
  
  // Tests
  /****************************************************************************/
  
  datagn_2(input, &data, &angl, &plot, &segj, &output_file, &error_block);
  if (error_block) {
    assert(!error_block->flag);
  }
  
  //NECDataBlockPrint(data); // visualize the data
  
  assert(data->n == 7);
  assert(data->m == 0);
  assert(data->ld >= 7);
  assert(data->lp >= 0);
  assert(data->x[0] == 0);
  assert(data->x[6] == 0);
  assert(data->y[0] == 0);
  assert(data->y[6] == 0);
  assert(fabs(data->z[0] + 0.214286) < 1E-6);
  assert(fabs(data->z[6] - 0.214286) < 1E-6);
  assert(data->icon1[0] == NEC_NO_CONNECTION);
  assert(data->icon1[1] == 1);
  assert(data->icon1[2] == 2);
  assert(data->icon1[3] == 3);
  assert(data->icon2[0] == 2);
  assert(data->icon2[1] == 3);
  assert(data->icon2[2] == 4);
  assert(data->icon2[3] == 5);
  
  // Tear down
  /****************************************************************************/
  NECInputFileDelete(input);
  NECDataBlockDelete(data);
  NECAngleBlockDelete(angl);
  NECCurrentExpansionBlockDelete(segj);
  NECPlotBlockDelete(plot);
  NECErrorDelete(error_block);
  NECOutputFileDelete(output_file);
  
}

// Unit tests for datagn_2
// Test datagn_2 with Example 2 (from the NEC2 users manual).
void datagn_2_test_with_example_2() {
  
  // Setup
  /****************************************************************************/
  
  // Read the input file.
  char file_name[] = "EX2.nec";
  NECInputFile *input = NECInputFileMake(file_name);
  
  // Declare data structures that will contain the geometry data (similar to the
  // FORTRAN common blocks in the original code) as well as facilitate
  // functionality (error handling, saving data, etc.).
  NECDataBlock  *data = NULL;
  NECAngleBlock *angl = NULL;
  NECCurrentExpansionBlock  *segj = NULL;
  NECPlotBlock  *plot = NULL;
  NECError      *error_block = NECErrorMake(false, 0, "No Error");
  NECOutputFile *output_file = NECOutputFileMake("datagn_2_test_EX2.txt");
  
  // Tests
  /****************************************************************************/
  
  datagn_2(input, &data, &angl, &plot, &segj, &output_file, &error_block);
  if (error_block) {
    assert(!error_block->flag);
  }
  
  //NECDataBlockPrint(data); // visualize the data
  
  assert(data->n == 8);
  assert(data->m == 0);
  assert(data->ld >= 8);
  assert(data->lp >= 0);
  assert(data->x[0] == 0);
  assert(data->x[6] == 0);
  assert(data->y[0] == 0);
  assert(data->y[6] == 0);
  assert(fabs(data->z[0] + 0.218750) < 1E-6);
  assert(fabs(data->z[6] - 0.156250) < 1E-6);
  assert(data->icon1[0] == NEC_NO_CONNECTION);
  assert(data->icon1[1] == 1);
  assert(data->icon1[2] == 2);
  assert(data->icon1[3] == 3);
  assert(data->icon2[0] == 2);
  assert(data->icon2[1] == 3);
  assert(data->icon2[2] == 4);
  assert(data->icon2[3] == 5);
  
  // Tear down
  /****************************************************************************/
  NECInputFileDelete(input);
  NECDataBlockDelete(data);
  NECAngleBlockDelete(angl);
  NECCurrentExpansionBlockDelete(segj);
  NECPlotBlockDelete(plot);
  NECErrorDelete(error_block);
  NECOutputFileDelete(output_file);
  
}

// Unit tests for datagn_2
// Test datagn_2 with Example 3 (from the NEC2 users manual).
void datagn_2_test_with_example_3() {
  
  // Setup
  /****************************************************************************/
  
  // Read the input file.
  char file_name[] = "EX3.nec";
  NECInputFile *input = NECInputFileMake(file_name);
  
  // Declare data structures that will contain the geometry data (similar to the
  // FORTRAN common blocks in the original code) as well as facilitate
  // functionality (error handling, saving data, etc.).
  NECDataBlock  *data = NULL;
  NECAngleBlock *angl = NULL;
  NECCurrentExpansionBlock  *segj = NULL;
  NECPlotBlock  *plot = NULL;
  NECError      *error_block = NECErrorMake(false, 0, "No Error");
  NECOutputFile *output_file = NECOutputFileMake("datagn_2_test_EX3.txt");
  
  // Tests
  /****************************************************************************/
  
  datagn_2(input, &data, &angl, &plot, &segj, &output_file, &error_block);
  if (error_block) {
    assert(!error_block->flag);
  }
  
  //NECDataBlockPrint(data); // visualize the data
  
  assert(data->n == 9);
  assert(data->m == 0);
  assert(data->ld >= 9);
  assert(data->lp >= 0);
  assert(data->x[0] == 0);
  assert(data->x[6] == 0);
  assert(data->y[0] == 0);
  assert(data->y[6] == 0);
  assert(fabs(data->z[0] - 2.277778) < 1E-6);
  assert(fabs(data->z[8] - 6.722222) < 1E-6);
  assert(data->icon1[0] == NEC_NO_CONNECTION);
  assert(data->icon1[1] == 1);
  assert(data->icon1[2] == 2);
  assert(data->icon1[3] == 3);
  assert(data->icon2[0] == 2);
  assert(data->icon2[1] == 3);
  assert(data->icon2[2] == 4);
  assert(data->icon2[3] == 5);
  
  // Tear down
  /****************************************************************************/
  NECInputFileDelete(input);
  NECDataBlockDelete(data);
  NECAngleBlockDelete(angl);
  NECCurrentExpansionBlockDelete(segj);
  NECPlotBlockDelete(plot);
  NECErrorDelete(error_block);
  NECOutputFileDelete(output_file);
  
}

// Unit tests for datagn_2
// Test datagn_2 with Example 4 (from the NEC2 users manual).
void datagn_2_test_with_example_4() {
  
  // Setup
  /****************************************************************************/
  
  // Read the input file.
  char file_name[] = "EX4.nec";
  NECInputFile *input = NECInputFileMake(file_name);
  
  // Declare data structures that will contain the geometry data (similar to the
  // FORTRAN common blocks in the original code) as well as facilitate
  // functionality (error handling, saving data, etc.).
  NECDataBlock  *data = NULL;
  NECAngleBlock *angl = NULL;
  NECCurrentExpansionBlock  *segj = NULL;
  NECPlotBlock  *plot = NULL;
  NECError      *error_block = NECErrorMake(false, 0, "No Error");
  NECOutputFile *output_file = NECOutputFileMake("datagn_2_test_EX4.txt");
  
  // Tests
  /****************************************************************************/
  
  datagn_2(input, &data, &angl, &plot, &segj, &output_file, &error_block);
  if (error_block) {
    assert(!error_block->flag);
  }
  
  //NECDataBlockPrint(data); // visualize the data
 
  // Check some of the wire data
  assert(data->n == 8);
  assert(data->ld >= 8);
  assert(data->x[0] == 0.000);
  assert(data->y[0] == 0.000);
  assert(data->z[0] == 0.125);
  assert(fabs(data->si[0] - 0.050000) < 1E-6);
  assert(data->icon1[0] == NEC_PATCH_OFFSET + 9);
  assert(data->icon2[0] == 2);
  assert(data->x[6] == -0.0375);
  assert(data->y[6] ==  0.0000);
  assert(data->z[6] ==  0.3000);
  assert(fabs(data->si[6] - 0.075000) < 1E-6);
  assert(data->icon1[6] == 4);
  assert(data->icon2[6] == 8);
  
  // Check some of the patch data
  assert(data->m == 12);
  assert(data->lp >= 12);
  assert(data->xp[0] ==  0.10);
  assert(data->yp[0] ==  0.05);
  assert(data->zp[0] ==  0.05);
  assert(data->pa[0] ==  0.01);
  assert(data->xp[1] ==  0.05);
  assert(data->yp[1] ==  0.10);
  assert(data->zp[1] ==  0.05);
  assert(data->pa[1] ==  0.01);
  assert(data->xp[2] ==  0.10);
  assert(data->yp[2] == -0.05);
  assert(data->zp[2] ==  0.05);
  assert(data->pa[2] ==  0.01);
  assert(data->xp[3] ==  0.05);
  assert(data->yp[3] == -0.10);
  assert(data->zp[3] ==  0.05);
  assert(data->pa[3] ==  0.01);
  assert(data->xp[4] == -0.10);
  assert(data->yp[4] ==  0.05);
  assert(data->zp[4] ==  0.05);
  assert(data->pa[4] ==  0.01);
  
  // Tear down
  /****************************************************************************/
  NECInputFileDelete(input);
  NECDataBlockDelete(data);
  NECAngleBlockDelete(angl);
  NECCurrentExpansionBlockDelete(segj);
  NECPlotBlockDelete(plot);
  NECErrorDelete(error_block);
  NECOutputFileDelete(output_file);
  
}

// Unit tests for datagn_2
// Test datagn_2 with Example 5 (from the NEC2 users manual).
void datagn_2_test_with_example_5() {
  
  // Setup
  /****************************************************************************/
  
  // Read the input file.
  char file_name[] = "EX5.nec";
  NECInputFile *input = NECInputFileMake(file_name);
  
  // Declare data structures that will contain the geometry data (similar to the
  // FORTRAN common blocks in the original code) as well as facilitate
  // functionality (error handling, saving data, etc.).
  NECDataBlock  *data = NULL;
  NECAngleBlock *angl = NULL;
  NECCurrentExpansionBlock  *segj = NULL;
  NECPlotBlock  *plot = NULL;
  NECError      *error_block = NECErrorMake(false, 0, "No Error");
  NECOutputFile *output_file = NECOutputFileMake("datagn_2_test_EX5.txt");
  
  // Tests
  /****************************************************************************/
  
  datagn_2(input, &data, &angl, &plot, &segj, &output_file, &error_block);
  if (error_block) {
    assert(!error_block->flag);
  }
  
  //NECDataBlockPrint(data); // visualize the data
  
  assert(data->n == 78);
  assert(data->m == 0);
  // This example only has GW cards - this functionality is thoroughly tested
  // by other unit tests.
  
  // Tear down
  /****************************************************************************/
  NECInputFileDelete(input);
  NECDataBlockDelete(data);
  NECAngleBlockDelete(angl);
  NECCurrentExpansionBlockDelete(segj);
  NECPlotBlockDelete(plot);
  NECErrorDelete(error_block);
  NECOutputFileDelete(output_file);
  
}

// Unit tests for datagn_2
// Test datagn_2 with Example 6 (from the NEC2 users manual).
void datagn_2_test_with_example_6() {
  
  // Setup
  /****************************************************************************/
  
  // Read the input file.
  char file_name[] = "EX6.nec";
  NECInputFile *input = NECInputFileMake(file_name);
  
  // Declare data structures that will contain the geometry data (similar to the
  // FORTRAN common blocks in the original code) as well as facilitate
  // functionality (error handling, saving data, etc.).
  NECDataBlock  *data = NULL;
  NECAngleBlock *angl = NULL;
  NECCurrentExpansionBlock  *segj = NULL;
  NECPlotBlock  *plot = NULL;
  NECError      *error_block = NECErrorMake(false, 0, "No Error");
  NECOutputFile *output_file = NECOutputFileMake("datagn_2_test_EX6.txt");
  
  // Tests
  /****************************************************************************/
  
  datagn_2(input, &data, &angl, &plot, &segj, &output_file, &error_block);
  if (error_block) {
    assert(!error_block->flag);
  }
  
  //NECDataBlockPrint(data); // visualize the data
  
  // Check some of the geometrical data
  assert(data->n == 9);
  assert(data->m == 56);
  assert(fabs(data->pa[0] - 38.40*0.01*0.01) < 1E-6); // Did GS work?
  assert(fabs(data->pa[9] - 44.89*0.01*0.01) < 1E-6);
  assert(fabs(data->xp[6] - data->xp[0]*cos(M_PI/6)) < 1E-6); // Did GM work?
  assert(fabs(data->yp[8] - data->xp[0]*sin(M_PI/6)) < 1E-6);
  assert(fabs(data->zp[6] - data->zp[0]) < 1E-6);
  assert(fabs(data->xp[8] + data->xp[32]) < 1E-6); // Did GR work?
  assert(fabs(data->yp[8] + data->yp[32]) < 1E-6);
  assert(fabs(data->zp[8] - data->zp[32]) < 1E-6);
  //printf("%f %f %f",data->xp[8],data->yp[8],data->zp[8]);
  //printf("%f %f %f",data->xp[32],data->yp[32],data->zp[32]);
  
  // Tear down
  /****************************************************************************/
  NECInputFileDelete(input);
  NECDataBlockDelete(data);
  NECAngleBlockDelete(angl);
  NECCurrentExpansionBlockDelete(segj);
  NECPlotBlockDelete(plot);
  NECErrorDelete(error_block);
  NECOutputFileDelete(output_file);
  
}

// Unit tests for datagn_2
// Test datagn_2 with Example 7 (from the NEC2 users manual).
void datagn_2_test_with_example_7() {
  
  // Setup
  /****************************************************************************/
  
  // Read the input file.
  char file_name[] = "EX7.nec";
  NECInputFile *input = NECInputFileMake(file_name);
  
  // Declare data structures that will contain the geometry data (similar to the
  // FORTRAN common blocks in the original code) as well as facilitate
  // functionality (error handling, saving data, etc.).
  NECDataBlock  *data = NULL;
  NECAngleBlock *angl = NULL;
  NECCurrentExpansionBlock  *segj = NULL;
  NECPlotBlock  *plot = NULL;
  NECError      *error_block = NECErrorMake(false, 0, "No Error");
  NECOutputFile *output_file = NECOutputFileMake("datagn_2_test_EX7.txt");
  
  // Tests
  /****************************************************************************/
  
  datagn_2(input, &data, &angl, &plot, &segj, &output_file, &error_block);
  if (error_block) {
    assert(!error_block->flag);
  }
  
  //NECDataBlockPrint(data); // visualize the data
  
  assert(data->n == 29);
  assert(data->m == 0);
  // This example only has GW cards - this functionality is thoroughly tested
  // by other unit tests.
  
  // Tear down
  /****************************************************************************/
  NECInputFileDelete(input);
  NECDataBlockDelete(data);
  NECAngleBlockDelete(angl);
  NECCurrentExpansionBlockDelete(segj);
  NECPlotBlockDelete(plot);
  NECErrorDelete(error_block);
  NECOutputFileDelete(output_file);
  
}
