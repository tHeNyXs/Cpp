#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, c; cin >> n >> c;
    vector<int> dp(c+1, 0);
    for(int i = 0, w, v; i < n; ++i) {
        cin >> w >> v;
        for (int j = c; j >= w; --j) {
            dp[j] = max(dp[j], dp[j-w] + v);
        }
    }
    cout << dp[c];

    return 0;
}