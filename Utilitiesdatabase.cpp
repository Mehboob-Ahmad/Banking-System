#include "Utilitiesdatabase.h"
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <limits>
#include "Header.h"
#include <iomanip>
#include <random>


using namespace std; 


void Utilitiesdatabase::showMenu(const string& bills, const string& challan,
    const string& ticket, const string& travel,
    const string& loan, const string& education,
    const string& insurance, const string& spinwheelPrize) {
    cout << "Welcome to the Utilities Payment System!" << endl;
    cout << "1. Pay Bills: " << bills << endl;
    cout << "2. Pay Challan: " << challan << endl;
    cout << "3. Pay Ticket: " << ticket << endl;
    cout << "4. Pay Travel: " << travel << endl;
    cout << "5. Pay Loan: " << loan << endl;
    cout << "6. Pay Education: " << education << endl;
    cout << "7. Pay Insurance: " << insurance << endl;
    cout << "8. Spin Wheel for Prize: " << spinwheelPrize << endl;
    cout << "0. Exit" << endl;
}

int Utilitiesdatabase::getUserChoice() {
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return -1;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return choice;
}

void Utilitiesdatabase::displayMessage(const string& message) {
    cout << message << endl;
}

void Utilitiesdatabase::waitForSpin() {
    cout << "Spinning the wheel..." << endl;
}

string Utilitiesdatabase::spinTheWheelAndDisplayPrize() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1, 100);
    int prize = distrib(gen);

    if (prize <= 20) {
        return "Free Coffee Voucher!";
    } else if (prize <= 50) {
        return "10% Discount on Next Bill!";
    } else if (prize <= 80) {
        return "Rs. 500 Cashback!";
    } else {
        return "Better luck next time!";
    }
}


void calculatordatabase::showMenu(const string& totalwealth,
    const string& familymembers,
    const string& fitraRate,
    const string& nisabthreshold,
    const string& monthlyInstallment) {
    cout << "=== Calculator Menu ===" << endl;
    cout << "1. Total Wealth: " << totalwealth << endl;
    cout << "2. Number of Family Members: " << familymembers << endl;
    cout << "3. Fitra Rate: " << fitraRate << endl;
    cout << "4. Nisab Threshold: " << nisabthreshold << endl;
    cout << "5. Monthly Installment: " << monthlyInstallment << endl;
    cout << "0. Exit" << endl;
}

int calculatordatabase::getUserChoice() {
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return -1;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return choice;
}

void calculatordatabase::displayMessage(const string& message) {
    cout << message << endl;
}


void ATMdatabase::showMenu(const string& cardNumber,
    const string& pin,
    const string& isActivated) {
    cout << "=== ATM Services ===" << endl;
    cout << "1. Card Number: " << cardNumber << endl;
    cout << "2. PIN: " << pin << endl;
    cout << "3. Activated: " << isActivated << endl;
    cout << "0. Exit" << endl;
}

int ATMdatabase::getUserChoice() {
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return -1;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return choice;
}

void ATMdatabase::displayMessage(const string& message) {
    cout << message << endl;
}


void Accountdatabase::showMenu(const string& customerName,
    const string& customerCnic,
    const string& type,
    const string& number,
    const string& balance,
    const string& frozen) {
    cout << "\n=== Account Information ===" << endl;
    cout << "Name: " << customerName << endl
        << "CNIC: " << customerCnic << endl
        << "Type: " << type << endl
        << "Number: " << number << endl
        << "Balance: " << balance << endl
        << "Status: " << frozen << endl;
}

int Accountdatabase::getUserChoice() {
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return -1;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return choice;
}

void Accountdatabase::displayMessage(const string& message) {
    cout << message << endl;
}


void BankSystemdatabase::showMenu(const vector<Account*>& accounts) {
    cout << "\n=== Bank System Overview ===" << endl;
    cout << "Total Accounts: " << accounts.size() << endl;
    cout << "\n--- All Accounts ---" << endl;
    for (Account* accountPtr : accounts) {
        cout << "Acc No: " << accountPtr->getAccountNumber()
            << ", Name: " << accountPtr->getCustomerName()
            << ", Balance: " << fixed << setprecision(2) << accountPtr->getBalance()
            << ", Status: " << (accountPtr->getIsFrozen() ? "Frozen" : "Active") << endl;
    }
    cout << "0. Back to Main Menu" << endl;
}

int BankSystemdatabase::getUserChoice() {
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return -1;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return choice;
}

void BankSystemdatabase::displayMessage(const string& message) {
    cout << message << endl;
}


void Admindatabase::showMenu(const string& username, const string& password,
                             const string& billType, double totalBill,
                             const string& challanType, double totalChallan,
                             bool freezeAccount, bool deleteAccount) {
   cout << "=== Admin Menu ===" << endl;
   cout << "1. Admin Username: " << username << endl;
   cout << "2. Admin Password: " << password << endl;
   cout << "3. Current Bill Type: " << billType << endl;
   cout << "4. Current Total Bill: " << fixed << setprecision(2) << totalBill << endl;
   cout << "5. Current Challan Type: " << challanType << endl;
   cout << "6. Current Total Challan: " << fixed << setprecision(2) << totalChallan << endl;
   cout << "7. Global Freeze Account Flag: " << (freezeAccount ? "Yes" : "No") << endl;
   cout << "8. Global Delete Account Flag: " << (deleteAccount ? "Yes" : "No") << endl;
   cout << "9. Manage Accounts (Freeze/Unfreeze/Delete)" << endl;
   cout << "0. Exit" << endl;
}

int Admindatabase::getUserChoice() {
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return -1;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return choice;
}

void Admindatabase::displayMessage(const string& message) {
    cout << message << endl;
}