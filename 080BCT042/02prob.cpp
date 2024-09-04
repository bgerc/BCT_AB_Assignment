// Design a class Employee with id, name, and salary as data members. Implement
// functions to input employee data and display employees who have a salary greater
// than a user-specified amount.

#include <iostream>
#include <string>

using namespace std;

class Employee
{
    int id;
    string name;
    float salary;

public:
    void getData()
    {
        cout << "Enter id: ";
        cin >> id;
        cin.ignore();
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter salary: ";
        cin >> salary;
    }

    void showData() const
    {
        cout << "Id: " << id << "\tName: " << name << "\tSalary: " << salary << endl;
    }

    float getSalary() const
    {
        return salary;
    }
};

int main()
{
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;

    Employee *employees = new Employee[n];

    cout << "Enter the details of " << n << " employees:" << endl;
    for (int i = 0; i < n; ++i)
    {
        employees[i].getData();
    }

    float reqsalary;
    cout << "Enter a specific salary: ";
    cin >> reqsalary;

    cout << "\nEmployees with a salary greater than " << reqsalary << ":\n";
    bool found = false;
    for (int i = 0; i < n; ++i)
    {
        if (employees[i].getSalary() > reqsalary)
        {
            employees[i].showData();
            found = true;
        }
    }

    if (!found)
    {
        cout << "No employees found with a salary greater than " << reqsalary << "." << endl;
    }

    delete[] employees;
    return 0;
}