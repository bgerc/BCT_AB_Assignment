#include<iostream>
using namespace std;
class employee
{
int id ,salary;
char name[10];
public:
void getdata()
{
    cout<<"Enter the id and name";
    cin>>id>>name;
    cout<<"Enter the salary";
    cin>>salary;
}
void showdata()
{
    cout<<"Name: "<<name<<endl
        <<"Id: "<<id<<endl
        <<"Salary: "<<salary<<endl;
}
bool operator>(int sal)
{
return salary>sal;
}
};
int main()
{
int n;
cout<<"Enter the number of data";
cin>>n;
employee e[n];
for(int i=0;i<n;i++)
{
    e[i].getdata();
}
int sal;
cout<<"Enter the salary you want to display the data of user"<<endl;
cin>>sal;
for(int i=0;i<n;i++)
{
    if(e[i]>sal)
    {
        e[i].showdata();
    }
}
}