#include <iostream>
using namespace std;

class headPhone {
    private:
        static string model;
        int price;
        int volume;
        int highest_freq_len;
    public:
        headPhone();
        ~headPhone();
        headPhone(int, int);
        void set_model(string);
        void get_model();
        void set_price(int);
        void set_vol(int);
        int get_vol() {
            return volume;
        }
        int get_price() {
            return price;
        }
};

string headPhone::model;

headPhone::~headPhone() {
    cout << "Good by from headphone's destructor" << '\n';
}

headPhone::headPhone(int vol, int price) {
    volume = vol;
    this->price = price;
    price = 3000;
    highest_freq_len = 16000;
    cout << "Object constructed with volume and price!" << '\n';
}

headPhone::headPhone() {
    volume = 50;
    price = 3000;
    highest_freq_len = 16000;
    cout << "Object constructed!" << '\n';
}

void headPhone::set_model(string model) {
    this->model = model;
}

void headPhone::get_model() {
    cout << model << '\n';
}

void headPhone::set_price(int p) {
    price = p;
}

void headPhone::set_vol(int volumn) {
    this->volume = volumn;
}

int main() {
    headPhone fenix, tee(75, 30000);
    fenix.set_price(6767);
    fenix.set_vol(100);
    fenix.set_model("ABC");
    cout << "Fenix Volume : " << fenix.get_vol() << '\n';
    cout << "Fenix Price : " << fenix.get_price() << '\n';
    cout << "Fenix Model : "; fenix.get_model();

    cout << "Tee Volume : " << tee.get_vol() << '\n';
    cout << "Tee Price : " << tee.get_price() << '\n';

    return 0;
}