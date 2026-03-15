#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, string>
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 0; i < n; ++i) {
        string a; int f;
        cin >> a >> f;
        pq.emplace(f, a);
    }

    map<char, string> m;

    while (pq.size() > 1) {
        auto a = pq.top(); pq.pop();
        auto b = pq.top(); pq.pop();

        for (char x : a.second) m[x] = "0" + m[x];
        for (char y : b.second) m[y] = "1" + m[y];

        pq.emplace(a.first+b.first, a.second+b.second);
    }

    for (auto i : m) {
        cout << i.first << " " << i.second << '\n';
    }

    return 0;
}