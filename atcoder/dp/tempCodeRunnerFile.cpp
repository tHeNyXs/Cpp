#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int h[N], dp[N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }

    dp[1] = 0;
    dp[2] = abs(h[2] - h[1]);

    for (int i = 3; i <= n; ++i) {
        dp[i] = min(dp[i-1] + abs(h[i-1] - h[i]),
                    dp[i-2] + abs(h[i-2] - h[i]));
    }
    // for (int i = 1; i <= n; ++i) {
    //     cout << dp[i] << ' ';
    // }
    cout << dp[n];

    return 0;
}