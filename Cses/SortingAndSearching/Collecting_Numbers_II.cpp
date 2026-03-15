#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<pair<int, int>> p(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i].first;
        p[i].second = i;
    }
    sort(p.begin()+1, p.end());

    while (m--) {
        int a, b; cin >> a >> b;

        for (int i = 1; i <= n; ++i) {
            if (p[i].second == a) p[i].second = b;
            else if (p[i].second == b) p[i].second = a;
        }

        int cnt = 1;
        for (int i = 2; i <= n; ++i) {
            if (p[i].second < p[i-1].second) cnt++;
        }

        cout << cnt << "\n";
    }

    return 0;
}