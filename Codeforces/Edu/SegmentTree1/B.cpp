#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
const int inf = 1e9+5;

struct segment_tree {
    int t[4*N];

    void update(int l, int r, int idx, int val, int p) {
        if (l > idx || r < idx) return;
        if (idx <= l && r <= idx) {
            t[p] = val;
            return;
        }
        int mid = (l+r)/2;
        update(l, mid, idx, val, p*2);
        update(mid+1, r, idx, val, p*2+1);
        t[p] = min(t[p*2], t[p*2+1]);
    }

    int query(int l, int r, int wl, int wr, int p) {
        if (l > wr || r < wl) return inf;
        if (wl <= l && r <= wr) return t[p];
        int mid = (l+r)/2;
        int L = query(l, mid, wl, wr, p*2);
        int R = query(mid+1, r, wl, wr, p*2+1);
        return min(L, R);
    }
};

segment_tree seg;

int main() {
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
            seg.update(1, n, i+1, v, 1);
        }
        else {
            int l, r; cin >> l >> r;
            cout << seg.query(1, n, l+1, r, 1) << '\n';
        }
    }

    return 0;
}