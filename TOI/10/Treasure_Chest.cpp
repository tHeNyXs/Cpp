#include <bits/stdc++.h>
using namespace std;
#define int long long
struct Node {
    int c2, c3, c5, c7;

    Node() {
        c2 = c3 = c5 = c7 = 0;
    }
    
    Node (int a, int b, int c, int d) {
        c2 = a; c3 = b; c5 = c; c7 = d;
    }
};

Node operator+(const Node a, const Node b) {
    Node temp;
    temp.c2 = a.c2 + b.c2;
    temp.c3 = a.c3 + b.c3;
    temp.c5 = a.c5 + b.c5;
    temp.c7 = a.c7 + b.c7;
    return temp;
}

Node operator-(const Node a, const Node b) {
    Node temp;
    temp.c2 = a.c2 - b.c2;
    temp.c3 = a.c3 - b.c3;
    temp.c5 = a.c5 - b.c5;
    temp.c7 = a.c7 - b.c7;
    return temp;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int m, n; cin >> m >> n;
    map<int, Node> pref;
    pref[2] = Node(1, 0, 0, 0);
    pref[3] = Node(0, 1, 0, 0);
    pref[4] = Node(2, 0, 0, 0);
    pref[5] = Node(0, 0, 1, 0);
    pref[6] = Node(1, 1, 0, 0);
    pref[7] = Node(0, 0, 0, 1);
    pref[8] = Node(3, 0, 0, 0);
    pref[9] = Node(0, 2, 0, 0);
    pref[10] = Node(1, 0, 1, 0);
    map<int, Node> c;
    for (int i = 1; i <= m; ++i) {
        int x, s, t;
        cin >> x >> s >> t;
        c[s] = c[s] + pref[x];
        c[t+1] = c[t+1] - pref[x];
    }
    
    int ans = 0;
    int prev = -1;
    int dist = 0;
    Node now;
    for (auto[i, j] : c) {
        int temp = 1;
        temp = (now.c2 + 1) * (now.c3 + 1) * (now.c5 + 1) * (now.c7 + 1);
        // cout << "I : " << i << '\n';
        // cout << "Now : " << now.c2 << " " << now.c3 << " " << now.c5 << " " << now.c7 << '\n';
        // cout << "Temp :" << temp << "\n\n";
        if (temp == ans) {
            dist += i - prev;
        }
        else if (temp > ans) {
            ans = temp;
            dist = i-prev;
        }
        now = now + j;
        prev = i;
    }
    cout << ans << " " << dist;

    return 0;
}