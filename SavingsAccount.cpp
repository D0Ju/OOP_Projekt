#include "SavingsAccount.h"

//constructors
SavingsAccount::SavingsAccount(const std::string &accNum, double balance) : Account("Savings", accNum, balance), 
interestRate(INTEREST_RATE), transactionLimit(TRANS_LIMIT){}


//methods -- overriden
void SavingsAccount::deposit(double amount){
    if (transactionCount < transactionLimit) {
        balance += amount;
        transactionCount++;
    } else {
        std::cout << "Transaction limit reached. Cannot deposit.\n";
    }
}

void SavingsAccount::withdraw(double amount){
    if (transactionCount < transactionLimit) {
        if (amount <= balance) {
            balance -= amount;
            transactionCount++;
    }else{
        std::cout << "Insufficient funds.\n";
        }
    }
    else {
        std::cout << "Transaction limit reached. Cannot withdraw.\n";
    }
}

void SavingsAccount::applyInterest(){
    balance += balance * interestRate;
}

void SavingsAccount::showAccountDetails(){
    std::cout << "Savings Account - Number: " << accNum
                << ", Balance: " << balance
                << ", Transactions this month: " << transactionCount
                << ", Type: " << accType << "\n";
}
