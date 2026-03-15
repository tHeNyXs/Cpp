#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n; vector<int> bits;

    Fenwick(int n) {
        this->n = n;
        bits.assign(n+1, 0);
    }

    void update(int i) {
        while (i <= n) {
            bits[i]++;
            i += i&-i;
        }
    }

    int ans(int i) {
        int sum = 0;
        while (i > 0) {
            sum += bits[i];
            i -= i&-i;
        }
        return sum;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    pair<int, int> q[n];
    vector<int> val;
    for (int i = 0; i < n; ++i) {
        cin >> q[i].first >> q[i].second;
        val.emplace_back(q[i].second);
    }

    sort(val.begin(), val.end());
    val.erase(unique(val.begin(), val.end()), val.end());
    Fenwick f(val.size());

    for (int i = 0; i < n; ++i) {
        auto[x, y] = q[i];
        int pos = lower_bound(val.begin(), val.end(), y) - val.begin()+1;
        if (x == 1) f.update(pos);
        else {
            cout << f.ans(pos) << '\n';
        }
    }

    return 0;
}