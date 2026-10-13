#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, q; cin >> n >> q;
    int a[n+1]; for (int i = 1; i <= n; ++i) cin >> a[i];
    int mid = sqrt(n);
    // cout << mid << " ";
    int pfs[n+1][mid+1];
    memset(pfs, 0, sizeof(pfs));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= mid; ++j) {
            if (i-j >= 0) pfs[i][j] += pfs[i-j][j] + a[i];
        }
    }

    while (q--) {
        int l, m, r;
        cin >> l >> m >> r;
        if (m <= mid) {
            while ((r-l) % m) r--;
            cout << pfs[r][m] - pfs[l][m] + a[l] << ' ';
        }
        else {
            int sum = 0;
            for (int i = l; i <= r; i += m) sum += a[i];
            cout << sum << ' ';
        }
    }

    return 0;
}