#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, int>
const int N = 1e5+5;
const int mod = 1e9+7;
const ll inf = 1e18;
vector<pii> graph[N];
vector<ll> cnt(N, 0);
vector<ll> dist(N, inf);
vector<vector<int>> path(N, vector<int>(2, 0));
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    while (m--) {
        int u, v; ll w;
        cin >> u >> v >> w;
        graph[u].emplace_back(w, v);
    }

    dist[1] = path[1][0] = path[1][0] = 0;
    cnt[1] = 1;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(dist[1], 1);
    while (!pq.empty()) {
        auto[uw, u] = pq.top(); pq.pop();
        if (uw > dist[u]) continue;
        for (auto[w, v] : graph[u]) {
            if (dist[u]+w < dist[v]) {
                dist[v] = dist[u]+w;
                path[v][0] = path[u][0]+1;
                path[v][1] = path[u][1]+1;
                cnt[v] = cnt[u];
                pq.emplace(dist[v], v);
            }
            else if (dist[u]+w == dist[v]) {
                path[v][0] = min(path[v][0], path[u][0]+1);
                path[v][1] = max(path[v][1], path[u][1]+1);
                cnt[v] += cnt[u];
                cnt[v] %= mod;
            }
        }
    }

    cout << dist[n] << " " << cnt[n]%mod << " " << path[n][0] << " " << path[n][1];


    return 0;
}