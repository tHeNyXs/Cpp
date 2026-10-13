#include <bits/stdc++.h>
using namespace std;
const int mod = 676767677;

void solve() {
    int n; cin >> n;
    int num[n];
    for (auto &i : num) cin >> i;

    int ans = 0;
    for (int i : num) if (i > 1) ans = (ans+i)%mod;
    if (num[n-1] == 1) ans++;
    cout << ans%mod << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) solve();

    return 0;
}