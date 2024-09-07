#include <iostream>
#include <string>

using namespace std;

class Account {
protected:
    double balance;

public:
    Account(double initialBalance) : balance(initialBalance) {}

    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << ", New Balance: " << balance << endl;
    }

    virtual void withdraw(double amount) = 0;           // Pure virtual function

    virtual ~Account() {}                               // declaration of a virtual destructor for the Account class
};

class SavingAccount : public Account {
public:
    SavingAccount(double initialBalance) : Account(initialBalance) {}

    void withdraw(double amount) override {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn: " << amount << ", New Balance: " << balance << endl;
        } else {
            cout << "Insufficient balance in Saving Account." << endl;
        }
    }
};

class CheckingAccount : public Account {
private:
    double overdraftLimit;

public:
    CheckingAccount(double initialBalance, double overdraft) : Account(initialBalance), overdraftLimit(overdraft) {}

    void withdraw(double amount) override {
        if (balance + overdraftLimit >= amount) {
            balance -= amount;
            cout << "Withdrawn: " << amount << ", New Balance: " << balance << endl;
        } else {
            cout << "Overdraft limit exceeded in Checking Account." << endl;
        }
    }
};

int main() {
    Account* account1 = new SavingAccount(200.0);
    Account* account2 = new CheckingAccount(500.0, 200.0);

    account1->deposit(200.0);      //200+200=400
    account1->withdraw(150.0);     //400-150=250

    account2->deposit(100.0);      //500+100=600
    account2->withdraw(700.0);     //600-700=-100

    delete account1;
    delete account2;

    return 0;
}
