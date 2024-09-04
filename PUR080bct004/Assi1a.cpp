#include<iostream>
using namespace std;

class Person 
{
    private:
        char name[30];
        int year, month, day;
    public:
        void getinfo()
        {
            cout << "Enter Name of person:" << endl;
            cin >> name;
            cout << "Enter date of birth in year , month and day:" << endl;
            cin >> year >> month >> day;
        }
        void display()
        {
            cout << "Name is :" << name << endl;
            cout << "Date of Birth:" << endl;
            cout << year << ":yy " << month << ":mm " << day << ":day" << endl;
        }
        friend void relate(Person* , int n, int targetyear, int targetmonth, int targetday);
};

void relate(Person* p, int n, int targetyear, int targetmonth, int targetday)
{
    for(int i = 0; i < n; i++)
    {
        if (p[i].year == targetyear && p[i].month == targetmonth && p[i].day == targetday)
        {
            p[i].display();
        }
    }
}

int main()
{
    int n, i, targetyear, targetmonth, targetday;
    cout << "Enter the number of people: " << endl;
    cin >> n;
    Person *p = new Person[n];
    for(i = 0; i < n; i++)
    {
        p[i].getinfo();
    }
    cout << "Enter date of birth in year , month and day to relate: " << endl;
    cin >> targetyear >> targetmonth >> targetday;
    relate(p, n, targetyear, targetmonth, targetday);
    delete[] p;
    return 0;
}
