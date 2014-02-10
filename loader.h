#ifndef LOADER_H
#define LOADER_H

#include <string>
#include "cluster.h"
#include "data.h"
#include "model.h"
#include "config.h"

class Loader {
   public:
      Loader();
      Loader(const string, const string);
      void init(const string, const string);
      bool load_in_data(const int);
      bool load_in_hdphmm_model(Config*, const int);
      int get_num_clusters() {return cluster_num;}
      string convert_num_to_label(const int num);
      vector<Cluster*> get_models() {return clusters;}
      Data* get_data() {return data;}
      ~Loader();
   private:
      string fname;
      string fname_data;
      vector<Cluster*> clusters;
      Data* data;
      int cluster_num;
      int data_num; 
      Model* _model;
};

#endif
