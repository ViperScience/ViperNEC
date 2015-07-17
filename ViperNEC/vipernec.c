//
//   vipernec.c
//   ViperNEC
//
//   Created by Dylan Crocker on 7/16/15.
//   Copyright 2015 Viper Science
//
//   Licensed under the Apache License, Version 2.0 (the "License");
//   you may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.
//

#include "vipernec.h"
#include "geometry.h"
#include "blocks.h"
#include "error.h"
#include "io.h"

#include <stdlib.h>

/**
 * This is the actual NEC solver.
 */
int vipernec(const char *input_file_path, const char *output_file_path) {
  
  // Read the input file.
  NECInputFile *input = NECInputFileMake(input_file_path);
  
  // Declare data structures that will contain the geometry data (similar to the
  // FORTRAN common blocks in the original code) as well as facilitate
  // functionality (error handling, saving data, etc.).
  NECDataBlock  *data = NULL;
  NECAngleBlock *angl = NULL;
  NECCurrentExpansionBlock  *segj = NULL;
  NECPlotBlock  *plot = NULL;
  NECError      *error_block = NULL;
  NECOutputFile *output_file = NULL;
  
  // Copy the simulation comments to the output file.
  
  // Parse the geometry data from the input file - This function will initialize
  // and/or resize the data buffers as needed.
  datagn_2(input, &data, &angl, &plot, &segj, &output_file, &error_block);
  if (error_block->flag) {
    // Make sure error handling still cleans up the memory used
    
    NECOutputFileWriteLine(output_file, (*error_block).message);
    return 0; // Print the error and return
    
  }
  
  // Should now have filled geometry buffers.
  
  // What next??
  
  //
  
  // Clean-up
  NECInputFileDelete(input);
  NECDataBlockDelete(data);
  NECAngleBlockDelete(angl);
  NECCurrentExpansionBlockDelete(segj);
  NECPlotBlockDelete(plot);
  NECErrorDelete(error_block);
  NECOutputFileDelete(output_file);
  
  return 0;
}