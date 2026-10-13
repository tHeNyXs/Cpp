#include <bits/stdc++.h>
using namespace std;
#define tu tuple<int, int, int>
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    map<int, int> mp;
    while (m--) {
        int l, r; cin >> l >> r;
        mp[l]++;
        mp[r+1]--;
    }
    mp[n+1];

    char a; cin >> a;
    int w;
    if (a == 'R') w = 0;
    else if (a == 'G') w = 1;
    else w = 2;

    int ans = 0;
    int prev = 1, val = 0;
    for (auto i : mp) {
        int dist = i.first-prev;
        int cur = val % 3;
        int diff = (w-cur + 3) % 3;
        ans += diff*dist;

        prev = i.first;
        val += i.second;
    }
    cout << ans;

    return 0;
}