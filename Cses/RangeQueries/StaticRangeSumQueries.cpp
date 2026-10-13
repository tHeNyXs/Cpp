#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Fen {
    int n;
    vector<int> t;

    Fen(int n) {
        this->n = n;
        t.resize(n+1, 0);
    }

    void update(int idx, int val) {
        while (idx <= n) {
            t[idx] += val;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += t[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
};

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    Fen fw(n);
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        fw.update(i, x);
    }
    
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << fw.query(r) - fw.query(l-1) << '\n';
    }


    return 0;
}