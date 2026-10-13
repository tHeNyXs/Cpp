#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int p[N];

struct Edge {
    int u, v, w;

    Edge(int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    };

    bool operator<(const Edge &a) const {
        return w < a.w;
    };
};

int find(int u) {
    if (p[u] == u) return u;
    return p[u] = find(p[u]);
}



int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, s, e;
    cin >> n >> m >> s >> e;
    vector<Edge> ed;
    while (m--) {
        int u, v, w; cin >> u >> v >> w;
        ed.emplace_back(Edge(u, v, w));
    }
    sort(ed.begin(), ed.end());

    int ans = INT_MAX;
    for (int t = 1; t <= 200; ++t) {
        auto it = lower_bound(ed.begin(), ed.end(), Edge(0, 0, t));
        iota(p, p+N, 0);
        int maxx = -1;
        while (find(s) != find(e) && it != ed.end()) {
            auto[u, v, w] = *it; it++;
            int pu = find(u);
            int pv = find(v);
            p[pu] = pv;
            if (find(s) == find(e)) {
                ans = min(ans, w-t);
                break;
            }
        }
        
    }
    cout << ans;
}