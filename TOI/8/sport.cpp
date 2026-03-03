#include <bits/stdc++.h>
using namespace std;

void check(int k, int a, int b, vector<char>& c) {
    if (a == k || b == k) {
        for (char i : c) cout << i << " ";
        cout << '\n';
        return;
    }


    c.emplace_back('W');
    check(k, a + 1, b, c);
    c.pop_back();

    c.emplace_back('L');
    check(k, a, b + 1, c);
    c.pop_back();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int k, a, b;
    cin >> k >> a >> b;
    vector<char> start;
    check(k, a, b, start);

    return 0;
}