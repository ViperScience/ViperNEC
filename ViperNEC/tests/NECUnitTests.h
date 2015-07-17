//
//  NECUnitTests.h
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

#include <assert.h>

/**
 *
 */
void run_all_unit_tests();

/**
 * Test the atgn_ function (arctangent).
 */
void atgn__test();

/**
 * Test the cang_ function.
 * Calculates the phase angle of a complex number (degrees).
 */
void cang__test();

/**
 * Test the dB functions (dB10_ and dB20_).
 */
void dB_functions_test();

/**
 * Convert lower to upper case (test upcase_2).
 */
void upcase_2_test();

/**
 *  Test parsit_2 by feeding it an input card string.
 */
void parsit_2_test();

/**
 *  Test readgm_2 by feeding it a test input card string.
 */
void readgm_2_test();

/**
 *  Unit tests for wire_2
 */
void wire_2_test();

/**
 *  Unit tests for arc_2
 */
void arc_2_test();

/**
 *  Unit tests for helix_2
 */
void helix_2_test();

/**
 *  Unit tests for patch_2
 */
void patch_2_test();

/**
 *  Unit tests for connect_2
 */
void connect_2_test();

/**
 *  Unit tests for isegno_2
 */
void isegno_2_test();

/**
 *  Unit tests for reflc_2
 */
void reflc_2_test();

/**
 *  Unit tests for move_2
 */
void move_2_test();

/**
 *  Unit tests for gfil_2
 */
void gfil_2_test();

/**
 *  Unit tests for subph_2
 */
void subph_2_test();

/**
 *  Unit tests for NECInputFileMake
 *  Test reading in an NEC simulation file.
 */
void NECInputFileMake_test();

/**
 *  Unit tests the output file object.
 */
void NECOutputFile_test();

/**
 *  Unit tests for datagn_2
 */
void datagn_2_test_with_example_1();
void datagn_2_test_with_example_2();
void datagn_2_test_with_example_3();
void datagn_2_test_with_example_4();
void datagn_2_test_with_example_5();
void datagn_2_test_with_example_6();
void datagn_2_test_with_example_7();
