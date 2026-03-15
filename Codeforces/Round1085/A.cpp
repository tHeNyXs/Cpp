#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int q; cin >> q;
    while (q--) {
        unordered_map<string, bool> m;
        int n; cin >> n;
        string a; cin >> a;
        int Max, Min;
        int cnt = 0;
        for (char i : a) if (i == '1') cnt++;
        for (int i = 1; i < n-1; ++i) {
            if (a[i-1] == '1' && a[i+1] == '1' && a[i] != '1') {
                a[i] = '1';
                i = 1;
                cnt++;
            }
        }
        Min = Max = cnt;
        for (int i = 1; i < n-1; ++i) {
            if (a[i-1] == '1' && a[i+1] == '1' && a[i] != '0') {
                a[i] = '0';
                i = 1;
                Min--;
            }
        }

        cout << Min << " " << Max << '\n';
    }

    return 0;
}