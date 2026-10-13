#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k; cin >> n >> k;
    if (k < n || k >= 2*n)
    {
        cout << "-1\n";
        return;
    }

    vector<vector<int>> vec(n, vector<int>(n, 0));
    int cnt = 1;
    int px, py;
    px = py = 0;
    int down = k-n;
    while (cnt <= k)
    {
        vec[px][py] = cnt++;
        if (down)
        {
            down--;
            vec[px][py+1] = cnt++;
        }
        px++; py++;
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (!vec[i][j])
            {
                vec[i][j] = cnt++;
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << vec[i][j] << " ";
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