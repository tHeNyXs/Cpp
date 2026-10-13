#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int len = 2; len <= n; ++len) {
        for (int l = 0; l+len-1 < n; ++l) {
            int r = l+len-1;
            
            for (int i = l; i <= r; ++i) {
                dp[l][r] += a[i];
            }

            int minn = 1e18;
            for (int mid = l; mid+1 <= r; ++mid) {
                minn = min(minn, dp[l][mid] + dp[mid+1][r]);
            }
            dp[l][r] += minn;
        }
    }

    // for (int len = 2; len <= n; ++len) {
    //     for (int l = 0; l+len-1 < n; ++l) {
    //         int r = l+len-1;
    //         cout << "L : " << l << " | R : " << r << " DP : " << dp[l][r] << '\n';
    //     }
    // }

    cout << dp[0][n-1];

    return 0;
}