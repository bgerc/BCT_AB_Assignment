#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    int id;
    string name;
    double salary;

public:
    
    void input() {
        cout << "Enter Employee ID: ";
        cin >> id;
        cin.ignore();                               // To ignore the newline character
        cout << "Enter Employee Name: ";
        getline(cin, name);
        cout << "Enter Employee Salary: ";
        cin >> salary;
    }

    
    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", Salary: " << salary << endl;
    }

   
    double getSalary() const {
        return salary;
    }
};

int main() {
    const int MAX_EMPLOYEES = 100;
    Employee employees[MAX_EMPLOYEES];
    int n;

    cout << "Enter the number of employees: ";
    cin >> n;

    
    for (int i = 0; i < n; ++i) {
        cout << "Enter details for employee " << i + 1 << ":\n";
        employees[i].input();
    }

    double limit;
    cout << "Enter the user input salary: ";
    cin >> limit;

    cout << "Employees with salary greater than " << limit << ":\n";
    for (int i = 0; i < n; ++i) {
        if (employees[i].getSalary() > limit) {
            employees[i].display();
        }
    }

    return 0;
}
