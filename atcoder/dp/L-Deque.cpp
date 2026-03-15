#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    ll a[n+1];
    for (int i = 1; i <= n; ++i) cin >> a[i];
    vector<vector<ll>> dp(n+1, vector<ll>(n+1, -(1e18)));
    for (int i = 1; i <= n; ++i) dp[i][i] = a[i];

    for (int len = 2; len <= n; ++len) {
        for (int l = 1; l+len-1 <= n; ++l) {
            int r = l+len-1;
            dp[l][r] = max(a[l]-dp[l+1][r], dp[l][r]);
            dp[l][r] = max(a[r]-dp[l][r-1], dp[l][r]);
        }
    }


    cout << dp[1][n];

    return 0;
}