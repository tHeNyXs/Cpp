#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<int> p(N);

struct Node {
    int u, v, w;
};

struct K {
    int a, b, k, idx;
};

int dsu(int a) {
    if (p[a] == a) return a;
    else return p[a] = dsu(p[a]);
}

bool cmpNode(const Node a, const Node b) {
    return a.w < b.w;
}

bool cmpK(const K a, const K b) {
    return a.k < b.k;
}

int main() {
    // ios_base::sync_with_stdio(false); cin.tie(nullptr);
    iota(p.begin(), p.end(), 0);
    int n, m, q; cin >> n >> m >> q;
    Node node[m];
    for (int i = 0; i < m; ++i) cin >> node[i].u >> node[i].v >> node[i].w;
    K k[q];
    for (int i = 0; i < q; ++i) {
        cin >> k[i].a >> k[i].b >> k[i].k;
        k[i].idx = i;
    }

    sort(node, node+m, cmpNode);
    sort(k, k+q, cmpK);

    vector<string> ans(q);
    int j = 0;
    for (int i = 0; i < q; ++i) {
        int nowK = k[i].k;
        int nowIdx = k[i].idx;
        int a = k[i].a;
        int b = k[i].b;
        // cout << "I : " << i << '\n';
        while (j < m) {
            if (node[j].w > nowK) break;
            int pu = dsu(node[j].u);
            int pv = dsu(node[j].v);
            if (pu != pv) p[pv] = pu;
            j++;
        }
        // for (int j = 1; j <= n; ++j) {
        //     cout << p[j] << " ";       
        // } cout << '\n';
        if (dsu(a) == dsu(b)) ans[nowIdx] = "Yes";
        else ans[nowIdx] = "No";
    }
    for (auto i : ans) cout << i << '\n';

    return 0;
}