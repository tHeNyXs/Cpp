#include <bits/stdc++.h>
using namespace std;

class STD {
    public:
        string fname, lname;
        int score;
        bool operator<(STD);
};

bool STD::operator<(STD a) {
    if (score != a.score) return score > a.score;
    if (fname != a.fname) return fname < a.fname;
    return lname < a.lname;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    STD s[n];
    for (int i = 0; i < n; ++i) {
        cin >> s[i].fname >> s[i].lname >> s[i].score;
    }

    sort(s, s+n);
    for (int i = 0; i < n; ++i) {
        cout << s[i].fname << " " << s[i].lname << " " << s[i].score << '\n';
    }

    return 0;
}