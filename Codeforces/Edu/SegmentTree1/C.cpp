#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
const int inf = 1e9+5;
int min_ans, cnt_ans;

struct segment_tree {
    int t[4*N];
    int cnt_min[4*N];
    segment_tree() {
        fill(t, t+4*N, inf);
        fill(cnt_min, cnt_min+4*N, 1);
    }
    
    void update(int l, int r, int idx, int val, int p) {
        if (l > idx || r < idx) return;
        if (idx <= l && r <= idx) {
            t[p] = val;
            cnt_min[p] = 1;
            return;
        }
        int mid = (l+r)/2;
        update(l, mid, idx, val, p*2);
        update(mid+1, r, idx, val, p*2+1);
        t[p] = min(t[p*2], t[p*2+1]);
        if (t[p*2] == t[p*2+1]) {
            cnt_min[p] = cnt_min[p*2]+cnt_min[p*2+1];
        }
        else if (t[p] == t[p*2]) cnt_min[p] = cnt_min[p*2];
        else cnt_min[p] = cnt_min[p*2+1];
    }

    void query(int l, int r, int wl, int wr, int p) {
        if (l > wr || r < wl) return;
        if (wl <= l && r <= wr) {
            if (t[p] < min_ans) {
                min_ans = t[p];
                cnt_ans = cnt_min[p];
            }
            else if (t[p] == min_ans) {
                cnt_ans += cnt_min[p];
            }
            return;
        }
        int mid = (l+r)/2;
        query(l, mid, wl, wr, p*2);
        query(mid+1, r, wl, wr, p*2+1);
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
            min_ans = inf; cnt_ans = 0;
            seg.query(1, n, l+1, r, 1);
            cout << min_ans << " " << cnt_ans << '\n';
        }
    }

    return 0;
}