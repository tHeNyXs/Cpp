#include <bits/stdc++.h>
using namespace std;
#define tu tuple<int, int, int>
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, q; cin >> n >> q;
    tu p[q];
    int a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 0; i < q; ++i) {
        int l, r; cin >> l >> r;
        p[i] = tu(r, l, i);
    }

    sort(p, p+q);


    vector<int> ans[n];
    multiset<int> s;
    auto[prevR, prevL, start] = p[0];
    for (int i = prevL; i <= prevR; ++i) s.emplace(a[i]);
    int cnt = 0;
    for (auto i : s) {
        ans[start].emplace_back(i);
        cnt++;
        if (cnt >= 10) break;
    }

    for (int i = 1; i < q; ++i) {
        auto[r, l, idx] = p[i];
        // cout << "L : " << l << " | R : " << r << '\n';
        for (int j = prevR+1; j <= r; ++j) s.emplace(a[j]);
        if (prevL > l) {
            for (int j = l; j < prevL; ++j) s.emplace(a[j]);
        }
        else {
            for (int j = prevL; j < l; ++j) {
                auto it = s.find(a[j]); s.erase(it);
            }
        }
        
        cnt = 0;
        for (auto j : s) {
            ans[idx].emplace_back(j);
            cnt++;
            if (cnt >= 10) break;
        }
        prevL = l;
        prevR = r;
    }

    for (int i = 0; i < q; ++i) {
        for (int j : ans[i]) cout << j << " ";
        cout << '\n';
    }

    return 0;
}