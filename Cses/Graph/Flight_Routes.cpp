#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, int>
const int N = 1e5+5;
vector<pii> graph[N];
multiset<ll> dist[N];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    while (m--) {
        int u, v; ll w;
        cin >> u >> v >> w;
        graph[u].emplace_back(w, v);
    }

    dist[1].emplace(0);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(0, 1);
    while (!pq.empty()) {
        auto[uw, u] = pq.top(); pq.pop();
        if (dist[u].size() == k && uw > *prev(dist[u].end())) continue;
        for (auto[w, v] : graph[u]) {
            if (dist[v].size() < k) {
                dist[v].emplace(uw+w);
                pq.emplace(uw+w, v);
            }
            else {
                auto it = prev(dist[v].end());
                if (uw+w < *it) {
                    dist[v].erase(it);
                    dist[v].emplace(uw+w);
                    pq.emplace(uw+w, v);
                }
            } 
        }
    }
    
    for (auto i : dist[n]) {
        cout << i << " ";
    }

    return 0;
}