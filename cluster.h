#ifndef CLUSTER_H
#define CLUSTER_H

#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>

#include "bound.h"
#include "segment.h"
#include "prob_list.h"
#include "gmm.h"
#include "config.h"
#include "toolkit.h"

using namespace std;

class Cluster {
 public:
  Cluster() {};
  Cluster(Config*);
  Cluster(Config*, int);
  Cluster(Config*, int, int, int);
  Cluster(Cluster&);
  Cluster& operator+= (Cluster&);
  // Access functions
  void set_transition_probs(vector<vector<float> >&);
  void set_emission(GMM&, int);
  void set_emissions(vector<GMM>&);
  void set_id(int id) {_id = id;}
  void set_is_fixed(bool is_fixed) {_is_fixed = is_fixed;}
  int id() {return _id;}
  int state_num() {return _state_num;}
  float transition_prob(int i, int j) {return _transition_probs[i][j];}
  bool is_fixed() const {return _is_fixed;}
  vector<vector<float> > transition_probs() {return _transition_probs;}
  GMM& emission(int index) {return _emissions[index];}
  Config* config() {return _config;}
  // Tool
  float** ConstructSegProbTable(vector<Bound*>&);
  float ComputeSegmentProb(Segment*);
  ProbList<int>** MessageBackwardForASegment(Segment*);
  void Plus(Segment*);
  void Minus(Segment*);
  void Save(ofstream&);
  void Load(ifstream&);
  void PreCompute(float**, int);
  int FindNextBoundary(vector<Bound*>&, int);

  float get_forward_prob(const int i, const int j) {return forward[i][j];}
  float get_backward_prob(const int i, const int j) {return backward[i][j];}

  void set_forward_prob(const int, const int, const float);
  void set_backward_prob(const int, const int, const float);

  void init_prob_table(const int);
  float compute_state_prob(const int, const float*);

  float get_trans_prob(const int i, const int j) const {return _transition_probs[i][j];}

  float get_prior_prob() const {return -log(_config -> weak_limit());} 

  GMM* GMM_ptr(int i) {return &_emissions[i];}
  ~Cluster();
 protected:
  ToolKit _toolkit;
  bool _is_fixed;
  int _id;
  int _state_num;

  vector<vector<float> > forward;
  vector<vector<float> > backward;
  // Save in Log
  vector<vector<float> > _transition_probs;
  vector<GMM> _emissions;
  Config* _config;
};

#endif
