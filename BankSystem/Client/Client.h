#ifndef BANKSYSTEM_CLIENT_H
#define BANKSYSTEM_CLIENT_H

#include <string>
#include <vector>
using namespace std;

class Client
{
private:
  string name = "", surname = "", address = "";
  int passport = 0;
  bool verified = false;
public:
  Client(string name, string surname, string address, int passport, bool verified);
  void setName(string name);
  string getName();

  void setSurname(string surname);
  string getSurname();

  void setAddress(string address);
  string getAddress();

  void setPassport(int passport);
  int getPassport();

  void setVerified(bool verified);
  bool getVerified();
};

#endif //BANKSYSTEM_CLIENT_H
