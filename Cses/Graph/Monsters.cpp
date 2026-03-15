#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+5;
char vec[N][N];
int dist[N][N];
int vis[N][N];
int distM[N][N];
char path[N][N];
int n, m;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    memset(path, 'X', sizeof(path));
    memset(distM, 0x3f, sizeof(distM));
    int si, sj;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> vec[i][j];
            if (vec[i][j] == 'A') {
                si = i;
                sj = j;
                path[si][sj] = '\0';
            }
        }
    }

    int di[] = {-1, 1, 0, 0};
    int dj[] = {0, 0, -1, 1};
    char staus[] = {'U', 'D', 'L', 'R'};
    queue<pair<int, int>> q;
    q.emplace(si, sj);
    vis[si][sj] = true;
    while (!q.empty()) {
        auto[i, j] = q.front(); q.pop();
        for (int k = 0; k < 4; ++k) {
            int ni = i+di[k];
            int nj = j+dj[k];
            if (ni <= 0 || ni > n || nj <= 0 || nj > m || vis[ni][nj] || vec[ni][nj] == '#') continue;
            dist[ni][nj] = dist[i][j] + 1;
            vis[ni][nj] = true;
            path[ni][nj] = staus[k];
            q.emplace(ni, nj);
        }
    }

    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 1; j <= m; ++j) {
    //         cout << dist[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (vec[i][j] == 'M') {
                q.emplace(i, j);
                distM[i][j] = 0;
                vis[i][j] = true;
            }
        }
    }

    while (!q.empty()) {
        auto[i, j] = q.front(); q.pop();
        for (int k =  0; k < 4; ++k) {
            int ni = i+di[k];
            int nj = j+dj[k];
            if (ni <= 0 || ni > n || nj <= 0 || nj > m || vis[ni][nj] || vec[ni][nj] == '#') continue;
            distM[ni][nj] = distM[i][j]+1;
            vis[ni][nj] = true;
            q.emplace(ni, nj);
        }
    }

    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 1; j <= m; ++j) {
    //         cout << dist[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 1; j <= m; ++j) {
    //         cout << distM[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (distM[i][j] <= dist[i][j]) path[i][j] = 'X';
        }
    }

    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 1; j <= m; ++j) {
    //         cout << path[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    int ei, ej;
    ei = ej = -1;
    for (int i = 1; i <= n; ++i) {
        if (path[i][1] != 'X') {
            ei = i;
            ej = 1;
        }
        else if (path[1][i] != 'X') {
            ei = 1;
            ej = i;
        }
        else if (path[n][i] != 'X') {
            ei = n;
            ej = i;
        }
        else if (path[i][m] != 'X') {
            ei = i;
            ej = m;
        }
    }

    if (ei == -1 || ej == -1) cout << "NO";
    else {
        cout << "YES\n";
        string ans = "";
        // cout << si << ei << sj << ej;
        while (ei != si || ej != sj) {
            for (int i = 0; i < 4; ++i) {
                if (staus[i] == path[ei][ej]) {
                    ans += path[ei][ej];
                    ei -= di[i];
                    ej -= dj[i];
                    break;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        cout << ans;
    }

    return 0;
}