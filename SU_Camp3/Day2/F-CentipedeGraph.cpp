#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

vector<int> graph[N];
bool vis[N];
int ans;

int dfs(int u, int par) {
    int first, second;
    first = second = 0;
    for (int v : graph[u]) {
        if (v == par) continue;
        int val = dfs(v, u);
        if (val > first) {
            second = first;
            first = val;
        }
        else {
            second = max(second, val);
        }
    }
    
    if (graph[u].size() >= 4) {
        ans = max(ans, first+second+1);
        return 1+first;
    }
    else if (graph[u].size() == 3) {
        ans = max(ans, first+1);
        return 1;
    }
    else return 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int q; cin >> q;
    while (q--) {
        memset(vis, false, sizeof(vis));
        for (int i = 0; i < N; ++i) graph[i].clear();
        int n; cin >> n;
        for (int i = 1; i < n; ++i) {
            int u, v; cin >> u >> v;
            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
        }
        
        ans = 1;
        dfs(1, 1);
        // cout << '\n';
        cout << ans << "\n";
    }

    return 0;
}