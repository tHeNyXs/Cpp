#include <iostream>
using namespace std;

class studentCard {
    private:
        int id;
        string firstName, lastName, birthDate;
    public:
        void set_data(int, string, string, string);
        void print_all_data();
};

void studentCard::set_data(int id, string firstName, string lastName, string birthDate) {
    this->id = id;
    this->firstName = firstName;
    this->lastName = lastName;
    this->birthDate = birthDate;
}

void studentCard::print_all_data() {
    cout << "ID : " << id << '\n';
    cout << "Firstname : " << firstName << '\n';
    cout << "Lastname : " << lastName << '\n';
    cout << "Birth Date : " << birthDate << "\n\n";
}

int main() {
    studentCard fenix, t, few;
    fenix.set_data(6767, "Wasuthron", "Jirapatcharasin", "14/02/2009");
    fenix.print_all_data();

    t.set_data(1234, "Teerapon", "Soonthorn", "03/02/2009");
    t.print_all_data();

    few.set_data(5678, "Sittiphum", "Laosamathikul", "28/03/2009");
    few.print_all_data();

    return 0;
}

