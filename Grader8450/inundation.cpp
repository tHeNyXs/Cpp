#include <bits/stdc++.h>
using namespace std;

#define N 31

int c, r, t;
int d[N][N];
bool vis[N][N];
int cnt;

int di[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dj[] = {1, -1, 0, 1, -1, 1, -1, 0};

void dfs(int x, int y) {
    for (int i = 0; i < 8; ++i) {
        int nx = x + di[i];
        int ny = y + dj[i];
        if (nx < 0 || nx >= c || ny < 0 || ny >= r || vis[nx][ny] || d[nx][ny] > t) continue;
        vis[nx][ny] = true;
        cnt++;
        dfs(nx, ny);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin >> c >> r;
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < r; ++j) {
            cin >> d[i][j];
        }
    }

    cin >> t;
    multiset<int> ans;
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < r; ++j) {
            if (vis[i][j] || d[i][j] > t) continue;
            // cout << "I : " << i << " | J : " << j << '\n';
            vis[i][j] = true;
            cnt = 1;
            dfs(i, j);
            ans.insert(cnt);
        }
    }

    cout << ans.size() << "\n";
    for (int i : ans) {
        cout << i << '\n';
    }

    return 0;
}