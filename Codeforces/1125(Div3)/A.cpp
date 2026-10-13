#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    int num[n];
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }

    sort(num, num+n);
    unordered_map<int, pair<int, int>> minMax;
    for (int i = 0; i < n; ++i) {
        int curr = num[i];
        if (!minMax.count(curr)) {
            minMax[curr].first = minMax[curr].second = i;
        }
        else {
            minMax[curr].second = i;
        }
    }

    int ans = 2e9;
    for (auto[key, value] : minMax) {
        auto [prev, next] = value;
        next = n-next-1;
        // cout << "Key : " << key << " | Prev : " << prev << " | Next : " << next << '\n';
        int same = min(prev, next);
        if (prev > next) same += prev-same;
        else if (next > prev) same += next-same;
        ans = min(ans, same);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int q; cin >> q;
    while (q--) solve();

    return 0;
}