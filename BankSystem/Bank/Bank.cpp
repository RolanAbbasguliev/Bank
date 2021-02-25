#include "Bank.h"

Bank::Bank(string name, float suspectSum, float percentage, float creditLimit, float commission)
{
  this->creditLimit = creditLimit;
  this->commission = commission;
  this->name = name;
  this->percetage = percentage;
  this->suspectSum = suspectSum;
}

void Bank::Transaction(Account *acc1, Account *acc2, float money)
{
  Time time;
  if (this->accountList.find(acc1->getId()) != this->accountList.end() && this->accountList.find(acc2->getId()) != this->accountList.end())
    this->accountList.find(acc1->getId())->second->MoneyTransfer(this->accountList.find(acc2->getId())->second, money, time);
  else
    throw ExeptionHandler("Account doesn't registered");
}

void Bank::CancelTransaction(Account *acc1, Account *acc2, float money)
{
  for (int i = 0; i < acc1->transactionList.size(); i++)
  {
    if (acc1->transactionList.find(i)->second.getReciver() == acc2->getId())
    {
      cout << "-----------------------\n";
      cout << "Transaction Time\n";
      acc1->transactionList.find(i)->second.TransactionTime();
      cout << "Money transfer: " << acc1->transactionList.find(i)->second.getMoney() << "\n";

      char choose;
      cout << "Want to backup transaction? (y/n) ";
      cin >> choose;

      if (choose == 'y')
      {
        this->accountList.find(acc1->getId())->second->MoneyTransferBackUp(acc2, money, acc1->transactionList.find(
                i)->second.getTime());
        break;
      }
    }
  }
}


void Bank::CardBalance(Account *acc)
{
  cout << this->accountList.find(acc->getId())->second->getBalance() << "\n";
}

void Bank::CardWithdraw(Account *acc, float money)
{
  this->accountList.find(acc->getId())->second->PullMoney(money);
}

void Bank::CardRefill(Account *acc, float money)
{
  this->accountList.find(acc->getId())->second->PushMoney(money);
}


Account*  Bank::DebitAccountCreate(Client newClient, float balance)
{
  Account *acc = AccountSelector::createAccount("debit", balance, newClient.getVerified(), this->suspectSum, this->percetage);
  accountList.insert(make_pair(acc->getId(), acc));
  return acc;
}

Account*  Bank::DepositAccount(Client newClient, float balance, Time currentDate, Time endDate)
{
  Account *acc = AccountSelector::createAccount("deposit", balance, newClient.getVerified(), this->suspectSum, 0, 0, currentDate, endDate);
  accountList.insert(make_pair(acc->getId(), acc));
  return acc;
}

Account*  Bank::CreditAccountCreate(Client newClient, float balance)
{
  Account *acc = AccountSelector::createAccount("credit", balance, newClient.getVerified(), this->suspectSum, this->commission, this->creditLimit);
  accountList.insert(make_pair(acc->getId(), acc));
  return acc;
}

void Bank::DayPassed(int days)
{
  for (int i = 0; i < accountList.size(); i++)
    accountList.find(i)->second->ToTheFuture(days);
}




