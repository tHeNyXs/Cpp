#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<ll> c(n);
    for (int i = 0; i < n; ++i) cin >> c[i];
    sort(c.begin(), c.end());

    ll ans = 1;
    for (int i = 0; i < n; ++i) {
        if (c[i] > ans) break;
        ans += c[i];
    }

    cout << ans;
}