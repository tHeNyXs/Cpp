#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<char> ans;
    while (cin.peek() != '\n') {
        char a; cin >> a;
        ans.emplace_back(a);
    }
    sort(ans.begin(), ans.end());
    char target; cin >> target;
    
    int l = 0, r = ans.size()-1;
    bool flag = false;
    while (l <= r) {
        int mid = (l+r)/2;
        if (ans[mid] == target) {
            flag = true;
            break;
        }
        else if (ans[mid] < target) l = mid+1;
        else r = mid-1;
    }
    if (flag) cout << "Found";
    else cout << "Not Found";

    return 0;
}