#ifndef BANKSYSTEM_DEPOSITACCOUNT_H
#define BANKSYSTEM_DEPOSITACCOUNT_H

#include "../Account.h"
#include "../../Time/Time.h"

class DepositAccount : public Account, public Time
{
private:
  Time currentDate, endDate;
  float percentage = 0, percentageMoney = 0;
public:
  DepositAccount(float  balance, bool verified, float suspectSum, Time currentDate, Time endDate);

  void CheckDate();
  void ToTheFuture(int days) override;
  void CheckPayment(float money) override;
  void PullMoney(float money) override;

};

#endif //BANKSYSTEM_DEPOSITACCOUNT_H
