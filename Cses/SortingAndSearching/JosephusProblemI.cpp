#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    queue<int> q;

    for (int i=1;i<=n;i++) {
        q.push(i);
    }

    while (!q.empty()) {
        int temp = q.front();
        if (q.size() == 1) {
            cout << q.front();
            return 0;
        }
        q.pop();
        cout << q.front() << ' ';
        q.pop();
        q.push(temp);
    }
    return 0;
}