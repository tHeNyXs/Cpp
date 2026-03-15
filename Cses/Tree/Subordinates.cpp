#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
vector<int> graph[N];
vector<int> child(N, 0);

int dfs(int u) {
    for (int v : graph[u]) {
        child[u] += child[v] + dfs(v) + 1;
    }
    return child[u];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 2; i <= n; ++i) {
        int p; cin >> p;
        graph[p].emplace_back(i);
    }

    dfs(1);

    for (int i = 1; i <= n; ++i) {
        cout << child[i] << " ";
    }

    return 0;
}