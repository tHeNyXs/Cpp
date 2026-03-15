#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e9+5;
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int tx, ty; cin >> tx >> ty;
    int n; cin >> n;
    pair<int, int> p[4][n];
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> p[i][j].first >> p[i][j].second;
        }
    }

    unordered_map<int, pair<int, int>> sumX(10000000), sumY(10000000);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int key = (p[0][i].first + p[1][j].first)*N + p[0][i].second + p[1][j].second;
            sumX[key] = {i, j};
            sumY[key] = {i, j};
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int needX = tx - (p[2][i].first + p[3][j].first);
            int needY = ty - (p[2][i].second + p[3][j].second);
            int key = needX*N + needY;
            if (sumX.count(key) && sumY.count(key)) {
                auto[k, l] = sumX[key];
                cout << p[0][k].first << " " << p[0][k].second << "\n"
                     << p[1][l].first << " " << p[1][l].second << "\n"
                     << p[2][i].first << " " << p[2][i].second << "\n"
                     << p[3][j].first << " " << p[3][j].second;
                return 0;
            }
        }
    }
    
    return 0;
}