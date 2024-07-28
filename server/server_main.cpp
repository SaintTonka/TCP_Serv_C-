#include "Networki/BaseServ.h"
#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int main(int argc, char* argv[] )
{
  try {
    boost::asio::io_context io_context;
    tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(),1337));

    while(true)
    {
      std::cout<<"accepting connections"<<std::endl;
      tcp::socket socket(io_context);
      acceptor.accept(socket); //gets connection

      std::string msg = "It works";
      boost::system::error_code error;


      boost::asio::write(socket, boost::asio::buffer(msg), error);
    }
  } catch (std::exception& e)
  {
    std::cerr<<e.what()<<std::endl;
  }
  return 0;
}