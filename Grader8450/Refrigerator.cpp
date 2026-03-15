#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0, x; i < n; ++i) {
            cin >> x; pq.emplace(x);
        }
        int day = 0;
        while (true) {
            int now = pq.top(); pq.pop();
            if (now <= day) break;
            int plus = pq.top()-now+1;
            now += plus;
            day += plus;
            pq.emplace(now);
        }
        cout << day << '\n';
    }

    return 0;
}