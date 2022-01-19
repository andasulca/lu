#include <iostream>
#include <program.h>

using namespace std;

int main()
{
    int action;
    double balance, interest;
    cout << "Enter starting balance" << endl;
    cin >> balance;
    cout << "Enter starting interest rate" << endl;
    cin >> interest;
    bankAccount BankAccount(balance, interest);



    repeatBankActions:
    cout << "Enter action. 0 - exit. 1 - Add money. 2 - Withdraw money. 3 - Change interest. 4 - Recalculate. 5 - print account info." << endl;
    cin >> action;
    if (action == 1) {
        double money;
        cout << "Enter money amount:";
        cin >> money;
        BankAccount.addMoney(money);
        BankAccount.print();
        goto repeatBankActions;
    }
    else if (action == 2) {
        double money;
        cout << "Enter money amount:";
        cin >> money;
        BankAccount.withdrawMoney(money);
        BankAccount.print();
        goto repeatBankActions;
    }
    else if (action == 3) {
        double interest;
        cout << "Enter new interest rate:";
        cin >> interest;
        BankAccount.changeInterest(interest);
        BankAccount.print();
        goto repeatBankActions;
    }
    else if (action == 4) {
        int days;
        cout << "Enter days:";
        cin >> days;
        BankAccount.recalculate(days);
        BankAccount.print();
        goto repeatBankActions;
    }
    else if (action == 5) {
        BankAccount.print();
        goto repeatBankActions;
    }
    else if (action == 0) {
        return 0;
    }
    else {
        goto repeatBankActions;
    }


    return 0;
}
