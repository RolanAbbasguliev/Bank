#ifndef BANKSYSTEM_ACCOUNT_H
#define BANKSYSTEM_ACCOUNT_H

#include "../Exception/Exception.h"
#include "../Client/Client.h"
#include "Transaction.h"
#include <algorithm>
#include <map>

#include <string>

using namespace std;

class Account
{
private:
  static int aid;
  int accId = 0;
  bool verified = false;
  float balance = 0, suspectSum = 0;

  Time currentDate;
public:
  map <int, Transaction> transactionList;

  //int counter = 0;  // for percetage handle
  Account(float balance, bool verified, float suspectSum);

  int getId();
  void setId(int id);

  float getBalance();
  void setBalance(float balance);


  void VerificationControl(float money);
  void PushMoney(float money);


  Time* getDate();



  void TransferRecorder(Account *acc, float money, Time time);
  void TransferRemover(Account *acc, float money, Time time);
  void MoneyTransfer(Account *acc, float money, Time time);
  void MoneyTransferBackUp(Account *acc, float money, Time time);



  virtual void ToTheFuture(int days) = 0;
  virtual void CheckPayment(float money) = 0;
  virtual void PullMoney(float money) = 0;
};








#endif //BANKSYSTEM_ACCOUNT_H
