#include "bankAccount.h"

bankAccount::bankAccount(double balance, double interest)
{
    this->balance = balance;
    this->interest = interest;
}

bankAccount::~bankAccount()
{
    cout<<"Bank account deleted!"<<endl;
}

bankAccount::addMoney(double money)
{
    if (money > 0)
        this->balance = this->balance + money;
    else
        cout<<"Input value must be larger than 0."<<endl;
}

bankAccount::withdrawMoney(double money)
{
    if (money > 0 && money <= this->balance)
        this->balance = this->balance - money;
    else if (money < 0)
        cout<<"Input value must be larger than 0."<<endl;
    else
        cout<<"Input value exceeds account balance."<<endl;
}

bankAccount::changeIntereset(double newInterest)
{
    this->interest = newInterest;
}

bankAccount::recalculate(int days)
{
    if(days>0)
        this->balance = this->balance * (days/360)*this->interest + this->balance;
    else
        cout<<"Days to recalculate must be more than 0."<<endl;
}

bankAccount::print()
{
    cout<<"Account balance: "<<this->balance<<" EUR"<<endl;
}


