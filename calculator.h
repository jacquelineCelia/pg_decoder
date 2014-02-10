/* -*- C++ -*-
 *
 * Copyright (c) 2014
 * Spoken Language Systems Group
 * MIT Computer Science and Artificial Intelligence Laboratory
 * Massachusetts Institute of Technology
 *
 * All Rights Reserved

*	FILE: calculator.h 
*										                            *
*   				      				                            *
*   Chia-ying (Jackie) Lee <chiaying@csail.mit.edu>					*
*   Feb 2014							                            *
*********************************************************************/
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <vector>

using namespace std;

class Calculator {
   public:
      Calculator();
      float sum_logs(vector<float>);
      float find_log_max(vector<float>);
      ~Calculator();
};

#endif
