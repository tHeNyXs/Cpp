#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, d;
    cin >> n >> d;
    int cnt = 0;
    int prev;
    int maxx = -1;
    queue<int> q;
    for (int i = 0, num; i < n; ++i) {
        cin >> num;
        if (i == 0) {
            prev = num;
            q.emplace(num);
            continue;
        }
        prev = q.front();
        if (num - prev <= d) {
            cnt++;
            maxx = max(maxx, cnt);
        }   
        else {
            q.pop();
        }
        q.emplace(num);
        // cout << maxx << '\n' << prev << " " << num << '\n' << cnt << '\n' << "\n\n";
    }
    cout << maxx;

    return 0;
}