#include "UtilitiesController.h"
#include "UtilitiesView.h"
#include "Utilitiesdatabase.h"
#include "Header.h"
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip>
#include <random>


extern int getValidatedIntInput(const string& prompt, const string& errorMsg);
extern double getValidatedDoubleInput(const string& prompt, const string& errorMsg);
extern string getStringInput(const string& prompt);


using namespace std;

void AccountsController::showmenu(Account& account) {
    AccountView::showInfo(
        account.getCustomerName(),
        account.getCustomerCnic(),
        account.getAccountType(),
        account.getAccountNumber(),
        to_string(account.getBalance()),
        account.getIsFrozen() ? "Frozen" : "Active"
    );
    AccountView::displayMessage("\n=== Account Management ===");
    AccountView::displayMessage("1. Deposit");
    AccountView::displayMessage("2. Withdraw");
    AccountView::displayMessage("3. View Details (current account)");
    AccountView::displayMessage("0. Back to User Menu");
}

void AccountsController::handleUserChoice(int choice, Account& account, BankSystem& bankSystem) {
    AccountView::displayMessage("Selected Account Option: " + to_string(choice));
    double amount;

    switch (choice) {
    case 1: {
        amount = getValidatedDoubleInput("Enter amount to deposit:", "Invalid amount. Please enter a number.");
        if (amount >= 0) {
            account.deposit(amount);
        } else {
            AccountView::displayMessage("Deposit amount cannot be negative.");
        }
        break;
    }
    case 2: {
        amount = getValidatedDoubleInput("Enter amount to withdraw:", "Invalid amount. Please enter a number.");
        if (amount >= 0) {
            account.withdraw(amount);
        } else {
            AccountView::displayMessage("Withdrawal amount cannot be negative.");
        }
        break;
    }
    case 3: {
        AccountView::showInfo(
            account.getCustomerName(),
            account.getCustomerCnic(),
            account.getAccountType(),
            account.getAccountNumber(),
            to_string(account.getBalance()),
            account.getIsFrozen() ? "Frozen" : "Active"
        );
        break;
    }
    case 0:
        AccountView::displayMessage("Exiting Account Management.");
        break;
    default:
        AccountView::displayMessage("Invalid choice. Please try again.");
        break;
    }
}

void UtilitiesController::showmenu(Utilities& utilities) {
    cout << "Welcome to the Utilities Payment System!" << endl;
    cout << "1. Pay Bills: " << utilities.getBills() << endl;
    cout << "2. Pay Challan: " << utilities.getChallan() << endl;
    cout << "3. Pay Ticket: " << utilities.getTicket() << endl;
    cout << "4. Pay Travel: " << utilities.getTravel() << endl;
    cout << "5. Pay Loan: " << utilities.getLoan() << endl;
    cout << "6. Pay Education: " << utilities.getEducation() << endl;
    cout << "7. Pay Insurance: " << utilities.getInsurance() << endl;
    cout << "8. Spin Wheel for Prize: " << utilities.getSpinwheelPrize() << endl;
    cout << "0. Exit" << endl;
}

void UtilitiesController::handleUserChoice(int choice, Utilities& utilities) {
    string type;
    double amount;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1, 100);

    switch (choice) {
    case 1: {
        type = getStringInput("Enter bill type (e.g., Electricity, Gas, Water):");
        amount = getValidatedDoubleInput("Enter bill amount:", "Invalid amount. Please enter a number.");
        if (amount >= 0) {
            utilities.setBills("Paid " + to_string(amount) + " for " + type);
            cout << "Bill paid successfully." << endl;
        } else {
            cout << "Bill amount cannot be negative." << endl;
        }
        break;
    }
    case 2: {
        type = getStringInput("Enter challan type (e.g., Traffic, Tax):");
        amount = getValidatedDoubleInput("Enter challan amount:", "Invalid amount. Please enter a number.");
        if (amount >= 0) {
            utilities.setChallan("Paid " + to_string(amount) + " for " + type);
            cout << "Challan paid successfully." << endl;
        } else {
            cout << "Challan amount cannot be negative." << endl;
        }
        break;
    }
    case 3: {
        type = getStringInput("Enter ticket type (e.g., Cinema, Concert):");
        amount = getValidatedDoubleInput("Enter ticket amount:", "Invalid amount. Please enter a number.");
        if (amount >= 0) {
            utilities.setTicket("Paid " + to_string(amount) + " for " + type);
            cout << "Ticket paid successfully." << endl;
        } else {
            cout << "Ticket amount cannot be negative." << endl;
        }
        break;
    }
    case 4: {
        type = getStringInput("Enter travel type (e.g., Bus, Train, Flight):");
        amount = getValidatedDoubleInput("Enter travel amount:", "Invalid amount. Please enter a number.");
        if (amount >= 0) {
            utilities.setTravel("Paid " + to_string(amount) + " for " + type);
            cout << "Travel paid successfully." << endl;
        } else {
            cout << "Travel amount cannot be negative." << endl;
        }
        break;
    }
    case 5: {
        type = getStringInput("Enter loan type (e.g., Personal, Home):");
        amount = getValidatedDoubleInput("Enter loan payment amount:", "Invalid amount. Please enter a number.");
        if (amount >= 0) {
            utilities.setLoan("Paid " + to_string(amount) + " for " + type);
            cout << "Loan payment made successfully." << endl;
        } else {
            cout << "Loan payment amount cannot be negative." << endl;
        }
        break;
    }
    case 6: {
        type = getStringInput("Enter education type (e.g., Tuition, Books):");
        amount = getValidatedDoubleInput("Enter education amount:", "Invalid amount. Please enter a number.");
        if (amount >= 0) {
            utilities.setEducation("Paid " + to_string(amount) + " for " + type);
            cout << "Education payment made successfully." << endl;
        } else {
            cout << "Education amount cannot be negative." << endl;
        }
        break;
    }
    case 7: {
        type = getStringInput("Enter insurance type (e.g., Health, Car):");
        amount = getValidatedDoubleInput("Enter insurance amount:", "Invalid amount. Please enter a number.");
        if (amount >= 0) {
            utilities.setInsurance("Paid " + to_string(amount) + " for " + type);
            cout << "Insurance payment made successfully." << endl;
        } else {
            cout << "Insurance amount cannot be negative." << endl;
        }
        break;
    }
    case 8: {
        cout << "Spinning the wheel..." << endl;
        cout << "(Simulating spin...)" << endl;

        int prize = distrib(gen);
        if (prize <= 20) {
            utilities.setSpinwheelPrize("Free Coffee Voucher!");
        } else if (prize <= 50) {
            utilities.setSpinwheelPrize("10% Discount on Next Bill!");
        } else if (prize <= 80) {
            utilities.setSpinwheelPrize("Rs. 500 Cashback!");
        } else {
            utilities.setSpinwheelPrize("Better luck next time!");
        }
        cout << "You won: " << utilities.getSpinwheelPrize() << endl;
        break;
    }
    case 0:
        cout << "Exiting Utilities Menu." << endl;
        break;
    default:
        cout << "Invalid choice. Please try again." << endl;
        break;
    }
}

void CalculatorController::showmenu(Calculator& calculator) {
    cout << "=== Calculator Menu ===" << endl;
    cout << "1. Total Wealth: " << calculator.getTotalWealth() << endl;
    cout << "2. Number of Family Members: " << calculator.getFamilyMembers() << endl;
    cout << "3. Fitra Rate: " << calculator.getFitraRate() << endl;
    cout << "4. Nisab Threshold: " << calculator.getNisabThreshold() << endl;
    cout << "5. Monthly Installment: " << calculator.getMonthlyInstallment() << endl;
    cout << "0. Exit" << endl;
}

void CalculatorController::handleUserChoice(int choice, Calculator& calculator) {
    string input;
    switch (choice) {
    case 1: {
        input = getStringInput("Enter total wealth:");
        calculator.setTotalWealth(input);
        break;
    }
    case 2: {
        input = getStringInput("Enter number of family members:");
        calculator.setFamilyMembers(input);
        break;
    }
    case 3: {
        input = getStringInput("Enter fitra rate:");
        calculator.setFitraRate(input);
        break;
    }
    case 4: {
        input = getStringInput("Enter nisab threshold:");
        calculator.setNisabThreshold(input);
        break;
    }
    case 5: {
        input = getStringInput("Enter monthly installment:");
        calculator.setMonthlyInstallment(input);
        break;
    }
    case 0:
        cout << "Exiting Calculator Menu." << endl;
        break;
    default:
        cout << "Invalid choice. Please try again." << endl;
        break;
    }
}

void ATMController::showmenu(ATM& atm) {
    cout << "=== ATM Services ===" << endl;
    cout << "1. Card Number: " << atm.getCardNumber() << endl;
    cout << "2. PIN: " << atm.getPin() << endl;
    cout << "3. Activated: " << (atm.getIsActivated() ? "Yes" : "No") << endl;
    cout << "0. Exit" << endl;
}

void ATMController::handleUserChoice(int choice, ATM& atm) {
    string input;
    switch (choice) {
    case 1: {
        input = getStringInput("Enter card number:");
        atm.setCardNumber(input);
        break;
    }
    case 2: {
        input = getStringInput("Enter PIN:");
        atm.setPin(input);
        break;
    }
    case 3: {
        input = getStringInput("Activate ATM (1 for Yes, 0 for No):");
        atm.setIsActivated(input == "1");
        break;
    }
    case 0:
        cout << "Exiting ATM Services." << endl;
        break;
    default:
        cout << "Invalid choice. Please try again." << endl;
        break;
    }
}

void BankSystemController::showmenu(BankSystem& bankSystem) {
    BankSystemview bankSystemView;
    bankSystemView.showMenu(bankSystem.getAllAccounts());
    cout << "0. Back to Main Menu" << endl;
}

void BankSystemController::handleUserChoice(int choice, BankSystem& bankSystem) {
    BankSystemview bankSystemView;
    switch (choice) {
    case 1: {
        bankSystemView.showMenu(bankSystem.getAllAccounts());
        break;
    }
    case 0:
        cout << "Exiting Bank System Management." << endl;
        break;
    default:
        cout << "Invalid choice. Please try again." << endl;
        break;
    }
}

void AdminController::showmenu(Admin& admin) {
    cout << "\n=== Admin Panel ===" << endl;
    cout << "Admin Username: " << admin.getUsername() << endl;
    cout << "Admin Password: " << admin.getPassword() << endl;
    cout << "Default Bill Type: " << admin.getBillType() << ", Total: " << fixed << setprecision(2) << admin.getTotalBill() << endl;
    cout << "Default Challan Type: " << admin.getChallanType() << ", Total: " << fixed << setprecision(2) << admin.getTotalChallan() << endl;
    cout << "Global Freeze Account Flag: " << (admin.getFreezeAccountFlag() ? "Yes" : "No") << endl;
    cout << "Global Delete Account Flag: " << (admin.getDeleteAccountFlag() ? "Yes" : "No") << endl;
    cout << "1. Set Bill Details" << endl;
    cout << "2. Set Challan Details" << endl;
    cout << "3. Freeze Account" << endl;
    cout << "4. Unfreeze Account" << endl;
    cout << "5. Delete Account" << endl;
    cout << "0. Exit Admin Panel" << endl;
}

void AdminController::handleUserChoice(int choice, Admin& admin, BankSystem& bankSystem) {
    string type;
    double amount;
    string accountNumber;

    switch (choice) {
    case 1: {
        type = getStringInput("Enter bill type (e.g., Electricity, Gas):");
        amount = getValidatedDoubleInput("Enter total bill amount to generate:", "Invalid amount. Please enter a number.");
        if (amount >= 0) {
            admin.setBillDetails(type, amount);
            cout << "Bill details generated/updated successfully." << endl;
        } else {
            cout << "Bill amount cannot be negative." << endl;
        }
        break;
    }
    case 2: {
        type = getStringInput("Enter challan type (e.g., Traffic, Tax):");
        amount = getValidatedDoubleInput("Enter total challan amount to generate:", "Invalid amount. Please enter a number.");
        if (amount >= 0) {
            admin.setChallanDetails(type, amount);
            cout << "Challan details generated/updated successfully." << endl;
        } else {
            cout << "Challan amount cannot be negative." << endl;
        }
        break;
    }
    case 3: {
        accountNumber = getStringInput("Enter account number to freeze:");
        if (bankSystem.freezeAccount(accountNumber)) {
            cout << "Account frozen successfully." << endl;
        } else {
            cout << "Failed to freeze account or account not found." << endl;
        }
        break;
    }
    case 4: {
        accountNumber = getStringInput("Enter account number to unfreeze:");
        if (bankSystem.unfreezeAccount(accountNumber)) {
            cout << "Account unfrozen successfully." << endl;
        } else {
            cout << "Failed to unfreeze account or account not found." << endl;
        }
        break;
    }
    case 5: {
        accountNumber = getStringInput("Enter account number to delete:");
        string confirm = getStringInput("Are you sure you want to delete this account? (yes/no):");
        if (confirm == "yes") {
            if (bankSystem.deleteAccount(accountNumber)) {
                cout << "Account deleted successfully." << endl;
            } else {
                cout << "Failed to delete account or account not found." << endl;
            }
        } else {
            cout << "Account deletion cancelled." << endl;
        }
        break;
    }
    case 0:
        cout << "Exiting Admin Menu." << endl;
        break;
    default:
        cout << "Invalid choice. Please try again." << endl;
        break;
    }
}

void LoanController::showMenu(LoanTracker* loan) {
    if (loan) {
        cout << "\n=== Loan Management ===" << endl;
        loan->checkLoanStatus();
        cout << "1. Make Installment Payment" << endl;
        cout << "2. Check Loan Status" << endl;
        cout << "0. Back to Account Menu" << endl;
    } else {
        cout << "\n=== Loan Management ===" << endl;
        cout << "No active loan for this account." << endl;
        cout << "1. Apply for a New Loan" << endl;
        cout << "0. Back to Account Menu" << endl;
    }
}

void LoanController::handleUserChoice(int choice, Account& account, BankSystem& bank) {
    LoanTracker* loan = bank.getLoanTracker(account.getAccountNumber());

    if (!loan) {
        switch (choice) {
        case 1: {
            cout << "\n--- Apply for New Loan ---" << endl;
            int totalInstallments = getValidatedIntInput("Enter total number of installments:", "Invalid input. Please enter a number.");
            if (totalInstallments <= 0) {
                cout << "Number of installments must be positive." << endl;
                break;
            }
            int duration = getValidatedIntInput("Enter loan duration in days:", "Invalid input. Please enter a number.");
            if (duration <= 0) {
                cout << "Loan duration must be positive." << endl;
                break;
            }
            LoanTracker* newLoan = new LoanTracker(totalInstallments, 0, duration, time(0), &account);
            bank.addLoanTracker(account.getAccountNumber(), newLoan);
            cout << "Loan applied successfully." << endl;
            break;
        }
        case 0:
            cout << "Exiting Loan Management." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } else {
        switch (choice) {
        case 1: {
            double amount = getValidatedDoubleInput("Enter payment amount:", "Invalid input. Please enter a number.");
            if (amount <= 0) {
                cout << "Payment amount must be positive." << endl;
                break;
            }
            loan->makeInstallmentPayment(amount, &account);
            break;
        }
        case 2: {
            loan->checkLoanStatus();
            break;
        }
        case 0:
            cout << "Exiting Loan Management." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }
}
