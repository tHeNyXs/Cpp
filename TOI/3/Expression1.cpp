#include <bits/stdc++.h>
using namespace std;

int change(char a) {
    if (a == '+') return 0;
    if (a == '*') return 1;
    if (a == '^') return 2;
    return 3;
}

string check(string a, int b, queue<int>& q) {
    char min = '(';
    vector<int> posi;
    int cnt = 0;
    vector<bool> cannot(a.length(), false);
    for (int i = 0; i < a.length(); ++i) {
        if ('0' <= a[i] && a[i] <= '9') continue;
        if (a[i] == '(') cnt++;
        if (cnt) {
            cannot[i] = true;
        }
        if (change(a[i]) < change(min) && !cnt) {
            min = a[i];
        }
        if (a[i] == ')') cnt--;
    }
    // cout << min  << '\n';
    vector<string> ans;
    string temp = "";
    for (int i = 0; i < a.length(); ++i) {
        if ((a[i] == min || ((a[i] == '(' || a[i] == ')') && (min == '(' || min == ')'))) && !cannot[i]) {
            ans.emplace_back(temp);
            temp = "";
            continue;
        }
        temp += a[i];
        if (i == a.length() - 1) {
            ans.emplace_back(temp);
        }
    }
    if (ans.size() == 1 && ans.front()[0] == '(' && ans.front()[a.length() - 1] == ')') {
        ans.pop_back();
        string temp = "";
        for (int i = 1; i < a.length() - 1; ++i) {
            temp += a[i];
        }
        ans.emplace_back(temp);
    }
    // for (auto i : ans) {
    //     cout << i << "     ";
    // }
    // cout << endl;
    // cout << '\n' << b << " " << ans[b - 1] << '\n';
    if (b > ans.size()) return "null";
    else if (!q.empty()) {
        q.pop();
        if (q.empty()) return ans[b - 1];
        return check(ans[b - 1], q.front(), q);
    }
    return ans[b - 1];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string a;
    cin >> a;
    int n; cin >> n;
    while (n--) {
        stack<int> com;
        queue<int> q;
        while (true) {
            int num;
            cin >> num;
            if (num == 0) break;
            com.emplace(num);
            q.emplace(num);
        }
        string result = "";
        int temp = com.size();
        result = check(a, q.front(), q);
        while (!com.empty()) {
            cout << "op(" << com.top() << ",";
            com.pop();
        }
        cout << 'p';
        while (temp--) {
            cout << ')';
        }
        cout << '=' << result << '\n';
    }

    return 0;
}