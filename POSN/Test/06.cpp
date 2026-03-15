#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, c;
    cout << "Enter a : "; cin >> a;
    cout << "Enter b : "; cin >> b;
    cout << "Enter c : "; cin >> c;
    while (a <= b) {
        for (int i = 1; i <= c; ++i) {
            cout << a << "\t";
            a++;
            if (a > b) break;
        }
        cout << '\n';
    }

    return 0;
}