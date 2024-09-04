/*Create a base class Account with data members accountNumber and balance.
Derive two classes SavingsAccount and CheckingAccount from Account.
Implement polymorphic behavior where the base class pointer can point to objects of
derived classes, and call their respective member functions to deposit and withdraw
money, applying specific rules for each account type.*/

#include <iostream>
#include <cstdlib>

using namespace std;

class Account
{
protected:
    int accountNumber;
    double balance;

public:
    Account(double b) : accountNumber(rand()), balance(b) {}

    virtual void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited: $" << amount << " into Account " << accountNumber << endl;
    }

    virtual void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            cout << "Withdrew: $" << amount << " from Account " << accountNumber << endl;
        }
        else
        {
            cout << "Insufficient balance!" << endl;
        }
    }

    virtual void displayBalance() const
    {
        cout << "Account Number: " << accountNumber << ", Balance: $" << balance << endl;
    }

    virtual ~Account() {}
};

class SavingsAccount : public Account
{
    double interestRate;
    int withdrawalLimit;

public:
    SavingsAccount(double b, double rate, int limit) : Account(b), interestRate(rate), withdrawalLimit(limit) {}

    void deposit(double amount) override
    {
        balance += amount + (amount * interestRate);
        cout << "Deposited: $" << amount << " with interest into Savings Account " << accountNumber << endl;
    }

    void withdraw(double amount) override
    {
        if (withdrawalLimit > 0)
        {
            Account::withdraw(amount);
            withdrawalLimit--;
        }
        else
        {
            cout << "Withdrawal limit reached! Cannot withdraw more this month." << endl;
        }
    }
};

class CheckingAccount : public Account
{
    double overdraftLimit;

public:
    CheckingAccount(double b, double limit) : Account(b), overdraftLimit(limit) {}

    void withdraw(double amount) override
    {
        if (amount <= balance + overdraftLimit)
        {
            balance -= amount;
            cout << "Withdrew: $" << amount << " from Checking Account " << accountNumber << endl;
        }
        else
        {
            cout << "Overdraft limit exceeded!" << endl;
        }
    }
};

int main()
{
    Account *accounts[2];

    accounts[0] = new SavingsAccount(5000.0, 0.02, 3);
    accounts[1] = new CheckingAccount(100.0, 50.0);

    for (int i = 0; i < 2; i++)
    {
        double amount;
        cout << "Enter amount to deposit into Account " << i + 1 << ": $";
        cin >> amount;
        accounts[i]->deposit(amount);

        cout << "Enter amount to withdraw from Account " << i + 1 << ": $";
        cin >> amount;
        accounts[i]->withdraw(amount);

        accounts[i]->displayBalance();
        delete accounts[i];
    }

    return 0;
}