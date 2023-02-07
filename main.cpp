#include <iostream>
#include "Network/Server.h"
#include "Network/Client.h"

using namespace Network_Server;
using namespace Network_Client;
int main() {
    std::cout << " whoami?\n !root :((" << std::endl;
    std::string ip = "127.0.0.1";
    size_t port = 8000;
    Server server(ip, port);
    Client iencli(ip,port);
    int res = server.bindServer();
    res == SOCKET_ERROR ? std::cout << "Error binding:  " << WSAGetLastError() << std::endl : std::cout << "Successfull binding\n";
    res = server.listenServer();
    res == SOCKET_ERROR ? std::cout << "Error listening: " << WSAGetLastError() << std::endl : std::cout << "Successfully listening\n";
    res = iencli.connectClient();
    res == SOCKET_ERROR ? std::cout << "ERROR !!!\n" << WSAGetLastError() << std::endl : std::cout << "Successfully connected client to remote server\n";
    server.acceptConnection();
    std::cout << "Trying communications \n";
    res = iencli.sendMessage("Hello world ya zebi\n");
    res == SOCKET_ERROR ? std::cout << "Error send: " << WSAGetLastError() << std::endl : std::cout << "Sent message :)\n";
    std::cout << server.readCommunications();
    return 0;
}
