#include "DebitAccount.h"

DebitAccount::DebitAccount(float balance, bool verified, float suspectSum, float percentage):
        Account(balance, verified, suspectSum)
{

  this->percentage = percentage;
}



void DebitAccount::CheckPayment(float money)
{
  if (this->getBalance() - money < 0)
  {
    throw ExeptionHandler("No enough money");
  }
}

void DebitAccount::PullMoney(float money)
{
  this->CheckPayment(money);
  this->VerificationControl(money);
  this->setBalance(this->getBalance() - money);
}


void DebitAccount::ToTheFuture(int days)
{
  for (int i = 0; i < days; i++)
  {
    if (this->getDate()->endMonth())
    {
      this->setBalance(this->getBalance() + this->percentageMoney);
      this->percentageMoney = 0;
    }
    this->getDate()->DayPlus();
    this->percentageMoney += this->getBalance() * this->percentage / 365 / 100;
  }
}


