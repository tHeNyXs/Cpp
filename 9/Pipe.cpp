#include <iostream>
#include <vector>
using namespace std;

#define t table[i][j]

struct Pipe
{
    bool up, low, left, right;
    Pipe()
    {
        up = low = left = right = false;
    }
};

vector<vector<Pipe>> table;
int cnt, tempLong;
int c,r;

int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, -1, 1};
// up low left right

bool out(int i, int j)
{
    return i < 0 || i >= c || j < 0 || j >= r;
}

void dfs(int oi, int oj)
{
    for (int i = 0; i < 4; ++i)
    {
        int ni = oi+di[i];
        int nj = oj+dj[i];
        if (out(ni, nj) || vis[ni][nj] == 0) continue;
        if (i == 0 && (!table[ni][nj].low || !table[oi][oj].up)) continue;
        if (i == 1 && (!table[ni][nj].up || !table[oi][oj].low)) continue;
        if (i == 2 && (!table[ni][nj].right || !table[oi][oj].left)) continue;
        if (i == 3 && (!table[ni][nj].left || !table[oi][oj].right)) continue;
        vis[oi][oj]--;
        for (int j = 0; j < c; ++j)
        {
            for (int k = 0; k < r; ++k)
            {
                cout << vis[j][k] << " ";
            }
            cout << '\n';
        }
        cout << "oi : " << oi << " oj : " << oj << '\n' << "ni : " << ni << " nj : " << nj << "\n\n";
        tempLong++;
        dfs(ni, nj);
    }
}


int main()
{
    // ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> c >> r;
    table.resize(c, vector<Pipe>(r));

    for (int i = 0; i < c; ++i)
    {
        for (int j = 0, temp; j < r; ++j)
        {
            cin >> temp;
            if (temp == 11 || temp == 13 || temp == 22 || temp == 31) t.left = true;
            if (temp == 11 || temp == 12 || temp == 21 || temp == 31) t.up = true;
            if (temp == 12 || temp == 14 || temp == 22 || temp == 31) t.right = true;
            if (temp == 13 || temp == 14 || temp == 21 || temp == 31) t.low = true;
            if (temp == 31) vis[i][j] = 2;
            else if (temp != 0) vis[i][j] = 1;
            else vis[i][j] = 0;
        }
    }

    vector<int> ans;
    for (int i = 0; i < c; ++i)
    {
        for (int j = 0; j < r; ++j)
        {
            if (vis[i][j] != 0)
            {
                tempLong = 0;
                // cout << "i : " << i << " j : " << j << "\n";
                dfs(i, j);
                ans.emplace_back(tempLong);
                cnt++;
            }
        }
    }
    
    cout << cnt << '\n';
    for (int num : ans) cout << num << ' ';

    return 0;
}