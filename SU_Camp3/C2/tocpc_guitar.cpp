#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define pi pair<pii, int>
const int N = 305;
const int inf = 1e18;
int mat[N][N];
int n, m, k;
vector<vector<int>> dist(N, vector<int>(N, inf));
vector<int> que(N);
int ans = inf;

struct Node {
    int u, s, w;

    Node(int u, int s, int w) {
        this->u = u;
        this->s = s;
        this->w = w;
    };

    bool operator<(const Node &b) const {
        return w < b.w;
    }
};

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> mat[i][j];
        }
    }

    for (int i = 1; i <= m; ++i) {
        cin >> que[i];
    }
    
    priority_queue<Node> pq;
    pq.emplace(Node(0, k, 0));
    int ans = inf;
    while (!pq.empty()) {
        auto[u, s, w] = pq.top(); pq.pop();
        w = -w;
        if (u == m+1) {
            ans = min(ans, w);
            continue;
        }
        if (w > dist[s][u]) continue;
        for (int i = 1; i <= s; ++i) {
            int val = mat[que[u]][que[u+1+i]];
            if (u+1+i > m+1) break;
            if (w+val >= dist[s-i][u+1+i]) continue;
            dist[s-i][u+1+i] = w+val;
            pq.emplace(Node(u+1+i, s-i, -(w+val)));
        }
        int val = mat[que[u]][que[u+1]];
        if (w+val < dist[s][u+1]) {
            dist[s][u+1] = w+val;
            pq.emplace(Node(u+1, s, -(w+val)));
        }
    }
    
    cout << ans;

    return 0;
}