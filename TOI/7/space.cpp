#include <bits/stdc++.h>
using namespace std;

void print(int x, int n) {
    for (int i = 1; i <= n; ++i) {
        int value = pow(2, n - i);
        if (x >= value) {
            x -= value;
            cout << 1;
        }
        else cout << 0;
    }
    cout << " ";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int limit = pow(2, n);
    for (int i = 0; i < limit; ++i) {
        for (int j = i + 1; j < limit; ++j) {
            int x = i ^ j;
            // cout << x << '\n';
            if (x == 0) continue;
            if ((x & (x - 1)) != 0) continue;
            print(i, n);
            print(j, n);
            cout << "\n";
        }
    }

    return 0;
}