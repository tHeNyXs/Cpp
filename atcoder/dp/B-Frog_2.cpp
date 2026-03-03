#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+105;
int h[N];
vector<int> dp(N, INT_MAX);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }

    dp[1] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            dp[i+j] = min(dp[i] + abs(h[i]-h[i+j]), dp[i+j]);
        }
    }
    // for (int i = 1; i <= n; ++i) {
    //     cout << dp[i] << ' ';
    // }
    cout << dp[n];

    return 0;
}