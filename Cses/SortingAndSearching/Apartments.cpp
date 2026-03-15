#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    int a[n]; for (int i = 0; i < n; ++i) cin >> a[i];
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0, b; i < m; ++i) {
        int x; cin >> x;
        pq.emplace(x);
    }
    sort(a, a+n);
    int cnt = 0;
    int i = 0;
    while (i < n && !pq.empty()) {
        int now = pq.top();
        if (a[i]-k <= now && now <= a[i]+k) {
            i++;
            cnt++;
            pq.pop();
        }
        else if (now < a[i]-k) pq.pop();
        else if (now > a[i]+k) i++;
    }
    cout << cnt;

    return 0;
}