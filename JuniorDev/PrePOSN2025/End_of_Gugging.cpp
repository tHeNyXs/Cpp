#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, k; cin >> n >> k;
    ll c[n];
    for (int i = 0; i < n; ++i) cin >> c[i];
    int maxL[n][n], maxR[n][n], minL[n][n], minR[n][n];
    for (int len = 1; len <= n; ++len) {
        for (int l = 0; l+len-1 < n; ++l) {
            int r = l+len-1;
            ll maxx = LLONG_MIN, minn = LLONG_MAX;
            for (int i = l; i <= r; ++i) {
                if (c[i] > maxx) {
                    maxx = c[i];
                    maxR[l][r] = i;
                }
                if (c[i] < minn) {
                    minn = c[i];
                    minR[l][r] = i;
                }
            }

            for (int i = r; i >= l; --i) {
                if (c[i] == maxx) maxL[l][r] = i;
                if (c[i] == minn) minL[l][r] = i;
            }
        }
    }

    vector<vector<ll>> dp(n, vector<ll>(n, 1e18));
    for (int len = 1; len <= n; ++len) {
        for (int l = 0; l+len-1 < n; ++l) {
            int r = l+len-1;
            if (l == r) {
                dp[l][r] = 0;
                continue;
            }
            for (int i = l; i < r; ++i) {
                ll cost = 1e18;
                int a = maxL[l][i];
                int b = minR[i+1][r];
                if (c[a] > c[b]) cost = 2LL*abs(a-b)*(c[a]-c[b]);
                a = maxR[i+1][r]; b = minL[l][i];
                if (c[a] > c[b]) cost = min(cost, 2LL*abs(a-b)*(c[a]-c[b]));

                if (cost == 1e18) cost = 0;
                dp[l][r] = min(dp[l][r], dp[l][i]+dp[i+1][r]+cost);
            }
        }
    }

    ll val[k+1][n+1];

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= k; j++)
            val[j][i] = 1e18;
    val[0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++)
        {
            for (int x = 0; x < i; x++)
                val[j][i] = min(val[j][i], val[j - 1][x] + dp[x][i - 1]);
        }
    cout << val[k][n] << '\n';


    return 0;
}