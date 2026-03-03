#include <iostream>
#include <list>
using namespace std;
int main() {
    list<int> myList = {10, 3, 7, 15, 20, 17};

    int k; cin >> k;
    
    myList.splice(myList.begin(), myList, next(myList.begin(), k), myList.end());
    cout << "swap at position 2\n";
    for (int num : myList) {
        cout << num << ' ';
    }

    return 0;
}