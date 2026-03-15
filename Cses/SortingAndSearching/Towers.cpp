#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    multiset<int> s;
    while (n--) {
        int x; cin >> x;
        auto it = s.upper_bound(x);
        if (it == s.end()) s.emplace(x);
        else {
            s.erase(it);
            s.emplace(x);
        }
    }
    cout << s.size();

    return 0;
}