#include <iostream>
using namespace std;
int main() {
    char a; cin >> a;
    double x; cin >> x;
    if (a == 'i') x *= 2.54;
    else if (a == 'c') x /= 2.54;
    else {
        cout << "Error";
        return 0;
    }
    cout << "Result is " << x;

    return 0;
}