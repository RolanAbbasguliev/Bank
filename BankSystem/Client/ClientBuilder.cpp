#include "ClientBuilder.h"

ClientBuilder::ClientBuilder() {}

ClientBuilder &ClientBuilder::nameBuild(string name)
{
  this->name = name;
  return *this;
}

ClientBuilder &ClientBuilder::surnameBuild(string surname)
{
  this->surname = surname;
  return *this;
}

ClientBuilder &ClientBuilder::addressBuild(string address)
{
  this->verified = true;
  this->address = address;
  return *this;
}

ClientBuilder &ClientBuilder::passportBuild(int passport)
{
  this->verified = true;
  this->passport = passport;
  return *this;
}

ClientBuilder &ClientBuilder::verifiedBuild(bool verified)
{
  this->verified = verified;
  return *this;
}

Client &ClientBuilder::build()
{
  Client *client = new Client(name, surname, address, passport, verified);
  return *client;
}
