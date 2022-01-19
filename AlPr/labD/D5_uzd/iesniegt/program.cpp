#include "program.h"
#include <iostream>
using namespace std;

bankAccount::bankAccount(double balance, double interest)
{
    this->balance = balance;
    this->interest = interest;
}

bankAccount::~bankAccount()
{
    cout<<"Bank account deleted!"<<endl;
}

void bankAccount::addMoney(double money)
{
    if (money > 0)
        this->balance = this->balance + money;
    else
        cout<<"Input value must be larger than 0."<<endl;
}

void bankAccount::withdrawMoney(double money)
{
    if (money > 0 && money <= this->balance)
        this->balance = this->balance - money;
    else if (money < 0)
        cout<<"Input value must be larger than 0."<<endl;
    else
        cout<<"Input value exceeds account balance."<<endl;
}

void bankAccount::changeInterest(double newInterest)
{
    this->interest = newInterest;
}

void bankAccount::recalculate(int days)
{
    double addedValue = (double)this->balance * (days/360.0)*this->interest/100.0;
    if(days>0)
        this->balance = addedValue + this->balance;
    else
        cout<<"Days to recalculate must be more than 0."<<endl;
}

 void bankAccount::print()
{
    cout<<"Account balance: "<<this->balance<<" EUR"<<endl;
}


