#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> b(11, vector<char>(81, '.'));
int maxx = -1;
void create(int s, int h) {
    int xc = h * 2;
    for (int i = maxx; xc >= 2; --i, xc -= 2, ++s) {
        for (int j = 0; j < xc; ++j) {
            if ((j == 0 || j == xc - 1) && (b[i][s + j] == '/' || b[i][s + j] == '\\')) b[i][s + j] = 'v';
            else if (j == 0 && b[i][s + j] == '.') b[i][s + j] = '/';
            else if (j == xc - 1 && b[i][s + j] == '.') b[i][s + j] = '\\';
            else b[i][s + j] = 'X';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int mr = -1;
    int rh = -1;
    vector<pair<int, int>> com(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> com[i].first >> com[i].second;
        maxx = max(maxx, com[i].second);
        if (com[i].first > mr) {
            mr = com[i].first;
            rh = com[i].second;
        }
    }
    for (int i = 1; i <= n; ++i) {
        create(com[i].first,  com[i].second);
    }
    for (int i = 1; i <= maxx; ++i) {
        for (int j = 1; j <= mr - 1 + (rh * 2); ++j) {
            cout << b[i][j];
        }
        cout << '\n';
    }
    

    return 0;
}