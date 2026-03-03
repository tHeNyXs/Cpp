#include <bits/stdc++.h>
using namespace std;

#define MaxN 8 + 1
bool ban[MaxN];
int n, m;

void dfs(vector<int> path) {
    if (path.size() == n) {
        for (int i : path) {
            cout << i << " ";
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (find(path.begin(), path.end(), i) != path.end()) continue;
        vector<int> temp = path;
        temp.emplace_back(i);
        dfs(temp);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0, x; i < m; ++i) {
        cin >> x;
        ban[x] = true;
    }

    for (int i = 1; i <= n; ++i) {
        if (ban[i]) continue;
        vector<int> temp = {i};
        dfs(temp);
    }

    return 0;
}