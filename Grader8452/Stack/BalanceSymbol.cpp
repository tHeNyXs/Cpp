#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    cin.ignore();
    while (n--) {
        stack<char> s;
        string a;
        
        getline(cin, a);
        bool flag = false;
        bool inSingle, inDouble;
        inSingle = inDouble = false;
        for (int i = 0; i < a.length(); ++i) {
            if (a[i] == '(' || a[i] == '{' || a[i] == '[' || a[i] == '<') s.emplace(a[i]);
            else if (a[i] == ')' || a[i] == '}' || a[i] == ']' || a[i] == '>') {
                if (s.empty()) flag = true;
                else if (a[i] == ')' && s.top() != '(') flag = true;
                else if (a[i] == '}' && s.top() != '{') flag = true;
                else if (a[i] == ']' && s.top() != '[') flag = true;
                else if (a[i] == '>' && s.top() != '<') flag = true;
                else s.pop();
            }
            else if (a[i] == '\'') {
                if (!inSingle) {
                    s.emplace(a[i]);
                    inSingle = true;
                }
                else {
                    if (s.empty() || s.top() != '\'') flag = true;
                    else {
                        s.pop();
                        inSingle = false;
                    }
                }
            }
            else if (a[i] == '\"') {
                if (!inDouble) {
                    s.emplace(a[i]);
                    inDouble = true;
                }
                else {
                    if (s.empty() || s.top() != '\"') flag = true;
                    else {
                        s.pop();
                        inDouble = false;
                    }
                }
            }
            if (flag) {
                break;
            }
        }
        if (!s.empty()) {
            flag = true;
        }
        cout << (flag ? "NO\n" : "YES\n"); 
    }

    return 0;
}