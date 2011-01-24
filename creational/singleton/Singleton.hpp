#ifndef __SINGLETON_H__
# define __SINGLETON_H__

# include <iostream>

template <typename T>
class	Singleton
{
protected:
  inline Singleton(){}
  inline ~Singleton()
  {
    std::cout << "destroying singleton."
	      << std::endl;
  }
public:
  inline static T*	getInstance()
  {
    if (!_singleton)
      {
	std::cout << "creating singleton."
		  << std::endl;
	_singleton = new T;
      }
    else
      {
	std::cout << "singleton already created!"
		  << std::endl;
      }
    return (static_cast<T*>(_singleton));
  }

  inline static void	kill()
  {
    if (_singleton)
      {
	delete _singleton;
	_singleton = NULL;
      }
    else
      {
	std::cout << "singleton already destroyed!"
		  << std::endl;
      }
  }
private:
  static T*	_singleton;
};

template <typename T>
T*	Singleton<T>::_singleton = NULL;

#endif // !__SINGLETON_H__
