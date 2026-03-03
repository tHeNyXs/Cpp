#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    vector<bool> vis(n + 1, false);
    for (int i = 1, cntM = 1; cnt < n; ++i, ++cntM) {
        if (i > n) {
            i = 0;
            cntM--;
            continue;
        }
        if (vis[i]) {
            cntM--;
            continue;
        }
        if (!vis[i] && cntM % m == 0) {
            cout << i << " ";
            vis[i] = true;
            cnt++;
        }
    }

    return 0;
}