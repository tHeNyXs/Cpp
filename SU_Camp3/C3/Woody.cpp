#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e18;
const int N = 505;
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, tx, ty; cin >> n >> tx >> ty;
    vector<vector<int>> dp(N, vector<int>(N, inf));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        int x, y, w; cin >> x >> y >> w;
        for (int j = N-1; j >= 0; --j) {
            for (int k = N-1; k >= 0; --k) {
                // if (j-x >= 0) dp[j][k] = min(dp[j][k], dp[j-x][k]+w);
                // if (k-y >= 0) dp[j][k] = min(dp[j][k], dp[j][k-y]+w);
                // if (j-x >= 0 && j-y >= 0) dp[j][k] = min(dp[j][k], dp[max(j-x, 1LL*0)][max(k-y, 1LL*0)]+w);
                dp[j][k] = min(dp[j][k], dp[max(j-x, 1LL*0)][max(k-y, 1LL*0)]+w);
            }
        }
    }

    // for (int i = 0; i <= tx; ++i) {
    //     for (int j = 0; j <= ty; ++j) {
    //         if (dp[i][j] == inf) cout << "  ";
    //         else cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    if (dp[tx][ty] == inf) dp[tx][ty] = -1;
    cout << dp[tx][ty];

    return 0;
}