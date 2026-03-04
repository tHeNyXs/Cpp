#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<int> graph[n+1];
    vector<int> cnt(n+1, 0);
    while (m--) {
        int u, v;
        cin >> u >> v;
        graph[u].emplace_back(v);
        cnt[v]++;
    }

    vector<int> dist(n+1, 0);
    queue<int> q;
    for (int i = 1; i <= n; ++i) if (!cnt[i]) q.emplace(i);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : graph[u]) {
            dist[v] = max(dist[v], dist[u]+1);
            cnt[v]--;
            if (cnt[v] == 0) q.emplace(v);
        }
    }

    cout << *max_element(dist.begin(), dist.end());

    return 0;
}