// Create a base class Account with data members account Number and balance.
// Derive two classes SavingsAccount and CheckingAccount from Account. Implement polymorphic
// behavior where the base class pointer can point to objects of derived classes, and call their 
// respective member functions to deposit and withdraw money, applying specific rules for each account type.

#include <iostream>
#include <cstdlib>

#define num_accounts 5

using namespace std;

class account {
protected:
    int accnum;
    float balance;

public:
    account() : balance(0) {
        accnum = rand() % 100;
    }

    virtual void deposit() = 0;
    virtual void withdraw() = 0;

    virtual ~account() {}
};

class savings : public account {
    int limit = 6;
    float fee = 0.01;

public:
    void deposit() {
        float amt;
        cout << "enter deposit amount for account " << accnum << ": ";
        cin >> amt;
        balance += amt;
        cout << "balance: " << balance << endl;
    }

    void withdraw() {
        float amt;
        cout << "enter withdrawal amount from account " << accnum << ": ";
        cin >> amt;

        if (limit > 0) {
            if (balance >= amt) {
                limit--;
                balance -= amt;
                cout << "Available Balance: " << balance << endl;
            } else {
                cout << "insufficient funds." << endl;
            }
        } else {
            char choice;
            cout << "limit reached. 1% fee will apply. continue (y/n)? ";
            cin >> choice;
            if (choice == 'y') {
                balance -= amt * (1 + fee);
                cout << " available balance: " << balance << endl;
            } else {
                cout << "transaction cancelled." << endl;
            }
        }
    }
};

class checking : public account {
    float maxlimit = 100000;

public:
    void deposit() {
        float amt;
        cout << "enter deposit amount for account " << accnum << ": ";
        cin >> amt;
        balance += amt;
        cout << "balance: " << balance << endl;
    }

    void withdraw() {
        float amt;
        cout << "enter withdrawal amount from account " << accnum << ": ";
        cin >> amt;

        if (amt > maxlimit) {
            cout << "max limit: " << maxlimit << endl;
        } else {
            if (balance >= amt) {
                balance -= amt;
                cout << "availeble balance: " << balance << endl;
            } else {
                cout << "insufficient funds." << endl;
            }
        }
    }
};

int main() {
    account* accounts[num_accounts];
    accounts[0] = new savings;
    accounts[1] = new savings;
    accounts[2] = new checking;
    accounts[3] = new checking;
    accounts[4] = new checking;

    for (int i = 0; i < num_accounts; i++) {
        accounts[i]->deposit();
    }

    for (int i = 0; i < num_accounts; i++) {
        accounts[i]->withdraw();
    }

    for (int i = 0; i < num_accounts; i++) {
        delete accounts[i];
    }

    return 0;
}
