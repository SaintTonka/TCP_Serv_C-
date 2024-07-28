#include "Networki/tcp_connection.h"
#include "Networki/BaseServ.h"
#include <boost/asio.hpp>
#include <iostream>

namespace My 
{
    using boost::asio::ip::tcp;

    TCPServer::TCPServer(IPver ipv, int port)
        : _ipVersion(ipv), _port(port),
          _acceptor(_ioContext, tcp::endpoint(ipv == IPver::V4 ? tcp::v4() : tcp::v6(), port))
    {
        
    }

    int TCPServer::Run()
    {
        try 
        {
            StartAccept();
            _ioContext.run();
        }
        catch (std::exception& e)
        {
        std::cerr<<e.what()<<std::endl;
        return -1;
        }

    return 0;
    }

    void TCPServer::StartAccept()
    {
        // create connection
        auto connection = TCP_connection::Create(_ioContext);
        //async accept
        _acceptor.async_accept(connection -> Socket(), [connection, this](const boost::system::error_code& error){
            if (!error)
                connection -> Start();
                
            StartAccept();
        });
    }
    
}




