#include "Transaction.h"
int Transaction::tid = 0;
Transaction::Transaction(int sender, int reciver, float money, Time time)
{
  this->transactionId = tid++;
  this->money = money;
  this->reciver = reciver;
  this->sender = sender;
  this->time = time;
}

int Transaction::getId()
{
  return this->transactionId;
}

int Transaction::getSender()
{
  return this->sender;
}

int Transaction::getMoney()
{
  return this->money;
}

void Transaction::TransactionTime()
{
  this->time.showTime();
}

int Transaction::getReciver()
{
  return this->reciver;
}

Time Transaction::getTime()
{
  return this->time;
}
