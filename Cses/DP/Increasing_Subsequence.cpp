#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    int a[n]; for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> dp(n+1, INT_MAX);
    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(dp.begin(), dp.end(), a[i]);
        int idx = it-dp.begin();
        dp[idx] = a[i];
    }
    for (int i = n; i >= 0; --i) {
        if (dp[i] == INT_MAX) continue;
        cout << i+1;
        break;
    }

    return 0;
}