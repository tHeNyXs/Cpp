#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n, k;
int arr[N];

bool can(int m) {
    int check[N];
    for (int i = 0; i < n; ++i) {
        if (arr[i] < m) check[i] = -1;
        else check[i] = 1;
    }
    
    int pfs[N];
    pfs[0] = check[0];
    for (int i = 1; i < n; ++i) {
        pfs[i] = pfs[i-1] + check[i];
    }

    int minn = 0;
    for (int i = k-1; i < n; ++i) {
        if (i-k >= 0) minn = min(minn, pfs[i-k]);
        if (pfs[i] - minn > 0) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int l = 0, r = N;
    while (l < r) {
        int mid = (l+r+1)/2;
        if (can(mid)) l = mid;
        else r = mid-1;
        // cout << mid << '\n';
    }
    cout << l;

    return 0;
}