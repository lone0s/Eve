//
// Created by ohno on 1/25/2023.
//

#pragma once


/*     Needed methods :
 * - Create a socket (Socket constructor func) <-- Sys
 * - Connect to a given address (Socket Connect() func) <-- Sys
 * - Read data <-- Sys
 * - Send data <-- Sys
 */


#include <ws2tcpip.h>
#include <iostream>
#include "SocketAdam.h"

namespace Network_Client {
    class Client : public SocketAdam {
        addrinfo serverInfo;
        int resolveServer(const std::string& ipAddr, size_t port);
    public:
        Client(const std::string& ipAddr, size_t port) : SocketAdam(ipAddr, port)
        {
            std::cout << "Created new client socket for " << ipAddr << ":" << port << " server ^-^\n";
        };
        int connectClient();
    };
}

//EVA01_CLIENT_H
