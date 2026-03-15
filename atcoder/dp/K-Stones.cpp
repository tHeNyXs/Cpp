#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, k; cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a+n);
    vector<bool> dp(k+1, false);
    dp[0] = false;
    for (int i = 1; i <= k; ++i) {
        for (int j : a) {
            if (i-j < 0) continue;
            if (!dp[i-j]) dp[i] = true;
        }
    }

    if (dp[k]) cout << "First";
    else cout << "Second";

    return 0;
}