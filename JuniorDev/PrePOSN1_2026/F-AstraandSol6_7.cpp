#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--)
    {
        ll n; int b;
        cin >> n >> b;
        if (b == 0 || n == 1)
        {
            cout << "1\n";
            continue;
        }
        int cnt = 0;
        while (n > 0)
        {
            bool minus = n%2 == 0;
            n /= 2;
            cnt++;
            if (n != 0)
            {
                cnt++;
                if (minus) n--;
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}