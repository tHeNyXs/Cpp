#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int N = 1e5+5;
int x[N], fen[N], cnt[N];
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b; cin >> a >> b;
        x[b] = a;
    }

    ll ans = 0;
    for (int i = n; i >= 1; --i) {
        ll sum = 0;
        int idx = x[i]-1;
        while (idx > 0) {
            sum += fen[idx];
            idx -= idx & -idx;
        }
        idx = x[i]-1;
        int tempCnt = 0;
        while (idx > 0) {
            tempCnt += cnt[idx];
            idx -= idx & -idx;
        }
        ans += sum + (tempCnt*x[i]);

        idx = x[i];
        while (idx < N) {
            fen[idx] += x[i];
            idx += idx & -idx;
        }
        idx = x[i];
        while (idx < N) {
            cnt[idx]++;
            idx += idx & -idx;
        }
    }
    cout << ans;

    return 0;
}