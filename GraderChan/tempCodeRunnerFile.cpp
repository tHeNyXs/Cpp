#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    int A, B, C;
    A = B = C = 0;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if (x == 1) A++;
        else if (x == 2) B++;
        else C++;
    }

    double dp[305][305][305];
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 0;
    for (int a = 0; a <= A; ++a) {
        for (int b = 0; b <= B; ++b) {
            for (int c = 0; c <= C; ++c) {
                dp[a][b][c] = 1;
                if (a > 0) dp[a][b][c] += a/n * dp[a-1][b][c];
                if (b > 0) dp[a][b][c] += b/n * dp[a+1][b-1][c];
                if (c > 0) dp[a][b][c] += c/n * dp[a][b+1][c-1];
                if (n - (a+b+c) > 0) dp[a][b][c] += (n-(a+b+c))/n * dp[a][b][c];
            }
        }
    }
    cout << dp[A][B][C];

    return 0;
}