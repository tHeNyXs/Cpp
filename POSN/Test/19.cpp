#include <bits/stdc++.h>
using namespace std;
int main() {
    int arr[10];
    for (int i = 0; i < 10; ++i) cin >> arr[i];
    int maxx, minn;
    maxx = minn = abs(arr[0]-arr[1]);
    int check = maxx;
    int startMax = 0;
    int startMin = 0;
    bool flag = false;
    for (int i = 1; i < 9; ++i) {
        int value = abs(arr[i] - arr[i+1]);
        if (value != check) flag = true;
        if (value > maxx) {
            startMax = i;
            maxx = value;
        }
        if (value < minn) {
            startMin = i;
            minn = value;
        }
    }
    if (!flag) {
        cout << "None+++";
    }
    else {
        cout << "Max is " << arr[startMax] << "," << arr[startMax+1] << " ==> " << maxx << " and Min is " << arr[startMin] << "," << arr[startMin+1] << " ==> " << minn;
    }

    return 0;
}