#include "SavingsAccount.h"

//constructors
SavingsAccount::SavingsAccount(const std::string &accNum, double balance) : Account("Savings", accNum, balance), 
interestRate(INTEREST_RATE), transactionLimit(TRANS_LIMIT){}


//methods -- overriden
void SavingsAccount::deposit(double amount){
    if (amount > 0) {
        if (transactionCount < transactionLimit) {
            balance += amount;
            std::cout << "New account balance: "<< balance << std::endl; 
            transactionCount++;
        } else {
            throw TransactionLimit();
        }
    } else {
        throw NegativeBalance();
    }
}

void SavingsAccount::withdraw(double amount){
    if (amount > 0) {
        if (transactionCount < transactionLimit) {
            if (amount <= balance) {
                balance -= amount;
                //dodano ovdje prije bilo u bank.cpp, i ako je bio exceedan broj pokazala bi se poruka da su novci povuceni
                std::cout << "Withdrew " << amount << " from account " << accNum << std::endl;
                std::cout << "New account balance: "<< balance << std::endl; 
                transactionCount++;
            }else{
                throw InsufficientFunds();
            }
        }
        else {
            throw TransactionLimit();
        }
    }
    else {
        throw NegativeBalance();
    }
}

void SavingsAccount::applyInterest(){
    if (months == 0) {
            throw std::runtime_error("Cannot calculate interest -- 0 months");
        }
    //ovo bi bilo da radim sa vremenom koristit cu neku random varijablu da pokazem ovo.
    //balance += balance * interestRate * months; 
    balanceWithInterest = balance;
    balanceWithInterest += balance * interestRate * months;
}

void SavingsAccount::showAccountDetails(){
    std::cout << "Savings Account - Number: " << accNum
                << ", Balance: " << balance
                << ", Transactions this month: " << transactionCount
                << ", Type: " << accType << "\n";
    try{
        applyInterest();
        std::cout << "Balance in 6 months with interest rate of 5% is " << balanceWithInterest << "\n";
    }
    catch(std::runtime_error &e){
        std::cout << e.what() << std::endl;
    }
}

SavingsAccount::~SavingsAccount(){}
