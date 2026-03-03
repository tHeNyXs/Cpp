#include <bits/stdc++.h>
using namespace std;

int m, n;
unordered_map<int, int> b;
vector<int> ans;
bool vis[2][1005][1005];
int g[1005][1005];
int di[] = {-1, 0, 1, 0};
int dj[] = {0, 1, 0, -1};

int dfs(int c, int r, int d) {
    int len = 0;
    while (c >= 0 && c < m && r >= 0 && r < n) {
        if (!(b[g[c][r]] & (1 << (d+2)%4))) break;
        if (vis[g[c][r] == 31 ? (d&1) : 0][c][r]) break;
        vis[g[c][r] == 31 ? (d&1) : 0][c][r] = true;
        len++;
        if (g[c][r] != 31) {
            for (int i = 0; i < 4; ++i) {
                if (i == (d + 2) % 4) continue;
                if (b[g[c][r]] & (1 << i)) {
                    d = i;
                    break;
                }
            }
        }
        c += di[d];
        r += dj[d];

        // for (int i = 0; i < m; ++i) {
        //     for (int j = 0; j < n; ++j) {
        //         cout << g[i][j] << " ";
        //     }
        //         cout << '\n';
        // }
        // cout << "ans : " << ans.size() << " | len : " << len << '\n';
        // cout << "c : " << c << " | r : " << r << " | d : " << d << '\n';
        // cout << "----------------------------------------------------------------------------------------\n";

    }
    return len;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
        }
    }
    b[0] = 0;
    b[11] = 9;
    b[12] = 3;
    b[13] = 12;
    b[14] = 6;
    b[21] = 5;
    b[22] = 10;
    b[31] = 15;

    for (int j = 0; j < n; ++j) {
        if (b[g[0][j]] & 1) {
            int len = dfs(0, j, 2);
            if (len) ans.emplace_back(len);
        }
    }

    for (int j = 0; j < n; ++j) {
        if (b[g[m-1][j]] & 4) {
            int len = dfs(m-1, j, 0);
            if (len) ans.emplace_back(len);
        }
    }

    for (int i = 0; i < m; ++i) {
        if (b[g[i][0]] & 8) {
            int len = dfs(i, 0, 1);
            if (len) ans.emplace_back(len);
        }
    }

    for (int i = 0; i < m; ++i) {
        if (b[g[i][n-1]] & 2) {
            int len = dfs(i, n-1, 3);
            if (len) ans.emplace_back(len);
        }
    }

    cout << ans.size() << '\n';
    for (int num : ans) {
        cout << num << " ";
    }


    return 0;
}