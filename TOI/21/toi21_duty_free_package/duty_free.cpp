#include <vector>
#include <bits/stdc++.h>
using namespace std;

// you can write more function here
vector<int> p;
vector<int> lazy;
int timer;

int find(int u) {
  if (lazy[u] != timer) {
    lazy[u] = timer;
    p[u] = u;
    return u;
  }
  if (p[u] == u) return u;
  return p[u] = find(p[u]);
}


int minimum_bag_rearrangement_time(std::vector<int> max_allowed_positions) {
  //write your code here
  int cnt = 0;
  int len = max_allowed_positions.size();
  p.resize(len+1);
  lazy.resize(len+1, 0);
  iota(p.begin(), p.end(), 0);
  for (auto i : max_allowed_positions) {
    int pu = find(i);
    if (pu == 0) {
      cnt++;
      timer++;
      pu = find(i);
    }
    p[pu] = find(pu-1);
  }
  return cnt;
}