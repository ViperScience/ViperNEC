//
//  connect_2.c
//  ViperNEC
//
//  Created by Dylan Crocker on 7/24/14.
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

#include "geometry.h"
#include "blocks.h"
#include "error.h"
#include "const.h"
#include "macro.h"
#include "io.h"

#include <math.h>

#define data_1 (*data)
#define x (data_1.x)
#define y (data_1.y)
#define z (data_1.z)
#define icon1 (data_1.icon1)
#define icon2 (data_1.icon2)
#define iconx (data_1.iconx)
#define ld (data_1.ld)
#define n1 (data_1.n1)
#define n2 (data_1.n2)
#define n (data_1.n)
#define np (data_1.np)
#define m1 (data_1.m1)
#define m2 (data_1.m2)
#define m (data_1.m)
#define mp (data_1.mp)
#define ipsym (data_1.ipsym)
#define x2 data->si  /* Equivalenced */
#define y2 data->alp /* Equivalenced */
#define z2 data->bet /* Equivalenced */
#define segj_1 (*segj)
#define jco (segj_1.jco)
#define iscon (segj_1.iscon)
#define nscon (segj_1.nscon)
#define ipcon (segj_1.ipcon)
#define npcon (segj_1.npcon)

/**
 * While searching for connections there are three modes (or paths) the
 * algorithm uses:
 * 1. Search for connection to wire (no gnd or wire end not touching/in the gnd)
 * 2. There is a gnd and a wire is in it! ERROR
 * 3. There is a gnd and the wire is touching it (connection)
 * This enum is used to indicate the apropriate mode so the corect code branch
 * will be taken.
 */
enum CONNECT_MODE {
  CONNECT_MODE_SEARCH,
  CONNECT_MODE_ERROR,
  CONNECT_MODE_GND
};

/**
 *  This function (connect_2) is a cleaned up version of the function generated
 *  by f2c (connect_) with some modifications. The main modification is the
 *  removal of global data structures containing all the buffers to hold the
 *  geometry data. Instead, the data objects (pointers) are passed as an input
 *  to the function.
 *
 *  The data buffer object contains a buffer to hold connection data for all
 *  wire segments. This buffer is already sized to hold connection data for all
 *  existing segments as it gets sized along with the wire data buffers as they
 *  are filled by other functions.
 *
 *  The connection values stored in data->icon1 (and data->icon2) represent the
 *  segment numbers to which connections exist. Note: these are segment numbers
 *  (start at 1) and not segment indices (starts at 0). Also, the values have 
 *  been modified slightly as follow: 
 *      1. The value for no connection is NEC_NO_CONNECTION which is defined in 
 *         nec2vs_constants.h.
 *      2. The offset for patch connection numbers has been changed from 10000 
 *         to NEC_PATCH_OFFSET which is also defined in nec2vs_constants.h.
 *
 * Original FORTRAN documentation:
 *     CONNECT SETS UP SEGMENT CONNECTION DATA IN ARRAYS ICON1 AND ICON2
 *     BY SEARCHING FOR SEGMENT ENDS THAT ARE IN CONTACT.
 *
 * Original NEC Documentation:
 *
 * PURPOSE
 *     To locate segment ends that contact each other or contact the center of
 * a surface patch.
 *
 * METHOD
 *     The ends of each segment are identified as end 1 and end 2, defined
 * during geometry input. The connection data for segment I is stored in array
 * variables ICON1(I) for end 1 and ICON2(1) for end 2.
 *     Four conditions are possible at each segment end: (1) no connection (a 
 * free end), (2) connection to one or more other segments, (3) connection to a
 * ground plane, or (4) connection to a surface modeled with patches. These
 * conditions are indicated in the following way for end 1 of segment I:
 *     (1) noconnection. . . . . . . . . . . . . . . ICON1(I) = 0
 *     (2) connection to segment J . . . . . . . . . ICON1(I) = +-J
 *     (3) connection to a ground plane. . . . . . . ICON1(I) = I
 *     (4) connection to patch K . . . . . . . . . . ICON1(I) = 10000 + k
 * In case 2 , if segment J has the same reference direction as segment I (end 2
 * of segment J connected to end 1 of segment I) , the sign is positive. For
 * opposed reference directions (end 1 to end 1) the sign is negative. If 
 * several segments connect to end 1 of segment I, then J is the number of the 
 * next connected segment in sequence.
 *     If segment I connects to patch K, the segment end must coincide with the
 * patch center. Patch K is then divided into four patches numbered K through
 * K + 3 by a call to subroutine SUBPH.
 *     The connection data is illustrated in the following listing for the six
 * segments in the structure in figure 3 (see the original documentation for 
 * this figure).
 *     Connections between patches are not checked, since, except where a wire
 * connects to a surface, the current expansion function on a patch does not
 * extend beyond that patch.
 *
 * @param data NECDataBlock in which the parsed geometry data is stored. This
 *             must not be NULL. The function will not execute if |data| is 
 *             NULL.
 * @param segj
 * @param angl NECAngleBlock in which is stored angle geometry information for
 *             wires and patches (must not be NULL).
 * @param ignd Ground plane flag and directive: 1 to adjust symmetry for ground 
 *             and set ICON (I) = I; —1 to adjust symmetry only; 0 for no ground
 * @param error
 * @since v1.0
 */
bool connect_2(NECDataBlock *data, NECCurrentExpansionBlock *segj,
               NECAngleBlock *angl, int *ignd, NECOutputFile *outfile,
               NECError **error) {
  
  // Input verification
  if ((data == NULL) || (angl == NULL) || (segj == NULL) || (outfile == NULL)) {
    if (error) { *error = NECErrorMakeInvalidInput(); }
    return false;
  }
  
  // Maximum separation as a fraction of segment length.
  double smin = .001;
  
  nscon = 0;
  npcon = 0;
  
  // If the ground plane flag is set, adjust the symmetry flag and the number of
  // elements in symetric cells.
  if (*ignd != 0) {
    NECOutputFileWriteGroundSpec(outfile, *ignd);
    
    if (ipsym == 2) {
      // If plane symmetry (ipsym = 2), double the number of segments and
      // patches in a symmetric cell.
      np *= 2;
      mp *= 2;
    } else if (abs(ipsym) > 2) {
      // If there is a ground plane (ignd != 0) and a horizontal rotation
      // (|ipsym| > 2), remove all symmetry.
      np = n;
      mp = m;
    }
    
    // If there are more segments and patches in symmetric than the total number
    // of segments and patches, something went wrong so return an error.
    if (np > n) {
      *error = NECErrorMake(true, UnknownError, "DATA ERROR");
      return false;
    }
    
    // If the number of segments in patches in symetric cells are the same as
    // the total number of segments and patches respectively, clear the symmetry
    // flag.
    if (np == n && mp == m) { ipsym = 0; }
  }
  
  //////////////////////////////////////////////////////////////////////////////
  // Search for wire-wire connections.
  // Original Documentation:
  // Check other segments from I + 1 through N and then 1 through I - 1, until a
  // connected end is found. The separation of segment ends is determined by the
  // sum of the separations in x, y, and z to save time.
  //////////////////////////////////////////////////////////////////////////////
  
  // Only search through the wire segments for connections if the buffers
  // actually contain wire segment data.
  if (n > 0) {
    
    // This flag is used to indicate when a connection has been found.
    bool connection_found = false;
    
    // Start - Loop through all the wire segments looking for a connection to
    // another wire segment.
    for (size_t is = 0; is < n; ++is) {
      
      iconx[is] = 0;
      double xi1 = x[is];
      double yi1 = y[is];
      double zi1 = z[is];
      double xi2 = x2[is];
      double yi2 = y2[is];
      double zi2 = z2[is];
      
      // Calculate the maximum separation distance to still be considered a
      // connection (related to segment length).
      double slen =
        sqrt(pow(xi2 - xi1, 2) + pow(yi2 - yi1, 2) + pow(zi2 - zi1, 2)) * smin;
      
      //////////////////////////////////////////////////////////////////////////
      // Determine the connection data for the first end of the segment.
      //////////////////////////////////////////////////////////////////////////
      
      char search_mode = CONNECT_MODE_SEARCH;
      
      // If there is a gnd plane we must do a couple more checks...
      if (*ignd > 0) {
        // Make sure the wire is not in the ground. Remember, gnd is at z = 0.
        if (zi1 <= -slen) {
          search_mode = CONNECT_MODE_ERROR;
        }
        // Is the end connected to the ground? If so set the connection data and
        // move to the other end of the segment. Remember, gnd is at z = 0.
        else if (zi1 <= slen) {
          search_mode = CONNECT_MODE_GND;
        }
      }
      
      // Operate based on the determined mode...
      switch (search_mode) {
        case CONNECT_MODE_GND: {
          icon1[is] = IDX_TO_NUM(is);
          z[is] = 0.f;
          break;
        }
        case CONNECT_MODE_ERROR: {
          // Error - the wire extends below the ground.
          *error = NECErrorMake021(IDX_TO_NUM(is));
          return false;
        }
        case CONNECT_MODE_SEARCH:
        default: {
          
          connection_found = false; // Clear the flag.
          long ic = is;
          for (size_t j = 1; j < n; ++j) {
            ++ic; // Start with the segment after the one in question.
            if (ic >= n) { ic = 0; } // Start at the begining.
            
            // Calculate the separation between the two first ends of the
            // segments.
            double sep = fabs(xi1 - x[ic]) + fabs(yi1 - y[ic]) + fabs(zi1 - z[ic]);
            
            // Is there a connection?
            if (sep <= slen) {
              icon1[is] = -IDX_TO_NUM(ic);
              connection_found = true; // use this below
              break; // break for-loop
            }
            
            // Calculate the separation between the first end of the segment in
            // question and the second end of the other segment.
            sep = fabs(xi1 - x2[ic]) + fabs(yi1 - y2[ic]) + fabs(zi1 - z2[ic]);
            
            // Is there a connection?
            if (sep <= slen) {
              icon1[is] = IDX_TO_NUM(ic);
              connection_found = true; // use this below
              break; // break for-loop
            }
            
          } // end for-loop
          
          // If no connection was found, ensure the array element is set to
          // zero, unless the segment is from the NGF and is already set to
          // connect to a patch.
          if (!connection_found) {
            if (!(is < n1 && icon1[is] > NEC_PATCH_OFFSET)) {
              icon1[is] = NEC_NO_CONNECTION;
            }
          }
          
          break; // break out of switch case
        } // end default case
      } // end switch
      
      //////////////////////////////////////////////////////////////////////////
      // Determine the connection data for the second end of the segment.
      //////////////////////////////////////////////////////////////////////////
      
      search_mode = CONNECT_MODE_SEARCH;
      
      // If there is a gnd plane we must do a couple more checks...
      if (*ignd > 0) {
        // Make sure the wire is not in the ground. Remember, gnd is at z = 0.
        if (zi2 <= -slen) {
          search_mode = CONNECT_MODE_ERROR;
        }
        // Is the end connected to the ground? If so make sure the other end is
        // not and then set the connection data. Remember, gnd is at z = 0.
        else if (zi2 <= slen) {
          if (icon1[is] != IDX_TO_NUM(is)) {
            search_mode = CONNECT_MODE_GND;
          } else {
            search_mode = CONNECT_MODE_ERROR;
          }
        }
      }
      
      // Operate based on the determined mode...
      switch (search_mode) {
        case CONNECT_MODE_GND: {
          icon2[is] = IDX_TO_NUM(is);
          z2[is] = 0.f;
        }
        case CONNECT_MODE_ERROR: {
          if (icon1[is] != IDX_TO_NUM(is)) {
            // Error - the wire extends below the ground.
            *error = NECErrorMake021(is);
          } else {
            // Error - the wire lies in the ground.
            *error = NECErrorMake022(is);
          }
          return false;
        }
        case CONNECT_MODE_SEARCH:
        default: {
          
          connection_found = false; // Clear the flag.
          long ic = is;
          for (size_t j = 1; j < n; ++j) {
            ++ic; // Start with the segment after the one in question.
            if (ic >= n) { ic = 0; } // Or wrap around to start at the begining.
            
            // Calculate the distance between the second end of the segment in
            // question and the first end of the segment being checked for a
            // connection.
            double sep = fabs(xi2 - x[ic]) + fabs(yi2 - y[ic]) + fabs(zi2 - z[ic]);
            
            // Is there a connection?
            if (sep <= slen) {
              icon2[is] = IDX_TO_NUM(ic);
              connection_found = true; // use this below
              break; // break for-loop
            }
            
            // Calculate the distance between the second end of the segment in
            // question and the second end of the segment being checked for a
            // connection.
            sep = fabs(xi2 - x2[ic]) + fabs(yi2 - y2[ic]) + fabs(zi2 - z2[ic]);
            
            // Is there a connection?
            if (sep <= slen) {
              icon2[is] = -IDX_TO_NUM(ic);
              connection_found = true; // use this below
              break; // break for-loop
            }
          }
          
          // If no connection was found, ensure the array element is set to
          // zero, unless the segment is from the NGF and is already set to
          // connect to a patch.
          if (!connection_found) {
            if (!(is < n1 && icon2[is] >= NEC_PATCH_OFFSET)) {
              icon2[is] = NEC_NO_CONNECTION;
            }
          }
          
          break; // break out of switch case
        } // end default case
      } // end switch
    } // Stop - Done looping through the wire segments looking for connections
  }
  
  //////////////////////////////////////////////////////////////////////////////
  // Search for wire-patch connections.
  //////////////////////////////////////////////////////////////////////////////
  
  // Only search through the surface patches for connections if the buffers
  // actually contain surface patch data. It seems as though this search could
  // be combined with the one above to improve efficiency...
  if (m > 0) {
    
    ////////////////////////////////////////////////////////////////////////////
    // Find wire-surface connections for new patches.
    // Original Documentation (OD):
    // Search for segments connected to patches. Only new patches (not NGF) are
    // checked. If a connection is found the patch is divided into four patches
    // at its present location in the data arrays and patches following it are
    // shifted up by three locations. This is done by calling SUBPH, an entry
    // point of subroutine PATCH.
    ////////////////////////////////////////////////////////////////////////////
    for (size_t ip = m1; ip < m; ++ip) {
      
      // Get patch data
      double xs = data->xp[ip];
      double ys = data->yp[ip];
      double zs = data->zp[ip];
      
      // Search through segments looking for a connection to the patch.
      for (size_t is = 0; is < n; ++is) {
        
        // Get segment start location.
        double xi1 = x[is];
        double yi1 = y[is];
        double zi1 = z[is];
        
        // Get segment end location.
        double xi2 = x2[is];
        double yi2 = y2[is];
        double zi2 = z2[is];
        
        // Calculate the maximum separation for a connection.
        double slen = (fabs(xi2 - xi1) + fabs(yi2 - yi1) + fabs(zi2 - zi1)) * smin;
        
        // Calculate the separation between the segment (start and end) and the
        // patch.
        double sep_str = fabs(xi1 - xs) + fabs(yi1 - ys) + fabs(zi1 - zs);
        double sep_end = fabs(xi2 - xs) + fabs(yi2 - ys) + fabs(zi2 - zs);
        
        // If the separation is within the minimum distance there is a connection.
        if ((sep_str <= slen) || (sep_end <= slen)) {
          if (sep_str <= slen) {
            icon1[is] = IDX_TO_NUM(ip) + NEC_PATCH_OFFSET;
          }
          else {
            icon2[is] = IDX_TO_NUM(ip) + NEC_PATCH_OFFSET;
          }
          // Connection - Divide patch into 4 patches at present array loc.
          if (!subph_2(data, angl, ip, 0, error)) {
            return false;
          }
          break; // Stop search.
        }
      } // end segment loop
    } // end patch loop
    
    ////////////////////////////////////////////////////////////////////////////
    // Repeat search for new segments connected to NGF patches.
    // Original Documentation (OD):
    // Search for new segments connected to NGF patches. If a connection is
    // found four patches, covering the area of the original patch, are added to
    // the end of data arrays by calling SUBPH. The original patch retains its
    // location but the z coordinate at its center is changed to 10000.
    ////////////////////////////////////////////////////////////////////////////
    
    // Only conduct this search if both:
    // 1. Patch data exists in the NGF file (m1 > 0).
    // and 2. new segments have been added (n > n1).
    if (m1 > 0 && n > n1) {
      
      // Search through NGF patchs for connections to new segments.
      for (size_t ip = 0; ip < m1; ++ip) {
        
        // Get patch data
        double xs = data->xp[ip];
        double ys = data->yp[ip];
        double zs = data->zp[ip];
        
        // Search through new segments looking for a connection to the patch.
        for (size_t is = n1; is < n; ++is) {
          
          double xi1 = x[is];
          double yi1 = y[is];
          double zi1 = z[is];
          double xi2 = x2[is];
          double yi2 = y2[is];
          double zi2 = z2[is];
          
          double slen =
              (fabs(xi2 - xi1) + fabs(yi2 - yi1) + fabs(zi2 - zi1)) * smin;
          double sep = fabs(xi1 - xs) + fabs(yi1 - ys) + fabs(zi1 - zs);
          if (sep <= slen) {
            icon1[is] = m + NEC_PATCH_OFFSET;
            if (!NECCurrentExpansionBlockPushBackIPCON(segj, ip)) {
              return false;
            }
            if (!subph_2(data, angl, ip, 1, NULL)) {
              return false;
            }
            break;
          }
          
          sep = fabs(xi2 - xs) + fabs(yi2 - ys) + fabs(zi2 - zs);
          if (sep <= slen) {
            icon2[is] = m + NEC_PATCH_OFFSET;
            if (!NECCurrentExpansionBlockPushBackIPCON(segj, ip)) {
              return false;
            }
            if (!subph_2(data, angl, ip, 1, NULL)) {
              return false;
            }
            break;
          }
          
        } // End looping through new segments
      } // end looping through NGF patches
    } // end if new segments and NGF patches
  } // end if any surface patches exist
  
  // This prints the connection data to the output file.
  NECOutputFileWriteSegmentsUsed(outfile, n, np, ipsym);
  if (m > 0) {
    NECOutputFileWritePatchesUsed(outfile, m, mp);
  }
 
  // Is symmetry in use (no if iseg == 1)?
  size_t iseg = (n + m) / (np + mp);
  
  // If there is symmetry in use.
  if (iseg != 1) {
    if (ipsym < 0) {
      NECOutputFileWriteFoldRotationalSymmetry(outfile, iseg);
    } else if (ipsym == 0) {
      // Error: Symmetry is in use ((n + m) / (np + mp) != 1) but the symmetry
      // flag is set to zero (no symmetry).
      if (error) {
        *error = NECErrorMake(
            true, -1, "Symmetry detected but no symmetry flag.");
      }
      return false;
    } else {
      long ic = iseg / 2;
      if (iseg == 8) { ic = 3; }
      NECOutputFileWritePlanesOfSymmetry(outfile, ic);
    }
  }
  
  // Continue only if there are wire segments in the buffer.
  if (n != 0) {
    
    NECOutputFileWriteMultiwireJunctionsHeader(outfile);
    
    iseg = 0; // set iseg to zero for some reason...
    
    // Adjust connected segment ends to exactly coincide. Print junctions of
    // three or more segments. Also, find old segments connecting to new
    // segments.
    for (size_t j = 0; j < n; ++j) {
      
      // Connection indicator (other segment?) for segment j (end 1)
      long cseg_num = icon1[j];
      
      // Count the number of wire segments connected at the junction
      long ic = 1;
      
      // jco is used here to store the segments connecte at the junction. The
      // sign is used to indicate which end (1 or 2).
      jco[0] = -IDX_TO_NUM(j);
      
      // This variable is used to indicate the end of the segment that is
      // connected at the junction (-1 = end 1, 1 = end 2).
      int jend = -1;
      
      // Segment j (end 1) coordinate data
      double xa = x[j];
      double ya = y[j];
      double za = z[j];
      
      // Do the search for each end of the segment.
      for (char iend = 0; iend < 2; iend++) {
        
        // If there is actually something connected to the segment.
        // ix == NEC_NO_CONNECTION  // Nothing connected to the segment
        // ix == j + 1              // Connected to the ground plane
        // ix >= NEC_PATCH_OFFSET   // Connected to a patch
        if ((cseg_num != NEC_NO_CONNECTION) && (cseg_num != IDX_TO_NUM(j))
            && (cseg_num < NEC_PATCH_OFFSET)) {
          
          // True if the junction includes any new segments when NGF is in use.
          bool nsflg = false;
          
          do {
            
            if (signbit(cseg_num) > 0) {
              cseg_num = -cseg_num;
            }
            else {
              jend = -jend;
            }
            
            ++ic; // Increment the count of wires at the junction
            
            // Make sure jco is big enough
            if (!NECCurrentExpansionBlockBufferSize(segj, ic)) {
              if (error != NULL) { *error = NECErrorMake002(cseg_num); }
              return false;
            }
            
            // Store the connected segment (sign represents end).
            jco[ic - 1] = cseg_num * jend;
            
            nsflg = (cseg_num > n1); // if (ix > n1) { nsflg = true; }
            
            long cseg_idx = NUM_TO_IDX(cseg_num);
            if (jend == 1) {
              xa += x2[cseg_idx];
              ya += y2[cseg_idx];
              za += z2[cseg_idx];
              cseg_num = icon2[cseg_idx];
            } else {
              xa += x[cseg_idx];
              ya += y[cseg_idx];
              za += z[cseg_idx];
              cseg_num = icon1[cseg_idx];
            }
            
          } while (labs(cseg_num) > IDX_TO_NUM(j));
          
          // If |ix| == j then we have come all the way around (counted up all
          // the segments at the junction, therefore, processing of the
          // accumulated junction data should commence. If |ix| < j, then the
          // junction must have been previously processed so skip to what is
          // next (either the next end of the same segment, or the next segment
          // altogether.
          
          if (labs(cseg_num) == IDX_TO_NUM(j)) {
            
            double sep = (double) ic;
            xa /= sep;
            ya /= sep;
            za /= sep;
            
            for (size_t i = 0; i < ic; ++i) {
              long ix = NUM_TO_IDX(labs(jco[i]));
              if (signbit(jco[i]) == 0) {
                x2[ix] = xa;
                y2[ix] = ya;
                z2[ix] = za;
              } else {
                x[ix] = xa;
                y[ix] = ya;
                z[ix] = za;
              }
            }
            
            // OD: If the junction includes new segments (NSFLG = 1) and IX is
            //     a NGF segment an equation number, NSCON, is assigned for the
            //     modified basis function of segment IX. The equation number
            //     is stored in array ICONX and the segment number is stored in
            //     ISCON.
            if ((n1 != 0) && nsflg) {
              for (size_t i = 0; i < ic; ++i) {
                long ix = NUM_TO_IDX(labs(jco[i]));
                if ((ix < n1) && (iconx[ix] == 0)) {
                  NECCurrentExpansionBlockPushBackISCON(segj, ix);
                  iconx[ix] = nscon;
                }
              }
            }
            
            // OD: Segment numbers are printed for junctions of three or more
            //     segments.
            if (ic >= 3) {
              ++iseg;
              NECOutputFileWriteMultiwireJunction(outfile, iseg, jco, ic);
            }
          }
        }
        
        // OD: The loop is initialized for the second end of segment J and the
        //     steps from CN191 are repeated.
        if (iend == 0) {
          // If end 1 was checked, set to the variables to check end 2 and
          // re-run the check algorithm.
          cseg_num = icon2[j];    // Connection indicator for segment j (end 2)
          ic = 1;                 // Reset the wires at junction count
          jend = 1;               // Set flag for end 2
          jco[0] = IDX_TO_NUM(j); // So far the given segment is in the junc
          xa = x2[j];             // Segment j (end 2) coordinate data
          ya = y2[j];             // **
          za = z2[j];             // **
        }
        
      } // end: for (char iend = 1; iend <= 2; iend++)
    } // end: for (size_t j = 0; j < n; ++j)
    
    if (iseg == 0) {
      NECOutputFileWriteLine(outfile, "  NONE");
    }
    
    // If there are both old segments and new patches, find the old segments
    // that connect to new patches.
    // OD: Equation numbers for modified basis functions are assigned for old
    //     segments that connect to new patches.
    if ((n1 > 0) && (m > m1)) {
      for (size_t j = 0; j < n1; ++j) {
        long ix = icon1[j];           // Connection indicator for end 1
        if (ix > NEC_PATCH_OFFSET) {  // If connected to a patch
          ix -= NEC_PATCH_OFFSET;     // Get the patch number
          if (ix > m1) {              // If greater than m1 its a new patch
            if (iconx[j] != 0) { continue; }
            if (!NECCurrentExpansionBlockPushBackISCON(segj, j)) {
              return false;
            }
            iconx[j] = nscon;
            continue;
          }
        }
        ix = icon2[j];                // Connection indicator for end 1
        if (ix > NEC_PATCH_OFFSET) {  // If connected to a patch
          ix -= NEC_PATCH_OFFSET;     // Get the patch number
          if (ix > m1) {              // If greater than m1 its a new patch
            if (iconx[j] != 0) { continue; }
            if (!NECCurrentExpansionBlockPushBackISCON(segj, j)) {
              return false;
            }
            iconx[j] = nscon;
          }
        }
      }
    } // end: looking for old segments that connect to new patches
    
  } // end: [if (n != 0)] if wire segments exist
  
  return true; // No problems...
}

#undef data_1
#undef x
#undef y
#undef z
#undef icon1
#undef icon2
#undef iconx
#undef ld
#undef n1
#undef n2
#undef n
#undef np
#undef m1
#undef m2
#undef m
#undef mp
#undef ipsym
#undef x2
#undef y2
#undef z2
#undef segj_1
#undef jco
#undef iscon
#undef nscon
#undef ipcon
#undef npcon
