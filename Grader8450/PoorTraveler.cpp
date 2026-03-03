#include <bits/stdc++.h>
using namespace std;
class node {
    public:
        int v, c, t;
};

class travel {
    public:
        int now, c, t;
        vector<int> path;
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, k, p;
    cin >> n >> m >> k >> p;
    vector<node> graph[n];
    for (int i = 0, u, v, c, t; i < m; ++i) {
        cin >> u >> v >> c >> t;
        node temp;
        temp.v = v; temp.c = c; temp.t = t;
        graph[u].emplace_back(temp);
    }

    queue<travel> q;
    for (int i = 0; i < n; ++i) {
        travel temp;
        temp.now = i; temp.c = k; temp.t = p;
        vector<int> tempV; tempV.emplace_back(i);
        temp.path = tempV;
        q.emplace(temp);
    }

    vector<int> ans;
    while (!q.empty()) {
        auto[now, cost, time, path] = q.front(); q.pop();
        if (path.size() > ans.size()) ans = path;
        for (auto[v, c, t] : graph[now]) {
            if (find(path.begin(), path.end(), v) != path.end()) continue;
            if (cost - c < 0 || time - t < 0) continue;
            vector<int> temp = path;
            temp.emplace_back(v);
            travel tempTravel;
            tempTravel.now = v;
            tempTravel.path = temp;
            tempTravel.c = cost-c;
            tempTravel.t = time-t;
            q.emplace(tempTravel);
        }
    }
    cout << "Maximum cities reachable: " << ans.size() << "\n";
    cout << "Path: ";
    for (auto i : ans) {
        cout << i << " ";
    }

    return 0;
}