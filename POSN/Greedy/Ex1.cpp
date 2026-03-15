#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> coins = {10, 5, 2, 1};
    vector<int> cnt = {0, 0, 0, 0};
    int n; cin >> n;

    for (int i = 0; i < coins.size(); ++i) {
        if (n/coins[i]) {
            cnt[i] += n/coins[i];
            n %= coins[i];
        }
    }

    int sum = 0;
    for (int i = 0; i < coins.size(); ++i) {
        cout << "(" << coins[i] << "x" << cnt[i] << ")";
        if (i == coins.size()-1) cout << "\n";
        else cout << ", ";
        sum += cnt[i];
    }
    cout << "Total: " << sum << " coins";

    return 0;
}
