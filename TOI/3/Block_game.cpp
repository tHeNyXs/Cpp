#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> b;
int score, m, n;
int di[4] = {-1, 1, 0, 0};
int dj[4] = {0, 0, -1, 1};
bool out(int i, int j) {
    return i < 0 || j < 0 || i >= n || j >= m;
}

bool isLet(char a) {
    return 'A' <= a && a <= 'Z';
}

bool bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.emplace(i, j);
    char let = b[i][j];
    bool flag = false;
    while(!q.empty()) {
        auto[ii, jj] = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k) {
            int ni = ii + di[k];
            int nj = jj + dj[k];
            if (out(ni, nj) || (ni == i && nj == j) || b[ni][nj] != let) continue;
            b[ni][nj] = '-';
            score += 5;
            flag = true;
            q.emplace(ni, nj);
        }
    }
    if (flag) {
        b[i][j] = '-';
        score += 5;
    }
    return flag;
}

void check() {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            if (b[i + 1][j] == '-' && isLet(b[i][j])) {
                swap(b[i + 1][j], b[i][j]);
            }
        }
    }
}

void update(int i, int j, int r) {
    swap(b[i][j], b[i][j + r]);
    while (i + 1 < n && b[i + 1][j + r] == '-') {
        swap(b[i][j + r], b[i + 1][j + r]);
        i++;
    }
    bool temp = bfs(i, j + r);
    check();
}

void print() {
    cout << score << '\n';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << b[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    b.resize(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> b[i][j];
        }
    }

    int c; cin >> c;
    while (c--) {
        int i, j;
        cin >> i >> j;
        char com;
        cin >> com;
        int r;
        if (com == 'L') r = -1;
        else r = 1;
        if (out(i, j) || out(i, j + r) || !isLet(b[i][j]) || b[i][j + r] != '-') score -= 5;
        else {
            update(i, j, r);
            for (int k = 0; k < n; ++k) {
                for (int l = 0; l < m; ++l) {
                    if (isLet(b[k][l])) {
                        if (bfs(k, l)) check();
                    }
                }
            }
        }
    }
    print();

    return 0;
}