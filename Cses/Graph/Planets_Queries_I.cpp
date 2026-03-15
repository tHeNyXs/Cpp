#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int LOG = 60; // รองรับ k ถึง 10^18

int up[N][LOG];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> up[i][0]; // เดิน 1 step
    }

    // precompute jump table
    for (int j = 1; j < LOG; ++j) {
        for (int i = 1; i <= n; ++i) {
            up[i][j] = up[ up[i][j-1] ][j-1];
        }
    }

    while (q--) {
        long long x, k;
        cin >> x >> k;
        for (int j = 0; j < LOG; ++j) {
            if (k & (1LL << j)) {
                x = up[x][j];
            }
        }
        cout << x << '\n';
    }
}