#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m; cin >> n >> m;
    vector<int> vec(n);
    vector<int> cnt(m+1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
        cnt[vec[i]]++;
    }

    sort(vec.begin(), vec.end());
    for (int i = 1; i <= m/2; i++)
    {
        auto it = upper_bound(vec.begin(), vec.end(), i);
        cnt[i] += int(vec.end() - it);
        cnt[i] += cnt[2*i];
    }

    cout << *max_element(cnt.begin(), cnt.end()) << '\n';
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