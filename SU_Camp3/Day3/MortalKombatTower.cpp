#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int q; cin >> q;
    while (q--) {
        int n; cin >> n;
        int dp[2][2][n+1]; // turn, player, position
        memset(dp, 0x3f, sizeof(dp));
        int arr[n+1];
        for (int i = 1; i <= n; ++i) cin >> arr[i];
        dp[0][0][0] = dp[0][1][0] = 0;
        if (arr[1]) dp[0][0][1] = 1;
        else dp[0][0][1] = 0;
        for (int i = 2; i <= n; ++i) {
            int f1 = dp[0][0][i-1];
            int f2 = dp[1][0][i-1];
            int s1 = dp[0][1][i-1];
            int s2 = dp[1][1][i-1];
            if (arr[i]) {
                dp[0][0][i] = min({dp[0][0][i], s1+1, s2+1});
                dp[1][0][i] = min({dp[1][0][i], s1+1, s2+1, f1+1});
            }
            else {
                dp[0][0][i] = min({dp[0][0][i], s1, s2});
                dp[1][0][i] = min({dp[1][0][i], s1, s2, f1});
            }
            dp[0][1][i] = min({dp[0][1][i], f1, f2});
            dp[1][1][i] = min({dp[1][1][i], f1, f2, s1});
        }
        

        cout << min({dp[0][0][n], dp[0][1][n], dp[1][0][n], dp[1][1][n]}) << '\n';
    }

    return 0;
}