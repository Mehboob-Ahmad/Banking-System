// UtilitiesController.h
#ifndef UTILITIES_CONTROLLER_H
#define UTILITIES_CONTROLLER_H

#include "Header.h"
#include "UtilitiesView.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;
class UtilitiesController
{
public:

    static void showmenu(Utilities& utilities);

    static void handleUserChoice(int choice, Utilities& utilities);
};

class CalculatorController
{
public:
    static void showmenu(Calculator& calculator);
};
class ATMController
{
public:
    static void showmenu(ATM& atm);
    static void handleUserChoice(int choice, ATM& atm);
    static void displayMessage(const string& message);


};

class AccountsController
{
public:
    static void showmenu(Account& account);
    static void handleUserChoice(int choice, Account& account);
    static void displayMessage(const string& message);
};

class BankSystemController
{
public:
    static void showmenu(BankSystem& bankSystem);
    static void handleUserChoice(int choice, BankSystem& bankSystem);
    static void displayMessage(const string& message);
};

class AdminController
{
public:
    static void showmenu(Admin& admin);
    static void handleUserChoice(int choice, Admin& admin);
    static void displayMessage(const string& message);
};
#endif