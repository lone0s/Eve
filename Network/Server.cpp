//
// Created by ohno on 1/25/2023.
//
#include <iostream>
#include "Server.h"

using namespace Network_Server;
//using namespace Network_Client;

int Server::bindServer() {
    std::cout << "Binding..\n";
    std::cout << "Sizeof : " << sizeConfigSock() << std::endl;
    std::cout << ""
    return bind(getSock(), (SOCKADDR *) &getSocketConfig(), sizeConfigSock());
}

int Server::listenServer() {
    std::cout << "Listening for connections..\n";
    return listen(getSock(), SOMAXCONN);
}

void Server::acceptConnection() {
    connection = accept(getSock(), nullptr, nullptr);
    std::cout << "Connection Established ^_^\n";
}
