//
// Created by ohno on 1/26/2023.
//

// EVA01_SOCKETORIGIN_H

# pragma once

#include <winsock2.h>
#include <stdexcept>

class SocketAdam {
    /***************************************** Base class *****************************************/
    private:
        /*********************************** Attributes ***********************************/
        SOCKET sock;

        WSADATA data;

        sockaddr_in socketConfig;
        /************************************ Methods ************************************/
        void initSocket(const std::string &ipAddr, size_t port);

        WORD getWinSockVersion() const;
    public:
        SocketAdam(const std::string &ipAddr, size_t port) : sock(), data(), socketConfig() { initSocket(ipAddr, port); };

        int sendMessage(const std::string& message) const;

        const char* receiveMessage() const;

        void Close() const;

        void setSock(SOCKET sock);

        void setData(const WSADATA &data);

        void setSocketConfig(const sockaddr_in &socketConfig);

        SOCKET getSock() const;

        const sockaddr_in &getSocketConfig() const;

        unsigned int sizeConfigSock() const;
};

void SocketAdam::initSocket(const std::string &ipAddr, size_t port) {
    int res = WSAStartup(getWinSockVersion(), &data);
    if (res != 0)
        throw std::runtime_error("Couldn't initConfig WSA(data)\n");
    sock = socket(AF_INET6, SOCK_STREAM, IPPROTO_TCP);
    if (sock == INVALID_SOCKET){
        WSACleanup();
        throw std::runtime_error("Couldn't initConfig SOCKET\n");
    }
    socketConfig.sin_family = AF_INET6;
    socketConfig.sin_addr.s_addr = inet_addr(ipAddr.c_str());
    socketConfig.sin_port = htons(port);
}

WORD SocketAdam::getWinSockVersion() const {
    WSADATA temp;
    WSAStartup(MAKEWORD(0,0), &temp);
    return temp.wVersion;
}

void SocketAdam::Close() const {
    closesocket(sock);
    WSACleanup();
}

int SocketAdam::sendMessage(const std::string &message) const {
    return send(sock, message.c_str(), message.size(), MSG_OOB);
}

const char* SocketAdam::receiveMessage() const {
    char* buff;
    int buffLen;
    recv(sock, buff, buffLen, MSG_OOB);
}

void SocketAdam::setSock(SOCKET sock) {
    SocketAdam::sock = sock;
}

void SocketAdam::setData(const WSADATA &data) {
    SocketAdam::data = data;
}

void SocketAdam::setSocketConfig(const sockaddr_in &socketConfig) {
    SocketAdam::socketConfig = socketConfig;
}

SOCKET SocketAdam::getSock() const {
    return sock;
}

const sockaddr_in &SocketAdam::getSocketConfig() const {
    return socketConfig;
}

unsigned int SocketAdam::sizeConfigSock() const {
    return sizeof(socketConfig);
}

