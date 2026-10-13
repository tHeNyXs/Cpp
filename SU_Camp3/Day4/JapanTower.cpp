#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
struct fw {
    int t[N];

    void update(int idx) {
        while (idx < N) {
            t[idx]++;
            idx += idx & -idx;
        }
    }

    int sum(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += t[idx];
            idx -= idx & -idx;
        }
        return sum;
    }

};

fw f;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    while (n--) {
        int h; cin >> h;
        cout << f.sum(h) << ' ';
        f.update(h);
    }

    return 0;
}