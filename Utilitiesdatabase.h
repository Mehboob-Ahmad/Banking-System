#pragma once
#ifndef UTILITIESDATABASE_H
#define UTILITIESDATABASE_H

#include <string>
#include <vector>
#include <iostream>
#include <limits>
#include "Header.h"


using namespace std; 


class Utilitiesdatabase {
public:
    void showMenu(const string& bills, const string& challan,
        const string& ticket, const string& travel,
        const string& loan, const string& education,
        const string& insurance, const string& spinwheelPrize);

    static int getUserChoice();
    static void displayMessage(const string& message);

    void waitForSpin();
    string spinTheWheelAndDisplayPrize();
};

class calculatordatabase {
public:
    void showMenu(const string& totalwealth,
        const string& familymembers,
        const string& fitraRate,
        const string& nisabthreshold,
        const string& monthlyInstallment);
    static int getUserChoice();
    static void displayMessage(const string& message);
};

class ATMdatabase {
public:
    void showMenu(const string& cardNumber,
        const string& pin,
        const string& isActivated);
    static int getUserChoice();
    static void displayMessage(const string& message);
};

class Accountdatabase {
public:
    void showMenu(const string& customerName,
        const string& customerCnic,
        const string& type,
        const string& number,
        const string& balance,
        const string& frozen);
    static int getUserChoice();
    static void displayMessage(const string& message);
};

class BankSystemdatabase {
public:
   void showMenu(const vector<Account*>& accounts);
   static int getUserChoice();
   static void displayMessage(const string& message);
};

class Admindatabase {
public:
    void showMenu(const string& username, const string& password,
                  const string& billType, double totalBill,
                  const string& challanType, double totalChallan,
                  bool freezeAccount, bool deleteAccount);
    static int getUserChoice();
    static void displayMessage(const string& message);
};

#endif