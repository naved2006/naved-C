#include <iostream>
#include <cstring>
using namespace std;

class BankAccount{
protected :
    int accountNumber;
    char accountholdername[50];
    double balance;
    
public :
   BankAccount() 
    {
        accountNumber = 0;
        strcpy(accountholdername, "");
        balance = 0;
    }

    BankAccount(int acc, const char name[], double bal)
    {
        accountNumber = acc;
        strcpy(accountholdername, "name");
        balance = bal;
    }

    void deposit(double amount)
    {
       balance += amount;
       cout<<"Amount Deposited Succesfully\n";
    }

    virtual void withdraw(double amount)
        {
            if(amount <= balance)
            {
                balance -= amount;
                cout<<"Succesfully Withdrawn\n";
            }
        
            else
            {
                cout<<"Insufficient Balance]\n";
            }
        }    

        double getBalance() 
        {
            return balance;
        }

    virtual void displayAccountInfo()
        {
            cout<<"Account Number : "<<accountNumber<<endl;
            cout<<"Account Holder : "<<accountholdername<<endl;
            cout<<"Balance : "<<balance<<endl;
        }    

    virtual void CalculateInterest()
        {
            cout<<"No Interest for this account type\n";
            }

    virtual ~BankAccount(){
    }
};

class SavingsAccount : public BankAccount
{
    private:
        double interestRate;

    public:

        SavingsAccount(){
    }

    SavingsAccount(int acc, const char name[], double bal, double rate)
        : BankAccount(acc,name,bal){
            interestRate = rate;
        }

    void CalculateInterest()
    {
        double interest = balance * interestRate / 100;
        cout<<"Interest : "<<interest<<endl;
    }    
     
}; 

class CurrentAccount : public BankAccount
{
    private:
        double overdraftLimit;

    public:
 
        CurrentAccount(){
    }

   CurrentAccount(int acc, const char name[], double bal, double rate)
        : BankAccount(acc,name,bal){
           overdraftLimit = rate;
        }

    void withdraw(double amount)
    {
       if(balance + overdraftLimit >= amount)
       {
            balance -= amount;
            cout<<"Succesfully Withdrawn\n";
       }
       else
       {
            cout<<"Overdraft Limit Exceeded\n";
       }
    } 
}; 


class FixedDepositAccount : public BankAccount
{
    private:
        int term;

    public:

       FixedDepositAccount(){
    }

    FixedDepositAccount(int acc, const char name[], double bal, int t)
        : BankAccount(acc,name,bal){
            term = t;
        }

    void CalculateInterest()
    {
        double interest = balance *0.06 *term / 12;
        cout<<"FixedDepositAccount : "<<interest<<endl;
    }    
     
}; 


int main()
{
   BankAccount * account;
   SavingsAccount s;
   CurrentAccount c;
   FixedDepositAccount fd;

   int choice;
   double amount;

    do{
        cout << "--- Banking System Info ---" << endl;
        cout << "1.  SavingsAccount"<< endl;
        cout << "2.  CurrentAccount" << endl;
        cout << "3.  FixedDepositAccount" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        
        switch (choice) 
        {
        case 1:
            s = SavingsAccount(010,"Mohammad",3500,2);
           account = &s;

           account ->displayAccountInfo();

            cout<<"Enter deposit amount: ";
            cin>>amount;
            account ->deposit(amount);

           account ->CalculateInterest();
           break;

        case 2:
             c = CurrentAccount(010,"Naved",200000,1000);
           account = &c;

           account ->displayAccountInfo();
            
            cout<<"Enter withdraw amount: ";
            cin>>amount;
            account ->withdraw(amount);

           account ->CalculateInterest();
           break;


        case 3:
            fd = FixedDepositAccount(010,"Ahmed",50000,36);
           account = &fd;

           account ->displayAccountInfo();

           account ->CalculateInterest();
           break;

        case 0:
            cout << "Exit" << endl;
            break;

        default:
            cout << "Incorrect Choice" << endl;
        }

    } 
    while (choice != 0);

    return 0;

}