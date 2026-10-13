#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
const int N = 2e5+5;

vector<int> graph[N];
vector<int> edge[N];
int val[N];
int n, m;

void dfs(int u, int p) {
    if (u <= n) val[u] = 1;
    for (int v : graph[u]) {
        if (v == p) continue;
        dfs(v, u);
        val[u] += val[v];
        edge[u].emplace_back(val[v]);
    }
}

void set_val(int u, int p) {
    if (u <= n) return;
    for (int v : graph[u]) {
        if (v == p || v <= n) continue;
        edge[v].emplace_back(n-val[v]);
        set_val(v, u);
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i < n+m; ++i) {
        int u, v; cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    dfs(n+1, n+1);
    set_val(n+1, n+1);

    // for (int i : edge[n+1]) {
    //     cout << i << " ";
    // }
    // cout << '\n';

    int ans = 0;
    for (int i = n+1; i <= n+m; ++i) {
        // cout << "I : " << i << " | ";
        // for (int j : edge[i]) cout << j << " ";
        // cout << '\n';
        if (edge[i].size() < 4) continue;
        int dp[5] = {0};
        for (int val : edge[i]) {
            dp[4] += dp[3]*val;
            dp[3] += dp[2]*val;
            dp[2] += dp[1]*val;
            dp[1] += val;
        }
        ans += dp[4] % mod;
    }
    cout << ans % mod;

    return 0;
}