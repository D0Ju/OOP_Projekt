#include "Account.h"
#include "SavingsAccount.h"
#include "CurrentAccount.h"
#include <vector>

//centralna klasa upravlja accountovima, userima, operacijama
class Bank{
    public:
    //konstruktor
    Bank();
    Bank(Account*);

    //metode
    void createAccount(const std::string&, const std::string&, double);
    void depositMoney(const std::string& accountNumber, double amount);
    void withdrawMoney(const std::string& accountNumber, double amount);
    void displayAccountDetails(const std::string& accountNumber);
    void displayAccounts();
    //destruktor
    ~Bank();
    
    private:
    std::vector<Account*> accounts;
    char name[50];
    std::string lastName;

};