#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int c, r;
    cin >> c >> r;
    vector<vector<int>> bh(c, vector<int>(r + 1, 0));
    vector<vector<int>> count(c, vector<int>(r + 1, 0));

    for (int i = 0; i < r; ++i) {
        count[0][i] = 1;
    }

    for (int i = 0; i < c; ++i) {
        int sj, ej;
        if (i % 2 == 0) {
            sj = 0;
            ej = r-1;
        }
        else {
            sj = 1;
            ej = r;
        }
        for (int j = sj; j <= ej; ++j) {
            cin >> bh[i][j];
            if (i == 0) continue;
            int sj1;
            if (i%2 == 0) sj1 = j+1;
            else sj1 = j-1;
            int a = bh[i-1][sj1] + bh[i][j], b = bh[i-1][j] + bh[i][j];
            if (a > b) {
                bh[i][j] = a;
                count[i][j] = count[i-1][sj1];
            }
            else if (a < b) {
                bh[i][j] = b;
                count[i][j] = count[i-1][j];
            }
            else {
                bh[i][j] = a;
                count[i][j] = count[i-1][j] + count[i-1][sj1];
            }
        }
    }

    // for (int i = 0; i < c; ++i) {
    //     for (int j = 0; j <= r; ++j) {
    //         cout << setw(3) << setfill(' ') << bh[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    int maxx = *max_element(bh[c-1].begin(), bh[c-1].end());
    int cnt = 0;
    for (int j = 0; j <= r; ++j) {
        if (bh[c-1][j] == maxx) {
            cnt += count[c-1][j];
        }
    }
    cout << maxx << " " << cnt;

    return 0;
}