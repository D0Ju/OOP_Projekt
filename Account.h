#pragma once
#include <string>
#include <iostream>
#include "MyExceptions.h"

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
    virtual void showAccountDetails() = 0;
    virtual void deposit(double);
    virtual void withdraw(double) = 0;

    //destructor
    virtual ~Account();
    protected:
    std::string accType;
    std::string accNum;
    double balance;

};