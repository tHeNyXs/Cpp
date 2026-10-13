#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 8e4+5;
const int mod = 1e9-1;

struct fw{
    int t[N];

    fw() {
        memset(t, 0, sizeof(t));
    }

    void update(int idx, int val) {
        while (idx < N) {
            t[idx] += val;
            // t[idx] %= mod;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += t[idx];
            sum %= mod;
            idx -= idx & -idx;
        }
        return sum;
    }

};

fw fen[41];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, k; cin >> n >> k;
    int a[n+1];
    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = 1; i <= n; ++i) {
        fen[1].update(a[i], 1);
        // cout << "I : " << i << " | fen : " << fen[i].query(n) << '\n';
        for (int len = 2; len <= k; ++len) {
            int val = (fen[len-1].query(n) - fen[len-1].query(a[i]) + mod) % mod;
            // cout << "val : " << val << '\n';
            fen[len].update(a[i], val);
        }
    }

    cout << fen[k].query(n);


    return 0;
}