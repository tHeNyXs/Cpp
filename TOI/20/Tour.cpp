#include <bits/stdc++.h>
using namespace std;
#define int long long
#define tu tuple<int, int, int>
#define pii pair<int, int>
int n, m, l;
const int N = 2e5+5;
vector<tu> graph[N];
vector<pii> p;

void dfs(int u, int s1, int s2) {
    if (u == n) {
        p.emplace_back(s1, s2);
        return;
    }
    for (auto[v, s, w] : graph[u]) {
        if (s == 1) dfs(v, s1+w, s2);
        else dfs(v, s1, s2+w);
    }
}

int dist(int x1, int y1, int x2, int y2) {
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m >> l;
    for (int i = 1; i <= l; ++i) {
        int x; cin >> x;
    }
    while (m--) {
        int u, v, s, w;
        cin >> u >> v >> s >> w;
        graph[u].emplace_back(v, s, w);
    }

    dfs(1, 0, 0);
    sort(p.begin(), p.end());
    // for (auto[x, y] : p) {
    //     cout << x << " : " << y << '\n';
    // }
    queue<pii> q;
    set<pii> s;
    q.emplace(p[0]);
    s.emplace(p[0].second, p[0].first);
    int d = 1e18;
    for (int i = 1; i < p.size(); ++i) {
        auto[x1, y1] = p[i];

        while (!q.empty()) {
            auto[x2, y2] = q.front();
            if ((x1-x2)*(x1-x2) > d) {
                q.pop();
                s.erase({y2, x2});
            }
            else break;
        }

        auto it1 = s.lower_bound({y1-sqrt(d), -1e18});
        auto it2 = s.upper_bound({y1+sqrt(d), 1e18});

        for (auto it = it1; it != it2; ++it) {
            auto[y2, x2] = *it;
            d = min(d, dist(x1, y1, x2, y2));
        }

        q.emplace(p[i]);
        s.emplace(y1, x1);
    }
    cout << d;

    return 0;
}