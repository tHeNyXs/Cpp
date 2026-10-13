#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin >> n;
    int vec[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> vec[i];
    }

    vector<bool> check(n, true);
    for (int i = 0; i < n; ++i)
    {
        for (int j = vec[i]*(i+1); j < vec[i]*(i+1)+(i+1) && j < n; ++j)
        {
            check[j] = false;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; ++i)
    {
        if (check[i]) q.emplace(i);
    }
    cout << q.size() << '\n';
    if (!q.empty())
    {
        while (!q.empty())
        {
            cout << q.front() << ' ';
            q.pop();
        }
        cout << '\n';
    }
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