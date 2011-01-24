#include <stack>
#include <iostream>

class	IExpression;
class	Binary;
class	Addition;
class	Multiplication;
class	Number;

typedef std::stack<IExpression*>	stackExp;

class	IExpression
{
public:
  virtual void	run(stackExp&) = 0;
};

class	Number : public IExpression
{
public:
  Number(const int& value)
    : _value(value)
  {}
public:
  virtual void	run(stackExp& s)
  {
    s.push(this);
  }

  const int&	getValue()
  {
    return (this->_value);
  }
private:
  int	_value;
};

class	Binary : public IExpression
{
public:
  Binary(IExpression* op1,
	 IExpression* op2)
    : _op1(op1), _op2(op2)
  {}
public:
  virtual void	run(stackExp&)
  {}
protected:
  IExpression*	_op1;
  IExpression*	_op2;
};

class	Addition : public Binary
{
public:
  Addition(IExpression* op1,
	   IExpression*	op2)
    : Binary(op1, op2)
  {}

  virtual void	run(stackExp& s)
  {
    int	left;
    int	right;

    this->_op1->run(s);
    this->_op2->run(s);
    left = ((Number*)s.top())->getValue();
    delete s.top();
    s.pop();
    right = ((Number*)s.top())->getValue();
    delete s.top();
    s.pop();
    s.push(new Number(left + right));
  }
};

class	Multiplication : public Binary
{
public:
  Multiplication(IExpression* op1,
		 IExpression* op2)
    : Binary(op1, op2)
  {}

  virtual void	run(stackExp& s)
  {
    int	left;
    int	right;

    this->_op1->run(s);
    this->_op2->run(s);
    left = ((Number*)s.top())->getValue();
    delete s.top();
    s.pop();
    right = ((Number*)s.top())->getValue();
    delete s.top();
    s.pop();
    s.push(new Number(left * right));
  }
};

int	main(void)
{
  IExpression*	exp;
  stackExp	stack;
  int		sum;

  // 3 + ((21345 + 3) *	(1 * 3))
  exp = new Addition(new Number(3),
		     new Multiplication(new Addition(new Number(21345),
						     new Number(3)),
					new Multiplication(new Number(1),
							   new Number(3))));
  exp->run(stack);
  sum = ((Number*)stack.top())->getValue();
  if (exp != stack.top())
    delete stack.top();
  std::cout << "Sum: [" << sum << ']' << std::endl;
  delete exp;
  return (0);
}
