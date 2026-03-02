#include <iostream>
#include <cmath>
using namespace std;

class footBall {
    private:
        double diameter, mass;
    public:
        void set_diameter(double);
        void set_mass(double);
        double get_volume();
        double get_density();
};

void footBall::set_diameter(double diameter) {
    this->diameter = diameter;
}

void footBall::set_mass(double mass) {
    this->mass = mass;
}

double footBall::get_volume() {
    double r = (diameter/2);
    return (4.0/3.0) * M_PI * pow(r, 3);
}

double footBall::get_density() {
    return mass / get_volume();
}

int main() {
    footBall ball1, ball2;
    ball1.set_diameter(5);
    ball1.set_mass(2);
    cout << "Football1 Volume : " << ball1.get_volume() << '\n';
    cout << "Football1 Density : "<< ball1.get_density() << "\n\n";

    ball2.set_diameter(10);
    ball2.set_mass(4);
    cout << "Football2 Volume : " << ball2.get_volume() << '\n';
    cout << "Football2 Density : "<< ball2.get_density() << "\n\n";
    
    return 0;
}

