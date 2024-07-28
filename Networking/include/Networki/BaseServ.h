#pragma once 
#include <boost/asio.hpp>

using boost::asio::ip::tcp;
namespace My 
{
    class TCPServer
    {
        

        enum class IPver
        {
            V4,
            V6
        };
        public: 
        TCPServer(IPver ipv, int port);
        
        int Run();//run io_content

        private:
            void StartAccept();
        private:
            IPver _ipVersion;
            int _port;
            boost::asio::io_context _ioContext;
            tcp::acceptor _acceptor;
    };
}
#include <iostream>
#include <algorithm>
#include <iterator>
#include <boost/lambda/lambda.hpp>
