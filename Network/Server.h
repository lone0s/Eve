//
// Created by ohno on 1/25/2023.
//

#pragma once
#include <winsock2.h>
#include "SocketAdam.h"


namespace Network_Server {
    class Server : public SocketAdam {
        SOCKET connection;
        public:
            int bindServer();
            int listenServer();
            void acceptConnection();
            Server(const std::string& ipAddr, size_t port) : SocketAdam(ipAddr, port), connection(INVALID_SOCKET) {
                std::cout << "Created new Server "<< ipAddr << ":" << port << " ^-^\n";
            };
            std::string readCommunications();
    };
}

//EVA01_SERVER_H