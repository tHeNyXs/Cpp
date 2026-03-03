#include <iostream>
#include <list>
using namespace std;
int main() {
    list<int> myList = {10, 3, 7, 15, 20, 17};

    int sum = 0;
    auto it = myList.begin();
    while (it != myList.end()) {
        sum += *it;
        it++;
    }
    cout << sum;

    return 0;
}