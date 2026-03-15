#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> graph[N];
vector<int> path(N, 0);
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    
    queue<int> q;
    q.emplace(1);
    path[1] = -1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        // if (path[u].size()) continue;
        for (int v : graph[u]) {
            if (path[v]) continue;
            path[v] = u;
            q.emplace(v);
        }
    }
    // for (int i = 1; i <= n; ++i) {
    //     cout << "I : ";
    //     for (int j : path[i]) {
    //         cout << j << " ";
    //     }
    //     cout << '\n';
    // }
    if (path[n] == 0) cout << "IMPOSSIBLE";
    else {
        vector<int> ans;
        while (n != -1) {
            ans.emplace_back(n);
            n = path[n];
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for (int i : ans) cout << i << " ";
    }


    return 0;
}