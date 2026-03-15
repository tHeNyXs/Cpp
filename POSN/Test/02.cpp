#include <bits/stdc++.h>
using namespace std;
int main() {
    int n1, n2;
    cout << "Input first Number : "; cin >> n1;
    cout << "Input second Number : "; cin >> n2;
    int ans = n1+n2;
    cout << "Result is\n";
    int range[] = {1000, 100, 10, 1};
    while (ans != 0) {
        for (int i : range) {
            if (ans / i) {
                cout << ans/i << '\n';
                ans %= i;
                break;
            }
        }
    }

    return 0;
}