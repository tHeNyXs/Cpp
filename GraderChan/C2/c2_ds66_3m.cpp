#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX = 2e7 + 5;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    ll cnt = 0;
    vector<int> diff(MAX, 0);
    int f;
    for (int i = 0; i < n; ++i) {

        int x, y; cin >> x >> y;
        cnt += y-x;
        diff[x]++;
        diff[y]--;
        f = x;
    }
    ll mid = cnt/2;
    if (cnt == 1) {
        cout << f;
        return 0;
    }
    vector<int> test(MAX, 0);
    for (int i = 0; i < MAX; ++i) {
        if (i > 0) test[i] = test[i-1];
        test[i] += diff[i];
    }

    for (int i = 0; i < MAX; ++i) {
        mid -= test[i];
        if (mid <= 0) {
            cout << i;
            break;
        }
    }

    return 0;
}