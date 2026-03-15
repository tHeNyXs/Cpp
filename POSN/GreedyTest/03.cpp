#include <bits/stdc++.h>
using namespace std;
#define pii pair<double, pair<double, double>>
int main() {
    double maxx;
    int n;
    cin >> maxx >> n;
    vector<pii> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].second.first >> p[i].second.second;
        p[i].first = (p[i].second.second / p[i].second.first);
    }

    sort(p.begin(), p.end(), greater<pii>());
    double cnt = 0;
    double ans = 0;
    int pt = 0;
    while (cnt < maxx && pt < n) {
        double w = p[pt].second.first, v = p[pt].second.second;
        double d = p[pt].first;
        if (cnt+w <= maxx) {
            cnt += w;
            ans += v;
        }
        else {
            ans += (d*(maxx-cnt));
            cnt = maxx;
        }
        pt++;
    }
    cout << fixed << setprecision(2) << ans;

    return 0;
}