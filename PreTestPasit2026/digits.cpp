#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll p; cin >> p;
    if (p == 0)
    {
        cout << "10";
        return 0;
    }
    stack<int> s;
    for (int i = 9; i >= 2; i--)
    {
        while (p%i == 0)
        {
            s.emplace(i);
            p /= i;
        }
    }
    if (p != 1) cout << "-1";
    else {
        while (!s.empty())
        {
            cout << s.top();
            s.pop();
        }
    }

    return 0;
}