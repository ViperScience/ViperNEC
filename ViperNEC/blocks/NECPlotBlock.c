//
//  NECPlotBlock.c
//  ViperNEC
//
//  Created by Dylan Crocker on 7/25/14.
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

#include "NECPlotBlock.h"
#include <stdlib.h>

NECPlotBlock *NECPlotBlockMake() {
  NECPlotBlock *block = calloc(1, sizeof(NECPlotBlock));
  return block;
}

void NECPlotBlockDelete(NECPlotBlock *block) {
  if (block != NULL) {
    free(block);
    block = NULL;
  }
}