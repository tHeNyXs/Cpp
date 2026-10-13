#include <bits/stdc++.h>
using namespace std;
#define tu tuple<int, int, int>
const int N = 1e4+5;
vector<vector<int>> graph(N);
int main() {
    // ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<tu> edge;
    for (int i = 1; i < n; ++i) {
        int u, v, w; cin >> u >> v >> w;
        edge.emplace_back(w, u, v);
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    sort(edge.begin(), edge.end(), greater<tu>());

    int ans = 0;
    vector<bool> vis(n+1, false);
    for (int i = 0; i < n-1; ++i) {
        auto[w, u, v] = edge[i];
        if (vis[u] && vis[v]) continue;
        ans += w;
        vis[u] = true;
        vis[v] = true;
        for (int j : graph[u]) {
            if (vis[j]) continue;
            vis[j] = true;
        }
        for (int j : graph[v]) {
            if (vis[j]) continue;
            vis[j] = true;
        }
        // cout << "W : " << w << " | U : " << u << " | V : " << v << '\n';
    }
    cout << ans;

    return 0;
}