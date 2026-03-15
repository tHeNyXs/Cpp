#include <bits/stdc++.h>
#define pii pair<ll, int>
#define ll long long
using namespace std;
const int N = 1e5+5;
const ll inf = 1e18;
vector<pii> graph[N];
vector<ll> dist(N, inf);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    while (m--) {
        int u, v; cin >> u >> v;
        ll w; cin >> w;
        graph[u].emplace_back(w, v);
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[1] = 0;
    pq.emplace(dist[1], 1);
    while (!pq.empty()) {
        auto[uw, u] = pq.top(); pq.pop();
        if (uw > dist[u]) continue;
        for (auto[w, v] : graph[u]) {
            if (dist[v] <= dist[u]+w) continue;
            dist[v] = dist[u]+w;
            pq.emplace(dist[v], v);
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << dist[i] << " ";
    }

    return 0;
}