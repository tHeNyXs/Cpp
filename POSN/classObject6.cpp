#include <iostream>
#include <iomanip>
using namespace std;

class Times {
    private:
        int hour, min;
    public:
        Times();
        void set_hour(int);
        void set_min(int);
        void print();
        Times operator +(Times);
};

Times::Times() {
    hour = min = 0;
}

void Times::set_hour(int hour) {
    this->hour = hour;
}

void Times::set_min(int min) {
    this->min = min;
}

void Times::print() {
    cout << setw(2) << setfill('0') << hour << ":" << min;
}

Times Times::operator +(Times a) {
    int sumMin = min + a.min;
    int sumHour = hour + a.hour;
    if (sumMin >= 60) {
        sumHour += sumMin/60;
        sumMin %= 60;
    }
    if (sumHour >= 24) sumHour %= 24;

    Times temp; temp.hour = sumHour; temp.min = sumMin;
    return temp;
}

int main() {
    int hour, min;
    Times t1, t2, t3;
    cout << "Set hour (t1) : "; cin >> hour;
    cout << "Set min (t1) : "; cin >> min;
    t1.set_hour(hour); t1.set_min(min);

    cout << "Set hour (t2) : "; cin >> hour;
    cout << "Set min (t2) : "; cin >> min;
    t2.set_hour(hour); t2.set_min(min);

    t3 = t1 + t2;
    t3.print();
    
    return 0;
}

