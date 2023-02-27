//
// Created by ohno on 1/25/2023.
//
#include <iostream>
#include "Server.h"

using namespace Network_Server;

int Server::bindServer() {
    std::cout << "Binding..\n";
    std::cout << "Sizeof : " << sizeConfigSock() << std::endl;
    std::cout << "Sock config inn : " << getSocketConfig() << std::endl;
    return bind(getSock(), (SOCKADDR *) getSocketConfig(), sizeConfigSock());
}

int Server::listenServer() {
    std::cout << "Listening for connections..\n";
    return listen(getSock(), SOMAXCONN);
}

void Server::acceptConnection() {
    connection = accept(getSock(), nullptr, nullptr);
    if (connection < 0)
        std::cerr << "Erreur connexion\n";
    this ->setSock(connection);
    std::cout << "Connection Established ^-^\n";
}

std::string Server::readCommunications() {
    char buff[512] {};
    int buffLen = 512;
    recv(connection, buff, buffLen, 0);
    std::string res{buff};
    res.length() != 0 ? std::cout << "Received a new message :)\n" : std::cout <<"No message sent :(\n";
    return res;
}
