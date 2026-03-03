#include <bits/stdc++.h>
using namespace std;
int maxx, n;
vector<vector<int>> b;
int di[4] = {-1, 1, 0, 0};
int dj[4] = {0, 0, -1, 1};
void dfs(int i, int j) {
    for (int k = 0; k < 4; ++k) {
        int ni = i + di[k];
        int nj = j + dj[k];
        if (ni < 1 || nj < 1 || ni > n || nj > n || b[ni][nj] <= b[i][j] || b[ni][nj] == 100) continue;
        maxx = max(maxx, b[ni][nj]);
        dfs(ni, nj);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    int si, sj;
    cin >> sj >> si;
    b.resize(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> b[i][j];
        }
    }
    maxx = b[si][sj];
    dfs(si, sj);
    cout << maxx;

    return 0;
}