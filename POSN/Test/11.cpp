#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cout << "N = "; cin >> n;
    n++;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n-i; ++j) cout << " ";
        for (int j = 0; j < i; ++j) cout << j;
        for (int j = i-2; j >= 0; --j) cout << j;
        cout << '\n';
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= i; ++j) cout << " ";
        for (int j = 0; j < n-i; ++j) cout << j;
        for (int j = n-i-2; j >= 0; --j) cout << j;
        cout << '\n';
    }
    

    return 0;
}