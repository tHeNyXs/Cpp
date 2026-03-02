#include <bits/stdc++.h>
using namespace std;

bool vis[10];
int n, m;
int ans = INT_MAX;

typedef struct P {
    int x, y, z;
};

typedef struct S {
    int m, k, c;
};

P s[10];
S item[10];

int travel(P a, P b) {
    // return (a.x-b.x)*(a.x-b.y) + (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z);
    return pow(a.x-b.x, 2) + pow(a.y-b.y, 2) + pow(a.z-b.z, 2);
}

void dfs(P start, int sum, int monitor, int keyboard, int com) {
    if (monitor <= 0 && keyboard <= 0 && com <= 0) {
        ans = min(sum, ans);
        return;
    }

    for (int i = 0; i < m; ++i) {
        if (vis[i]) continue;
        vis[i] = true;
        dfs(s[i], sum + travel(s[i], start), monitor-item[i].m, keyboard-item[i].k, com-item[i].c);
        vis[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    P u;
    cin >> u.x >> u.y >> u.z;

    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> s[i].x >> s[i].y >> s[i].z;
        cin >> item[i].m >> item[i].k >> item[i].c; 
    }

    for (int i = 0; i < m; ++i) {
        vis[i] = true;
        dfs(s[i], travel(s[i], u), n-item[i].m, n-item[i].k, n-item[i].c);
        memset(vis, false, sizeof(vis));
    }

    cout << ans;

    return 0;
}