#include "Client.h"


Client::Client(string _name, string _surname, string _address, int _passport, bool _verified):
        name(_name), surname(_surname), address(_address), passport(_passport), verified(_verified) {}

void Client::setName(string name)
{
  this->name = name;
}
string Client::getName()
{
  return this->name;
}

void Client::setSurname(string surname)
{
  this->surname = surname;
}
string Client::getSurname()
{
  return this->surname;
}

void Client::setAddress(string address)
{
  this->address = address;
}
string Client::getAddress()
{
  return this->address;
}

void Client::setPassport(int passport)
{
  this->passport = passport;
}
int Client::getPassport()
{
  return this->passport;
}

void Client::setVerified(bool verified)
{
  this->verified = verified;
}
bool Client::getVerified()
{
  return this->verified;
}



