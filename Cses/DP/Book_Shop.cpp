#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int X = 1e5 + 5;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, x; cin >> n >> x;
    vector<vector<int>> dp(2, vector<int>(X, 0));
    int price[n], page[n];
    for (int i = 0; i < n; ++i) cin >> price[i];
    for (int i = 0; i < n; ++i) cin >> page[i];

    int cur = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < X; ++j) {
            dp[cur][j] = dp[!cur][j];
            if (j-price[i] >= 0) dp[cur][j] = max(dp[cur][j], dp[!cur][j-price[i]] + page[i]);
        }
        cur = !cur;
    }
    cout << dp[!cur][x];

    return 0;
}