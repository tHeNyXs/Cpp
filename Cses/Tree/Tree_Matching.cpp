#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
vector<int> graph[N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    vector<bool> single(n+1, false);
    vector<bool> vis(n+1, false);
    for (int i = 1; i <= n; ++i) {
        if (graph[i].size() == 1) single[i] = true;
    }
    

    for (int u = 1; u <= n; ++u) {
        for (auto v : graph[u]) {
            if (single[v]) {
                vis[u] = true;
                break;
            }
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) cnt++;
    }
    cout << cnt;

    return 0;
}