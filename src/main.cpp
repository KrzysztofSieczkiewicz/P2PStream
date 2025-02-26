#include <asio.hpp>
#include <iostream>

using namespace std;

int main() {
    cout << "Test" << endl;

    asio::io_context context;
    context.run();

    cout << "Context runs" << endl;

    return 0;
}