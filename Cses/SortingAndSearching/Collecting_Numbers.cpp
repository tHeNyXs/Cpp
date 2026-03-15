#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].first; p[i].second = i;
    }

    sort(p.begin(), p.end());

    int cnt = 1;
    for (int i = 1; i < n; ++i) {
        if (p[i].second < p[i-1].second) cnt++;
    }
    cout << cnt;

    return 0;
}