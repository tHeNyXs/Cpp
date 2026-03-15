#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].first >> p[i].second;
    }

    sort(p.begin(), p.end());
    int ans = 0;
    int l = 0, r = n-1;
    while (l < r) {
        int pl = p[l].first, pr = p[r].first;
        int vl = p[l].second, vr = p[r].second;
        int value = (pr-pl) * min(vl, vr);
        ans = max(ans, value);
        if (vl > vr) r--;
        else l++;
    }

    cout << ans;

    return 0;
}