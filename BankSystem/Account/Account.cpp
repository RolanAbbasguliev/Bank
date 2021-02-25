#include "Account.h"

int Account::aid = 0;

Account::Account(float balance, bool verified, float suspectSum)
{
  this->accId = aid++;
  this->balance = balance;
  this->verified = verified;
  this->suspectSum = suspectSum;
}

int Account::getId()
{
  return this->accId;
}
void Account::setId(int id)
{
  this->accId = id;
}

float Account::getBalance()
{
  return this->balance;
}
void Account::setBalance(float balance)
{
  this->balance = balance;
}



void Account::VerificationControl(float money)
{
  if (!this->verified && money > this->suspectSum)
    throw ExeptionHandler("No verification: money limit complete");
}

void Account::PushMoney(float money)
{
  this->balance += money;
}

void Account::TransferRecorder(Account *acc, float money, Time time)
{
  Transaction transaction1(this->getId(), acc->getId(), money, time);
  this->transactionList.insert(make_pair(transaction1.getId(), transaction1));
  acc->transactionList.insert(make_pair(transaction1.getId(), transaction1));
}

void Account::TransferRemover(Account *acc, float money, Time time)
{
  int flag = 0;;
  for (int i = 0; i < this->transactionList.size(); i++)
  {
    flag = 1;
    if (this->transactionList.find(i)->second.getReciver() == acc->getId() &&
        this->transactionList.find(i)->second.getTime() == time)
    {
      this->transactionList.erase(i);
      acc->transactionList.erase(i);
    }
  }
}

void Account::MoneyTransfer(Account *acc, float money, Time time)
{
  this->CheckPayment(money);
  this->VerificationControl(money);
  this->PullMoney(money);
  acc->PushMoney(money);

  //record to list
  this->TransferRecorder(acc, money, time);
}

void Account::MoneyTransferBackUp(Account *acc, float money, Time time)
{
  acc->CheckPayment(money);
  this->PushMoney(money);
  acc->PullMoney(money);
  this->TransferRemover(acc, money, time);
}

Time* Account::getDate()
{
  return &currentDate;
}



