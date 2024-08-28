#include <iostream>
#include <cstring>
using namespace std;
class person
{
    int year, month, day;
    char name[10];

public:
    person(int y = 0, int m = 0, int d = 0)
    {

        year = y;
        month = m;
        day = d;
    }
    void getdata()
    {
        cout << "Enter the name";
        cin >> name;
        cout << "Enter the date of birth";
        cin >> year >> month >> day;
    }
    void showdata()
    {
        cout << endl
             << "Name: " << name << endl
             << "date of birth:" << year << ":" << month << ":" << day;
    }
    bool operator==(person p)
    {
        return (year == p.year && month == p.month && day == p.day);
    
    }
};

int main()
{
    int n;
    cout << "Enter the number of data";
    cin >> n;
    person p[n];
    for (int i = 0; i < n; i++)
    {
        p[i].getdata();
    }
    system("cls");
    cout<<"displaying all the on entering date of birth"<<endl;
    int year, month, day;
    cout << "Enter the date of birth";
    cin >> year >> month >> day;
    person s(year, month, day);
    for (int i = 0; i < n; i++)
    {
        if (p[i] == s)
        {
            p[i].showdata();
        }
    }
    return 0;
}