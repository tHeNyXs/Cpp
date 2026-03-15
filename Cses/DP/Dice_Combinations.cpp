#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9+7;
const int N = 1e6+5;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<ll> dp(N, 0);
    for (int i = 1; i <= 6; ++i) dp[i] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= 6; ++j) {
            if (i-j > 0) dp[i] += dp[i-j];
            dp[i] %= MOD;
        }
    }
    cout << dp[n];

    return 0;
}