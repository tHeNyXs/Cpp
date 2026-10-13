#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int q; cin >> q;
    while (q--) {
        int n; cin >> n;
        int h[n];
        int minn = 7, maxx = 0;
        for (int i = 0; i < n; ++i) {
            cin >> h[i];
            minn = min(minn, h[i]);
            maxx = max(maxx, h[i]);
        }
        cout << maxx - minn + 1 << '\n';
    }

    return 0;
}