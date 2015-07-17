//
//  error.h
//  ViperNEC
//
//  Created by Dylan Crocker on 7/31/14.
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

// Many of these errors are deprecated from the new code structure. They are
// all included here from the original NEC documentation along with some new
// ones for the new code structure.

#ifndef NEC_ERROR_H
#define NEC_ERROR_H

#include <stdbool.h>
#include <stdlib.h>

#define MESSAGE_SIZE 256

typedef enum {
  NoError = 0,
  Error001, // Errors defined in the NEC documentation.
  Error002,
  Error003,
  Error004,
  Error005,
  Error006,
  Error007,
  Error008,
  Error009,
  Error010,
  Error011,
  Error012,
  Error013,
  Error014,
  Error015,
  Error016,
  Error017,
  Error018,
  Error019,
  Error020,
  Error021,
  Error022,
  Error023,
  Error024,
  Error025,
  Error026,
  Error027,
  Error028,
  Error029,
  Error030,
  Error031,
  Error032,
  Error033,
  Error034,
  Error035,
  Error036,
  Error037,
  Error038,
  Error039,
  Error040,
  Error041,
  Error042,
  Error043,
  Error044,
  Error045,
  Error046,
  OutOFMemoryError = 100, // New Errors
  NoInputDataError,
  InvalidInputError,
  UnknownError = 999,
} NECErrorCode;

/**
 * Structures used throughout the NEC program to wrap errors for passing out
 * of functions to error handling code.
 */
typedef struct error_block {
  bool flag;                      // Flag: true = error, false = no error.
  NECErrorCode code;              // Numerical code - see the NECErrorCode enum.
  char message[MESSAGE_SIZE + 1]; // Textual description of the error.
} NECError;

/**
 * Build an arbitrary error block.
 * @param flag    Boolean flag indicating an error.
 * @param code    Numerical error code.
 * @param message Description of error (human readable).
 * @return A pointer to a new NECError structure.
 * @since v1.0
 */
NECError *NECErrorMake(bool flag, NECErrorCode code, const char* message);

/**
 * Clean up memory allocated to a specified NECError block.
 * @param error NECError block to be released.
 * @since v1.0
 */
void NECErrorDelete(NECError *error);

/**
 * Return a pointer to a newly created (on the heap) NECError structure which
 * indicates the program has run out of memory. Note: if the program has run out
 * of all memory this function my not work. Use after unsuccessfull calls to 
 * malloc.
 */
NECError *NECErrorMakeOutOfMemeory();

/**
 * Build and return a error block indicating that input data was given to a
 * function (e.g. NULL pointer).
 */
NECError *NECErrorMakeNoInputData();

/**
 * Build an error block indicating an invalid input error. This error will be
 * created by functions when an input is invalid (e.g. NULL pointer).
 */
NECError *NECErrorMakeInvalidInput();

////////////////////////////////////////////////////////////////////////////////
// Errors Defined in the NEC documentation.
////////////////////////////////////////////////////////////////////////////////

/** Build Error Block 001 (description below)
 * CHECK DATA, PARAMETER SPECIFYING SEGMENT POSITION IN A GROUP OF EQUAL
 * TAGS CANNOT BE ZERO.
 * Routine: ISEGNO
 * This error results from an input data error and may occur at any point
 * where a tag number is used to identify a segment. Execution terminated.
 * Data on the NT, TL, EX, and PT cards should be checked.
 */
NECError *NECErrorMake001();

/** Build Error Block 002 (description below)
 * CONNECT - SEGMENT CONNECTION ERROR FOR SEGMENT _.
 * Routine: CONNECT
 * Possible causes: number of segments at a Junction exceeds limit: segment
 * lengths are zero; array overflow.
 */
NECError *NECErrorMake002(size_t segment);

/** Build Error Block 003 (description below)
 * DATA FAULT ON LOADING CARD NO. __ ITAG STEP1 __ IS GREATER THAN ITAG STEP2 _.
 * Routine: MAIN
 * When several segments are loaded, the number of the second segment
 * specified must be greater than the number of the first segment.
 * Execution terminated.
 */
NECError *NECErrorMake003(size_t card_no, size_t step_1, size_t step_2);

/** Build Error Block 004 (description below)
 * EOF ON UNIT _ NBLKS = _ NEOF = _
 * Routine: BLCKLN, entry point of BLCKOT
 * An end of file has been encountered while reading data from the unit.
 * NBLKS determines how many records are read from the unit. NEOF is a
 * flag to indicate which call to BLCKIN iniciated the read. If NEOF a
 * 777, this diagnostic is normal and execution will continue. Otherwise,
 * an error is indicated and execution will terminate.
 */
NECError *NECErrorMake004(size_t unit, size_t nblks, size_t neof);

/** Build Error Block 005 (description below)
 * ERROR -- ARC ANGLE EXCEEDS 360. DEGREES
 * Routine: ARC
 * Error on GA card.
 */
NECError *NECErrorMake005();

/** Build Error Block 006 (description below)
 * ERROR - B LESS THAN A IN ROM2
 * Routine: ROM2
 * Program malfunction,
 */
NECError *NECErrorMake006();

/** Build Error Block 007 (description below)
 * ERROR - FR/GN CARD IS NOT ALLOWED WITH N.G.F.
 * Routine: Main
 * See section 111-5.
 */
NECError *NECErrorMake007();

/** Build Error Block 008 (description below)
 * ERROR - CORNERS OF QUADRILATERAL PATCH DO NOT LIE IN A PLANE.
 * Routine: Patch
 * The four corners of a quadrilateral patch (SP card) must lie in a plane.
 */
NECError *NECErrorMake008();

/** Build Error Block 009 (description below)
 * ERROR - COUPLING IS NOT BETWEEN 0 AND 1
 * Routine: Couple
 * Inaccuracy in solution or error in data.
 */
NECError *NECErrorMake009();

/** Build Error Block 010 (description below)
 * ERROR - GF MUST BE FIRST GEOMETRY DATA CARD
 * Routine: DATAGN
 * See section III-5.
 */
NECError *NECErrorMake010();

/** Build Error Block 011 (description below)
 * ERROR IN GROUND PARAMETERS - COMPLEX DIELECTRIC CONSTANT _ FROM FILE _ IS
 * REQUESTED.
 * Routine: MAIN
 * Complex dielectric constant from file TAPE21 does not agree with data
 * from GN and FR cards.
 */
NECError *NECErrorMake011();

/** Build Error Block 012 (description below)
 * ERROR - INSUFFICIENT STORAGE FOR INTERACTION MATRICES.
 * IRESRV, IMAT, NEQ, NEQ2
 * Routine: FBNGF
 * Array storage exceeded in NGF solution.
 */
NECError *NECErrorMake012();

/** Build Error Block 013 (description below)
 * ERROR - INSUFFICIENT STORAGE FOR MATRIX
 * Routine: FBLOCK
 * Array storage for matrix is not sufficient for out-of-core solution.
 */
NECError *NECErrorMake013();

/** Build Error Block 014 (description below)
 * ERROR - NETWORK ARRAY DIMENSIONS TOO SMALL.
 * Routine: NETWK
 * The number of different segments to which transmission lines or network
 * ports are connected exceeds array dimensions. Execution terminated.
 * Array size in the original NEC deck is 30. Refer to array dimension
 * limitations in Part I1 for changing array sizes.
 */
NECError *NECErrorMake014();

/** Build Error Block 015 (description below)
 * ERROR - LOADING MAY NOT BE ADDED TO SEGMENTS IN N.G.F. SECTION
 * Routine: LOAD
 * See section 111-5.
 */
NECError *NECErrorMake015();

/** Build Error Block 016 (description below)
 * ERROR - N.G.F. IN USE. CANNOT WRITE NEW N.G.F.
 * Routine: MAIN
 */
NECError *NECErrorMake016();

/** Build Error Block 017 (description below)
 * ERROR - NO. NEW SEGMENTS CONNECTED TO N.G.F. SEGMENTS OR PATCHES
 * EXCEEDS LIMIT.
 * Routine: CONECT
 * Array dimension limit.
 */
NECError *NECErrorMake017();

/** Build Error Block 018 (description below)
 * FAULTY DATA CARD LABEL AFTER GEOMETRY SECTION.
 * Routine: MAIN
 * A card with an unrecognizable mnemonic has been encountered in the
 * program control cards following the geometry cards. Execution
 * terminated.
 */
NECError *NECErrorMake018();

/** Build Error Block 019 (description below)
 * GEOMETRY DATA CARD ERROR.
 * Routine: DATAGN
 * A geometry data card was expected, but the card mnemonic is not that
 * of a geometry card. Execution terminated. After the GE card in a
 * data deck, the possible geometry mnemonics are GE, GM, OR, GS, GW,
 * GX, SP, and SS.
 * The GE card must be used to terminate the geometry cards.
 */
NECError *NECErrorMake019();

/** Build Error Block 020 (description below)
 * GEOMETRY DATA ERROR - PATCH _ LIES IN PLANE OF SYMMETRY.
 * Routine: REFLC
 */
NECError *NECErrorMake020(size_t patch);

/** Build Error Block 021 (description below)
 * GEOMETRY DATA ERROR - SEGMENT _ EXTENDS BELOW GROUND.
 * Routine: CONECT
 * When ground is specified on the GE card, no segment may extend below
 * the XY plane. Execution terminated.
 */
NECError *NECErrorMake021(size_t segment);

/** Build Error Block 022 (description below)
 * GEOMETRY DATA ERROR - SEGMENT _ LIES IN GROUND PLANE.
 * Routine: CONECT
 * When ground is specified on the GE card, no segment should lie in the
 * XY plane. Execution terminated.
 */
NECError *NECErrorMake022(size_t segment);

/** Build Error Block 023 (description below)
 * GEOMETRY DATA ERROR - SEGMENT _ LIES IN PLANE OF SYMMETRY.
 * Routine: REFLC
 * A segment may not lie in or cross a plane of symmetry about which the
 * structure is reflected since the segment and its image will coincide or
 * cross. Execution terminated.
 */
NECError *NECErrorMake023(size_t segment);

/** Build Error Block 024 (description below)
 * IMPROPER LOAD TYPE CHOSEN, REQUESTED TYPE IS _.
 * Routine: LOAD
 * Valid load types (LDTYP on the LD card) arq from 0 through 5.
 * Execution terminated.
 */
NECError *NECErrorMake024(int load_type);

/** Build Error Block 025 (description below)
 * INCORRECT LABEL FOR A COMMENT CARD.
 * Routine: MAIN
 * The program expected a comment card, with mnemonic CM or CE, but
 * encountered a different mnemonic. Execution terminated. Comment cards
 * must be the first cards in a data set, and the comments must be
 * terminated by the CE mnemonic.
 */
NECError *NECErrorMake025();

/** Build Error Block 026 (description below)
 * LOADING DATA CARD ERROR, NO SEGMENT HAS AN ITAG = _.
 * Routine: LOAD
 * ITAG specified on an LD card could not be found an a segment tag.
 * Execution terminated.
 */
NECError *NECErrorMake026(size_t tag);

/** Build Error Block 027 (description below)
 * NO SEGMENT HAS AN ITAG OF _.
 * Routine: ISEGNO
 * This error results from faulty input data and can occur at any point
 * where a tag number is used to identify'a segmept. Exec~tion terminated.
 * Tag numbers on the NT, TL, EX, CP, PQ, and PT cards should be checked.
 */
NECError *NECErrorMake027(size_t tag);

/** Build Error Block 028 (description below)
 * NOTE, SOME OF THE ABOVE SEGMENTS HAVE BEEN LOADED TWICE, IMPEDANCES ADDED.
 * Routine: LOAD
 * A segment or segments have been loaded by two or more LD cards. The
 * impedances of the loads have been added in series. This is only an
 * informative message. Execution continues.
 */
NECError *NECErrorMake028();

/** Build Error Block 029 (description below)
 * NUMBER OF EXCITATION CARDS EXCEEDS STORAGE ALLOTTED.
 * Routine: MAIN
 * The number of voltage source excitations exceeds array dimensions.
 * Execution terminated. The dimensions in the original NEC deck allow
 * 10 voltage sources. Refer to Array Dimension Limitations in Part II
 * to change the dimensions.
 */
NECError *NECErrorMake029();

/** Build Error Block 030 (description below)
 * NUMBER OF LOADING CARDS EXCEEDS STORAGE ALLOTTED.
 * Routine; MAIN
 * The number of LD cards exceeds array dimension. Execution termtnated.
 * The dimension in the original NEC deck allows 30 LD cards. Refer to
 * Part II to change the dimensions.
 */
NECError *NECErrorMake030();

/** Build Error Block 031 (description below)
 * NUMBER OF NETWORK CARDS EXCEEDS STORAGE ALLOTTED.
 * Routine: MAIN
 * The number of NT and TL cards exceeds array dimension. Execution
 * terminated. The dimension in the original NEC dockc allows 30 cards.
 * Refer to Array Dimension Limitations in Part II to change the dimensions.
 */
NECError *NECErrorMake031();

/** Build Error Block 032 (description below)
 * NUMBER OF SEGMENTS IN COUPLING CALCULATION (CP) EXCEEDS LIMIT.
 * Routine: MAIN
 * Array dimension limit.
 */
NECError *NECErrorMake032();

/** Build Error Block 033 (description below)
 * NUMBER OF SEGMENTS AND SURFACE PATCHES EXCEEDS DIMENSION LIMIT.
 * Routine: DATAON
 * The sum of the number of segments and patches is limited by dimensions.
 * The present limit is 300.
 */
NECError *NECErrorMake033();

/** Build Error Block 034 (description below)
 * PATCH DATA ERROR.
 * Routine: DATAGN
 * Invalid data on SP, SM, or SC card; or SC card not found where required.
 */
NECError *NECErrorMake034();

/** Build Error Block 035 (description below)
 * PIVOT(_) = _
 * Routine: FACTR (in-core) or LFACTR (out-of-core)
 * This will be printed during the Gauss Doolittle factoring of the
 * interaction matrix or the network matrix when a pivot element less than
 * 10E-10 is encountered, and indicates that the matrix is nearly singular.
 * The number in parentheses shows on which pass through the matrix the
 * condition occurred. This is usually an abnormal condition although
 * execution will continue. It nay result from coinciding segments or a
 * segment of zero length.
 */
NECError *NECErrorMake035(size_t pass, double element);

/** Build Error Block 036 (description below)
 * RADIAL WIRE G.S. APPROXIMATION MAY NOT BE USED WITH SOMOMERFELD GROUND
 * OPTION.
 * Routine: MAIN
 */
NECError *NECErrorMake036();

/** Build Error Block 037 (description below)
 * RECEIVING PATTERN STORAGE TOO SMALL, ARRAY TRUNCATED.
 * Routine: MAIN
 * The number of points requested in a receiving pattern exceeds array
 * dimension. Execution will continue, but storae$ of normalized pattern
 * will be truncated. This array dimension is 200 in the original NEC
 * deck. Refer to Array Dimension Limitations in Part II to change
 * dimension.
 */
NECError *NECErrorMake037();

/** Build Error Block 038 (description below)
 * ROM2 - STEP SIZE LIMITED AT Z = _.
 * Routine: ROM2
 * Probably caused by a wire too close to the ground in the Sommerfield/
 * Norton ground method. Execution continues but results may be inaccurate.
 */
NECError *NECErrorMake038(size_t z);

/** Build Error Block 039 (description below)
 * SBF - SEGMENT CONNECTION ERROR FOR SEGMENT _.
 * Routine: SBF
 * The number of sepents at a junction exceeds dimension limit (30), or.
 * the connection numbers are not self-consistent,
 */
NECError *NECErrorMake039(size_t segment);

/** Build Error Block 040 (description below)
 * SEGMENT DATA ERROR.
 * Routine: MAIN
 * A segment with zero length or zero radius was found. Execution terminated.
 */
NECError *NECErrorMake040();

/** Build Error Block 041 (description below)
 * STEP SIZE LIMITED AT Z = _.
 * Routinet INTX, HFK
 * The numerical integration to compute interaction matrix elements, using
 * the Romberg variable interval width method, was limited by the minimum
 * allowed step size. Execution will continue. An inaccuracy may occur
 * but is usually not serious. May result from thin wire or wire close
 * to the ground.
 */
NECError *NECErrorMake041(size_t z);

/** Build Error Block 042 (description below)
 * STORAGE FOR IMPEDANCE NORMALIZATION TOO SMALL, ARRAY TRUNCATED.
 * Routine: MIAIN
 * The number of frequencies on FR card exceeds the array dimension for
 * impedance normalization. An impedance beyond the limit will not be
 * normalized. Execution continues. The limit is 50 in the original NEC
 * deck, Refer to Array Dimension Limitations in Part II to change limit.
 */
NECError *NECErrorMake042();

/** Build Error Block 043 (description below)
 * SYMMETRY ERROR - NROW, NCOL = _, _.
 * Routine: FBLOCK
 * Array overflow or program malfunction.
 */
NECError *NECErrorMake043(size_t row, size_t col);

/** Build Error Block 044 (description below)
 * TBF - SEGMENT CONNECTION ERROR FOR SEGMENT _.
 * Routine: TBF
 * Same as error 39.
 */
NECError *NECErrorMake044(size_t segment);

/** Build Error Block 045 (description below)
 * TRIO - SEGMENT CONNECTION ERROR FOR SEGMENT _.
 * Routine: TRIO
 * Same as error 39.
 */
NECError *NECErrorMake045(size_t segment);

/** Build Error Block 046 (description below)
 * WHEN MULTIPLE FREQUENCIES ARE REQUESTED, ONLY ONE NEAR FIELD CARD CAN
 * BE USED - LAST CARD READ IS USED.
 * Routine: MAIN
 * Execution continues.
 */
NECError *NECErrorMake046();

#endif
