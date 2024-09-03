#include<iostream>
using namespace std;

class classaccount {
protected:
    int acno;
    float balance;

public:
    virtual void deposit(float amount) {}
    virtual void withdraw(float amount) {}

    void getinput() {
        cin >> acno >> balance;
    }

    void display() {
        cout << "Account Number: " << acno << endl;
        cout << "Balance: " << balance << endl;
    }
};

class savingacc : public classaccount {
public:
    void deposit(float amount) override {
        balance += amount;
        cout << "Amount Deposited in Savings Account: " << amount << endl;
    }

    void withdraw(float amount) override {
        cout << "Withdrawals are not allowed from Savings Account!" << endl;
    }
};

class checkingacc : public classaccount {
public:
    void withdraw(float amount) override {
        if (balance >= amount) {
            balance -= amount;
            cout << "Amount Withdrawn from Checking Account: " << amount << endl;
        } else {
            cout << "Insufficient funds in Checking Account!" << endl;
        }
    }

    void deposit(float amount) override {
        balance += amount;
        cout << "Amount Deposited in Checking Account: " << amount << endl;
    }
};

int main() {
    classaccount* ac;
    savingacc sa;
    checkingacc ca;

    ac = &sa;
    cout << "Enter savings account details (Account Number Balance): ";
    ac->getinput();
    ac->deposit(100);
    ac->display();

    ac = &ca;
    cout << "\nEnter checking account details (Account Number Balance): ";
    ac->getinput();
    ac->withdraw(50);
    ac->display();

    return 0;
}
