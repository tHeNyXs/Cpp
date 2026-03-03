#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int s, n, t;
    cin >> s >> n >> t;
    list<int> l[s];
    for (int i = 0; i < s; ++i) {
        int prev;
        for (int j = 0, x; j < n; ++j) {
            cin >> x;
            if (j != 0 && x < prev) break;
            l[i].push_back(x);
            prev = x;
        }
    }

    list<int> sum;
    for (int i = 0; i < s; ++i) {
        sum.splice(sum.begin(), l[i]);
    }

    sum.sort(greater<int>());
    if (t == 0) {
        for (int i : sum) {
            cout << i << " ";
        }
    }
    else if (t == 1) {
        int cnt = 0;
        for (int i : sum) {
            cnt++;
            if (!(cnt % 2)) continue;
            cout << i << " ";
        }
    }
    else {
        int cnt = 0;
        for (int i : sum) {
            cnt++;
            if (cnt % 2) continue;
            cout << i << " ";
        }
    }

    return 0;
}