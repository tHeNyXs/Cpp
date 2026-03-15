#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    int l[n+1];
    for (int i = 1; i <= n; ++i) {
        cin >> l[i];
    }
    vector<vector<int>> graph(n+1);
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    for (int u = 1; u <= n; ++u) {
        vector<bool> dp(n+1, false);
        int need = l[u]-1;
        dp[0] = true;
        for (int v : graph[u]) {
            if (l[v] < l[u]) {
                for (int i = need; i >= l[v]; --i) {
                    if (dp[i - l[v]]) dp[i] = true;
                }
            }
        }
        if (!dp[need]) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";

    return 0;
}