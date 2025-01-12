#include "Account.h"
#define INTEREST_RATE 0.05
#define TRANS_LIMIT 5
class SavingsAccount : public Account{
    public:
    //konstruktori
    SavingsAccount(const std::string& accNum, double balance);

    
    //metode
    void deposit(double) override;
    void withdraw(double) override;
    void applyInterest();
    void showAccountDetails() override;
    //destructor
    virtual ~SavingsAccount();

    private:
    double interestRate;
    int balanceWithInterest;
    int months = 6;
    int transactionCount = 0;
    int transactionLimit;
};