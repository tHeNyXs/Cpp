#include <bits/stdc++.h>
using namespace std;

#define ll long long
int n, k, c;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> k >> c;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int l, h; cin >> l >> h;

    pair<int, int> p[n];
    for (int i = 0; i < n; ++i) {
        int start, end;
        start = end = 0;
        ll sum = 0;
        for (int j = i; j < n; ++j) {
            sum += a[j]*pow(j-i, c);
            if (sum >= l && start == 0) {
                start = j-i+1;
            }
            if (sum > h) {
                end = j-i;
                break;
            }
            if (j == n-1 && sum <= h && sum >= l) {
                end = j-i+1;
                break;
            }
        }
        p[i].first = start;
        p[i].second = end;
    }

    // for (int i = 0; i < n; ++i) {
    //     cout << p[i].first << " " << p[i].second << '\n';
    // }
    int cnt[n+1][k+1];
    memset(cnt, 0, sizeof(cnt));
    for (int i = p[0].first; i <= p[0].second; ++i) {
        cnt[0+i][1]++;
    }
    int mod = 1e9+7;
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < k; ++j) {
            if (cnt[i][j]) {
                if (cnt[i][j] >= mod) cnt[i][j] %= mod;
                for (int l = p[i].first; l <= p[i].second; ++l) {
                    if (l+i >= n+1) break;
                    cnt[i+l][j+1] += cnt[i][j];
                    if (cnt[i+l][j+1] >= mod) cnt[i+l][j+1] %= mod;
                }
            }
        }
    }
    cout << cnt[n][k] % mod;


    return 0;
}