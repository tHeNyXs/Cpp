#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> graph[N];
vector<bool> vis(N, false);
vector<int> p(N);
vector<bool> inStk(N, false);
int cycle = -1;
void dfs(int u) {
    if (cycle != -1) return;
    inStk[u] = true;
    for (int v : graph[u]) {
        if (cycle != -1) return;
        if (inStk[v]) {
            cycle = v;
            p[cycle] = u;
            return;
        }
        if (vis[v]) continue;
        vis[v] = true;
        p[v] = u;
        dfs(v);
    }
    inStk[u] = false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    iota(p.begin(), p.end(), 0);
    int n, m; cin >> n >> m;
    while (m--) {
        int u, v; cin >> u >> v;
        graph[u].emplace_back(v);
    }

    for (int i = 1; i <= n; ++i) {
        if (cycle != -1) break;
        if (vis[i]) continue;
        vis[i] = true;
        dfs(i);
    }
    
    if (cycle == -1) cout << "IMPOSSIBLE";
    else {
        // for (int i = 0; i < n; ++i) cycle = p[cycle];
        vector<int> ans;
        ans.emplace_back(cycle);
        int temp = p[cycle];
        while (temp != cycle) {
            ans.emplace_back(temp);
            temp = p[temp];
        }
        ans.emplace_back(temp);
        reverse(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for (int i : ans) cout << i << " ";
    }

    return 0;
}