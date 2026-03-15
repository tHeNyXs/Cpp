#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    ll a[n];
    ll pfs[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a, a+n);
    for (int i = 0; i < n; ++i) {
        pfs[i] = a[i];
        if (i > 0) pfs[i] += pfs[i-1];
    }

    ll ans = 1e18;
    for (int i = 0; i < n; ++i) {
        ll value = 0;
        if (i > 0) value += (a[i] * (i)) - pfs[i-1];
        if (i < n-1) value += (pfs[n-1] - pfs[i]) - (a[i]*(n-i-1));
        ans = min(value, ans);
    }
    cout << ans;

    return 0;
}