#include <vector>
#include <iostream>
#include <algorithm>
#include "route.h"
using namespace std;
vector<pair<int,int>> route(int n, vector<int> w){
  vector<pair<int, int>> p;
  int len = w.size();
  int over = len - (n-1);
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < i && over; ++j) {
      p.emplace_back(i+1, j);
      over--;
    }
    p.emplace_back(i, i+1);
  }

  return p;
}
