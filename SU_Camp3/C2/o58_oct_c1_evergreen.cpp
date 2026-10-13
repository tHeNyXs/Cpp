#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, k; cin >> n >> k;
    int sum = n;
    map<int, bool> m;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        m[x] = true;
    }

    int cnt = 0;
    while (sum < k) {
        map<int, bool> next = m;
        for (auto i : m) {
            next[i.first-1] = next[i.first+1] = true;
        }
        m = next;
        sum += m.size();
        cnt++;
    }
    cout << cnt;
    

    return 0;
}