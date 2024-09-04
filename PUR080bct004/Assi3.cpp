/*calculate class library with booktitle,author and no of copies as 
data members. implement method to add books ,issue book and return books.
Ensure that the no of copies is appropriate updated for each operation. */
#include<iostream>
using namespace std;
class LIBRARY
{
    char booktitles[100],author[30];
    int noofcopies=0;
    public:
    void books()
    {
        cout<<"Enter title of books:"<<endl;
        cin>>booktitles;
        cout<<"Enter author name :"<<endl;
        cin>>author;
        cout<<"Enter no of copies :"<<endl;
        cin>>noofcopies;
    }
    void addbooks()
    {
        int n;
        cout << "Enter the number of books to add : ";
        cin >> n;
        noofcopies++;
        cout<<"Books are added successfully."<<endl;
    }
    void issuebook()
    {
        if(noofcopies==0)
        {
            cout<<"Your Preferred book is out of stock. "<<endl;
            cout<<"sorry to say that!"<<endl;
        }
        else
        {
            cout<<"Congrats book is issued . please don't write anything in book."<<endl;
            noofcopies--;
        }
    }
    void returnbook()
    {
        noofcopies++;
        cout<<"Book is successfully returned."<<endl;
        cout<<"THANKYOU VISIT AGAIN !"<<endl;
    }
};
int main()
{
    int heee;
    LIBRARY l;
    cout<<"WELCOME TO VIRTUAL WORLD LIBRARY."<<endl;
    l.books();
    cout<<"Enter what you want to do:"<<endl;
    cout<<"Enter 1 for addbook:"<<endl;
    cout<<"Enter 2 for issuebook:"<<endl;
    cout<<"Enter 3 for returnbook:"<<endl;
    cout<<"Enter 4 for exit:"<<endl;
    cin>>heee;
    while(heee != 4)
    {
    switch(heee)
    {
            case 1:
                l.addbooks();
                break;
            case 2:
                l.issuebook();
                break;
            case 3:
                l.returnbook();
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid Choice...";
                cout << "Enter what you want to do:" << endl;
    }
        cout << "Enter 1 for add book:" << endl;
        cout << "Enter 2 for issue book:" << endl;
        cout << "Enter 3 for add and issue book:" << endl;
        cout << "Enter 4 for return book:" << endl;
        cout << "Enter 5 for exit:" << endl;
        cin >> heee;
    }
    cout<<"THANKYOU FOR VISITING US. PLEASE VISIT AGAIN.";
    return 0;
}
