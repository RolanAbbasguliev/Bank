#ifndef BANKSYSTEM_BANK_H
#define BANKSYSTEM_BANK_H

#include "../Account/AccountSelector.h"
#include "../Client/Client.h"
#include <iostream>
#include <map>
using namespace std;

class Bank
{
public:
  string name = "";
  float percetage = 0, suspectSum = 0, commission = 0, creditLimit = 0;
  map <int, Account*> accountList;

public:
  Bank(string name, float suspectSum, float procentage, float creditLimit, float commission);
  void CardBalance(Account *acc);


  void CardRefill(Account *acc, float money);
  void CardWithdraw(Account *acc, float money);

  void Transaction(Account *acc1, Account *acc2, float money);
  void CancelTransaction(Account *acc1, Account *acc2, float money);

  void DayPassed(int days);


  Account* DebitAccountCreate(Client newClient, float balance);
  Account* DepositAccount(Client newClient, float balance, Time currentDate, Time endDate);
  Account* CreditAccountCreate(Client newClient, float balance);
};

#endif //BANKSYSTEM_BANK_H
