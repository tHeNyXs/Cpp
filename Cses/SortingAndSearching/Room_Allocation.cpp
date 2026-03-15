#include <bits/stdc++.h>
using namespace std;
#define pii pair<pair<int, int>, int>
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<pii> room(n);
    for (int i = 0; i < n; ++i) {
        cin >> room[i].first.first >> room[i].first.second;
        room[i].second = i;
    }
    sort(room.begin(), room.end());
    vector<int> ans(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, 1);
    int cnt = 1;
    for (auto[t, idx] : room) {
        int s = t.first, e = t.second;
        auto[prevD, roomNum] = pq.top(); pq.pop();
        if (prevD < s) {
            pq.emplace(e, roomNum);
            ans[idx] = roomNum;
        }
        else {
            pq.emplace(prevD, roomNum);
            cnt++;
            ans[idx] = cnt;
            pq.emplace(e, cnt);
        }
    }

    cout << cnt << '\n';
    for (int i : ans) cout << i << " ";

    return 0;
}