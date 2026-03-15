#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int a, b; cin >> a >> b;
    int t; cin >> t;
    if (t > max(a, b)) {
        cout << "-1\n";
        return 0;
    }
    else {
        vector<int> vis(max(a, b)+1, INT_MAX);
        vector<vector<bool>> check(a+1, vector<bool>(b+1, false));
        queue<pair<pair<int, int>, int>> q;
        q.emplace(make_pair(a, 0), 1); q.emplace(make_pair(0, b), 1);
        while (!q.empty()) {
            pair<pair<int, int>, int> temp = q.front(); q.pop();
            pair<int, int> t = temp.first;
            int cnt = temp.second;
            int x = t.first; int y = t.second;
            if (check[x][y]) continue;
            check[x][y] = true;
            // cout << "X : " << x << " | Y : " << y << '\n';
            vis[x] = min(vis[x], cnt); vis[y] = min(vis[y], cnt);

            // เติม
            q.emplace(make_pair(a, y), cnt+1);
            q.emplace(make_pair(x, b), cnt+1);

            // ทิ้ง
            q.emplace(make_pair(0, y), cnt+1);
            q.emplace(make_pair(x, 0), cnt+1);

            // เท 1 -> 2
            int pour = min(x, b-y);
            q.emplace(make_pair(x-pour, y+pour), cnt+1);

            // เท 2 -> 1
            pour = min(y, a-x);
            q.emplace(make_pair(x+pour, y-pour), cnt+1);
        }
        // for (int i = 1; i <= max(a, b); ++i) {
        //     cout << "I : " << i << " | cnt : " << vis[i] << '\n';
        // }
        if (vis[t] == INT_MAX) cout << -1;
        else cout << vis[t];
    }

    return 0;
}