#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int s, n;
    cin >> s >> n;
    list<int> l[s];
    for (int i = 0; i < s; ++i) {
        for (int j = 0; j < n; ++j) {
            int x; cin >> x;
            if (x <= 0) break;
            l[i].insert(l[i].end(), x);
        }
    }

    for (int i = 0; i < s; ++i) {
        for (int j = 0; j < s; ++j) {
            if (i == j) continue;
            auto it = l[i].begin();
            int cnt = 0;
            while (it != l[i].end()) {
                auto temp = find(l[j].begin(), l[j].end(), *it);
                if (temp != l[j].end()) cnt++;
                *it++;
            }
            cout << cnt << " ";
        }
        cout << '\n';
    }

    return 0;
}