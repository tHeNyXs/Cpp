#include "2eggs.h"

int height_threshold(int N, int Q) {
  int egg = 1;
  if (N == 2) {
    if (drop_egg(egg, 1)) return 1;
    else return 2;
  }
  else if (N == 4) {
    if (drop_egg(1, 2)) {
      if (drop_egg(2, 1)) return 1;
      else return 2;
    }
    else if (drop_egg(2, 3)) return 3;
    else return 4;
  }
  int i = 10;
  while (i <= N) {
    if (drop_egg(1, i)) {
      for (int j = i-9; j < i; ++j) {
        if (drop_egg(2, j)) return j;
      }
      return i;
    }
    i += 10;
  }
  return N;
  
}