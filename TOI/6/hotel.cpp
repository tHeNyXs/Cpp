#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    int sum = 0;
    if (n >= 15) {
        sum += n / 15 * 3000;
        n %= 15;
    }
    if (n >= 10) {
        sum += 3000;
        n = 0;
    }
    if (n >= 5) {
        sum += n / 5 * 1500;
        n %= 5;
    }
    if (n >= 4) {
        sum += 1500;
        n = 0;
    }
    if (n >= 2) {
        sum += n / 2 * 800;
        n %= 2;
    }
    if (n >= 1) {
        sum += n / 1 * 500;
        n %= 1;
    }
    cout << sum;

    return 0;
}