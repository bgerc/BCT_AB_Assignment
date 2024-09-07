/*
Create a base class Account with data members accountNumber and balance.
Derive two classes SavingsAccount and CheckingAccount from Account.
Implement polymorphic behavior where the base class pointer can point to objects of
derived classes, and call their respective member functions to deposit and withdraw
money, applying specific rules for each account type.
*/

#include <iostream>
using namespace std;

const int maxTransactions = 3;
const double transactionFee = 2.0;
const double creditLimit = 100.0;

class BankAccount {
protected:
    int accountID;
    double currentBalance;

public:
    virtual void inputDetails() = 0;
    virtual void makeDeposit() = 0;
    virtual void makeWithdrawal() = 0;
    virtual void displayDetails() = 0;
    virtual ~BankAccount() {}
};

class SavingsAccount : public BankAccount {
private:
    double minimumRequiredBalance;
    int transactionCount;
    double extraWithdrawalFee;

public:
    SavingsAccount(double minBalance)
        : minimumRequiredBalance(minBalance), transactionCount(0), extraWithdrawalFee(transactionFee) {}

    void inputDetails() {
        cout << "Enter account ID: ";
        cin >> accountID;
        cout << "Enter current balance: ";
        cin >> currentBalance;
    }

    void makeDeposit() {
        double amount;
        cout << "Enter the amount to deposit: ";
        cin >> amount;
        currentBalance += amount;
    }

    void makeWithdrawal() {
        double amount;
        cout << "Enter the amount to withdraw: ";
        cin >> amount;
        if (transactionCount >= maxTransactions) {
            cout << "Transaction limit reached. A fee of " << extraWithdrawalFee << " will be applied." << endl;
            currentBalance -= extraWithdrawalFee;
        }
        if (currentBalance - amount < minimumRequiredBalance) {
            cout << "Insufficient balance. Withdrawal would fall below minimum balance." << endl;
        } else {
            currentBalance -= amount;
            transactionCount++;
            cout << "Withdrawal successful." << endl;
        }
    }

    void displayDetails() {
        cout << "Account ID: " << accountID << endl;
        cout << "Current Balance: " << currentBalance << endl;
        cout << "Transactions This Month: " << transactionCount << endl;
    }
};

class CheckingAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CheckingAccount() : overdraftLimit(creditLimit) {}

    void inputDetails() {
        cout << "Enter account ID: ";
        cin >> accountID;
        cout << "Enter current balance: ";
        cin >> currentBalance;
    }

    void makeDeposit() {
        double amount;
        cout << "Enter the amount to deposit: ";
        cin >> amount;
        currentBalance += amount;
    }

    void makeWithdrawal() {
        double amount;
        cout << "Enter the amount to withdraw: ";
        cin >> amount;
        if (currentBalance - amount < -overdraftLimit) {
            cout << "Insufficient funds. Withdrawal would exceed overdraft limit." << endl;
        } else {
            currentBalance -= amount;
            cout << "Withdrawal successful." << endl;
        }
    }

    void displayDetails() {
        cout << "Account ID: " << accountID << endl;
        cout << "Current Balance: " << currentBalance << endl;
    }
};

int main() {
    BankAccount* account = nullptr;
    int accountType;
    int choice;

    cout << "\nSelect the account type\n1. Savings Account\n2. Checking Account" << endl;
    cin >> accountType;

    switch (accountType) {
    case 1:
        account = new SavingsAccount(100.0);
        break;
    case 2:
        account = new CheckingAccount();
        break;
    default:
        cout << "Invalid Input." << endl;
        return 1;
    }

    account->inputDetails();
    while (true) {
        cout << "\nEnter your choice\n1. Deposit Money\n2. Withdraw Money\n3. View Details\n4. Exit" << endl;
        cin >> choice;
        switch (choice) {
        case 1:
            account->makeDeposit();
            break;
        case 2:
            account->makeWithdrawal();
            break;
        case 3:
            account->displayDetails();
            break;
        case 4:
            delete account;
            return 0;
        default:
            cout << "Invalid Input." << endl;
            break;
        }
    }
}