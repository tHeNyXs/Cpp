#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int q = 20;
    while (q--) {
        ll m, n; cin >> m >> n;
        ll ans = 0;
        if (m%2) ans = 0;
        else if (m/2 - n < 0) ans = 0;
        else ans = 2*n - m/2 + 1;
        ans = max(ans, 1LL*0);
        cout << ans << '\n';
    }

    return 0;
}