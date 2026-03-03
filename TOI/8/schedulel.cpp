#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define p pair<int, int>

const int N = 1e3 + 5;
int m, n;
int J[N], K[N];
p dp[N][N];

p change(p a, int b) {
    if (a.s + b > m) return {a.f + 1, b};
    return  {a.f, a.s + b};
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> m >> n;
    for (int i = 1; i <= n; ++i) cin >> J[i];
    for (int i = 1; i <= n; ++i) cin >> K[i];

    dp[0][0] = {1, 0};
    for (int i = 1; i <= n; ++i) dp[i][0] = change(dp[i - 1][0], J[i]);
    for (int j = 1; j <= n; ++j) dp[0][j] = change(dp[0][j - 1], K[j]);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <=n; ++j) {
            p a = change(dp[i - 1][j], J[i]), b = change(dp[i][j - 1], K[j]);
            dp[i][j] = min(a, b);
        }
    }
    cout << dp[n][n].f << '\n' << dp[n][n].s;

    return 0;
}