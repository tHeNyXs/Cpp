#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> vec;
int n, m;
int sumV, sumK;
int tempV, tempK;

int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, -1, 1};

void dfs(int x, int y) {
    if (vec[x][y] == 'k') tempK++;
    else if (vec[x][y] == 'v') tempV++;
    vec[x][y] = '#';
    for (int i = 0; i < 4; ++i) {
        int ni = x+di[i];
        int nj = y+dj[i];
        if (ni <= 0 || ni > n || nj <= 0 || nj > m || vec[ni][nj] == '#') continue;
        dfs(ni, nj);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    vec.resize(n+1, vector<char>(m+1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> vec[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (vec[i][j] != '#') {
                tempV = tempK = 0;
                dfs(i, j);
                if (tempK > tempV) sumK += tempK;
                else sumV += tempV;
                // cout << "I : " << i << " | J : " << j << '\n';
                // cout << tempV << " : " << tempK << "\n\n";
            }
        }
    }
    cout << sumK << " " << sumV;

    return 0;
}