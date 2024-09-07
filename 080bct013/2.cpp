#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Employee{
    int id;
    string name;
    float salary;
    public:
    void getData(){
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin,name);
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter salary: ";
        cin >> salary;
    }
    float getSalary(){
        return salary;
    }
    void displayData(){
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Salary: " << salary << endl;
    }
};
int main(){
    float user_specified_amount;
    int n;
    cout << "Enter total number of employee: ";
    cin >> n;
    Employee *e = new Employee[n];
    for(int i=0;i<n;i++){
        e[i].getData();
    }
    cout << "Enter User Specified Amount: ";
    cin >> user_specified_amount;
    for(int i=0;i<n;i++){
        if(e[i].getSalary()>user_specified_amount){
            e[i].displayData();
        }
    }
    return 0;
}