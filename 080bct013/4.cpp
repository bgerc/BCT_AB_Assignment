#include<iostream>
#include<cstdlib>

#define no_of_accounts 5

using namespace std;

class Account{
    protected:
        int accountNumber;
        float balance;

    public:
        Account(){
            accountNumber = rand();
        }

        virtual void depositMoney() = 0;
        virtual void withdrawMoney() = 0;

        virtual ~Account(){}
};

class SavingsAccount : public Account{
    int withdrawalLimit = 6;
    float penalty = 0.01;
    public:
        void depositMoney() override{
            float amount;
            cout << "Enter the amount to deposit to account number " << accountNumber << ": ";
            cin >> amount;
            balance += amount;
        }

        void withdrawMoney() override{
            float amount;
            cout << "Enter the amount to withdraw from account number " << accountNumber << ": " ;
            cin >> amount;
            if (withdrawalLimit > 0){
                if(balance > amount){
                    withdrawalLimit--;
                    balance -= amount;
                } else {
                    cout << "Insufficient Balance" << endl;
                }
            } else {
                char ch;
                cout << "You have reached your withdrawal limit. If you still wish to continue, 1%% penalty will be charged from you account. Do you wish to continue(y/n): ";
                if(ch == 'y'){
                    balance -= amount * (1 + penalty);
                } else {
                    cout << "Transaction cancelled!";
                }
            }
        }
        
};

class CheckingAccount : public Account{
    float withdrawalLimit = 100000;
    public:
        void depositMoney() override{
            float amount;
            cout << "Enter the amount to deposit from account number " << accountNumber << ": ";
            cin >> amount;
            balance += amount;
        }
        void withdrawMoney() override{
            float amount;
            cout << "Enter the amount to withdraw from account number " << accountNumber << ": ";
            cin >> amount;
            if(amount > withdrawalLimit){
                cout << "Sorry you cannot withdraw more than " << withdrawalLimit << " at once." << endl;
            } else {
                if(balance < amount){
                    cout << "Insufficient Balance" << endl;
                } else {
                    balance -= amount;
                }
            }
        }
};

int main(){
    Account *aPtr[no_of_accounts];
    aPtr[0] = new SavingsAccount;
    aPtr[1] = new SavingsAccount;
    aPtr[2] = new CheckingAccount;
    aPtr[3] = new CheckingAccount;
    aPtr[4] = new CheckingAccount;

    for(int i=0; i<no_of_accounts; i++)
        aPtr[i]->depositMoney();

    for(int i=0; i<no_of_accounts; i++)
        aPtr[i]->withdrawMoney();

    for(int i=0; i<no_of_accounts; i++)
        delete aPtr[i];
}