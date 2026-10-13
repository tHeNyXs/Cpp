#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin >> n;
    int cnt[2] = {0, 0};
    for (int i = 0; i < n; ++i)
    {
        int x; cin >> x;
        cnt[x]++;
    }
    if (cnt[1] >= cnt[0]) cout << "Bessie\n";
    else cout << "Elsie\n";
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