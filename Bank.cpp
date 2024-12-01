#include "Bank.h"

Bank::Bank(){}

Bank::Bank(Account *){}

// methods
void Bank::createAccount(const std::string& accountType, const std::string& accountNumber, double initialBalance){
    if(accountType == "Savings"){
        accounts.push_back(new SavingsAccount(accountNumber, initialBalance));
    }
    else if(accountType == "Current"){
        accounts.push_back(new CurrentAccount(accountNumber, initialBalance));
    }
    else{
        std::cout << "Invalid account type" << std::endl;
    }
}

void Bank::depositMoney(const std::string &accountNumber, double amount){
    for(const auto& account : accounts){
        if(account->getAccountNumber() == accountNumber){
            account->deposit(amount);
        }
    }
}

void Bank::withdrawMoney(const std::string &accountNumber, double amount){
    for(const auto& account : accounts){
        if(account->getAccountNumber() == accountNumber){
            account->withdraw(amount);
            std::cout << "Withdrew " << amount << " from account " << accountNumber << std::endl;
        }
    }
} 


void Bank::displayAccountDetails(const std::string &accountNumber){
    for(const auto& account : accounts){
        if(account->getAccountNumber() == accountNumber){
            account->showAccountDetails();
        }
        else{
            std::cout << "Account not found." << std::endl;
        }
    }
}

void Bank::displayAccounts(){ 
    if (accounts.empty()) {
        std::cout << "No accounts available in the bank.\n";
        return;
    }
    for(const auto& account : accounts){
        account->showAccountDetails();
        std::cout<<std::endl;
    }
}

Bank::~Bank() {
    for (auto* acc : accounts) {
        delete acc;
    }
    accounts.clear(); 
}