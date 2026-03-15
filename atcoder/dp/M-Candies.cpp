#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, k; cin >> n >> k;
    ll a[n+1];
    for (int i = 1; i <= n; ++i) cin >> a[i];

    vector<vector<ll>> dp(n+1, vector<ll>(k+1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        vector<ll> prev(k+1, 0);
        for (int j = 0; j <= k; ++j) {
            prev[j] = dp[i-1][j];
            if (j > 0) prev[j] += prev[j-1];
        }

        for (int j = 0; j <= k; ++j) {
            if (j-a[i] > 0) dp[i][j] += prev[j] - prev[j-a[i]-1];
            else dp[i][j] = prev[j];
            dp[i][j] %= mod;
        }
    }
    cout << dp[n][k];

    return 0;
}