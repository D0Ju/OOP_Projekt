#include "Bank.h"
#include <cctype>
#include <algorithm>

Bank::Bank(){}

Bank::Bank(Account* ac){
    accounts.push_back(ac);
}

// methods

//std::transform mi neradi na accountType zbog nekog razloga pa sam napravio novi string koji je jednak njemu 
//koristi se za transformiranje stringova u lowercase
void Bank::createAccount(const std::string& accountType, const std::string& accountNumber, double initialBalance){
    std::string data = accountType;
    std::transform(data.begin(), data.end(), data.begin(), [](unsigned char c){ return std::tolower(c); });
    if(data == "savings" || data == "s"){
        try{
            accounts.push_back(new SavingsAccount(accountNumber, initialBalance));
            std::cout << "Savings account created successfully.\n";
        }
        catch(MyExceptions &e){
            std::cout << e.getMsg() << std::endl;
        }
    }
    else if(data == "current" || data == "c"){
        try{
            accounts.push_back(new CurrentAccount(accountNumber, initialBalance));
            std::cout << "Current account created successfully.\n";
        }
        catch(MyExceptions &e)
        {
            std::cout << e.getMsg() << std::endl;
        }
        
    }
    else{
        std::cout << "Invalid account type" << std::endl;
    }
}

void Bank::depositMoney(const std::string &accountNumber, double amount){
    bool accountFound = false;
    for(const auto& account : accounts){
        if(account->getAccountNumber() == accountNumber){
            //mora se postavit na true prvo jer ako se pozove deposit prije postavljanja 
            //na true i unese se negativna vrijednost onda ce se pozvati i AccountNotFound()
            try{
                accountFound = true;
                account->deposit(amount);
            }
            catch (MyExceptions &e){
                std::cout << e.getMsg() << std::endl;
            }
        }
    }
    if(!accountFound){
        throw AccountNotFound();
    }
}

void Bank::withdrawMoney(const std::string &accountNumber, double amount){
    bool accountFound = false;
    for(const auto& account : accounts){
        if(account->getAccountNumber() == accountNumber){
            //mora se postavit na true prvo jer ako se pozove deposit prije postavljanja 
            //na true i unese se negativna vrijednost onda ce se pozvati i AccountNotFound()
            try{
                accountFound = true;
                account->withdraw(amount);
            }
            catch(MyExceptions &e){
                std::cout << e.getMsg() << std::endl;
            }
        }
    }
    if(!accountFound){
        throw AccountNotFound();
    }
} 


void Bank::displayAccountDetails(const std::string &accountNumber){
    bool accountFound = false;
    for(const auto& account : accounts){
        if(account->getAccountNumber() == accountNumber){
            account->showAccountDetails();
            accountFound = true;
            break;
        }
    }
    if(!accountFound){
        throw AccountNotFound();
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