#include <bits/stdc++.h>
using namespace std;
int main() {
    // ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    int num[n];
    for (int i = 0; i < n; ++i) cin >> num[i];
    int start, end;
    cin >> start >> end;
    vector<bool> vis(1001, false);
    queue<pair<int, int>> q;
    q.emplace(start, 0);
    int ans = INT_MAX;
    while (!q.empty()) {
        pair<int, int> front = q.front(); q.pop();
        int u = front.first; int cnt = front.second;
        if (u == end) {
            ans = min(cnt, ans);
            continue;
        }
        if (u < 0 || u > 1000) continue;
        if (cnt > ans) continue;
        if (vis[u]) continue;
        vis[u] = true;
        // cout << u << '\n';

        for (int i : num) {
            int now1 = u+i;
            int now2 = u-i;
            int now3 = u^i;
            q.emplace(now1, cnt+1);
            q.emplace(now2, cnt+1);
            q.emplace(now3, cnt+1);
        }
    }
    if (ans == INT_MAX) cout << -1;
    else cout << ans;

    return 0;
}