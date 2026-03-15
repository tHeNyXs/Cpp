#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].first >> p[i].second;
    }

    sort(p.begin(), p.end(), cmp);
    int cnt, e;
    cnt = e = 0;
    for (int i = 0; i < n; ++i) {
        if (e <= p[i].first) {
            e = p[i].second;
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}