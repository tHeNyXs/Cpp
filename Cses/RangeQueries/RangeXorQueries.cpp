#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

struct SegTree {
    int n;
    int t[4*N];
    SegTree (int n) {
        this->n = n;
    }

    void insert(int idx, int l, int r, int val) {
        if (idx < l || idx > r) return;
        int mid = (l+r)/2;
    }

};

SegTree seg(N);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, q; cin >> n >> q;


    return 0;
}