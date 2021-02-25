#ifndef BANKSYSTEM_ACCOUNTSELECTOR_H
#define BANKSYSTEM_ACCOUNTSELECTOR_H

#include "Account.h"
#include "DebitAccount/DebitAccount.h"
#include "DepositAccount/DepositAccount.h"
#include "CreditAccount/CreditAccount.h"

#include "../Client/Client.h"


class AccountSelector
{
public:
  static Account* createAccount(const string& type, float balance, bool verified, float suspectSum, float percentage = 0, float creditLimit = 0,
                               Time currentDate = Time(), Time endDate = Time())
  {
    Account *account = nullptr;

    if (type == "debit")
      account = new DebitAccount(balance, verified, suspectSum, percentage);
    else if (type == "deposit")
      account = new DepositAccount(balance, verified, suspectSum, currentDate, endDate);
    else if (type == "credit")
      account = new CreditAccount(balance, verified, suspectSum, percentage, creditLimit);
    else
      throw ExeptionHandler("No such account type");

    return account;
  }
};

#endif //BANKSYSTEM_ACCOUNTSELECTOR_H
