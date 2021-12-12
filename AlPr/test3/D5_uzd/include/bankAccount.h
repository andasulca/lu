#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H


class bankAccount
{
    public:
        bankAccount(double balance, double interest);
        ~bankAccount();
        void addMoney(double money);
        void withdrawMoney(double money);
        void changeIntereset(double newInterest);
        void recalculate();
        void print();

    protected:

    private:
        double balance;
        double intereset;
};

#endif // BANKACCOUNT_H
