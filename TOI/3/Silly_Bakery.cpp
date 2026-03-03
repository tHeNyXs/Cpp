#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    double sum = 0;
    for (int i = 0, a, b, c, d, e; i < n; ++i) {
        cin >> a >> b >> c >> d >> e;
        sum += a;
        sum += .75 * b;
        sum += .5 * c;
        sum += .25 * d;
        sum += .125 * e;
    }
    cout << ceil(sum);
    

    return 0;
}