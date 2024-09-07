/*
Design a class Employee with id, name, and salary as data members. Implement
functions to input employee data and display employees who have a salary greater
than a user-specified amount.
*/

#include <iostream>
using namespace std;

class Employee {
private:
    int id;
    string name;
    double salary;

public:
    Employee(int id = 0, string name = "", double salary = 0.0)
        : id(id), name(name), salary(salary) {}

    void inputData() {
        cout << "Enter Employee ID: ";
        cin >> id;
        cout << "Enter Employee Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Employee Salary: ";
        cin >> salary;
    }

    void displayData() const {
        cout << "Employee ID: " << id << "\n";
        cout << "Employee Name: " << name << "\n";
        cout << "Employee Salary: " << salary << "\n";
    }

    bool hasSalaryGreaterThan(double amount) const {
        return salary > amount;
    }
};

int main() {
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;
    Employee* employees = new Employee[n];

    for (int i = 0; i < n; ++i) {
        cout << "\nEnter details for Employee " << i + 1 << ":\n";
        employees[i].inputData();
    }
    double specifiedAmount;
    cout << "\nEnter the salary amount to compare: ";
    cin >> specifiedAmount;
    cout << "\nEmployees with salary greater than " << specifiedAmount << ":\n";
    bool found = false;
    for (int i = 0; i < n; ++i) {
        if (employees[i].hasSalaryGreaterThan(specifiedAmount)) {
            employees[i].displayData();
            found = true;
            cout << "-------------------------\n";
        }
    }
    if (!found) {
        cout << "No employee has a salary greater than " << specifiedAmount << ".\n";
    }

    // Free the dynamically allocated memory
    delete[] employees;

    return 0;
}
