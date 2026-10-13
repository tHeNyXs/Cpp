#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pi pair<pii, int>
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<vector<char>> vec(n+1, vector<char>(m+1, 'X'));
    bool vis[n+1][m+1] = {0};
    vector<vector<int>> dist(n+1, vector<int>(m+1, 1e9));
    int si, sj, ei, ej;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> vec[i][j];
            if (vec[i][j] == 'S') {
                si = i; sj = j;
            }
            if (vec[i][j] == 'T') {
                ei = i;
                ej = j;
            }
        }
    }

    queue<pii> q;
    q.emplace(si, sj);
    vis[si][sj] = true;
    dist[si][sj] = 0;
    int di[] = {-1, 1, 0, 0};
    int dj[] = {0, 0, -1, 1};
    while (!q.empty()) {
        auto[i, j] = q.front(); q.pop();
        if (i == ei && j == ej) {
            continue;
        }
        for (int k = 0; k < 4; ++k) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if (ni <= 0 || ni > n || nj <= 0 || nj > m) continue;
            if (vec[ni][nj] == 'X') continue;
            dist[ni][nj] = min(dist[i][j]+1, dist[ni][nj]);
            q.emplace(ni, nj);  
            if (vec[ni][nj] == '#') {
                int x = ni+1;
                while (x <= n) {
                    q.emplace(x, nj);
                    vis[x][nj] = true;
                    dist[x][nj] = min(dist[x][nj], dist[ni][nj]+1);
                    x++;
                }
                x = ni-1;
                while (x >= 1) {
                    q.emplace(x, nj);
                    vis[x][nj] = true;
                    dist[x][nj] = min(dist[x][nj], dist[ni][nj]+1);
                    x--;
                }
                int y = nj+1;
                while (y <= m) {
                    q.emplace(ni, y);
                    vis[ni][y] = true;
                    dist[ni][y] = min(dist[ni][y], dist[ni][nj]+1);
                    y++;
                }
                y = nj-1;
                while (y >= 1) {
                    q.emplace(ni, y);
                    vis[ni][y] = true;
                    dist[ni][y] = min(dist[ni][y], dist[ni][nj]+1);
                    y--;
                }
            }
        }
        // cout << "I : " << i << " | J : " << j << '\n';
        // for (int i = 1; i <= n; ++i) {
        //     for (int j = 1; j <= m; ++j) {
        //         if (dist[i][j] >= 10) cout << "  ";
        //         else cout << dist[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
    }


    cout << dist[ei][ej];

    return 0;
}