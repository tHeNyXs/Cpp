#include <bits/stdc++.h>
using namespace std;
deque<char> ans;
unordered_map<int, char> m;
void convert(int start, int press) {
    if (start == 0) {
        while (press-- && !ans.empty()) {
            ans.pop_back();
        }
        return;
    }
    if (start == 6 || start == 8) {
        press %= 4;
        if (press) press -= 4;
    }
    else {
        press %= 3;
        if (press) press -= 3;
    }
    ans.emplace_back(m[start] + press);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    m[1] = 'C';
    m[2] = 'F';
    m[3] = 'I';
    m[4] = 'L';
    m[5] = 'O';
    m[6] = 'S';
    m[7] = 'V';
    m[8] = 'Z';
    int start, press;
    cin >> start >> press;
    start -= 1;
    convert(start, press);
    n--;
    while (n--) {
        int x, y;
        cin >> x >> y;
        int temp = start / 3;
        start += x;
        if (start / 3 < temp) start = temp * 3;
        if (start / 3 > temp) start = temp * 3 + 2;
        temp = start % 3;
        start += y * 3;
        if (start < 0) start = temp;
        if (start > 8) start = temp + 6;
        cin >> press;
        convert(start, press);
    }
    if (ans.empty()) {
        cout << "null";
    }
    while (!ans.empty()) {
        cout << ans.front(); ans.pop_front();
    }

    return 0;
}