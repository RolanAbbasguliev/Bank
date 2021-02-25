//
// Created by Rolan Abbasguliev on 23.02.2021.
//

#ifndef BANKSYSTEM_DEBITACCOUNT_H
#define BANKSYSTEM_DEBITACCOUNT_H

#include "../Account.h"

class DebitAccount : public Account
{
private:
  float percentageMoney = 0;
  float percentage = 0;
public:
  float getPecentageMoney();
  void ToTheFuture(int days) override;
  DebitAccount(float balance, bool verified, float suspectSum, float percentage);
  void CheckPayment(float money) override;
  void PullMoney(float money) override;

};

#endif //BANKSYSTEM_DEBITACCOUNT_H
