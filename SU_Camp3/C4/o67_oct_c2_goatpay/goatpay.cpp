#include "goatpay.h"
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define tuu tuple<int, int, int>
const int MxN = 1e6+5;
vector<tuu> graph[MxN];
int cmp[MxN];
void plant_tree(int N, std::vector<int> U, std::vector<int> V, std::vector<int> W, std::vector<int> C) {
  // Your code here
  for (int i = 0; i < U.size(); ++i) {
    graph[U[i]].emplace_back(V[i], i, C[i]);
    graph[V[i]].emplace_back(U[i], i, C[i]);
  }
  for (int i = 0; i < U.size(); ++i) {
    cmp[i] = W[i];
  }
}

int goat_pay(int tu, int tv, int x) {
  // Your code here
  queue<tuu> q;
  q.emplace(tu, tu, 0);
  while (!q.empty()) {
    auto[u, p, val] = q.front(); q.pop();
    if (u == tv) {
      return val;
    }

    for (auto[v, w, c] : graph[u]) {
      if (v == p) continue;
      w = cmp[w];
      if (c == x) q.emplace(v, u, val^w);
      else q.emplace(v, u, val);
    }
  }

  return -1;
}

void update_edge(int id, int d) {
  // Your code here
  cmp[id] = d;
}