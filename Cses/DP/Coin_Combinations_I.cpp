#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int T = 1e6+5;
const int mod = 1e9+7;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, t;
    cin >> n >> t;
    vector<ll> dp(T, 0); // [value] = amount
    int c[n];
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        dp[c[i]]++;
    }
    for (int i = 0; i < T; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i-c[j] >= 0) dp[i] += dp[i-c[j]];
            dp[i] %= mod;
        }
    }
    // for (int i = 0; i <= t; ++i) {
    //     cout << dp[i] << " ";
    // }


    cout << dp[t];
    

    return 0;
}