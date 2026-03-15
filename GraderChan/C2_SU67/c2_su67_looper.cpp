#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
vector<int> graph[N];
vector<int> dist(N, INT_MAX);
vector<int> minCycle(N, INT_MAX);
vector<bool> inStk(N, false);
vector<bool> vis(N, false);
vector<int> p(N, 0);
bool flag;

void cycle(int u) {
    vis[u] = inStk[u] = true;

    for (int v : graph[u]) {
        if (inStk[v]) {
            flag = true;
            vector<int> c;
            int temp = u;
            while (temp != v) {
                c.emplace_back(temp);
                temp = p[temp];
            }
            c.emplace_back(temp);
            for (int i : c) {
                minCycle[i] = min(minCycle[i], (int)c.size());
            }
            continue;
        }
        if (vis[v]) continue;
        p[v] = u;
        cycle(v);
    }

    inStk[u] = false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int ques; cin >> ques;
    while (ques--) {
        int n, m, k, s;
        cin >> n >> m >> k >> s;
        for (int i = 0; i < N; ++i) graph[i].clear();
        for (int i = 1; i <= m; ++i) {
            int u, v; cin >> u >> v;
            graph[u].emplace_back(v);
        }

        fill(dist.begin(), dist.end(), INT_MAX); fill(minCycle.begin(), minCycle.end(), INT_MAX);
        fill (inStk.begin(), inStk.end(), false); fill(vis.begin(), vis.end(), false);
        iota(p.begin(), p.end(), 0); flag = false;
        for (int i = 1; i <= n; ++i) {
            if (vis[i]) continue;
            cycle(i);
        }
        // for (int i = 1; i <= n; ++i) {
        //     cout << "I : " << i << " | Cycle : " << minCycle[i] << '\n';
        // }
        if (!flag && k > 1) {
            cout << "-1\n";
            continue;
        }

        fill(vis.begin(), vis.end(), false);
        queue<int> q;
        q.emplace(s);
        dist[s] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (vis[u]) continue;
            vis[u] = true;
            for (int v : graph[u]) {
                if (dist[u]+1 >= dist[v]) continue;
                dist[v] = dist[u]+1;
                q.emplace(v);
            }
        }
        int ans = INT_MAX;
        int town = -1;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INT_MAX) continue;
            int value = dist[i];
            if (k > 1) {
                if (minCycle[i] == INT_MAX) continue;
                else value += minCycle[i]*(k-1);
            }
            if (value < ans) {
                ans = value;
                town = i;
            }
        }
        cout << ans << " " << town << '\n';
    }

    return 0;
}