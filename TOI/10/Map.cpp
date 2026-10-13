#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<pair<int, char>> graph[n*m];
    map<pii, int> mp;
    for (int i = 1; i < n*m; ++i) {
        int a, b; char c;
        cin >> a >> c >> b;
        char op;
        if (c == 'U') op = 'D';
        else op = 'R';
        graph[a].emplace_back(b, op);
        graph[b].emplace_back(a, c);
    }

    vector<bool> vis(n*m, false);
    mp[{0, 0}] = 0;
    vis[0] = true;
    queue<pair<pii, int>> q;
    q.emplace(pii(0, 0), 0);
    while (!q.empty()) {
        auto[p, u] = q.front(); q.pop();
        for (auto[v, op] : graph[u]) {
            if (vis[v]) continue;
            vis[v] = true;
            int x = p.first, y = p.second;
            if (op == 'U') x--;
            else if (op == 'D') x++;
            else if (op == 'L') y--;
            else y++;
            mp[{x, y}] = v;
            q.emplace(pii(x, y), v);
        }
    }
    int cnt = 0;
    for (auto i : mp) {
        cout << i.second << " ";
        cnt++;
        if (cnt == m) {
            cout << '\n';
            cnt = 0;
        }
    }

    return 0;
}