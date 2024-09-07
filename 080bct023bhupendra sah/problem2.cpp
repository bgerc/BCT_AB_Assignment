/*
Design a class Employee with id, name, and salary as data members. Implement
functions to input employee data and display employees who have a salary greater
than a user-specified amount.
*/

#include<iostream>
#include<iomanip>

using namespace std;

class Employee{
    int id;
    char name[50];
    float salary;

    public:
        void getData(){
            cout << "Enter id, name and salary: ";
            cin >> id >> name >> salary;
        }

        void showData(){
            cout << "Id:" << id << setw(20) << "Name: " << name << setw(20) << "Salary: " << salary << endl;
        }

        float getSal(){
            return salary;
        }
};

int main(){
    int n;
    cout << "Enter the no. of employees: ";
    cin >> n;
    Employee *e = new Employee[n];

    cout << "Enter the employee details of " << n << " employees:" << endl;
    for(int i=0; i<n; i++){
        e[i].getData();
    }

    float salary;

    cout << "Enter a specific salary: ";
    cin >> salary;

    for(int i=0; i<n; i++){
        if(e[i].getSal() > salary)
            e[i].showData();
    }

    delete [] e;
}