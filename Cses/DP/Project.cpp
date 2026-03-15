#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct P {
    int s, e;
    ll p;
};

bool cmp(const P a, const P b) {
    if (a.e != b.e) return a.e < b.e;
    return a.s < b.s;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    P p[n+1];
    for (int i = 1; i <= n; ++i) {
        cin >> p[i].s >> p[i].e >> p[i].p;
    }

    sort(p+1, p+n+1, cmp);
    int e[n+1];
    for (int i = 1; i <= n; ++i) e[i] = p[i].e;

    vector<ll> dp(n+1, 0);
    for (int i = 1; i <= n; ++i) {
        int idx = (lower_bound(e+1, e+n+1, p[i].s) - e); idx--;
        dp[i] = max(dp[idx]+p[i].p, dp[i-1]);
        // cout << "Start : " << p[i].s << " | End : " << p[i].e << " | Dp : " << dp[i] << '\n';
    }
    cout << dp[n];

    return 0;
}