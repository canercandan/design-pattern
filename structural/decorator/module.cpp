#include <iostream>
#include "module.h"

Request::Request()
  : _port(0)
{}

const int&	Request::getPort()
{
  return (this->_port);
}

void	Request::setPort(const int& port)
{
  this->_port = port;
}

RequestModular::RequestModular(IRequest* req)
  : _req(req)
{}

RequestModular::~RequestModular()
{
  delete _req;
}

const int&	RequestModular::getPort()
{
  return (this->_req->getPort());
}

void	RequestModular::setPort(const int& port)
{
  this->_req->setPort(port);
}

Response::Response(IRequest* req)
  : _req(req)
{}

void	Response::browser()
{
  std::cout << "browser standard" << std::endl;
}

ResponseModular::ResponseModular(IResponse* res)
  : _res(res)
{}

ResponseModular::~ResponseModular()
{
  delete _res;
}

void	ResponseModular::browser()
{
  this->_res->browser();
}

AutoIndex::AutoIndex(IResponse* res)
  : ResponseModular(res)
{}

void	AutoIndex::browser()
{
  std::cout << "browser autoindex" << std::endl;
}

int	main(void)
{
  IRequest*	req = new Request;
  IResponse*	res = new Response(req);

  res->browser();

  res = new ResponseModular(res);
  res->browser();

  res = new AutoIndex(res);
  res->browser();

  delete req;
  delete res;

  return 0;
}
