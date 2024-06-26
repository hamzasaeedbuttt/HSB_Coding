#include <iostream>

using namespace std;

struct BankAccount{
    public:
    string accountholder;
    double balance;

    BankAccount()
    {
        accountholder = "";
        balance = 0;
    }

    void setter(string name, double num)
    {
        accountholder = name;
        balance = num;
    }

    double getBalance()
    {
        return balance;
    }

    string getName()
    {
        return accountholder;
    }


};

void deposit(BankAccount &b, double money)
{
    b.balance += money;
    cout<<b.balance;
}

void withdraw(BankAccount &b, double money)
{
    if(b.balance>=money)
    {b.balance -= money;
    cout<<b.balance;}
    else{cout<<"Error";}
}


int main()
{
    string name1, name2;
    double balance1, balance2;
    cout<<"Enter name of first account holder: ";
    cin>>name1;
    cout<<"Enter bank balance of first account: ";
    cin>>balance1;
    cout<<"Enter name of second account holder: ";
    cin>>name2;
    cout<<"Enter bank balance of second account: ";
    cin>>balance2;

    BankAccount b1;
    b1.setter(name1, balance1);
    BankAccount b2;
    b2.setter(name2, balance2);

    double x;
    cout<<"Enter the amount of cash you wish to deposit in the first bank account: ";
    cin>>x;
    cout<<"Updated bank balance for account 1 is: ";
    deposit(b1, x);

    cout<<endl;

    double a;
    cout<<"Enter the amount of cash you wish to withdraw from the first bank account: ";
    cin>>a;
    cout<<"Updated bank balance for account 1 is: ";
    withdraw(b1, a);
}