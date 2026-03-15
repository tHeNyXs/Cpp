#include <bits/stdc++.h>
using namespace std;
int main() {
    int r, n; cin >> r >> n;
    int h[n];
    for (int i = 0; i < n; ++i) cin >> h[i];
    sort(h, h+n);

    int prev = 0;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int now = h[i];
        if (now <= prev) continue;
        prev = now+r+r;
        cnt++;
    }
    cout << cnt;

    return 0;
}