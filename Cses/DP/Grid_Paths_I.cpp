#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<vector<char>> t(n+1, vector<char>(n+1, '\0'));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> t[i][j];
        }
    }
    
    vector<vector<int>> num(n+1, vector<int>(n+1, 0));
    if (t[1][1] == '.') num[1][1] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (t[i][j] == '*' || (i == 1 && j == 1)) continue;
            num[i][j] = num[i-1][j] + num[i][j-1];
            // if (t[i-1][j] == '.' && t[i][j-1] == '.') num[i][j]++;
            if (num[i][j] >= int(1e9) + 7) num[i][j] %= int(1e9) + 7;   
        }
    }

    // for (int i = 1; i <= n; ++i) {
    //     for (int j = 1; j <= n; ++j) {
    //         cout << num[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    cout << num[n][n] ;

    return 0;
}