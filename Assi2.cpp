#include<iostream>
using namespace std;
class EMPLOYEE
{
    int empid;
    char name[50] ;//employee name 
    float salary;
    public:
    void getinput()
    {
        cout<<"enter employee no,name, salary:";
        cin>>empid>>name>>salary;
    }
    void show()
    {
        cout<<"employee id:"<<empid<<endl<<"employee name:"<<name<<endl<<"basic salary:"<<salary<<endl;
    }
    friend void compare(EMPLOYEE* ,int n, float enteredsalary);
};
void compare(EMPLOYEE* E,int n, float enteredsalary)
{
    for(int i=0;i<n;i++)
    {
        if(E[i].salary==enteredsalary)
        {
            E[i].show();
        }
    }
}
int main()
{
    int n,i,enteredsalary;
    cout<<"How many employee:";
    cin>>n;
    EMPLOYEE *E= new EMPLOYEE[n];
    for(i=0;i<n;i++)
    {
        E[i].getinput();
    }
    cout<<"Enter salary to compare:"<<endl;
    cin>>enteredsalary;
    compare(E,n,enteredsalary);
    delete[] E;
    return 0;
}