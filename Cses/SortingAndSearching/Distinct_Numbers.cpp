#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    map<int, bool> m;
    while (n--) {
        int num; cin >> num;
        m[num] = true;
    }
    cout << m.size();

    return 0;
}