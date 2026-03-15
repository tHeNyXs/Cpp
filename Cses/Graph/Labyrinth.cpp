#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<vector<bool>> r(N, vector<bool>(N));
    int si, sj, ei, ej;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char a; cin >> a;
            if (a == '#') r[i][j] = false;
            else r[i][j] = true;
            if (a == 'A') {
                si = i;
                sj = j;
            }
            if (a == 'B') {
                ei = i;
                ej = j;
            }

        }
    }
    char path[N][N];
    memset(path, '#', sizeof(path));
    queue<pair<int, int>> q;
    vector<char> ans;
    q.emplace(si, sj);
    int di[] = {-1, 1, 0, 0};
    int dj[] = {0, 0, -1, 1};
    char staus[] = {'U', 'D', 'L', 'R'};
    // vector<vector<bool>> vis(n, vector<bool>(m, false));
    while (!q.empty()) {
        auto[i, j] = q.front(); q.pop();

        if (i == ei && j == ej) {
            while (i != si || j != sj) {
                ans.emplace_back(path[i][j]);
                for (int k = 0; k < 4; ++k) {
                    if (staus[k] == path[i][j]) {
                        i -= di[k];
                        j -= dj[k];
                        break;
                    }
                }
                // cout << "I : " << i << " | J : " << j << '\n';
            }
            reverse(ans.begin(), ans.end());
            break;
        }

        for (int k = 0; k < 4; ++k) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if (ni < 0 || ni >= n || nj < 0 || nj >= m || !r[ni][nj]) continue;
            // vis[ni][nj] = true;
            r[ni][nj] = false;
            path[ni][nj] = staus[k];
            q.emplace(ni, nj);
        }
    }

    if (ans.size() == 0) cout << "NO";
    else {
        cout << "YES\n";
        cout << ans.size() << '\n';
        for (char i : ans) {
            cout << i;
        }
    }
    // cout << '\n';

    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         cout << path[i][j];
    //     }
    //     cout << '\n';
    // }


    return 0;
}