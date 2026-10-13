#include <bits/stdc++.h>
using namespace std;

void find_h(int u, int *h, vector<vector<int>> &graph) {
    for (int v : graph[u]) {
        find_h(v, h, graph);
        h[u] = h[v]+1;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int q; cin >> q;
    while (q--) {
        int n; cin >> n;
        int a[n+1]; for (int i = 1; i <= n; ++i) cin >> a[i];
        vector<vector<int>> graph(n+1);
        for (int i = 1; i < n; ++i) {
            int u, v; cin >> u >> v;
            graph[u].emplace_back(v);
        }
        int h[n+1]; = {0};
        find_h(1, h, graph);
        for (int )

    }

    return 0;
}