#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> p(N);

int dsu(int a) {
    if (p[a] == a) return a;
    return p[a] = dsu(p[a]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    iota(p.begin(), p.end(), 0);
    while (m--) {
        int u, v; cin >> u >> v;
        int pu = dsu(u), pv = dsu(v);
        if (pu != pv) p[pu] = pv;
    }

    int cnt = 0;
    int ref = dsu(1);
    vector<pair<int, int>> ans;
    for (int i = 2;  i <= n; ++i) {
        int pu = dsu(i);
        if (pu != ref) {
            cnt++;
            ans.emplace_back(ref, pu);
            p[pu] = ref;
        }
    }
    cout << ans.size() << '\n';
    for (auto[u, v] : ans) {
        cout << u << " " << v << '\n';
    }


    return 0;
}