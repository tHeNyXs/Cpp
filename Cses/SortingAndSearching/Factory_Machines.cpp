#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf = 1e18;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, t; cin >> n >> t;
    int k[n];
    for (int i = 0; i < n; ++i) cin >> k[i];

    ll l = 0, r = inf;
    ll ans;
    while (l < r) {
        ll mid = (l+r)/2;
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += mid / k[i];
            if (sum >= t) break;
        }
        if (sum >= t) {
            r = mid;
            ans = mid;
        }
        else l = mid+1;
    }
    cout << l;
 
    return 0;
}