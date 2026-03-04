#include <bits/stdc++.h>
using namespace std;

#define ll int
const ll inf = INT_MAX;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll n, m; cin >> n >> m;
    vector<pair<ll, ll>> graph[n];
    while (m--) {
        ll u, v, w; cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
    }
    ll start; cin >> start;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.emplace(0, start);
    vector<ll> dist(n, inf);
    vector<vector<ll>> path(n);
    for (int i = 0; i < n; ++i) path[i].emplace_back(i);
    dist[start] = 0;
    while (!pq.empty()) {
        auto [uw, u] = pq.top(); pq.pop();

        if (uw > dist[u]) continue;

        for (auto[v, w] : graph[u]) {
            if (dist[v] <= dist[u]+w) continue;
            dist[v] = dist[u]+w;
            path[v] = path[u];
            path[v].emplace_back(v);
            pq.emplace(dist[v], v);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i == start) continue;
        cout << start << " -> " << i << " (";
        if (dist[i] == inf) cout << "inf)\n";
        else {
            cout << dist[i] << ") ";
            for (int j : path[i]) {
                cout << j << " ";
            }
            cout << '\n';
        }
    }

    return 0;
}