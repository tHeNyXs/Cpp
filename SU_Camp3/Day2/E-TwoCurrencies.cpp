#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pi pair<pii, int>
const int N = 55;
const int inf = 2e9;

vector<pi> graph[N];
vector<vector<int>> dist(N, vector<int>(N*50, inf));
pii change[N];


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, s;
    cin >> n >> m >> s;

    while (m--) {
        int u, v, a, b;
        cin >> u >> v >> a >> b; // a = silver, b = time
        graph[u].emplace_back(pi(pii(a, b), v));
        graph[v].emplace_back(pi(pii(a, b), u));
    }
    for (int i = 1; i <= n; ++i) {
        cin >> change[i].first >> change[i].second;
    }

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.emplace(pi(pii(s, 0), 1));
    while (!pq.empty()) {
        auto[_, u] = pq.top(); pq.pop();
        auto[silver, time] = _;
        if (time > dist[u][silver]) continue;
        dist [u][silver] = time;
        for (auto[_, v] : graph[u]) {
            auto[a, b] = _;
            // if (dist[silver+change[v]][u]+time)
        }
    }

    return 0;
}