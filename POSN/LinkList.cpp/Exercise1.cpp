#include <iostream>
#include <list>
using namespace std;
int main() {
    list<int> myList = {10, 3, 7, 15, 20, 17};

    auto it = myList.begin();
    while (it != myList.end()) {
        cout << *it << " ";
        it++;
    }

    return 0;
}