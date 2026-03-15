#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int x, n; cin >> x >> n;
    set<int> s;
    s.emplace(0);
    s.emplace(x);
    multiset<int> ms;
    ms.emplace(x);
    while (n--) {
        int p; cin >> p;
        auto r = s.upper_bound(p);
        auto l = prev(r);
        int valL = *l, valR = *r;
        int mid = valR - valL;
        // cout << "MID : " << mid << '\n';
        auto e = ms.find(mid);
        ms.erase(e);
        ms.emplace(p - valL);
        ms.emplace(valR - p);
        s.emplace(p);
        cout << *ms.rbegin() << ' ';
        // cout << "S : ";
        // for (int i : s) cout << i << " ";
        // cout << '\n';
        // cout << "MS : ";
        // for (int i : ms) cout << i << " ";
        // cout << "\n\n";
    }

    return 0;
}