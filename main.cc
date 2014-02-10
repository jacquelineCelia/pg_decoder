/* -*- C++ -*-
 *
 * Copyright (c) 2014
 * Spoken Language Systems Group
 * MIT Computer Science and Artificial Intelligence Laboratory
 * Massachusetts Institute of Technology
 *
 * All Rights Reserved

*	FILE: main.cc 
*										                            *
*   				      				                            *
*   Chia-ying (Jackie) Lee <chiaying@csail.mit.edu>					*
*   Feb 2014							                            *
*********************************************************************/
#include <iostream>
#include <string>
#include <cstdlib>

#include "config.h"
#include "decoder.h"

using namespace std;

void print_usage() {
   cout << "./decode_to_pg -i model_file -d data_file"
     << " -o output_file -d dim -m mode[1: forward backward"
     << " 2: single state decoding] -t threshod"
     << " -a model_type[0: dphmm, 1: bmodel, 2:hdphmm] "
     << " -b output in binary form[1:yes, 0:no] -config config" << endl;
}

int main(int argc, char* argv[]) {
   if (argc != 19) {
      print_usage();
      return 1;
   }
   string fname_model = argv[2];
   string fname_data = argv[4];
   string fname_out = argv[6];
   int dim = atoi(argv[8]);
   int mode = atoi(argv[10]);
   int threshold = atoi(argv[12]);
   int model_type = atoi(argv[14]);
   int binary_out = atoi(argv[16]);
   string fn_config = argv[18];

   Config config;
   if (!config.Load(fn_config)) {
       cout << "Cannot load configuration file." 
            << " Check " << fn_config << endl;
   }

   Decoder decoder(fname_model, fname_data, dim);
   if (model_type == 2) {
       if (!decoder.load_hdphmm_model(&config, threshold)) {
           cout << "Model file cannot be opened. " 
                << "Check " << fname_model << "..." << endl;
           return -1;
       }
       else {
           cout << "model loaded" << endl;
       }
   }
   else {
       cout << "Can only do hdphmm model type with this program." << endl;
       return -1;
   }
   if (!decoder.load_data()) {
      cout << "Data file cannot be opened. "
        << "Check " << fname_data << "..." << endl;
      return -1;
   }
   else {
      cout << "data loaded" << endl;
   }
   if (mode == 1) {
      decoder.compute_forward_backward();
      decoder.compute_posterior();
   }
   else if (mode == 2) {
      cout << "model 2" << endl;
      decoder.compute_single_state();
      cout << "single state computed" << endl;
      decoder.compute_posterior();
      cout << "pg computed" << endl;
   }
   cout << "ready to save" << endl;
   if (binary_out) {
       decoder.save_posterior_bin(fname_out);
   }
   else {
       decoder.save_posterior(fname_out);
   }
   cout << "saved" << endl;
   return 0;
}
