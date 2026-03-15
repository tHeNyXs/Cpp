#include <bits/stdc++.h>
using namespace std;
int main() {
    int num; cin >> num;
    int range[] = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
    int cnt[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    while (num != 0) {
        for (int i = 0; i < 9; ++i) {
            if (num/range[i]) {
                cnt[i] += num/range[i];
                num %= range[i];
            }
        }
    }

    for (int i : cnt) {
        cout << i << " ";
    }

    return 0;
}