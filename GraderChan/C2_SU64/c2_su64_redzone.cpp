#include <bits/stdc++.h>
using namespace std;

int n, m, l, d;

bool check(int a, vector<int>& num, vector<int>& order) {
    vector<int> diff(n+2, 0);
    for (int i = 1; i <= a; ++i) {
        int pos = order[i];
        int L = max(1, pos-l);
        int R = min(n, pos+l);
        diff[L] -= d;
        diff[R+1] += d;
    }
    int cur = 0;
    for (int i = 1; i <= n; ++i) {
        cur += diff[i];
        if (num[i] + cur > 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m >> l >> d;
    vector<int> a(n+1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<int> order(m+1);
    for (int i = 1; i <= m; ++i) cin >> order[i];

    int L = 1, R = m;
    int ans = -1;
    while (L <= R) {
        int mid = (L+R)/2;
        if (check(mid, a, order)) {
            ans = mid;
            R = mid-1;
        }
        else L = mid+1;
    }
    cout << ans;

    return 0;
}