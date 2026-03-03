#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> b;
int cnt, n, c, xc, yc;
int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, -1, 1};
void dfs(int i, int j, int num) {
    b[i][j] = 0;
    for (int k = 0; k < 4; ++k) {
        int ni = i + di[k];
        int nj = j + dj[k];
        if (ni < 0 || nj < 0 || ni >= n || nj >= n || b[ni][nj] != num) continue;
        if (di[k] != 0) yc++;
        if (dj[k] != 0) xc++;
        dfs(ni, nj, num);
        c++;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    b.resize(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> b[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (b[i][j] != 0) {
                c = 1;
                xc = yc = 0;
                dfs(i, j, b[i][j]);
                if (c == 3 && xc == 1 && yc == 1) cnt++;
                // cout << i << " " << j << '\n';
            }
        }
    }
    cout << cnt;

    return 0;
}