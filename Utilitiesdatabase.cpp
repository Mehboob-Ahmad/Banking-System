// Utilitiesdatabase.cpp
#include "Utilitiesdatabase.h"
#include <iostream>
#include <string>
#include <map>
#include <ctime>
#include <limits>
#include "Header.h"

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
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return choice;
}
void Utilitiesdatabase::displayMessage(const string& message) {
    cout << message << endl;
}

void Utilitiesdatabase::waitForSpin() {
    cout << "Spinning the wheel... (Press Enter to stop)" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Wait for user to press Enter
}

string Utilitiesdatabase::spinTheWheelAndDisplayPrize() {
    srand(time(0));
    int prizeIndex = rand() % 5;
    string prizes[] = { "10% Discount", "Free Service", "Gift Card", "Cashback", "Try Again" };
    return prizes[prizeIndex];
}

void calculatordatabase::showMenu(const string& totalwealth,
    const string& familymembers,
    const string& fitraRate,
    const string& nisabthreshold,
    const string& monthlyInstallment) {
    cout << "=== Calculator Menu ===" << endl;
    cout << "1. Total Wealth: " << totalwealth << endl;
    cout << "2. Family Members: " << familymembers << endl;
    cout << "3. Fitra Rate: " << fitraRate << endl;
    cout << "4. Nisab Threshold: " << nisabthreshold << endl;
    cout << "5. Monthly Installment: " << monthlyInstallment << endl;
    cout << "0. Exit" << endl;
}

int calculatordatabase::getUserChoice() {
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return choice;
}

void ATMdatabase::showMenu(const string& cardNumber,
    const string& pin,
    const string& isActivated) {
    cout << "=== ATM Menu ===" << endl;
    cout << "1. Card Number: " << cardNumber << endl;
    cout << "2. Pin: " << pin << endl;
    cout << "3. Is Activated: " << isActivated << endl;
    cout << "0. Exit" << endl;
}

int ATMdatabase::getUserChoice() {
    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
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
    cout << "=== Account Details ===" << endl;
    cout << "Customer Name : " << customerName << endl;
    cout << "Customer CNIC : " << customerCnic << endl;
    cout << "Account Type  : " << type << endl;
    cout << "Account Number: " << number << endl;
    cout << "Balance       : " << balance << endl;
    cout << "Frozen Status : " << frozen << endl;
    cout << "0. Exit" << endl;
}

int Accountdatabase::getUserChoice() {
    int choice;
    cout << "Select option (0 to exit): ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return choice;
}

void Accountdatabase::displayMessage(const string& message) {
    cout << message << endl;
}

void BankSystemdatabase::showMenu(
    const string& customerName,
    const string& customerCnic,
    const string& type,
    const string& number,
    const string& balance,
    const string& frozen
) {
    cout << "=== Bank System Account Info ===" << endl;
    cout << "Customer Name : " << customerName << endl;
    cout << "Customer CNIC : " << customerCnic << endl;
    cout << "Account Type  : " << type << endl;
    cout << "Account Number: " << number << endl;
    cout << "Balance       : " << balance << endl;
    cout << "Frozen Status : " << frozen << endl;
}
int BankSystemdatabase::getUserChoice() {
	int choice;
	cout << "Select option (0 to exit): ";
	cin >> choice;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return choice;
}
void BankSystemdatabase::displayMessage(const string& message) {
	cout << message << endl;
}

void Admindatabase::showMenu(const string& username, const string& password, const string& billType, double totalBill, const string& challanType, double totalChallan, bool freezeAccount, bool deleteAccount) {
   cout << "=== Admin Menu ===" << endl;
   cout << "1. Username: " << username << endl;
   cout << "2. Password: " << password << endl;
   cout << "3. Bill Type: " << billType << endl;
   cout << "4. Total Bill: " << totalBill << endl;
   cout << "5. Challan Type: " << challanType << endl;
   cout << "6. Total Challan: " << totalChallan << endl;
   cout << "7. Freeze Account: " << (freezeAccount ? "Yes" : "No") << endl;
   cout << "8. Delete Account: " << (deleteAccount ? "Yes" : "No") << endl;
   cout << "0. Exit" << endl;
}

int Admindatabase::getUserChoice() {
	int choice;
	cout << "Select option (0 to exit): ";
	cin >> choice;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return choice;
}

void Admindatabase::displayMessage(const string& message) {
	cout << message << endl;
}