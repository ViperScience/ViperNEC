//
//  patch_2.c
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

#include "blocks.h"
#include "error.h"

#include <math.h>

// I don't really like the #define's here but it made the code easier to
// update (less mundane copy paste of "data->" everywhere).
#define x (data->xp)
#define y (data->yp)
#define z (data->zp)
#define t1x (data->t1x)
#define t1y (data->t1y)
#define t1z (data->t1z)
#define t2x (data->t2x)
#define t2y (data->t2y)
#define t2z (data->t2z)
#define bi (data->pa)
#define n (data->n)
#define np (data->np)
#define m (data->m)
#define mp (data->mp)
#define ipsym (data->ipsym)
#define salp (angl->salp)

#define COS_1_DEG 0.9998f /* cosd(1.0) in test for planar patch */

/**
 * patch_2
 * This function inserts patch data into the patch geometry buffers.
 * This function (patch_2) is a cleaned up version of the function generated
 * by f2c (patch_) with some modifications. The main modification is the
 * removal of global data structures containing all the buffers to hold the 
 * geometry data. Instead, the data object (pointer) is passed as an input to 
 * the function. Additionally, in the original FORTRAN code this was a single
 * subroutine with multiple entry points (PATCH and SUBPH). These entry points
 * have been made into two separate functions residing in separate files.
 *
 * Original Documentation:
 * The code from PA14 to PA129 genrerates data for a single new patch or
 * multiple patches. There are four options for defining a single patch, as
 * illustrated in Figure 5 of Part III. For a single patch, NX is zero and NY is
 * NS + 1 where NS is the parameter from the SP input card and is shown on
 * Figure 5. Rectangular, triangular or quadrilateral patches are defined by the
 * coordinates of three or four corners in the parameters X1 though Z4. In the
 * arbitrary shape option (Figure 5A in Part III) the center of the patch is X1,
 * Y1, Z1; alpha is X2; A is Y24 and the area is Z2, The patch data is stored in
 * COMMON/DATA/ from the top of the arrays downward (see Section III).
 *
 * @param data NECDataBlock in which the parsed geometry data is stored. This
 *             must not be NULL. The function will not execute if |data| is 
 *             NULL (return an error).
 * @param angl NECAngleBlock in which is stored angle geometry information for 
 *             wires and patches (must not be NULL).
 * @param nx Zero for a single patch. For multiple patches nx is defined in
 *           Figure 6 of Part 111.
 * @param ny For a single patch, ny is ns + 1 where ns is the parameter from 
 *           the SP input card and is shown on Figure 5 of the original NEC
 *           documentation. For multiple patches ny is defined in Figure 6 of 
 *           Part 111.
 * @param x1 Coordinate of the first patch corner on the x-axis.
 * @param y1 Coordinate of the first patch corner on the y-axis.
 * @param z1 Coordinate of the first patch corner on the z-axis.
 * @param x2 Coordinate of the second patch corner on the x-axis.
 * @param y2 Coordinate of the second patch corner on the y-axis.
 * @param z2 Coordinate of the second patch corner on the z-axis.
 * @param x3 Coordinate of the third patch corner on the x-axis.
 * @param y3 Coordinate of the third patch corner on the y-axis.
 * @param z3 Coordinate of the third patch corner on the z-axis.
 * @param x4 Coordinate of the fourth patch corner on the x-axis.
 * @param y4 Coordinate of the fourth patch corner on the y-axis.
 * @param z4 Coordinate of the fourth patch corner on the z-axis.
 * @return Returns TRUE if completed successfully.
 * @since v1.0
 */
bool patch_2(NECDataBlock *data, NECAngleBlock *angl, int *nx, int *ny,
             double *x1, double *y1, double *z1, double *x2,
             double *y2, double *z2, double *x3, double *y3,
             double *z3, double *x4, double *y4, double *z4,
             NECError **error_block) {
  
  // Check the inputs.
  if (!data || !angl) {
    if (error_block) { *error_block = NECErrorMakeInvalidInput(); }
    return false;
  }
  
  // XNV, YNV, ZNV = unit vector normal to the patch
  double xnv, ynv, znv;
  
  // XA = |S1 X S2| = area of rectangle or twice area of triangle.
  double xa;
  
  // S1X, S1Y, S1Z a vector from corner 1 to corner 2
  double s1x = 0.0, s1y = 0.0, s1z = 0.0;
  
  // S2X, S2Y, S2Z a vector from corner 2 to corner 3
  double s2x = 0.0, s2y = 0.0, s2z = 0.0;
  
  // |S1 X S2|
  double xst;
  
  // XN2, YN2, ZN2 = S3 X S4. Later the code checks that the four corners are
  // coplanar by the test:
  // (S1 X S2).(S3 X S4)/|S1 X S2||S3 X S4| > .9998
  double xn2, yn2, zn2;
  
  // XS, YS, ZS = patch center
  double xs, ys, zs;
  
  ++m; // Increment patch count.
  size_t m_index = m - 1; // -1 since m has been incremented already.
  
  // Since the patch data is now stored in a separate buffer the index
  // should be the next spot in the buffer. Make sure the buffer is the
  // correct size!
  // Make sure the buffers are big enough.
  if (NECDataBlockEnlargePatchBuffers(data, m) == false) {
    if (error_block) { *error_block = NECErrorMakeOutOfMemeory(); }
    return false;
  }
  if(NECAngleBlockEnlargePatchBuffer(angl, m) == false) {
    if (error_block) { *error_block = NECErrorMakeOutOfMemeory(); }
    return false; // Out of memory
  }
  
  // Patch type (NY for a single patch):
  // 1 - arbitrary shape, 2 - rectangular, 3 - triangular, 4 - quadrilateral
  int ntp = *ny;
  
  if (*nx > 0) { ntp = 2; } // If nx > 0 must be rectangular section
  
  if (ntp <= 1) { // If the patch is of arbitrary shape
    x[m_index] = *x1;
    y[m_index] = *y1;
    z[m_index] = *z1;
    bi[m_index] = *z2;
    
    xnv = cos(*x2) * cos(*y2);
    ynv = cos(*x2) * sin(*y2);
    znv = sin(*x2);
    
    xa = sqrt(xnv * xnv + ynv * ynv);
    
    if (xa < 1e-6) { // ~zero area (point)
      t1x[m_index] = 1.f;
      t1y[m_index] = 0.f;
      t1z[m_index] = 0.f;
    } else {
      t1x[m_index] = -ynv / xa;
      t1y[m_index] = xnv / xa;
      t1z[m_index] = 0.f;
    }
  } else { // Patch is rect, tri, or quad shape.

    s1x = *x2 - *x1;
    s1y = *y2 - *y1;
    s1z = *z2 - *z1;
    s2x = *x3 - *x2;
    s2y = *y3 - *y2;
    s2z = *z3 - *z2;
    
    if (*nx != 0) {
      s1x /= *nx;
      s1y /= *nx;
      s1z /= *nx;
      s2x /= *ny;
      s2y /= *ny;
      s2z /= *ny;
    }
    
    xnv = s1y * s2z - s1z * s2y;
    ynv = s1z * s2x - s1x * s2z;
    znv = s1x * s2y - s1y * s2x;
    xa = sqrt(xnv * xnv + ynv * ynv + znv * znv);
    xnv /= xa;
    ynv /= xa;
    znv /= xa;
    xst = sqrt(s1x * s1x + s1y * s1y + s1z * s1z);
    
    t1x[m_index] = s1x / xst;
    t1y[m_index] = s1y / xst;
    t1z[m_index] = s1z / xst;
    
    if (ntp > 2) { // triangular or quadrilateral
      if (ntp == 4) { // quadrilateral
        s1x = *x3 - *x1;
        s1y = *y3 - *y1;
        s1z = *z3 - *z1;
        s2x = *x4 - *x1;
        s2y = *y4 - *y1;
        s2z = *z4 - *z1;
        xn2 = s1y * s2z - s1z * s2y;
        yn2 = s1z * s2x - s1x * s2z;
        zn2 = s1x * s2y - s1y * s2x;
        xst = sqrt(xn2 * xn2 + yn2 * yn2 + zn2 * zn2);
        
        // factor in computing center of mass of quadrilateral
        double salpn = 1.f / ((xa + xst) * 3.f);
        
        x[m_index] = (xa * (*x1 + *x2 + *x3) + xst * (*x1 + *x3 + *x4)) * salpn;
        y[m_index] = (xa * (*y1 + *y2 + *y3) + xst * (*y1 + *y3 + *y4)) * salpn;
        z[m_index] = (xa * (*z1 + *z2 + *z3) + xst * (*z1 + *z3 + *z4)) * salpn;
        bi[m_index] = (xa + xst) * .5f;
        
        // All corners of quadrilateral patch must lie in a plane.
        s1x = (xnv * xn2 + ynv * yn2 + znv * zn2) / xst;
        if (s1x <= COS_1_DEG) {
          if (error_block) { *error_block = NECErrorMake008(); }
          return false;
        }
        
      } else { // triangular
        x[m_index] = (*x1 + *x2 + *x3) / 3.f;
        y[m_index] = (*y1 + *y2 + *y3) / 3.f;
        z[m_index] = (*z1 + *z2 + *z3) / 3.f;
        bi[m_index] = xa * .5f;
      }
    } else { // rectangluar
      x[m_index] = *x1 + (s1x + s2x) * .5f;
      y[m_index] = *y1 + (s1y + s2y) * .5f;
      z[m_index] = *z1 + (s1z + s2z) * .5f;
      bi[m_index] = xa;
    }
    
  }
  
  t2x[m_index] = ynv * t1z[m_index] - znv * t1y[m_index];
  t2y[m_index] = znv * t1x[m_index] - xnv * t1z[m_index];
  t2z[m_index] = xnv * t1y[m_index] - ynv * t1x[m_index];
  salp[m_index] = 1.f;
  
  if (*nx == 0) { // Single patch
    ipsym = 0;
    np = n;
    mp = m;
  } else { // Multi-patch surface
    
    m = m + *nx * *ny - 1; // -1 since m has already been incremented once.
    
    // Make sure the buffers are big enough.
    if (NECDataBlockEnlargePatchBuffers(data, m) == false) {
      if (error_block) { *error_block = NECErrorMakeOutOfMemeory(); }
      return false;
    }
    if(NECAngleBlockEnlargePatchBuffer(angl, m) == false) {
      if (error_block) { *error_block = NECErrorMakeOutOfMemeory(); }
      return false; // Out of memory
    }
    
    xn2 = x[m_index] - s1x - s2x;
    yn2 = y[m_index] - s1y - s2y;
    zn2 = z[m_index] - s1z - s2z;
    xs = t1x[m_index];
    ys = t1y[m_index];
    zs = t1z[m_index];
    double xt = t2x[m_index];
    double yt = t2y[m_index];
    double zt = t2z[m_index];
    
    --m_index; // Go back to start incrementing from the begining.
    
    // Add all the patches from the grid multipatch surface.
    for (int iy = 0; iy < *ny; ++iy) {
      xn2 += s2x;
      yn2 += s2y;
      zn2 += s2z;
      for (int ix = 1; ix <= *nx; ++ix) {
        xst = (double) ix;
        ++m_index;
        x[m_index] = xn2 + xst * s1x;
        y[m_index] = yn2 + xst * s1y;
        z[m_index] = zn2 + xst * s1z;
        bi[m_index] = xa;
        salp[m_index] = 1.f;
        t1x[m_index] = xs;
        t1y[m_index] = ys;
        t1z[m_index] = zs;
        t2x[m_index] = xt;
        t2y[m_index] = yt;
        t2z[m_index] = zt;
      }
    }
    
  }
  
  return true;
}

#undef x
#undef y
#undef z
#undef bi
#undef ld
#undef n
#undef np
#undef m
#undef mp
#undef ipsym
#undef salp
#undef t2z
#undef t2y
#undef t2x
#undef t1z
#undef t1y
#undef t1x
