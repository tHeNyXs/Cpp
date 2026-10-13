#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    int a[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    vector<int> dp((1<<n), 0);
    dp[0] = 1;
    for (int i = 0; i < (1<<n); ++i) {
        int cnt = __builtin_popcount(i);
        for (int j = 0; j < n; ++j) {
            if (!a[cnt][j] || i & (1<<j)) continue;
            dp[i | (1<<j)] += dp[i];
            dp[i | (1<<j)] %= mod;
        }
    }
    cout << dp[(1<<n)-1];

    return 0;
}