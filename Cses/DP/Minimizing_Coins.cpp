#include <bits/stdc++.h>
using namespace std;
const int T = 1e6+5;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, t;
    cin >> n >> t;
    vector<int> dp(T, INT_MAX); // [value] = amount
    int c[n];
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        dp[c[i]] = 1;
    }

    // sort(c, c+n, greater<int>());
    // for (int i = 0; i < n; ++i) cout << c[i] << " ";
    // cout << '\n';
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = c[i]; j <= t; ++j) {
            if (dp[j-c[i]] != INT_MAX) dp[j] = min(dp[j-c[i]]+1, dp[j]);
        }
        // for (int j = 0; j <= 11; ++j) cout << dp[j] << " ";
        // cout << '\n';
    }
    if (dp[t] == INT_MAX) cout << -1;
    else cout << dp[t];
    

    return 0;
}