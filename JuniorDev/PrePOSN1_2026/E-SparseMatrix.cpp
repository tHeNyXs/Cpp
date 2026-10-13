#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    map<pair<int, int>, int> ma;
    set<pair<int, int>> p;
    for (int i = 0; i < n; ++i)
    {
        int m; cin >> m;
        for (int j = 0; j < m; ++j)
        {
            int x; cin >> x;
            ma[{i, j}] += x;
            ma[{j, i}] += x;
            p.emplace(i, j);
            if (i != j) p.emplace(j, i);
        }
    }

    ll ans = 1;
    for (auto[i, j] : p)
    {
        ans *= ma[{i, j}];
        ans %= mod;
    }

    cout << ans;

    return 0;
}