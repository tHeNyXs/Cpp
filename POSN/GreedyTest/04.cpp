#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll d, m; int n;
    cin >> d >> m >> n;
    set<ll> s;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x; s.insert(x);
    }

    ll cnt = 0;
    bool flag = false;
    ll now = m;
    while (now < d) {
        auto it = s.upper_bound(now);
        if (it == s.begin()) break;
        else {
            it--;
            now = *it;
            cnt++;
        }
        now += m;
        // cout << "Now : " << now << '\n';
    }

    if (now < d) cout << "-1";
    else cout << cnt;

    return 0;
}