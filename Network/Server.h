//
// Created by ohno on 1/25/2023.
//

#pragma once
#include <winsock2.h>
#include "SocketAdam.h"


namespace Network {
    class Server : public SocketAdam {
        SOCKET connection;
        public:
            int bindServer();
            int listenServer();
            void acceptConnection();
            Server(const std::string& ipAddr, size_t port) : SocketAdam(ipAddr, port), connection(INVALID_SOCKET) {};
    };
}

//EVA01_SERVER_H