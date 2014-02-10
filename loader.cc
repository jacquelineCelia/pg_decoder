/* -*- C++ -*-
 *
 * Copyright (c) 2014
 * Spoken Language Systems Group
 * MIT Computer Science and Artificial Intelligence Laboratory
 * Massachusetts Institute of Technology
 *
 * All Rights Reserved

*	FILE: loader.cc 
*										                            *
*   				      				                            *
*   Chia-ying (Jackie) Lee <chiaying@csail.mit.edu>					*
*   Feb 2014							                            *
*********************************************************************/
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <cstdlib>

#include "loader.h"
#include "cluster.h"
#include "util.h"

#define LTPI 1.8378770664093454835606594728112 

using namespace std;

Loader::Loader() {
}

Loader::Loader(const string s_filename, \
  const string s_filename_data) {
   fname = s_filename;
   fname_data = s_filename_data;
}

void Loader::init(const string s_filename, \
  const string s_filename_data) {
   fname = s_filename;
   fname_data = s_filename_data;
}

bool Loader::load_in_hdphmm_model(Config* config, const int threshold) {
    _model = new Model(config); 
    _model -> LoadSnapshot(fname);
    clusters = _model -> clusters();
    return true;
}

bool Loader::load_in_data(const int dim) {
   data = new Data(dim); 
   ifstream fdata(fname_data.c_str(), ios::binary);
   if (!fdata.good()) {
      cout << fname_data << " cannot be opened." << endl;
      return false;
   }
   fdata.seekg(0, ios_base::end);
   int data_len = (int) fdata.tellg();
   fdata.seekg(0, ios_base::beg);
   int counter = 0;
   cout << "loading data..." << endl;
   while (fdata.tellg() < data_len) {
      float* frame_i = new float[dim];
      fdata.read(reinterpret_cast<char*> (frame_i), sizeof(float) * dim);
      data -> insert_frame(frame_i);
      counter++;
   }
   data -> set_frame_num();
//   data -> show();
   fdata.close();
   return true;
}

string Loader::convert_num_to_label(const int s_num) {
   string label;
   int num = s_num;
   int d = num % 26 + 97;
   char t = d;
   label += t; 
   num /= 26;
   while (num > 0) {
      d = num % 26 + 97;
      t = d;
      label += t; 
      num /= 26;
   }
   return label;
}


Loader::~Loader() {
   // delete clusters
   // for (unsigned int c = 0; c < clusters.size(); ++c) {
   //    delete clusters[c];
   // }
   delete _model;
}
