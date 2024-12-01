#include "CurrentAccount.h"

CurrentAccount::CurrentAccount(std::string accNum, double balance) : Account("Current", accNum, balance), overdraftLimit(OVERDRAFT){}

void CurrentAccount::withdraw(double amount){
    if (balance - amount >= -overdraftLimit) {
        balance -= amount;
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
