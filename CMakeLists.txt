cmake_minimum_required(VERSION 3.14)
project(P2PStream)

include(FetchContent)

FetchContent_Declare(
    asio
    GIT_REPOSITORY https://github.com/chriskohlhoff/asio.git
    GIT_TAG        asio-1-32-0
)

FetchContent_GetProperties(asio)

FetchContent_MakeAvailable(asio)

message(STATUS "asio_SOURCE_DIR: ${asio_SOURCE_DIR}")

add_executable(main_executable src/main.cpp src/server/server.cpp)

target_include_directories(main_executable PRIVATE ${asio_SOURCE_DIR}/asio/include)