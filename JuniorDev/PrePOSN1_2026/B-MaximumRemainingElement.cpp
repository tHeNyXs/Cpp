#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    sort(arr, arr+n);
    if (n == 1) {
        cout << arr[0];
        return 0;
    }

    int sum = -arr[0];
    for (int i = 1; i < n-1; ++i)
    {
        sum += arr[i];
    }
    cout << arr[n-1] + sum;

    return 0;
}