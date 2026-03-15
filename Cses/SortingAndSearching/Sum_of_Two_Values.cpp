#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, t; cin >> n >> t;
    vector<pair<int, int>> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i].first;
        vec[i].second = i+1;
    }

    sort(vec.begin(), vec.end());

    for (int i = 0; i < n; ++i) {
        int need = t-vec[i].first;
        int l = i+1, r = n-1;
        while (l <= r) {
            int mid = (l+r)/2;
            if (vec[mid].first == need) {
                cout << vec[i].second << " " << vec[mid].second;
                return 0;
            }
            else if (vec[mid].first > need) r = mid-1;
            else l = mid+1;
        }
    }
    cout << "IMPOSSIBLE";

    return 0;
}