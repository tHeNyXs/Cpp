#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 52;
vector<int> graph[N];
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x; cin >> x;
            if (x) graph[i].emplace_back(j);
        }
    }
    

    return 0;
}