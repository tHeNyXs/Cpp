#include <bits/stdc++.h>
using namespace std;

#define MaxM 40 + 1
#define MaxT 100 + 1
int m, n, t;
int road[MaxT][MaxM];
bool flag;
void dfs(vector<int> path, int now) {
    int size = path.size();
    if (size == t) {
        flag = true;
        for (int i : path) {
            cout << i << '\n';
        }
    }
    if (flag) return;
    
    if (now != 1) {
        if (!road[size + 1][now - 1]) {
            vector<int> temp = path;
            temp.emplace_back(1);
            dfs(temp, now - 1);
        }
    }
    if (now != m) {
        if (!road[size + 1][now + 1]) {
            vector<int> temp = path;
            temp.emplace_back(2);
            dfs(temp, now + 1);
        }
    }
    if (!road[size+ 1][now]) {
        vector<int> temp = path;
        temp.emplace_back(3);
        dfs(temp, now);
    }

}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> m >> n >> t;
    for (int i = 1; i <= t; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> road[i][j];
        }
    }

    vector<int> path;
    dfs(path, n);

    return 0;
}