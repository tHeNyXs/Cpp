#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, int>
const int N = 1e5+5;
const int M = 2e5+5;
int id = 1;
vector<pair<int, ll>> graph[N+ (2*M)]; // เก็บว่าแต่ละidเชื่อมจากไหนไปไหน
vector<int> temp[N]; // เก็บเมือง
map<pair<int, int>, int> mp; // เอาไว้สร้าง id ของแต่ละเมือง
vector<ll> dist(N + (2*M), 1e18);
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    ll a[n+1];
    for (int i = 1; i <= n; ++i) cin >> a[i];

    // กำหนดไอดีให้ทุกหัวเมืองก่อน
    for (int i = 1; i <= n; ++i) {
        mp[{i, 1}] = id++;
        temp[i].emplace_back(1);
    }

    // แปลงวงเวียน/เมือง เป็นไอดี แล้วเชื่อมในกราฟ
    for (int i = 1; i <= m; ++i) {
        int u, x, v, y;
        cin >> u >> x >> v >> y;
        if (mp[{u, x}] == 0) {
            mp[{u, x}] = id++;
            temp[u].emplace_back(x);
        }
        if (mp[{v, y}] == 0) {
            mp[{v, y}] = id++;
            temp[v].emplace_back(y);
        }
        int startId = mp[{u, x}];
        int endId = mp[{v, y}];
        graph[startId].emplace_back(endId, 1);
        graph[endId].emplace_back(startId, 1);
    }

    // เชื่อมเมืองแต่ละเมืองในวงเวียน
    for (int i = 1; i <= n; ++i) {
        sort(temp[i].begin(), temp[i].end());
        if (temp[i].size() == 1) continue;
        // เชื่อมทุกเมือง กับ เมืองก่อนหน้า
        for (int j = 1; j < temp[i].size(); ++j) {
            int nowId = mp[{i, temp[i][j]}];
            int prevId = mp[{i, temp[i][j-1]}];
            graph[nowId].emplace_back(prevId, temp[i][j] - temp[i][j-1]);
            graph[prevId].emplace_back(nowId, temp[i][j] - temp[i][j-1]);
            // cout << temp[i][j] - temp[i][j-1] << '\n';
        }
        // เชื่อมเมืองหน้าสุด กับ เมืองท้ายสุด
        int startId = mp[{i, 1}];
        int endId = mp[{i, temp[i].back()}];
        graph[startId].emplace_back(endId, a[i] - temp[i].back() + 1);
        graph[endId].emplace_back(startId, a[i] - temp[i].back() + 1);
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[mp[{1, 1}]] = 0;
    pq.emplace(0, mp[{1, 1}]);
    while (!pq.empty()) {
        auto[nowDist, nowId] = pq.top(); pq.pop();
        if (nowDist > dist[nowId]) continue;
        for (auto[v, w] : graph[nowId]) {
            if (nowDist + w >= dist[v]) continue;
            dist[v] = nowDist + w;
            pq.emplace(dist[v], v);
        }
    }

    if (dist[mp[{n, 1}]] == 1e18) cout << "-1";
    else cout << dist[mp[{n, 1}]];

    return 0;
}