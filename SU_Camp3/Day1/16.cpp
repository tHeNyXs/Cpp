#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 10001;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    int dp[n+1];
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = 0;
        for (int j = 0; j < i; ++j) {
            dp[i] += dp[j] * dp[i-j-1];
            dp[i] %= mod;
        }
    }
    cout << dp[n];

    return 0;
}