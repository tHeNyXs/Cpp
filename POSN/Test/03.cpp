#include <bits/stdc++.h>
using namespace std;
int main() {
    int s, e;
    cin >> s >> e;
    int sum = (s+e) * (e-s + 1)*1.0/2;
    cout << sum;

    return 0;
}