#include <iostream>
using namespace std;

int count = 100000;
const int currentYear = 2025;
class product {
    private:
        int id;
        string name;
        int price;
        int expiredYear;
    public:
        product();
        ~product();
        void set_data(string, int, int);
        void print_data();
};

product::product() {
    id = count++;
}

product::~product() {
    if (expiredYear < currentYear) {
        cout << name << " is expired.\n";
    }
}

void product::set_data(string name, int price, int expiredYear) {
    this->name = name;
    this->price = price;
    this->expiredYear = expiredYear;
}

void product::print_data() {
    cout << "----------Product----------\n";
    cout << "ID : " << id << '\n';
    cout << "Name : " << name << '\n';
    cout << "Price : " << price << '\n';
    cout << "Expired Year : " << expiredYear << '\n';
    cout << "---------------------------\n\n";
}

int main() {
    int n;
    cout << "How amount product do you need ?\n";
    cin >> n;
    product p[n];
    for (int i = 0; i < n; ++i) {
        string name;
        cout << "Enter Product " << i+1 << " Name : "; cin >> name;

        int price;
        cout << "Enter Product Price : "; cin >> price;

        int expiredYear;
        cout << "Enter Product Expired Year : "; cin >> expiredYear; cout << '\n';

        p[i].set_data(name, price, expiredYear);
    }

    for (int i = 0; i < n; ++i) {
        p[i].print_data();
    }

    return 0;
}