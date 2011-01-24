#ifndef __MODULE_H__
# define __MODULE_H__

class	IRequest;
class	Request;
class	RequestModular;

class	IResponse;
class	Response;
class	ResponseModular;
class	AutoIndex;

class	IRequest
{
 public:
  virtual ~IRequest(){}

  virtual const int&	getPort() = 0;
  virtual void		setPort(const int&) = 0;
};

class	Request : public IRequest
{
 public:
  Request();

  virtual const int&	getPort();
  virtual void		setPort(const int&);
 private:
  int	_port;
};

class	RequestModular : public IRequest
{
  RequestModular(IRequest*);
  ~RequestModular();

  virtual const int&	getPort();
  virtual void		setPort(const int&);
 private:
  IRequest*	_req;
};

class	IResponse
{
 public:
  virtual ~IResponse(){}

  virtual void	browser() = 0;
};

class	Response : public IResponse
{
 public:
  Response(IRequest*);

  virtual void	browser();
 private:
  IRequest*	_req;
};

class	ResponseModular : public IResponse
{
 public:
  ResponseModular(IResponse*);
  ~ResponseModular();

  virtual void	browser();
 private:
  IResponse*	_res;
};

class	AutoIndex : public ResponseModular
{
 public:
  AutoIndex(IResponse*);

  virtual void	browser();
};

#endif // !__MODULE_H__
