#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, x; cin >> n >> x;
    vector<pair<int, int>> dp(1<<n, {n+1, 0});
    int w[n];
    for (int i = 0; i < n; ++i) cin >> w[i];

    dp[0] = {1, 0};
    for (int mask = 0; mask < (1<<n); ++mask) {
        for (int i = 0; i < n; ++i) {
            if (!(mask & (1<<i))) continue;
            int prev = mask ^ (1<<i);
            int prevCount = dp[prev].first;
            int prevWeight = dp[prev].second;
            pair<int, int> temp;
            if (prevWeight + w[i] > x) temp = {prevCount+1, w[i]};
            else temp = {prevCount, prevWeight+w[i]};
            dp[mask] = min(dp[mask], temp);
        }
    }
    cout << dp[(1<<n)-1].first;

    return 0;
}