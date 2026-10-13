#include "council.h"
const int MxN = 1e5+5;
int giveAnswer(int n, int m, int q) {
    // edit this
    int p[MxN];
    int cnt[MxN] = {0};
    int ans, maxx;
    maxx = 0;
    for (int i = 0; i < MxN; ++i) p[i] = i;
    for (int i = 1; i < n; ++i) {
        for (int j = i+1; j <= n; ++j) {
            if (sameVote(i, j)) {
                p[j] = p[i];
                cnt[p[i]]++;
                if (cnt[p[i]] > maxx) {
                    maxx = cnt[p[i]];
                    ans = p[i];
                }
            }
        }
    }

    return ans;
}