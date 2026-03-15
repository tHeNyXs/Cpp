#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, int>
#define pi pair<pii, bool>
const int N = 1e5+5;
const ll inf = 1e18;
vector<pii> graph[N];
vector<vector<ll>> dist(N, vector<ll>(2, inf));
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v; ll w;
        cin >> u >> v >> w;
        graph[u].emplace_back(w, v);
    }

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    dist[1][0] = dist[1][1] = 0;
    pq.emplace(make_pair(0, 1), false);
    while (!pq.empty()) {
        auto [temp, ticket] = pq.top(); pq.pop();
        int u = temp.second; ll uw = temp.first;
        if (uw > dist[u][ticket]) continue;
        for (auto[w, v] : graph[u]) {
            if (!ticket && dist[u][0] + (w/2) < dist[v][1]) {
                dist[v][1] = dist[u][0] + (w/2);
                pq.emplace(make_pair(dist[v][1], v), true);
            }
            if (dist[u][ticket] + w < dist[v][ticket]) {
                dist[v][ticket] = dist[u][ticket] + w;
                pq.emplace(make_pair(dist[v][ticket], v), ticket);
            }
        }
    }
    cout << min(dist[n][0], dist[n][1]);

    return 0;
}