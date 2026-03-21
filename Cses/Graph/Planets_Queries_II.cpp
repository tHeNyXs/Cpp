#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5+5;
ll up[N][60];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> up[i][0];
    }

    for (int j = 0; j < 60; ++j) {
        for (int i = 1; i <= n; ++i) {
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }

    while (q--) {
        int start, end;
        ll ans = 0;
        
    }

    return 0;
}