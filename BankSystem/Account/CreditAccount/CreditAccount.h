#ifndef BANKSYSTEM_CREDITACCOUNT_H
#define BANKSYSTEM_CREDITACCOUNT_H

#include "../Account.h"
#include <cmath>

class CreditAccount : public Account
{
private:
  float creditLimit = 0;
  float commission = 0;
public:

  float getCreditLimit();
  void setCreditLimit(float creditLimit);
  CreditAccount(float  balance, bool verified, float suspectSum, float percentage, float creditLimit);
  void CheckPayment(float money) override;
  void PullMoney(float money) override;
  void ToTheFuture(int day) override {};
};

#endif //BANKSYSTEM_CREDITACCOUNT_H
