#include "server.h"

#include <iostream>
#include <memory>
#include <asio.hpp>

using asio::ip::tcp;

Server::Server(asio::io_context& io_context, tcp::endpoint endpoint) :
    io_context_(io_context),
    acceptor_(io_context, endpoint) 
{
    start_listening();
}

void Server::start_listening() {
    // 1. Start new socket for a connection
    std::shared_ptr<tcp::socket> socket = std::make_shared<tcp::socket>(io_context_);

    // 2. Asynchronously accept incoming connection
    acceptor_.async_accept(*socket, [this, socket](asio::error_code error) {
        handle_accept(socket, error);
    });
}

void Server::handle_accept(std::shared_ptr<tcp::socket> socket, asio::error_code error) {
    if (error) {
        std::cerr << "Connection acception error: " << error.message() << std::endl;
        return;
    }

    std::cout << "Accepted connection from: " << socket->remote_endpoint() << std::endl;
    start_listening();
}
