#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, k; cin >> n >> k;
    set<int> s;
    for (int i = 0; i < k; ++i) {
        int x; cin >> x;
        s.emplace(x);
    }
    // sort(a, a+n);
    int dp[n+1][4+1];
    memset(dp, 0, sizeof(dp));
    int temp[] = {0, 1, 2, 4};
    dp[0][0] = 1;
    // int idx = a[idx];
    for (int i = 0; i <= n; ++i) {
        for (int j = 1; j <= 4; ++j) {
            if (j == 3) continue;
            bool flag = false;
            // cout << "I : " << i << " | J : " << j << "\n";
            // cout << "Check : ";
            for (int check = i-j+1; check < i; ++check) {
                // cout << check << ' '; 
                if (s.find(check) != s.end()) {
                    flag = true;
                    break;
                }
            }
            // cout << '\n';
            if (flag) continue;
            if (j == 1 && i-1 >= 0) dp[i][j] = (dp[i][j] + dp[i-1][2] + dp[i-1][1] + dp[i-1][0]) % mod;
            else if (j == 2 && i-2 >= 0) dp[i][j] = (dp[i][j] + dp[i-2][1] + dp[i-2][4] + dp[i-2][0]) % mod;
            else if (j == 4 && i-4 >= 0) dp[i][j] = (dp[i][j] + dp[i-4][2] + dp[i-4][4] + dp[i-4][0]) % mod;
        }
    }

    // for (int i = 1; i <= n; ++i) {
    //     for (int j : temp) {
    //         cout << "I : " << i << " | Step : " << j  << " | Dp : " << dp[i][j] << '\n';
    //     }
    // }

    int ans = 0;
    for (int i = 1; i <= 4; ++i) {
        ans += dp[n][i];
        ans %= mod;
    }
    cout << ans % mod;
    
    return 0;
}