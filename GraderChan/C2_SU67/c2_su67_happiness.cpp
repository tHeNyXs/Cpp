#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        ll x; cin >> x;
        sum += x;
        pq.emplace(x);

        if (sum < 0) {
            sum -= pq.top(); pq.pop();
        }
    }
    cout << pq.size();

    return 0;
}