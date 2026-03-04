#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, mw; cin >> n >> mw;
    vector<vector<ll>> dp(n+1, vector<ll>(mw+1, 0));
    for (int i = 1; i <= n; ++i) {
        int w, v; cin >> w >> v;
        for (int j = 0; j <= mw; ++j) {
            dp[i][j] = dp[i-1][j];
            if (j-w < 0) continue;
            // cout << "I : " << i << " | J : " << j << '\n';
            // cout << dp[i-1][j-w] << " " << v << "\n";
            dp[i][j] = max(dp[i][j], dp[i-1][j-w] + v);
        }
    }

    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 1; j <= mw; ++j) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    cout << dp[n][mw];

    return 0;
}