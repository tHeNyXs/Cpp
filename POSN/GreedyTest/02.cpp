#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    int n; cin >> n;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i].first >> p[i].second;

    sort(p.begin(), p.end(), cmp);
    int cnt = 0;
    int e = 0;
    for (int i = 0; i < n; ++i) {
        if (e <= p[i].first) {
            cnt++;
            e = p[i].second;
        }
    }
    cout << cnt;

    return 0;
}