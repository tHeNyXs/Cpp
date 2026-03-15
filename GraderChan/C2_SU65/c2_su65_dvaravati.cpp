#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string a, b;
    cin >> a >> b;
    int x = a.length();
    vector<vector<int>> dp(x+1, vector<int>(x+1, 0));
    for (int i = 1; i <= x; ++i) {
        for (int j = 1; j <= x; ++j) {
            if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    string ans = "";
    int i, j; i = j = x;
    while (i >= 1 && j >= 1) {
        if (a[i-1] == b[j-1]) {
            ans += a[i-1];
            i--; j--;
        }
        else if (dp[i][j-1] >= dp[i-1][j]) 
            j--;
        else 
            i--;
        // cout << i << j << '\n';
    }

    // for (int i = 1; i <= x; ++i) {
    //     for (int j = 1; j <= x; ++j) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
    cout << dp[x][x] << '\n';
    cout << (dp[x][x] >= x/2 ? "y" : "n");

    return 0;
}