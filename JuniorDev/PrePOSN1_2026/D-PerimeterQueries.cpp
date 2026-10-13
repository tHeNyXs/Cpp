#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, q; cin >> n >> q;
    int a[n+2], b[n+2];
    a[0] = b[0] = a[n+1] = b[n+1] = 0;
    ll sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i] >> b[i];
        sum += b[i] * 2;
    }
    sum += a[1]+a[n];
    for (int i = 2; i <= n; ++i)
    {
        sum += abs(a[i]-a[i-1]);
    }
    cout << sum << '\n';
    while (q--)
    {
        int x, c, d; cin >> x >> c >> d;
        sum -= b[x]*2;
        sum += d*2;
        sum -= abs(a[x]-a[x-1]) + abs(a[x]-a[x+1]);
        sum += abs(c-a[x-1]) + abs(c-a[x+1]);
        a[x] = c; b[x] = d;
        cout << sum << '\n';
    }

    return 0;
}