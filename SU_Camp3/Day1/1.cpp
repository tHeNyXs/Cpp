#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    stack<char> s;
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        char x; cin >> x;
        if (s.empty() || s.top() != x) s.emplace(x);
        else s.pop();
    }

    cout << s.size() << '\n';
    if (s.empty()) {
        cout << "empty";
        return 0;
    }
    while (!s.empty()) {
        cout << s.top(); s.pop();
    }

    return 0;
}