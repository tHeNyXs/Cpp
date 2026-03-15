#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int a; cin >> a;
    int mod; cin >> mod;
    stack<int> ans;
    while (a != 0) {
        ans.emplace(a%mod);
        a /= mod;
    }

    while (!ans.empty()) {
        cout << ans.top(); ans.pop();
    }

    return 0;
}