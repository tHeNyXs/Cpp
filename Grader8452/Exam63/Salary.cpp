#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+5;
vector<int> graph[N];
ll money[N];

void give(int u) {
    for (int v : graph[u]) {
        money[v] += money[u];
        give(v);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int v = 2; v <= n; ++v) {
        int u; cin >> u;
        graph[u].emplace_back(v);
    }
    while (m--) {
        int u, k;
        cin >> u >> k;
        money[u] += k;
    }

    give(1);
    for (int i = 1; i <= n; ++i) cout << money[i] << " ";

    return 0;
}