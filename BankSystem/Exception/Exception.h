#ifndef BANKSYSTEM_EXCEPTION_H
#define BANKSYSTEM_EXCEPTION_H

#include <string>
using namespace std;

class ExeptionHandler : public exception
{
private:
  string m_error;
public:
  ExeptionHandler(string error) : m_error(error){}
  const char* what() const noexcept { return m_error.c_str(); }
};


#endif //BANKSYSTEM_EXCEPTION_H
