#include "bits/stdc++.h"
using namespace std;
const int INF = 2e9 + 7, SZ = 45e5 + 7, N = 15e2 + 11;
int ht[SZ];
pair<int, int> nums[5][N];
pair<int, int> sum[SZ];
int x, y, n;
signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> x >> y >> n;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> nums[i][j].first >> nums[i][j].second;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int valx = nums[1][i].first + nums[2][j].first;
            int valy = nums[1][i].second + nums[2][j].second;
            int idx = ((valx * 3 + valy) % SZ + SZ) % SZ;
            while (ht[idx])
            {
                idx++;
                idx %= SZ;
            }
            ht[idx] = i * N + j;
            sum[idx] = {valx, valy};
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int valx = x - nums[3][i].first - nums[4][j].first;
            int valy = y - nums[3][i].second - nums[4][j].second;
            int idx = ((valx * 3 + valy) % SZ + SZ) % SZ;
            while (ht[idx])
            {
                if (sum[idx] == make_pair(valx, valy))
                {
                    int a[5] = {0, ht[idx] / N, ht[idx] % N, i, j};
                    for (int k = 1; k <= 4; k++)
                    {
                        cout << nums[k][a[k]].first << ' ' << nums[k][a[k]].second << '\n';
                    }
                    return 0;
                }
                idx++;
                idx %= SZ;
            }
        }
    }
}