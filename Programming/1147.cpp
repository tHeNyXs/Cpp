#include <bits/stdc++.h>
using namespace std;

const int N = 262144+5;
const int inf = 1e9+5;
struct segment_tree {
    int t[4*N];
    void build(int l, int r, int w, int v, int p) {
        if (l > w || r < w) return;
        if (l == r) {
            t[p] = v;
            return;
        }
        int mid = (l+r)/2;
        build(l, mid, w, v, p*2);
        build(mid+1, r, w, v, p*2+1);
        t[p] = max(t[p*2], t[p*2+1]);
    }


    int query(int l, int r, int wl, int wr, int p) {
        if (l > wr || r < wl) return -inf;
        if (wl <= l && r <= wr) return t[p];
        int mid = (l+r)/2;
        int L = query(l, mid, wl, wr, p*2);
        int R = query(mid+1, r, wl, wr, p*2+1);
        return max(L, R);
    }
};

segment_tree t;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, q; cin >> n >> q;
    while (q--) {
        char o; cin >> o;
        if (o == 'U') {
            int i, z; cin >> i >> z;
            t.build(1, n, i, z, 1);
        }
        else {
            int l, r; cin >> l >> r;
            cout << t.query(1, n, l, r, 1) << '\n';
        }
    }

    return 0;
}