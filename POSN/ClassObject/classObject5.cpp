#include <iostream>
#include <vector>
using namespace std;

const int currentYear = 2025;
class product {
    private:
        int id;
        string name;
        int price;
        int expiredYear;
        int g;
    public:
        void set_data(string, int, int, int);
        void set_id(int);
        void print_data();
        int get_expiredYear();
};

void product::set_data(string name, int price, int expiredYear, int g) {
    this->name = name;
    this->price = price;
    this->expiredYear = expiredYear;
    this->g = g;
}

void product::set_id(int id) {
    this->id = id;
}

void product::print_data() {
    cout << "----------Product----------\n";
    cout << "ID : " << id << " (Group " << g << ")" << '\n';
    cout << "Name : " << name << '\n';
    cout << "Price : " << price << '\n';
    cout << "Expired Year : " << expiredYear << '\n';
    cout << "---------------------------\n\n";
}

int product::get_expiredYear() {
    return expiredYear;
}

class group {
    private:
        vector<product> p;
        int nowId;
    public:
        group();
        void add_group(product&);
        void print_group();
};

group::group() {
    nowId = 100000;
}

void group::add_group(product& pro) {
    pro.set_id(nowId++);
    p.emplace_back(pro);
}

void group::print_group() {
    for (product item : p) {
        if (item.get_expiredYear() < currentYear) item.print_data();
    }
}

int main() {
    int n;
    cout << "How amount product do you need ?\n";
    cin >> n;

    int m;
    cout << "How many group of product do you need ?\n";
    cin >> m;

    product p[n];
    group g[m];
    for (int i = 0; i < n; ++i) {
        string name;
        cout << "Enter Product " << i+1 << " Name : "; cin >> name;

        int price;
        cout << "Enter Product Price : "; cin >> price;

        int expiredYear;
        cout << "Enter Product Expired Year : "; cin >> expiredYear; cout;

        int gro;
        cout << "Enter Product Group ("; for (int j = 1; j <= m; ++j) {cout << j; if(j != m) cout << ' ';} cout << ") : ";
        cin >> gro; cout << '\n';
        if (gro <= 0 || gro > m) {
            cout << "Error";
            return 0;
        }

        p[i].set_data(name, price, expiredYear, gro);
        g[gro-1].add_group(p[i]);
    }

    int tg;
    cout << "What group do you want to check expired date ?\n"; cin >> tg;
    g[tg-1].print_group();

    return 0;
}