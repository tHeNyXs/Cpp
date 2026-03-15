#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];

    map<int, bool> m;   
    int ans = -1;
    int l = 0;
    for (int r = 0; r < n; ++r) {
        while (m[a[r]]) {
            m[a[l]] = false;
            m.erase(a[l]);
            l++;
        }
        m[a[r]] = true;
        ans = max(ans,  (int)m.size());
    }

    cout << ans;

    return 0;
}