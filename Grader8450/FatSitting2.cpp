#include <bits/stdc++.h>
using namespace std;

#define N 6005

int n;
vector<vector<int>> dist(2, vector<int>(N, INT_MAX));
vector<int> graph[N];

void bfs(queue<pair<int, int>> &q, int p) {
    while (!q.empty()) {
        auto[u, cnt] = q.front(); q.pop();
        for (int v : graph[u]) {
            if (dist[p][v] <= cnt+1) continue;
            dist[p][v] = cnt+1;
            q.emplace(v, cnt+1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    int p1; cin >> p1;
    queue<pair<int, int>> q1;
    for (int i = 0, s; i < p1; ++i) {
        cin >> s;
        q1.emplace(s, 0);
        dist[0][s] = 0;
    }

    int p2; cin >> p2;
    queue<pair<int, int>> q2;
    for (int i = 0, s; i < p2; ++i) {
        cin >> s;
        q2.emplace(s, 0);
        dist[1][s] = 0;
    }

    for (int u = 1; u <= n; ++u) {
        int m; cin >> m;
        while (m--) {
            int v; cin >> v;
            graph[u].emplace_back(v);
        }
    }

    bfs(q1, 0);
    bfs(q2, 1);

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