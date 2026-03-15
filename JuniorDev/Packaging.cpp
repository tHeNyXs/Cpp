#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;
const int N = 2e3+5;
ll dp[N][N];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) dp[i][1] = 1;

    for (int h = 1; h <= m; ++h) {
        for (int now = 1; now <= n; ++now) {
            dp[now][h] += dp[now][h-1]; dp[now][h] %= mod;
            dp[now][h] += dp[now-1][h-1]; dp[now][h] %= mod;
            dp[now][h] += dp[now-1][h]; dp[now][h] %= mod;
        }
    }

    ll sum = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            sum += dp[i][j];
            sum %= mod;
        }
    }
    cout << sum;


    return 0;
}