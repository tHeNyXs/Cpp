#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, k; cin >> n >> k;
    multiset<int> s;
    for (int i = 0, x; i < k; ++i) {
        cin >> x; s.insert(x);
    }

    int c; cin >> c;
    while (c--) {
        int start, end; cin >> start >> end;
        auto it = s.lower_bound(start);
        if (it == s.end()) it--;
        else if (it != s.begin() && start-*prev(it) < *it-start) it--;
        cout << *it << '\n';
        s.erase(it);
        s.insert(end);
    }

    return 0;
}