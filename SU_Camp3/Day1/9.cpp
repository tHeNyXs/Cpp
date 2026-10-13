#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, q; cin >> n >> q;
    int pfs[n];
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if (i == 0) pfs[i] = x;
        else pfs[i] = pfs[i-1] + x;
    }
    for (int i = n-2; i >= 0; --i) {
        pfs[i] = min(pfs[i], pfs[i+1]);
    }
    
    while (q--) {
        int t; cin >> t;
        cout << upper_bound(pfs, pfs+n, t) - pfs << '\n';
    }

    return 0;
}