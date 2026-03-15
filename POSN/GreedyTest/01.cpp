#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    int c[] = {10, 5, 2, 1};
    int cnt[] = {0, 0, 0, 0};
    int sum = 0;
    for (int i = 0; i < 4; ++i) {
        cnt[i] += n/c[i];
        n %= c[i];
        sum += cnt[i];
    }

    cout << sum << " (";
    bool first = false;
    for (int i = 0; i < 4; ++i) {
        if (cnt[i]) {
            if (first) cout << ", ";
            cout << c[i] << "x" << cnt[i];
            first = true;
        }
    }
    cout << ')';

    return 0;
}