#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    unordered_map<char, vector<pair<char, int>>> m;
    while (n--) {
        char u, v;
        int dis;
        cin >> u >> v >> dis;
        m[u].emplace_back(v, dis);
        m[v].emplace_back(u, dis);
    }
    unordered_map<char, char> p;
    unordered_map<char, bool> c;
    stack<vector<char>> s;
    s.push({'X'});
    vector<char> ans;
    while (!s.empty()) {
        auto u = s.top(); s.pop();
        c[u.back()] = true;
        if (u.back() == 'Y') {
            ans = u;
            break;
        }
        for (auto[v, w] : m[u.back()]) {
            if (c[v]) continue;
            vector<char> temp = u;
            temp.emplace_back(v);
            s.emplace(temp);
        }
    }
    
    if (ans.size() == 0) {
        cout << "broken";
        return 0;
    }

    double sum = 0;
    for (int i = 0; i < ans.size() - 1; ++i) {
        vector<int> sett;
        for (auto j : m[ans[i]]) {
            if (j.first != ans[i + 1]) continue;
            sett.emplace_back(j.second);
        }
        sort(sett.begin(), sett.end());
        cout << ans[i] << " " << ans[i + 1] << " ";
        double pluss;
        if (sett.size() % 2 == 0) {
            pluss = (sett[sett.size() / 2] + sett[sett.size() / 2 - 1]) * 1.0 / 2;
        }
        else pluss = sett[sett.size() / 2];
        sum += pluss;
        cout << fixed << setprecision(1) << pluss << '\n';
    }
    cout << fixed << setprecision(1) << sum;

    return 0;
}