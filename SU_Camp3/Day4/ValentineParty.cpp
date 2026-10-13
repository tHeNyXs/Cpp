#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;

struct fw {
    int t[N];

    fw() {
        memset(t, 0, sizeof(t));
    }

    void update(int idx, int val) {
        while (idx < N) {
            t[idx] += val;
            idx += idx & -idx;
        }
    }

    int sum(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += t[idx];
            idx -= idx & -idx;
        }
        return sum;
    }

};

fw f;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, p; cin >> n >> p;
    while (p--) {
        int a, k, d, q; cin >> a >> k >> d >> q;
        int l = a-k, r = a+k;
        if (l <= 0) l += n;
        if (r > n) r -= n;
        if (l <= r) {
            f.update(l, d);
            f.update(r+1, -d);
        }
        else {
            f.update(1, d);
            f.update(r+1, -d);
            f.update(l, d);
        }

        // cout << "L : " << l << " | R : " << r << '\n';
        // for (int i = 1; i <= n; ++i) {
        //     cout << f.sum(i) << " ";
        // }
        // cout << '\n';

        while (q--) {
            int x; cin >> x;
            cout << max(0, 10000-f.sum(x)) << ' ';
        }
        cout << '\n';
    }

    return 0;
}