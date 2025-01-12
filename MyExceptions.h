#include <iostream>
#pragma once

class MyExceptions {
    public:
    MyExceptions(int tag, std::string msg): tag(tag), msg(msg){}
    //getters
    int getTag(){ 
        return tag; 
    }
    std::string getMsg(){ 
        return msg; 
    }
    private:
    int tag;
    std::string msg;
};


class NegativeBalance : public MyExceptions {
    public:
    NegativeBalance(): MyExceptions(1, "Error: Balance cannot be negative."){}
};

class TransactionLimit : public MyExceptions {
    public:
    TransactionLimit(): MyExceptions(2, "Error: Transaction limit reached."){}
};

class InsufficientFunds : public MyExceptions {
    public:
    InsufficientFunds(): MyExceptions(3, "Error: Insufficient funds."){}
};

class OverdraftLimit : public MyExceptions {
    public:
    OverdraftLimit(): MyExceptions(4, "Error: Overdraft limit exceeded."){}
};

class AccountNotFound : public MyExceptions {
    public:
    AccountNotFound(): MyExceptions(5, "Error: Account not found."){}
};