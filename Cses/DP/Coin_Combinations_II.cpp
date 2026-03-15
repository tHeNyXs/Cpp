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
    }
    sort(c, c+n);
    for (int i = 0; i < n; ++i) {
        dp[c[i]]++;
        for (int j = c[i]; j < T; ++j) {
            if (dp[j-c[i]]) dp[j] += dp[j-c[i]];
            dp[j] %= mod;
        }
    }


    cout << dp[t];
    

    return 0;
}