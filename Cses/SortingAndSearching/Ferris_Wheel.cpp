#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, x; cin >> n >> x;
    int c[n]; for (int i = 0; i < n; ++i) cin >> c[i];
    sort(c, c+n);
    int l = 0, r = n-1;
    int cnt = 0;
    while (l <= r) {
        if (c[l]+c[r] <= x) {
            cnt++;
            l++;
            r--;
        }
        else {
            r--;
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}