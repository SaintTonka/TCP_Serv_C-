#include "Networki/tcp_connection.h"


namespace My{
    TCP_connection::TCP_connection(boost::asio::io_context& ioContext): _socket(ioContext)
    {

    }
    void TCP_connection::Start()
    {
        boost::asio::async_write(_socket, boost::asio::buffer(_message), 
        [this](const boost::system::error_code& error, size_t bytesTransferred) {
            if (error) 
            {
                std::cout<<"Failed to send message"<<std::endl;
            }
            else 
            {
                std::cout<<"Sent"<<bytesTransferred<<"bytes of data\n";
            }
        });
    }

}