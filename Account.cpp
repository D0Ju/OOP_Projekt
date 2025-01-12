#include "Account.h"
#include "MyExceptions.h"

Account::Account(){}

Account::Account(std::string accType, std::string accNum, double balance){
    setAccountType(accType);
    setAccountNumber(accNum);
    setBalance(balance);
}

// setters
void Account::setAccountType(std::string accType){
    /* nema potrebe provjeravati jeli savings ili current zato sto to provjeravamao u Bank.cpp u createAccount
    if(accType == "Savings" || accType =="Current"){  
        this->accType = accType;
        std::cout << accType << " account created successfully.\n";
    }
    */
    this->accType = accType;
}
void Account::setAccountNumber(std::string accNum){
    this->accNum = accNum;
}

void Account::setBalance(double balance){
    if(balance < 0){
        throw NegativeBalance();
    }
    else this->balance = balance;
}

//getters
std::string Account::getAccountType(){
    return accType;
}

std::string Account::getAccountNumber(){
    return accNum;
}

double Account::getBalance(){
    return balance;
}

//methods
void Account::showAccountDetails(){ 
    std::cout << "Account Details: \n" << "Type: " << accType << "\nAccount Number: " << accNum << "\nBalance: " << balance << std::endl;
}

void Account::deposit(double amount){
    if(amount > 0){
        balance += amount;
        std::cout << "New account balance: "<< balance << std::endl; 
    }else{
        throw NegativeBalance();
    }
}

void Account::withdraw(double amount){
    if (amount <= balance) {
        balance -= amount;
        showAccountDetails();
    }else {
        throw InsufficientFunds();
        showAccountDetails();
    }
}

Account::~Account(){}
