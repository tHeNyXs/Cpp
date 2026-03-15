#include <bits/stdc++.h>
using namespace std;

string word;
bool check(int l, int r) {
    if (word[l] != word[r]) return false;
    else if (l-1 >= 0 && r+1 < word.size()) {
        return check(l-1, r+1);
    }
    else return true;
}

int main() {
    cout << "Input String = "; cin >> word;
    int len = word.size();
    bool flag;
    if (len%2) flag = check(len/2, len/2);
    else flag = check(len/2-1, len/2);

    cout << word;
    if (flag) cout << " is a Palindrome.";
    else cout << " is not a Palindrome.";

    return 0;
}