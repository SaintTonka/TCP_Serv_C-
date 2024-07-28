#pragma once 
#include <boost/asio.hpp>
#include <iostream>
#include <memory>

using boost::asio::ip::tcp;

namespace My {
    class TCP_connection 
    {
        public:
            using pointer = std::shared_ptr<TCP_connection>;

            static pointer Create(boost::asio::io_context& ioContext)
            {
                return std::make_shared<TCP_connection>(ioContext);
            }

        tcp::socket& Socket()
        {
            return _socket;
        }
        void Start();

        private:
            explicit TCP_connection(boost::asio::io_context& ioContext);

        private:
            tcp::socket _socket;
            std::string _message {"Hello!\n"};
    };
}