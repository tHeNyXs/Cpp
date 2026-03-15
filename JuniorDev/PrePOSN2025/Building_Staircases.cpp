#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, k; cin >> n >> k;
    int h[n];
    for (int i = 0; i < n; ++i) cin >> h[i];
    int minn = *min_element(h, h+n);
    int l = 0, r = minn;
    int ans = -1;
    while (l <= r) {
        int mid = (l+r)/2;
        multiset<int> s;
        for (int i = 0; i < n; ++i) {
            auto it = s.lower_bound(h[i] + mid);
            if (it == s.end()) s.emplace(h[i]);
            else {
                s.erase(it);
                s.emplace(h[i]);
            }
        }
        if (s.size() <= k) {
            ans = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    cout << ans;

    return 0;
}