#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    ll num[n];
    for (int i = 0; i < n; ++i) cin >> num[i];
    ll minn = 1e18;
    ll pfs = 0;
    ll ans = -1e18;
    for (int i = 0; i < n; ++i) {
        pfs += num[i];
        ans = max(ans, pfs);
        ans = max(ans, pfs-minn);
        minn = min(pfs, minn);
    }
    cout << ans;

    return 0;
}