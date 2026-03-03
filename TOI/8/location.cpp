#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int m, n, k;
    cin >> m >> n >> k;
    vector<vector<int>> sum(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1, x; j <= n; ++j) {
            cin >> x;
            sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + x;
        }
    }

    // for (int i = 0; i <= m; ++i) {
    //     for (int j = 0; j <= n; ++j) {
    //         cout << sum[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    int max = -1;
    for (int i = k; i <= m; ++i) {
        for (int j = k; j <= n; ++j) {
            int num = sum[i][j] - sum[i][j - k] - sum[i - k][j] + sum[i - k][j - k];
            // cout << i << " : " << j << " Sum is " << num << '\n';
            if (num > max) max = num;
        }
    }
    cout << max;
    
    return 0;
}