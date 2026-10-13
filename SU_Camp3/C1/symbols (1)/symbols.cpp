#include "symbols.h"

// edit this file as you like

int N;
int Q;

const long long mod = 20232566;
long long arr[80005];

void explore_site(int N, int Q) {
  ::N = N;
  ::Q = Q;

  for (int i = 1; i <= N; ++i) {
    arr[i] = 26;
  }

}
int retrieve_notes(int L, int R) {
  long long val = 1;
  for (int i = L+1; i <= R; ++i) {
    arr[i] -= i-L;
  }

  for (int i = 1; i <= N; ++i) {
    val *= arr[i];
    val %= mod;
  }

  return val%mod;
}