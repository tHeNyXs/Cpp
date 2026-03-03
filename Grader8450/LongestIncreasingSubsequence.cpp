#include <bits/stdc++.h>
using namespace std;

#define N 5001

int n;
vector<int> dp(N, 1);
int num[N];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> num[i];

    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (num[i] < num[j]) dp[j] = max(dp[i]+1, dp[j]);
        }
    }
    // for (int i = 0; i < n; ++i) {
    //     cout << dp[i] << ' ';
    // }
    cout << *max_element(dp.begin(), dp.end());
    
    return 0;
}