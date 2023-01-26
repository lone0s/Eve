cmake_minimum_required(VERSION 3.24)
project(Eva01)

set(CMAKE_CXX_STANDARD 14)

add_executable(Eva01 main.cpp Network/Client.cpp Network/Client.h Network/Server.cpp Network/Server.h Network/SocketAdam.h)
