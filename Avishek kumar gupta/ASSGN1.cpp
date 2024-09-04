/*
Create a class person with name and date of birth as data members. Ask the user to
enter a date of birth and print all persons name with a matched date of birth.
*/

#include<iostream>
#include<string>

using namespace std;

class BirthDate {
    int day, month, year;

    public:
        void inputDate() {
            cin >> day >> month >> year;
        }

        void displayDate() const {
            cout << day << "-" << month << "-" << year;
        }

        bool isEqualTo(const BirthDate &other) const {
            return (day == other.day && month == other.month && year == other.year);
        }
};

class Individual {
    string fullName;
    BirthDate dob;

    public:
        void inputDetails() {
            cout << "Enter full name: ";
            cin.ignore();
            getline(cin, fullName);
            cout << "Enter date of birth (dd mm yyyy): ";
            dob.inputDate();
        }

        void displayDetails() const {
            cout << "Full Name: " << fullName << endl;
            cout << "Date of Birth: ";
            dob.displayDate();
            cout << endl;
        }

        friend bool matchBirthDate(const BirthDate&, const Individual&);
};

bool matchBirthDate(const BirthDate &date, const Individual &person) {
    return date.isEqualTo(person.dob);
}

int main() {
    int count;
    cout << "Enter the number of individuals: ";
    cin >> count;

    Individual *individuals = new Individual[count];

    cout << "Enter the details of " << count << " individuals:" << endl;
    for(int i = 0; i < count; i++) {
        individuals[i].inputDetails();
    }

    BirthDate searchDate;
    cout << "Enter the date of birth to search for (dd mm yyyy): ";
    searchDate.inputDate();

    cout << "Individuals with matching date of birth:" << endl;
    for(int i = 0; i < count; i++) {
        if(matchBirthDate(searchDate, individuals[i])) {
            individuals[i].displayDetails();
        }
    }

    delete[] individuals;

    return 0;
}
