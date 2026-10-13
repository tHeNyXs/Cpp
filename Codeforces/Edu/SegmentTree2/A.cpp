#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
#define int long long

struct segment_tree {
    int t[4*N];
    int lazy[4*N];
    
    segment_tree() {
        fill(t, t+4*N, 0);
        fill(lazy, lazy+4*N, 0);
    }

    void update(int l, int r, int wl, int wr, int val, int p) {
        if (l > wr || r < wl) return;
        if (wl <= l && r <= wr) {
            lazy[p] += val;
            return;
        }
        int mid = (l+r)/2;
        update(l, mid, wl, wr, val, p*2);
        update(mid+1, r, wl, wr, val, p*2+1);
    }

    void query(int l, int r, int idx, int p) {
        if (l > idx || r < idx) return;
        if (l == r) {
            t[p] += lazy[p];
            lazy[p] = 0;
            cout << t[p] << '\n';
            return;
        }
        int mid = (l+r)/2;
        t[p] += lazy[p];
        int L = p*2, R = p*2+1;
        lazy[L] += lazy[p]; lazy[R] += lazy[p];
        lazy[p] = 0;
        query(l, mid, idx, L);
        query(mid+1, r, idx, R);
    }
};

segment_tree seg;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    while (m--) {
        int o; cin >> o;
        if (o == 1) {
            int l, r, val;
            cin >> l >> r >> val;
            seg.update(1, n, l+1, r, val, 1);
        }
        else {
            int idx; cin >> idx;
            seg.query(1, n, idx+1, 1);
        }
    }

    return 0;
}