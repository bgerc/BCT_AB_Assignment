#include <iostream>
#include<string>
using namespace std;
class Date{
    int day,month,year;
    public:
    void getData(){
        cout << "Enter Date of Birth:" << endl;
        cout << "Year? ";
        cin >> year;
        cout << "Month? ";
        cin >> month;
        cout << "Day? ";
        cin >> day;
    }
    bool operator==(Date obj){
        return obj.day == day && obj.month == month && obj.year == year;
    }
    friend class Person;
};
class Person{
    string name;
    Date date_of_birth;
    public:
    void getData(){
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin,name);
        date_of_birth.getData();
    }
    void getName(){
        cout << "Name: " << name << endl;
    }
    void compareDate(int n,Person p[]);
};
void Person::compareDate(int n, Person p[]){
    bool *matched = new bool[n]();
    bool anymatch = false;
    for(int i=0;i<n;i++){
        if(matched[i]==true){
            continue;
        }
        bool firstmatch = true;
        for(int j=i+1;j<n;j++){
            if(p[i].date_of_birth == p[j].date_of_birth){
                if(firstmatch == true){
                    cout << "Persons With Matched Dates:" << endl;
                    p[i].getName();
                    firstmatch = false;
                    anymatch = true;
                }
                p[j].getName();
                matched[j] = true;
            }
        }
    }
    if(anymatch == false){
        cout << "No Matched Date found";
    }
    delete[] matched;
}
int main(){
    int n;
    cout << "Enter the number of person: ";
    cin >> n;
    Person *p = new Person[n];
    for(int i=0;i<n;i++){
        cout << "Enter "<< i+1 << " Person Detail" << endl;
        p[i].getData();
    }
    p->compareDate(n,p);
    delete[] p;
    return 0;
}
