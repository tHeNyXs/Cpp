#include <bits/stdc++.h>
using namespace std;

// dp[จำนวนช่วงอาเรย์][ค่าปัจจุบัน] = วิธีที่เป็นไปได้
// dp[0][start] = 1
#define ll long long

const int N = 1e5+5;
ll dp[N][105];
const int mod = 1e9+7;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    int a[n];
    for (int i = 1; i <= n; ++i) cin >> a[i];
    if (a[1] == 0) for (int i = 1; i <= m; ++i) dp[1][i] = 1;
    else dp[1][a[1]] = 1;

    for (int i = 2; i <= n; ++i) {
        if (a[i]) {
            dp[i][a[i]] += dp[i-1][a[i]-1];
            dp[i][a[i]] += dp[i-1][a[i]];
            dp[i][a[i]] += dp[i-1][a[i]+1];
            dp[i][a[i]] %= mod;
        }
        else {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] += dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];
                dp[i][j] %= mod;
            }
        }
    }

    ll sum = 0;
    for (int i = 1; i <= m; ++i) {
        sum += dp[n][i];
        sum %= mod;
    }
    cout << sum;

    return 0;
}