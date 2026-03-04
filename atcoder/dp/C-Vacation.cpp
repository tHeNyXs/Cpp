#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> dp(3, 0);
    while (n--) {
        int x, y, z;
        cin >> x >> y >> z;
        vector<int> prev = dp;
        dp[0] = max(prev[1]+x, prev[2]+x);
        dp[1] = max(prev[0]+y, prev[2]+y);
        dp[2] = max(prev[0]+z, prev[1]+z);
        // for (int i : dp) {
        //     cout << i << " ";
        // }
        // cout << '\n';
    }
    cout << *max_element(dp.begin(), dp.end());

    return 0;
}