#ifndef DECODER_H
#define DECODER_H

#include <string>
#include "loader.h"
#include "calculator.h"
#include "model.h"
#include "config.h"

using namespace std;

class Decoder {
   public:
      Decoder(const string, const string, const int);
      bool load_data();
      bool load_hdphmm_model(Config*, const int);
      void compute_forward_backward();
      void compute_posterior();
      void compute_forward_prob();
      void compute_backward_prob();
      void save_posterior(const string); 
      void save_posterior_bin(const string); 
      void compute_single_state();
      ~Decoder();
   private:
      int dim;
      Loader loader;
      vector<Cluster*> clusters;
      Data* data;
      vector<vector<float> > posteriors;
      string fn_model;
      string fn_data;
      Calculator calculator;
};

#endif
