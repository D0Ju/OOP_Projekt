#include <iostream>
#include "Bank.h"

int main() {
  Bank bank;
  //Account ac("Savings", "da", 3);
  //Bank bank2(&ac);
  int choice;

  do {
    std::cout << "\n=== Bank Management System ===\n";
    std::cout << "1. Create Account\n";
    std::cout << "2. Deposit Money\n";
    std::cout << "3. Withdraw Money\n";
    std::cout << "4. Display Account Details\n";
    std::cout << "5. Display All Accounts\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    
    switch (choice) {
    case 1: 
      {
        system("cls");
        std::string accountType, accountNumber;
        double initialBalance;
        std::cout << "Enter account type (Savings/Current): ";
        std::cin >> accountType;
        std::cout << "Enter account number: ";
        std::cin >> accountNumber;
        std::cout << "Enter initial balance: ";
        std::cin >> initialBalance;
        bank.createAccount(accountType, accountNumber, initialBalance);
        break;
      }
    case 2: 
      {
        system("cls");
        std::string accountNumber;
        double amount;
        std::cout << "Enter account number: ";
        std::cin >> accountNumber;
        std::cout << "Enter amount to deposit: ";
        std::cin >> amount;
        bank.depositMoney(accountNumber, amount);
        break;
      }
    case 3: 
      {
        system("cls");
        std::string accountNumber;
        double amount;
        std::cout << "Enter account number: ";
        std::cin >> accountNumber;
        std::cout << "Enter amount to withdraw: ";
        std::cin >> amount;
        bank.withdrawMoney(accountNumber, amount);
        break;
      }
    case 4: 
      {
        system("cls");
        std::string accountNumber;
        std::cout << "Enter account number: ";
        std::cin >> accountNumber;
        bank.displayAccountDetails(accountNumber);
        break;
      }
    case 5:
      { 
        system("cls");
        bank.displayAccounts();
        break;
      }
    case 6:
      { 
        system("cls");
        std::cout << "";
        break;
      }
    default:
        std::cout << "Invalid choice. Please try again.\n";
    }
} while (choice != 6);
}
