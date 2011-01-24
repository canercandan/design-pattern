#include "UniqObject.h"

UniqObject::UniqObject()
  : _value(0)
{}

UniqObject::~UniqObject()
{}

void	UniqObject::setValue(const int& value)
{
  this->_value = value;
}

const int&	UniqObject::getValue()
{
  return (this->_value);
}
