#include <bits/stdc++.h>
#define FOR(i, s, e) for (int i = s; i <= e; ++i)
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<vector<char>> vec(n, vector<char>(n));
    FOR(i, 0, n-1) FOR(j, 0, n-1) cin >> vec[i][j];

    vector<pair<int, int>> cur;
    cur.emplace_back(0, 0);
    string ans = "";
    ans += vec[0][0];
    FOR(i, 1, (n*2)-2) {
        char best = 'Z';
        for (auto[c, r] : cur) {
            if (c+1 < n) best = min(best, vec[c+1][r]);
            if (r+1 < n) best = min(best, vec[c][r+1]);
        }

        vector<pair<int, int>> next;
        for (auto[c, r] : cur) {
            if (c+1 < n && vec[c+1][r] == best) next.emplace_back(c+1, r);
            if (r+1 < n && vec[c][r+1] == best) next.emplace_back(c, r+1);
        }
        sort(next.begin(), next.end());
        next.erase(unique(next.begin(), next.end()), next.end());
        ans += best;
        cur = next;
    }
    cout << ans;

    return 0;
}