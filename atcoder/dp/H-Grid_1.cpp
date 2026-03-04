#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int c, r; cin >> c >> r;
    vector<vector<char>> table(c+1, vector<char>(r+1));
    for (int i = 1; i <= c; ++i) for (int j = 1; j <= r; ++j) cin >> table[i][j];

    vector<vector<ll>> cnt(c+1, vector<ll>(r+1, 0));
    if (table[1][1] == '.') cnt[1][1] = 1;
    for (int i = 1; i <= c; ++i) {
        for (int j = 1; j <= r; ++j) {
            if (table[i][j] != '.' || (i == 1 && j == 1)) continue;
            cnt[i][j] = cnt[i-1][j] + cnt[i][j-1];
            cnt[i][j] %= MOD;
        }
    }
    cout << cnt[c][r];

    return 0;
}