// Header.h
#pragma once
#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <limits>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Utilities {
private:
    string bills;
    string challan;
    string spinwheelPrize;
    string ticket;
    string travel;
    string loan;
    string education;
    string insurance;
public:
    Utilities() {
        bills = "";
        challan = "";
        spinwheelPrize = "Not played yet";
        ticket = "";
        travel = "";
        loan = "";
        education = "";
        insurance = "";
    }

    Utilities(string b, string c, string sp, string t, string tr, string l, string e, string i) {
        bills = b;
        challan = c;
        spinwheelPrize = sp;
        ticket = t;
        travel = tr;
        loan = l;
        education = e;
        insurance = i;
    }
    const string& getBills() const { return bills; }
    const string& getChallan() const { return challan; }
    const string& getTicket() const { return ticket; }
    const string& getTravel() const { return travel; }
    const string& getLoan() const { return loan; }
    const string& getEducation() const { return education; }
    const string& getInsurance() const { return insurance; }
    const string& getSpinwheelPrize() const { return spinwheelPrize; }

    void setBills(const string& b) { bills = b; }
    void setChallan(const string& c) { challan = c; }
    void setTicket(const string& t) { ticket = t; }
    void setTravel(const string& tr) { travel = tr; }
    void setLoan(const string& l) { loan = l; }
    void setEducation(const string& e) { education = e; }
    void setInsurance(const string& i) { insurance = i; }
    void setSpinwheelPrize(const string& sp) { spinwheelPrize = sp; }

    // File handling for Utilities
    void saveToFile(const string& filename) {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            outFile << bills << "|" << challan << "|" << spinwheelPrize << "|"
                    << ticket << "|" << travel << "|" << loan << "|"
                    << education << "|" << insurance << endl;
            outFile.close();

        } else {
        }
    }

    void loadFromFile(const string& filename) {
        ifstream inFile(filename);
        if (inFile.is_open()) {
            string line;
            if (getline(inFile, line)) {
                stringstream ss(line);
                getline(ss, bills, '|');
                getline(ss, challan, '|');
                getline(ss, spinwheelPrize, '|');
                getline(ss, ticket, '|');
                getline(ss, travel, '|');
                getline(ss, loan, '|');
                getline(ss, education, '|');
                getline(ss, insurance);
            }
            inFile.close();
            // cout << "Utilities data loaded successfully." << endl; // Optional: for debugging
        } else {
            // cout << "No saved utilities data found. Starting with default." << endl; // Optional: for debugging
        }
    }
};

class Account {
private:
    string customerName;
    string customerCnic;
    string accountType;
    string accountNumber;
    double balance;
    string password;
    bool isFrozen;

public:
    Account(string name, string cnic, string type, string number, double bal, string pwd)
        : customerName(name), customerCnic(cnic), accountType(type), accountNumber(number), balance(bal), password(pwd), isFrozen(false) {}

    const string& getCustomerName() const { return customerName; }
    const string& getCustomerCnic() const { return customerCnic; }
    const string& getAccountType() const { return accountType; }
    const string& getAccountNumber() const { return accountNumber; }
    double getBalance() const { return balance; }
    const string& getPassword() const { return password; }
    bool getIsFrozen() const { return isFrozen; }
    bool getIsFrozenForFile() const { return isFrozen; }

    void deposit(double amount) {
        if (!isFrozen) {
            balance += amount;
            cout << "Deposited " << amount << ". New balance: " << balance << endl;
        } else {
            cout << "Account is frozen. Cannot deposit." << endl;
        }
    }

    bool withdraw(double amount) {
        if (!isFrozen) {
            if (balance >= amount) {
                balance -= amount;
                cout << "Withdrew " << amount << ". New balance: " << balance << endl;
            } else {
                cout << "Insufficient balance." << endl;
            }
        } else {
            cout << "Account is frozen. Cannot withdraw." << endl;
        }
    }

    void freeze() {
        isFrozen = true;
        cout << "Account " << accountNumber << " has been frozen." << endl;
    }

    void unfreeze() {
        isFrozen = false;
        cout << "Account " << accountNumber << " has been unfrozen." << endl;
    }

    void getType();

    Account * verifyPin(const string & pwd);
};

class BankSystem {
private:

    vector<string> customerCNICs;

    string generateAccountNumber() {
        string accNum;
        bool unique = false;
        while (!unique) {
            accNum = "";
            for (int i = 0; i < 16; i++) {
                int digit = rand() % 10;
                accNum += to_string(digit);
            }
            unique = true;
            for (Account* acc : accounts) {
                if (acc->getAccountNumber() == accNum) {
                    unique = false;
                    break;
                }
            }
        }
        return accNum;
    }

public:
    vector<Account*> accounts;
    ~BankSystem() {
        for (Account* acc : accounts) {
            delete acc;
        }
    }

    void createAccount() {
        string name, cnic, type, password;
        double balance;

        cout << "Enter customer name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter customer CNIC: ";
        getline(cin, cnic);
        cout << "Enter account type (e.g., Savings, Current): ";
        getline(cin, type);
        cout << "Enter initial balance: ";
        cin >> balance;
        cout << "Set password for the account: ";
        cin.ignore();
        getline(cin, password);

        string number = generateAccountNumber();
        Account* newAccount = new Account(name, cnic, type, number, balance, password);
        accounts.push_back(newAccount);
        customerCNICs.push_back(cnic);
        cout << "Account created successfully! Your account number is: " << number << endl;
    }

    Account* findAccount(const string& accountNumber) {
        for (Account* acc : accounts) {
            if (acc->getAccountNumber() == accountNumber) {
                return acc;
            }
        }
        return nullptr;
    }

    Account* login(const string& accountNumber, const string& password) {

        for (Account* acc : accounts) {
            if (acc->getAccountNumber() == accountNumber) {
                if (acc->getPassword() == password) {

                    if (!acc->getIsFrozen()) {
                        cout << "Login successful for account " << accountNumber << endl;
                        return acc;
                    } else {
                        cout << "Account " << accountNumber << " is frozen. Please contact bank for assistance." << endl;
                        return nullptr;
                    }
                } else {
                    cout << "Incorrect password for account " << accountNumber << endl;
                    return nullptr;
                }
            }
        }

        // If the loop finishes, it means no account with the given accountNumber was found
        cout << "Account " << accountNumber << " not found." << endl;
        return nullptr;
    }

    void viewCustomerAccounts() {
        if (accounts.empty()) {
            cout << "No accounts to display." << endl;
            return;
        }
        cout << "--- All Customer Accounts ---" << endl;
        for (Account* acc : accounts) {
            cout << "Name: " << acc->getCustomerName()
                 << ", CNIC: " << acc->getCustomerCnic()
                 << ", Account Number: " << acc->getAccountNumber()
                 << ", Type: " << acc->getAccountType()
                 << ", Balance: " << fixed << setprecision(2) << acc->getBalance()
                 << ", Frozen: " << (acc->getIsFrozen() ? "Yes" : "No") << endl;
        }
    }

    void freezeAccount(const string& accountNumber) {
        Account* acc = findAccount(accountNumber);
        if (acc) {
            acc->freeze();
        } else {
            cout << "Account not found." << endl;
        }
    }

    void unfreezeAccount(const string& accountNumber) {
        Account* acc = findAccount(accountNumber);
        if (acc) {
            acc->unfreeze();
        } else {
            cout << "Account not found." << endl;
        }
    }

    void saveAccountsToFile(const string& filename) {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            for (Account* acc : accounts) {
                outFile << acc->getCustomerName() << "|"
                        << acc->getCustomerCnic() << "|"
                        << acc->getAccountType() << "|"
                        << acc->getAccountNumber() << "|"
                        << acc->getBalance() << "|"
                        << acc->getPassword() << "|"
                        << (acc->getIsFrozen() ? "1" : "0") << endl;
            }
            outFile.close();
            cout << "Account data saved successfully." << endl;
        } else {
            cout << "Error: Unable to open file for writing account data." << endl;
        }
    }

    void loadAccountsFromFile(const string& filename) {
        ifstream inFile(filename);
        if (inFile.is_open()) {
            string line;
            while (getline(inFile, line)) {
                stringstream ss(line);
                string name, cnic, type, number, password, balanceStr, isFrozenStr;
                double balance;
                bool isFrozen;

                getline(ss, name, '|');
                getline(ss, cnic, '|');
                getline(ss, type, '|');
                getline(ss, number, '|');
                getline(ss, balanceStr, '|');
                getline(ss, password, '|');
                getline(ss, isFrozenStr);

                balance = stod(balanceStr);
                isFrozen = (isFrozenStr == "1");

                Account* loadedAccount = new Account(name, cnic, type, number, balance, password);
                if (isFrozen) {
                    loadedAccount->freeze();
                }
                accounts.push_back(loadedAccount);
                customerCNICs.push_back(cnic);
            }
            inFile.close();
            cout << "Account data loaded successfully." << endl;
        } else {
            cout << "No saved account data found. Starting with an empty system." << endl;
        }
    }

    Account * getAccount(const string & string);
};

class ATM {
private:
    string cardNumber;
    string pin;
    bool isActivated;

    string generateCardNumber() {
        string cardNum = "";
        for (int i = 0; i < 16; i++) {
            int digit = rand() % 10;
            cardNum = cardNum + to_string(digit);
        }
        return cardNum;
    }

public:
    ATM() {
        cardNumber = "";
        pin = "";
        isActivated = false;
    }

    void SetupCard() {
        cardNumber = generateCardNumber();
        cout << "Generated Card Number: " << cardNumber << endl;
        cout << "Set your 4-digit PIN: ";
        cin >> pin;
        isActivated = false;
        cout << "Card setup complete. Please activate your card." << endl;
    }

    void ActivateCard() {
        if(cardNumber != "" && pin != "") {
            isActivated = true;
            cout << "Card has been successfully activated." << endl;
        } else {
            cout << "Please setup the card first." << endl;
        }
    }

    void DeActivateCard() {
        isActivated = false;
        cout << "Card has been deactivated." << endl;
    }

    bool VerifyPIN(string enteredPin) const {
        return isActivated && (enteredPin == pin);
    }

    void saveToFile(const string& filename) {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            outFile << cardNumber << endl;
            outFile << pin << endl;
            outFile << isActivated << endl;
            outFile.close();
            cout << "Card information saved successfully." << endl;
        } else {
            cout << "Error: Unable to open file for writing." << endl;
        }
    }

    void loadFromFile(const string& filename) {
        ifstream inFile(filename);
        if (inFile.is_open()) {
            getline(inFile, cardNumber);
            getline(inFile, pin);
            string isActivatedStr;
            getline(inFile, isActivatedStr);
            isActivated = (isActivatedStr == "1");
            inFile.close();
            cout << "Card information loaded successfully." << endl;
        } else {
            cout << "No saved card data found. Please setup a new card." << endl;
        }
    }

    // Getters
    string getCardNumber() const { return cardNumber; }
    string getPin() const { return pin; }
    bool getIsActivated() const { return isActivated; }
};

class Calculator {
private:
    double totalWealth;
    int familyMembers;
    double fitraRate;
    double nisabThreshold;
    double monthlyInstallment;
    double fitraana;
    double zakat;
public:
    Calculator() {
        totalWealth = 0.0;
        familyMembers = 0;
        fitraRate = 0.0;
        nisabThreshold = 0.0;
        monthlyInstallment = 0.0;
        fitraana = 0.0;
        zakat = 0.0;
    }
    Calculator(double wealth, int members, double fitra, double nisab, double installment)
        : totalWealth(wealth), familyMembers(members), fitraRate(fitra), nisabThreshold(nisab), monthlyInstallment(installment) {
        fitraana = 0.0;
        zakat = 0.0;
    }
    double getTotalWealth() const { return totalWealth; }
    int getFamilyMembers() const { return familyMembers; }
    double getFitraRate() const { return fitraRate; }
    double getNisabThreshold() const { return nisabThreshold; }
    double getMonthlyInstallment() const { return monthlyInstallment; }
    void setTotalWealth(double wealth) { totalWealth = wealth; }
    void setFamilyMembers(int members) { familyMembers = members; }
    void setFitraRate(double fitra) { fitraRate = fitra; }
    void setNisabThreshold(double nisab) { nisabThreshold = nisab; }
    void setMonthlyInstallment(double installment) { monthlyInstallment = installment; }
    void calculateFitra() {
        fitraana = familyMembers * fitraRate;
    }
    void calculateZakat() {
        if (totalWealth >= nisabThreshold) {
            zakat = 0.025 * totalWealth;
        } else {
            zakat = 0;
        }
    }
    double getFitraana() const { return fitraana; }
    double getZakat() const { return zakat; }

    // File handling for Calculator
    void saveToFile(const string& filename) {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            outFile << totalWealth << endl;
            outFile << familyMembers << endl;
            outFile << fitraRate << endl;
            outFile << nisabThreshold << endl;
            outFile << monthlyInstallment << endl;
            outFile.close();

        } else {
        }
    }

    void loadFromFile(const string& filename) {
        ifstream inFile(filename);
        if (inFile.is_open()) {
            inFile >> totalWealth;
            inFile >> familyMembers;
            inFile >> fitraRate;
            inFile >> nisabThreshold;
            inFile >> monthlyInstallment;
            inFile.close();
            // cout << "Calculator data loaded successfully." << endl; // Optional: for debugging
        } else {
            // cout << "No saved calculator data found. Starting with default." << endl;
        }
    }
};

class Admin {
private:
    string username;
    string password;
    string billType;
    double totalBill;
    string challanType;
    double totalChallan;
    bool freezeAccount;
    bool deleteAccount;

public:
    Admin(string user, string pass) : username(user), password(pass), billType(""), totalBill(0.0), challanType(""), totalChallan(0.0), freezeAccount(false), deleteAccount(false) {}

    string getUsername() const { return username; }
    string getPassword() const { return password; }
    string getBillType() const { return billType; }
    double getTotalBill() const { return totalBill; }
    string getChallanType() const { return challanType; }
    double getTotalChallan() const { return totalChallan; }
    bool getFreezeAccount() const { return freezeAccount; }
    bool getDeleteAccount() const { return deleteAccount; }

    void setBillDetails(string type, double amount) {
        billType = type;
        totalBill = amount;
    }

    void setChallanDetails(string type, double amount) {
        challanType = type;
        totalChallan = amount;
    }

    void setFreezeAccount(bool freeze) {
        freezeAccount = freeze;
    }

    void setDeleteAccount(bool del) {
        deleteAccount = del;
    }

    // File handling for Admin
    void saveToFile(const string& filename) {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            outFile << username << endl;
            outFile << password << endl;
            outFile << billType << endl;
            outFile << totalBill << endl;
            outFile << challanType << endl;
            outFile << totalChallan << endl;
            outFile << freezeAccount << endl;
            outFile << deleteAccount << endl;
            outFile.close();
            // cout << "Admin data saved successfully." << endl; // Optional: for debugging
        } else {
            // cout << "Error: Unable to open file for writing admin data." << endl; // Optional: for debugging
        }
    }

    void loadFromFile(const string& filename) {
        ifstream inFile(filename);
        if (inFile.is_open()) {
            string line;
            getline(inFile, username);
            getline(inFile, password);
            getline(inFile, billType);
            inFile >> totalBill;
            inFile.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(inFile, challanType);
            inFile >> totalChallan;
            inFile.ignore(numeric_limits<streamsize>::max(), '\n');
            string freezeAccountStr, deleteAccountStr;
            getline(inFile, freezeAccountStr);
            getline(inFile, deleteAccountStr);
            freezeAccount = (freezeAccountStr == "1");
            deleteAccount = (deleteAccountStr == "1");
            inFile.close();
            // cout << "Admin data loaded successfully." << endl; // Optional: for debugging
        } else {
            // cout << "No saved admin data found. Starting with default." << endl; // Optional: for debugging
        }
    }
};

#endif