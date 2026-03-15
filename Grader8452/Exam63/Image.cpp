#include <bits/stdc++.h>
using namespace std;
const int L = 70;
int pfs[L][L];
int n, cnt;

void half(int ti, int tj, int di, int dj, int len) {
    // cout << "Ti : " << ti << " | Tj : " << tj << " | Di : " << di << " | Dj : " << dj << " Len : " << len << '\n';
    cnt++; 
    int hi = (ti+di)/2;
    int hj = (tj+dj)/2;
    int p = pfs[hi][hj] - pfs[hi][hj-len] - pfs[hi-len][hj] + pfs[hi-len][hj-len];
    if (p && p != len*len) {
        half(ti, tj, hi, hj, len/2);
    }
    else cnt += 2;

    p = pfs[hi][hj+len] - pfs[hi][hj] - pfs[hi-len][hj+len] + pfs[hi-len][hj];
    if (p && p != len*len) {
        half(ti, hj+1, hi, dj, len/2);
    }
    else cnt += 2;

    p = pfs[di][hj] - pfs[di][hj-len] - pfs[di-len][hj] + pfs[di-len][hj-len];
    if (p && p != len*len) {
        half(hi+1, tj, di, hj, len/2);
    }
    else cnt += 2;

    p = pfs[di][dj] - pfs[di][dj-len] - pfs[di-len][dj] + pfs[di-len][dj-len];
    if (p && p != len*len) {
        half(hi+1, hj+1, di, dj, len/2);
    }
    else cnt += 2;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> pfs[i][j];
            pfs[i][j] += pfs[i-1][j] + pfs[i][j-1] - pfs[i-1][j-1];
        }
    }

    if (pfs[n][n] && pfs[n][n] != n*n) {
        half(1, 1, n, n, n/2);
    }
    cout << cnt;

    return 0;
}