/* -*- C++ -*-
 *
 * Copyright (c) 2014
 * Spoken Language Systems Group
 * MIT Computer Science and Artificial Intelligence Laboratory
 * Massachusetts Institute of Technology
 *
 * All Rights Reserved

*	FILE: data.cc 				                                *
*										                            *
*   				      				                            *
*   Chia-ying (Jackie) Lee <chiaying@csail.mit.edu>					*
*   Feb 2014							                            *
*********************************************************************/
#include <iostream>
#include "data.h"

Data::Data() {
}

Data::Data(const int s_dim) {
   dim = s_dim;
}

void Data::insert_frame(const float* frame_i) {
   frames.push_back(frame_i);
}

void Data::set_frame_num() {
   frame_num = (int) frames.size();
}

void Data::show() {
   for (int i = 0; i < frame_num; ++i) {
      cout << "frame[ " << i << " ]: ";
      for (int j = 0; j < dim; ++j) {
          cout << "[" << j << "] " << frames[i][j] << " "; 
      }
      cout << endl;
   }
}

Data::~Data() {
   for (int i = 0; i < frame_num; ++i) {
      delete[] frames[i];
   }
}
