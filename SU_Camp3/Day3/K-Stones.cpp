#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<bool> dp(k+1, false);
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a+n);

    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i-a[j] < 0) continue;
            if (!dp[i-a[j]]) dp[i] = true;
        }
    }
    
    // for (int i = 1; i <= k; ++i) {
    //     cout << dp[i] << " ";
    // }
    cout << (dp[k] ? "First" : "Second");

    return 0;
}