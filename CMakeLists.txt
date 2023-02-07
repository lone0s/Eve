cmake_minimum_required(VERSION 3.24)
project(Eva01)

set(CMAKE_CXX_STANDARD 14)
include_directories(Winsock2.h)

find_library(WINSOCK_LIBRARY ws2_32)
add_executable(Eva01
        main.cpp
        Network/Client.cpp
        Network/Client.h
        Network/Server.cpp
        Network/Server.h
        Network/SocketAdam.h Network/SocketAdam.cpp Encryption/ECIH.cpp Encryption/ECIH.h Arithmetic/BigInt.cpp Arithmetic/BigInt.h Arithmetic/BigInt.h Arithmetic/GaloisField.cpp Arithmetic/GaloisField.h Arithmetic/EllipticCurve.cpp Arithmetic/EllipticCurve.h Arithmetic/Point.cpp Arithmetic/Point.h)

if (WIN32)
    target_link_libraries(Eva01 wsock32 ws2_32)
endif()