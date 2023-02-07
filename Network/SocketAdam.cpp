//
// Created by ohno on 1/27/2023.
//

#include "SocketAdam.h"

void SocketAdam::initSocket(const std::string &ipAddr, size_t port) {
    int res = WSAStartup(getWinSockVersion(), &data);
    if (res != 0)
        throw std::runtime_error("Couldn't initConfig WSA(data)\n");
    sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == INVALID_SOCKET){
        WSACleanup();
        throw std::runtime_error("Couldn't init config SOCKET\n");
    }
    socketConfig.sin_family = AF_INET;
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
    return send(sock, message.c_str(), message.size(), 0);
}

std::string SocketAdam::receiveMessage() const {
    char buff[1024] {};
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

void SocketAdam::setSocketConfig(const sockaddr_in &socketConfig) {
    SocketAdam::socketConfig = socketConfig;
}

SOCKET SocketAdam::getSock() const {
    return sock;
}

sockaddr_in* SocketAdam::getSocketConfig() {
    return &socketConfig;
}

unsigned int SocketAdam::sizeConfigSock() const {
    return sizeof(socketConfig);
}
/*

void SocketAdam::setCommunications(SOCKET communications) {
    SocketAdam::communications = communications;
}

SOCKET SocketAdam::getCommunications() const {
    return communications;
}
*/

