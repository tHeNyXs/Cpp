#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int sum = 0;
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) sum += i;
    if (sum%2) {
        cout << 0;
        return 0;
    }
    sum /= 2;
    vector<ll> dp(sum+1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = sum; j >= i; --j) {
            dp[j] += dp[j-i];
            dp[j] %= mod;
        }
    }
    ll inv2 = mod/2;

    cout << (dp[sum] * inv2) % mod;

    return 0;
}