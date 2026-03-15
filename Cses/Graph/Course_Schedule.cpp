#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> graph[N];
vector<int> cnt(N, 0);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        graph[u].emplace_back(v);
        cnt[v]++;
    }

    queue<int> ans, q;
    for (int i = 1; i <= n; ++i) {
        if (cnt[i] == 0) {
            q.emplace(i);
        }
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        ans.emplace(u);
        for (int v : graph[u]) {
            cnt[v]--;
            if (!cnt[v]) q.emplace(v);
        }
    }
    if (ans.size() != n) cout << "IMPOSSIBLE";
    else {
        while (!ans.empty()) {
            cout << ans.front() << " ";
            ans.pop();
        }    
    }

    return 0;
}