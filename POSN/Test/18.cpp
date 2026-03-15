#include <bits/stdc++.h>
using namespace std;

bool check(int l, int r, string word) {
    if (word[l] != word[r]) return false;
    else if (l-1 >= 0 && r+1 < word.size()) {
        return check(l-1, r+1, word);
    }
    else return true;
}

int ans(string word) {
    if (word.size() == 1) return 1;
    int len = word.size();
    int l, r;
    l = r = len/2;
    if (len%2 == 0) l--;

    // cout << "L : " << l << " | R : " << r << '\n';

    if (check(l, r, word)) {
        string newWord = "";
        for (int i = 0; i <= l; ++i) newWord += word[i];
        return 1 + ans(newWord);
    }
    else return 0;
}

int cnt = 0;
int main() {
    string word; cin >> word;
    cout << word << " is " << ans(word) << "-Palindrome";

    return 0;
}