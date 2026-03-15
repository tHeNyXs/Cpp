#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    vector<int> num;
    num.emplace_back(INT_MIN);
    int x;
    while (cin >> x) {
        num.emplace_back(x);
    }
    num.emplace_back(INT_MIN);
    for (int i = 1; i < num.size()-1; ++i) {
        bool con1, con2;
        con1 = con2 = true;

        if (i > 0 && num[i] <= num[i-1]) con1 = false;
        if (i != num.size()-1 && num[i] <= num[i+1]) con2 = false;
        if (con1 && con2) cout << num[i] << " ";
    }

    return 0;
}