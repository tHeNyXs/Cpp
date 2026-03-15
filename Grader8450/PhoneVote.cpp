#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, c, k; cin >> n >> c >> k;
    unordered_map<int, int> cnt;
    unordered_map<string, int> person(1000000);
    while (n--) {
        string num; cin >> num;
        int v; cin >> v;
        person[num]++;
        if (person[num] <= k) cnt[v]++;
    }
    for (int i = 1; i <= c; ++i) {
        cout << cnt[i] << '\n';
    }

    return 0;
}