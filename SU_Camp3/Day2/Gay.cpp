#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<int> graph[N];
int vis[N];
int color[N];
bool flag;

void dfs(int u) {
    if (flag) return;
    vis[u] = true;
    for (int v : graph[u]) {
        if (color[u] == color[v] && v != u) {
            flag = true;
            return;
        }
        if (vis[v]) continue;
        if (color[u] == 1) color[v] = 2;
        else color[v] = 1;
        dfs(v);
        if (flag) return;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int q; cin >> q;
    while (q--) {
        memset(vis, false, sizeof(vis));
        memset(color, 0, sizeof(color));
        for (int i = 0; i < N; ++i) {
            graph[i].clear();
        }
        flag = false;
        int n, m; cin >> n >> m;
        while (m--) {
            int u, v; cin >> u >> v;
            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
        }

        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                color[i] = 1;
                dfs(i);
            }
        }

        cout << (flag ? "Gay found!\n" : "Gay not found!\n");
    }

    return 0;
}