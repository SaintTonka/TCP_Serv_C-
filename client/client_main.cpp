#include <iostream>
#include <boost/asio.hpp>
#include <array>


using boost::asio::ip::tcp;

int main(int argc, char* argv[] )
{
  try {
    boost::asio::io_context ioContext;

    tcp::resolver resolver {ioContext};

    auto endpoint = resolver.resolve("127.0.0.1", "1337");

    tcp::socket socket {ioContext};
    boost::asio::connect(socket, endpoint);

    while(true)
    {
      //List messages
      std::array<char,128> buff {};
      boost::system::error_code error;

      size_t lenghth = socket.read_some(boost::asio::buffer(buff), error);

      if (error == boost::asio::error::eof) 
      { // cut off
        break;
      }
      else if (error) {
        throw boost::system::system_error (error);
      }

      std::cout.write(buff.data(), lenghth);

    }

  } catch (std::exception& e) {
    std::cerr<<e.what()<<std::endl;
  }

  return 0;
}