#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string a; cin >> a;
    stack<char> op;
    queue<char> inform;
    for (int i = 0; i < a.size(); ++i) {
        if ('1' <= a[i] && a[i] <= '3') {
            while (!op.empty() && op.top() != '[' && a[i] <= op.top()) {
                inform.emplace(op.top());
                op.pop();
            }
            op.emplace(a[i]);
        }
        else if (a[i] == '[' || a[i] == ']') {
            if (a[i] == '[') op.emplace(a[i]);
            else {
                while (op.top() != '[') {
                    inform.emplace(op.top());
                    op.pop();
                }
                op.pop();
            }
        }
        else inform.emplace(a[i]);
    }
    while (!op.empty()) {
        inform.emplace(op.top()); op.pop();
    }

    stack<int> num;
    while (!inform.empty()) {
        char now = inform.front(); inform.pop();
        if ('A' <= now && now <= 'Z') num.emplace(20);
        else {
            int s = num.top(); num.pop();
            int f = num.top(); num.pop();
            if (now == '1') num.emplace( (f+s)*104 / 100 );
            else if (now == '2') num.emplace( (f+s)*108 / 100 );
            else if (now == '3') num.emplace( (f+s)*116 / 100 );
        }
    }
    cout << num.top();

    return 0;
}