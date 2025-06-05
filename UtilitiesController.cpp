// UtilitiesController.cpp
#include "UtilitiesController.h"
#include "UtilitiesView.h"
#include "Utilitiesdatabase.h"
#include "Header.h"
#include <iostream>
#include <string>
#include <map>
#include <limits>


using namespace std;


void UtilitiesController::showmenu(Utilities& utilities) {
    Utilitiesdatabase utilitiesDatabase;



    utilitiesDatabase.showMenu(utilities.getBills(), utilities.getChallan(),
        utilities.getTicket(), utilities.getTravel(),
        utilities.getLoan(), utilities.getEducation(),
        utilities.getInsurance(), utilities.getSpinwheelPrize());
}


void UtilitiesController::handleUserChoice(int choice, Utilities& utilities) {
    Utilitiesdatabase utilitiesDatabase; // Create an instance to interact with database functions

    switch (choice) {
    case 1:
        utilitiesDatabase.displayMessage("You selected Pay Bills. Setting bills to 0.");
        utilities.setBills("0");
        break;
    case 2:
        utilitiesDatabase.displayMessage("You selected Pay Challan. Setting challan to 0.");
        utilities.setChallan("0");
        break;
    case 3:
        utilitiesDatabase.displayMessage("You selected Pay Ticket. Setting ticket to 0.");
        utilities.setTicket("0");
        break;
    case 4:
        utilitiesDatabase.displayMessage("You selected Pay Travel. Setting travel to 0.");
        utilities.setTravel("0");
        break;
    case 5:
        utilitiesDatabase.displayMessage("You selected Pay Loan. Setting loan to 0.");
        utilities.setLoan("0");
        break;
    case 6:
        utilitiesDatabase.displayMessage("You selected Pay Education. Setting education to 0.");
        utilities.setEducation("0");
        break;
    case 7:
        utilitiesDatabase.displayMessage("You selected Pay Insurance. Setting insurance to 0.");
        utilities.setInsurance("0");
        break;
    case 8: {
        utilitiesDatabase.displayMessage("Spinning the wheel...");
        string prize = utilitiesDatabase.spinTheWheelAndDisplayPrize();
        utilities.setSpinwheelPrize(prize);
        utilitiesDatabase.displayMessage("You won: " + utilities.getSpinwheelPrize());
        break;
    }
    case 0:
        utilitiesDatabase.displayMessage("Exiting Utilities Payment System. Goodbye!");
        break;
    default:
        utilitiesDatabase.displayMessage("Invalid choice. Please try again.");
        break;
    }
}


void CalculatorController::showmenu(Calculator& calculator)
{
    CalculatorView calculatorView;
    calculatorView.showMenu(
        to_string(calculator.getTotalWealth()),
        to_string(calculator.getFamilyMembers()),
        to_string(calculator.getFitraRate()),
        to_string(calculator.getNisabThreshold()),
        to_string(calculator.getMonthlyInstallment())
    );
}


void ATMController::showmenu(ATM& atm)
{
    ATMview atmView;
    atmView.showMenu(
        atm.getCardNumber(),
        atm.getPin(),
        atm.getIsActivated() ? "Activated" : "Not Activated"
    );
}

void ATMController::handleUserChoice(int choice, ATM& atm)
{
    ATMdatabase atmDatabase;
    switch (choice)
    {
    case 1:
        atmDatabase.displayMessage("You selected Card Number: " + atm.getCardNumber());
        break;
    case 2:
        atmDatabase.displayMessage("You selected Pin: " + atm.getPin());
        break;
    case 3:
        atmDatabase.displayMessage("You selected Is Activated: " + string(atm.getIsActivated() ? "Activated" : "Not Activated"));
        break;
    case 0:
        atmDatabase.displayMessage("Exiting the program.");
        break;
    default:
        atmDatabase.displayMessage("Invalid choice. Please try again.");
        break;
    }
}


void ATMController::displayMessage(const string& message)
{
    ATMdatabase atmDatabase;
    atmDatabase.displayMessage(message);
}

void AccountsController::showmenu(Account& account)
{
    Accountdatabase accountDatabase;
    accountDatabase.showMenu(
        account.getCustomerName(),
        account.getCustomerCnic(),
        account.getAccountType(),
        account.getAccountNumber(),
        to_string(account.getBalance()),
        account.getIsFrozen() ? "Frozen" : "Not Frozen"
    );
}

void AccountsController::handleUserChoice(int choice, Account& account)
{
    Accountdatabase accountDatabase;
    switch (choice)
    {
    case 1:
        accountDatabase.displayMessage("You selected Customer Name: " + account.getCustomerName());
        break;
    case 2:
        accountDatabase.displayMessage("You selected Customer CNIC: " + account.getCustomerCnic());
        break;
    case 3:
        accountDatabase.displayMessage("You selected Account Type: " + account.getAccountType());
        break;
    case 4:
        accountDatabase.displayMessage("You selected Account Number: " + account.getAccountNumber());
        break;
    case 5:
        accountDatabase.displayMessage("You selected Balance: " + to_string(account.getBalance()));
        break;
    case 6:
        accountDatabase.displayMessage("You selected Frozen Status: " + string(account.getIsFrozen() ? "Frozen" : "Not Frozen"));
        break;
    case 0:
        accountDatabase.displayMessage("Exiting the program.");
        break;
    default:
        accountDatabase.displayMessage("Invalid choice. Please try again.");
        break;
    }
}

void AccountsController::displayMessage(const string& message)
{
    Accountdatabase accountDatabase;
    accountDatabase.displayMessage(message);
}

void BankSystemController::showmenu(BankSystem& bankSystem)
{
    // This controller doesn't directly show a menu based on BankSystem state
    // but interacts with it to perform actions like creating accounts, logging in, etc.
}

void BankSystemController::handleUserChoice(int choice, BankSystem& bankSystem) {
    BankSystemdatabase bankSystemDatabase;
    switch (choice) {
        case 1: // Create Account
            bankSystem.createAccount();
            break;
        case 2: { // Login
            string accNum, pwd;
            cout << "Account number: ";
            cin >> accNum;
            cout << "Password: ";
            cin >> pwd;
            bankSystem.login(accNum, pwd);
            break;
        }
        case 3: // View Accounts
            bankSystem.viewCustomerAccounts();
            break;
        case 4: { // Freeze Account
            string accNum;
            cout << "Enter account number to freeze: ";
            cin >> accNum;
            bankSystem.freezeAccount(accNum);
            break;
        }
        case 5: { // Unfreeze Account
            string accNum;
            cout << "Enter account number to unfreeze: ";
            cin >> accNum;
            bankSystem.unfreezeAccount(accNum);
            break;
        }
        case 0: // Exit
            bankSystemDatabase.displayMessage("Exiting Bank System.");
            break;
        default:
            bankSystemDatabase.displayMessage("Invalid choice. Please try again.");
            break;
    }
}


void BankSystemController::displayMessage(const string& message)
{
    BankSystemdatabase bankSystemDatabase;
    bankSystemDatabase.displayMessage(message);
}

void AdminController::showmenu(Admin& admin)
{
    Admindatabase adminDatabase;
    adminDatabase.showMenu(
        admin.getUsername(),
        admin.getPassword(),
        admin.getBillType(),
        admin.getTotalBill(),
        admin.getChallanType(),
        admin.getTotalChallan(),
        admin.getFreezeAccount(),
        admin.getDeleteAccount()
    );
}

void AdminController::handleUserChoice(int choice, Admin& admin)
{
    Admindatabase adminDatabase;
    switch (choice)
    {
    case 1:
        adminDatabase.displayMessage("You selected Username: " + admin.getUsername());
        break;
    case 2:
        adminDatabase.displayMessage("You selected Password: " + admin.getPassword());
        break;
    case 3:
        adminDatabase.displayMessage("You selected Bill Type: " + admin.getBillType());
        break;
    case 4:
        adminDatabase.displayMessage("You selected Total Bill: " + to_string(admin.getTotalBill()));
        break;
    case 5:
        adminDatabase.displayMessage("You selected Challan Type: " + admin.getChallanType());
        break;
    case 6:
        adminDatabase.displayMessage("You selected Total Challan: " + to_string(admin.getTotalChallan()));
        break;
    case 7:
        adminDatabase.displayMessage("You selected Freeze Account: " + string(admin.getFreezeAccount() ? "Yes" : "No"));
        break;
    case 8:
        adminDatabase.displayMessage("You selected Delete Account: " + string(admin.getDeleteAccount() ? "Yes" : "No"));
        break;
    case 0:
        adminDatabase.displayMessage("Exiting Admin Menu.");
        break;
    default:
        adminDatabase.displayMessage("Invalid choice. Please try again.");
        break;
    }
}

void AdminController::displayMessage(const string& message)
{
    Admindatabase adminDatabase;
    adminDatabase.displayMessage(message);
}