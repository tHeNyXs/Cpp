#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int w, h, n;
    cin >> w >> h >> n;
    vector<int> dp(w, 0);
    while (n--) {
        int x, a;
        cin >> x >> a;
        for (int i = 0; i < a && x + i < w; ++i) {
            dp[x + i]++;
        }
    }
    int cnt100, cnt50;
    cnt100 = cnt50 = 0;
    for (int i = 0; i < w; ++i) {
        if (dp[i] == 1) cnt50++;
        else if (dp[i] == 0) cnt100++;
    }
    cnt50 *= h;
    cnt100 *= h;
    cout << cnt100 << " " << cnt50;

    return 0;
}