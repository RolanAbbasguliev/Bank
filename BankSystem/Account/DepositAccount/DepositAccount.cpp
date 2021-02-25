#include "DepositAccount.h"

DepositAccount::DepositAccount(float balance, bool verified, float suspectSum, Time currentDate, Time endDate):
        Account(balance, verified, suspectSum)
{
  /*this->currentDate = currentDate;
  this->endDate = endDate;*/

  if (balance > 100000)
    this->percentage = 4;
  else if (balance >= 50000 && balance <= 100000)
    this->percentage = 3.5;
  else
    this->percentage = 4;
}



void DepositAccount::CheckPayment(float money)
{
  if (this->getBalance() - money < 0)
    throw ExeptionHandler("No enough money");
}

void DepositAccount::CheckDate()
{
  if (this->currentDate < this->endDate)
    throw ExeptionHandler("You cannot Pull money from this account until end date");
}


void DepositAccount::PullMoney(float money)
{
  this->VerificationControl(money);
  this->CheckPayment(money);
  this->CheckDate();
  this->setBalance(this->getBalance() - money);
}

void DepositAccount::ToTheFuture(int days)
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
