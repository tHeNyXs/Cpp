#include <bits/stdc++.h>
using namespace std;

struct Fenwick
{
    vector<int> t;

    Fenwick(int n)
    {
        t.resize(n+1);
    }
};

void solve()
{
    int n, m; cin >> n >> m;
    vector<int> vec(n);
    vector<int> cnt(m+1, 0);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
        cnt[vec[i]]++;
        sum += vec[i];
    }
    sort(vec.begin(), vec.end());

    int cntPrint = 0;
    while (cnt[1] != sum)
    {
        for (int i = 1; i <= m/2; i++)
        {
            
        }
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