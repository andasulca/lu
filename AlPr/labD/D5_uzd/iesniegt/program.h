


class bankAccount
{
    public:
        bankAccount(double balance, double interest);
        ~bankAccount();
        void addMoney(double money);
        void withdrawMoney(double money);
        void changeInterest(double newInterest);
        void recalculate(int days);
        void print();

    protected:

    private:
        double balance;
        double interest;
};

