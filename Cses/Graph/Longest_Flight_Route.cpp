#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<int> graph[n+1];
    int cnt[n+1] = {0};
    while (m--) {
        int u, v; cin >> u >> v;
        graph[u].emplace_back(v);
        cnt[v]++;
    }

    queue<int> q, topo;
    for (int i = 1; i <= n; ++i) {
        if (!cnt[i]) q.emplace(i);
    }
    q.emplace(1);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo.emplace(u);
        for (int v : graph[u]) {
            cnt[v]--;
            if (!cnt[v]) q.emplace(v);
        }
    }
    vector<int> dp(n+1, 0);
    dp[1] = 1;
    vector<int> p(n+1);
    iota(p.begin(), p.end(), 0);
    while (!topo.empty()) {
        int u = topo.front(); topo.pop();
        for (int v : graph[u]) {
            if (dp[u] && dp[u]+1 > dp[v]) {
                dp[v] = dp[u]+1;
                p[v] = u;
            }
        }
    }

    if (dp[n] == 0) cout << "IMPOSSIBLE";
    else {
        vector<int> ans;
        int temp = n;
        while (temp != 1) {
            ans.emplace_back(temp);
            temp = p[temp];
        }
        ans.emplace_back(1);
        cout << ans.size() << '\n';
        reverse(ans.begin(), ans.end());
        for (int i : ans) cout << i << " ";
    }

    return 0;
}