#include <bits/stdc++.h>
using namespace std;
#define tu tuple<int, int, int>
const int N = 1e6+5;
int p[N];
int vis[N];

int find(int u) {
    if (p[u] == u) return p[u];
    return p[u] = find(p[u]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    iota(p, p+N, 0);
    vector<tu> tech;
    
    for (int i = 1; i <= n; ++i) {
        int a, b; cin >> a >> b;
        tech.emplace_back(a, b, i);
    }
    
    while (m--) {
        int u, v; cin >> u >> v;
        int pu = find(u), pv = find(v);
        if (pu == pv) continue;
        p[pu] = pv;
    }

    sort(tech.begin(), tech.end());
    map<int, int> cnt;
    for (int i = 1; i <= n; ++i) {
        int idx = find(i);
        cnt[idx]++;
    }

    int prev = find(get<2>(tech[0]));
    cnt[prev]--;
    int ans = 0;

    // for (auto[x, y, i] : tech) {
    //     cout << find(i) << ' ';
    // }
    // cout << '\n';

    // for (auto i : cnt) {
    //     cout << i.first << " : " << i.second << '\n';
    // }

    for (int i = 1; i < tech.size(); ++i) {
        auto[a, b, idx] = tech[i];
        idx = find(idx);
        prev = find(prev);
        if (idx != prev && cnt[prev]) {
            // cout << "idx : " << idx << " | prev : " << prev << " | Left : " << cnt[prev] << '\n';
            cnt[idx] += cnt[prev];
            p[prev] = idx;
            ans++;
        }
        cnt[idx]--;

        prev = idx;
    }

    cout << ans;

    return 0;
}