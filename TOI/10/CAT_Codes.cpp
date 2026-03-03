#include <bits/stdc++.h>
using namespace std;

int to_digit(string num, int len) {
    int temp = 0;
    for (int i = 0; i < len; ++i) {
        temp = (temp << 1) | (num[i] - '0');
    }
    return temp;
 }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int k, m; cin >> k >> m;
    unordered_map<int, int> cat;
    for (int i = 0; i < k; ++i) {
        string temp;
        cin >> temp;
        int num = to_digit(temp, m);
        cat[num] = i+1;
        // cout << "I : " << i+1 << " | num : " << num << '\n';
    }

    // for (int n : num) {
    //     cout << n << " ";
    // }

    int n; cin >> n;
    while (n--) {
        int d; cin >> d;
        string num; cin >> num;
        vector<bool> vis(k+1, false);
        int number = 0;
        for (int i = 0; i < m; ++i) {
            number = (number << 1) | (num[i] - '0');
        }
        vis[cat[number]] = true;
        for (int i = m; i < d; ++i) {
            number -= (num[i-m] - '0') << (m-1);
            number *= 2;
            number += num[i] - '0';
            vis[cat[number]] = true;
        }

        bool flag = false;
        for (int i = 1; i <= k; ++i) {
            if (vis[i]) cout << i << " ";
            flag |= vis[i];
        }
        if (!flag) cout << "OK";
        cout << '\n';
    }

    return 0;
}