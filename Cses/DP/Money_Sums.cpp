#include <bits/stdc++.h>
#define FOR(i, s, e) for (int i = s; i <= e; ++i)
using namespace std;
const int N = 1e5+5;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    int c[n];
    int sum = 0;
    FOR(i, 0, n-1) {
        cin >> c[i];
        sum += c[i];
    }

    vector<bool> dp(N, false);
    dp[0] = true;
    sort(c, c+n);
    for (int i = 0; i < n; ++i) {
        for (int j = sum; j >= c[i]; --j){
            if (dp[j-c[i]]) dp[j] = true;
        }
    }

    int cnt = 0;
    FOR(i, 1, sum) if (dp[i]) cnt++;

    cout << cnt << '\n';
    FOR(i, 1, sum) if (dp[i]) cout << i << " ";
    
    return 0;
}