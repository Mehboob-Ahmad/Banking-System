// UtilitiesView.h
#pragma once  
#ifndef UTILITIES_VIEW_H  
#define UTILITIES_VIEW_H  

#include <iostream>  
#include <string>  
#include <map> 
#include "Header.h"   

using namespace std;

class UtilitiesView  
{  
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

class CalculatorView  
{  
public:  
   void showMenu(const string& totalwealth,  
       const string& familymembers,  
       const string& fitraRate,  
       const string& nisabthreshold,  
       const string& monthlyInstallment);  
   int getUserChoice();  
};  

class ATMview {
public:
    void showMenu(const string& cardNumber,
        const string& pin,
        const string& isActivated);
    int getUserChoice();
};

void showInfo(
    const string& customerName,
    const string& customerCnic,  
    const string& type,
    const string& number,
    const string& balance,
    const string& frozen
);
   int getUserChoice();
   class Accountview {  
   public:  
       void showInfo(
           const string& customerName,
           const string& customerCnic,
           const string& type,
           const string& number,
           const string& balance,
           const string& frozen 
       );  
       void displayMessage(const string& message);
       int getUserChoice();
   };

class BankSystemview {  
public:  
   void showMenu(map<string, Account*> accounts,   
       map<string, int> customerAccounts);  
   int getUserChoice();  
   void displayMessage(const string& message);  
};  

class Adminview {
public:
	int getUserChoice();
	void displayMessage(const string& message);
    void showMenu(const string& username, const string& password, const string& bill_type, int total_bill, const string& challan_type, int total_challan, bool freeze_account, bool delete_account);
};

#endif