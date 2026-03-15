#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> graph[N];
vector<int> p(N, 0);
vector<int> ans;

void dfs(int u) {
    if (ans.size()) return;
    for (int v : graph[u]) {
        if (v == p[u]) continue;
        if (ans.size()) break;
        if (p[v]) {
            ans.emplace_back(v);
            int temp = u;

            while (temp != v) {
                ans.emplace_back(temp);
                temp = p[temp];
            }
            ans.emplace_back(v);
            return;
        }
        p[v] = u;
        dfs(v);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    for (int i = 1; i <= n; ++i) {
        if (p[i]) continue;
        queue<int> q;
        p[i] = i;
        dfs(i);
        if (ans.size()) break;
        // cout << "I : " << i << '\n';
    }

    if (ans.size() == 0) cout << "IMPOSSIBLE";
    else {
        cout << ans.size() << '\n';
        for (int i : ans) cout << i << " ";
    }

    return 0;
}