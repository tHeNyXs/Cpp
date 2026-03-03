#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    char mo[2][n];
    for (int i = 0; i < n; ++i) {
        cin >> mo[0][i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> mo[1][i];
    }
    char key[m];
    for (int i = 0; i < m; ++i) {
        cin >> key[i];
    }

    for (int i = m; i >= 0; --i) {
        char ans[3];
        for (int j = 0; j < n; ++j) {
            ans[0] = key[i];
            ans[1] = mo[0][j];
            ans[2] = mo[1][j];
            sort(ans, ans + 3);
            key[i] = ans[1];
        }
    }
    for (char i : key) {
        cout << i;
    }

    return 0;
}