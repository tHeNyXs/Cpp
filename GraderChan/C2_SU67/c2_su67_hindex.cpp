#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) cin >> vec[i];
    sort(vec.begin(), vec.end(), greater<int>());
    int ans = -1;
    for (int i = 0; i < n; ++i) {
        if (vec[i] >= i+1) {
            ans = max(ans, i+1);
        }   
    }
    cout << ans;

    return 0;
}