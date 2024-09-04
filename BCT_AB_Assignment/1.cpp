

// // Create a class person with name and date of birth as data members. Ask the user to
// // enter a date of birth and print all persons name with a matched date of birth.


#include <iostream>
#include <string>
using namespace std;
class person{
    int year,month,day;
    string name;

    public:
    person(){}

    person(int y,int m, int d){
        year=y;
        month=m;
        day=d;
    }
    void input(){
        cout << "Enter the name " << endl;
        cin.ignore();
        getline(cin,name);
        cout << " Enter day (yy-mm-dd)" << endl;
        cin>> year >> month >> day;
    }
    void showdata(){
        cout << " Name is " << name  << endl;
        cout << " The day of birth is  " << endl;
        cout << year << " " << month << " " << day << endl; 
    }
    bool compare(person &p){
        return (year==p.year && month==p.month && day==p.day);
    }
};
int main()
{
    
    person p1[100];
    int n;
    cout << "Enter n " << endl;
    cin >> n;
    for(int i=0; i<n;  i++){

        p1[i].input();
     }

     int y,m,d;
     cout << " Enter the date of birth " << endl;
     cin >> y >> m >> d;
     person p2(y,m,d);

    //  bool found =false;
     for(int i=0; i<n; i++){
        if(p1[i].compare(p2))
        {
            p1[i].showdata();
           
        }
     }
    return 0;
}