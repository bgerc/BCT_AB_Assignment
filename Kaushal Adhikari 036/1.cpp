#include<iostream>
using namespace std;

class Person {
    char name[50];
    int year, month, day;
public:
    Person() {};
    void get() {
        cout << " __________________________________input________________________________________" << endl;
        cout << "Enter your Name: " << endl;
        cin >> name;
        cout << "Enter your DOB in order YYYY MM DD:" << endl;
        cin >> year >> month >> day;
        cout << " __________________________________________________________________________" << endl;

        while (month > 12 || month <= 0 || day > 31 || day <= 0) {
            cout << "Enter the correct value!!!" << endl;
            get();
        }
    }

    void show() {
        cout << endl;
        cout << " __________________________________________________________________________" << endl;
        cout << " Name: " << name << endl;
        cout << "DOB in form YYYY/MM/DD: " << year << "/" << month << "/" << day << endl;
        cout << " __________________________________________________________________________" << endl;
    }

    bool isSameDOB(int yr, int mn, int dy) {
        return (year == yr && month == mn && day == dy);
    }
};

int main() {
    int n;
    cout << "Enter the number of records to enter:" << endl;
    cin >> n;

    Person persons[100]; // Array of Person objects

    for (int i = 0; i < n; i++) {
        persons[i].get();
    }

    int yr, mn, dy;
    cout << "Enter the DOB to search for records (YYYY MM DD):" << endl;
    cin >> yr >> mn >> dy;

    cout << "Records with DOB " << yr << "/" << mn << "/" << dy << ":" << endl;
    for (int i = 0; i < n; i++) {
        if (persons[i].isSameDOB(yr, mn, dy)) {
            persons[i].show();
        }
    }

    return 0;
}
