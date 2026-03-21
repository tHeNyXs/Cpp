#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
int up[N][60];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> up[i][0];
    }

    for (int i = 1; i < 60; ++i) {
        for (int j = 1; j <= n; ++j) {
            up[j][i] = up[ up[j][i-1] ][i-1];
        }
    }

    while (q--) {
        int x, k; cin >> x >> k;
        for (int i = 0; i < 60; ++i) {
            if (k & (1LL << i)) {
                x = up[x][i];
                // break;
            }
        }
        cout << x << '\n';
    }

    return 0;
}