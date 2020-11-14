#pragma once

#include <iostream>
#include <vector>

using namespace std;

class ChoiceAbstract {
  public:
	  void virtual callback(string id, vector<int> params) = 0;
};

