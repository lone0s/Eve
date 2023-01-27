//
// Created by ohno on 1/27/2023.
//

#include <ws2tcpip.h>
#include "SocketAdam.h"

void SocketAdam::initSocket(const std::string &ipAddr, size_t port) {
    int res = WSAStartup(MAKEWORD(2,2), &data);
    if (res != 0)
        throw std::runtime_error("Couldn't initConfig WSA(data)\n");
    sock = socket(AF_INET6, SOCK_STREAM, IPPROTO_TCP);
    if (sock == INVALID_SOCKET){
        WSACleanup();
        throw std::runtime_error("Couldn't initConfig SOCKET\n");
    }
    socketConfig.sin6_family = AF_INET6;
    inet_pton(AF_INET6, ipAddr.c_str(), &socketConfig.sin6_addr);
    socketConfig.sin6_port = htons(port);
}

WORD SocketAdam::getWinSockVersion() const {
    WSADATA temp;
    WSAStartup(MAKEWORD(0,0), &temp);
    return temp.wVersion;
}

void SocketAdam::Close() {
    closesocket(sock);
    WSACleanup();
}

int SocketAdam::sendMessage(const std::string &message) const {
    return send(sock, message.c_str(), message.size(), 0);
}

std::string SocketAdam::receiveMessage() const {
    char buff[1024];
    int buffLen = 1024;
    recv(sock, buff, buffLen, MSG_OOB);
    return std::string{buff};
}

void SocketAdam::setSock(SOCKET sock) {
    SocketAdam::sock = sock;
}

void SocketAdam::setData(const WSADATA &data) {
    SocketAdam::data = data;
}

void SocketAdam::setSocketConfig(const sockaddr_in6 &socketConfig) {
    SocketAdam::socketConfig = socketConfig;
}

SOCKET SocketAdam::getSock() const {
    return sock;
}

sockaddr_in6* SocketAdam::getSocketConfig() {
    return &socketConfig;
}

unsigned int SocketAdam::sizeConfigSock() const {
    return sizeof(socketConfig);
}

