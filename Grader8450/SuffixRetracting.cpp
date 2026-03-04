#include <bits/stdc++.h>
using namespace std;

int k;

void print(vector<int>& a, int i) {
    if (i == a.size()) return;
    cout << a[i] << " ";
    print(a, i+1);
}

void findSum(vector<int>& a, int  target, int sum) {
    int size = a.size();
    if (size == target-1) {
        a.emplace_back(sum);
        print(a, 0); cout << '\n';
        if (target - k <= 0) target = 1;
        else target -= k;
        size = a.size();
        if (size != 1) findSum(a, target, 0);
        return;
    }
    int back;
    back = a.back(); a.pop_back();
    findSum(a, target, sum+back);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    vector<int> a;
    cin >> k;
    while (true) {
        int x; cin >> x;
        if (x == -1) break;
        a.emplace_back(x);
    }

    print(a, 0); cout << '\n';
    int target = a.size();
    if (target - k <= 0) target = 1;
    else target -= k;
    findSum(a, target, 0);

    return 0;
}