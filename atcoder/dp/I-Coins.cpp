#include <bits/stdc++.h>
using namespace std;
#define lf long double
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<lf> c(n+1);
    for (int i = 1; i <= n; ++i) cin >> c[i];

    vector<lf> dp(n+1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j >= 0; --j) {
            dp[j] *= (1-c[i]);
            if (j > 0) dp[j] += dp[j-1] * c[i];
        }
    }

    lf sum = 0;
    for (int i = n; i > n/2; --i) {
        sum += dp[i];
    }
    cout << fixed << setprecision(9) << sum;

    return 0;
}