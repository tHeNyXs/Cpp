#include <bits/stdc++.h>
using namespace std;
int n, target;
bool found = false;
void ans(int now, int t, vector<vector<bool>>& lane, string path) {
    // cout << "now : " << now << " | t : " << t << "\n";
    if (found) return;
    if (t == target) {
        for (char i : path) {
            cout << i << "\n";
        }
        found = true;
        return;
    }
    if (!found && lane[t+1][now-1]) ans(now-1, t+1, lane, path+"1");
    if (!found && lane[t+1][now+1]) ans(now+1, t+1, lane, path+"2");
    if (!found && lane[t+1][now]) ans(now, t+1, lane, path+"3");
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int start;
    cin >> n >> start;
    cin >> target;
    vector<vector<bool>> lane(target+1, vector<bool>(n+2, false));
    for (int i = 1; i <= target; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x; cin >> x;
            if (x == 1) lane[i][j] = false;
            else lane[i][j] = true;
        }
    }

    ans(start, 0, lane, "");

    return 0;
}