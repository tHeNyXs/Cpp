#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e3 + 5;
const int mod = 1e9 + 7;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<vector<ll>> dp(N, vector<ll>(N, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            char a; cin >> a;
            if (a == '.') dp[i][j]++;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == 1 && j == 1) continue;
            if (dp[i][j]) dp[i][j] = dp[i-1][j] + dp[i][j-1];
            dp[i][j] %= mod;
        }
    }

    cout << dp[n][n];

    return 0;
}