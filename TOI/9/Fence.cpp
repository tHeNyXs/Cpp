#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int c, r;
int cnt[501][501];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int q = 2;
    while (q--)
    {
        cin >> c >> r;
        memset(cnt, 0, sizeof(cnt));
        int t; cin >> t;
        for (int i = 0, x, y; i < t; ++i)
        {
            cin >> x >> y;
            cnt[x+1][y+1] = 1;
        }

        for (int i = 1; i <= c; ++i)
        {
            for (int j = 1; j <= r; ++j)
            {
                cnt[i][j] += cnt[i-1][j] + cnt[i][j-1] - cnt[i-1][j-1];
            }
        }

        // for (int i = 1; i <= c; ++i)
        // {
        //     for (int j = 1; j <= r; ++j)
        //     {
        //         cout << cnt[i][j] << " ";
        //     }
        //     cout << '\n';
        // }

        int start = min(c, r);
        int result = -1;
        while (true)
        {
            if (start <= 0) break;
            for (int i = c; i >= start; --i)
            {
                for (int j = r; j >= start; --j)
                {
                    int bigRec = cnt[i][j] - cnt[i-start][j] - cnt[i][j-start] + cnt[i-start][j-start];
                    int inRec = cnt[i-1][j-1] - cnt[i-1][j-start+1] - cnt[i-start+1][j-1] + cnt[i-start+1][j-start+1];
                    // cout << "I : " << i << " J : " << j << " Start : " << start << '\n';
                    // cout << "Big = " << bigRec << " In = " << inRec << "\n\n";
                    if (start == 1 || start == 2) result = bigRec;
                    else result = bigRec - inRec;
                    if (!result) break;
                }
                if (!result) break;
            }
            if (!result) break;
            start--;
        }
        cout << start << '\n';
    }
    
    return 0;
}