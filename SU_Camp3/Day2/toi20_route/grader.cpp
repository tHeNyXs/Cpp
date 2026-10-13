#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>

#include "route.cpp"

int main(int argc, char* argv[]) {
  int N, M;
  assert(scanf("%d %d", &N, &M) == 2);

  std::vector<int> W(M);
  for(int i = 0; i < M; i++){
    assert(scanf("%d",&W[i]) == 1);
  }
  fclose(stdin);

  std::sort(W.begin(), W.end());

  std::vector<std::pair<int,int>> A = route(N, W);

  for(int i = 0; i < M; i++){
    printf("%d %d %d\n", A[i].first, A[i].second, W[i]);
  }
  fclose(stdout);
  return 0;
}
