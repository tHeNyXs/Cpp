#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<vector<int>> graph(N);
pair<int, int> par[N];
int cnt = 0;

void dfs(int u, int p) {
    par[u].first = cnt++;
    for (int v : graph[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    par[u].second = cnt++;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, t; cin >> n >> m >> t;
    while (m--) {
        int u, v; cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    for (int i = 1; i <= t; ++i) {
        int u; cin >> u;
        dfs(u, u);
    }

    // for (int i = 1; i <= n; ++i) {
    //     cout << "I : " << i << " | pair : " << par[i].first << ", " << par[i].second << '\n';
    // }

    int q; cin >> q;
    while (q--) {
        int u, v; cin >> u >> v;
        cout << (par[v].first < par[u].first && par[u].second < par[v].second ? "YES\n" : "NO\n");
    }

    return 0;
}