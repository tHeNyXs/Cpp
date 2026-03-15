#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string a, b; cin >> a >> b;
    int x = a.length(), y = b.length();
    vector<vector<int>> dp(x+1, vector<int>(y+1, 0));
    for (int i = 1; i <= x; ++i) dp[i][0] = i;
    for (int j = 1; j <= y; ++j) dp[0][j] = j;
    
    for (int i = 1; i <= x; ++i) {
        for (int j = 1; j <= y; ++j) {
            if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
            else {
                dp[i][j] = 1 + min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
            }
        }
    }
    cout << dp[x][y];
    
    return 0;
}