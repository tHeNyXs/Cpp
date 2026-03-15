#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cout << "Enter Line : "; cin >> n;
    if (n == 1) {
        cout << 1;
        return 0;
    }
    for (int i = 1; i <= n-1; ++i) cout << "  ";
    cout << 1 << '\n';
    for (int i = 2; i <= n-1; ++i) {
        for (int j = 1; j <= n-i; ++j) cout << "  ";
        cout << i << " ";
        for (int j = 1; j <= ((i-1)*2)-1; ++j) cout << "  ";
        cout << i << " ";
        cout << '\n';
    }
    for (int i = 1; i <= 2*n-1; ++i) {
        cout << n << " ";
    }

    return 0;
}