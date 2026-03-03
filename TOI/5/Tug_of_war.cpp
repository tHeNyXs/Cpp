#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 
    int n; cin >> n;
    int a[n], b[n];
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!i) cin >> a[j];
            else cin >> b[j];
        }
    }
    sort(a, a + n);
    sort(b, b + n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += abs(a[i] - b[i]);
    }
    cout << sum;
    
    return 0;
}