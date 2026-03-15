#include <bits/stdc++.h>
using namespace std;

double dist(pair<double, double> a, pair<double, double> b) {
    return sqrt( pow(a.first - b.first, 2) + pow(a.second-b.second, 2) );
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    pair<double, double> p[5];
    for (int i = 0; i < 5; ++i) cin >> p[i].first >> p[i].second;
    double minn, maxx;
    vector<pair<int, int>> pmin, pmax;
    minn = maxx = dist(p[0], p[1]);
    for (int i = 0; i < 5; ++i) {
        for (int j = i+1; j < 5; ++j) {
            double now = dist(p[i], p[j]);
            if (now < minn) {
                minn = now;
                pmin.clear();
            }
            if (now > maxx) {
                maxx = now;
                pmax.clear();
            }
            if (now == maxx) pmax.emplace_back(i, j);
            if (now == minn) pmin.emplace_back(i, j);
            // cout << "I : " << i << " | J : " << j << '\n';
            // cout << "MAX : " << maxx << " | MIN : " << minn << " | NOW : " << now << '\n';
        }
    }
    
    cout << "Max is\n";
    for (auto[i, j] : pmax) {
        cout << "(" << p[i].first << "," << p[i].second << ")" << " - (" << p[j].first << "," << p[j].second << ")\n";
    }
    cout << '\n';

    cout << "Min is\n";
    for (auto[i, j] : pmin) {
        cout << "(" << p[i].first << "," << p[i].second << ")" << " - (" << p[j].first << "," << p[j].second << ")\n";
    }

    return 0;
}