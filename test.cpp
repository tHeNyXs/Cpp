#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int N = (1e4+30)*2 + 50;
const int M = 95;
map<pair<int, int>, int> mp;
map<int, pair<int, int>> rev;
vector<vector<pii>> graph(N);
vector<vector<int>> dist(M, vector<int>(M, 1e17));
int id = 1;
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int k, m; cin >> k >> m;
    for (int i = 0; i < k; ++i) {
        int ux, uy, vx, vy;
        cin >> ux >> uy >> vx >> vy;
        if (!mp[{ux, uy}]) {
            mp[{ux, uy}] = id;
            rev[id] = {ux, uy};
            id++;
        }
        if (!mp[{vx, vy}]) {
            mp[{vx, vy}] = id;
            rev[id] = {vx, vy};
            id++;
        }
        dist[mp[{ux, uy}]][mp[{vx, vy}]] = dist[mp[{vx, vy}]][mp[{ux, uy}]] = 0;
    }

    for (int i = 1; i < id; ++i) {
        for (int j = 1; j < id; ++j) {
            if (i == j) dist[i][j] = 0;
            else {
                int ux = rev[i].first, uy = rev[i].second, vx = rev[j].first, vy = rev[j].second;
                dist[i][j] = min(dist[i][j], abs(ux-vx) + abs(uy-vy));
            }
        }
    }

    for (int k = 1; k < id; ++k) {
        for (int i = 1; i < id; ++i) {
            for (int j = 1; j < id; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        int ux, uy, vx, vy;
        cin >> ux >> uy >> vx >> vy;
        int ans = abs(ux-vx) + abs(uy-vy);
        for (int j = 1; j < id; ++j) {
            int best = 1e18;
            for (int k = 1; k < id; ++k) {
                best = min(best, abs(ux-rev[k].first) + abs(uy-rev[k].second) + dist[k][j]);
            }

            ans = min(ans, best + abs(rev[j].first-vx) + abs(rev[j].second-vy));
        }
        cout << ans << '\n';
    }

    return 0;
}