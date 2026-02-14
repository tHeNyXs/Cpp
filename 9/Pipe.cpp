#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> table;

int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, -1, 1};
string ds[] = {"up", "low", "left", "right"};
int c, r;
int len, cnt;

bool out(int i, int j) {
    return i < 0 || i >= c || j < 0 || j >= r;
}

void dfs(int oi, int oj, string os) {
    for (int i = 0; i < 4; ++i) {
        int ni = oi + di[i];
        int nj = oj + dj[i];
        string ns = ds[i];
        if (out(ni, nj) || ns != os || table[ni][nj] <= 0) continue;
        bool flag, change;
        flag = change = false;
        if (ns == "left") {
            if (table[ni][nj] == 12) ns = "up";
            else if (table[ni][nj] == 14) ns = "low";
            else if (table[ni][nj] == 22) ns = "left";
            else if (table[ni][nj] == 31) {
                ns = "left";
                table[ni][nj] = 21;
                change = true;
            }
            else flag = true;
        }
        else if (ns == "up") {
            if (table[ni][nj] == 13) ns = "left";
            else if (table[ni][nj] == 14) ns = "right";
            else if (table[ni][nj] == 21) ns = "up";
            else if (table[ni][nj] == 31) {
                ns = "up";
                table[ni][nj] = 22;
                change = true;
            }
            else flag = true;
        }
        else if (ns == "low") {
            if (table[ni][nj] == 11) ns = "left";
            else if (table[ni][nj] == 12) ns = "right";
            else if (table[ni][nj] == 21) ns = "low";
            else if (table[ni][nj] == 31) {
                ns = "low";
                table[ni][nj] = 22;
                change = true;
            }
            else flag = true;
        }
        else if (ns == "right") {
            if (table[ni][nj] == 11) ns = "up";
            else if (table[ni][nj] == 13) ns = "low";
            else if (table[ni][nj] == 22) ns = "right";
            else if (table[ni][nj] == 31) {
                ns = "right";
                table[ni][nj] = 21;
                change = true;
            }
            else flag = true;
        }

        if (flag) continue;
        if (!change) table[ni][nj] = 0;
        len++;
        dfs(ni, nj, ns);
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> c >> r;
    table.resize(c, vector<int>(r));
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < r; ++j) {
            cin >> table[i][j];
        }
    }

    vector<int> ans;
    for (int i = 0; i < c; ++i) {
        for (int j = 0; j < r; ++j) {
            if (table[i][j] <= 0) continue;
            cnt++;
            int temp = table[i][j];
            if (temp == 31) {
                table[i][j] = 21;
                dfs(i, j, "left");
                dfs(i, j, "right");
                ans.emplace_back(len);
                len = 0;
                continue;
            }
            table[i][j] = 0;
            if (temp == 11 || temp == 13 || temp == 22) dfs(i, j, "left");
            if (temp == 11 || temp == 12 || temp == 21) dfs(i, j, "up");
            if (temp == 12 || temp == 14 || temp == 22) dfs(i, j, "right");
            if (temp == 13 || temp == 14 || temp == 21) dfs(i, j, "low");
            // for (int k = 0; k < c; ++k) {
            //     for (int l = 0; l < r; ++l) {
            //         cout << table[k][l] << ' ';
            //     }
            //     cout << "\n";
            // }
            // cout << "i : " << i << " j : " << j << "\n\n";
            ans.emplace_back(len);
            len = 0;
        }
    }
    cout << cnt << '\n';
    for (int num : ans) {
        cout << num+1 << ' ';
    }
    
    return 0;
}