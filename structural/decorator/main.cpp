#include <iostream>

class	IWidget;
class	TextField;
class	Decorator;
class	BorderDecorator;
class	ScrollDecorator;

class	IWidget
{
 public:
  virtual ~IWidget(){}
  virtual void	draw() = 0;
};

class	TextField : public IWidget
{
public:
  TextField(int w, int h)
    : _w(w), _h(h)
  {}

  void	draw()
  {
    std::cout << "TextField: "
	      << this->_w << ", "
	      << this->_h << std::endl;
  }
private:
  int	_w;
  int	_h;
};

class	Decorator : public IWidget
{
public:
  Decorator(IWidget* widget)
    : _widget(widget)
  {}
  ~Decorator()
  {
    delete _widget;
  }

  void	draw()
  {
    this->_widget->draw();
  }
private:
  IWidget*	_widget;
};

class	BorderDecorator : public Decorator
{
public:
  BorderDecorator(IWidget* widget)
    : Decorator(widget)
  {}

  void	draw()
  {
    this->Decorator::draw();
    std::cout << "   BorderDecorator" << std::endl;
  }
};

class	ScrollDecorator : public Decorator
{
public:
  ScrollDecorator(IWidget* widget)
    : Decorator(widget)
  {}

  void	draw()
  {
    this->Decorator::draw();
    std::cout << "   ScrollDecorator" << std::endl;
  }
};

class	ILoveGeraldine : public Decorator
{
public:
  ILoveGeraldine(IWidget* widget)
    : Decorator(widget)
  {}

  void	draw()
  {
    this->Decorator::draw();
    std::cout << "   ILoveGeraldine" << std::endl;
  }
};

int	main(void)
{
  IWidget*	aWidget;

  aWidget = new ILoveGeraldine(new BorderDecorator(new ScrollDecorator(new BorderDecorator(new TextField(80, 24)))));
  aWidget->draw();
  delete aWidget;
}
