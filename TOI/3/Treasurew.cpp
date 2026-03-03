#include <bits/stdc++.h>
using namespace std;
vector<string> com;
double x, y;
double convert(string a) {
    double ans = 0;
    for (int i = 0; i < a.length(); ++i) {
        ans += ((a[i] - '0') * pow(10, a.length() - 1 - i));
    }
    return ans;
}

void change(string a) {
    string num = "";
    string com = "";
    for (int i = 0; i < a.length(); ++i) {
        if ('0' <= a[i] && a[i] <= '9') {
            num += a[i];
        }
        else com += a[i];
    }
    double value = convert(num);
    if (com == "N") y += value;
    else if (com == "E") x += value;
    else if (com == "S") y -= value;
    else if (com == "W") x -= value;
    else {
        double toPlus = value * sqrt(2) / 2;
        if (com == "NW") {
            x -= toPlus;
            y += toPlus;
        }
        else if (com == "SE") {
            x += toPlus;
            y -= toPlus;
        }
        else if (com == "NE") {
            x += toPlus;
            y += toPlus;
        }
        else if (com == "SW") {
            x -= toPlus;
            y -= toPlus;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    while (true) {
        string a;
        cin >> a;
        if (a == "*") break;
        change(a);
    }
    cout << fixed << setprecision(3) << x << " " << y << '\n'
         << sqrt(pow(x, 2) + pow(y, 2));

    return 0;
}