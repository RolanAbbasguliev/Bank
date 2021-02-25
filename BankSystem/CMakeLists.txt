cmake_minimum_required(VERSION 3.17)
project(BankSystem)

set(CMAKE_CXX_STANDARD 14)

add_executable(BankSystem main.cpp Account/Account.cpp Account/Account.h Account/AccountSelector.cpp Account/AccountSelector.h Bank/Bank.cpp Bank/Bank.h Client/Client.cpp Client/Client.h Client/ClientBuilder.cpp Client/ClientBuilder.h Exception/Exception.h Account/DebitAccount/DebitAccount.cpp Account/DebitAccount/DebitAccount.h Date/Date.h Account/Transaction.h Account/DepositAccount/DepositAccount.cpp Account/DepositAccount/DepositAccount.h Account/CreditAccount/CreditAccount.cpp Account/CreditAccount/CreditAccount.h  Time/Time.cpp Time/Time.h Account/Transaction.cpp)