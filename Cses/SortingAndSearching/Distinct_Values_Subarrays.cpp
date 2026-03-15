#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    ll cnt = 0;
    ll x[n]; for (int i = 0; i < n; ++i) cin >> x[i];
    int l = 0;
    map<ll, bool> vis;
    for (int r = 0; r < n; ++r) {
        while (vis[x[r]]) {
            vis[x[l]] = false;
            l++;
        }
        vis[x[r]] = true;
        cnt += r-l+1;
        // cout << "L : " << l << " | R : " << r << " | CNT : " << cnt << '\n';
    }
    cout << cnt;

    return 0;
}