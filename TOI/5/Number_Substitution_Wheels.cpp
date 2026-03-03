#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int s[3];
    int input; cin >> input;
    int k[3] = {100, 10, 1};
    for (int i = 0; i < 3; ++i) {
        s[i] = input / k[i];
        input %= k[i];
    }

    int start[3] = {s[0], s[1], s[2]};
    string a; cin >> a;
    string ans = "";
    for (int i = 0; i < a.length(); ++i) {
        int num = a[i] - '0';
        int prev_num, prev_s;
        for (int j = 0; j < 3; ++j) {
            prev_s = s[j];
            s[j] += num - 1;
            if (s[j] == 0) s[j] = 9;
            if (s[j] > 9) s[j] -= 9;
            
            prev_num = num;
            num = s[j];
            if (j == 2) ans += s[j] + '0';

            if (j == 0) s[j] = prev_s + start[0];
            else if (j == 1) s[j] = prev_s - 1; 
            else s[j] = prev_s + start[2];

            if (s[j] < 1) s[j] += 9;
            if (s[j] > 9) s[j] -= 9;
        }
    }

    cout << ans;

    return 0;
}