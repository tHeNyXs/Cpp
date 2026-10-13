#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int q; cin >> q;
    map<int, int> m;
    while (q--) {
        int o; cin >> o;
        if (o == 1) {
            int l, r; cin >> l >> r;
            m[l]++;
            m[r+1]--;
        }
        else {
            int cnt = 0;
            int sum = 0;
            for (auto i : m) {
                sum += i.second;
                if (sum == 0) cnt++;
            }
            cout << cnt << '\n';
        }
    }

    return 0;
}