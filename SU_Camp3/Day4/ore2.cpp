#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> dp(n+1), a(n+1), pfs(n+1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pfs[i] = a[i] + pfs[i-1];
    }

    deque<pii> dq;


    return 0;
}