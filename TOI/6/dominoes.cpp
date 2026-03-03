#include <bits/stdc++.h>
using namespace std;

void dfs(int n, string ans) {
    if (n == 0) {
        cout << ans << "E\n";
        return;
    }

    if (n < 0) return;
    
    dfs(n - 1, ans + "--\n");
    dfs(n - 2, ans + "||\n");
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    dfs(n, "");

    return 0;
}