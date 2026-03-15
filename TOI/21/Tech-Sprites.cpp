#include <bits/stdc++.h>
using namespace std;
#define pii pair<pair<int, int>, int> 
const int N = 1e6+5;
vector<int> p(N);

int dsu(int a) {
    if (p[a] == a) return a;
    return p[a] = dsu(p[a]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    iota(p.begin(), p.end(), 0);
    int n, m; cin >> n >> m;
    vector<pii> ts(n+1);
    for (int i = 1; i <= n; ++i) cin >> ts[i].first.first >> ts[i].first.second, ts[i].second = i;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        int ru = dsu(u);
        int rv = dsu(v);
        if (ru != rv) p[ru] = rv;
    }

    // for (int i = 1; i <= n; ++i) {
    //     cout << p[i] << " ";
    // } cout << '\n';

    sort(ts.begin()+1, ts.end());
    // for (int i = 1; i <= n; ++i) {
    //     cout << dsu(p[ts[i].second]) << " ";
    // }

    vector<bool> vis(n+1, false);
    int prev = dsu(ts[1].second);
    vis[prev] = true;
    int cnt = 0;
    for (int i = 2; i <= n; ++i) {
        int now = dsu(ts[i].second);
        // cout << "I : " << i << " | Now : " << now << " | Prev : " << prev << '\n';
        if (vis[now] && now != prev) {
            p[now] = prev;
            now = prev;
            cnt++;
        }
        vis[now] = true;
        prev = now;
    }

    cout << cnt;

    return 0;
}