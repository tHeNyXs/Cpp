#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
int main() {
    list<int> myList = {10, 3, 7, 15, 20, 17};

    int position, value;
    cin >> position >> value;

    auto it = myList.begin();
    advance(it, position);
    myList.insert(it, value);

    for (auto num : myList) {
        cout << num << " ";
    }

    return 0;
}