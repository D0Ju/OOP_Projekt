#include <iostream>
#include "Bank.h"
#include <unistd.h>

int main() {
  Bank bank;
  //Saving Accounts
  bank.createAccount("Savings", "S001", 100);
  bank.createAccount("Savings", "S002", 200);
  bank.createAccount("Savings", "S003", 300);
  bank.createAccount("Savings", "S004", 400);
  bank.createAccount("Savings", "S005", 500);
  bank.createAccount("Savings", "S006", 600);
  //Current Accounts
  bank.createAccount("Current", "C001", 100);
  bank.createAccount("Current", "C002", 200);
  bank.createAccount("Current", "C003", 300);
  bank.createAccount("Current", "C004", 400);
  bank.createAccount("Current", "C005", 500);
  bank.createAccount("Current", "C006", 600);
  system("cls");
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
        sleep(2);
        system("cls");
    }
  } while (choice != 6);
}
