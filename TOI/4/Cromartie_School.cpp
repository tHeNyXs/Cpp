#include <bits/stdc++.h>
using namespace std;
struct pii {
    int area = 1, water = 0;
};

struct comp {
    bool operator()(const pii& a, const pii& b) {
        if (a.area != b.area) return a.area > b.area;
        return a.water < b.water;
    }
};

vector<vector<int>> b;
int n, m;
int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, -1, 1};

bool out(int i, int j) {
    return i < 0 || j < 0 || i >= n || j >= m;
}

void floodfill(int i, int j, vector<vector<char>>& b) {
    b[i][j] = 'S';
    for (int k = 0; k < 4; ++k) {
        int ni = i + di[k];
        int nj = j + dj[k];
        if (out(ni, nj) || b[ni][nj] != 'P') continue;
        floodfill(ni, nj, b);
    }
}

pii findAns(int i, int j, vector<vector<char>> b) {
    pii ans;
    if (b[i][j] == 'P') {
        floodfill(i, j, b);
        ans.water++;
    }
    i--;
    j--;
    int cnt = 1;
    while (true) {
        if (out(i, j)) break;
        bool flag = false;
        int toPlus = 0;
        if (b[i][j] == 'T') break;
        if (b[i][j] == 'P') {
            floodfill(i, j, b);
            toPlus++;
        }
        for (int k = 1; k <= cnt; ++k) {
            if (out(i, j + k) || out(i + k, j) || b[i][j + k] == 'T' || b[i + k][j] == 'T') {
                flag = true;
                break;
            }
            if (b[i + k][j] == 'P') {
                floodfill(i + k, j, b);
                toPlus++;
            }
            if (b[i][j + k] == 'P') {
                floodfill(i, j + k, b);
                toPlus++;
            }
        }
        if (flag) break;
        cnt++; i--; j--;
        ans.water += toPlus;
        ans.area = cnt * cnt;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> m >> n;
    vector<vector<char>> b(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> b[i][j];
        }
    }

    vector<pii> vec;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            if (b[i][j] != 'T') {
                vec.emplace_back(findAns(i, j, b));
                // cout << i << " " << j << '\n'
                //      << vec.back().area << " " << vec.back().water << "\n\n";
            }
        }
    }
    sort(vec.begin(), vec.end(), comp());
    if (!vec.empty()) cout << vec[0].area << " " << vec[0].water;
    else cout << "0 0";

    return 0;
}