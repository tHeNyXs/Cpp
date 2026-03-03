#include <bits/stdc++.h>
using namespace std;

class mouse {
    private:
        string name;
        string sensor;
        string color;
        int cleanliness;
        int battery;
        int weight;
        bool on;
    public:
        mouse();
        void use(int, int);
        void charge(int);
        void moving();
        void check();
        void clean(int);
};

mouse::mouse() {
    name = "VXE MAD R1";
    sensor =  "PAW 3395";
    color = "White";
    weight = 42;
    cleanliness = battery = 100;
};

void mouse::use(int useBatt, int disCleanliness) {
    cout << "Use Battery : " << useBatt << "%\n";
    cout << "More dirty : " << disCleanliness << "%\n\n";
    battery -= useBatt;
    cleanliness -= disCleanliness;
}

void mouse::charge(int chargeBatt) {
    cout << "Charge : " << chargeBatt << "%\n\n";
    battery += chargeBatt;
    on = false;
}

void mouse::moving() {
    on = true;
    cout << "Using now!\n\n";
}

void mouse::check() {
    cout << "----------Staus----------\n";
    cout << "Battery : " << battery << "%\n";
    cout << "CLeanliness : " << cleanliness << "%\n";
    cout << "Staus : "; cout << (on ? "On" : "off") << '\n';
    cout << "-------------------------\n\n";
}

void mouse::clean(int clean) {
    cout << "Clean More : " << clean << "%\n\n";
    cleanliness += clean;
}

int main() {
    mouse fenix_mouse;
    fenix_mouse.check();
    fenix_mouse.moving();
    fenix_mouse.use(50, 15);
    fenix_mouse.check();
    fenix_mouse.charge(50);
    fenix_mouse.check();
    fenix_mouse.clean(10);
    fenix_mouse.check();

    return 0;
}