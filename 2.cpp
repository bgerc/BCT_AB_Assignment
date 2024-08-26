
// Design a class Employee with id, name, and salary as data members. Implement
// functions to input employee data and display employees who have a salary greater
// than a user-specified amount.


#include <iostream>
using namespace std;
class Employee{
    int id;
    string name;
    float salary;

    public:
    Employee() : id(0), salary(0.0) {}


    Employee(int i, const string& n, float s) : id(i), name(n), salary(s) {}


    void input(){
        cout << " Enter name " << endl;
        cin.ignore();
        getline(cin, name);
        cout << "Enter id and salary " << endl; 
        cin >> id >> salary;
    }

    void display(){
        cout << " Employee with greater salary is  " << endl;
        cout << " Name " << name << " Id :   "  << id  << endl;
        cout << " Salary :   " << salary  << endl ;
;
    }
    bool compare(float entered_sal)
    {
       return (salary>entered_sal);

       
    }
};
int main()
{
    int n;
    Employee e[100];
    cout << " Enter n " << endl;
    cin >> n;
    for(int i=0; i<n; i++){
        e[i].input();
    }
   
    float sal;
    cout << " Enter the salary of user specified amount  " <<endl;
    cin >> sal;


    bool check=false;
    for(int i=0; i<n; i++){
        if(e[i].compare(sal)){
            e[i].display();
            check=true;
        }
    }
    return 0;
}