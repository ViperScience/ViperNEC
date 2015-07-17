//
//  NECOutputFile.h
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

#ifndef VIPERNEC_NECOUTPUTFILE_H
#define VIPERNEC_NECOUTPUTFILE_H

#include <stdlib.h>
#include "types.h"

/**
 *  This struct and its helper methods are used to write results and information
 *  from the NEC simulation to a text file.
 *
 *  @since v1.0
 */
typedef struct ouput_file {
  
  /** 
   *  Path to the output file.
   *
   *  @since v1.0
   */
  char *filePath;
  
} NECOutputFile;

/**
 *  Create an NEC output file object and create the file on disk (overwrite if
 *  necessary).
 *
 *  @param outputFilePath Path to the NEC output file to be written.
 *
 *  @since v1.0
 */
NECOutputFile* NECOutputFileMake(const char *outputFilePath);

/**
 *  Frees all dynamically allocated memory in the given NECOutputFile struct as
 *  well as the struct's memory itself. The given pointer will be set to NULL.
 *
 *  @param file An NECInputFile object that has been initialized (mallaoc) and
 *              has dynamically created arrays that need released.
 *
 *  @since v1.0
 */
void NECOutputFileDelete(NECOutputFile *file);

/**
 *  Write a given (preformatted) string of characters to the output file.
 *
 *  @param file  An initialized NECInputFile object (cannot be NULL)
 *  @param chars The string of characters to be written to the file
 *
 *  @return True if all file operations completed successfully
 *
 *  @since v1.0
 */
bool NECOutputFileWrite(NECOutputFile *file, const char *chars);

/**
 *  Write a given (preformatted) line of text to the output file.
 *
 *  @param file An initialized NECInputFile object (cannot be NULL)
 *  @param line The line of text to be written to the file
 *
 *  @return True if all file operations completed successfully
 *
 *  @since v1.0
 */
bool NECOutputFileWriteLine(NECOutputFile *file, const char *line);

/******************************************************************************/
// Convenience functions for writing geometry information from datagn_2.
/******************************************************************************/

/**
 *  This method is a helper function for writing wire structure specification 
 *  data (from the GW card) to the output log file. It provides a defined format 
 *  string which it uses to format the given paramters before writing the data 
 *  to file.
 *
 *  @param file     The output file object which facilitates data logging
 *  @param nwire    The number of the wire (the count of wires processed)
 *  @param s1_x     Wire start x-coordintate
 *  @param s1_y     Wire start y-coordintate
 *  @param s1_z     Wire start z-coordintate
 *  @param s2_x     Wire end x-coordintate
 *  @param s2_y     Wire end y-coordintate
 *  @param s2_z     Wire end z-coordintate
 *  @param radius   Wire radius
 *  @param num_segs Number of segments making up the wire
 *  @param star_seg The global segment number for the fist segment
 *  @param stop_seg The global segment number for the last segment
 *  @param tag      Wire tag number
 *
 *  @return True if all file operations completed successfully
 *
 *  @since v1.0
 */
bool NECOutputFileWriteWireStructureSpec(NECOutputFile *file, size_t nwire,
                                         double s1_x, double s1_y, double s1_z,
                                         double s2_x, double s2_y, double s2_z,
                                         double radius, size_t num_segs,
                                         size_t star_seg, size_t stop_seg,
                                         long tag);

/**
 *  This method is a helper function for writing patch structure specification
 *  data (from the SP card) to the output log file. It provides a defined format
 *  string which it uses to format the given paramters before writing the data
 *  to file.
 *
 *  @param file  The output file object which facilitates data logging
 *  @param p_num Patch number
 *  @param ipt   Patch type identifier
 *  @param x1    X-axis coordinate of the first patch corner
 *  @param y1    Y-axis coordinate of the first patch corner
 *  @param z1    Z-axis coordinate of the first patch corner
 *  @param x2    X-axis coordinate of the second patch corner
 *  @param y2    Y-axis coordinate of the second patch corner
 *  @param z2    Z-axis coordinate of the second patch corner
 *
 *  @return True if all file operations completed successfully
 *
 *  @since v1.0
 */
bool NECOutputFileWritePatchStructureSpec(NECOutputFile *file, size_t p_num,
                                          const char* ipt, double x1, double y1,
                                          double z1, double x2, double y2,
                                          double z2);

/**
 *  This function logs the second half of the patch specification data (read 
 *  from the SC card) which contains the 3rd and 4th corner coordinates.
 *
 *  @param file The output file object which facilitates data logging
 *  @param x3   X-axis coordinate of the third patch corner
 *  @param y3   Y-axis coordinate of the third patch corner
 *  @param z3   Z-axis coordinate of the third patch corner
 *  @param x4   X-axis coordinate of the fourth patch corner
 *  @param y4   Y-axis coordinate of the fourth patch corner
 *  @param z4   Z-axis coordinate of the fourth patch corner
 *
 *  @return True if all file operations completed successfully
 *
 *  @since v1.0
 */
bool NECOutputFileWritePatchStructureSpecPart2(NECOutputFile *file, double x3,
                                               double y3, double z3, double x4,
                                               double y4, double z4);

/**
 *  This function logs the multiple patch specification data (read from an SM
 *  card) to the output log file.
 *
 *  @param file  The output file object which facilitates data logging
 *  @param p_num Patch number
 *  @param x1    X-axis coordinate of the first corner of the multi-patch area
 *  @param y1    Y-axis coordinate of the first corner of the multi-patch area
 *  @param z1    Z-axis coordinate of the first corner of the multi-patch area
 *  @param x2    X-axis coordinate of the second corner of the multi-patch area
 *  @param y2    Y-axis coordinate of the second corner of the multi-patch area
 *  @param z2    Z-axis coordinate of the second corner of the multi-patch area
 *  @param nx    Number of patches from corner 1 to corner 2
 *  @param ny    Number of patches from corner 2 to corner 3
 *
 *  @return True if all file operations completed successfully
 *
 *  @since v1.0
 */
bool NECOutputFileWriteMultiPatchSpecP1(NECOutputFile *file, size_t p_num,
                                        double x1, double y1, double z1,
                                        double x2, double y2, double z2,
                                        long nx, long ny);

/**
 *  This function logs the second half of the multi-patch specification data 
 *  (read from the SC card) which contains the 3rd and 4th corner coordinates.
 *
 *  @param file The output file object which facilitates data logging
 *  @param x3   X-axis coordinate of the third corner of the multi-patch area
 *  @param y3   Y-axis coordinate of the third corner of the multi-patch area
 *  @param z3   Z-axis coordinate of the third corner of the multi-patch area
 *  @param x4   X-axis coordinate of the fourth corner of the multi-patch area
 *  @param y4   Y-axis coordinate of the fourth corner of the multi-patch area
 *  @param z4   Z-axis coordinate of the fourth corner of the multi-patch area
 *
 *  @return True if all file operations completed successfully
 *
 *  @since v1.0
 */
bool NECOutputFileWriteMultiPatchSpecP2(NECOutputFile *file, double x3,
                                        double y3, double z3, double x4,
                                        double y4, double z4);

/**
 *  This method is a helper function for writting wire data specified in a
 *  GC card to the log file.
 *
 *  @param file The output file object which facilitates data logging
 *  @param rdel Segment length ratio
 *  @param rad1 Radius of the first segment
 *  @param rad2 Radius of the last segment
 *
 *  @return True if all file operations completed successfully
 *
 *  @since v1.0
 */
bool NECOutputFileWriteWireTapperData(NECOutputFile *file, double rdel,
                                      double rad1, double rad2);

/**
 *  This function writes the wire arc specification data (read from the GA card)
 *  to the output log file.
 *
 *  @param file      The output file object which facilitates data logging
 *  @param nwire     The number of the wire (the count of wires processed)
 *  @param rada      Arc radius
 *  @param ang1      Start angle
 *  @param ang2      Stop angle
 *  @param rad       Wire radius
 *  @param num_segs  Number of segments making up the wire
 *  @param first_seg The global segment number for the fist segment
 *  @param last_seg  The global segment number for the last segment
 *  @param tag       Wire tag number
 *
 *  @return True if all file operations completed successfully
 *
 *  @since v1.0
 */
bool NECOutputFileWriteArcData(NECOutputFile *file,  size_t nwire, double rada,
                               double ang1, double ang2, double rad,
                               long int num_segs, long int first_seg,
                               long int last_seg, long int tag);

/**
 *  This function writes the wire helix specification data (read from the GH
 *  card) to the output log file.
 *
 *  @param file      The output file object which facilitates data logging
 *  @param nturns    number of turns in the spiral
 *  @param zlen      length of the spiral (along the z-axis)
 *  @param nwire     The number of the wire (the count of wires processed)
 *  @param hr1       Radius of the spiral at the start
 *  @param hr2       Radius of the spiral at the end
 *  @param wr1       Radius of wire at the first segment
 *  @param wr2       Radius of wire at the last segment
 *  @param ispx      Flag: 0 - log spiral, 1 - archimedes (if hr1 != hr2)
 *  @param num_segs  Number of segments making up the wire
 *  @param first_seg The global segment number for the fist segment
 *  @param last__seg The global segment number for the last segment
 *  @param tag       Wire tag number
 *
 *  @return True if all file operations completed successfully
 *
 *  @since v1.0
 */
bool NECOutputFileWriteHelixData(NECOutputFile *file, double nturns,
                                 double zlen, size_t nwire, double hr1,
                                 double hr2, double wr1, double wr2,
                                 double ispx, size_t num_segs, size_t first_seg,
                                 size_t last__seg, long int tag);

/**
 *  This function is used to write the contents of a gemoetry card to the output 
 * log file when a geometry card error is detected.
 *
 *  @param file   The output file object which facilitates data logging
 *  @param code   The two character code identifying the type of card
 *  @param int_1  The first integer of the card
 *  @param int_2  The second integer of the card
 *  @param real_1 The first real of the card
 *  @param real_2 The second real of the card
 *  @param real_3 The third real of the card
 *  @param real_4 The fourth real of the card
 *  @param real_5 The fifth real of the card
 *  @param real_6 The sixth real of the card
 *  @param real_7 The seventh real of the card
 *
 *  @return True if all file operations completed successfully
 *
 *  @since v1.0
 */
bool NECOutputFileWriteGeometryCardError(NECOutputFile *file, const char* code,
                                         long int int_1, long int int_2,
                                         double real_1, double real_2,
                                         double real_3, double real_4,
                                         double real_5, double real_6,
                                         double real_7);

/**
 *  This function formats and records rotation data (from the GR card) to the
 *  output log file.
 *
 *  @param file The output file object which facilitates data logging
 *  @param tag  Tag number of the structure to be rotated
 *  @param ns   Total number of times that the structure is to occur in the
 *              cylindrical array
 *
 *  @return True if all file operations completed successfully
 *
 *  @since v1.0
 */
bool NECOutputFileWriteZAxisRotation(NECOutputFile *file, long tag, long ns);

/**
 *  This is a helper function for writing information into the log file
 *  when structures are moved.
 *
 *  @param file The output file object which facilitates data logging
 *  @param tagi Segment tag increment (applied to transformed segments)
 *  @param reps Repetition factor
 *  @param arx  The angle of rotation about the x-axis
 *  @param ary  The angle of rotation about the y-axis
 *  @param arz  The angle of rotation about the z-axis
 *  @param xdt  X direction translation variable
 *  @param ydt  Y direction translation variable
 *  @param zdt  Z direction translation variable
 *  @param tag  The tag of the first wire segment in data to be moved
 *
 *  @return True if all file operations completed successfully
 *
 *  @since v1.0
 */
bool NECOutputFileWriteStructureMoved(NECOutputFile *file, long tagi, long reps,
                                      double arx, double ary, double arz,
                                      double xdt, double ydt, double zdt,
                                      double tag);

/**
 *  Logs the gemotry scaling information from the GS card.
 *
 *  @param file         The output file object which facilitates data logging
 *  @param scale_factor Structure scale factor (sizes muliplied by scale_factor)
 *
 *  @return True if all file operations completed successfully
 *
 *  @since v1.0
 */
bool NECOutputFileWriteScaleStructure(NECOutputFile *file, double scale_factor);

/**
 *  This function writes the header to the output log file for the wire 
 *  segmentation data section.
 *
 *  @param file The output file object which facilitates data logging
 *
 *  @return True if all file operations completed successfully
 *
 *  @since v1.0
 */
bool NECOutputFileWriteWireSementationHeader(NECOutputFile *file);

/**
 *  This function facilitates writing wire segmentation data to the output file.
 *
 *  @param file   The output file object which facilitates data logging
 *  @param seg_no The wire segment number (not index)
 *  @param x      X-coordinate of the wire segment
 *  @param y      Y-coordinate of the wire segment
 *  @param z      Z-coordinate of the wire segment
 *  @param length The length of the wire segment
 *  @param alpha  The alpha angle of the wire segment
 *  @param beta   The alpha angle of the wire segment
 *  @param rad    The wire segment radius
 *  @param im     The segment connected on the - side of the segment
 *  @param ip     The segment connected on the + side of the segment
 *  @param tag    The wire segment tag
 *
 *  @return True if all file operations completed successfully
 *
 *  @since v1.0
 */
bool NECOutputFileWriteWireSementationData(NECOutputFile *file, size_t seg_no,
                                           double x, double y, double z,
                                           double length, double alpha,
                                           double beta, double rad, long im,
                                           long ip, long tag);

bool NECOutputFileWritePatchDataHeader(NECOutputFile *file);

/**
 *  This function facilitates writing surface patch data to the output file.
 *
 *  @param file     The output file object which facilitates data logging
 *  @param patch_no The patch number
 *  @param x        X-coordinate of the surface patch
 *  @param y        Y-coordinate of the surface patch
 *  @param z        Z-coordinate of the surface patch
 *  @param un_x     Unit normal vector (x coordinate)
 *  @param un_y     Unit normal vector (y coordinate)
 *  @param un_z     Unit normal vector (z coordinate)
 *  @param area     The area of the patch
 *  @param ut_x1    The first unit tangent vector (x coordinate)
 *  @param ut_y1    The first unit tangent vector (y coordinate)
 *  @param ut_z1    The first unit tangent vector (z coordinate)
 *  @param ut_x2    The second unit tangent vector (x coordinate)
 *  @param ut_y2    The second unit tangent vector (y coordinate)
 *  @param ut_z2    The second unit tangent vector (z coordinate)
 *
 *  @return True if all file operations completed successfully
 *
 *  @since v1.0
 */
bool NECOutputFileWritePatchData(NECOutputFile *file, size_t patch_no, double x,
                                 double y, double z, double un_x, double un_y,
                                 double un_z, double area, double ut_x1,
                                 double ut_y1, double ut_z1, double ut_x2,
                                 double ut_y2, double ut_z2);

/**
 *  This function provides an easy interface for writing structure reflection
 *  information to the log file.
 *
 *  @param file The output file object which facilitates data logging
 *  @param ix   Flag indicating reflection along the x-axis
 *  @param iy   Flag indicating reflection along the y-axis
 *  @param iz   Flag indicating reflection along the z-axis
 *  @param itg  Tag increment
 *
 *  @return True if all file operations completed successfully
 *
 *  @since v1.0
 */
bool NECOutputFileWriteReflectionData(NECOutputFile *file, long ix, long iy,
                                      long iz, long itx);

/******************************************************************************/
// Convenience functions for writing geometry information from connect_2.
/******************************************************************************/

/**
 *  Write the ground specification to the output file.
 *
 *  @param file The output file object which facilitates data logging
 *  @param ignd Ground flag
 *
 *  @return True if all file operations completed successfully
 *
 *  @since v1.0
 */
bool NECOutputFileWriteGroundSpec(NECOutputFile *file, long ignd);

/**
 *  Write the summary of total segments used in the simulation.
 *
 *  @param file  The output file object which facilitates data logging
 *  @param n     The total number of segments
 *  @param np    The number of segments in symmetric cell
 *  @param ipsym Symmetry flag
 *
 *  @return True if all file operations completed successfully
 *
 *  @since v1.0
 */
bool NECOutputFileWriteSegmentsUsed(NECOutputFile *file, size_t n, size_t np,
                                    long ipsym);

/**
 *  Write the summary of total patchs used in the simulation.
 *
 *  @param file The output file object which facilitates data logging
 *  @param m    Total number of patches
 *  @param mp   The number of patches in symmetric cell
 *
 *  @return True if all file operations completed successfully
 *
 *  @since v1.0
 */
bool NECOutputFileWritePatchesUsed(NECOutputFile *file, size_t m, size_t mp);

/**
 *  Write the fold rotational symmetry information.
 *
 *  @param file The output file object which facilitates data logging
 *  @param iseg Number of fold rotational symmetry
 *
 *  @return True if all file operations completed successfully
 *
 *  @since v1.0
 */
bool NECOutputFileWriteFoldRotationalSymmetry(NECOutputFile *file, long iseg);

/**
 *  Write the planes of symmetry information.
 *
 *  @param file The output file object which facilitates data logging
 *  @param ic   Number of planes of symmetry (1-3)
 *
 *  @return True if all file operations completed successfully
 *
 *  @since v1.0
 */
bool NECOutputFileWritePlanesOfSymmetry(NECOutputFile *file, long ic);

/**
 *  Write the header for the multiwire junction data.
 *
 *  @param file The output file object which facilitates data logging
 *
 *  @return True if all file operations completed successfully
 *
 *  @since v1.0
 */
bool NECOutputFileWriteMultiwireJunctionsHeader(NECOutputFile *file);

/**
 *  Write the multiwire junction data to the output file.
 *
 *  @param file The output file object which facilitates data logging
 *  @param iseg Junction number (start with 1)
 *  @param jco  Array containing segment numbers for segments in the junction
 *  @param ic   Number of segments in the junction
 *
 *  @return True if all file operations completed successfully
 *
 *  @since v1.0
 */
bool NECOutputFileWriteMultiwireJunction(NECOutputFile *file, long iseg,
                                         long *jco, long ic);

/******************************************************************************/
// Convenience functions for writing geometry information from helix_2.
/******************************************************************************/


bool NECOutputFileWriteConeAngle(NECOutputFile *file, double angle);
bool NECOutputFileWritePitchAngle(NECOutputFile *file, double angle);
bool NECOutputFileWriteWireTurnLength(NECOutputFile *file, double length);

#endif
