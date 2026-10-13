#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin >> n;
    vector<int> vec(n);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
        if (!vec[i]) cnt++;
    }

    if (cnt < 2)
    {
        cout << "-1\n";
        return;
    }

    int ans = 0;
    if (vec[0]) ans++;
    if (vec[n-1]) ans++;
    cout << ans << '\n';
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