#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>

const int inf = 9e18;

int dist(pii p1, pii p2) {
    auto[x1, y1] = p1;
    auto[x2, y2] = p2;
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    pii p[n];
    for (int i = 0; i < n; ++i) cin >> p[i].first >> p[i].second;
    sort(p, p+n);
    queue<pii> q;
    set<pii> s;
    int d = inf;
    q.emplace(p[0]);
    s.emplace(p[0].second, p[0].first);
    for (int i = 1; i < n; ++i) {
        auto[x1, y1] = p[i];

        while (!q.empty()) {
            auto[x2, y2] = q.front();
            if ((x1-x2)*(x1-x2) > d) {
                q.pop();
                s.erase({y2, x2});
            }
            else break;
        }

        auto it1 = s.lower_bound({y1-sqrt(d), -inf});
        auto it2 = s.upper_bound({y1+sqrt(d), inf});
        for (auto it = it1; it != it2; ++it) {
            auto[y2, x2] = *it;
            int nowDist = dist(p[i], {x2, y2});
            if (nowDist < d) d = nowDist;
        }

        q.emplace(p[i]);
        s.emplace(y1, x1);
    }

    cout << d;

    return 0;
}