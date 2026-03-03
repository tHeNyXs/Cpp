#include <bits/stdc++.h>
using namespace std;

int c, ansN, ansValue = 144;
double finalAns = INFINITY;
double findBookSell(int n, int d) {
    return ((100 - (0.8569 * exp(0.09 * d))) * n) / 100;
}

void findAns(int n, int value) {
    if (n > 15000) return;
    int sum = (n * value) + c;
    double ans;
    // cout << i * findBookSell(n, i - 100) - sum;
    for (int i = 74; i <= 144; ++i) {
        ans = i * findBookSell(n, i - 100) - sum;
        if (ans < finalAns && ans > 0) {
            ansValue = i;
            finalAns = ans;
            ansN = n;
        }
    }
    findAns(n + 500, value - 1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> c;
    findAns(1000, 100);
    cout << ansN << '\n' << ansValue << '\n' << fixed << setprecision(2) << finalAns;

    return 0;
}