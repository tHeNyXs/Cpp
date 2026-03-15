#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> arr(9, 50);
    for (int i = 1; i <= 8; ++i) {
        int x; cin >> x;
        arr[i] -= x;
    }

    int x; cin >> x;
    bool flag = false;
    for (int i = 1; i <= 8; ++i) {
        if (arr[i] >= x) {
            cout << i << " ";
            flag = true;
        }
    }
    if (!flag) cout << 0;

    return 0;
}