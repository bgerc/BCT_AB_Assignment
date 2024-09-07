#include <iostream>
#include <string>

using namespace std;

class person {
private:
    string name;
    int DOB;
public:
    void input() {
        cout << "Enter the name and date of birth (YYYYMMDD): ";
        cin >> name >> DOB;
    }

    int getDOB() const {
        return DOB;
    }

    string getName() const {
        return name;
    }
};

int main(int argc, char const *argv[]) {
    int n;
    person p[100];
    cout << "Enter the number of people: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "Enter details for person " << i + 1 << ":\n";
        p[i].input();
    }

    int searchDOB;
    cout << "Enter the date of birth to search (YYYYMMDD): ";
    cin >> searchDOB;

    cout << "People with date of birth " << searchDOB << ":\n";
    for (int i = 0; i < n; ++i) {
        if (p[i].getDOB() == searchDOB) {
            cout << p[i].getName() << endl;
        }
    }

    return 0;
}









/*
#include <iostream>

using namespace std;

class person {
private:
    string name;
    int DOB;
public:
void input(){
    cout << "Enter the name and date of bith";
    cin >> name >> DOB;

}
void inputDOB() {
    cout <<"Enter the DOB";
    cin >> DOB;
    cout << DOB;
}

};

int main(int argc, char const *argv[])
{
    int n
    person p[100];
    cout <<"enter the number of people";
    cin >> n;
    
    return 0;
}
*/