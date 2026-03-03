#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int l1, l2;
    cin >> l1 >> l2;
    char a[l1], b[l2];
    cin >> a >> b;
    vector<vector<int>> t(l1+1, vector<int>(l2+1, 0));
    for (int i = 1; i <= l1; ++i) {
        for (int j = 1; j <= l2; ++j) {
            if (a[i-1] == b[j-1]) {
                t[i][j] = t[i-1][j-1] + 1;
                continue;
            }
            t[i][j] = max(t[i-1][j], t[i][j-1]);
        }
    }

    cout << t[l1][l2];

    return 0;
}