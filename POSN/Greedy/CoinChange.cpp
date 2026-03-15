#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int> &coins, int amount) {
    int count = 0;
    for (int i = coins.size()-1; i >= 0; --i) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            count++;
        }
    }
    return amount == 0 ? count : -1;
}

int main() {
    vector<int> coins = {1, 2, 5, 10};
    int amount = 48;
    cout << coinChange(coins, amount) << '\n';

    return 0;
}
