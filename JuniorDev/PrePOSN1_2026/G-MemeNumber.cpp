#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    unordered_map<int, bool> check;
    for (int i = 0; i < m; ++i)
    {
        int x; cin >> x;
        check[x] = true;
    }
    int arr[n];
    int front, back;
    front = back = 0;
    int frontSum, backSum;
    frontSum = backSum = 0;
    int prev = 0;
    for (int i = 0; i < n; ++i)
    {  
        int x; cin >> x;
        if (x == 2) {
            if (back-front < k) cout << "0\n";
            if (check[frontSum] && back-front >= k) prev--;
            frontSum -= arr[front];
            if (back-front > k) frontSum += arr[front+k];
            else backSum -= arr[front];
            front++;
            // cout << "FrontSum : " << frontSum << " | BackSum : " << backSum << " | ";
            cout << prev << '\n';
            continue;
        }
        
        int a; cin >> a;
        arr[back] = a;
        if (back-front+1 <= k) {
            frontSum += arr[back];
            backSum += arr[back];
        }
        else {
            backSum -= arr[back-k];
            backSum += arr[back];
        }
        if (check[backSum]) prev++;
        back++;
        // cout << "FrontSum : " << frontSum << " | BackSum : " << backSum << " | ";
        cout << prev << '\n';
    }

    return 0;
}