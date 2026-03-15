#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
const int N = 25e2+5;
const ll inf = 1e18;
vector<ll> dist(N, inf);
vector<int> p(N);
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<pair<pii, ll>> edge;
    for (int i = 0; i < m; ++i) {
        int u, v; ll w;
        cin >> u >> v >> w;
        edge.emplace_back(make_pair(u, v), w);
        p[v] = u;
    }
    dist[1] = 0;
    for (int j = 0; j < n; ++j) {
    for (int i = 0; i < m; ++i) {
        auto[u, v] = edge[i].first;
        auto w = edge[i].second;
        if (dist[u]+w < dist[v]) {
            dist[v] = dist[u]+w;
            p[v] = u;
        }
    }
    }
    
    int cycle = -1;
    for (int i = 0; i < m; ++i) {
        auto[u, v] = edge[i].first;
        auto w = edge[i].second;
        if (dist[u]+w < dist[v]) {
            dist[v] = dist[u]+w;
            p[v] = u;
            cycle = v;
            break;
        }
    }

    if (cycle == -1) cout << "NO";
    else {
        for(int i=0;i<n;i++) cycle = p[cycle];
        cout << "YES\n";
        vector<int> ans;
        ans.emplace_back(cycle);
        int temp = p[cycle];
        while (temp != cycle) {
            ans.emplace_back(temp);
            temp = p[temp];
        }
        ans.emplace_back(temp);
        reverse(ans.begin(),ans.end());
        for (int i : ans) cout << i << " ";
    }

    return 0;
}