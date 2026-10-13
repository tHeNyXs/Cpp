#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 22;
int c[N];

int craft(int n, int w) {
    if (n == 1) return w;

    int sum = 2*w + 1 - c[n-1];
    int a, b;
    a = craft(n-1, sum/2);
    b = craft(n-1, sum - sum/2);
    if (a <= 0 || b <= 0) return -1;
    return a+b;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, w; cin >> n >> w;
    for (int i = 1; i < n; ++i) cin >> c[i];
    cout << craft(n, w);

    return 0;
}