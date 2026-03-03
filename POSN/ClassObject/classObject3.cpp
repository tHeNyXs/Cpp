#include <iostream>
using namespace std;

class studentCard {
    private:
        int id;
        string firstName;
        string lastName;
        string birthDate;
    public:
        studentCard();
        ~studentCard();
        void set_data(int, string, string, string);
        void print_all_data();
};

studentCard::studentCard() {
    id = 1000;
    firstName = "Somsri";
    lastName = "Sasom";
    birthDate = "01/01/1900";
}

studentCard::~studentCard() {
    cout << "Good bye\n";
}

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
    studentCard fenix, im, nine;
    fenix.set_data(6767, "Wasuthron", "Jirapatcharasin", "14/02/2009");
    fenix.print_all_data();

    im.set_data(1234, "Tanat", "Saiphet", "23/05/2009");
    im.print_all_data();

    nine.set_data(0005, "Vichit", "Vhanthongkum", "01/01/2009");
    nine.print_all_data();

    return 0;
}

