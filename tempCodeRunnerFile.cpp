#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, x; cin >> n >> x;
    int c[n]; for(int i = 0; i < n; ++i) cin >> c[i];
    vector<ll> dp(x+1, 0);
    for (int i = 0; i < n; ++i) {
        dp[c[i]]++;
        for (int j = c[i]; j <= x; ++j) {
            if (j-c[i] < 0) continue;
            dp[j] += dp[j-c[i]];
            dp[j] %= mod;
        }
    }
    cout << dp[x];

    return 0;
}