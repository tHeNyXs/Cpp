#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        int arr[n];
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        string com; cin >> com;
        int l = 0, r = n-1;
        for (int i = 0; i < n; ++i) {
            if (com[i] == 'L') l++;
            else r--;
        }
        stack<int> ans;
        int sum = 1;
        for (int i = n-1; i >= 0; --i) {
            if (com[i] == 'L') l--;
            else r++;
            if (com[i] == 'L') sum *= arr[l];
            else sum *= arr[r];
            sum %= m;
            ans.emplace(sum);
        }

        while (!ans.empty()) {
            cout << ans.top() << " "; ans.pop();
        }
        cout << '\n';

    }

    return 0;
}