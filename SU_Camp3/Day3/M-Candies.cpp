#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, k; cin >> n >> k;
    int a[n+1];
    for (int i =1; i <= n; ++i) cin >> a[i];
    sort(a, a+n+1);
    int dp[n+1][k+1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= k; ++i) dp[0][i] = 1;
    for (int p = 1; p <= n; ++p) {
        for (int i = a[p]; i <= k; ++i) {
            dp[p][i] += dp[p-1][i-a[p]];
            dp[p][i] %= mod;
        }
    }

    for (int p = 0; p <= n; ++p) {
        for (int i = 0; i <= k; ++i) {
            // cout << "P : " << p << " | Sum : " << i << "\n";
            cout << dp[p][i] << " ";
        }
        cout << '\n';
    }

    cout << dp[n][k];

    return 0;
}