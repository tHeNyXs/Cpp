#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e3 + 5, MD = 1e9 + 7;
int n, k, c, l, r, a[N], cl[N], cr[N], dp[N], pf[N];

int poww(int b, int ex){
    int res = 1;
    while(ex){
        if(ex & 1){
            res *= b;
            if(res > r) return -1;
        }
        b *= b;
        if(ex != 1 && b > r) return -1;
        ex /= 2;
    }
    return res;
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> k >> c;
    for(int i = 1;i<=n;i++) cin >> a[i], cl[i] = INT_MAX;
    cin >> l >> r;
    for(int i = 1;i<=n;i++){
        int sm = 0;
        for(int j = i;j<=n;j++){
            if(poww(j - i, c) == -1) break;
            sm += poww(j - i, c) * a[j];
            if(sm > r) break;
            if(sm >= l) cl[j] = min(cl[j], i), cr[j] = max(cr[j], i);
        }
    }
    dp[0] = 1;
    for(int i = 0;i<=n;i++) pf[i] = 1;
    for(int i = 1;i<=k;i++){
        for(int j = 0;j<=n;j++) dp[j] = 0;
        for(int j = i;j<=n;j++){
            if(cl[j] == INT_MAX){
                dp[j] = 0;
                continue;
            }
            dp[j] = pf[cr[j] - 1];
            if(cl[j] - 2 >= 0) dp[j] -= pf[cl[j] - 2];
            if(dp[j] < 0) dp[j] += MD;
            dp[j] %= MD;
        }
        pf[0] = dp[0];
        for(int j = 1;j<=n;j++) pf[j] = (pf[j - 1] + dp[j]) % MD;
    }
    cout << dp[n];
}