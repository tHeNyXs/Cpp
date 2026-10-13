#include <bits/stdc++.h>
using namespace std;

void print(int a1, int a2, int a3, char op)
{
    cout << "YES\n"
         << a1 << op << a2 << '=' << a3;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;
    if (a1+a2 == a3) print(a1, a2, a3, '+');
    else if (a1+a3 == a2) print(a1, a3, a2, '+');
    else if (a2+a3 == a1) print(a2, a3, a1, '+');
    else if (a1*a2 == a3) print(a1, a2, a3, '*');
    else if (a1*a3 == a2) print(a1, a3, a2, '*');
    else if (a2*a3 == a1) print(a2, a3, a1, '*');
    else if (a1/a2 == a3 && !(a1%a2)) print(a1, a2, a3, '/');
    else if (a2/a1 == a3 && !(a2%a1)) print(a2, a1, a3, '/');
    else if (a1/a3 == a2 && !(a1%a3)) print(a1, a3, a2, '/');
    else if (a3/a1 == a2 && !(a3%a1)) print(a3, a1, a2, '/');
    else if (a2/a3 == a1 && !(a2%a3)) print(a2, a3, a1, '/');
    else if (a3/a2 == a1 && !(a3%a2)) print(a3, a2, a1, '/');
    else cout << "NO";

    return 0;
}