#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf = 1e18;

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    ll ans = (n-1) + (n * (m-1));
    cout << (k == ans ? "YES\n" : "NO\n");
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}