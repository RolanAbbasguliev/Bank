#include <iostream>
#include "Client/ClientBuilder.h"
#include "Bank/Bank.h"
#include "Date/Date.h"
#include <vector>
#include <ctime>
#include "Time/Time.h"
using namespace std;


int main(int argc, char const **argv)
{
  Time date;
  Time endDeposit;
  endDeposit.SetDate(26, 02, 2021);

  Bank bank("Sberbank", 500, 10, 500, 5);   //nam, sussum, pr, crlim, comiss

  ClientBuilder clientBuilder;
  Account *card1 = nullptr, *card2 = nullptr, *card3 = nullptr;
  Client client1 = ClientBuilder().nameBuild("Rolan").surnameBuild("Abbasguliev").passportBuild(23242).build();
  Client client2 = ClientBuilder().nameBuild("Nikita").build();
  Client client3 = ClientBuilder().nameBuild("Vasya").build();



  card1 = bank.CreditAccountCreate(client1, 400);
  card2 = bank.DebitAccountCreate(client2, 600);
  card3 = bank.DepositAccount(client3, 1000, date, endDeposit);

  bank.Transaction(card1, card2, 200);
  bank.CardBalance(card1);
  bank.CardBalance(card2);

  bank.Transaction(card1, card2, 200);
  bank.CardBalance(card1);
  bank.CardBalance(card2);

  bank.CancelTransaction(card1, card2, 200);
  bank.CardBalance(card1);
  bank.CardBalance(card2);

  bank.DayPassed(40);
  bank.CardBalance(card2);







  return 0;
}
