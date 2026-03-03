#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    string a; cin >> a;
    string b = a;
    reverse(b.begin(), b.end());

    vector<vector<int>> dp(2, vector<int>(n+1, 0));
    int cur = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i-1] == b[j-1]) dp[cur][j] = dp[!cur][j-1]+1;
            else dp[cur][j] = max(dp[cur][j-1], dp[!cur][j]);
        }
        cur = !cur;
    }
    cout << n-dp[!cur][n];

    return 0;
}