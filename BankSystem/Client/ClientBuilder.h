#ifndef BANKSYSTEM_CLIENTBUILDER_H
#define BANKSYSTEM_CLIENTBUILDER_H

#include <string>
#include "Client.h"
using namespace std;

class ClientBuilder
{
private:
  string name = "", surname = "", address = "";
  int passport = 0;
  bool verified = false;
public:
  ClientBuilder();
  ClientBuilder &nameBuild(string name);
  ClientBuilder &surnameBuild(string surname);
  ClientBuilder &addressBuild(string address);
  ClientBuilder &passportBuild(int passport);
  ClientBuilder &verifiedBuild(bool verified);
  Client &build();
};

#endif //BANKSYSTEM_CLIENTBUILDER_H
