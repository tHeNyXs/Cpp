#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int l1, l2;
    cin >> l1 >> l2;
    vector<vector<int>> dp(2, vector<int>(l2+1, 0));
    int ans = -1;
    string a, b; cin >> a >> b;
    for (int i = 1; i <= l1; ++i) {
        for (int j = 1; j <= l2; ++j) {
            if (a[i-1] == b[j-1]) dp[i%2][j] = dp[(i+1)%2][j-1] + 1;
            else dp[i%2][j] = 0;
            ans = max(ans, dp[i%2][j]);
        }

        // cout << "I : " << i << a[i-1] << '\n';
        // for (int j = 1; j <= l2; ++j) {
        //     cout << dp[i%2][j] << " ";
        // }
        // cout << "\n\n";

    }

    // for (int i = 0; i <= l1; ++i) {
    //     for (int j = 0; j <= l2; ++j) {
    //         if (i == 0 && j == 0) cout << " ";
    //         if (i == 0) {
    //             cout << b[j-1] << " ";
    //             continue;
    //         }
    //         if (j == 0) {
    //             cout << a[i-1] << " ";
    //             continue;
    //         }
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    cout << ans;

    return 0;
}