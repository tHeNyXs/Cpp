#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int c, r;
int cnt[501][501];
bool vis[501][501];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int q = 2;
    while (q--)
    {
        cin >> c >> r;
        memset(cnt, 0, sizeof(cnt));
        memset(vis, false, sizeof(vis));
        int t; cin >> t;
        for (int i = 0, x, y; i < t; ++i)
        {
            cin >> x >> y;
            vis[x+1][y+1] = true;
        }

        for (int i = 1; i <= c; ++i)
        {
            for (int j = 1; j <= r; ++j)
            {
                if (vis[i][j] || vis[i-1][j]) cnt[i][j] = max(cnt[i-1][j], cnt[i][j-1]) + 1;
                else cnt[i][j] = max(cnt[i-1][j], cnt[i][j-1]);
            }
        }

        for (int i = 1; i <= c; ++i)
        {
            for (int j = 1; j <= r; ++j)
            {
                cout << cnt[i][j] << " ";
            }
            cout << '\n';
        }

        // for (int i = 0; i <     )
        cout << "Hello" << '\n';
    }
    
    return 0;
}