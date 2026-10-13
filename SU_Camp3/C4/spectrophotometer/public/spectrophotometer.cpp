#include "spectrophotometer.h"
#include <bits/stdc++.h>
using namespace std;

void sort_lasers(int N) {
  int len = 3*N;
  int start = 0;
  int next = start+1;
  vector<bool> m(len, false);
  int cnt = 1;
  m[0] = true;
  while (cnt < N) {
    if (call_swap(start, next)) {
      cnt++;
      m[next] = true;
    }
    else call_swap(start, next);
    next++;
  }

  for (int i = 1; i < N; ++i) {
    if (!m[i]) {
      for (int j = i+1; j < len; ++j) {
        if (m[j]) {
          call_swap(i, j);
          m[j] = false;
          break;
        }
      }
    }
  }

  m.clear();
  cnt = 1;
  start = N;
  next = N+1;
  m[N] = true;
  while (cnt < N) {
    if (call_swap(start, next)) {
      cnt++;
      m[next] = true;
    }
    else call_swap(start, next);
    next++;
  }

  for (int i = N; i < 2*N; ++i) {
    if (!m[i]) {
      for (int j = i+1; j < len; ++j) {
        if (m[j]) {
          call_swap(i, j);
          m[j] = false;
          break;
        }
      }
    }
  }

}