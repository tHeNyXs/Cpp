#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    int A, B, C; cin >> A >> B >> C;
    ll ans = 0;
    for (int first = 0; first < 3; ++first) {
        int a = A, b = B, c = C;
        if (a == 0 && first == 0) continue;
        else if (b == 0 && first == 1) continue;
        else if (c == 0 && first == 2) continue;
        ll dp[A+1][B+1][C+1][3];
        memset(dp, 0, sizeof(dp));
        if (first == 0) {
            a--;
        }
        else if (first == 1) {
            b--;
        }
        else if (first == 2) {
            c--;
        }
        dp[a][b][c][first]++;
        for (int i = a; i >= 0; --i) {
            for (int j = b; j >= 0; --j) {
                for (int k = c; k >= 0; --k) {
                    for (int put = 0; put < 3; ++put) {
                        if (put == 0 && i-1 >= 0) {
                            dp[i][j][k][put] += dp[i-1][j][k][1] + dp[i-1][j][k][2];
                        }
                        else if (put == 1 && j-1 >= 0) {
                            dp[i][j][k][put] += dp[i][j-1][k][0] + dp[i][j-1][k][2];
                        }
                        else if (put == 2 && k-1 >= 0) {
                            dp[i][j][k][put] += dp[i][j][k-1][0] + dp[i][j][k-1][1];
                        }
                        dp[i][j][k][put] %= mod;
                    }
                }
            }
        }
        for (int i = 0; i < 3; ++i) {
            if (i != first) ans += dp[0][0][0][i];
            ans %= mod;
        }
    }
    cout << ans;
    

    return 0;
}