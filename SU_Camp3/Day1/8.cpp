#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    priority_queue<int> pq;
    while (n--) {
        char o; cin >> o;
        if (o == 'P') {
            int x; cin >> x;
            pq.emplace(x);
        }
        else {
            if (pq.empty()) cout << "-1\n";
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }

    return 0;
}