//
//  NECPlotBlock.h
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



#ifndef NEC_PLOT_BLOCK_H
#define NEC_PLOT_BLOCK_H

/** NECPlotBlock
 * I'm not sure what his is used for. It may need to be removed.
 *
 * @since v1.0
 */
typedef struct plot_block {
  int iplp1;
  int iplp2;
  int iplp3;
  int iplp4;
} NECPlotBlock;

NECPlotBlock *NECPlotBlockMake();
void NECPlotBlockDelete(NECPlotBlock *block);

#endif
