#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, pair<int, int>>
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int c, r; cin >> c >> r;
    vector<vector<bool>> black(c+1, vector<bool>(r+1, false));
    int q; cin >> q;
    int cntB = 0;
    vector<pii> dist[c+1][r+1];
    while (q--) {
        int i, x, y;
        cin >> i >> x >> y;
        if (i == 2 && cntB == 0) {
            cout << "-1\n";
            continue;
        }

        if (i == 1) {
            if (black[x][y]) cntB--;
            else cntB++;
            black[x][y] = !black[x][y];
            if (black[x][y]) {
                for (int j = 1; j <= c; ++j) {
                    for (int k = 1; k <= r; ++k) {
                        dist[j][k].emplace_back(abs(j-x)+abs(k-y), make_pair(x, y));
                    }
                }
            }
        }
        else {
            sort(dist[x][y].begin(), dist[x][y].end());
            for (auto[d, j] : dist[x][y]) {
                int nx = j.first, ny = j.second;
                if (black[nx][ny]) {
                    cout << d << "\n";
                    break;
                }
            }
        }
    }

    return 0;
}