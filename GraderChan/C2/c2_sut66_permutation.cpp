#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int MAX = 1e6;

vector<bool> prime(MAX, true);
int n;
int cnt;

unordered_map<char, int> um;

int to_digit(string a) {
    int sum = 0;
    for (char c : a) {
        sum = sum*10 + (c-'0');
    }
    return sum;
}

void findAns(string num) {
    if (num.size() == n) {
        if (prime[to_digit(num)]) cnt++;
        // cout << num << '\n';
        return;
    }

    for (int i = 0; i <= 9; ++i) {
        if (um['0'+i]) {
            um['0'+i]--;
            string temp = num;
            temp += char('0'+i);
            findAns(temp);
            um['0'+i]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    
    prime[0] = prime[1] = false;
    for (int i = 2; i < MAX; ++i)
        if (prime[i]) 
            for (int j = i+i; j < MAX; j += i) prime[j] = false;

    int q; cin >> q >> n;
    while (q--) {
        string ans; cin >> ans;
        um.clear();
        cnt = 0;
        for (int i = 0; i < ans.length(); ++i) um[ans[i]]++;
        findAns("");
        cout << cnt << '\n';
    }
    

    return 0;
}