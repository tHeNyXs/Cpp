#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<bool>> room;
int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, -1, 1};

void dfs(int x, int y) {
    for (int i = 0; i < 4; ++i) {
        int ni = x+di[i];
        int nj = y+dj[i];
        if (ni < 0 || ni >= n || nj < 0 || nj >= m || !room[ni][nj]) continue;
        room[ni][nj] = false;
        dfs(ni, nj);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    room.resize(n, vector<bool>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char a; cin >> a;
            if (a == '.') room[i][j] = true;
            else room[i][j] = false;
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (room[i][j]) {
                room[i][j] = false;
                dfs(i, j);
                cnt++;
                // cout << "I : " << i << " | J : " << j << '\n';
            }
        }
    }

    cout << cnt;

    return 0;
}