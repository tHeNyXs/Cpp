#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+5;
const int mod = 1e9+7;
vector<int> graph[N];
int dp[N][2];
bool vis[N];

void ans(int u) {
    dp[u][0] = dp[u][1] = 1;
    for (int v : graph[u]) {
        if (u == v || vis[v]) continue;
        vis[v] = true;
        ans(v);
        dp[u][0] = (dp[v][0]+dp[v][1]) * dp[u][0];
        dp[u][1] = dp[v][0] * dp[u][1];
        dp[u][0] %= mod;
        dp[u][1] %= mod;
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 1; i < n; ++i) {
        int x, y; cin >> x >> y;
        graph[x].emplace_back(y);
        graph[y].emplace_back(x);
    }

    vis[1] = true;
    ans(1);
    cout << (dp[1][0] + dp[1][1]) % mod;

    return 0;
}