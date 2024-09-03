#include <iostream>
#include <cstdlib>
using namespace std;

const float User_specifiedamount = 80000.00;

class employee {
    int id;
    string name;
    float salary;

public:
    void getinput() {
        cout << "Enter the ID: ";
        cin >> id;
        cout << "Enter the name: ";
        cin.ignore();  // Ignore leftover newline from previous input
        getline(cin, name);  // Read the full name
        cout << "Enter the salary: ";
        cin >> salary;
    }

    void display() {
        if (salary >= User_specifiedamount) {
            cout << "ID: " << id << endl;
            cout << "Name: " << name << endl;
            cout << "Salary: " << salary << endl;
        }
    }
};

int main() {
    int n;
    employee e[10];
    cout << "Enter the number of employees: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        e[i].getinput();
    }

    cout << "Employees with a salary greater than or equal to " << User_specifiedamount << ":" << endl;
    for (int i = 0; i < n; i++) {
        e[i].display();
    }

    return 0;
}
