//
// Created by ohno on 1/25/2023.
//

#include "Client.h"


int Network::Client::connectClient() {
    return connect(getSock(), (SOCKADDR*) &getSocketConfig(), sizeConfigSock());
}

int Network::Client::resolveServer(const std::string &ipAddr, size_t port) {
    struct addrinfo *result = nullptr, *ptr = nullptr;
    ZeroMemory(&serverInfo, sizeof(serverInfo));
    serverInfo.ai_family = AF_INET6;
    serverInfo.ai_socktype = SOCK_STREAM;
    serverInfo.ai_protocol = IPPROTO_TCP;

//    res = getaddrinfo(ipAddr.c_str(), std::to_string(port), &serverInfo, )
}
