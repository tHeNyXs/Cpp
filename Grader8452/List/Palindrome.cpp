#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    while (n--) {
        string a; cin >> a;
        list<char> f, b;
        for (int i = 0; i < a.length(); ++i) {
            f.insert(f.end(), a[i]);
            b.insert(b.begin(), a[i]);
        }
        cout << (f == b ? "YES\n" : "NO\n");

    }

    return 0;
}