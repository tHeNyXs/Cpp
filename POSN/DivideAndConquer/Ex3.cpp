#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<ll> arr(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll ans = -1e18;
    ll pfs = 0;
    for (int i = 1; i <= n; ++i) {
        pfs += arr[i];
        ans = max(ans, pfs);
        if (!pq.empty()) {
            ans = max(ans, pfs-pq.top());
        }
        pq.emplace(pfs);
    }
    cout << ans;

    return 0;
}