#ifndef __UNIQOBJECT_H__
# define __UNIQOBJECT_H__

#include "Singleton.hpp"

class	UniqObject : public Singleton<UniqObject>
{
  friend class	Singleton<UniqObject>;
 private:
  UniqObject();
  ~UniqObject();
 public:
  void		setValue(const int& value);
  const int&	getValue();
 private:
  int	_value;
};

#endif // !__UNIQOBJECT_H__
