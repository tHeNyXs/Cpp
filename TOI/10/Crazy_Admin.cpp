#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int m, o; cin >> m >> o;
    vector<ll> pfs(o+1, 0);
    ll l = 0, r = 1e18;
    for (int i = 1; i <= o; ++i) {
        ll x; cin >> x;
        pfs[i] = x + pfs[i-1];
        // cout << "I : " << i << " | pfs : " << pfs[i] << '\n';
        l = max(l, x);
    }

    while (l <= r) {
        ll mid = (l+r)/2;
        bool flag = false;
        ll prev = 0;
        int cnt = 1;
        for (int i = 1; i <= o; ++i) {
            if (pfs[i]-prev > mid) {
                prev = pfs[i-1];
                cnt++;
            }
            if (cnt > m) break;
        }
        if (cnt <= m) flag = true;
        if (flag) {
            r = mid-1;
        }
        else l = mid+1;
        // cout << "Mid : " << mid << " | cnt : " << cnt << '\n';
    }
    cout << l;

    return 0;
}