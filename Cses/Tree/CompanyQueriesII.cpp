#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
const int LOG = 20;
int lg[N];
int table[LOG][N];
int h[N];
vector<int> graph[N];

void dfs(int u) {
    for (int v : graph[u]) {
        h[v] = h[u]+1;
        dfs(v);
    }
}

int find_ans(int x, int y) {
    for (int i = LOG-1; i >= 0; --i) {
        if (h[table[i][y]] < h[x]) continue;
        y = table[i][y];
    }
    // cout << h[x] << " : " << h[y] << '\n';
    if (x == y) return x;

    for (int i = LOG-1; i >= 0; --i) {
        if (table[i][x] == table[i][y]) continue;
        x = table[i][x];
        y = table[i][y];
    }
    return table[0][x];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    lg[1] = 0;
    for (int i = 2; i < N; ++i) lg[i] = lg[i/2]+1;

    int n, q; cin >> n >> q;
    table[0][1] = 1;
    for (int i = 2; i <= n; ++i) {
        cin >> table[0][i];
        graph[table[0][i]].emplace_back(i);
    }

    for (int i = 1; i < LOG; ++i) {
        for (int j = 1; j <= n; ++j) {
            table[i][j] = table[i-1][ table[i-1][j] ];
        }
    }

    h[1] = 0;
    dfs(1);

    while (q--) {
        int x, y; cin >> x >> y;
        if (h[x] > h[y]) swap(x, y);
        cout << find_ans(x, y) << '\n';
    }

    return 0;
}