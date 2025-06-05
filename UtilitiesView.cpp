// UtilitiesView.cpp
#include "UtilitiesView.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

void UtilitiesView::showMenu(const string& bills,
    const string& challan,
    const string& ticket,
    const string& travel,
    const string& loan,
    const string& education,
    const string& insurance,
    const string& spinPrize) {
    cout << "=== Pay Utilities ===" << endl;
    cout << "1. Electricity bill    : " << bills << endl;
    cout << "2. Challan             : " << challan << endl;
    cout << "3. Ticket              : " << ticket << endl;
    cout << "4. Travel              : " << travel << endl;
    cout << "5. Loan                : " << loan << endl;
    cout << "6. Education           : " << education << endl;
    cout << "7. Insurance           : " << insurance << endl;
    cout << "8. Spin the Wheel      : "
        << (spinPrize.empty() ? "Not played yet" : spinPrize) << endl;
    cout << "0. Exit" << endl;
}

int UtilitiesView::getUserChoice() {
    int choice;
    cout << "Select option (0 to exit): ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return choice;
}

void UtilitiesView::waitForSpin() {
    cout << "Press Enter to stop the spin..." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void UtilitiesView::displayMessage(const string& msg) {
    cout << msg << endl;
}

void CalculatorView::showMenu(const string& totalwealth,
    const string& familymembers,
    const string& fitraRate,
    const string& nisabthreshold,
    const string& monthlyInstallment) {
    cout << "=== Calculator ===" << endl;
    cout << "Total Wealth      : " << totalwealth << endl;
    cout << "Family Members    : " << familymembers << endl;
    cout << "Fitra Rate        : " << fitraRate << endl;
    cout << "Nisab Threshold   : " << nisabthreshold << endl;
    cout << "Monthly Installment: " << monthlyInstallment << endl;
    cout << "0. Exit" << endl;
}

int CalculatorView::getUserChoice() {
    int choice;
    cout << "Select option (0 to exit): ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return choice;
}

void ATMview::showMenu(const string& cardNumber,
    const string& pin,
    const string& isActivated) {
    cout << "=== ATM Details ===" << endl;
    cout << "Card Number  : " << cardNumber << endl;
    cout << "PIN          : " << pin << endl;
    cout << "Is Activated : " << isActivated << endl;
    cout << "0. Exit" << endl;
}

int ATMview::getUserChoice() {
    int choice;
    cout << "Select option (0 to exit): ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return choice;
}

void showInfo(
    const string& customerName,
    const string& customerCnic,
    const string& type,
    const string& number,
    const string& balance,
    const string& frozen
) {
    cout << "=== Account Information ===" << endl;
    cout << "Customer Name : " << customerName << endl;
    cout << "Customer CNIC : " << customerCnic << endl;
    cout << "Account Type  : " << type << endl;
    cout << "Account Number: " << number << endl;
    cout << "Balance       : " << balance << endl;
    cout << "Frozen Status : " << frozen << endl;
}

void Accountview::showInfo(
    const string& customerName,
    const string& customerCnic,
    const string& type,
    const string& number,
    const string& balance,
    const string& frozen
) {
    cout << "=== Account Information ===" << endl;
    cout << "Customer Name : " << customerName << endl;
    cout << "Customer CNIC : " << customerCnic << endl;
    cout << "Account Type  : " << type << endl;
    cout << "Account Number: " << number << endl;
    cout << "Balance       : " << balance << endl;
    cout << "Frozen Status : " << frozen << endl;
}

void Accountview::displayMessage(const string& message) {
    cout << message << endl;
}

int Accountview::getUserChoice() {
    int choice;
    cout << "Select option (0 to exit): ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return choice;
}

void BankSystemview::showMenu(map<string, Account*> accounts,
    map<string, int> customerAccounts) {
    cout << "=== Bank System Overview ===" << endl;
    cout << "Total number of customers: " << customerAccounts.size() << endl;
    cout << "Number of accounts: " << accounts.size() << endl;
    cout << "Customer Accounts:" << endl;
    for (const auto& accPair : customerAccounts) {
        cout << "CNIC: " << accPair.first << ", Number of Accounts: " << accPair.second << endl;
    }
}

int BankSystemview::getUserChoice()
{
	int choice;
	cout << "Select option (0 to exit): ";
	cin >> choice;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return choice;
}
void BankSystemview::displayMessage(const string& message)
{
	cout << message << endl;
}

void Adminview::showMenu(const string& username, const string& password, const string& bill_type, int total_bill, const string& challan_type, int total_challan, bool freeze_account, bool delete_account) {
	cout << "=== Admin Menu ===" << endl;
	cout << "Username: " << username << endl;
	cout << "Password: " << password << endl;
	cout << "Bill Type: " << bill_type << ", Total Bill: " << total_bill << endl;
	cout << "Challan Type: " << challan_type << ", Total Challan: " << total_challan << endl;
	cout << "Freeze Account: " << (freeze_account ? "Yes" : "No") << ", Delete Account: " << (delete_account ? "Yes" : "No") << endl;
	cout << "0. Exit" << endl;
}

int Adminview::getUserChoice() {
	int choice;
	cout << "Select option (0 to exit): ";
	cin >> choice;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return choice;
}

void Adminview::displayMessage(const string& message) {
	cout << message << endl;
}