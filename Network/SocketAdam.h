//
// Created by ohno on 1/26/2023.
//

// EVA01_SOCKETORIGIN_H

# pragma once

#include <winsock2.h>
#include <ws2ipdef.h>
#include <stdexcept>

class SocketAdam {
    /***************************************** Base class *****************************************/
    private:
        /*********************************** Attributes ***********************************/
        SOCKET sock;

        WSADATA data;

        sockaddr_in6 socketConfig;
        /************************************ Methods ************************************/
        void initSocket(const std::string &ipAddr, size_t port);

        WORD getWinSockVersion() const;
    public:
        SocketAdam(const std::string &ipAddr, size_t port) : sock(), data(), socketConfig() { initSocket(ipAddr, port); };

        int sendMessage(const std::string& message) const;

        std::string receiveMessage() const;

        void Close();

        void setSock(SOCKET sock);

        void setData(const WSADATA &data);

        void setSocketConfig(const sockaddr_in6 &socketConfig);

        SOCKET getSock() const;

        sockaddr_in6* getSocketConfig();

        unsigned int sizeConfigSock() const;
};


//EVA00_ORIGIN_H