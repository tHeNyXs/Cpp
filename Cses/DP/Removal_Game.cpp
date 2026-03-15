#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e3 + 5;
ll dp[N][N];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    int num[n];
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
        sum += num[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int l = 0; i+l-1 < n; ++l) {
            int r = l+i-1;
            if (l == r) dp[l][r] = num[l];
            else {
                dp[l][r] = max(num[l] - dp[l+1][r], num[r] - dp[l][r-1]);
            }
        }
    }

    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < n; ++j) {
    //         cout << "I : " << i << " | J : " << j << " | DP : " << dp[i][j] << '\n';
    //     }
    // }

    cout << (sum + dp[0][n-1]) / 2;

    return 0;
}