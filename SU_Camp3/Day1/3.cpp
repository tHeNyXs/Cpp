#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string a; cin >> a;
    stack<char> s;
    int cnt = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == '(') s.emplace(a[i]);
        else if (s.empty()) cnt++;
        else s.pop();
    }
    cnt += s.size();
    cout << cnt;

    return 0;
}