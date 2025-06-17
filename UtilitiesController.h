#pragma once
#ifndef UTILITIES_CONTROLLER_H
#define UTILITIES_CONTROLLER_H

#include "Header.h"
#include "UtilitiesView.h"
#include <vector>

using namespace std; 

class AccountView;
class UtilitiesView;
class CalculatorView;
class ATMview;
class BankSystemview;
class Adminview;
class LoanView;

class AccountsController {
public:
    static void showmenu(Account& account);
    static void handleUserChoice(int choice, Account& account, BankSystem& bankSystem);
};

class UtilitiesController {
public:
    static void showmenu(Utilities& utilities);
    static void handleUserChoice(int choice, Utilities& utilities);
};

class CalculatorController {
public:
    static void showmenu(Calculator& calculator);
    static void handleUserChoice(int choice, Calculator& calculator);
};

class ATMController {
public:
    static void showmenu(ATM& atm);
    static void handleUserChoice(int choice, ATM& atm);
};

class BankSystemController
{
public:
    static void showmenu(BankSystem& bankSystem);
    static void handleUserChoice(int choice, BankSystem& bankSystem);
};

class AdminController {
public:
    static void showmenu(Admin& admin);
    static void handleUserChoice(int choice, Admin& admin, BankSystem& bankSystem);
};

class LoanController {
public:
    static void showMenu(LoanTracker* loan);
    static void handleUserChoice(int choice, Account& account, BankSystem& bank);
};

#endif