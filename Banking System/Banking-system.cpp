#include <iostream>
#include <cstring>
using namespace std;



class BankAccount
{

protected:

    int accountNumber;
    char accountHolderName[50];

private:

    double balance;

public:

    BankAccount()
    {
        accountNumber = 0;
        strcpy(accountHolderName,"");
        balance = 0;
    }

    BankAccount(int num , const char name[] , double bal)
    {
        accountNumber = num;
        strcpy(accountHolderName,name);
        balance = bal;
    }

    void deposit(double amount)
    {
        balance = balance + amount;
        cout<<"Amount deposited\n";
    }

    virtual void withdraw(double amount)
    {
        if(amount <= balance)
        {
            balance = balance - amount;
            cout<<"Amount withdrawn\n";
        }
        else
        {
            cout<<"Insufficient balance\n";
        }
    }

    double getBalance()
    {
        return balance;
    }

    void setBalance(double b)
    {
        balance = b;
    }

    virtual void calculateInterest()
    {
        cout<<"No interest calculation\n";
    }

    void displayAccountInfo()
    {
        cout<<"Account Number: "<<accountNumber<<endl;
        cout<<"Holder Name: "<<accountHolderName<<endl;
        cout<<"Balance: "<<balance<<endl;
    }

};





class SavingsAccount : public BankAccount
{

    double interestRate;

public:

    SavingsAccount()
    {
        interestRate = 0;
    }

    void input()
    {
        cout<<"Enter account number: ";
        cin>>accountNumber;

        cin.ignore();

        cout<<"Enter holder name: ";
        cin.getline(accountHolderName,50);

        double b;

        cout<<"Enter balance: ";
        cin>>b;

        setBalance(b);

        cout<<"Enter interest rate: ";
        cin>>interestRate;
    }

    void calculateInterest()
    {
        double interest;

        interest = getBalance() * interestRate / 100;

        cout<<"Savings Interest: "<<interest<<endl;
    }

};






class CheckingAccount : public BankAccount
{

    double overdraftLimit;

public:

    CheckingAccount()
    {
        overdraftLimit = 0;
    }

    void input()
    {
        cout<<"Enter account number: ";
        cin>>accountNumber;

        cin.ignore();

        cout<<"Enter holder name: ";
        cin.getline(accountHolderName,50);

        double b;

        cout<<"Enter balance: ";
        cin>>b;

        setBalance(b);

        cout<<"Enter overdraft limit: ";
        cin>>overdraftLimit;
    }

    void withdraw(double amount)
    {
        if(amount <= getBalance() + overdraftLimit)
        {
            double newBal;

            newBal = getBalance() - amount;

            setBalance(newBal);

            cout<<"Withdrawal successful\n";
        }
        else
        {
            cout<<"Overdraft limit exceeded\n";
        }
    }

};






class FixedDepositAccount : public BankAccount
{

    int term;

public:

    FixedDepositAccount()
    {
        term = 0;
    }

    void input()
    {
        cout<<"Enter account number: ";
        cin>>accountNumber;

        cin.ignore();

        cout<<"Enter holder name: ";
        cin.getline(accountHolderName,50);

        double b;

        cout<<"Enter deposit amount: ";
        cin>>b;

        setBalance(b);

        cout<<"Enter term in months: ";
        cin>>term;
    }

    void calculateInterest()
    {
        double rate = 6;

        double interest;

        interest = getBalance() * rate * term / 1200;

        cout<<"Fixed Deposit Interest: "<<interest<<endl;
    }

};







int main()
{

    SavingsAccount s;
    CheckingAccount c;
    FixedDepositAccount f;

    BankAccount *ptr;

    int choice;

    do
    {

        cout<<"\n------ Bank Menu ------\n";
        cout<<"1 Create Savings Account\n";
        cout<<"2 Create Checking Account\n";
        cout<<"3 Create Fixed Deposit Account\n";
        cout<<"4 Deposit\n";
        cout<<"5 Withdraw\n";
        cout<<"6 Calculate Interest\n";
        cout<<"7 Display Account\n";
        cout<<"8 Exit\n";

        cout<<"Enter choice: ";
        cin>>choice;



        if(choice == 1)
        {
          
          
            s.input();
            ptr = &s;
        }

        else if(choice == 2)
        {


            c.input();
            ptr = &c;
        }

        else if(choice == 3)
        {

            
            f.input();

            ptr = &f;



        }

        else if(choice == 4)
        {

            double amt;



            cout<<"Enter amount: ";


            cin>>amt;

            ptr->deposit(amt);
        }

        else if(choice == 5)
        {
            double amt;

            cout<<"Enter amount: ";

            cin>>amt;

            ptr->withdraw(amt);
        }


        else if(choice == 6)
        {


            ptr->calculateInterest();
        }




        else if(choice == 7)

        {


            ptr->displayAccountInfo();
        }




    }


    while(choice != 8);





    return 0;
}