#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    priority_queue<int, vector<int>, greater<int>> q1, q2;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        q1.emplace(x);
    }

    int m; cin >> m;
    for (int i = 0; i < m; ++i) {
        int x; cin >> x;
        q2.emplace(x);
    }

    int cnt = 0;
    while (!q1.empty() && !q2.empty()) {
        int child = q1.top(); q1.pop();
        while (!q2.empty() && q2.top() < child) {
            q2.pop();
        }
        if (!q2.empty()) {
            cnt++;
            q2.pop();
        }
    }
    cout << cnt;

    return 0;
}