#include <bits/stdc++.h>
using namespace std;
int main() {
    int s, e;
    cin >> s >> e;
    int sum = 0;
    for (int i = s; i <= e; ++i) {
        sum += i;
    }
    cout << sum;

    return 0;
}