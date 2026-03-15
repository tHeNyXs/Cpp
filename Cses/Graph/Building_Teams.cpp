#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> graph[N];
vector<int> team(N, 0);
vector<bool> vis(N, false);
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    bool flag = false;
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        team[i] = 1;
        queue<int> q;
        q.emplace(i);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            vis[u] = true;
            for (int v : graph[u]) {
                if (team[v] == team[u]) {
                    flag = true;
                    break;
                }
                if (vis[v]) continue;
                team[v] = (team[u]%2)+1;
                q.emplace(v);
            }
        }
        if (flag) break;
    }

    if (flag) cout << "IMPOSSIBLE";
    else {
        for (int i = 1; i <= n; ++i) {
            cout << team[i] << " ";
        }
    }

    return 0;
}