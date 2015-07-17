//
//  cards.h
//  ViperNEC
//
//  Created by Dylan Crocker on 7/16/15.
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

#ifndef VIPERNEC_CARDS_H
#define VIPERNEC_CARDS_H

typedef enum {
  CardLabel_Unkown = -1,
  CardLabel_CE,
  CardLabel_FR,
  CardLabel_LD,
  CardLabel_GN,
  CardLabel_EX,
  CardLabel_NT,
  CardLabel_XQ,
  CardLabel_NE,
  CardLabel_GD,
  CardLabel_RP,
  CardLabel_CM,
  CardLabel_NX,
  CardLabel_EN,
  CardLabel_TL,
  CardLabel_PT,
  CardLabel_KH,
  CardLabel_NH,
  CardLabel_PQ,
  CardLabel_EK,
  CardLabel_WG,
  CardLabel_CP,
  CardLabel_PL,
  CardLabel_GW,
  CardLabel_GX,
  CardLabel_GR,
  CardLabel_GS,
  CardLabel_GE,
  CardLabel_GM,
  CardLabel_SP,
  CardLabel_SM,
  CardLabel_GF,
  CardLabel_GA,
  CardLabel_SC,
  CardLabel_GC,
  CardLabel_GH,
} NECCardLabel;

void parsit_2(char *card, char *cmnd, int cmnd_len, int *maxint, int *maxrea,
              int *intfld, double *reafld);

void upcase_2(char *intext, char *outtxt, int length);

NECCardLabel label_id(const char *readLabel);

#endif
