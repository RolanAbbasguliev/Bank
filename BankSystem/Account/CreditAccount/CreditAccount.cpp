#include "CreditAccount.h"
float CreditAccount::getCreditLimit()
{
  return this->creditLimit;
}

void CreditAccount::setCreditLimit(float creditLimit)
{
  this->creditLimit = creditLimit;
}



CreditAccount::CreditAccount(float balance, bool verified, float suspectSum, float percentage, float creditLimit):
        Account(balance, verified, suspectSum)
{
  this->commission = percentage;
  this->setCreditLimit(creditLimit);
}

void CreditAccount::CheckPayment(float money)
{
  float Blimit = (this->getBalance() - money);
  if (Blimit < 0)
  {
    if (abs(Blimit) > this->getCreditLimit())
      throw ExeptionHandler("Credit limit out of range");
  }
}

void CreditAccount::PullMoney(float money)
{
  this->CheckPayment(money);
  this->VerificationControl(money);
  float Balance = this->getBalance() - money;
  if (Balance < 0)
  {
    float commisionMoney = money * this->commission / 100;
    this->setBalance(this->getBalance() - money + commisionMoney);
  }
  else
    this->setBalance(this->getBalance() - money);
}



