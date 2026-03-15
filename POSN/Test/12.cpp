#include <bits/stdc++.h>
using namespace std;
int main() {
    int value[15];
    iota(value, value+15, 0);
    cout << "Enter Line : ";
    int n; cin >> n;
    int temp = n;
    int line = 0;
    while (temp > 0) {
        line++;
        temp -= line;
    }
    
    int v = 1;
    for (int i = 1; i <= line; ++i) {
        if (i%2 == 1) {
            for (int j = 1; j <= line-1; ++j) cout << " ";
            for (int j = 1; j <= value[i]; ++j) cout << (v++)%10;
        }
        else {
            for (int j = 1; j <= line-i; ++j) cout << " ";
            for (int j = value[i]-1; j >= 0; --j) cout << (v+j)%10;
            v += value[i];
        }
        cout << '\n';
    }
    
    return 0;
}