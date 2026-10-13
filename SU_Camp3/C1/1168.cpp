#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<string> a;
    a.push_back("*");
    queue<string> q;
    for (char i = '1'; i <= '9'; i = char(i+1)) {
        string temp = "";
        temp += i;
        q.emplace(temp); a.emplace_back(temp);
    }

    while (!q.empty()) {
        string now = q.front(); q.pop();
        char last = now[now.size()-1];
        for (char i = char(last+1); i <= '9'; i = char(i+1)) {
            q.emplace(now + i); a.emplace_back(now + i);
        }
    }
    
    while (n--) {
        int x; cin >> x;
        if (x > a.size()) cout << "-1\n";
        else cout << a[x] << '\n';
    }

    return 0;
}