#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& arr, int l, int r, int target) {
    if (l > r) return -1;

    int mid = (l+r)/2;

    if (arr[mid] == target) return mid;
    else if (arr[mid] > target) return binarySearch(arr, l, mid-1, target);
    else return binarySearch(arr, mid+1, r, target);
}

int main() {
    vector<int> arr = {1, 2, 5, 8, 10, 48};
    int result = binarySearch(arr, 0, arr.size()-1, 8);
    cout << "Num 8 at index : " << result;

    return 0;
}