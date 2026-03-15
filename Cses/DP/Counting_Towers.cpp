#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;
const int N = 1e6+5;
ll dp[N][2];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    dp[1][0] = dp[1][1] = 1;
    for (int i = 2; i < N; ++i) {
        dp[i][0] = 4*dp[i-1][0] + dp[i-1][1];
        dp[i][0] %= mod;

        dp[i][1] = 2*dp[i-1][1] + dp[i-1][0];
        dp[i][1] %= mod;
    }
    while (t--) {
        int n; cin >> n;
        cout << (dp[n][0] + dp[n][1]) % mod << '\n';
    }

    return 0;
}