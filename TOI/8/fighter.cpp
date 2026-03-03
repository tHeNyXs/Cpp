#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int s = 1;
    int p[2] = {n, n};
    int prev; cin >> prev;
    p[(prev + 1) % 2]--;
    for (int i = 1, x; i < 2 * n; ++i) {
        cin >> x;
        if (x % 2 == prev % 2) {
            s++;
            if (s >= 3) {
                p[(x + 1) % 2] -= 2;
            }
        }
        else s = 1;
        p[(x + 1) % 2]--;
        // cout << x << "\n" << "Odd : " << p[1] << "     Even : " << p[0] << "\n\n";
        if (p[0] <= 0 || p[1] <= 0) {
            cout << x  % 2 << '\n' << x;
            break;
        }

        prev = x;
    }

    return 0;
}