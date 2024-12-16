#include "Account.h"
#define OVERDRAFT 500

class CurrentAccount : public Account{
    public:
    //constructors
    CurrentAccount(std::string accNum, double balance);
    //methods
    void withdraw(double) override;
    void showAccountDetails() override;
    //destructor
    virtual ~CurrentAccount();

    private:
    double overdraftLimit;
};

