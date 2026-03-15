#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, k; cin >> n >> k;
    pair<int, int> p[k];
    multiset<pair<int, int>> s;
    for (int i = 0; i < k; ++i) cin >> p[i].first;
    for (int i = 0; i < k; ++i) {
        cin >> p[i].second;
        s.emplace(p[i]);
    }

    int c; cin >> c;
    while (c--) {
        int start, end; cin >> start >> end;
        auto it = s.lower_bound({start, 0});
        if (it == s.end()) it--;
        else if (it != s.begin() && start-(*prev(it)).first < (*it).first - start) {
            it--;
            int value = it->first;
            while (it != s.begin() && it->first == value) it--;
            if (it->first != value) it++;
        }
        cout << it->first << " " << it->second << '\n';
        int val = it->second;
        val += abs(it->first - start) + abs(end-start);
        s.erase(it);
        s.emplace(end, val);
    }

    return 0;
}