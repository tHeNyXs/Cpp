#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int q; cin >> q;
    while (q--) {
        int n; cin >> n;
        ll m, a[n];
        cin >> m;
        for (int i = 0; i < n; ++i) {
            cin >> a[i]; a[i] %= m;
        }

        set<ll> s;
        ll pfs = 0;
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            pfs = (pfs+a[i]) % m;

            ans = max(ans, pfs);
            auto it = s.upper_bound(pfs);
            if (it != s.end()) {
                ans = max(ans, (pfs - *it + m) % m);
            }

            s.emplace(pfs);
        }
        cout << ans << '\n';
    }

    return 0;
}