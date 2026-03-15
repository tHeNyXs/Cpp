#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    pair<int, int> arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i].first;
        arr[i].second = i+1;
    }
    sort(arr, arr+n);

    int pt = 0;
    int cnt = 1;
    while (pt < n) {
        if (pt+1 == n) {
            cout << "R#" << cnt << " - Movie" << arr[pt].second << '\n';
            pt++;
            continue;
        }
        int sum = arr[pt].first + arr[pt+1].first;
        if (sum > 240) {
            cout << "R#" << cnt << " - Movie" << arr[pt].second << '\n';
            pt++;
        }
        else {
            cout << "R#" << cnt << " - Movie" << arr[pt].second << " Movie" << arr[pt+1].second << '\n';
            pt += 2; 
        }
        cnt++;
    }

    return 0;
}