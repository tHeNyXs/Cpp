#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, q; cin >> n >> q;
    vector<bool> vec(n+1, true);
    for (int i = 3; i <= n; i += 2) {
        for (int j = i; j <= n; j += i) {
            vec[j] = !vec[j];
        }
        for (int i = 1; i <= n; ++i) {
            cout << vec[i];
        }
        cout << '\n';
    }

    while (q--) {
        int l, r; cin >> l >> r;
        int cnt = 0;
        for (int i = l; i <= r; ++i) {
            if (vec[i]) cnt++;
        }
        cout << cnt << '\n';
    }

    return 0;
}