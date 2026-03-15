#include <bits/stdc++.h>
#define FOR(i, s, e) for (int i = s; i <= e; ++i)
#define ll long long
#define pii pair<pair<int, int>, ll>
using namespace std;
const int N = 25e2+5;
const ll inf = -1e18;
vector<pii> edge;
vector<ll> dist(N, inf);
vector<int> p(N, 0);
vector<int> c(N, 0);
vector<int> graph[N];
vector<bool> vis(N, false);
int n, m;

bool dfs(int u) {
    if (u == n) return true;
    bool flag = false;
    vis[u] = true;
    for (int v : graph[u]) {
        if (vis[v]) continue;
        flag |= dfs(v);
    }
    return flag;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    iota(p.begin(), p.end(), 0);
    iota(c.begin(), c.end(), 0);
    FOR(i, 1, m) {
        int u, v; ll w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v);
        edge.emplace_back(make_pair(u, v), w);
    }

    dist[1] = 0;
    unordered_map<int, bool> cycle;
    for (int i = 1; i <= m; ++i) {
        for (auto[t, w] : edge) {
            int u = t.first, v = t.second;
            if (dist[u] == inf) continue;
            dist[v] = max(dist[v], dist[u]+w);
        }
    }

    for (int i = 1; i <= m; ++i) {
        for (auto[t, w] : edge) {
            int u = t.first, v = t.second;
            if (dist[u] == inf) continue;
            ll prev = dist[v];
            dist[v] = max(dist[v], dist[u]+w);
            if (prev != dist[v]) cycle[v] = true;
        }
    }

    // for (int i : cycle) cout << i << " ";
    // cout << '\n';

    for (auto t : cycle) {
        if (t.second == false) continue;
        int u = t.first;
        vis.clear();
        if (!dfs(u)) continue;
        cout << "-1\n";
        return 0;
    }

    // if (prev != um.size()) cout << -1;
    // else cout << dist[n];
    cout << dist[n];


    return 0;
}