#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

class ACCOUNT
{
protected:
    int accountno;
    float balance;
public:
    void account()
    {
        accountno=rand();
        cout<<"account no :"<<accountno<<endl;
    }
    virtual void deposit(){}
    virtual void withdraw(){}
    float getBalance() 
    {
        cout<<"enter your total balance :"<<endl;
        cin>>balance;
        return balance; 
    }
};

class SAVINGACCOUNT:public ACCOUNT
{
    float balance1,balance0,balance11,balance00;
public:
    void deposit()
    {
        balance0=ACCOUNT::getBalance();
        cout<<"The total balance is :"<<endl;
        cout<<balance0<<endl;
        cout << "Enter the amount to deposit to account  :" <<endl;
        cin>>balance1;
        balance11=balance0+balance1;
        cout<<"your total balance is:"<<endl;
        cout<<"Rs:"<<balance11<<endl;
    }
    void withdraw() 
    {
        cout<<"Enter the balance  to withdraw: "<<endl;
        cin>>balance00;
        if(balance00 <=balance11)
        {
            balance11=balance11-balance00;
            cout<<"Remaining money in your account is "<<endl;
            cout<<balance11<<endl;
        }
    }
};

class CHECKINGACCOUNT:public ACCOUNT
{
    float balance2,balance3,rebalance;
    char a[3];
public:
    void withdraw()
    {
        balance3=ACCOUNT::getBalance();
        cout<<"The total balance is :"<<balance3<<endl;
        cout<<"Enter the balance  to withdraw: "<<endl;
        cin>>balance2;
        if(balance2 <=balance3)
        {
            balance3=balance3-balance2;
            cout<<"Remaining money in your account is "<<endl;
            cout<<balance3<<endl;
            cout<<"Enter y for withdraw money:"<<endl;
            cin>>a;
            if(a[0]=='y')
            {
               
            }
            else
            {
                cout<<"Transaction cancelled!"<<endl;
            }
        }
        else
        {
            cout<<"Insufficient balance."<<endl;
        }
    }
};

int main()
{
    int heee;
    char b[2];
    ACCOUNT *ptr;
    ACCOUNT a;
    ptr=&a;
    ptr->account();
    SAVINGACCOUNT s1;
    CHECKINGACCOUNT c;
    cout<<"Enter a no to  :"<<endl;
    cout<<"Enter 1 for deposit money:"<<endl;
    cout<<"Enter 2 for withdraw money:"<<endl;
    cout<<"Enter 3 for exit:"<<endl;
    cin>>heee;
    while(true)
    {
        switch(heee)
        {
            case 1:
            ptr= &s1;
            ptr->deposit();
            cout<<"Do you also want to withdraw money:"<<endl;
            cin>>b;
            if(b[0]=='y')
            {
                ptr->withdraw();
            }
            break;
            case 2:
            ptr=&c;
            ptr->withdraw();
            break;
            case 3:
            exit(0);
        }
        cout<<"Enter a no to  :"<<endl;
        cout<<"Enter 1 for deposit money:"<<endl;
        cout<<"Enter 2 for withdraw money:"<<endl;
        cout<<"Enter 3 to exit:"<<endl;
        cin>>heee;
    }
    return 0;
}