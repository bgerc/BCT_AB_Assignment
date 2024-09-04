#include<iostream>
using namespace std;
class employee{
    int id;
    char name[40];
    float salary;
    public:
    employee(){};

         void get() {
        cout << " __________________________________input________________________________________" << endl;
        cout << "Enter your Name: " << endl;
        cin >> name;
        cout << "Enter your id:"<<endl;
        cin>>id;
           cout << "Enter your salary:"<<endl;
           cin>>salary;
                   cout << " __________________________________________________________________________" << endl;

        }
         void show() {
        cout << endl;
        cout << " __________________________________________________________________________" << endl;
        cout << " Name: " << name << endl;
                cout << "id:"<<id<<endl;
           cout << "salary:"<<salary<<endl;
                   cout << " __________________________________________________________________________" << endl;
         }
        
         int compare(float s){
            if (salary>=s){
                show();
            }

         }

    };
        int main(){
            int n;
            float s;
            cout<<"Enter the no. of records :"<<endl;
            cin>>n;
            employee e[100];
            for(int i=0;i<n;i++){
                    e[i].get();
            }
            cout<<"Enter the threshold salary for the employee record:"<<endl;
            cin>>s;
         for(int i=0;i<n;i++){
                   e[i].compare( s);
                } 
        }