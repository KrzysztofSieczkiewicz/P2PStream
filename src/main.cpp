#include <iostream>
#include <memory>
#include <asio.hpp>
#include <asio/ip/tcp.hpp>

#include "server/server.h"

using namespace std;

int main() {
    try {
        asio::io_context io_context;
        tcp::endpoint endpoint(tcp::v4(), 8080); // Listen on port 8080
        Server server(io_context, endpoint);
        io_context.run(); // Start the event loop
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}