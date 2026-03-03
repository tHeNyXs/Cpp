#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    list<int> o, e;
    int cnt = 0;
    while (true) {
        int x; cin >> x;
        if (x == 0) cnt++;
        else cnt = 0;
        if (cnt == 3) {
            e.pop_front();
            e.pop_front();
            break;
        }
        
        x % 2 ? o.push_front(x) : e.push_front(x);
    }

    while (!e.empty() && !o.empty()) {
        int even = e.front();
        int odd = o.front();
        if (even > odd) e.pop_front();
        else o.pop_front();
    }
    int size = e.size() + o.size();
    cout << (e.empty() ? "EVEN " : "ODD ") << size;
    
    return 0;
}