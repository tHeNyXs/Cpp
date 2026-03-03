#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 5;
    while (q--) {
        int n; cin >> n;
        vector<int> graph1[n + 1], graph2[n + 1];
        for (int i = 0, u, v; i < n - 1; ++i) {
            cin >> u >> v;
            (u < v ? graph1[u].emplace_back(v) : graph1[v].emplace_back(u));
        }
        for (int i = 0, u, v; i < n - 1; ++i) {
            cin >> u >> v;
            (u < v ? graph2[u].emplace_back(v) : graph2[v].emplace_back(u));
        }
        bool flag = true;
        for (int u = 1; u <= n; ++u) {
            priority_queue<int> pq1, pq2;
            for (int v : graph1[u]) {
                pq1.push(v);
            }
            for (int v : graph2[u]) {
                pq2.push(v);
            }
            if (pq1.size() != pq2.size()) {
                flag = false;
                // cout << "hello\n";
                break;
            }
            while (!pq1.empty()) {
                if (pq1.top() != pq2.top()) {
                    flag = false;
                    break;
                }
                pq1.pop(); pq2.pop();
            }
        }
        cout << (flag ? "Y" : "N");
    }

    return 0;
}