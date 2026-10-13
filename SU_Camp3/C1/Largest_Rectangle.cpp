#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    while (true) {
        int n; scanf("%lld",&n);
        if (n == 0) break;
        int t[n];
        int ans = 0;
        for (int i = 0; i < n; ++i) scanf("%lld", &t[i]);
        for (int i = 0; i < n; ++i) {
            int l = i, r = i;
            while (l >= 0 && t[l] >= t[i]) l--;
            l++;
            while (r < n && t[r] >= t[i]) r++;
            r--;
            ans = max(ans, (r-l+1)*t[i]);
        }
        printf("%lld\n", ans);
    }

    return 0;
}