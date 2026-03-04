#include <bits/stdc++.h>
using namespace std;

string a, b;
string ans = "";
vector<vector<int>> dp;
void backtrack(int x, int y) {
    if (ans.size() == dp[a.size()][b.size()]) return;

    if (a[x-1] == b[y-1]) {
        ans += a[x-1];
        backtrack(x-1, y-1);
    }
    else if (dp[x][y] == dp[x-1][y]) {
        backtrack(x-1, y);
    }
    else backtrack(x, y-1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> a >> b;
    int x, y;
    x = a.size(); y = b.size();
    dp.resize(x+1, vector<int>(y+1, 0));
    for (int i = 1; i <= x; ++i) {
        for (int j = 1; j <= y; ++j) {
            if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    // for (int i = 1; i <= x; ++i) {
    //     for (int j = 1; j <= y; ++j) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    backtrack(x, y);
    reverse(ans.begin(), ans.end());
    cout << ans;

    return 0;
}