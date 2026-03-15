#include <bits/stdc++.h>
using namespace std;
int s, e;

int ans(int i) {
    if (i == e) return e;
    return i + ans(i+1);
}

int main() {
    cin >> s >> e;
    cout << ans(s);

    return 0;
}