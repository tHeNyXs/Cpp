#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+5;
vector<vector<int>> graph(N);
int cnt[N];
int h[N];
int ans[N];
int n;

void find_h(int u, int p) {
    for (int v : graph[u]) {
        if (v == p) continue;
        h[v] = h[u]+1;
        find_h(v, u);
    }
}

void find_cnt(int u, int p) {
    cnt[u] = 1;
    for (int v : graph[u]) {
        if (v == p) continue;
        find_cnt(v, u);
        cnt[u] += cnt[v];
    }
}

void sol(int u, int p) {
    for (int v : graph[u]) {
        if (v == p) continue;
        ans[v] = ans[u]-cnt[v] + (n - cnt[v]);
        sol(v, u);
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    h[1] = 0;
    find_h(1, 0);
    int sum = 0;
    for (int i = 2; i <= n; ++i) {
        sum += h[i];
    }
    ans[1] = sum;
    find_cnt(1, 0);
    sol(1, 0);
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << '\n';
    }

    return 0;
}