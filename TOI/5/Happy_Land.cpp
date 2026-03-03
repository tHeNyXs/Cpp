#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

int m, n;
vector<vector<double>> land;
int di[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dj[] = {-1, 0, 1, -1, 1, -1, 0, 1};
vector<vector<bool>> vis;
double findAns(int ni, int nj, int cnt, double sum) {
    if (cnt == m * n) {
        return sum;
    }

    vector<pii> update;
    double value = land[ni][nj] * .1;
    for (int i = 0; i < 8; ++i) {
        int nni = ni + di[i];
        int nnj = nj + dj[i];
        if (nni < 0 || nni >= m || nnj < 0 || nnj >= n) continue;
        land[nni][nnj] += value;
        update.emplace_back(nni, nnj);
    }
    
    double result = 1e18;
    vis[ni][nj] = true;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!vis[i][j]) {
                result = min(result, findAns(i, j, cnt + 1, sum + land[i][j]));
            }
        }
    }
    vis[ni][nj] = false;

    for (auto[i, j] : update) {
        land[i][j] -= value;
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> m >> n;
    land.resize(m, vector<double>(n));
    vis.resize(m, vector<bool>(n, false));
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j) {
            cin >> land[i][j];
        }
    }

    double ans = 1e18;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            ans = min(ans, findAns(i, j, 1, land[i][j]));
        }
    }
    printf("%.2lf", ans);

    return 0;
}