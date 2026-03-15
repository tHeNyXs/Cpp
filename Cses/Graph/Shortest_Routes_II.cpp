#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, int>
#define FOR(i, s, e) for (int i = s; i <= e; ++i)
using namespace std;
const int N = 505;
const ll inf = 1e18;
vector<vector<ll>> dist(N, vector<ll>(N, inf));

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, q; cin >> n >> m >> q;
    FOR(i, 1, n) dist[i][i] = 0;

    while (m--) {
        int u, v; cin >> u >> v;
        ll w; cin >> w;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }

    FOR(k, 1, n) FOR(i, 1, n) FOR(j, 1, n) {
        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
    }
    while (q--) {
        int u, v; cin >> u >> v;
        if (dist[u][v] == inf) cout << "-1\n";
        else cout << dist[u][v] << '\n';
    }
    
    
    return 0;
}