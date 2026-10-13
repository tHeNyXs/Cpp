#include "spectrophotometer.h"
#include <bits/stdc++.h>
using namespace std;

void sort_lasers(int N) {
  int len = 3*N;
  int start, next;
  start = 0, next = 1;
  while (next < len) {
    if (!call_swap(start, next)) {
        start++;
        next++;
    }
    else next++;
  }
  start = 0; next = 1;
  while (next < len-N) {
    if (!call_swap(start, next)) {
        start++;
        next++;
    }
    else next++;
  }

}