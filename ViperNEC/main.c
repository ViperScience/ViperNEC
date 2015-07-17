//
//  main.c
//  ViperNEC
//
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vipernec.h"
#include "Tests/NECUnitTests.h"

int main(int argc, char *argv[])
{
  int ret_val = -1;
  if (argc >= 2) {
    if (strncmp("-u", argv[1], 2) == 0) {
      // The "-u" option will run all unit tests for the program.
      run_all_unit_tests();
      printf("All unit tests passed.");
      ret_val = 0;
    } else if (argc >= 3) {
      // Otherwise, start the solver with the given file paths.
      ret_val = vipernec(argv[1], argv[2]);
    }
    else {
      printf("Invalid input parameters.");
    }
  } else {
    printf("No input parameters specified.");
  }
  return ret_val;
}
