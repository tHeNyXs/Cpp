#include <bits/stdc++.h>
using namespace std;

int ans(string a) {
    if (a.size() == 1) return 1;
    queue<char> q;
    stack<char> s;
    for (int i = 0; i < a.size(); ++i) {
        q.emplace(a[i]);
        s.emplace(a[i]);
    }

    while (!q.empty() && !s.empty()) {
        if (q.front() != s.top()) return 0;
        q.pop(); s.pop();
    }

    int l = 0, r = a.size()/2;
    if (a.size()%2 == 0) r--;
    string newWord = "";
    for (int i = l; i <= r; ++i) {
        newWord += a[i];
    }
    return 1 + ans(newWord);
}

int main() {
    string a; cin >> a;
    cout << ans(a) << "-Palindrome";

    return 0;
}