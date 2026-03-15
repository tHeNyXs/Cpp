#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int a, b; cin >> a >> b;
    vector<vector<int>> dp(a+1, vector<int>(b+1, INT_MAX));
    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            if (i == j) {
                dp[i][j] = 0;
                continue;
            }
            
            for (int k = 1; k <= i/2; ++k) {
                dp[i][j] = min(dp[k][j] + dp[i-k][j]+1, dp[i][j]);
            }

            for (int k = 1; k <= j/2; ++k) {
                dp[i][j] = min(dp[i][k] + dp[i][j-k]+1, dp[i][j]);
            }

            // cout << "I : " << i << " | J : " << j << " | DP : " << dp[i][j] << '\n';    
        }
    }
    cout << dp[a][b];

    return 0;
}