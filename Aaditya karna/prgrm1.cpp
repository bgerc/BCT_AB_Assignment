#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string Name;
    int DOB;

public:
    void getInput() {
        cout << "Enter the name: ";
        cin.ignore();  // To ignore any leftover newline characters in the input buffer
        getline(cin, Name);  // Get the full name, including spaces
        cout << "Enter the DOB (in format YYYYMMDD): ";
        cin >> DOB;
    }

    void display(int searchDOB) {
        if (DOB == searchDOB) {
            cout << "Name: " << Name << endl;
        }
    }
};

int main() {
    Person p[10];
    int n;
    cout << "Enter the number of persons: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        p[i].getInput();
    }

    int searchDOB;
    cout << "Enter the date of birth (in format YYYYMMDD) to search for: ";
    cin >> searchDOB;

    cout << "Persons with DOB " << searchDOB << ":" << endl;
    for (int i = 0; i < n; i++) {
        p[i].display(searchDOB);
    }

    return 0;
}