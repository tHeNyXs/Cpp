#include <bits/stdc++.h>
using namespace std;

string convert(int a) {
    string result = "";
    while (a > 0) {
        result += '0' + (a % 2);
        a /= 2;
    }
    result += '0';
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    unordered_map<string, char> m;
    int n; cin >> n;
    for (int i = 'A'; i <= 'Z'; ++i) {
        m[convert(i)] = i;
    }

    string ans = "";
    int s = 1;
    while (n--) {
        string input; cin >> input;
        if (input.size() < 16) continue;
        string toCal = "";
        int it = 0;
        while (it < 16 && toCal.size() < 8) {
            string temp = "";
            temp += input[it];
            temp += input[it + 1];
            if (s == 1) {
                if (temp == "00") {
                    toCal += '0';
                    s = 1;
                }
                else if (temp == "11") {
                    toCal += '1';
                    s = 2;
                }
            }
            else if (s == 2) {
                if (temp == "10") {
                    toCal += '0';
                    s = 3;
                }
                else if (temp == "01") {
                    toCal += '1';
                    s = 4;
                }
            }
            else if (s == 3) {
                if (temp == "00") {
                    toCal += '1';
                    s = 2;
                }
                else if (temp == "11") {
                    toCal += '0';
                    s = 1;
                }
            }
            else if (s == 4) {
                if (temp == "10") {
                    toCal += '1';
                    s = 4;
                }
                else if (temp == "01") {
                    toCal += '0';
                    s = 3;
                }
            }

            
            it += 2;
        }
        ans += m[toCal];
        // cout << toCal << '\n';
    }
    cout << ans;

    return 0;
}