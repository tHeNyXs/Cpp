#include <bits/stdc++.h>
using namespace std;
#define int long long

int coin;
int have[3], need[3], price[3];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string a; cin >> a;
    for (char i : a) {
        if (i == 'B') need[0]++;
        else if (i == 'S') need[1]++;
        else need[2]++;
    }
    for (int i = 0; i < 3; ++i) cin >> have[i];
    for (int i = 0; i < 3; ++i) cin >> price[i];

    cin >> coin;

    int l = 0, r = 1e13;
    while (l < r) {
        int mid = (l+r+1)/2;
        int cost = 0;
        for (int i = 0; i < 3; ++i) {
            if (need[i] == 0) continue;
            int use = (need[i]*mid);
            if (use > have[i]) {
                use -= have[i];
                if (use > coin/price[i]) {
                    cost = 1e18;
                    break;
                }
                cost += use * price[i];
            }
        }
        // cout << "PREV : " << prev << '\n';
        // cout << "L : " << l << " | R : " << r << '\n';
        // cout << "MID : " << mid << "\n\n";
        if (cost > coin) r = mid-1;
        else l = mid;
    }
    cout << l;

    return 0;
}