#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    ll ans = 0;
    if (n >= 15) {
        ans += (n/15)*3000;
        n %= 15;
    }
    if (n >= 11) {
        ans += 3000;
        n -= 15;
    }
    if (n >= 5) {
        ans += 1500;
        n -= 5;
    }
    if (n >= 4) {
        ans += 1500;
        n -= 5;
    }
    if (n >= 2) {
        ans += 800;
        n -= 2;
    }
    if (n >= 1) {
        ans += 500;
        n -= 1;
    }
    cout << ans;

    return 0;
}