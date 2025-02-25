#ifndef SERVER_H
#define SERVER_H

#include <memory>
#include <asio.hpp>

using asio::ip::tcp;

class Server {

public:
    Server(asio::io_context& io_context, tcp::endpoint endpoint);

private:
    asio::io_context& io_context_;
    tcp::acceptor acceptor_;

    void start_listening();
    void handle_accept(std::shared_ptr<tcp::socket> socket, asio::error_code error);
};

#endif