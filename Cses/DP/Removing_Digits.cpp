#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    int cnt = 0;
    while (n != 0) {
        string a = to_string(n);
        int maxx = -1;
        for (int i = 0; i < a.length(); ++i) {
            if (a[i]-'0' > maxx) maxx = int(a[i]-'0');
        }
        n -= maxx;
        cnt++;
    }
    cout << cnt;
    

    return 0;
}