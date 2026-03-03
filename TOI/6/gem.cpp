#include <bits/stdc++.h>
using namespace std;
const int MxN = 1e5 + 5;
const int MxM = 2e5 + 5;
vector<int> graph[MxM * 2];
bool inStk[MxM * 2];
int dfn[MxM * 2], comp[MxM * 2], low[MxM * 2];
int cntOrder, cntComp;
stack<int> s;

void tajan(int u) {
    dfn[u] = low[u] = cntOrder++;
    s.push(u);
    inStk[u] = true;
    for (int v : graph[u]) {
        if (!dfn[v]) {
            tajan(v);
            low[u] = min(low[u], low[v]);
        } else if (inStk[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }

    if (low[u] == dfn[u]) {
        while(true) {
            int now = s.top(); s.pop();
            comp[now] = cntComp;
            inStk[now] = false;
            if (now == u) break;
        }
        cntComp++;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 5;
    while (q--) {
        int n, m; cin >> n >> m;
        for (int i = 1; i <= 2*m; ++i)
            graph[i].clear();
        memset(inStk, 0, sizeof(inStk));
        memset(dfn, 0, sizeof(dfn));
        memset(comp, 0, sizeof(comp));
        memset(low, 0, sizeof(low));
        cntOrder = cntComp = 1;
        while (!s.empty()) s.pop();
        for (int i = 0, x, y; i < n; ++i) {
            cin >> x >> y;
            graph[x + m].emplace_back(y);
            graph[y + m].emplace_back(x);
        }
        for (int i = 0, x, y; i < m / 2; ++i) {
            cin >> x >> y;
            graph[x].emplace_back(y + m);
            graph[y].emplace_back(x + m);
        }

        for (int u = 1; u <= m * 2; ++u) {
            if (comp[u])  continue;
            tajan(u);
        }

        bool flag = false;
        for (int i = 1; i <= m; ++i) {
            if (comp[i] == comp[i + m]) {
                flag = true;
                break;
            }
        }
        cout << (flag ? "N" : "Y");
    }        

    return 0;
}