#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<vector<bool>> island(n+2, vector<bool>(m+2, false));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1, x; j <= m; ++j) {
            cin >> x;
            if (x == 1) island[i][j] = true;
        }
    }

    int cnt = 0;
    int di[] = {1, -1, 0, 0};
    int dj[] = {0, 0, 1, -1};

    for (int i = 0; i <= n+1; ++i) {
        for (int j = 0; j <= m+1; ++j) {
            if (!island[i][j]) {
                for (int k = 0; k < 4; ++k) {
                    int ni = i+di[k];
                    int nj = j+dj[k];
                    if (ni<0||nj<0||ni>n||nj>m) continue;
                    if (island[ni][nj]) cnt++;
                }
            }
        }
    }
    cout << cnt;

    return 0;
}