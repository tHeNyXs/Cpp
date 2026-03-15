#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll n; cin >> n;
    vector<ll> a(n, 0);
    for (ll i = 0; i < n; ++i) cin >> a[i];
    vector<ll> ic(n, 1000);
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i-1]) ic[i] = ic[i-1];
        if (a[i] > a[i-1] && ic[i] <= ic[i-1]) ic[i] = ic[i-1] + 1000;
    }

    // for (int i : ic) cout << i << ' ';
    // cout << '\n';
    for (int i = n-2; i >= 0; --i) {
        if (a[i] == a[i+1]) ic[i] = ic[i+1];
        if (a[i] > a[i+1] && ic[i] <= ic[i+1]) ic[i] = ic[i+1]+1000;
    }
    // for (int i : ic) cout << i << ' ';
    // cout << '\n';

    ll sum = 0;
    for (ll i = 0; i < n; ++i) sum += ic[i];
    cout << sum;

    return 0;
}