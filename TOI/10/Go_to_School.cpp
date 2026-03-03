#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int r, c; cin >> r >> c;
    vector<vector<ll>> table(c+2, vector<ll>(r+2, 0));
    vector<vector<bool>> ban(c+2, vector<bool>(r+2, false));
    int n; cin >> n;
    while (n--) {
        int x, y;
        cin >> y >> x;
        x = c-x + 1;
        ban[x][y] = true;
    }

    
    if (!ban[c][1]) table[c][1] = 1;
    for (int i = c; i >= 1; --i) {
        for (int j = 1; j <= r; ++j) {
            if (ban[i][j]) continue;
            table[i][j] += table[i+1][j] + table[i][j-1];
        }
    }

    // for (int i = 0; i <= c; ++i) {
    //     for (int j = 0; j <= r; ++j) {
    //         cout << table[i][j] << " ";
    //     }    
    //     cout << '\n';
    // }
    cout << table[1][r];


    return 0;
}