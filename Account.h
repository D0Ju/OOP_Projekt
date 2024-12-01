#pragma once
#include <string>
#include <iostream>
class Account{
    public:
    Account();
    Account(std::string, std::string, double); 

    //setter
    void setAccountType(std::string);
    void setAccountNumber(std::string);
    void setBalance(double);
    //getter
    std::string getAccountType();
    std::string getAccountNumber();
    double getBalance();

    //methods
    virtual void showAccountDetails();
    virtual void deposit(double);
    virtual void withdraw(double);


    protected:
    std::string accType;
    std::string accNum;
    double balance;

};