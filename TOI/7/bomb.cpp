#include <bits/stdc++.h>
using namespace std;

typedef struct{
    int x, y;
} B;

bool cmp(const B &a, const B &b) {
    if (a.x != b.x) return a.x > b.x;
    return a.y < b.y;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    B b[n];
    for (int i = 0; i < n; ++i) {
        cin >> b[i].x >> b[i].y;
    }
    sort(b, b + n, cmp);
    int maxX, maxY;
    maxX = maxY = -1;
    for (int i = 0; i < n; ++i) {
        if (b[i].x >= maxX || b[i].y >= maxY) {
            if (b[i].x > maxX) maxX = b[i].x;
            if (b[i].y > maxY) maxY = b[i].y;
            cout << b[i].x << " " << b[i].y << '\n';
        }
    }

    return 0;
}