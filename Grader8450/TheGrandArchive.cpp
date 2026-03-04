#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    while (n--) {
        string a, b; cin >> a >> b;
        vector<vector<bool>> dp(a.size()+1, vector<bool>(b.size()+1, false));

        for (int i = 0; i <= a.size(); ++i) {
            dp[i][0] = true;
            // cout << i << " " << 0 << " \n";
        }

        for (int i = 1; i <= a.size(); ++i) {
            for (int j = 1; j <= b.size(); ++j) {
                if ('A' <= a[i-1] && a[i-1] <= 'Z') {
                    if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
                }
                else {
                    dp[i][j] = dp[i-1][j];
                    if (a[i-1] - 'a' + 'A' == b[j-1]) {
                        dp[i][j] = dp[i-1][j-1] | dp[i][j];
                        // cout << i << " " << j << " " << '\n';
                        // cout << dp[i-1][j-1] << '\n';
                    }
                }
            }
        }

        // for (int i = 0; i <= a.size(); ++i) {
        //     for (int j = 0; j <= b.size(); ++j) {
        //         if (i == 0 && j == 0) cout << "  ";
        //         else if (i == 0) cout << b[j-1] << " ";
        //         else if (j == 0) cout << a[i-1] << " ";
        //         else cout << dp[i][j] << " ";
        //     }
        //     cout << '\n';
        // }

        cout << (dp[a.size()][b.size()] ? "YES\n" : "NO\n");
    }

    return 0;
}