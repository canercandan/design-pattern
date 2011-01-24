#include "UniqObject.h"

int	main(void)
{
  UniqObject*	obj1;
  UniqObject*	obj2;
  UniqObject*	obj3;

  obj1 = UniqObject::getInstance();
  obj2 = UniqObject::getInstance();
  obj3 = UniqObject::getInstance();

  obj1->setValue(134);

  std::cout << std::endl;

  std::cout << "obj1::_value = "
	    << obj1->getValue() << std::endl;
  std::cout << "obj2::_value = "
	    << obj2->getValue() << std::endl;
  std::cout << "obj3::_value = "
	    << obj3->getValue() << std::endl;

  std::cout << std::endl;

  obj1->kill();
  obj2->kill();
  obj3->kill();

  return 0;
}
