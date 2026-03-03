#include <bits/stdc++.h>
using namespace std;

#define N 1505

int n;
vector<vector<int>> dist(2, vector<int>(N, INT_MAX));
vector<int> graph[N];

void dfs(int u, int cnt, int p) {
    for (int v : graph[u]) {
        if (dist[p][v] <= cnt+1) continue;
        dist[p][v] = cnt+1;
        dfs(v, cnt+1, p);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    int s1, s2; cin >> s1 >> s2;
    for (int u = 1; u <= n; ++u) {
        int m; cin >> m;
        while (m--) {
            int v; cin >> v;
            graph[u].emplace_back(v);
        }
    }
    dist[0][s1] = 0;
    dist[1][s2] = 0;
    dfs(s1, 0, 0);
    dfs(s2, 0, 1);

    // for (int i = 0; i < 2; ++i) {
    //     for (int j = 1; j <= n; ++j) {
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    int b; cin >> b;
    int cnt[3] = {0, 0, 0};
    while (b--) {
        int x; cin >> x;
        if (dist[0][x] < dist[1][x]) cnt[0]++;
        else if (dist[0][x] > dist[1][x]) cnt[1]++;
        else cnt[2]++;
    }

    for (int i : cnt) {
        cout << i << ' ';
    }

    return 0;
}