#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, ll>
#define pi pair<pair<ll, vector<bool>>, int>

const int N = 5e4+5;
const int M = 1e5+5;
const ll inf = 1e18;

vector<pii> graph[N];
vector<int> color(N);
int n, m, k, s, t;
vector<int> fp(N, 0);
vector<ll> dist(N, inf);
vector<int> path[N];
ll priceFp[3];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m >> k >> s >> t;
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        ll w;
        cin >> u >> v >> w >> c;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
        color[u] = color[v] = c;
    }

    for (int i = 1; i <= k; ++i) cin >> priceFp[i];
    for (int i = 1; i <= k; ++i) {
        int a; cin >> a;
        while (a--) {
            int u; cin >> u;
            fp[u] = i;  
        }
    }
    for (int i = 1; i <= n; ++i) cout << fp[i] << " ";
    cout << '\n';    

    priority_queue<pi, vector<pi>, greater<pi>> pq; // {pair<value, freepass>, u}
    dist[s] = 0;
    pq.emplace(pi{{0LL, vector<bool>(3, false)}, s});
    while (!pq.empty()) {
        auto[temp, u] = pq.top(); pq.pop();
        auto[value, free] = temp;
        for (auto[v, w] : graph[u]) {
            if (free[fp[color[v]]]) w = 0;
            if (value+w > dist[v]) continue;
            dist[v] = value + w;
            // path[v] = path[u];
            // path[v].emplace_back(v);
            pq.emplace(pi{{dist[v], free}, v});

            if (fp[v]) {
                vector<bool> te = free;
                te[fp[v]] = true;
                pq.emplace(pi{{priceFp[fp[v]] + value, te}, v});
            }
        }
        // cout << "U : " << u << " | free : " << free[0] << free[1] << free[2] << '\n';
    }

    for (int i = 1; i <= n; ++i) {
        cout << dist[i] << " ";
    }

    return 0;
}
/*
4 4 1 1 4
1 2 4 0
1 3 4 0
2 3 12 1
3 4 10 1
6
1
2
*/