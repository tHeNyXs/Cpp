#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int q; cin >> q;
    while (q--) {
        string a, b;
        cin >> a >> b;
        unordered_map<char, int> cnt1, cnt2;
        for (int i = 0; i < a.size(); ++i) cnt1[a[i]]++;
        for (int i = 0; i < b.size(); ++i) cnt2[b[i]]++;
        if (cnt1 != cnt2) {
            cout << "Cannot transform to " << b << '\n';
            continue;
        }

        unordered_map<char, queue<int>> pos;
        for (int i = 0; i < b.size(); ++i) {
            pos[b[i]].emplace(i);
        }

        vector<int> p(a.size(), 0);
        for (int i = 0; i < a.size(); ++i) {
            p[i] = pos[a[i]].front(); pos[a[i]].pop();
        }

        vector<bool> vis(a.size(), false);
        int ans = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (vis[i] || p[i] == i) continue;
            int temp = p[i];
            vis[i] = true;
            int cycle = 1;
            while (temp != i) {
                cycle++;
                vis[temp] = true;
                temp = p[temp];
            }
            ans += cycle-1;
        }
        cout << ans << '\n';
    }

    return 0;
}