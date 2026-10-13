#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> a(n+1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    int cnt = n * (n+1) / 2;
    int l = 1;
    int sum1 = 0, sum0 = 0;
    for (int r = 1; r <= n; ++r) {
        if (a[r]) sum1++;
        else sum0++;
        while (sum0 > k || sum1 > k) {
            if (a[l]) sum1--;
            else sum0--;
            l++;
        }
        // cout << "CNT : " << cnt << '\n';
        cnt -= (r-l+1);
    }

    cout << cnt;

    return 0;
}