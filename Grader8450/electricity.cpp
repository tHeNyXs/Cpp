#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, k; cin >> n >> k;
    int p[n+1];
    for (int i = 1; i <= n; ++i) cin >> p[i];
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 1; i < k; ++i) {
        pq.emplace(p[i], i);
    }

    for (int i = k+1; i <= n; ++i) {
        while (pq.top().second < i-k) {
            pq.pop();
        }
        p[i] += pq.top().first;
        pq.emplace(p[i], i);
    }

    cout << p[1] + p[n];

    return 0;
}