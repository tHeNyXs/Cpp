#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define pi pair<int, pii>

const int N = 3005;
int mat[N][N];
bool vis[N];
int p[N];
int ans[N][N];
vector<pii> graph[N];

int find(int u) {
    if (p[u] == u) return u;
    return p[u] = find(p[u]);
}

void dfs(int now, int u, int val) {
    for (auto[w, v] : graph[u]) {
        if (vis[v]) continue;
        vis[v] = true;
        ans[now][v] = ans[v][now] = val+w;
        dfs(now, v, val+w);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    iota(p, p+N, 0);
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    for (int i = 1; i < n; ++i) {
        for (int j = i+1; j <= n; ++j) {
            int w; cin >> w;
            pq.emplace(pi(w, pii(i, j)));
            pq.emplace(pi(w, pii(j, i)));
            mat[i][j] = mat[j][i] = w;
        }
    }

    int cnt = 0;
    while (!pq.empty()) {
        auto[w, _] = pq.top(); pq.pop();
        auto[u, v] = _;
        int pu = find(u), pv = find(v);
        if (pu == pv) continue;
        p[pu] = pv;
        graph[u].emplace_back(w, v);
        graph[v].emplace_back(w, u);
        ans[u][v] = ans[v][u] = w;
        cnt++;
        if (cnt == n-1) break;
    }

    for (int i = 1; i <= n; ++i) {
        memset(vis, false, sizeof(vis));
        vis[i] = true;
        dfs(i, i, 0);
    }



    for (int i = 1; i < n; ++i) {
        for (int j = i+1; j <= n; ++j) {
            if (ans[i][j] != mat[i][j]) {
                cout << "No";
                return 0;
            }
            // cout << ans[i][j] << " ";
        }
        // cout << '\n';
    }
    cout << "Yes";

    return 0;
}