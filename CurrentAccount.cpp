#include "CurrentAccount.h"

CurrentAccount::CurrentAccount(std::string accNum, double balance) : Account("Current", accNum, balance), overdraftLimit(OVERDRAFT){}

void CurrentAccount::withdraw(double amount){
    if (balance - amount >= -overdraftLimit) {
        balance -= amount;
        //dodano ovdje prije bilo u bank.cpp, i ako je bio exceedan broj pokazala bi se poruka da su novci povuceni
        std::cout << "Withdrew " << amount << " from account " << accNum << std::endl;
        std::cout << "New account balance: "<< balance << std::endl; 
    } else {
        std::cout << "Overdraft limit exceeded. Cannot withdraw.\n";
    }
}

void CurrentAccount::showAccountDetails(){
    std::cout << "Current Account - Number: " << accNum
                << ", Balance: " << balance
                << ", Overdraft Limit: " << overdraftLimit
                  << ", Type: " << accType << "\n";
}

CurrentAccount::~CurrentAccount(){}
