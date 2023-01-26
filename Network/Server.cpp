//
// Created by ohno on 1/25/2023.
//
#include <iostream>
#include "Server.h"

using namespace Network;

int Server::bindServer() {
    return bind(getSock(), (SOCKADDR *) &getSocketConfig(), sizeConfigSock());
}

int Server::listenServer() {
    return listen(getSock(), SOMAXCONN);
}

void Server::acceptConnection() {
    connection = accept(getSock(), nullptr, nullptr);
    std::cout << "Connection Established ^_^\n";
}
