#include <bits/stdc++.h>
using namespace std;

int n, q;
char winner = '0';
vector<vector<char>> table;

bool out(int i, int j) {
    return i <= 0 || i > n || j <= 0 || j > n;
}

void check(int x, int y, int dx, int dy) {
    int cnt = 1;
    int nx = x + dx;
    int ny = y + dy;
    while (!out(nx, ny) && table[nx][ny] == table[x][y]) {
        cnt++;
        nx += dx;
        ny += dy;
    }

    nx = x - dx;
    ny = y - dy;
    while (!out(nx, ny) && table[nx][ny] == table[x][y]) {
        cnt++;
        nx -= dx;
        ny -= dy;
    }

    if (cnt == n) {
        winner = table[x][y];
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> q;
    char start; cin >> start;
    char op;
    if (start == 'X') op = 'O';
    else op = 'X';
    queue<pair<int, int>> com;
    while (q--) {
        int x, y;
        cin >> x >> y;
        com.emplace(x, y);
    }

    table.resize(n+1, vector<char>(n+1, '.'));
    int cur = 0;
    int cnt[3] = {0, 0, 0};
    while (!com.empty()) {
        char place;
        if (cur) place = op;
        else place = start;
        pair<int, int> temp = com.front(); com.pop();
        int x = temp.first;
        int y = temp.second;
        if (x <= 0 || x > n || y <= 0 || y > n || table[x][y] != '.') {
            cnt[1]++;
            continue;
        }

        cnt[0]++;
        table[x][y] = place;
        check(x, y, 1, 0);
        check(x, y, 0, 1);
        check(x, y, 1, 1);
        check(x, y, 1, -1);

        // for (int i = 1; i <= n; ++i) {
        //     for (int j = 1; j <= n; ++j) {
        //         cout << table[i][j];
        //     }
        //     cout << '\n';
        // }
        
        if (winner != '0' || cnt[0] == n*n) break;

        cur = !cur;
    }

    for (int i = 0; i < n*2-1; ++i) cout << '-';
    cout << '\n';
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << table[i][j] << " ";
        }
        cout << '\n';
    }
    for (int i = 0; i < n*2-1; ++i) cout << '-';
    cout << '\n';

    if (winner != '0') cout << "Winner is " << winner << "!\n";
    else if (cnt[0] != n*n) cout << "No More Data!\n";
    else cout << "No Winner!\n";
    cout << "# Valid Turns : " << cnt[0] << '\n';
    cout << "# Invalid Turns : " << cnt[1] << '\n';
    cout << "# Remaining Data : " << com.size();


    return 0;
}