#include <bits/stdc++.h>
using namespace std;
typedef struct {
    int s, e, n;
} P;

bool cmp(const P &a, const P &b) {
    if (a.s != b.s) return a.s < b.s;
    return a.e <= b.e;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k, m;
    cin >> n >> k >> m;
    P p[n + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> p[i].s >> p[i].e;
        p[i].n = i;
    }
    sort(p + 1, p + n + 1, cmp);
    // for (auto[s, e, i] : p) {
    //     cout << s << " " << e << " " << i << '\n';
    // }
    vector<bool> can(n + 1, false);
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; ++i) {
        if (pq.size() < k) {
            pq.push(p[i].e);
            can[p[i].n] = true;
            continue;;
        }
        if (p[i].s > pq.top()) {
            pq.pop(); pq.push(p[i].e);
            can[p[i].n] = true;
        }
    }
    for (int i = 0, j; i < m; ++i) {
        cin >> j;
        cout << (can[j] ? "Y " : "N ");
    }

    return 0;
}