#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;
int main() {
    int n; cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        cnt[x]++;
    }

    ll ans = 1;
    for (auto it : cnt) {
        ans *= it.second+1;
        ans %= mod;
    }
    cout << ans-1;

    return 0;
}