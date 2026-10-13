#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int dp[N][3];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    int vac[n+1][3];
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> dp[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 3; ++j) {
            dp[i][j] += max(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]);
        }
    }

    cout << max({dp[n][0], dp[n][1], dp[n][2]});

    return 0;
}