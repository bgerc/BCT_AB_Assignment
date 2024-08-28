#include<iostream>
using namespace std;

class Account {
protected:
    double account_number, balance = 0;
public:
    Account(double acc = 0) {
        account_number = acc;
    }
    virtual void deposit() = 0;
    virtual void withdraw() = 0;
    void showdata() {
        cout << "Account number: " << account_number << endl
             << "Balance: " << balance << endl;
    }
};

class SavingAccount : public Account {
    int withdrawlimit = 10;
public:
    SavingAccount(double acc = 0) : Account(acc) {}
    
    void deposit() {
        int bal;
        cout << "Enter the amount to deposit: ";
        cin >> bal;
        balance += bal;
    }
    
    void withdraw() {
        int bal;
        cout << "Enter the amount to withdraw: ";
        cin >> bal;
        if (bal <= balance) {
            if (withdrawlimit > 0) {
                balance -= bal;
                withdrawlimit--;
                cout << "Amount successfully withdrawn" << endl;
            } else {
                cout << "You have reached your transaction limit" << endl;
            }
        } else {
            cout << "Insufficient balance" << endl;
        }
    }
};

class CheckingAccount : public Account {
    int withdrawlimit = 1000000;
public:
    CheckingAccount(double acc = 0) : Account(acc) {}
    
    void deposit() {
        int bal;
        cout << "Enter the amount to deposit: ";
        cin >> bal;
        balance += bal;
    }
    
    void withdraw() {
        int bal;
        cout << "Enter the amount to withdraw: ";
        cin >> bal;
        if (bal > withdrawlimit) {
            cout << "You cannot withdraw this amount at once" << endl;
        } else if (bal <= balance) {
            balance -= bal;
            cout << "Amount successfully withdrawn" << endl;
        } else {
            cout << "Insufficient balance" << endl;
        }
    }
};

int main() {
    int ch;
    double acc;
    cout << "Enter the account number: ";
    cin >> acc;

    SavingAccount s(acc);
    CheckingAccount c(acc);
    Account *a[] = { &s, &c };

    while (1) {
        cout << "1. Deposit money in saving account" << endl;
        cout << "2. Withdraw money from saving account" << endl;
        cout << "3. Deposit money in checking account" << endl;
        cout << "4. Withdraw money from checking account" << endl;
        cout << "5. Show saving account details" << endl;
        cout << "6. Show checking account details" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                a[0]->deposit();
                break;
            case 2:
                a[0]->withdraw();
                break;
            case 3:
                a[1]->deposit();
                break;
            case 4:
                a[1]->withdraw();
                break;
            case 5:
                a[0]->showdata();
                break;
            case 6:
                a[1]->showdata();
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
