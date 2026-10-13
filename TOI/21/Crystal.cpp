#include <bits/stdc++.h>
using namespace std;
#define tu tuple<int, int, int>

struct Fen{
    int n;
    vector<int> t;
    Fen(int n) {
        this->n = n;
        t.resize(n+1, 0);
    }

    int query(int idx) {
        int result = 0;
        while (idx > 0) {
            result = max(result, t[idx]);
            idx -= idx & -idx;
        }
        return result;
    }

    void update(int idx, int val) {
        while (idx <= n) {
            t[idx] = max(t[idx], val);
            idx += idx & -idx;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int u, k, n; cin >> u >> k >> n;
    vector<tu> vec;
    vector<int> allp;
    for (int i = 1; i <= n; ++i) {
        int p, w, t; cin >> p >> w >> t;
        vec.emplace_back(t, p, w);
        allp.emplace_back(p);
    }

    sort(vec.begin(), vec.end());
    sort(allp.begin(), allp.end());

    Fen all(n);
    vector<Fen> fw(u, Fen(n));
    
    int ans = 0;
    for (auto[t, p, w] : vec) {
        p = lower_bound(allp.begin(), allp.end(), p) - allp.begin() + 1;
        int stay = fw[w].query(p-1)+1;
        
        int jump = 0;
        int best = all.query(p-1);
        if (best >= k) jump = best-k+1;

        int cur = max(stay, jump);
        fw[w].update(p, cur);
        all.update(p, cur);

        ans = max(ans, cur);

    }
    cout << ans;

    return 0;
}