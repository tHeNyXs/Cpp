#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+5;
struct segment_tree{
    int t[4*N];

    void update(int l, int r, int idx, int val, int p) {
        if (l > idx || r < idx) return;
        if (l == r) {
            t[p] = val;
            return;
        }
        int mid = (l+r)/2;
        update(l, mid, idx, val, p*2);
        update(mid+1, r, idx, val, p*2+1);
        t[p] = t[p*2] + t[p*2+1];
    }

    int query(int l, int r, int wl, int wr, int p) {
        if (l > wr || r < wl) return 0;
        if (wl <= l && r <= wr) return t[p];
        int mid = (l+r)/2;
        int L = query(l, mid, wl, wr, p*2);
        int R = query(mid+1, r, wl, wr, p*2+1);
        return L+R;
    }
};

segment_tree seg;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        seg.update(1, n, i, x, 1);
    }

    while (m--) {
        int o; cin >> o;
        if (o == 1) {
            int i, v; cin >> i >> v;
            i++;
            seg.update(1, n, i, v, 1);
        }
        else {
            int l, r; cin >> l >> r;
            cout << seg.query(1, n, l+1, r, 1) << '\n';
        }
    }

    return 0;
}