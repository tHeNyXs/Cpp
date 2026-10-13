#include <bits/stdc++.h>
using namespace std;

bool check(string a) {
    stack<char> s;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == ')' || a[i] == '}' || a[i] == ']') {
            if (s.empty()) return false;
            else if (a[i] == ')' && s.top() != '(') return false;
            else if (a[i] == '}' && s.top() != '{') return false;
            else if (a[i] == ']' && s.top() != '[') return false;
            s.pop();
        }
        else s.emplace(a[i]);
    }
    return s.empty();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int q; cin >> q;
    while (q--) {
        string a; cin >> a;
        cout << (check(a) ? "yes\n" : "no\n");
    }

    return 0;
}