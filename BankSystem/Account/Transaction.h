#ifndef BANKSYSTEM_TRANSACTION_H
#define BANKSYSTEM_TRANSACTION_H


#include "../Date/Date.h"
#include "../Time/Time.h"


class Transaction
{
private:
  static int tid;
  int transactionId;
  float money = 0;
  Time time;
  int reciver, sender;
  bool mark = false; //for removing from list
public:
  int getId();
  int getSender();
  int getMoney();
  int getReciver();
  Time getTime();
  void TransactionTime();
  Transaction(int sender, int reciver, float money, Time time);
};

#endif //BANKSYSTEM_TRANSACTION_H
