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
#include "SocketAdam.h"

namespace Network {
    class Client : public SocketAdam {
        addrinfo serverInfo;
        int resolveServer(const std::string& ipAddr, size_t port);
    public:
        Client(const std::string& ipAddr, size_t port) : SocketAdam(ipAddr, port) { resolveServer(ipAddr, port); };
        int connectClient();
    };
}

//EVA01_CLIENT_H
