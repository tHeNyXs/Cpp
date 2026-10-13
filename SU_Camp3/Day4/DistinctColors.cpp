#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
vector<vector<int>> graph(N);
set<int> s[N];
int ans[N];

void dfs(int u, int p) {
    for (int v : graph[u]) {
        if (v == p) continue;
        dfs(v, u);
        if (s[u].size() < s[v].size()) {
            swap(s[u], s[v]);
        }
        for (int i : s[v]) {
            s[u].emplace(i);
        }
    }
    ans[u] = s[u].size();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        s[i].emplace(x);
    }
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    dfs(1, 1);
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }

    return 0;
}