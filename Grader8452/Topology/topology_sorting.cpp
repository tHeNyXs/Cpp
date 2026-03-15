#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<int> graph[n];
    int cnt[n];
    fill(cnt, cnt+n, 0);
    while (m--) {
        int u, v; cin >> u >> v;
        graph[u].emplace_back(v);
        cnt[v]++;
    }

    queue<int> topo, q;
    for (int i = 0; i < n; ++i) {
        if (!cnt[i]) q.emplace(i);
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo.emplace(u);
        for (int v : graph[u]) {
            cnt[v]--;
            if (!cnt[v]) q.emplace(v);
        }
    }

    while (!topo.empty()) {
        cout << topo.front() << " ";
        topo.pop();
    }

    return 0;
}