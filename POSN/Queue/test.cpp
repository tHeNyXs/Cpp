#include <iostream>
#include <queue>
using namespace std;
int main() {
    int N = 10;
    queue<string> q;
    q.push("1");

    for (int i = 0; i < N; ++i) {
        string front = q.front(); q.pop();
        cout << front << '\n';

        q.push(front + "0");
        q.push(front + "1");
    }

    return 0;
}