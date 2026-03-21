#include <bits/stdc++.h>
using namespace std;
int maxx;

struct Day{
    int day, min;
};

Day operator+(const Day& a, const Day& b) {
    Day temp; temp.day = a.day + b.day;
    if (a.min + b.min > maxx) {
        temp.day++;
        temp.min = b.min;
    }
    else {
        temp.min = a.min + b.min;
    }
    return temp;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> maxx;
    int n; cin >> n;
    Day dayJ[n+1], dayK[n+1];
    for (int i = 1; i <= n; ++i) {
        cin >> dayJ[i].min;
        dayJ[i].day = 0;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> dayK[i].min;
        dayK[i].day = 0;
    }

    vector<vector<Day>> dp(n+1, vector<Day>(n+1));
    Day temp; temp.day = 1; temp.min = 0;
    dp[0][0] = temp;
    for (int i = 1; i <= n; ++i) {
        dp[0][i] = dayK[i];
        dp[0][i] = dp[0][i] + dp[0][i-1];

        dp[i][0] = dayJ[i];
        dp[i][0] = dp[i][0] + dp[i-1][0];
    }

    for (int j = 1; j <= n; ++j) {
        for (int k = 1; k <= n; ++k) {
            Day prev1 = dp[j][k-1] + dayK[k];
            Day prev2 = dp[j-1][k] + dayJ[j];
            if (prev1.day < prev2.day) dp[j][k] = prev1;
            else if (prev1.day > prev2.day) dp[j][k] = prev2;
            else if (prev1.min < prev2.min) dp[j][k] = prev1;
            else dp[j][k] = prev2;
        }
    }

    cout << dp[n][n].day << " " << dp[n][n].min;

    return 0;
}