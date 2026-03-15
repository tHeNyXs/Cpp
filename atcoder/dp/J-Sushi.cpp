#include <bits/stdc++.h>
using namespace std;
int A, B, C;
int n;
double dp[305][305][305];

double ans(int x, int y, int z) {
    if (x < 0 || y < 0 || z < 0) return 0;
    if (!x && !y && !z) return 0;
    if (dp[x][y][z]) return dp[x][y][z];
    double sum = n;
    if (x > 0) sum += x * ans(x-1, y, z);
    if (y > 0) sum += y * ans(x+1, y-1, z);
    if (z > 0) sum += z * ans(x, y+1, z-1);
    sum /= (x+y+z);
    dp[x][y][z] = sum;
    return dp[x][y][z];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    A = B = C = 0;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if (x == 1) A++;
        else if (x == 2) B++;
        else C++;
    }
    cout << fixed << setprecision(10) << ans(A, B, C);

    return 0;
}