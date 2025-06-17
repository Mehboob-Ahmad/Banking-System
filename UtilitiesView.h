#pragma once
#ifndef UTILITIES_VIEW_H
#define UTILITIES_VIEW_H

#include <iostream>
#include <string>
#include <vector>
#include "Header.h"

using namespace std;

class Account;

class AccountView {
public:
    static void showInfo(
        const string& customerName,
        const string& customerCnic,
        const string& type,
        const string& number,
        const string& balance,
        const string& frozen
    );

    static void displayMessage(const string& message);

    static int getUserChoice();
};

class UtilitiesView {
public:
    void showMenu(const string& bills,
        const string& challan,
        const string& ticket,
        const string& travel,
        const string& loan,
        const string& education,
        const string& insurance,
        const string& spinPrize);

    int getUserChoice();

    void waitForSpin();

    void displayMessage(const string& msg);
};

class CalculatorView {
public:
    void showMenu(const string& totalwealth,
        const string& familymembers,
        const string& fitraRate,
        const string& nisabthreshold,
        const string& monthlyInstallment);

    int getUserChoice();

    void displayMessage(const string& message);
};

class ATMview {
public:
    void showMenu(const string& cardNumber,
        const string& pin,
        const string& isActivated);

    int getUserChoice();

    void displayMessage(const string& message);
};

class BankSystemview {
public:
    void showMenu(const vector<Account*>& accounts);
    int getUserChoice();

    void displayMessage(const string& message);
};

class Adminview {
public:
    void showMenu(const string& username, const string& password,
                  const string& bill_type, double total_bill,
                  const string& challan_type, double total_challan,
                  bool freeze_account, bool delete_account);
    int getUserChoice();
};


#endif
