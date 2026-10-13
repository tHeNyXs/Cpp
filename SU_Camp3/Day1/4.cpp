#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 2e6;
int n;
ll c[N];

bool can(ll mid) {
    stack<ll> s;
    for (int i = 0; i < n; ++i) {
        if (c[i] <= mid) continue;
        else s.emplace(c[i]);
    }

    while (!s.empty()) {
        ll f = s.top(); s.pop();
        ll sec = s.top(); s.pop();
        if (f != sec) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    ll l = 0, r = 1e18;
    while (l < r) {
        ll mid = (l+r)/2;
        if (can(mid)) r = mid;
        else l = mid+1;
    }
    cout << l;

    return 0;
}