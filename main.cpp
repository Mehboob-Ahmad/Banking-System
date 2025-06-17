#include "UtilitiesController.h"
#include "UtilitiesView.h"
#include "Utilitiesdatabase.h"
#include "Header.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <algorithm>
#include <sstream>
#include <vector>


using namespace std;

const string ACCOUNTS_FILE = "accounts.txt";
const string UTILITIES_FILE = "utilities.txt";
const string CALCULATOR_FILE = "calculator.txt";
const string ADMIN_FILE = "admin.txt";
const string ATM_FILE = "atm.txt";

bool isValidCNIC(const string& cnic) {
    if (cnic.length() != 13) return false;
    for (char c : cnic) {
        if (c < '0' || c > '9') return false;
    }
    return true;
}


bool isValidUsername(const string& username) {
    if (username.length() < 3 || username.length() > 30) return false;

    for (char c : username) {
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
              (c >= '0' && c <= '9') || c == '_' || c == '.')) {
            return false;
        }
    }
    return true;
}

string getStringInput(const string& prompt) {
    string value;
    cout << prompt << endl;
    getline(cin, value);
    return value;
}

int getValidatedIntInput(const string& prompt, const string& errorMsg) {
    int value;
    while (true) {
        cout << prompt << endl;
        cin >> value;
        if (cin.fail()) {
            cout << errorMsg << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

double getValidatedDoubleInput(const string& prompt, const string& errorMsg) {
    double value;
    while (true) {
        cout << prompt << endl;
        cin >> value;
        if (cin.fail()) {
            cout << errorMsg << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}


int main() {
    srand(static_cast<unsigned int>(time(0)));

    BankSystem bank;
    Utilities utilities;
    Calculator calculator;
    Admin admin;
    ATM atm;

    bank.loadFromFile(ACCOUNTS_FILE);
    utilities.loadFromFile(UTILITIES_FILE);
    calculator.loadFromFile(CALCULATOR_FILE);
    admin.loadFromFile(ADMIN_FILE);
    atm.loadFromFile(ATM_FILE);


    bool running = true;
    while (running) {
        cout << "\n=== Banking System Main Menu ===" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Login to Account" << endl;
        cout << "3. Admin Panel" << endl;
        cout << "0. Exit" << endl;
        int mainChoice = getValidatedIntInput("Enter your choice:", "Invalid input. Please enter a number.");

        if (mainChoice == 0) {
            running = false;
        } else if (mainChoice == 1) {
            cout << "\n--- Create New Account ---" << endl;
            string name = getStringInput("Enter customer name:");
            string cnic;
            while (true) {
                cnic = getStringInput("Enter customer CNIC (13 digits, no dashes):");
                if (isValidCNIC(cnic)) {
                    break;
                } else {
                    cout << "Invalid CNIC. Please enter exactly 13 digits." << endl;
                }
            }
            string type = getStringInput("Enter account type (e.g., Savings, Current):");
            string pin = getStringInput("Set a 4-digit login PIN:");

            Account* newAccount = bank.createAccount(name, cnic, type, pin);
            if (newAccount) {
                cout << "Account created. Logging in..." << endl;
                bool accountSession = true;
                while (accountSession) {
                    AccountsController::showmenu(*newAccount);
                    int accountOpt = getValidatedIntInput("Enter your choice:", "Invalid input. Please enter a number.");
                    if (accountOpt == 0) {
                        accountSession = false;
                    } else {
                        AccountsController::handleUserChoice(accountOpt, *newAccount, bank);
                    }
                }
            }
        } else if (mainChoice == 2) {
            cout << "\n--- Account Login ---" << endl;
            string accNum = getStringInput("Enter account number:");
            string pin = getStringInput("Enter PIN:");

            Account* loggedInAccount = bank.getAccount(accNum);
            if (loggedInAccount) {
                if (bank.authenticateAccount(accNum, pin)) {
                    cout << "Login successful!" << endl;
                    bool accountSession = true;
                    while (accountSession) {
                        AccountsController::showmenu(*loggedInAccount);
                        cout << "4. Utilities" << endl;
                        cout << "5. Calculator" << endl;
                        cout << "6. ATM Services" << endl;
                        cout << "7. Loan Management" << endl;
                        cout << "0. Back to Main Menu" << endl;
                        int accountOpt = getValidatedIntInput("Enter your choice:", "Invalid input. Please enter a number.");

                        if (accountOpt == 0) {
                            accountSession = false;
                        } else if (accountOpt >= 1 && accountOpt <= 3) {
                            AccountsController::handleUserChoice(accountOpt, *loggedInAccount, bank);
                        } else if (accountOpt == 4) {
                            bool utilitiesSession = true;
                            while (utilitiesSession) {
                                UtilitiesController::showmenu(utilities);
                                int utilOpt = getValidatedIntInput("Enter your choice:", "Invalid input. Please enter a number.");
                                if (utilOpt == 0) {
                                    utilitiesSession = false;
                                } else {
                                    UtilitiesController::handleUserChoice(utilOpt, utilities);
                                }
                            }
                        } else if (accountOpt == 5) {
                            bool calculatorSession = true;
                            while (calculatorSession) {
                                CalculatorController::showmenu(calculator);
                                int calcOpt = getValidatedIntInput("Enter your choice:", "Invalid input. Please enter a number.");
                                if (calcOpt == 0) {
                                    calculatorSession = false;
                                } else {
                                    CalculatorController::handleUserChoice(calcOpt, calculator);
                                }
                            }
                        } else if (accountOpt == 6) {
                            bool atmSession = true;
                            while (atmSession) {
                                ATMController::showmenu(atm);
                                int atmOpt = getValidatedIntInput("Enter your choice:", "Invalid input. Please enter a number.");
                                if (atmOpt == 0) {
                                    atmSession = false;
                                } else {
                                    ATMController::handleUserChoice(atmOpt, atm);
                                }
                            }
                        } else if (accountOpt == 7) {
                            bool loanSession = true;
                            while (loanSession) {
                                LoanTracker* currentLoan = bank.getLoanTracker(loggedInAccount->getAccountNumber());
                                LoanController::showMenu(currentLoan);
                                int loanOpt = getValidatedIntInput("Enter your choice:", "Invalid input. Please enter a number.");
                                if (loanOpt == 0) {
                                    loanSession = false;
                                } else {
                                    LoanController::handleUserChoice(loanOpt, *loggedInAccount, bank);
                                }
                            }
                        }
                        else {
                            cout << "Invalid choice. Please try again." << endl;
                        }
                    }
                } else {
                    cout << "Invalid PIN. Login failed." << endl;
                }
            } else {
                cout << "Login failed. Account not found." << endl;
            }
        } else if (mainChoice == 3) {
            string admin_username = getStringInput("Enter admin username:");
            string admin_password = getStringInput("Enter admin password:");

            if (admin_username == admin.getUsername() && admin_password == admin.getPassword()) {
                cout << "Admin login successful!" << endl;
                bool adminSession = true;
                while (adminSession) {
                    AdminController::showmenu(admin);
                    int adminOpt = getValidatedIntInput("Enter your choice:", "Invalid input. Please enter a number.");
                    if (adminOpt == 0) {
                        adminSession = false;
                    } else {
                        AdminController::handleUserChoice(adminOpt, admin, bank);
                    }
                }
            } else {
                cout << "Admin login failed. Invalid credentials." << endl;
            }
        } else {
            cout << "Invalid choice. Please try again." << endl;;
        }
    }

    bank.saveToFile(ACCOUNTS_FILE);
    utilities.saveToFile(UTILITIES_FILE);
    calculator.saveToFile(CALCULATOR_FILE);
    admin.saveToFile(ADMIN_FILE);
    atm.saveToFile(ATM_FILE);

    cout << "Exiting Banking System. Goodbye!" << endl;

    return 0;
}