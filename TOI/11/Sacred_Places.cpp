#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
vector<int> p(N);
#define ll long long

struct Edge {
    int u, v;
    ll w;
};

bool cmp(const Edge a, const Edge b) {
    return a.w > b.w;
}

int findP(int a) {
    if (p[a] == a) return a;
    return p[a] = findP(p[a]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    iota(p.begin(), p.end(), 0);
    vector<Edge> e;
    while (m--) {
        Edge temp;
        cin >> temp.u >> temp.v >> temp.w;
        e.emplace_back(temp);
    }

    sort (e.begin(), e.end(), cmp);

    int cnt = 0;
    ll ans = 0;
    for (int pt = 0; pt < e.size() && cnt < n-1; ++pt) {
        int u = e[pt].u, v = e[pt].v;
        ll w = e[pt].w;
        int pu = findP(u), pv = findP(v);
        if (pu == pv) continue;
        ans += w-1;
        cnt++;
        p[pu] = pv;
    }
    cout << ans;

    return 0;
}