#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, k; cin >> n >> k;
    int dp[n+1][n+1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1; 

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {

            for (int end = i-k; end < )


        }
    }
    cout << dp[n][n]-1;

    return 0;
}