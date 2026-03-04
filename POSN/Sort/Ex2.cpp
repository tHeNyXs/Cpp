#include <iostream>
#include <algorithm>
using namespace std;

class date {
    public:
        int d, m, y;
};

bool cmp(const date& a, const date& b) {
    if (a.y != b.y) return a.y < b.y;
    if (a.m != b.m) return a.m < b.m;
    return a.d < b.d;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    date d[n];
    for (int i = 0; i < n; ++i) {
        cin >> d[i].d >> d[i].m >> d[i].y;
    }

    sort(d, d+n, cmp);
    for (int i = 0; i < n; ++i) {
        cout << d[i].d << " " << d[i].m << " " << d[i].y << '\n';
    }

    return 0;
}