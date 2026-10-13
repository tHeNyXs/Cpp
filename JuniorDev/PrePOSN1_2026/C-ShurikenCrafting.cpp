#include <bits/stdc++.h>
using namespace std;

void printFront(int size)
{
    for (int i = 1; i <= size; ++i)
    {
        for (int j = 1; j <= size; ++j) cout << '.';
        for (int j = 1; j <= size-i; ++j) cout << '.';
        for (int j = 1; j <= i; ++j) cout << '#';
        for (int j = 1; j <= size; ++j) cout << '.';
        cout << '\n';
    }
}

void printBack(int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 1; j <= size; ++j) cout << '.';
        for (int j = 1; j <= size-i; ++j) cout << '#';
        for (int j = 1; j <= i; ++j) cout << '.';
        for (int j = 1; j <= size; ++j) cout << '.';
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string a; cin >> a;
    string firstName = "", lastName = "";
    for (auto i : a)
    {
        if ('a' <= i && i <= 'z') firstName += i;
        else lastName += i;
    }
    firstName[0] -= 'a'-'A';
    for (int i = 1; i < lastName.size(); ++i)
    {
        lastName[i] += 'a'-'A';
    }
    int k; cin >> k;
    string fullName = firstName+lastName;
    if (k == 0) cout << fullName;
    else
    {
        int size = 2;
        while (pow(size, 2) < fullName.size()) size++;
        printFront(size);
        int pt = 0;
        while (fullName.size() != pow(size, 2)) fullName += '=';
        for (int i = 0; i < size; ++i)
        {
            for (int j = 1; j <= i; ++j) cout << '.';
            for (int j = 1; j <= size-i; ++j) cout << '#';
            for (int j = 1; j <= size; ++j) cout << fullName[pt++];
            for (int j = 1; j <= i+1; ++j) cout << '#';
            for (int j = 1; j <= size-i-1; ++j) cout << '.';
            cout << '\n';
        }
        printBack(size);
    }

    return 0;
}