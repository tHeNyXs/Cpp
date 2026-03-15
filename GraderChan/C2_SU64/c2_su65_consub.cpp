#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> num;
    int x;
    while (cin >> x) {
        num.push_back(x);
    }

    sort(num.begin(), num.end());
    // for (int i : num) cout << i << " ";
    // cout << '\n';

    int maxStreak = 1;
    int maxIdx = 1;
    int tempStreak = 1;
    for (int i = 1; i < num.size(); ++i) {
        if (num[i] == num[i-1]) continue;
        if (num[i] == num[i-1]+1) tempStreak++;
        else tempStreak = 1;
        if (tempStreak > maxStreak) {
            maxStreak = tempStreak;
            maxIdx = i;
        }
        // cout << "I : " << i << " | " << "Temp : " << tempStreak << '\n';
    }
    // cout << "Max : " << maxStreak << '\n';
    for(int i = maxStreak-1; i >= 0; --i) {
        cout << num[maxIdx]-i << ' ';
    }

    return 0;
}