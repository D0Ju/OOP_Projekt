#include "SavingsAccount.h"

//constructors
SavingsAccount::SavingsAccount(const std::string &accNum, double balance) : Account("Savings", accNum, balance), 
interestRate(INTEREST_RATE), transactionLimit(TRANS_LIMIT){}


//methods -- overriden
void SavingsAccount::deposit(double amount){
    if (transactionCount < transactionLimit) {
        balance += amount;
        std::cout << "New account balance: "<< balance << std::endl; 
        transactionCount++;
    } else {
        std::cout << "Transaction limit reached. Cannot deposit.\n";
    }
}

void SavingsAccount::withdraw(double amount){
    if (transactionCount < transactionLimit) {
        if (amount <= balance) {
            balance -= amount;
            //dodano ovdje prije bilo u bank.cpp, i ako je bio exceedan broj pokazala bi se poruka da su novci povuceni
            std::cout << "Withdrew " << amount << " from account " << accNum << std::endl;
            std::cout << "New account balance: "<< balance << std::endl; 
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

SavingsAccount::~SavingsAccount(){}
