#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+5;
vector<int> graph[N];
vector<ll> cnt(N, 0);
const int mod = 1e9+7;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    while (m--) {
        int u, v; cin >> u >> v;
        graph[u].emplace_back(v);
        cnt[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) if (!cnt[i]) q.emplace(i);

    queue<int> t;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        t.emplace(u);
        for (int v : graph[u]) {
            cnt[v]--;
            if (!cnt[v]) q.emplace(v);
        }
    }

    fill(cnt.begin(), cnt.end(), 0);
    cnt[1] = 1;
    while (!t.empty()) {
        int u = t.front(); t.pop();
        for (int v : graph[u]) {
            cnt[v] += cnt[u];
            cnt[v] %= mod;  
        }
    }

    cout << cnt[n];

    return 0;
}