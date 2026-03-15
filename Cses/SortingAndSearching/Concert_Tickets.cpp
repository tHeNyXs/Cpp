#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    multiset<int> price;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        price.insert(x);
    }
    int person[m];
    for (int i = 0; i < m; ++i) {
        cin >> person[i];
    }
    for (int i = 0; i < m; ++i) {
        multiset<int>::iterator it = price.upper_bound(person[i]);
        if (it == price.begin()) cout << "-1\n";
        else {
            it--;
            cout << *it << '\n';
            price.erase(it);
        }
    }

    return 0;
}