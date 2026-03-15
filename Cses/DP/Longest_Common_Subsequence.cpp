#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> vec1(n+1, 0), vec2(m+1, 0);
    for (int i = 1; i <= n; ++i) cin >> vec1[i];
    for (int i = 1; i <= m; ++i) cin >> vec2[i];

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (vec1[i] == vec2[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    cout << dp[n][m] << '\n';
    vector<int> ans;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (vec1[i] == vec2[j]) {
            ans.emplace_back(vec1[i]);
            i--;
            j--;
        }
        else if (dp[i][j] == dp[i-1][j]) {
            i--;
        }
        else j--;
    }
    reverse(ans.begin(), ans.end());
    for (int i : ans) cout << i << " ";

    return 0;
}