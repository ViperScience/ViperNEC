//
//  NECInputFile.c
//  ViperNEC
//
//  Created by Dylan Crocker on 7/14/14.
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

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "NECInputFile.h"

#define MAX_CARD_LENGTH 100

NECInputFile* NECInputFileMake(const char *input_file_path) {
  
  // Open a stream to the input file.
  FILE *in_file = fopen(input_file_path, "r");
  if (in_file == NULL) { return NULL; }
  
  // This flag is used to indicate all allocated memeory needs to be freed if an
  // error occurs.
  int clean_up = 0;
  
  // This flag is used to signal that the end of the geometry section has been
  // read (or the GE card found). It is used to prevent additional geometry
  // cards from being read after the GE card (which may couse errors later).
  int done_geometry = 0;
  
  // Create the buffers for holding the card data (initialize memory to 0).
  size_t comm_size = 10, geom_size = 10, ctrl_size = 10;
  char **comm_cards = calloc(comm_size, sizeof(char *));
  char **geom_cards = calloc(geom_size, sizeof(char *));
  char **ctrl_cards = calloc(ctrl_size, sizeof(char *));
  
  // Count the number of cards (lines) in the input file.
  int num_cards = 0, num_comments = 0, num_geometry = 0, num_control = 0;
  
  // Read the file line by line and save to the text (card) to the appropriate
  // buffer. Keep count of how big the buffers get!!
  char line[MAX_CARD_LENGTH];
  while (fgets(line, MAX_CARD_LENGTH, in_file) != NULL) {
    if        ((toupper(line[0]) == 'C' && toupper(line[1]) == 'M') ||
               (toupper(line[0]) == 'C' && toupper(line[1]) == 'E')) {
      // Comment cards
      
      num_comments++; // Increment the count first!
      
      // Need to re-allocate the buffer to get more space.
      if (num_comments > comm_size) {
        size_t new_comm_size = comm_size*2; // Double the size
        void *new_space = realloc(comm_cards, new_comm_size*sizeof(char *));
        if (new_space == NULL) {
          clean_up = 1;
          break;
        }
        comm_size = new_comm_size;
        comm_cards = new_space;
      }
      
      // Copy the string to a new buffer (dynamically allocated).
      comm_cards[num_comments - 1] = strdup(line);
      if (comm_cards[num_comments - 1] == NULL) {
        clean_up = 1;
        break;
      }
    } else if ((toupper(line[0]) == 'G' && toupper(line[1]) == 'A') ||
               (toupper(line[0]) == 'G' && toupper(line[1]) == 'F') ||
               (toupper(line[0]) == 'G' && toupper(line[1]) == 'M') ||
               (toupper(line[0]) == 'G' && toupper(line[1]) == 'R') ||
               (toupper(line[0]) == 'G' && toupper(line[1]) == 'S') ||
               (toupper(line[0]) == 'G' && toupper(line[1]) == 'W') ||
               (toupper(line[0]) == 'G' && toupper(line[1]) == 'X') ||
               (toupper(line[0]) == 'S' && toupper(line[1]) == 'P') ||
               (toupper(line[0]) == 'S' && toupper(line[1]) == 'M') ||
               (toupper(line[0]) == 'G' && toupper(line[1]) == 'E')) {
      // Geometry cards
      if (done_geometry == 0) {
        num_geometry++; // Increment the count first!
        
        // Need to re-allocate the buffer to get more space.
        if (num_geometry > geom_size) {
          size_t new_geom_size = geom_size*2; // Double the size
          void *new_space = realloc(geom_cards, new_geom_size*sizeof(char *));
          if (new_space == NULL) {
            clean_up = 1;
            break;
          }
          geom_size = new_geom_size;
          geom_cards = new_space;
        }
        
        // Copy the string to a new buffer (dynamically allocated).
        geom_cards[num_geometry - 1] = strdup(line);
        if (geom_cards[num_geometry - 1] == NULL) {
          clean_up = 1;
          break;
        }
      }
      
      // End of the Geometry input, save this card then accept no more.
      if ((toupper(line[0]) == 'G' && toupper(line[1]) == 'E')) {
        done_geometry = 1;
      }
    } else if ((toupper(line[0]) == 'C' && toupper(line[1]) == 'P') ||
               (toupper(line[0]) == 'E' && toupper(line[1]) == 'K') ||
               (toupper(line[0]) == 'E' && toupper(line[1]) == 'N') ||
               (toupper(line[0]) == 'E' && toupper(line[1]) == 'X') ||
               (toupper(line[0]) == 'F' && toupper(line[1]) == 'R') ||
               (toupper(line[0]) == 'G' && toupper(line[1]) == 'D') ||
               (toupper(line[0]) == 'G' && toupper(line[1]) == 'N') ||
               (toupper(line[0]) == 'K' && toupper(line[1]) == 'H') ||
               (toupper(line[0]) == 'L' && toupper(line[1]) == 'D') ||
               (toupper(line[0]) == 'N' && toupper(line[1]) == 'E') ||
               (toupper(line[0]) == 'N' && toupper(line[1]) == 'H') ||
               (toupper(line[0]) == 'N' && toupper(line[1]) == 'T') ||
               (toupper(line[0]) == 'N' && toupper(line[1]) == 'X') ||
               (toupper(line[0]) == 'P' && toupper(line[1]) == 'Q') ||
               (toupper(line[0]) == 'P' && toupper(line[1]) == 'T') ||
               (toupper(line[0]) == 'R' && toupper(line[1]) == 'P') ||
               (toupper(line[0]) == 'T' && toupper(line[1]) == 'L') ||
               (toupper(line[0]) == 'W' && toupper(line[1]) == 'G') ||
               (toupper(line[0]) == 'X' && toupper(line[1]) == 'Q')) {
      // Control cards
     
      num_control++; // Increment the count first!
      
      // Need to re-allocate the buffer to get more space.
      if (num_control > ctrl_size) {
        size_t new_ctrl_size = ctrl_size*2; // Double the size
        void *new_space = realloc(ctrl_cards, new_ctrl_size*sizeof(char *));
        if (new_space == NULL) {
          clean_up = 1;
          break;
        }
        ctrl_size = new_ctrl_size;
        ctrl_cards = new_space;
      }
      
      // Copy the string to a new buffer (dynamically allocated).
      ctrl_cards[num_control - 1] = strdup(line);
      if (ctrl_cards[num_control - 1] == NULL) {
        clean_up = 1;
        break;
      }
      
    } else {
      // Don't count unknown cards...
      continue;
    }
    num_cards++;
  }
  
  // Close the file.
  fclose(in_file);
  
  // If an error occured release any allocated memory and return NULL.
  NECInputFile *ret_val = NULL;
  if (clean_up) {
    for (int i = 0; i < comm_size; ++i) {
      if (comm_cards[i] != NULL) { free(comm_cards[i]); }
    }
    free(comm_cards);
    for (int i = 0; i < geom_size; ++i) {
      if (geom_cards[i] != NULL) { free(geom_cards[i]); }
    }
    free(geom_cards);
    for (int i = 0; i < ctrl_size; ++i) {
      if (ctrl_cards[i] != NULL) { free(ctrl_cards[i]); }
    }
    free(ctrl_cards);
  } else {
    
    // Re-size the buffers so space is not left allocated but unused.
    comm_cards = realloc(comm_cards, num_comments*sizeof(char *));
    geom_cards = realloc(geom_cards, num_geometry*sizeof(char *));
    ctrl_cards = realloc(ctrl_cards, num_control*sizeof(char *));
    
    // Create the inpt file struct to be returned.
    ret_val = malloc(sizeof(NECInputFile));
    ret_val->cardCount = num_cards;
    ret_val->commentCardCount = num_comments;
    ret_val->geometryCardCount = num_geometry;
    ret_val->controlCardCount = num_control;
    (*ret_val).commentCards = comm_cards;
    ret_val->geometryCards = geom_cards;
    ret_val->controlCards = ctrl_cards;
  }
  return ret_val;
}

void NECInputFileDelete(NECInputFile *ptr) {
  
  // If the given object is not null go through and free the memory.
  if (ptr != NULL) {
    
    // Free the memory taken up by the comment cards.
    if (ptr->commentCards != NULL) {
      for (int i = 0; i < ptr->commentCardCount; ++i) {
        if (ptr->commentCards[i] != NULL) { free(ptr->commentCards[i]); }
      }
      free(ptr->commentCards);
      ptr->commentCards = NULL;
    }
    
    // Free the memory taken up by the geometry cards.
    if (ptr->geometryCards != NULL) {
      for (int i = 0; i < ptr->geometryCardCount; ++i) {
        if (ptr->geometryCards[i] != NULL) { free(ptr->geometryCards[i]); }
      }
      free(ptr->geometryCards);
      ptr->geometryCards = NULL;
    }
    
    // Free the memory taken up by the control cards.
    if (ptr->controlCards != NULL) {
      for (int i = 0; i < ptr->controlCardCount; ++i) {
        if (ptr->controlCards[i] != NULL) { free(ptr->controlCards[i]); }
      }
      free(ptr->controlCards);
      ptr->controlCards = NULL;
    }
  
    free(ptr);
    ptr = NULL;
  }
}
