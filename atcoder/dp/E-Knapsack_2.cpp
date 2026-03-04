#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+5;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, mw; cin >> n >> mw;
    vector<ll> dp(N, 1e18);
    dp[0] = 0;
    for (int i = 0, w, v; i < n; ++i) {
        cin >> w >> v;
        for (int j = N-1; j >= 0; --j) {
            if (j-v >= 0) dp[j] = min(dp[j], dp[j-v]+w);
            else dp[j] = min(dp[j], dp[j+1]);
        }
    }
    for (int i = 0; i < N; ++i) {
        if (dp[i] > mw) {
            cout << i-1;
            break;
        }
    }

    return 0;
}