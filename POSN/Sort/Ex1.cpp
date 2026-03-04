#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    int num[n];
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }

    for (int i = 0; i < n-1; ++i) {
        int idx = i;
        int minn = num[i];
        for (int j = i+1; j < n; ++j) {
            if (minn>num[j]) {
                minn = num[j];
                idx = j;
            }
        }
        if (idx != i) swap(num[i], num[idx]);
        for (int j = 0; j < n; ++j) {
            cout << num[j] << " ";
        }
        cout << '\n';
    }

    return 0;
}