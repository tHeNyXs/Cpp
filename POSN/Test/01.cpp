#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cout << "Input Number : "; cin >> n;
    if (n%2) n = pow(n, 3);
    else n = pow(n, 2);
    cout << "Result is : " << n;

    return 0;
}