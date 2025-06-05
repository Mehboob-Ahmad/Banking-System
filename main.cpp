#include "UtilitiesController.h"
#include "UtilitiesView.h"
#include "Utilitiesdatabase.h"
#include "Header.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <map>
#include <limits>
#include <sstream>

using namespace std;

string getStringInput(const string& prompt) {
    string value;
    cout << prompt << endl;
    getline(cin, value);
    return value;
}

int getValidatedIntInput(const string& prompt, const string& errorMessage) {
    int value;
    string inputLine;
    while (true) {
        cout << prompt << endl;
        getline(cin, inputLine);
        stringstream ss(inputLine);
        if (ss >> value && ss.eof()) {
            return value;
        } else {
            cout << errorMessage << endl;
        }
    }
}

double getValidatedDoubleInput(const string& prompt, const string& errorMessage) {
    double value;
    string inputLine;
    while (true) {
        cout << prompt << endl;
        getline(cin, inputLine);
        stringstream ss(inputLine);
        if (ss >> value && ss.eof()) {
            return value;
        } else {
            cout << errorMessage << endl;
        }
    }
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    const string ACCOUNTS_FILE   = "accounts.txt";
    const string UTILITIES_FILE  = "utilities.txt";
    const string CALCULATOR_FILE = "calculator.txt";
    const string ADMIN_FILE      = "admin.txt";
    const string ATM_FILE        = "atm.txt";

    cout << "--- Data Files ---" << endl;
    cout << "Accounts Data:   " << ACCOUNTS_FILE << endl;
    cout << "Utilities Data:  " << UTILITIES_FILE << endl;
    cout << "Calculator Data: " << CALCULATOR_FILE << endl;
    cout << "Admin Data:      " << ADMIN_FILE << endl;
    cout << "ATM Data:        " << ATM_FILE << endl;
    cout << "------------------" << endl << endl;

    BankSystem bank;
    Utilities utilities;
    Calculator calculator;
    Admin admin("admin", "admin123");
    ATM atm;

    bank.loadAccountsFromFile(ACCOUNTS_FILE);
    utilities.loadFromFile(UTILITIES_FILE);
    calculator.loadFromFile(CALCULATOR_FILE);
    admin.loadFromFile(ADMIN_FILE);
    atm.loadFromFile(ATM_FILE);

    bool running = true;
    while (running) {
        cout << endl << "===== Banking System Main Menu =====" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Login to Account" << endl;
        cout << "3. View All Customer Accounts (Admin Only)" << endl;
        cout << "4. Freeze Account (Admin Only)" << endl;
        cout << "5. Unfreeze Account (Admin Only)" << endl;
        cout << "6. Admin Panel" << endl;
        cout << "0. Exit" << endl;

        int mainChoice = getValidatedIntInput("Enter your choice:", "Invalid input. Please enter a number.");

        if (mainChoice == 0) {
            running = false;
        }
        else if (mainChoice == 1) {
            bank.createAccount();
        }
        else if (mainChoice == 2) {
            string accNum = getStringInput("Enter account number:");
            string pwd    = getStringInput("Enter password:");

            Account* loggedInAccount = bank.login(accNum, pwd);
            if (loggedInAccount) {
                cout << "Login successful!" << endl;
                bool userSession = true;
                while (userSession) {
                    cout << endl << "===== Welcome, User of Account "
                         << loggedInAccount->getAccountNumber() << " =====" << endl;
                    cout << "===== User Services Menu =====" << endl;
                    cout << "1. Pay Utilities" << endl;
                    cout << "2. Use Calculator" << endl;
                    cout << "3. ATM Services" << endl;
                    cout << "4. Spin the Wheel" << endl;
                    cout << "5. Check Account Details" << endl;
                    cout << "6. Deposit Money" << endl;
                    cout << "7. Withdraw Money" << endl;
                    cout << "0. Logout" << endl;

                    int userChoice = getValidatedIntInput("Enter your choice:", "Invalid input. Please enter a number.");

                    if (userChoice == 0) {
                        userSession = false;
                        cout << "Logged out successfully." << endl;
                    }
                    else if (loggedInAccount->getIsFrozen() && !(userChoice == 5 || userChoice == 0)) {
                        cout << "Your account is frozen. You cannot perform transactions." << endl;
                    }
                    else if (userChoice == 1) {
                        UtilitiesController::showmenu(utilities);
                        int utilChoice = getValidatedIntInput("Enter your choice:", "Invalid input. Please enter a number.");
                        UtilitiesController::handleUserChoice(utilChoice, utilities);
                        utilities.saveToFile(UTILITIES_FILE);
                    }
                    else if (userChoice == 2) {
                        bool calcSession = true;
                        while (calcSession) {
                            cout << endl << "===== Calculator Menu =====" << endl;
                            cout << "1. Set Calculator Values" << endl;
                            cout << "2. Calculate Fitra" << endl;
                            cout << "3. Calculate Zakat" << endl;
                            cout << "4. View Current Calculator Settings" << endl;
                            cout << "0. Back to User Services Menu" << endl;

                            int calcMenuChoice = getValidatedIntInput("Enter choice:", "Invalid input. Please enter a number.");

                            if (calcMenuChoice == 0) {
                                calcSession = false;
                            }
                            else if (calcMenuChoice == 1) {
                                double wealth   = getValidatedDoubleInput("Enter total wealth:", "Invalid input. Please enter a number.");
                                int members     = getValidatedIntInput("Enter number of family members for Fitra:", "Invalid input. Please enter an integer.");
                                double fitraR   = getValidatedDoubleInput("Enter Fitra rate per person:", "Invalid input. Please enter a number.");
                                double nisabT   = getValidatedDoubleInput("Enter Nisab threshold for Zakat:", "Invalid input. Please enter a number.");
                                double monthlyI = getValidatedDoubleInput("Enter monthly installment (for general calculation):", "Invalid input. Please enter a number.");

                                calculator.setTotalWealth(wealth);
                                calculator.setFamilyMembers(members);
                                calculator.setFitraRate(fitraR);
                                calculator.setNisabThreshold(nisabT);
                                calculator.setMonthlyInstallment(monthlyI);
                                cout << "Calculator values updated." << endl;
                                calculator.saveToFile(CALCULATOR_FILE);
                            }
                            else if (calcMenuChoice == 2) {
                                calculator.calculateFitra();
                                cout << "Calculated Fitra: "
                                     << fixed << setprecision(2)
                                     << calculator.getFitraana() << endl;
                            }
                            else if (calcMenuChoice == 3) {
                                calculator.calculateZakat();
                                cout << "Calculated Zakat: "
                                     << fixed << setprecision(2)
                                     << calculator.getZakat() << endl;
                            }
                            else if (calcMenuChoice == 4) {
                                CalculatorController::showmenu(calculator);
                            }
                            else {
                                cout << "Invalid calculator menu choice." << endl;
                            }
                        }
                    }
                    else if (userChoice == 3) {
                        bool atmSession = true;
                        while (atmSession) {
                            cout << endl << "===== ATM Services =====" << endl;
                            cout << "1. Setup Card" << endl;
                            cout << "2. Activate Card" << endl;
                            cout << "3. Deactivate Card" << endl;
                            cout << "4. Verify PIN" << endl;
                            cout << "5. View ATM Card Details" << endl;
                            cout << "0. Back to User Services Menu" << endl;

                            int atmMenuChoice = getValidatedIntInput("Enter choice:", "Invalid input. Please enter a number.");

                            if (atmMenuChoice == 0) {
                                atmSession = false;
                            }
                            else if (atmMenuChoice == 1) {
                                atm.SetupCard();
                            }
                            else if (atmMenuChoice == 2) {
                                atm.ActivateCard();
                            }
                            else if (atmMenuChoice == 3) {
                                atm.DeActivateCard();
                            }
                            else if (atmMenuChoice == 4) {
                                string enteredPin = getStringInput("Enter PIN to verify:");
                                if (atm.VerifyPIN(enteredPin)) {
                                    cout << "PIN verified successfully." << endl;
                                } else {
                                    cout << "PIN verification failed or card not activated." << endl;
                                }
                            }
                            else if (atmMenuChoice == 5) {
                                ATMController::showmenu(atm);
                            }
                            else {
                                cout << "Invalid ATM menu choice." << endl;
                            }

                            atm.saveToFile(ATM_FILE);
                        }
                    }
                    else if (userChoice == 4) {
                        Utilitiesdatabase db;
                        db.waitForSpin();
                        string prize = db.spinTheWheelAndDisplayPrize();
                        utilities.setSpinwheelPrize(prize);
                        cout << "You won: " << prize << endl;
                        utilities.saveToFile(UTILITIES_FILE);
                    }
                    else if (userChoice == 5) {
                        cout << endl << "===== Your Account Details =====" << endl;
                        cout << "Name:          "
                             << loggedInAccount->getCustomerName() << endl;
                        cout << "CNIC:          "
                             << loggedInAccount->getCustomerCnic() << endl;
                        cout << "Type:          "
                             << loggedInAccount->getAccountType() << endl;
                        cout << "Number:        "
                             << loggedInAccount->getAccountNumber() << endl;
                        cout << "Balance:       "
                             << fixed << setprecision(2)
                             << loggedInAccount->getBalance() << endl;
                        cout << "Frozen Status: "
                             << (loggedInAccount->getIsFrozen() ? "Frozen" : "Active") << endl;
                    }
                    else if (userChoice == 6) {
                        double amount = getValidatedDoubleInput("Enter amount to deposit:", "Invalid amount. Please enter a number.");
                        if (amount > 0) {
                            loggedInAccount->deposit(amount);
                            bank.saveAccountsToFile(ACCOUNTS_FILE);
                            cout << "Deposit successful. New balance: "
                                 << fixed << setprecision(2)
                                 << loggedInAccount->getBalance() << endl;
                        } else {
                            cout << "Deposit amount must be positive." << endl;
                        }
                    }
                    else if (userChoice == 7) {
                        double amount = getValidatedDoubleInput("Enter amount to withdraw:", "Invalid amount. Please enter a number.");
                        if (amount > 0) {
                            if (loggedInAccount->withdraw(amount)) {
                                bank.saveAccountsToFile(ACCOUNTS_FILE);
                                cout << "Withdrawal successful. New balance: "
                                     << fixed << setprecision(2)
                                     << loggedInAccount->getBalance() << endl;
                            } else {
                                cout << "Insufficient balance or invalid amount." << endl;
                            }
                        } else {
                            cout << "Withdrawal amount must be positive." << endl;
                        }
                    }
                    else {
                        cout << "Invalid choice. Please try again." << endl;
                    }
                }
            }
            else {
                cout << "Login failed. Invalid account number or password." << endl;
            }
        }
        else if (mainChoice == 3) {
            string tempUser = getStringInput("Enter Admin Username:");
            string tempPass = getStringInput("Enter Admin Password:");
            if (tempUser == admin.getUsername() && tempPass == admin.getPassword()) {
                bank.viewCustomerAccounts();
            } else {
                cout << "Access Denied: Invalid admin credentials." << endl;
            }
        }
        else if (mainChoice == 4) {
            string tempUser = getStringInput("Enter Admin Username:");
            string tempPass = getStringInput("Enter Admin Password:");
            if (tempUser == admin.getUsername() && tempPass == admin.getPassword()) {
                string accNumToFreeze = getStringInput("Enter account number to freeze:");
                bank.freezeAccount(accNumToFreeze);
                bank.saveAccountsToFile(ACCOUNTS_FILE);
            } else {
                cout << "Access Denied: Invalid admin credentials." << endl;
            }
        }
        else if (mainChoice == 5) {
            string tempUser = getStringInput("Enter Admin Username:");
            string tempPass = getStringInput("Enter Admin Password:");
            if (tempUser == admin.getUsername() && tempPass == admin.getPassword()) {
                string accNumToUnfreeze = getStringInput("Enter account number to unfreeze:");
                bank.unfreezeAccount(accNumToUnfreeze);
                bank.saveAccountsToFile(ACCOUNTS_FILE);
            } else {
                cout << "Access Denied: Invalid admin credentials." << endl;
            }
        }
        else if (mainChoice == 6) {
            string adminUser = getStringInput("Enter Admin Username:");
            string adminPass = getStringInput("Enter Admin Password:");

            if (adminUser == admin.getUsername() && adminPass == admin.getPassword()) {
                cout << "Admin login successful!" << endl;
                bool adminSession = true;
                while (adminSession) {
                    cout << endl << "===== Admin Panel =====" << endl;
                    cout << "1. Set Bill Details" << endl;
                    cout << "2. Set Challan Details" << endl;
                    cout << "3. View Admin Settings" << endl;
                    cout << "0. Exit Admin Panel" << endl;

                    int adminOpt = getValidatedIntInput("Enter choice:", "Invalid admin choice. Please enter a number.");

                    if (adminOpt == 0) {
                        adminSession = false;
                    }
                    else if (adminOpt == 1) {
                        string type = getStringInput("Enter bill type (e.g., Electricity, Gas):");
                        double amount = getValidatedDoubleInput("Enter total bill amount:", "Invalid amount. Please enter a number.");
                        if (amount >= 0) {
                            admin.setBillDetails(type, amount);
                            cout << "Bill details updated." << endl;
                        } else {
                            cout << "Bill amount cannot be negative." << endl;
                        }
                    }
                    else if (adminOpt == 2) {
                        string type = getStringInput("Enter challan type (e.g., Traffic, Tax):");
                        double amount = getValidatedDoubleInput("Enter total challan amount:", "Invalid amount. Please enter a number.");
                        if (amount >= 0) {
                            admin.setChallanDetails(type, amount);
                            cout << "Challan details updated." << endl;
                        } else {
                            cout << "Challan amount cannot be negative." << endl;
                        }
                    }
                    else if (adminOpt == 3) {
                        AdminController::showmenu(admin);
                    }
                    else {
                        cout << "Invalid admin choice. Please try again." << endl;
                    }
                    admin.saveToFile(ADMIN_FILE);
                }
            }
            else {
                cout << "Admin login failed. Invalid credentials." << endl;
            }
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    bank.saveAccountsToFile(ACCOUNTS_FILE);
    utilities.saveToFile(UTILITIES_FILE);
    calculator.saveToFile(CALCULATOR_FILE);
    admin.saveToFile(ADMIN_FILE);
    atm.saveToFile(ATM_FILE);
    cout << "Exiting Banking System. Goodbye!" << endl;

    return 0;
}
