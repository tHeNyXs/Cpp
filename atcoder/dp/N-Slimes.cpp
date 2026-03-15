#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    ll num[n+1];
    ll pfs[n+1];
    num[0] = pfs[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> num[i];
        pfs[i] = num[i];
        if (i > 0) pfs[i] += pfs[i-1];
    }
    vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));
    for (int len = 1; len <= n; ++len) {
        for (int l = 1; l+len-1 <= n; ++l) {
            int r = l+len-1;
            if (l == r) {
                dp[l][r] = 0;
                continue;
            }

            dp[l][r] = pfs[r]-pfs[l-1];
            ll minn = 1e18;
            for (int k = l; k < r; ++k) {
                minn = min(dp[l][k] + dp[k+1][r], minn);
            }
            dp[l][r] += minn;
        }
    }

    cout << dp[1][n];

    return 0;
}