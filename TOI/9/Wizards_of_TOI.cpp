#include <bits/stdc++.h>
using namespace std;

const int N = 1505;
const int S = 45e5;
pair<int, int> p[5][N];
int ht[S];
pair<int, int> sum[S];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int tx, ty; cin >> tx >> ty;
    int n; cin >> n;
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> p[i][j].first >> p[i][j].second;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x = p[1][i].first + p[2][j].first;
            int y = p[1][i].second + p[2][j].second;
            int idx = ((x*3 +y)%S + S) % S;
            while (ht[idx]) {
                idx++;
                idx%= S;
            }
            ht[idx] = i*N + j;
            sum[idx] = {x, y};
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int needx = tx - p[3][i].first - p[4][j].first;
            int needy = ty - p[3][i].second - p[4][j].second;
            int idx = ((needx*3+needy)%S + S) % S;
            while (ht[idx]) {
                if (sum[idx] == make_pair(needx, needy)) {
                    int a[5] = {0, ht[idx] / N, ht[idx] % N, i, j};
                    for (int k = 1; k <= 4; k++)
                    {
                        cout << p[k][a[k]].first << ' ' << p[k][a[k]].second << '\n';
                    }
                    return 0;
                }
                idx++;
                idx%=S;
            }
        }
    }

    return 0;
}


