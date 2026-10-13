#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

struct Seg {
    vector<int> t;

    Seg(int n) {
        t.resize(4*n, 1e9);
    }

    void update(int l, int r, int idx, int val, int p) {
        if (r < idx || l > idx) return;
        if (r == l) {
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
        if (wl <= l && r <= wr) {
            return t[p];
        }
        int mid = (l+r)/2;
        int L = query(l, mid, wl, wr, p*2);
        int R = query(mid+1, r, wl, wr, p*2+1);
        return min(L, R);
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, q; cin >> n >> q;
    Seg seg(n);
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        seg.update(1, n, i, x, 1);
    }
    
    while (q--) {
        int l, r; cin >> l >> r;
        cout << seg.query(1, n, l, r, 1) << '\n';
    }

    return 0;
}