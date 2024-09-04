/*
Design a class Employee with id, name, and salary as data members. Implement
functions to input employee data and display employees who have a salary greater
than a user-specified amount.
*/

#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

class Worker {
    int empID;
    string empName;
    double empSalary;

public:
    void inputDetails() {
        cout << "Enter Employee ID, Name, and Salary: ";
        cin >> empID;
        cin.ignore();
        getline(cin, empName);
        cin >> empSalary;
    }

    void displayDetails() const {
        cout << "Employee ID: " << empID << setw(20) << "Name: " << empName << setw(20) << "Salary: $" << empSalary << endl;
    }

    double getSalary() const {
        return empSalary;
    }
};

int main() {
    int count;
    cout << "Enter the number of workers: ";
    cin >> count;

    Worker *workers = new Worker[count];

    cout << "Enter the details for " << count << " workers:" << endl;
    for(int i = 0; i < count; i++) {
        workers[i].inputDetails();
    }

    double thresholdSalary;
    cout << "Enter the salary threshold: ";
    cin >> thresholdSalary;

    cout << "Workers earning more than $" << thresholdSalary << ":" << endl;
    for(int i = 0; i < count; i++) {
        if(workers[i].getSalary() > thresholdSalary) {
            workers[i].displayDetails();
        }
    }

    delete[] workers;
    return 0;
}
