#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    ll p[n+1];
    for (int i = 1; i <= n; ++i) cin >> p[i];

    ll ans = 0;
    for (int i = 2; i <= n; ++i) {
        if (p[i] > p[i-1]) ans += p[i] - p[i-1];
    }

    cout << ans;

    return 0;
}