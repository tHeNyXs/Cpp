#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e5  + 5;

ll sumC[N], sumS[N];
int x[N];

ll get(ll sum[], int i) {
    ll s = 0;
    for (; i > 0; i -= i & -i) s += sum[i];
    return s;
}

void add(ll sum[], int i, ll value) {
    for(; i <= N; i += i & -i) sum[i] += value;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for (int i = 0, a, b; i < n; ++i) {
        cin >> a >> b;
        x[b] = a;
    }

    ll sum = 0;
    for (int i = n; i >= 1; --i) {
        sum += get(sumC, x[i] - 1) * x[i] + get(sumS, x[i] - 1);
        add(sumS, x[i], x[i] * 1LL);
        add(sumC, x[i], 1LL); 
    }
    cout << sum;

    return 0;
}