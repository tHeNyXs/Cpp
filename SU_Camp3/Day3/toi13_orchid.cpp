#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    int arr[n+1];
    for (int i = 1; i <= n; ++i) cin >> arr[i];
    vector<int> dp;
    dp.emplace_back(arr[1]);
    for (int i = 2; i <= n; ++i) {
        auto it = upper_bound(dp.begin(), dp.end(), arr[i]);
        if (it == dp.end()) dp.emplace_back(arr[i]);
        else {
            *(it) = arr[i];
        }
    }
    cout << n-dp.size();

    return 0;
}