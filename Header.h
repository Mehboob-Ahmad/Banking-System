#pragma once
#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;

class Account;
class BankSystem;

class Savable {
public:
    virtual void saveToFile(const string& filename) const = 0;
    virtual void loadFromFile(const string& filename) = 0;
    virtual ~Savable() = default;
};

class Utilities : public Savable {
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

    Utilities(string b, string c, string sp, string t, string tr, string l, string e, string i)
        : bills(b), challan(c), spinwheelPrize(sp), ticket(t), travel(tr), loan(l), education(e), insurance(i) {}

    string getBills() const { return bills; }
    string getChallan() const { return challan; }
    string getSpinwheelPrize() const { return spinwheelPrize; }
    string getTicket() const { return ticket; }
    string getTravel() const { return travel; }
    string getLoan() const { return loan; }
    string getEducation() const { return education; }
    string getInsurance() const { return insurance; }

    void setBills(const string& b) { bills = b; }
    void setChallan(const string& c) { challan = c; }
    void setSpinwheelPrize(const string& sp) { spinwheelPrize = sp; }
    void setTicket(const string& t) { ticket = t; }
    void setTravel(const string& tr) { travel = tr; }
    void setLoan(const string& l) { loan = l; }
    void setEducation(const string& e) { education = e; }
    void setInsurance(const string& i) { insurance = i; }

    void saveToFile(const string& filename) const override {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            outFile << bills << endl;
            outFile << challan << endl;
            outFile << spinwheelPrize << endl;
            outFile << ticket << endl;
            outFile << travel << endl;
            outFile << loan << endl;
            outFile << education << endl;
            outFile << insurance << endl;
            outFile.close();
        } else {
            cerr << "Error: Unable to open file for writing utilities data: " << filename << endl;
        }
    }

    void loadFromFile(const string& filename) override {
        ifstream inFile(filename);
        if (inFile.is_open()) {
            getline(inFile, bills);
            getline(inFile, challan);
            getline(inFile, spinwheelPrize);
            getline(inFile, ticket);
            getline(inFile, travel);
            getline(inFile, loan);
            getline(inFile, education);
            getline(inFile, insurance);
            inFile.close();
        } else {
            bills = "";
            challan = "";
            spinwheelPrize = "Not played yet";
            ticket = "";
            travel = "";
            loan = "";
            education = "";
            insurance = "";
            cerr << "Warning: Unable to open file for reading utilities data: " << filename << ". Initializing with defaults." << endl;
        }
    }
};

class Calculator : public Savable {
private:
    string totalWealth;
    string familyMembers;
    string fitraRate;
    string nisabThreshold;
    string monthlyInstallment;

public:
    Calculator() {
        totalWealth = "";
        familyMembers = "";
        fitraRate = "";
        nisabThreshold = "";
        monthlyInstallment = "";
    }

    Calculator(string tw, string fm, string fr, string nt, string mi)
        : totalWealth(tw), familyMembers(fm), fitraRate(fr), nisabThreshold(nt), monthlyInstallment(mi) {}

    string getTotalWealth() const { return totalWealth; }
    string getFamilyMembers() const { return familyMembers; }
    string getFitraRate() const { return fitraRate; }
    string getNisabThreshold() const { return nisabThreshold; }
    string getMonthlyInstallment() const { return monthlyInstallment; }

    void setTotalWealth(const string& tw) { totalWealth = tw; }
    void setFamilyMembers(const string& fm) { familyMembers = fm; }
    void setFitraRate(const string& fr) { fitraRate = fr; }
    void setNisabThreshold(const string& nt) { nisabThreshold = nt; }
    void setMonthlyInstallment(const string& mi) { monthlyInstallment = mi; }

    void saveToFile(const string& filename) const override {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            outFile << totalWealth << endl;
            outFile << familyMembers << endl;
            outFile << fitraRate << endl;
            outFile << nisabThreshold << endl;
            outFile << monthlyInstallment << endl;
            outFile.close();
        } else {
            cerr << "Error: Unable to open file for writing calculator data: " << filename << endl;
        }
    }

    void loadFromFile(const string& filename) override {
        ifstream inFile(filename);
        if (inFile.is_open()) {
           getline(inFile, totalWealth);
           getline(inFile, familyMembers);
           getline(inFile, fitraRate);
           getline(inFile, nisabThreshold);
           getline(inFile, monthlyInstallment);
            inFile.close();
        } else {
            totalWealth = "";
            familyMembers = "";
            fitraRate = "";
            nisabThreshold = "";
            monthlyInstallment = "";
            cerr << "Warning: Unable to open file for reading calculator data: " << filename << ". Initializing with defaults." <<endl;
        }
    }
};

class Admin : public Savable {
private:
    string username;
    string password;
    string billType;
    double totalBill;
    string challanType;
    double totalChallan;
    bool freezeAccountFlag;
    bool deleteAccountFlag;

public:
    Admin() : username("admin"), password("admin"), billType(""), totalBill(0.0), challanType(""), totalChallan(0.0), freezeAccountFlag(false), deleteAccountFlag(false) {}

    Admin(string u, string p, string bt, double tb, string ct, double tc, bool faf, bool daf)
        : username(u), password(p), billType(bt), totalBill(tb), challanType(ct), totalChallan(tc), freezeAccountFlag(faf), deleteAccountFlag(daf) {}

    string getUsername() const { return username; }
    string getPassword() const { return password; }
    string getBillType() const { return billType; }
    double getTotalBill() const { return totalBill; }
    string getChallanType() const { return challanType; }
    double getTotalChallan() const { return totalChallan; }
    bool getFreezeAccountFlag() const { return freezeAccountFlag; }
    bool getDeleteAccountFlag() const { return deleteAccountFlag; }

    void setUsername(const string& u) { username = u; }
    void setPassword(const string& p) { password = p; }
    void setBillDetails(const string& type, double amount) { billType = type; totalBill = amount; }
    void setChallanDetails(const string& type, double amount) { challanType = type; totalChallan = amount; }
    void setFreezeAccountFlag(bool faf) { freezeAccountFlag = faf; }
    void setDeleteAccountFlag(bool daf) { deleteAccountFlag = daf; }

    void saveToFile(const string& filename) const override {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            outFile << username << endl;
            outFile << password << endl;
            outFile << billType << endl;
            outFile << totalBill << endl;
            outFile << challanType << endl;
            outFile << totalChallan << endl;
            outFile << (freezeAccountFlag ? "1" : "0") << endl;
            outFile << (deleteAccountFlag ? "1" : "0") << endl;
            outFile.close();
        } else {
            cerr << "Error: Unable to open file for writing admin data: " << filename << endl;
        }
    }

    void loadFromFile(const string& filename) override {
        ifstream inFile(filename);
        if (inFile.is_open()) {
            string faf_str, daf_str;
            getline(inFile, username);
            getline(inFile, password);
            getline(inFile, billType);
            inFile >> totalBill;
            inFile.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(inFile, challanType);
            inFile >> totalChallan;
            inFile.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(inFile, faf_str);
            getline(inFile, daf_str);
            freezeAccountFlag = (faf_str == "1");
            deleteAccountFlag = (daf_str == "1");
            inFile.close();
        } else {
            username = "admin";
            password = "admin";
            billType = "";
            totalBill = 0.0;
            challanType = "";
            totalChallan = 0.0;
            freezeAccountFlag = false;
            deleteAccountFlag = false;
            cerr << "Warning: Unable to open file for reading admin data: " << filename << ". Initializing with defaults." << endl;
        }
    }
};

class ATM : public Savable {
private:
    string cardNumber;
    string pin;
    bool isActivated;

public:
    ATM() : cardNumber(""), pin(""), isActivated(false) {}
    ATM(string cn, string p, bool ia) : cardNumber(cn), pin(p), isActivated(ia) {}

    string getCardNumber() const { return cardNumber; }
    string getPin() const { return pin; }
    bool getIsActivated() const { return isActivated; }

    void setCardNumber(const string& cn) { cardNumber = cn; }
    void setPin(const string& p) { pin = p; }
    void setIsActivated(bool ia) { isActivated = ia; }

    void saveToFile(const string& filename) const override {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            outFile << cardNumber << endl;
            outFile << pin << endl;
            outFile << (isActivated ? "1" : "0") << endl;
            outFile.close();
        } else {
            cerr << "Error: Unable to open file for writing ATM data: " << filename << endl;
        }
    }

    void loadFromFile(const string& filename) override {
        ifstream inFile(filename);
        if (inFile.is_open()) {
            string ia_str;
            getline(inFile, cardNumber);
            getline(inFile, pin);
            getline(inFile, ia_str);
            isActivated = (ia_str == "1");
            inFile.close();
        } else {
            cardNumber = "";
            pin = "";
            isActivated = false;
            cerr << "Warning: Unable to open file for reading ATM data: " << filename << ". Initializing with defaults." << endl;
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
    string loginPin;
    bool isFrozen;

public:
    Account(string name, string cnic, string type, string accNum, double bal, string pin)
        : customerName(name), customerCnic(cnic), accountType(type), accountNumber(accNum), balance(bal), loginPin(pin), isFrozen(false) {}

    string getCustomerName() const { return customerName; }
    string getCustomerCnic() const { return customerCnic; }
    string getAccountType() const { return accountType; }
    string getAccountNumber() const { return accountNumber; }
    double getBalance() const { return balance; }
    string getLoginPin() const { return loginPin; }
    bool getIsFrozen() const { return isFrozen; }

    void setBalance(double bal) { balance = bal; }
    void setIsFrozen(bool frozen) { isFrozen = frozen; }
    void setLoginPin(const string& pin) { loginPin = pin; }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << ". New balance: " << balance << endl;
        } else {
            cout << "Deposit amount must be positive." << endl;
        }
    }

    bool withdraw(double amount) {
        if (isFrozen) {
            cout << "Account is frozen. Cannot withdraw." << endl;
            return false;
        }
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            cout << "Withdrew: " << amount << ". New balance: " << balance << endl;
            return true;
        } else if (amount <= 0) {
            cout << "Withdrawal amount must be positive." << endl;
            return false;
        } else {
            cout << "Insufficient balance." << endl;
            return false;
        }
    }
};

class LoanTracker : public Savable {
private:
    int totalInstallments;
    int paidInstallments;
    int loanDuration;
    time_t startDate;
    string linkedAccountNumber;

public:
    LoanTracker() {
        totalInstallments = 0;
        paidInstallments = 0;
        loanDuration = 30;
        startDate = time(0);
        linkedAccountNumber = "";
    }

    LoanTracker(int totalInst, int paidInst, int duration, time_t start, Account* acc) {
        totalInstallments = totalInst;
        paidInstallments = paidInst;
        loanDuration = duration;
        startDate = start;
        if (acc) {
            linkedAccountNumber = acc->getAccountNumber();
        } else {
            linkedAccountNumber = "";
        }
    }

    LoanTracker(int totalInst, int paidInst, int duration, time_t start, const string& accNum) {
        totalInstallments = totalInst;
        paidInstallments = paidInst;
        loanDuration = duration;
        startDate = start;
        linkedAccountNumber = accNum;
    }


    void makeInstallmentPayment(double amount, Account* account) {
        if (!account) {
            cout << "Error: No account linked to this loan tracker." << endl;
            return;
        }
        if (paidInstallments < totalInstallments) {
            paidInstallments++;
            account->setBalance(account->getBalance() - amount);
            cout << "Installment " << paidInstallments << "/" << totalInstallments << endl;
        } else {
            cout << "Loan already paid." << endl;
        }
    }

    void checkLoanStatus() {
        time_t now = time(0);
        double secondsElapsed = difftime(now, startDate);
        int daysElapsed = static_cast<int>(secondsElapsed / (3600 * 24));

        cout << "Loan started on: " << ctime(&startDate);
        cout << "Days elapsed: " << daysElapsed << "/" << loanDuration << endl;

        if (paidInstallments == totalInstallments) {
            if (daysElapsed > loanDuration) {
                int overduedays = daysElapsed - loanDuration;
                int penalty = overduedays * 100;
                cout << "Loan paid but was overdue by " << overduedays << " days." << endl;
                cout << "Penalty to pay: " << penalty << " Rs" << endl;
            } else {
                cout << "Loan paid on time." << endl;
            }
        } else {
            cout << "Installments paid: " << paidInstallments << " of " << totalInstallments << endl;
            if (daysElapsed > loanDuration) {
                cout << "Loan is overdue!" << endl;
            } else {
                cout << "Loan is active and on time." << endl;
            }
        }
    }

    void saveToFile(const string& filename) const override {
        ofstream outFile(filename, ios::app); // Open in append mode
        if (outFile.is_open()) {
            outFile << linkedAccountNumber << endl;
            outFile << totalInstallments << endl;
            outFile << paidInstallments << endl;
            outFile << loanDuration << endl;
            outFile << startDate << endl;
            outFile.close();
        } else {
            cerr << "Error: Unable to open file for writing loan tracker data: " << filename << endl;
        }
    }

    void loadFromFile(const string& filename) override {
        // This method is primarily handled by BankSystem's loadFromFile for LoanTrackers
        // Individual loan trackers don't load themselves from a file directly.
        // It's part of the BankSystem's overall loading process.
    }

    int getTotalInstallments() const { return totalInstallments; }
    int getPaidInstallments() const { return paidInstallments; }
    int getLoanDuration() const { return loanDuration; }
    time_t getStartDate() const { return startDate; }
    string getLinkedAccountNumber() const { return linkedAccountNumber; }

    void setLinkedAccountNumber(const string& accNum) { linkedAccountNumber = accNum; }
};


class BankSystem : public Savable {
private:
    vector<Account*> accounts;
    vector<LoanTracker*> loanTrackers;

public:
    BankSystem() = default;

    ~BankSystem() {
        for (Account* acc : accounts) {
            delete acc;
        }
        for (LoanTracker* loan : loanTrackers) {
            delete loan;
        }
    }

    Account* createAccount(string name, string cnic, string type, string pin) {
        string accNum = "ACC" + to_string(accounts.size() + 1001);
        Account* newAccount = new Account(name, cnic, type, accNum, 0.0, pin);
        accounts.push_back(newAccount);
        cout << "Account created successfully! Account Number: " << accNum << endl;
        return newAccount;
    }

    Account* getAccount(const string& accNum) {
        for (Account* acc : accounts) {
            if (acc->getAccountNumber() == accNum) {
                return acc;
            }
        }
        return nullptr;
    }

    bool authenticateAccount(const string& accNum, const string& pin) {
        Account* account = getAccount(accNum);
        if (account && account->getLoginPin() == pin) {
            return true;
        }
        return false;
    }

    bool freezeAccount(const string& accNum) {
        Account* account = getAccount(accNum);
        if (account) {
            account->setIsFrozen(true);
            return true;
        }
        return false;
    }

    bool unfreezeAccount(const string& accNum) {
        Account* account = getAccount(accNum);
        if (account) {
            account->setIsFrozen(false);
            return true;
        }
        return false;
    }

    bool deleteAccount(const string& accNum) {
        for (size_t i = 0; i < accounts.size(); ++i) {
            if (accounts[i]->getAccountNumber() == accNum) {
                delete accounts[i];
                accounts.erase(accounts.begin() + i);

                for (size_t j = 0; j < loanTrackers.size(); ++j) {
                    if (loanTrackers[j]->getLinkedAccountNumber() == accNum) {
                        delete loanTrackers[j];
                        loanTrackers.erase(loanTrackers.begin() + j);
                        break;
                    }
                }
                return true;
            }
        }
        return false;
    }

    LoanTracker* getLoanTracker(const string& accNum) {
        for (LoanTracker* loan : loanTrackers) {
            if (loan->getLinkedAccountNumber() == accNum) {
                return loan;
            }
        }
        return nullptr;
    }

    void addLoanTracker(const string& accNum, LoanTracker* loan) {
        for (size_t i = 0; i < loanTrackers.size(); ++i) {
            if (loanTrackers[i]->getLinkedAccountNumber() == accNum) {
                delete loanTrackers[i];
                loanTrackers.erase(loanTrackers.begin() + i);
                break;
            }
        }
        loanTrackers.push_back(loan);
    }

    void removeLoanTracker(const string& accNum) {
        for (size_t i = 0; i < loanTrackers.size(); ++i) {
            if (loanTrackers[i]->getLinkedAccountNumber() == accNum) {
                delete loanTrackers[i];
                loanTrackers.erase(loanTrackers.begin() + i);
                return;
            }
        }
    }


    void saveToFile(const string& filename) const override {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            outFile << accounts.size() << endl;
            for (Account* val : accounts) {
                outFile << val->getCustomerName() << endl;
                outFile << val->getCustomerCnic() << endl;
                outFile << val->getAccountType() << endl;
                outFile << val->getAccountNumber() << endl;
                outFile << val->getBalance() << endl;
                outFile << (val->getIsFrozen() ? "1" : "0") << endl;
                outFile << val->getLoginPin() << endl;
            }

            outFile << loanTrackers.size() << endl;
            for (LoanTracker* val : loanTrackers) {
                // Call LoanTracker's own saveToFile method which will append to the same file
                val->saveToFile(filename);
            }

            outFile.close();
        } else {
            cerr << "Error: Unable to open file for writing bank system data: " << filename << endl;
        }
    }

    void loadFromFile(const string& filename) override {
        for (Account* acc : accounts) {
            delete acc;
        }
        accounts.clear();

        for (LoanTracker* loan : loanTrackers) {
            delete loan;
        }
        loanTrackers.clear();

        ifstream inFile(filename);
        if (inFile.is_open()) {
            size_t numAccounts;
            inFile >> numAccounts;
            inFile.ignore(numeric_limits<streamsize>::max(), '\n');

            for (size_t i = 0; i < numAccounts; ++i) {
                string name, cnic, type, accNum, frozenStr, loadedPin;
                double balance;

                getline(inFile, name);
                getline(inFile, cnic);
                getline(inFile, type);
                getline(inFile, accNum);
                inFile >> balance;
                inFile.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(inFile, frozenStr);
                getline(inFile, loadedPin);

                Account* newAccount = new Account(name, cnic, type, accNum, balance, loadedPin);
                newAccount->setIsFrozen(frozenStr == "1");
                accounts.push_back(newAccount);
            }

            size_t numLoans;
            inFile >> numLoans;
            inFile.ignore(numeric_limits<streamsize>::max(), '\n');

            for (size_t i = 0; i < numLoans; ++i) {
                string accNum;
                int totalInst, paidInst, duration;
                time_t start;

                getline(inFile, accNum);
                inFile >> totalInst >> paidInst >> duration >> start;
                inFile.ignore(numeric_limits<streamsize>::max(), '\n');

                LoanTracker* loan = new LoanTracker(totalInst, paidInst, duration, start, accNum);
                loanTrackers.push_back(loan);
            }
            inFile.close();
        } else {
            cerr << "Warning: Unable to open file for reading bank system data: " << filename << ". Initializing with defaults." << endl;
        }
    }

    const vector<Account*>& getAllAccounts() const {
        return accounts;
    }
};

#endif
