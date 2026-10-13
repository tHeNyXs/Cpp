#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+5;
int dp[N];
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, W; cin >> n >> W;
    fill(dp, dp+N, 1e18); // value
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        int w, v; cin >> w >> v;
        for (int j = N-1; j >= 0; --j) {
            if (j-v < 0) continue;
            dp[j] = min(dp[j-v]+w, dp[j]);
        }
    }

    for (int i = N-1; i >= 0; --i) {
        if (dp[i] <= W) {
            cout << i;
            return 0;
        }
    }

    return 0;
}